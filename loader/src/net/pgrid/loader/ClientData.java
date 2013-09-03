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

import java.applet.Applet;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

/**
 * This class represents the data of the Runescape client. 
 * <p/>
 * It holds the parameters provided to the Applet, as well as the client data 
 * itself and the Applet instance.
 * <p/>
 * Instances of this class can be created empty and then filled with the data as required.
 * It is, however, not possible to overwrite existing data, since the setter methods
 * of this class will throw IllegalStateExceptions in that case.
 * <p/>
 * @author Patrick Kramer
 */
public class ClientData {
    
    private Map<String,String> clientParameters;
    private Map<String,String> appletParameters;
    private String downloadLink;
    private Applet applet;
    
    /**
     * Creates an empty ClientData object.
     */
    public ClientData() {}
    
    /**
     * Copy constructor.
     * <p/>
     * Creates a new ClientData object based on the provided ClientData.
     * @param data the ClientData object to copy from
     */
    public ClientData(ClientData data) {
        clientParameters = new HashMap<>(data.getClientParameters());
        appletParameters = new HashMap<>(data.getAppletParameters());
        
        downloadLink = data.getDownloadLink();
        applet = data.getApplet();
    }
    
    /**
     * Creates a new ClientData object containing the provided data.
     * @param cParams the client parameters
     * @param aParams the Applet parameters
     * @param dlLink  the client download link
     * @param app     the Applet instance
     */
    public ClientData (Map<String, String> cParams, Map<String, String> aParams, 
            String dlLink, Applet app) {
        clientParameters = cParams;
        appletParameters = aParams;
        downloadLink = dlLink;
        applet = app;
    }

    /**
     * @return the Applet instance, or null if none was set
     */
    public Applet getApplet() {
        return applet;
    }

    /**
     * Returns the Applet parameter value for the given key.
     * <p/>
     * If there is no parameter with the given key, or the Applet parameters 
     * are not set, this method returns null.
     * @param key the parameter key
     * @return the value belonging to the key, or null if no such key is known
     */
    public String getAppletParameter(String key) {
        return (appletParameters == null ? null : appletParameters.get(key));
    }

    /**
     * Returns the client parameter value for the given key.
     * <p/>
     * If there is no parameter with the given key, or the client parameters 
     * are not set, this method returns null.
     * @param key the parameter key
     * @return the value belonging to the key, or null if no such key is known
     */
    public String getClientParameter(String key) {
        return (clientParameters == null ? null : clientParameters.get(key));
    }

    /**
     * @return the client's download link, or null if none was set
     */
    public String getDownloadLink() {
        return downloadLink;
    }

    /**
     * @return a Map containing the Applet parameters
     */
    public Map<String, String> getAppletParameters() {
        return (appletParameters == null ? null :
                Collections.unmodifiableMap(appletParameters));
    }
    
    /**
     * @return true if and only if Applet parameters have been stored in this
     *         ClientData object, false otherwise
     */
    public boolean hasAppletParameters() {
        return appletParameters != null;
    }

    /**
     * @return a Map containing the client parameters
     */
    public Map<String, String> getClientParameters() {
        return (clientParameters == null ? null : 
                Collections.unmodifiableMap(clientParameters));
    }
    
    /**
     * @return true if and only if client parameters have been stored in this
     *         ClientData object, false otherwise
     */
    public boolean hasClientParameters() {
        return clientParameters != null;
    }

    /**
     * Sets the Applet instance.
     * <p/>
     * The provided Applet may be null, in which case this method does nothing.
     * @param a the Applet instance.
     * @throws IllegalStateException when the Applet was already set
     */
    public void setApplet(Applet a) {
        if (applet != null) {
            throw new IllegalStateException();
        }
        applet = a;
    }
    
    /**
     * Sets the download link for the client.
     * <p/>
     * The provided String may be null, in which case this method does nothing.
     * @param dlLink the download link
     * @throws IllegalStateException when the download link was already set
     */
    public void setDownloadLink(String dlLink) {
        if (downloadLink != null) {
            throw new IllegalStateException();
        }
        downloadLink = dlLink;
    }

    /**
     * Sets the parameters of the Applet instance.
     * <p/>
     * The Map may be null, in which case this method does nothing.
     * @param params the Applet parameters
     * @throws IllegalStateException when the Applet parameters were already set
     */
    public void setAppletParameters(Map<String, String> params) {
        if (appletParameters != null) {
            throw new IllegalStateException();
        }
        appletParameters = params;
    }
    
    /**
     * Sets the client parameters.
     * <p/>
     * The Map may be null, in which case this method does nothing.
     * @param params the client parameters
     * @throws IllegalStateException when the client parameters were already set
     */
    public void setClientParameters(Map<String, String> params) {
        if (clientParameters == null) {
            throw new IllegalStateException();
        }
        clientParameters = params;
    }

    public boolean readyForDownload() {
        return (clientParameters != null && appletParameters != null && 
                downloadLink != null);
    }
    
    public boolean readyForLaunch() {
        return readyForDownload() && applet != null;
    }
    
    @Override
    public boolean equals(Object obj) {
        if (obj != null && obj.getClass() == getClass()) {
            ClientData that = (ClientData) obj;
            return Objects.equals(this.getApplet(), that.getApplet()) &&
                   Objects.equals(this.getDownloadLink(), that.getDownloadLink()) &&
                   Objects.equals(this.getAppletParameters(), that.getAppletParameters()) &&
                   Objects.equals(this.getClientParameters(), that.getClientParameters());
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 67 * hash + Objects.hashCode(this.clientParameters);
        hash = 67 * hash + Objects.hashCode(this.appletParameters);
        hash = 67 * hash + Objects.hashCode(this.downloadLink);
        hash = 67 * hash + Objects.hashCode(this.applet);
        return hash;
    }

    @Override
    public String toString() {
        return "<ClientData[" + clientParameters + "," + appletParameters + ","
             + downloadLink + "," + applet + "]>";
    }
    
}
