package powergrid.core.decoding;

import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.security.GeneralSecurityException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.Objects;
import java.util.zip.GZIPInputStream;
import java.util.zip.InflaterInputStream;
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

/**
 * Class that decodes InputStream instances.
 * <p/>
 * Multiple decoding methods can be applied to the same InputStream, they will
 * be applied in sequence.
 * <p/>
 * This class applies decoding steps to the InputStream by wrapping it in a
 * decoding InputStream. Most of the used wrappers are provided by the Java API
 * natively.
 * <p/>
 * After all required decodings are applied, the InputStream can be retrieved
 * using the {@code get()} method.
 * <p/>
 * The supported encodings are: {@code gzip}, {@code deflate}, and {@code cis}.
 * In case {@code cis} is used with the Cipher algorithm "XOR", the custom 
 * XORInputStream is used instead of the Java API's native CipherInputStream.
 */
public class InputStreamDecoder {

    private static byte[] sharedKey = null;
    
    private InputStream in;

    /**
     * Creates a new InputStreamDecoder instance that decodes the provided InputStream.
     *
     * @param in the InputStream to decodeBase64
     */
    public InputStreamDecoder(InputStream in) {
        assert in != null;
        this.in = in;
    }

    /**
     * Returns the InputStream with all decoding wrappers.
     *
     * @return the resulting InputStream
     */
    public InputStream get() {
        return in;
    }

    /**
     * Decodes the InputStream using the provided method.
     *
     * @param method the method to apply decoding for
     * @return itself for fluency
     * @throws IOException when the decoding failed
     */
    public InputStreamDecoder decode(String method) throws IOException {
        if (method != null) {
            String m = method.toLowerCase();
            switch (m) {
                case "gzip":
                    in = new GZIPInputStream(in);
                    break;
                case "deflate":
                    in = new InflaterInputStream(in);
                    break;
                default:
                    if (m.startsWith("cis:")) {
                        String[] arguments = method.split(":");
                        if (arguments.length > 3) {
                            byte[] key = getSharedKey(arguments[3].getBytes("UTF-8"));
                            if (arguments[1].equals("XOR")) {
                                in = new XORInputStream(in, getSharedKey(key),
                                        Cipher.DECRYPT_MODE);
                            } else {
                                try {
                                in = new CipherInputStream(in, 
                                        getCipher(Cipher.DECRYPT_MODE, key, 
                                        arguments[1], arguments[2]));
                                } catch (GeneralSecurityException e) {
                                    throw new IOException ("Failed to get Cipher for encoded InputStream", e);
                                }
                            }
                        }
                    }
            }
        }
        return this;
    }

    /**
     * Decodes the InputStream by applying decodings for the provided methods in
     * sequence.
     *
     * @param methods the methods to apply decoding for
     * @return itself for fluency
     * @throws IOException when the decoding failed
     */
    public InputStreamDecoder decode(String[] methods) throws IOException {
        if (methods != null) {
            for (String method : methods) {
                decode(method);
            }
        }
        return this;
    }

