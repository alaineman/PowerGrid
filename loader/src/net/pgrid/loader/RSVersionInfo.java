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

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import net.pgrid.loader.logging.Logger;

/**
 * This class represents information that describes the Runescape client and 
 * its parameters. 
 * <p/>
 * This class is used for looking up parameters required for the client to start 
 * and to provide version information based on the client's encryption keys.
 * <p/>
 * In general, it can be assumed that the same encryption keys for different 
 * clients means that they're actually the same client. Similarly, if two 
 * RSVersionInfo objects are equal according to their {@code equals(Object)} method,
 * they represent the same Runescape client.
 * @author Patrick Kramer
 */
public class RSVersionInfo {
    private static final Logger LOGGER = Logger.get("VERSIONING");
    
    private final String userFlowID;
    
    private final Map<String, String> clientParameters;
    private final Map<String, String> appletParameters;

    private final boolean local;
    
    /**
     * Creates a new RSVersionInfo object with the specified information.
     * 
     * Neither parameter should be null, and the {@code clientParameters} Map
     * should contain non-null values for the keys "0" and "-1".
     * 
     * @param userFlowID the userFlow ID assigned to the java config file 
     *                   received from the Runescape servers
     * @param clientParameters a Map with the client parameters
     * @param appletParameters a Map with the Applet parameters
     * @throws IllegalArgumentException when any of the arguments is invalid
     */
    public RSVersionInfo(String userFlowID, Map<String, String> clientParameters, 
                         Map<String, String> appletParameters) {
        this(userFlowID, clientParameters, appletParameters, false);
    }
    
    private RSVersionInfo(String userFlowID, Map<String, String> client,
                          Map<String, String> applet, boolean local) {
        if (userFlowID == null || client == null 
         || applet == null || !applet.containsKey("0")
         || !applet.containsKey("-1")) {
            throw new IllegalArgumentException("Null value");
        }
        this.userFlowID = userFlowID;
        this.clientParameters = new HashMap<>(client);
        this.appletParameters = new HashMap<>(applet);
        this.local = local;
    }

    public boolean isLocal() {
        return local;
    }
    
    /**
     * @return the userFlow ID
     */
    public String getUserFlowID() {
        return userFlowID;
    }
    
    /**
     * @return the encryption key labeled {@code "0"}.
     */
    public String getEncryptionKey0() {
        return appletParameters.get("0");
    }
    
    /**
     * @return the encryption key labeled {@code "-1"}.
     */
    public String getEncryptionKeyM1() {
        return appletParameters.get("-1");
    }
    
    /**
     * Returns the client parameter with the specified key
     * @param key the key
     * @return the value belonging to the specified key, or null if the key was 
     *         not found
     */
    public String getClientParameter(String key) {
        return clientParameters.get(key);
    }
    
    /**
     * Returns the Applet parameter with the specified key
     * @param key the key
     * @return the value belonging to the specified key, or null if the key was 
     *         not found
     */
    public String getAppletParameter(String key) {
        return appletParameters.get(key);
    }
    
    public void writeTo(Path destination) throws IOException {
        if (!Files.exists(destination.getParent())) {
            Files.createDirectories(destination);
        }
        try (PrintStream out = new PrintStream(
                Files.newOutputStream(destination), false, "UTF-8")) {
            out.println(getUserFlowID());
            out.println(getEncryptionKey0());
            out.println(getEncryptionKeyM1());
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null && obj.getClass() == getClass()) {
            RSVersionInfo that = (RSVersionInfo) obj;
            return getEncryptionKey0().equals(that.getEncryptionKey0()) &&
                   getEncryptionKeyM1().equals(that.getEncryptionKeyM1());
        }
        return false;
    }

    @Override
    public int hashCode() {
        return 173 + 3 * getEncryptionKey0().hashCode()
                   + 5 * getEncryptionKeyM1().hashCode();
    }

    @Override
    public String toString() {
        return "RSVersionInfo(" + userFlowID + ")";
    }
    
    /**
     * Constructs an RSVersionInfo instance based on the version file at the 
     * provided Path.
     * @param origin the Path to read from
     * @return a RSVersionInfo instance with the information from the origin
     *         Path, or null if constructing the instance failed (for any reason)
     */
    public static RSVersionInfo fromPath(Path origin) {
        assert origin != null;
        try {
            Scanner sc = new Scanner(Files.newByteChannel(origin), "UTF-8");
            sc.useDelimiter("\r?\n"); // matches both LF and CR/LF line endings
            String userFlow = sc.next();
            String oldKey_0 = sc.next();
            String oldKey_m1 = sc.next();
            
            Map<String, String> appletParamStub = new HashMap<>(4);
            appletParamStub.put("0",  oldKey_0);
            appletParamStub.put("-1", oldKey_m1);
            return new RSVersionInfo(userFlow,new HashMap<>(2),appletParamStub,true); 
        } catch (FileNotFoundException ex) {
            // no previous keys were found or the KEYS_FILE is invalid
            LOGGER.log("Could not find old keys at ", ex.getLocalizedMessage());
            return null;
        } catch (NoSuchElementException ex) {
            LOGGER.log("The keys file \"", origin.toString(), "\" is invalid");
            return null;
        } catch (IOException iox) {
            LOGGER.log("I/O error while readin keys file");
            return null;
        }
    }
}
