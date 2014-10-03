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
package net.pgrid.loader;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import net.pgrid.loader.bridge.Updater;
import net.pgrid.loader.util.Logger;

/**
 * Downloads required files from the Runescape servers.
 * <p/>
 * This class contains all functionality required to download the client and all
 * required parameters for launching it.
 *
 * @author Patrick Kramer
 */
public class RSDownloader {

    /**
     * The Logger instance this class logs to.
     */
    private static final Logger LOGGER = Logger.get("LOADER");
    /**
     * Link to the Runescape config file.
     * <p/>
     * It is used as the default link for the configuration data.
     */
    public static final String CONFIG_LINK = "http://www.runescape.com/k=3/l=0/jav_config.ws";
    
    public static final String JAV_CONFIG = "http://www.runescape.com/l=0/jav_config.ws?userFlow=";
    /**
     * URL of the Runescape config file. It is set in the constructor.
     */
    private URL configURL;
    private RSVersionInfo versionInfo = null;

    /**
     * Creates a new ClientDownloader that uses the {@code CONFIG_LINK} as
     * config URL.
     */
    public RSDownloader() {
        try {
            configURL = new URL(CONFIG_LINK);
        } catch (MalformedURLException e) {
            // should normally not happen
            throw new AssertionError("Invalid CONFIG_LINK constant", e);
        }
    }

    /**
     * Creates a new ClientDownloader that uses the specified URL as config URL.
     *
     * @param configURL the config URL
     * @throws IllegalArgumentException when {@code configURL == null}
     */
    public RSDownloader(URL configURL) {
        if (configURL == null) {
            throw new IllegalArgumentException();
        }
        this.configURL = configURL;
    }

    /**
     * Loads the config file if it was not already downloaded.
     *
     * @param oldVersion the current (possibly outdated version)
     * @return the RSVersionInfo obtained from the Runescape servers
     * @throws IOException if the download failed
     */
    public synchronized RSVersionInfo loadConfig(RSVersionInfo oldVersion) throws IOException {
        if (versionInfo == null) {
            // Try to get the config to load.
            if (oldVersion != null) {
                try {
                    configURL = new URL(JAV_CONFIG + oldVersion.getUserFlowID());
                    LOGGER.log("Re-using old userflow id " + oldVersion.getUserFlowID());
                } catch (MalformedURLException e) {
                    LOGGER.log("got invalid userFlow link from version manager");
                }
            } else {
                LOGGER.log("Failed to get version info, using default config URL");
            }
            HttpURLConnection conn = (HttpURLConnection) configURL.openConnection();
            conn.setInstanceFollowRedirects(false); // do not auto-resolve the redirect
            // This is the link we're redirected to.
            String redirectLink = conn.getHeaderField("Location");
            conn.disconnect();

            // This may happen if the connection to the configURL fails. Then,
            // there will be no header information to collect.
            // As this may indicate there is no active internet connection
            // (or the unlikely event in which the RS servers are down),
            // there is nothing left to do other then report this and terminate.
            if (redirectLink == null) {
                PowerGrid.report("Failed to connect to Runescape server");
                throw new IOException("Failed to get config information");
            }
            // fire a new request with the redirect link
            conn = (HttpURLConnection) new URL(redirectLink).openConnection();
            String assignedUserFlow = redirectLink.substring(redirectLink.lastIndexOf('=') + 1);
            try (InputStream in = conn.getInputStream()) {
                // using a Scanner with the right delimiter provides the entire 
                // content of the stream at once in only a few lines.

                Scanner out = new Scanner(Channels.newChannel(in),
                        Updater.CHARSET.name()).useDelimiter("\\A");
                if (out.hasNext()) {
                    versionInfo = parseConfig(assignedUserFlow, out.next());
                    conn.disconnect();
                } else {
                    // If there is no config information, we cannot start the client
                    PowerGrid.report("Failed to get config info from Runescape server");
                    throw new IOException("Empty response getting config file");
                }
            }
            LOGGER.log("Got assigned new userFlow id " + assignedUserFlow);
        }
        return versionInfo;
    }

    /**
     * Downloads the client using the previously downloaded config.
     *
     * @param destination the destination to save the client.
     * @throws IOException if the download failed
     * @throws IllegalStateException when the client data is not available
     */
    public synchronized void loadClient(Path destination) throws IOException {
        assert destination != null;
        if (!Files.exists(destination.getParent())) {
            Files.createDirectories(destination.getParent());
        }
        if (!Files.exists(destination)) {
            Files.createFile(destination);
        }
        URL url = new URL(versionInfo.getClientParameter("codebase") + 
                          versionInfo.getClientParameter("initial_jar"));
        URLConnection conn = url.openConnection();

        // Using stream copy with Java NIO Channels. This is at least as fast
        // as manual copy using a byte array as buffer (but may be optimized
        // by native code, as data never needs to pass into the JVM).
        try (ReadableByteChannel reader = 
                    Channels.newChannel(conn.getInputStream());
             WritableByteChannel writer = 
                    Files.newByteChannel(destination,StandardOpenOption.WRITE)) {
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
     * 
     * All {@code Applet} parameters are parsed, as well as all client
     * parameters.
     * 
     * @param userFlow the userflow ID of the client.
     * @param configData the raw data retrieved from the RS servers.
     * @return the RSVersionInfo parsed from the provided data.
     * 
     * @throws IllegalStateException when the configData is not yet loaded.
     */
    private RSVersionInfo parseConfig(String userFlow, String configData) {
        if (configData == null) {
            throw new IllegalStateException();
        }

        Map<String, String> appParams = new HashMap<>(32);
        Map<String, String> cliParams = new HashMap<>(32);
        Scanner sc = new Scanner(configData);

        while (sc.hasNext()) {
            String line = sc.nextLine();
            if (line.startsWith("param=")) {
                int mid = line.indexOf('=', 6);
                String key = line.substring(6, mid);
                String value = line.substring(mid + 1);
                appParams.put(key, value);
            } else {
                int mid = line.indexOf('=');
                if (mid < 0) {
                    // invalid or empty line; skip
                    continue;
                }
                String key = line.substring(0, mid);
                String value = line.substring(mid + 1);
                cliParams.put(key, value);
            }
        }
        LOGGER.log("Config has been parsed");
        return new RSVersionInfo(userFlow, cliParams, appParams);
    }
}
