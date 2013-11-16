package net.pgrid.loader;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * This class checks the information belonging to the client data (as given by the 
 * {@literal jav_config} file), and tries to decide if the current version is 
 * still valid.
 * 
 * Doing so significantly decreases startup time, since the previously downloaded
 * client (and as such the updater file and encryption keys) can be reused.
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
    
    /**
     * The cached File containing the previous encryption keys.
     */
    public static final File KEYS_FILE = new File("cache/keys.dat");
    
    // the old userFlow
    private String userFlow = null;
    // the old encryption keys
    private String oldKey_m1 = null, oldKey_0 = null;
    // the new jav_config file data
    private String configData = null;
    
    /**
     * Attempts to read the previous configuration from the cache.
     * @return true if the required data existed and is valid, false otherwise.
     */
    public boolean parseCacheFile() {
        try {
            Scanner sc = new Scanner(new FileInputStream(KEYS_FILE), "US-ASCII");
            sc.useDelimiter("\r?\n");
            userFlow = sc.next();
            oldKey_0 = sc.next();
            oldKey_m1 = sc.next();
            
            return true; 
        } catch (FileNotFoundException | NoSuchElementException ex) {
            // no previous keys were found or the KEYS_FILE is invalid
            return false;
        }
    }
    
    public void parseJavaConfig() throws IOException {
        try {
            Scanner sc = new Scanner(new URL(JAV_CONFIG + userFlow).openStream(), "US-ASCII");
            sc.useDelimiter("\\A");
            configData = sc.next();
        } catch (NoSuchElementException e) {
            // could not read data. Means that the Scanner is empty
            throw new IOException("Empty response from jav_config", e);
        }
        
        String newKey_m1 = null, newKey_0 = null;
        // Scan through the data for the encryption keys
        int position = 0;
        int length = configData.length();
        do {
            int lineEnd = configData.indexOf('\n', position);
            if (configData.startsWith("param=-1=", position)) {
                newKey_m1 = configData.substring(position + 9, lineEnd);
                if (newKey_0 != null) {
                    break;
                }
            } else if (configData.startsWith("param=0=", position)) {
                newKey_0 = configData.substring(position + 8, lineEnd);
                if (newKey_m1 != null) {
                    break;
                }
            }
            position = lineEnd + 1;
        } while (position > 0 && position < length);
        
        if (newKey_0 != null && newKey_m1 != null) {
            if (newKey_0.equals(oldKey_0) && newKey_m1.equals(oldKey_m1)) {
                
            } else {
                // key mismatch
            }
        } else {
            throw new InputMismatchException("Missing required parameter(s)");
        }
    }
}