    /**
     * Returns the shared key for the given byte array, using the SHA-1
     * algorithm.
     *
     * @param bytes the bytes to compute the shared key for
     * @return the shared key for the given byte array
     */
    public byte[] getSharedKey(byte[] bytes) {
        if (sharedKey == null) {
            sharedKey = new byte[]{0, 0x32, 0x4f, 0x2a, 0x7f, 0x01, 0x5a, 0x69};
        }
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            md.update(sharedKey);
            md.update(bytes);
            return md.digest();
        } catch (NoSuchAlgorithmException e) {
            return null;
        }
    }

    /**
     * Returns the Cipher for the given encoding parameters.
     * <p/>
     * @param opmode the operation mode
     * @param key the key for the Cipher
     * @param cipherAlgorithm the algorithm to use for the Cipher
     * @param keyAlgorithm the algorithm to use to decodeBase64 the key
     * @return the Cipher for the given encoding parameters
     * @throws GeneralSecurityException if the Cipher could not be configured
     */
    public Cipher getCipher(int opmode, byte[] key, String cipherAlgorithm,
            String keyAlgorithm) throws GeneralSecurityException {
        final Cipher c = Cipher.getInstance(cipherAlgorithm);
        byte[] iv = null;
        int len = 16;
        final String[] keyArgs = keyAlgorithm.split("/");
        if (keyArgs.length > 1 && !keyArgs[1].isEmpty()) {
            try {
                iv = decodeBase64(keyArgs[1].getBytes("UTF-8"));
            } catch (UnsupportedEncodingException ignored) {
            }
        }
        if (keyArgs.length > 2) {
            try {
                len = Integer.parseInt(keyArgs[2]);
            } catch (NumberFormatException ignored) {
                len = 16;
            }
        }
        final SecretKeySpec sks = new SecretKeySpec(Arrays.copyOf(key, len), keyArgs[0]);
        if (iv == null) {
            c.init(opmode, sks);
        } else {
            c.init(opmode, sks, new IvParameterSpec(iv));
        }
        return c;
    }

    /**
     * Decodes the given bytes using Base 64 encoding.
     *
     * @param encodedBytes the encoded bytes
     * @return the decoded bytes.
     */
    public byte[] decodeBase64(final byte[] encodedBytes) {
        int inputLength = encodedBytes.length;
        int separatorCount = 0;
        for (byte encodedByte : encodedBytes) {
            // count the amount of separator bytes
            if (getValueForChar(encodedByte & 0xff) < 0) {
                separatorCount++;
            }
        }
        if ((inputLength - separatorCount) % 4 != 0) {
            // The provided byte array does not match base64 encoding
            return null;
        }
        int padding = 0;
        for (int i = inputLength; i > 1
                && getValueForChar(encodedBytes[--i] & 0xff) <= 0;) {
            // the value for the '=' character is used as padding
            if (encodedBytes[i] == '=') {
                padding++;
            }
        }
        int outputLength = ((inputLength - separatorCount) * 6 >> 3) - padding;
        byte[] decodedBytes = new byte[outputLength];
        for (int encodeIndex = 0, decodeIndex = 0; decodeIndex < outputLength;) {
            int assembledInt = 0;
            for (int validIndex = 0; validIndex < 4;) {
                int c = getValueForChar(encodedBytes[encodeIndex++] & 0xff);
                if (c >= 0) {
                    assembledInt |= c << 18 - validIndex * 6;
                    validIndex++;
                }
            }
            decodedBytes[decodeIndex++] = (byte) (assembledInt >> 16);
            if (decodeIndex < outputLength) {
                decodedBytes[decodeIndex++] = (byte) (assembledInt >> 8);
                if (decodeIndex < outputLength) {
                    decodedBytes[decodeIndex++] = (byte) assembledInt;
                }
            }
        }
        return decodedBytes;
    }

    /**
     * Helper method that determines the value for the given character in base64
     * decoding.
     * <p/>
     * The returned value is equal to the index of the provided char value in
     * the following String:
     * {@code "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"}
     * <p/>
     * The single exception here is that '=' translates to 0. Other values that
     * are not included in the above String translate to -1.
     *
     * @param c the value to look up.
     * @return the value for the character
     */
    private int getValueForChar(int c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A';
        } else if (c >= 'a' && c <= 'z') {
            return 26 + c - 'a';
        } else if (c >= '0' && c <= '9') {
            return 52 + c - '0';
        } else switch (c) {
                case '+': return 62;
                case '/': return 63;
                case '=': return 0;
                default:  return -1;
        }
    }

    /**
     * Returns a String-representation of this InputStreamDecoder, including the
     * String-value of the InputStream that would be returned if the
     * {@code get()} method was called.
     * <p/>
     * If, for any reason, the InputStream is equal to {@code null}, then the
     * String {@code "InputStreamDecoder(null)"} is returned.
     * <p/>
     * @return a String-representation of this InputStreamDecoder.
     */
    @Override
    public String toString() {
        return "Decoder(" + Objects.toString(get()) + ")";
    }
}