package net.pgrid.loader.bridge;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import net.pgrid.loader.ClientDownloader;
import net.pgrid.loader.Logger;

/**
 * 
 * @author Chronio
 */
public class ClassMapDownloader implements Runnable {
    
    public static final String DEFAULT_SERVER = "205.234.152.103";
    public static final int DEFAULT_PORT = 6739;
    
    private static final Logger LOGGER = Logger.get("UPDATER");
    
    private ClientDownloader dl;
    private byte[] hash = null;
    private volatile boolean ready = false;
    private byte[] classMapData = null;
    private String server;
    private int serverPort;

    public ClassMapDownloader(ClientDownloader downloader) {
        dl = downloader;
    }
    
    public ClassMapDownloader(ClientDownloader downloader, String updaterServer, int port) {
        dl = downloader;
        server = updaterServer;
        serverPort = port;
    }

    @Override
    public void run() {
        getData();
    }

    protected byte[] computeHash() throws IOException {
        if (hash == null) {
            try {
                MessageDigest digest = MessageDigest.getInstance("MD5");
                try (InputStream in = new FileInputStream("client.jar")) {
                    DigestInputStream dis = new DigestInputStream(in, digest);
                    while (dis.read() != -1) {}
                }
                hash = digest.digest();
            } catch (NoSuchAlgorithmException e) {
                LOGGER.describe(e);
                throw new InternalError("Failed to compute checksum due to unsupported algorithm");
            }
        }
        return hash;
    }
    
    public boolean isReady() {
        return ready;
    }
    
    protected byte[] getData(Socket s) {
        if (classMapData == null) {
            try {
                try (InputStream   in = s.getInputStream();
                     OutputStream out = s.getOutputStream()) {
                    LOGGER.log("Connection to \"" + s.getInetAddress().getHostName() + ":" + s.getPort() + "\" established");
                    
                    out.write(0x0);
                    out.write(0x3);
                    
                    OutputStreamWriter writer = new OutputStreamWriter(out);
                    writer.append(bytesToHex(computeHash())).append("\n");
                    writer.flush();
                    
                    LOGGER.log("Waiting for updater server");
                    
                    int response = in.read();
                    
                    switch(response) {
                        case 0x0: // the keys are required
                            writer.append(dl.getGamepack()).append("\n");
                            writer.append(dl.getParameter("-1")).append("\n");
                            writer.append(dl.getParameter("0")).append("\n");
                            writer.flush();
                            LOGGER.log("Keys sent, waiting for response");
                            break;
                        case 0x1: // the keys are not required
                            LOGGER.log("Waiting for server response");
                            break;
                        default:  // something went wrong
                            throw new IOException("Unexpected response from server: " + response);
                    }
                    
                    ByteArrayOutputStream bOut = new ByteArrayOutputStream(4096);
                    ReadableByteChannel rbc = Channels.newChannel(in);
                    WritableByteChannel wbc = Channels.newChannel(bOut);
                    ByteBuffer buf = ByteBuffer.allocateDirect(1024);
                    while (rbc.read(buf) != -1) {
                        buf.flip();
                        wbc.write(buf);
                        buf.compact();
                    }
                    buf.flip();
                    while (buf.hasRemaining()) {
                        wbc.write(buf);
                    }
                    classMapData = bOut.toByteArray();
                }
                
            } catch (UnknownHostException e) {
                LOGGER.log("Server \"" + getServer() + "\" cannot be found: " + e.getLocalizedMessage());
            } catch (IOException e) {
                LOGGER.describe(e);
            }
        }
        return classMapData;
    }
    
    public byte[] getData() {
        try {
            return getData(openConnection());
        } catch (IOException e) {
            LOGGER.describe(e);
            return null;
        }
    }
    
    protected Socket openConnection() throws IOException {
        return new Socket(getServer(), getServerPort());
    }

    public String getServer() {
        return server;
    }

    public int getServerPort() {
        return serverPort;
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
