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
            String hString = new String(hash) + "\n";
            dOut.writeChars(hString);
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
            
            FileOutputStream fos = new FileOutputStream("mapData.hex");
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

}
