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
import java.net.URL;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;
import java.nio.charset.Charset;
import net.pgrid.loader.GamepackIdentifier;
import net.pgrid.loader.RSVersionInfo;
import net.pgrid.loader.logging.Logger;

/**
 * Downloads the updater data from the updater server.
 * @author Patrick Kramer
 */
public class Updater {
    
    /** The default Updater server address. */
    public static final String DEFAULT_SERVER = "http://pgrid.net/marneus/";
    
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
    }
    
    /**
     * Creates a new ClassMapDownloader instance that acquires updater 
     * information for the provided RSVersionInfo object.
     * @param info the RSVersionInfo object
     * @param updaterServer the updater server
     */
    public Updater(RSVersionInfo info, String updaterServer) {
        if (info == null) {
            throw new IllegalArgumentException();
        }
        this.info = info;
        if (updaterServer != null) {
            server = updaterServer;
        } else {
            server = DEFAULT_SERVER;
        }
    }
    
    /**
     * @return the updater data as a byte array
     * @throws IOException when an I/O error occurred
     */
    public byte[] getData() throws IOException {
        long crc32 = GamepackIdentifier.computeChecksum("cache/client.jar", 
                info.getEncryptionKey0(), info.getEncryptionKeyM1());
        // Construct the URL from the CRC
        URL u = new URL(server + "reflection_cache_" + crc32 + ".xml");
        ByteArrayOutputStream bout = new ByteArrayOutputStream();
        WritableByteChannel out = Channels.newChannel(bout);
        try (InputStream uin = u.openStream()) {
            ReadableByteChannel in = Channels.newChannel(uin);
            ByteBuffer buf = ByteBuffer.allocateDirect(16 * 1024); // 16KB
            while (in.read(buf) != -1) {
                buf.flip();
                out.write(buf);
                buf.compact();
            }
            buf.flip();
            while (buf.hasRemaining()) {
                out.write(buf);
            }
        }
        LOGGER.log("Updater data acquired");
        return bout.toByteArray();
    }
}
