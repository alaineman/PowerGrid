package net.pgrid.loader;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
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
 * To do this, we have to keep track of the userFlow id, assigned by the 
 * Runescape servers to distinct between different users. We can request the 
 * {@literal jav_config} file for the same userFlow id. This file will then 
 * contain the same encryption keys if (and only if) the new Runescape client 
 * is the same version as one we have in cache.
 * @author Patrick Kramer
 */
public class RSVersionManager {
    
    /**
     * Prefix for requesting the {@literal jav_config} file with a specific 
     * userFlow id.
     */
    public static final String JAV_CONFIG = "http://www.runescape.com/l=3/k=0/jav_config.ws?userFlow=";
    
    private static final Logger LOGGER = Logger.get("VERSIONING");
    
    /**
     * The cached File containing the previous encryption keys.
     */
    public static final File KEYS_FILE = new File("cache/keys.dat");
    
    // the old userFlow
    private String userFlow = null;
    // the old encryption keys
    private String oldKey_m1 = null, oldKey_0 = null;

    /**
     * Attempts to read the previous configuration from the cache.
     * @return true if the required data existed and is valid, false otherwise.
     */
    public boolean parseCacheFile() {
        try {
            Scanner sc = new Scanner(new FileInputStream(KEYS_FILE), "US-ASCII");
            sc.useDelimiter("\r?\n"); // matches both LF and CR/LF line endings
            userFlow = sc.next();
            oldKey_0 = sc.next();
            oldKey_m1 = sc.next();
            
            return true; 
        } catch (FileNotFoundException | NoSuchElementException ex) {
            // no previous keys were found or the KEYS_FILE is invalid
            LOGGER.log("Could not find old keys");
            return false;
        }
    }

    public boolean hasUserFlow() {
        return userFlow != null;
    }

    public void setUserFlow(String userFlow) {
        this.userFlow = userFlow;
    }
    
    /**
     * @return the userFlow id
     */
    public String getUserFlow() {
        return userFlow;
    }
    
    public String getUserFlowLink() {
        return JAV_CONFIG + userFlow;
    }
    
    /**
     * Parses the Java config file and compares the new keys with the stored keys.
     * 
     * If no previous keys are known, this method first tries to load them using 
     * the {@code parseCacheFile()} method.
     * 
     * If the keys do not match, the keys are updated with the parameter keys.
     * @param newKey_0  the encryption key with parameter id 0
     * @param newKey_m1 the encryption key with parameter id -1
     * @return true if and only if the stored keys match the new keys, false otherwise
     * @throws NullPointerException when one of the keys is null
     * @throws IOException if an I/O error occurred.
     */
    public boolean compareAndUpdate(String newKey_0, String newKey_m1) throws IOException {
        
        if (userFlow != null && parseCacheFile() && 
                newKey_0.equals(oldKey_0) && newKey_m1.equals(oldKey_m1)) {
            // The keys are equal, so we can re-use the client.
            LOGGER.log("Encryption keys match: local RS client will be re-used");
            return true;
        } else {
            // key mismatch; update the outdated keys
            if (KEYS_FILE.getParentFile().mkdirs()) {
                LOGGER.log("Created cache directory");
            }
            if (KEYS_FILE.exists() || KEYS_FILE.createNewFile()) {
                try (PrintStream out = new PrintStream(KEYS_FILE, "US-ASCII")) {
                    out.println(userFlow);
                    out.println(newKey_0);
                    out.println(newKey_m1);
                }
                oldKey_0  = newKey_0;
                oldKey_m1 = newKey_m1;
                LOGGER.log("Updated encryption keys");
            } else {
                LOGGER.log("Could not create keys.dat file");
            }
            return false;
        }
    }
}
