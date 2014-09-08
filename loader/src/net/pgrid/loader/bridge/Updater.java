/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.jar.JarInputStream;
import net.pgrid.loader.logging.Logger;

/**
 * Downloads the updater data from the updater server.
 * @author Patrick Kramer
 */
public class Updater {
    
    /**
     * The Character encoding that will be used for all In- and OutputStreams
     * related to network traffic.
     * 
     * It is set as ISO-8859-1 (AKA Windows-1252, the default Windows encoding) 
     * based on the default encoding of config files as provided to us by the 
     * RuneScape servers and the Updater Server.
     */
    public static final Charset CHARSET = Charset.forName("ISO-8859-1");
    
    private static final Logger LOGGER = Logger.get("UPDATER");
    
    public static final String URL_TEMPLATE = 
            "http://pgrid.net/marneus/reflection_cache_{hash}.xml";
    
    public static final String CLIENT_PATH = "cache/client.jar";
    
    /**
     * Connects to the server of this Updater and tries to load the data 
     * from it.
     * 
     * @return the updater data as a byte array
     * @throws IOException when an I/O error occurred
     */
    public byte[] getData() throws IOException {
        URL u = createURL(Paths.get(CLIENT_PATH));
        
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
    
    /**
     * Creates a URL based on the client located at the provided Path.
     * 
     * @param clientPath the Path to the client file
     * @return the URL with updater data for the client
     * @throws IOException when an I/O error occurs reading the client
     */
    public URL createURL(Path clientPath) throws IOException {
        assert clientPath != null;
        try (JarInputStream in = new JarInputStream(
                    Files.newInputStream(clientPath))) {
            return new URL(URL_TEMPLATE.replace("{hash}",
                    String.valueOf(in.getManifest().hashCode())));
        }
    }
}
