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
import net.pgrid.loader.PGLoader;
import net.pgrid.loader.RSVersionInfo;
import net.pgrid.loader.logging.Logger;

/**
 * Downloads the updater data from the updater server.
 * @author Patrick Kramer
 */
public class Updater {
    
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
    private final String server;
    private final int serverPort;

    /**
     * Creates a new ClassMapDownloader instance that acquires updater 
     * information for the provided RSVersionInfo object.
     * @param info the RSVersionInfo object
     */
    public Updater(RSVersionInfo info) {
        if (info == null) {
            throw new IllegalArgumentException();
        }
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
    public Updater(RSVersionInfo info, String updaterServer, int port) {
        if (info == null) {
            throw new IllegalArgumentException();
        }
        this.info = info;
        if (updaterServer != null && port > 0 && port < 65536) {
            server = updaterServer;
            serverPort = port;
        } else {
            server = DEFAULT_SERVER;
            serverPort = DEFAULT_PORT;
        }
    }
    
    /**
     * @return the updater data as a byte array
     * @throws IOException when an I/O error occurred
     */
    public byte[] getData() throws IOException {
        Socket s = new Socket(server, serverPort);
        byte[] classMapData;
        try (InputStream in = s.getInputStream();
             OutputStream out = s.getOutputStream()) {
            LOGGER.log("Connection to \"" + s.getInetAddress().getHostName() + ":" + s.getPort() + "\" established");

            out.write(0x0);
            out.write(0x3);

            OutputStreamWriter writer = new OutputStreamWriter(out, CHARSET);
            // a pseudo-unique String indicating the client version
            writer.append(info.getEncryptionKeyM1() + info.getEncryptionKey0()).append("\n");
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
        return classMapData;
    }
}
