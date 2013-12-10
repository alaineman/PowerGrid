/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 * 
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
package net.pgrid.loader.bridge;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;
import java.nio.charset.Charset;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import net.pgrid.loader.RSVersionInfo;
import net.pgrid.loader.logging.Logger;

/**
 * Downloads the updater data from the updater server.
 * @author Patrick Kramer
 */
public class ClassMapDownloader {
    
    /** The default Updater Server address. */
    public static final String DEFAULT_SERVER = "205.234.152.103";
    /** The default Updater Server port. */
    public static final int DEFAULT_PORT = 6739;
    
    /**
     * The Character set that will be used for all In- and OutputStreams
     * related to network traffic.
     * <p/>
     * It is set as ISO-8859-1 based on the default encoding of config files as 
     * provided to us by the RuneScape servers and the Updater Server.
     */
    public static final Charset CHARSET = Charset.forName("ISO-8859-1");
    
    private static final Logger LOGGER = Logger.get("UPDATER");
    
    private final RSVersionInfo info;
    private byte[] hash = null;
    private final String server;
    private final int serverPort;

    /**
     * Creates a new ClassMapDownloader instance that acquires updater 
     * information for the provided RSVersionInfo object.
     * @param info the RSVersionInfo object
     */
    public ClassMapDownloader(RSVersionInfo info) {
        this.info = info;
        server = DEFAULT_SERVER;
        serverPort = DEFAULT_PORT;
    }
    
    /**
     * Creates a new ClassMapDownloader instance that acquires updater 
     * information for the provided RSVersionInfo object.
     * @param info the RSVersionInfo object
     * @param updaterServer the updater server
     * @param port the port of the updater server to connect to
     */
    public ClassMapDownloader(RSVersionInfo info, String updaterServer, int port) {
        this.info = info;
        server = updaterServer;
        serverPort = port;
    }

    /**
     * Returns the hash of the downloaded client jar file, if it exists.
     * <p/>
     * @return the hash of the client jar file as a hexadecimal String
     * @throws IOException when reading from the client jar file failed.
     * 
     */
    // FIXME Change computeHash() to something not dependant on the actual client file
    // This method should only depend on the RSVersionInfo provided to it.
    // Otherwise this method fails when the client is being updated during 
    // hash computation. Also, it cannot be asserted that the computed hash 
    // belongs to the client described by the RSVersionInfo object, as this may
    // differ from the client file at "cache/client.jar".
    private byte[] computeHash() throws IOException {
        if (hash == null) {
            try {
                MessageDigest digest = MessageDigest.getInstance("MD5");
                try (DigestInputStream dis = new DigestInputStream(new FileInputStream("cache/client.jar"), digest)) {
                    // run over the entire stream
                    while (dis.read() != -1) {}
                }
                hash = digest.digest();
            } catch (NoSuchAlgorithmException e) {
                // This should never happen!
                throw new AssertionError("MD5 is not recognized as a valid MessageDigest algorithm");
            }
        }
        return hash;
    }
    
    /**
     * @return the updater data as a byte array
     * @throws IOException when an I/O error occurred
     */
    public byte[] getData() throws IOException {
        Socket s = new Socket(server, serverPort);
        byte[] classMapData = null;
        try {
            try (InputStream in = s.getInputStream();
                 OutputStream out = s.getOutputStream()) {
                LOGGER.log("Connection to \"" + s.getInetAddress().getHostName() + ":" + s.getPort() + "\" established");

                out.write(0x0);
                out.write(0x3);

                OutputStreamWriter writer = new OutputStreamWriter(out, CHARSET);
                writer.append(bytesToHex(computeHash())).append("\n");
                writer.flush();

                LOGGER.log("Waiting for updater server");

                int response = in.read();

                switch(response) {
                    case 0x0: // the keys are required
                        writer.append(info.getClientParameter("initial_jar")).append("\n");
                        writer.append(info.getEncryptionKeyM1()).append("\n");
                        writer.append(info.getEncryptionKey0()).append("\n");
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
        } catch (IOException e) {
            LOGGER.log("Failed to load updater data", e);
        }
        return classMapData;
    }
    
    // FIXME memory leak: the hexArray is only used basically once, but remains allocated afterwards.
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
