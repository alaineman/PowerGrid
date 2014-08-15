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

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import net.pgrid.loader.logging.Logger;

/**
 * This class checks the information belonging to the client data (as given by the 
 * {@literal jav_config} file), and tries to decide if the current version is 
 * still valid.
 * 
 * Doing so significantly decreases startup time, since the previously downloaded
 * client (and as such the updater file) can be reused.
 * 
 * @author Patrick Kramer
 */
public class RSVersionManager {
    private static final Logger LOGGER = Logger.get("VERSIONING");
    
    /**
     * Prefix for requesting the {@literal jav_config} file with a specific 
     * userFlow id.
     */
    public static final String JAV_CONFIG = "http://www.runescape.com/l=0/jav_config.ws?userFlow=";
    
    /**
     * The cached File containing the previous encryption keys.
     */
    public static final File KEYS_FILE = new File("cache/keys.dat");

    /**
     * Attempts to read the previous configuration from the cache.
     * @return the required data if it existed and is valid, null otherwise.
     */
    public RSVersionInfo getCurrentVersion() {
        return getVersion(KEYS_FILE);
    }
    
    /**
     * Attempts to read RSVersion information from the given file.
     * @param cacheFile the file to read from
     * @return the RSVersionInfo object representing the version information,
     *         or null if the information could not be read.
     */
    public RSVersionInfo getVersion(File cacheFile) {
        try {
            Scanner sc = new Scanner(new FileInputStream(cacheFile), "UTF-8");
            sc.useDelimiter("\r?\n"); // matches both LF and CR/LF line endings
            String userFlow = sc.next();
            String oldKey_0 = sc.next();
            String oldKey_m1 = sc.next();
            
            Map<String, String> appletParamStub = new HashMap<>(4);
            appletParamStub.put("0",  oldKey_0);
            appletParamStub.put("-1", oldKey_m1);
            return new RSVersionInfo(userFlow, 
                    new HashMap<String, String>(2), appletParamStub); 
        } catch (FileNotFoundException ex) {
            // no previous keys were found or the KEYS_FILE is invalid
            LOGGER.log("Could not find old keys at ", ex.getLocalizedMessage());
            return null;
        } catch (NoSuchElementException ex) {
            LOGGER.log("The keys file \"", KEYS_FILE, "\" is invalid");
            return null;
        }
    }
    
    /**
     * Compares the two given versions, and returns whether the two versions are
     * the same
     * 
     * @param a the old version info
     * @param b the new version info
     * @return true if and only if the two versions are in fact the same, false otherwise
     * @throws NullPointerException when one of the RSVersionInfo objects is null
     */
    public boolean checkVersions(RSVersionInfo a, RSVersionInfo b) {
        return b.getEncryptionKey0() .equals(a.getEncryptionKey0()) 
            && b.getEncryptionKeyM1().equals(a.getEncryptionKeyM1());
    }
    
    /**
     * Writes the specified version info to the cache File.
     * @param info the version info
     * @throws IOException when writing the cache file failed
     */
    public void writeCurrentVersion(RSVersionInfo info) throws IOException {
        writeVersion(KEYS_FILE, info);
    }
    
    /**
     * Writes the specified version information to the given File
     * @param destination the destination File
     * @param info the RSVersionInfo object
     * @throws IOException when writing the version info fails
     */
    public void writeVersion(File destination, RSVersionInfo info) throws IOException {
        File folder = destination.getParentFile();
        if (!folder.isDirectory() && !folder.mkdirs()) {
            throw new IOException("Failed to create required directories");
        }
        try (PrintStream out = new PrintStream(destination, "UTF-8")) {
            out.println(info.getUserFlowID());
            out.println(info.getEncryptionKey0());
            out.println(info.getEncryptionKeyM1());
        }
    }
}
