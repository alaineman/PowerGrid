package powergrid.core;

import java.applet.Applet;
import java.net.URL;

/**
 * Loads the RS client and provides access methods to interact with the client.
 * @author Chronio
 */
public class RSAccessor {

    
    private URL base;
    private Applet rsClient = null;
    
    /**
     * Creates a new RSAccessor instance.
     * @param base The base URL to load from
     */
    public RSAccessor(URL base) {
        assert base != null;
        this.base = base;
    }

    /**
     * Returns the running RS Applet.
     * @return the Runescape Applet
     */
    public Applet getRSClient() {
        return rsClient;
    }
    
    /**
     * Returns whether the client has been loaded.
     * @return true if the client has been loaded, false otherwise.
     */
    public boolean isLoaded() {
        return rsClient != null;
    }

    /**
     * Returns the URL used as the base for loading the client.
     * @return the base URL
     */
    public URL getBaseURL() {
        return base;
    }
    
    /**
     * Loads the Runescape client Applet and runs it.
     */
    public void load() {
        HTTPClient client = new HTTPClient(getBaseURL());
        // TODO implement navigation through RS pages to find the loader.
    }
    
}
