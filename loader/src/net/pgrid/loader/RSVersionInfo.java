package net.pgrid.loader;

import java.util.HashMap;
import java.util.Map;

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
    
    private final String userFlowID;
    
    private final Map<String, String> clientParameters;
    private final Map<String, String> appletParameters;

    /**
     * Creates a new RSVersionInfo object with the specified information
     * @param userFlowID the userFlow ID assigned to the java config file 
     *                   received from the Runescape servers
     * @param clientParameters a Map with the client parameters
     * @param appletParameters a Map with the Applet parameters
     * @throws IllegalArgumentException when any of the arguments is {@code null}
     */
    public RSVersionInfo(String userFlowID, Map<String, String> clientParameters, Map<String, String> appletParameters) {
        if (userFlowID == null || clientParameters == null || appletParameters == null) {
            throw new IllegalArgumentException("Null value");
        }
        this.userFlowID = userFlowID;
        this.clientParameters = new HashMap<>(clientParameters);
        this.appletParameters = new HashMap<>(appletParameters);
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
        return 173 + 3 * userFlowID.hashCode();
    }

    @Override
    public String toString() {
        return "RSVersionInfo(" + userFlowID + ")";
    }
}
