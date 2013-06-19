package net.pgrid.loader;

import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            Logger.describe(e);
            return;
        }
        try {
            Socket sock = new Socket("205.234.152.103", 6739);
            Logger.log("UPDATER: Connection established");
            
            OutputStream out = sock.getOutputStream();
            InputStream in = sock.getInputStream();
            DataOutputStream dOut = new DataOutputStream(out);
            
            out.write(0x0);
            out.write(0x3);
            
            String hString = bytesToHex(hash);
            dOut.writeChars(hString + "\n");
            Logger.log("UPDATER: Client hash: " + hString);
            dOut.flush();
            
            int response = in.read();

            if (response == 1) {
                Logger.log("UPDATER: Keys not required, Collecting data");
            } else if (response == 0) {
                Logger.log("UPDATER: Sending client encryption keys");
                String gamepackURL = dl.getDownloadLink();
                dOut.writeChars(gamepackURL + "\n");
                String key_m1 = dl.getParameter("-1");
                dOut.writeChars(key_m1 + "\n");
                String key_0 = dl.getParameter("0");
                dOut.writeChars(key_0 + "\n");

                dOut.flush();
                Logger.log("UPDATER: Keys sent, waiting for response");
            } else {
                Logger.log("UPDATER: Got invalid response: " + response);
                return;
            }
            
            FileOutputStream fos = new FileOutputStream("mapdata.hex");
            FileChannel outChannel = fos.getChannel();
            ReadableByteChannel inChannel = Channels.newChannel(in);
            outChannel.transferFrom(inChannel, 0, Integer.MAX_VALUE);
            Logger.log("UPDATER: mapData stored");
            ready = true;
        } catch (IOException e) {
            Logger.describe(e);
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
