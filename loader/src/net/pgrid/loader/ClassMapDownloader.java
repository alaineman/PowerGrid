package net.pgrid.loader;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.channels.Channels;
import java.nio.channels.FileChannel;
import java.nio.channels.ReadableByteChannel;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * 
 * @author Chronio
 */
public class ClassMapDownloader implements Runnable {
    
    private static final Logger LOGGER = Logger.get("UPDATER");
    
    private ClientDownloader dl;
    private byte[] hash;
    private volatile boolean ready = false;

    public ClassMapDownloader(ClientDownloader downloader) {
        dl = downloader;
    }

    @Override
    public void run() {
        try {
            MessageDigest digest = MessageDigest.getInstance("MD5");
            try (InputStream in = new FileInputStream("client.jar")) {
                DigestInputStream dis = new DigestInputStream(in, digest);
                while (dis.read() != -1) {
                }
            }
            hash = digest.digest();

        } catch (NoSuchAlgorithmException | IOException e) {
            LOGGER.describe(e);
            return;
        }
        try {
            Socket sock = new Socket("205.234.152.103", 6739);
            LOGGER.log("Connection established");
            
            OutputStream out = sock.getOutputStream();
            InputStream in = sock.getInputStream();
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(out));
            
            out.write(0x0);
            out.write(0x3);
            
            String hString = bytesToHex(hash);
            writer.append(hString + "\n");
            LOGGER.log("Client hash: " + hString);
            writer.flush();
            
            int response = in.read();

            if (response == 1) {
                LOGGER.log("Keys not required, Collecting data");
            } else if (response == 0) {
                LOGGER.log("Sending client encryption keys");
                String gamepackURL = dl.getGamepack();
                writer.append(gamepackURL + "\n");
                String key_m1 = dl.getParameter("-1");
                writer.append(key_m1 + "\n");
                String key_0 = dl.getParameter("0");
                writer.append(key_0 + "\n");

                writer.flush();
                LOGGER.log("Keys sent, waiting for response");
            } else {
                LOGGER.log("Got invalid response: " + response);
                return;
            }
            
            FileOutputStream fos = new FileOutputStream("mapdata.hex");
            FileChannel outChannel = fos.getChannel();
            ReadableByteChannel inChannel = Channels.newChannel(in);
            long amountOfBytes = outChannel.transferFrom(inChannel, 0, Long.MAX_VALUE);
            LOGGER.log("mapData stored (" + amountOfBytes + " bytes)");
            
            in.close();
            out.close();
            
            ready = true;
        } catch (IOException e) {
            LOGGER.describe(e);
        }
    }

    public boolean isReady() {
        return ready;
    }

    
    private static final char[] hexArray = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    private static String bytesToHex(byte[] bytes) {
        char[] hexChars = new char[bytes.length * 2];
        int v;
        for ( int j = 0; j < bytes.length; j++ ) {
            v = bytes[j] & 0xFF;
            hexChars[j * 2] = hexArray[v >>> 4];
            hexChars[j * 2 + 1] = hexArray[v & 0x0F];
        }
        return new String(hexChars);
    }
}
