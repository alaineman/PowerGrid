package net.pgrid.loader;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Enumeration;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;
import java.util.jar.JarOutputStream;
import java.util.jar.Pack200;
import java.util.jar.Pack200.Unpacker;
import java.util.zip.CRC32;
import java.util.zip.CheckedInputStream;
import java.util.zip.GZIPInputStream;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import net.pgrid.loader.logging.Logger;

/**
 * Utility class for the finding the CRC32 of the Runescape client.
 * 
 * This class computes the checksum of the Runescape client's inner pack.
 * This gives us a good indication of which game pack we have, so that we can
 * collect the correct information from the updater server.
 * 
 * @author Patrick Kramer
 */
public class GamepackIdentifier {
    private static final Logger LOGGER = Logger.get("UPDATER");
    
    private GamepackIdentifier() {}
    
    private static final int[] CHARMAP;

    static {
        CHARMAP = new int[128];
        int i;
        for (i = 0; i < 128; ++i) {
            CHARMAP[i] = -1;
        }
        CHARMAP[42] = 62;
        CHARMAP[43] = 62;
        CHARMAP[45] = 63;
        CHARMAP[47] = 63;
        for (i = 48; i <= 57; ++i) {
            CHARMAP[i] = 4 + i;
        }
        for (i = 65; i <= 90; ++i) {
            CHARMAP[i] = i - 65;
        }
        for (i = 97; i <= 122; ++i) {
            CHARMAP[i] = i - 71;
        }
    }

    /**
     * Looks up the value belonging to the given char in the lookup table.
     * @param c the char to look up
     * @return the value corresponding to the given char.
     */
    private static int lookup(char c) {
        return c >= 0 && c < CHARMAP.length ? CHARMAP[c] : -1;
    }

