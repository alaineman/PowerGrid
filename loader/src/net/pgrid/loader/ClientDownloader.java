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
package net.pgrid.loader;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Downloads the client files from the Runescape servers.
 *
 * @author Chronio
 */
public class ClientDownloader {

    private static final Logger LOGGER = Logger.get("LOADER");
    
    /**
     * Link to the Runescape config file. It is used to get the config data
     * from.
     */
    public static final String CONFIG_LINK = "http://www.runescape.com/k=3/l=0/jav_config.ws";
    
    /**
     * the Runescape gamepack. Is null unless config was downloaded.
     */
    private String gamepack = null;
    /**
     * the Runescape codebase. Is null unless config was downloaded.
     */
    private String codebase = null;
    /**
     * URL of the Runescape config file. It is set in the constructor.
     */
    private URL configURL;
    /**
     * the codebase URL, is null unless requested.
     */
    private URL codebaseURL;
    /**
     * Parameters of the
     * <code>Applet</code> as a Map. Empty if config was not downloaded.
     */
    private Map<String, String> parameters;
    /**
     * The contents of the config file, or null if not downloaded.
     */
    private String configData = null;

    /**
     * Creates a new ClientDownloader that uses the DEFAULT_CONFIG as config
     * URL.
     */
    public ClientDownloader() {
        try {
            configURL = new URL(CONFIG_LINK);
            parameters = new HashMap<>(32);
        } catch (MalformedURLException e) {
            // should not be thrown
        }
    }

    /**
     * @return the codebase as defined in the config, or null if the config is
     * not yet loaded
     */
    public String getCodebase() {
        return codebase;
    }
    
    public URL getCodeBaseUrl() {
        if (codebase == null) {
            return null;
        }
        if (codebaseURL == null) {
            try {
                codebaseURL = new URL(codebase);
            } catch (MalformedURLException e) {
                LOGGER.describe(e);
            }
        }
        return codebaseURL;
    }
    
    public String getDownloadLink() {
        return codebase + gamepack;
    }

    public String getGamepack() {
        return gamepack;
    }

    /**
     * Returns the value for a given parameter
     *
     * @param param the requested parameter
     * @return the value for the given parameter, or null if the parameter is
     * not defined.
     */
    public String getParameter(String param) {
        return parameters.get(param);
    }

    /**
     * Loads the config file if it was not already downloaded.
     *
     * @throws IOException if the download failed
     */
    public void loadConfig() throws IOException {
        if (gamepack == null) {
            try (InputStream in = configURL.openStream()) {
                // using a Scanner with the right delimiter provides the entire 
                // content of the stream at once in only a few lines.
                Scanner out = new Scanner(in).useDelimiter("\\A");
                if (out.hasNext()) {
                    configData = out.next();
                } else {
                    throw new RuntimeException("Empty response getting config file");
                }
            }
            parseConfig();
        }
        assert gamepack != null;
    }

    /**
     * Downloads the client using the previously downloaded config.
     *
     * @throws IOException if the download failed
     */
    public void loadClient() throws IOException {
        assert gamepack != null;
        URL url = new URL(codebase + gamepack);
        URLConnection conn = url.openConnection();
        FileOutputStream out = new FileOutputStream("client.jar");

        // Using fast stream copy with Java NIO Channels. This is at least as fast
        // as manual copy using a byte array as buffer.
        try (InputStream in = conn.getInputStream()) {
            ReadableByteChannel reader = Channels.newChannel(in);
            WritableByteChannel writer = Channels.newChannel(out);

            ByteBuffer buffer = ByteBuffer.allocateDirect(16 * 1024);

            while (reader.read(buffer) != -1) {
                buffer.flip();
                writer.write(buffer);
                buffer.compact();
            }
            buffer.flip();
            while (buffer.hasRemaining()) {
                writer.write(buffer);
            }
        }
    }

    /**
     * Parses the required data from the downloaded config data.
     * <p/>
     * All
     * <code>Applet</code> parameters are parsed, as well as the "codebase",
     * "initial_jar" and "download" values.
     */
    private void parseConfig() {
        assert configData != null;

        Scanner sc = new Scanner(configData);
        while (sc.hasNext()) {
            String line = sc.nextLine();
            if (line.startsWith("param=")) {
                int mid = line.indexOf('=', 6);
                String key = line.substring(6, mid);
                String value = line.substring(mid + 1, line.length());
                parameters.put(key, value);
            } else if (line.startsWith("initial_jar=")) {
                gamepack = line.substring(12, line.length());
            } else if (line.startsWith("codebase=")) {
                codebase = line.substring(9, line.length());
            }
        }

        if (codebase == null || gamepack == null) {
            throw new RuntimeException("Invalid config");
        }
        LOGGER.log("Config has been parsed, gamepack URL is: " + codebase + gamepack);
    }
}
