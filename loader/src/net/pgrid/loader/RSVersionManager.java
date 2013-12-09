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
        } catch (FileNotFoundException | NoSuchElementException ex) {
            // no previous keys were found or the KEYS_FILE is invalid
            LOGGER.log("Could not find old keys", ex);
            return null;
        }
    }
    /**
     * Compares the two given versions, and writes the new version information 
     * to KEYS_FILE.
     * 
     * @param oldVersion the old version info
     * @param newVersion the new version info
     * @return true if and only if the two versions are in fact the same, false otherwise
     * @throws NullPointerException when one of the RSVersionInfo objects is null
     * @throws IOException if an I/O error occurred.
     */
    public boolean checkVersions(RSVersionInfo oldVersion, RSVersionInfo newVersion) throws IOException {
        String newKey_0 = newVersion.getEncryptionKey0();
        String newKey_m1 = newVersion.getEncryptionKeyM1();
        boolean match = newKey_0.equals(oldVersion.getEncryptionKey0()) 
                    && newKey_m1.equals(oldVersion.getEncryptionKeyM1());
        
        // update the keys.dat File.
        if (KEYS_FILE.getParentFile().mkdirs()) {
            LOGGER.log("Created cache directory");
        }
        if (KEYS_FILE.isFile() || KEYS_FILE.createNewFile()) {
            try (PrintStream out = new PrintStream(KEYS_FILE, "UTF-8")) {
                out.println(newVersion.getUserFlowID()); // write the new userflow id to the file.
                out.println(newKey_0);
                out.println(newKey_m1);
                
                out.flush();
            } catch (IOException ex) {
                LOGGER.log("Failed to update keys");
                throw ex;
            }
            if (!match) {
                LOGGER.log("Encryption keys have been updated");
            }
        } else {
            LOGGER.log("Could not create keys.dat file");
        }
        return match;
    }
}
