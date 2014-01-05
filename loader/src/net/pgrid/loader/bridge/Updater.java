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

import java.io.IOException;
import java.nio.charset.Charset;
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
        // We currently have no available updater server, so we can only exit 
        // directly.
        return new byte[0];
    }
}
