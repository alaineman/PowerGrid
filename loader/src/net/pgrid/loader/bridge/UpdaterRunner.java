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

import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.UnknownHostException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import net.pgrid.loader.util.Logger;

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
    public static final Path DESTINATION = Paths.get("cache", "updaterInfo.dat");
    
    public static final String DEFAULT_SERVER = "http://pgrid.net/marneus/";
    
    private final boolean useLocal;
    private final boolean profile;

    /**
     * Creates a new UpdaterRunner object.
     * 
     * @param useLocal true to use local updater data, false to call the Updater server
     * @param profile true to profile the updater and print the results, false to disable
     */
    public UpdaterRunner(boolean useLocal, boolean profile) {
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
        long timeStarted = profile ? System.currentTimeMillis() : 0;
        try {
            byte[] data;
            if (useLocal) {
                data = getLocalData();
            } else {
                data = getRemoteData();
            }
            signalUpdaterReady(data);
        } catch (FileNotFoundException | UnknownHostException e) {
            // Indicating "useLocal" is true and the file "cache/updaterInfo.dat" 
            // does not exist, or "useLocal" is false and no updater data file 
            // exists at the expected URL (or the updater server is offline).
            // The message contains the URL that could not been found in these 
            // cases.
            LOGGER.log("[CRITICAL] Updater data not found at: ", e.getMessage());
            signalUpdaterFailed();
        } catch (IOException e) {
            // Indicates any other kind of I/O error while reading or writing 
            // the updater info file.
            LOGGER.log("[CRITICAL] Failed to save the updater data", e);
            signalUpdaterFailed();
        }
        if (profile) {
            long timeTaken = System.currentTimeMillis() - timeStarted;
            LOGGER.log("Updater took " + (timeTaken/1000d) + "s to finish");
        }
    }
    
    /**
     * Tries to load the local updater data (stored at {@code DESTINATION}).
     * 
     * If no local data exists, or the data is invalid, this method connects to 
     * the updater server to download the missing updater data.
     * 
     * @return the loaded data.
     * 
     * @throws IOException when reading the data failed, or .
     */
    protected byte[] getLocalData() throws IOException {
        if (Files.exists(DESTINATION)) {
            byte[] data = Files.readAllBytes(DESTINATION);
            LOGGER.log("Re-used local updater data");
            return data;
        } else {
            LOGGER.log("[WARNING] Local client re-used but no updater data available!" 
                    +  "          Trying to download updater data from server...");
            return getRemoteData();
        }
    }
    
    /**
     * Tries to load the remote updater data.
     * 
     * @return the loaded data
     * @throws IOException if reading from the server failed for some reason, 
     *                     or if {@code DESTINATION} is not writable.
     */
    protected byte[] getRemoteData() throws IOException {
        byte[] data = new Updater().getData();
        if (!Files.isRegularFile(DESTINATION)) {
            Files.createFile(DESTINATION);
        }
        Files.write(DESTINATION, data);
        LOGGER.log("Remote updater data downloaded (" + data.length + " bytes)");
        return data;
    }
    
    /**
     * Notifies the C++ client the updater is ready.
     * 
     * This will parse and store the updater data.
     * 
     * @param data the bytes of the updater data.
     */
    private static native void signalUpdaterReady(byte[] data);
    
    /**
     * Notifies the C++ client the updater failed to retrieve 
     * the required data. 
     * 
     * This will cause the C++ client to disable most bot-related functionality,
     * as it cannot be used without the updater data (the client can only be
     * used as a 'normal' standalone RS client).
     */
    private static native void signalUpdaterFailed();
}
