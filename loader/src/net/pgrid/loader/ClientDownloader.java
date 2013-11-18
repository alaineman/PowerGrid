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
import net.pgrid.loader.bridge.ClassMapDownloader;
import net.pgrid.loader.logging.Logger;

/**
 * Downloads the client files from the Runescape servers.
 * <p/>
 * This class contains all functionality required to download the client and 
 * all required parameters for launching it.
 * 
 * @author Chronio
 */
public class ClientDownloader {

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
    
    /**
     * URL of the Runescape config file. It is set in the constructor.
     */
    private URL configURL;
    
    /**
     * ClientData instance that holds all the client info.
     * <p/>
     * 
     */
    private ClientData clientData = new ClientData();

    /**
     * Creates a new ClientDownloader that uses the {@code CONFIG_LINK} as config
     * URL.
     */
    public ClientDownloader() {
        try {
            configURL = new URL(CONFIG_LINK);
        } catch (MalformedURLException e) {
            throw (Error) new InternalError("Invalid CONFIG_LINK constant").initCause(e);
        }
    }
    
    /**
     * Creates a new ClientDownloader that uses the specified URL as config URL.
     * @param configURL the config URL
     * @throws IllegalArgumentException when {@code configURL == null}
     */
    public ClientDownloader(URL configURL) {
        if (configURL == null) {
            throw new IllegalArgumentException();
        }
        this.configURL = configURL;
    }
    
    /**
     * Creates a new ClientDownloader that stores its information in the 
     * specified ClientData object.
     * @param clientData the ClientData object
     * @throws IllegalArgumentException when {@code clientData == null}
     */
    public ClientDownloader(ClientData clientData) {
        this(); // needed to set the configURL
        
        if (clientData == null) {
            throw new IllegalArgumentException();
        }
        this.clientData = clientData;
    }
    
    /**
     * Creates a new ClientDownloader that stores its information in the 
     * specified ClientData object, and gets the configuration info from the 
     * specified configuration URL.
     * @param clientData the ClientData object
     * @param configURL the configuration URL
     * @throws IllegalArgumentException when {@code clientData == null} or
     *         {@code configURL == null}
     */
    public ClientDownloader(ClientData clientData, URL configURL) {
        if (clientData == null || configURL == null) {
            throw new IllegalArgumentException();
        }
        this.configURL  = configURL;
        this.clientData = clientData;
    }
    
    /**
     * @return the codebase as an URL instance, or null if the config is not 
     *         yet loaded or the URL is invalid.
     */
    public URL getCodeBaseUrl() {
        String codebase = clientData.getClientParameter("codebase");
        if (codebase != null) {
            try {
                return new URL(codebase);
            } catch (MalformedURLException e) {}
        }
        return null;
    }

    /**
     * Returns the value for the Applet parameter with the given key.
     * @param key the Applet parameter key
     * @return the value for the given key, or null if the key does not exist.
     */
    public String getAppletParameter(String key) {
        return clientData.getAppletParameter(key);
    }
    
    /**
     * Returns the value for the client parameter with the given key.
     * @param key the client parameter key
     * @return the value for the given key, or null if the key does not exist.
     */
    public String getClientParameter(String key) {
        return clientData.getClientParameter(key);
    }
    
    /**
     * @return the client download link, or null if the config data has not yet
     *         been parsed.
     */
    public String getDownloadLink() {
        return clientData.getDownloadLink();
    }

    /**
     * Returns a ClientData instance with the data collected by this 
     * ClientDownloader.
     * <p/>
     * This ClientDownloader is not backed by the returned ClientData, so changes
     * in the ClientData instance are not reflected in this ClientDownloader.
     * <p/>
     * @return a ClientData instance containing the data collected by this 
     *         ClientDownloader.
     */
    public ClientData getClientData() {
        return new ClientData(clientData);
    }

    /**
     * Loads the config file if it was not already downloaded.
     *
     * @throws IOException if the download failed
     */
    public void loadConfig() throws IOException {
        if (!clientData.readyForDownload()) {
            try (InputStream in = configURL.openStream()) {
                // using a Scanner with the right delimiter provides the entire 
                // content of the stream at once in only a few lines.
                Scanner out = new Scanner(Channels.newChannel(in), ClassMapDownloader.CHARSET.name()).useDelimiter("\\A");
                if (out.hasNext()) {
                    parseConfig(out.next());
                } else {
                    throw new RuntimeException("Empty response getting config file");
                }
            }
        }
    }

    /**
     * Downloads the client using the previously downloaded config.
     *
     * @throws IOException if the download failed
     * @throws IllegalStateException when the client data is not available
     */
    public void loadClient() throws IOException {
        if (!clientData.readyForDownload()) {
            throw new IllegalStateException();
        }
        
        RSVersionManager versionManager = new RSVersionManager();
        if (versionManager.compareAndUpdate(CONFIG_LINK, CONFIG_LINK)) {
            // the keys are still valid, so skip downloading.
            return;
        }
        
        
        URL url = new URL(clientData.getDownloadLink());
        URLConnection conn = url.openConnection();

        // Using stream copy with Java NIO Channels. This is at least as fast
        // as manual copy using a byte array as buffer.
        try (InputStream in = conn.getInputStream(); 
             FileOutputStream out = new FileOutputStream("client.jar")) {
            
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
     * All {@code Applet} parameters are parsed, as well as all client 
     * parameters.
     * <p/>
     * @throws IllegalStateException when the configData is not yet loaded.
     */
    private void parseConfig(String configData) {
        if (configData == null) {
            throw new IllegalStateException();
        }
        if (clientData.hasAppletParameters() && clientData.hasClientParameters()) {
            // This method will do nothing useful in this case.
            return;
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
                    // invalid line; skip
                    continue;
                }
                String key = line.substring(0, mid);
                String value = line.substring(mid + 1);
                cliParams.put(key, value);
            }
        }
        if (!clientData.hasAppletParameters()) {
            clientData.setAppletParameters(appParams);
        }
        if (!clientData.hasClientParameters()) {
            clientData.setClientParameters(cliParams);
        }
        
        LOGGER.log("Config has been parsed");
    }
}