    /**
     * Computes and returns the checksum of the inner.pack.gz file in the 
     * provided jar. 
     * @param jarFilename the file name of the jar file.
     * @param param0 the SecretKey parameter (parameter 0)
     * @param paramM1 the IVParameter (parameter -1)
     * @return the CRC32 checksum of the client's inner pack
     */
    public static long computeChecksum(final String jarFilename, final String param0, final String paramM1) {
        // Steps taken to fully decrypt the inner pack data:
        // -------------------------------------------------
        // 1. Unscramble the keys
        //    1.1 Unscramble the SecretKey
        //    1.2 Unscramble the IVParam key
        // 2. Decypher the data using the keys found at (1.)
        // 3. Unpack the decyphered (PACK200-)GZIP inner pack and save as a JAR
        // 4. Compute the CRC32 checksum of the written JAR
        
        byte[] skBytes;
        int bytePos;
        int var12;
        int var13;
        int var14;
        
        // Unscramble the Secret Key
        final int skLength = param0.length();
        int var5 = -4 & 3 + skLength;
        int skKeyLength = var5 / 4 * 3;
        if (var5 - 2 < skLength && lookup(param0.charAt(var5 - 2)) != 0) {
            if (skLength < var5 - 1 || lookup(param0.charAt(var5 - 1)) == -1) {
                --skKeyLength;
            }
        } else {
            skKeyLength -= 2;
        }

        skBytes = new byte[skKeyLength];
        bytePos = 0;
        int keyPos = 0;

        while (keyPos < skLength) {
            int unscrambledChar = lookup(param0.charAt(keyPos));
            var12 = skLength <= keyPos + 1 ? -1 : lookup(param0.charAt(keyPos + 1));
            var13 = keyPos + 2 < skLength ? lookup(param0.charAt(2 + keyPos)) : -1;
            var14 = 3 + keyPos < skLength ? lookup(param0.charAt(3 + keyPos)) : -1;
            skBytes[bytePos++] = (byte) (unscrambledChar << 2 | var12 >>> 4);
            if (var13 == -1) {
                break;
            }

            skBytes[bytePos++] = (byte) ((var12 & 15) << 4 | var13 >>> 2);
            if (~var14 == 0) {
                break;
            }

            skBytes[bytePos++] = (byte) ((3 & var13) << 6 | var14);
            keyPos += 4;
        }
        
        // Unscramble the ivParameter key
        int streamIndex;
        int bytesRead;
        byte[] ivBytes;
        int ivLength = paramM1.length();
        if (ivLength == 0) {
            ivBytes = new byte[0];
        } else {
            var5 = -4 & 3 + ivLength;
            int ivKeylength = var5 / 4 * 3;
            if (ivLength <= var5 - 2 || ~lookup(paramM1.charAt(var5 - 2)) == 0) {
                ivKeylength -= 2;
            } else if (ivLength <= var5 - 1 || -1 == lookup(paramM1.charAt(var5 - 1))) {
                --ivKeylength;
            }
            bytePos = 0;
            ivBytes = new byte[ivKeylength];
            var12 = paramM1.length();
            var13 = 0;

            while (var13 <= var12) {
                var14 = lookup(paramM1.charAt(var13));
                streamIndex = 1 + var13 >= var12 ? -1 : lookup(paramM1.charAt(1 + var13));
                bytesRead = var12 > var13 + 2 ? lookup(paramM1.charAt(var13 + 2)) : -1;
                int var17 = var12 <= var13 + 3 ? -1 : lookup(paramM1.charAt(3 + var13));
                ivBytes[bytePos++] = (byte) (streamIndex >>> 4 | var14 << 2);
                if (bytesRead == -1) {
                    break;
                }

                ivBytes[bytePos++] = (byte) (240 & streamIndex << 4 | bytesRead >>> 2);
                if (~var17 == 0) {
                    break;
                }

                ivBytes[bytePos++] = (byte) (bytesRead << 6 & 192 | var17);
                var13 += 4;
            }
        }
        
        // Create the Cipher with the unscrambled keys
        Cipher cipher;
        try {
            cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
            cipher.init(Cipher.DECRYPT_MODE, 
                    new SecretKeySpec(skBytes, "AES"), 
                    new IvParameterSpec(ivBytes));
        } catch (NoSuchPaddingException | NoSuchAlgorithmException | 
                InvalidKeyException | InvalidAlgorithmParameterException e) {
            throw new RuntimeException(e);
        }
        byte[] tempData = new byte[5242880];
        try {
            InputStream encryptedClient = null;
            try (JarFile theJar = new JarFile(jarFilename)) {
                Enumeration<?> en = theJar.entries();
                while (en.hasMoreElements()) {
                    JarEntry entry = (JarEntry) en.nextElement();
                    if (entry.getName().endsWith(".gz")) {
                        encryptedClient = theJar.getInputStream(entry);
                        break;
                    }
                }
            
                if (encryptedClient == null) {
                    throw new IOException("Failed to find inner.pack.gz in runescape.jar");
                }
                streamIndex = 0;

                try {
                    bytesRead = encryptedClient.read(tempData, streamIndex, 5242880 - streamIndex);

                    while (bytesRead != -1) {
                        streamIndex += bytesRead;
                        bytesRead = encryptedClient.read(tempData, streamIndex, 5242880 - streamIndex);
                    }
                } catch (IOException iox) {
                    LOGGER.log("I/O error reading inner.pack.gz", iox);
                }
            }
            byte[] var53 = new byte[streamIndex];
            System.arraycopy(tempData, 0, var53, 0, streamIndex);

            byte[] decipheredData = cipher.doFinal(var53);
            Unpacker jarUnpacker = Pack200.newUnpacker();
            encryptedClient.close();
            // TODO try to not save it in between, this costs a lot of time.
            File file = new File("cache/temp.jar");
            try (JarOutputStream decryptedClient = new JarOutputStream(new FileOutputStream(file))) {
                GZIPInputStream zipClient = new GZIPInputStream(new ByteArrayInputStream(decipheredData));
                jarUnpacker.unpack(zipClient, decryptedClient);
            } catch (IOException e) {
                LOGGER.log("Could not save client: ", e);
            }
            long crc = getCRC32("cache/temp.jar");
            LOGGER.log("CRC32 Computed. Result: " + crc);
            return crc;
        } catch (IOException e) {
            LOGGER.log("I/O error: ", e);
        } catch (BadPaddingException | IllegalBlockSizeException e) {
            LOGGER.log("Decryption failed: ", e);
        }
        return -1;
    }

    private static long getCRC32(String file) throws IOException {
        try (FileInputStream fin = new FileInputStream(file);
                CheckedInputStream cis = new CheckedInputStream(fin, new CRC32())) {
            byte[] buffer = new byte[1024];
            int bytesRead = 0;
            while (bytesRead != -1) {
                bytesRead = cis.read(buffer);
            }
            return cis.getChecksum().getValue();
        }
    }
}
