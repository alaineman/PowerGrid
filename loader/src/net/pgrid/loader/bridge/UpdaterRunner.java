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

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import net.pgrid.loader.logging.Logger;

/**
 * Runnable class that combines and executes all updater-related actions.
 * 
 * @author Patrick Kramer
 */
public class UpdaterRunner implements Runnable {

    private static final Logger LOGGER = Logger.get("UPDATER");
    
    /**
     * The default destination File.
     */
    public static final File DESTINATION = new File("cache", "updaterInfo.dat");
    
    public static final String DEFAULT_SERVER = "http://pgrid.net/marneus/newupdater/";
    
    private final String updaterServer;
    private final boolean useLocal;
    private final boolean profile;

    /**
     * Creates a new UpdaterRunner object.
     * 
     * @param useLocal true to use local updater data, false to call the Updater server
     * @param profile true to profile the updater and print the results, false to disable
     */
    public UpdaterRunner(boolean useLocal, boolean profile) {
        this(DEFAULT_SERVER, useLocal, profile);
    }
    
    /**
     * Creates a new UpdaterRunner object.
     * 
     * 
     * @param server the Updater server address
     * @param useLocal true to use local updater data, false to call the Updater server
     * @param profile true to profile the updater and print the results, false to disable
     */
    public UpdaterRunner(String server, boolean useLocal, boolean profile) {
        if (!useLocal && server == null) {
            throw new IllegalArgumentException("Null server not allowed when not running locally");
        }
        this.updaterServer = server;
        this.useLocal = useLocal;
        this.profile = profile;
    }
    
    /**
     * Runs the Updater client class.
     * 
     * This collects the Updater information from the server (or re-uses the 
     * local updater data) and passes it to the native client.
     */
    @Override
    public synchronized void run() {
        try {
            long timeStarted = profile ? System.currentTimeMillis() : 0;
            
            byte[] data;
            if (useLocal) {
                data = getLocalData();
            } else {
                data = getRemoteData(updaterServer);
            }
            // Tell the native code the updater is done
            signalUpdaterReady(data);
            
            if (profile) {
                long timeTaken = System.currentTimeMillis() - timeStarted;
                LOGGER.log("Updater took " + (timeTaken/1000d) + "s to finish");
            }
        } catch (IOException e) {
            LOGGER.log("Failed to save the updater data", e);
        }
    }
    
    /**
     * Tries to load the local updater data (stored at {@code DESTINATION}).
     * @return the loaded data.
     * 
     * @throws IOException when reading the data failed.
     * @throws FileNotFoundException when the File does not exist.
     */
    protected byte[] getLocalData() throws IOException {
        Path dest = DESTINATION.toPath();
        if (Files.exists(dest)) {
            byte[] data = Files.readAllBytes(dest);
            LOGGER.log("Re-used local updater data");
            return data;
        } else {
            LOGGER.log("[WARNING] Local client re-used but no updater data available!");
            throw new FileNotFoundException(DESTINATION.getPath());
        }
    }
    
    /**
     * Tries to load the remote updater data from the specified server.
     * @param server the server to connect to
     * @return the loaded data
     * @throws IOException if reading from the server failed for some reason, 
     *                     or if {@code DESTINATION} is not writable.
     */
    protected byte[] getRemoteData(String server) throws IOException {
        byte[] data = new Updater(server).getData();
        if (!DESTINATION.isFile() && !DESTINATION.createNewFile()) {
            throw new IOException("Could not write to File: " + DESTINATION.getPath());
        }
        try (FileOutputStream out = new FileOutputStream(DESTINATION)) {
            out.write(data);
        }
        LOGGER.log("Updater data acquired (" + data.length + " bytes)");
        return data;
    }
    
    /**
     * Notifies the C++ client the updater is ready.
     * 
     * This will parse and store the updater data.
     * 
     * @param checksum the checksum of the client
     * @param data the bytes of the updater data.
     */
    private static native void signalUpdaterReady(byte[] data);
}
