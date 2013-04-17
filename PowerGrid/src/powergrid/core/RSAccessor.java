package powergrid.core;

import java.applet.Applet;
import java.io.IOException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.regex.Matcher;
import static powergrid.PowerGrid.LOGGER;

/**
 * Loads the RS client and provides access methods to interact with the client.
 * @author Chronio
 */
public class RSAccessor {

    
    private URL base;
    private Applet rsClient = null;
    
    private byte[] loader = null;
    
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
     * Navigates the Runescape site to fetch the loader, then downloads and 
     * runs it.
     * @return true if and only if the operation was successful, false otherwise.
     */
    public boolean load() {
        HTTPClient client = new HTTPClient(getBaseURL());
        try {
            client.follow(new URL(getBaseURL().toString() + "game.ws?j=1"));
            // find the source of the frame's contents
            URL url = client.findAndFollow("src=\"(.*)\" frameborder");
            // find the java archive this source links to
            String archiveLink = client.findFirst("archive=(.*) ", 1);
            url = new URL(url.getProtocol() + "://" + 
                    url.getHost() + "/" + archiveLink);
            String className = client.findFirst("code=(.*) ", 1);
            HashMap<String, String> params = new HashMap<>(16, 7/8f);
            Matcher m = client.find("<param name=\"([^\\s]+)\"\\s+value=\"([^>]*)\">");
            while (m.find()) {
                params.put(m.group(1), m.group(2));
            }
            if (params.containsKey("haveie6")) {
                params.put("haveie6", "false");
            }
            return setupLoader(client, url, className, params);
        } catch (IOException e) {
            LOGGER.log(Level.SEVERE, 
                   "An Exception occurred while loading RS client", e);
        } catch (IllegalStateException e) {
            LOGGER.log(Level.SEVERE, 
                   "Required data not found in URL: " + client.getCurrent(), e);
        }
        return false;
    }
    
    /**
     * Downloads the Runescape Loader from the given URL, then instantiates it 
     * using the given className and parameters.
     * @param client the HTTPClient to use
     * @param url the URL to load from
     * @param className the name of the class to run
     * @param params the Applet parameters
     * @return 
     */
    private boolean setupLoader(HTTPClient client, URL url, String className, 
            Map<String, String> params) {
        
        return false;
    }
    
}
