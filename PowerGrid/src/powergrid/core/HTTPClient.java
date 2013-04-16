package powergrid.core;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Navigates web pages and follows links, simulating an actual browser.
 * <p/>
 * The page content is decoded before it is returned, so it is advised to use
 * this class when handling server connections with encoded responses.
 *
 * @author Chronio
 */
public class HTTPClient {

    /**
     * The default client for HTTPClient connections. It resembles a Mozilla
     * browser running Windows 7.
     */
    public static final String DEFAULT_AGENT =
            "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; "
            + (System.getProperty("sun.arch.data.model").equals("64") ? "WOW64 " : "")
            + "Trident/5.0)";
    
    private URL current;
    private String useragent;
    private URL previous;
    private URL contentURL;
    private String contents;

    /**
     * Creates a new HTTPClient that starts navigating at the specified URL.
     *
     * @param startURL the URL to start navigating from
     */
    public HTTPClient(URL startURL) {
        assert startURL != null;
        current = startURL;
        contentURL = null;
        previous = null;
        contents = null;
        useragent = DEFAULT_AGENT;
    }

    /**
     * Scans through the contents and returns a list of all substrings that
     * match the given regular expression.
     *
     * @param pattern the regular expression to scan for
     * @return a List of all classes matching the given regular expression
     * @throws IOException when the contents of the page could not be loaded
     */
    public List<String> find(String pattern) throws IOException {
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(getContents());
        ArrayList<String> results = new ArrayList<>();
        while (m.find()) {
            results.add(m.group());
        }
        return results;
    }

    /**
     * Fetches and returns the contents of the current URL.
     * <p/>
     * Successive calls do not reconnect with the server, but instead use cached
     * data.
     *
     * @return the contents of the current URL
     * @throws IOException when the loading failed.
     */
    public String getContents() throws IOException {
        if (!contentsLoaded()) {
            HttpURLConnection conn = createConnection();
            Object loaded = conn.getContent();
            if (loaded instanceof String) {
                contents = (String) loaded;
            } else {
                throw new UnsupportedOperationException("Unsupported content type");
            }
        }
        return contents;
    }

    /**
     * Returns whether the contents have been loaded.
     *
     * @return true if the contents have been loaded, false otherwise.
     */
    public boolean contentsLoaded() {
        return current.equals(contentURL);
    }

    /**
     * Returns the URL this HTTPClient is at.
     *
     * @return the HTTPClient's current URL
     */
    public URL getCurrent() {
        return current;
    }

    /**
     * Returns the active user agent.
     *
     * @return the user agent used for making connections.
     */
    public String getUserAgent() {
        return useragent;
    }

    /**
     * Returns the previous URL (referer) of this HTTPClient.
     *
     * @return the previous URL
     */
    public URL getPrevious() {
        return previous;
    }

    /**
     * Sets the current URL to point to the given next location and fetches the
     * URL's contents from the server.
     *
     * @param next the next URL to visit
     * @return itself for fluency
     * @throws IOException When the given URL could not be loaded.
     */
    public HTTPClient follow(URL next) throws IOException {
        assert next != null;
        if (!contentsLoaded()) {
            getContents();
        }
        previous = current;
        current = next;
        getContents();
        return this;
    }

    /**
     * Sets the user agent that is used for navigating.
     *
     * @param agent a String describing the user agent
     */
    public void setUserAgent(String agent) {
        assert agent != null && !agent.isEmpty();
        useragent = agent;
    }

    /**
     * Creates an URLConnection to the current URL.
     *
     * @return the created URLConnection
     * @throws IOException when the connection could not be created.
     */
    protected HttpURLConnection createConnection() throws IOException {
        HttpURLConnection conn = (HttpURLConnection) getCurrent().openConnection();
        conn.addRequestProperty("Host", getCurrent().getHost());
        conn.addRequestProperty("User-Agent", getUserAgent());
        conn.addRequestProperty("Accept-Encoding", "gzip,deflate");
        conn.addRequestProperty("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
        conn.addRequestProperty("Connection", "close");
        URL prev = getPrevious();
        if (prev != null) {
            conn.addRequestProperty("Referer", prev.toString());
        }
        conn.setConnectTimeout(10000);
        return conn;
    }

    /**
     * Returns a direct InputStream for the current URL. Note that this will
     * always make a new connection to the URL, and therefore should not be
     * called successively.
     * <p/>
     * The returned InputStream will not be encoded.
     *
     * @return an InputStream from the current URL
     * @throws IOException when the URL could not be opened
     */
    public InputStream getInputStream() throws IOException {
        HttpURLConnection conn = createConnection();
        InputStream in = conn.getInputStream();
        String encoding = conn.getContentEncoding();
        if (encoding == null) {
            return null;
        } else {
            return new Decoder(in).decode(encoding.split(":")).get();
        }
    }
}
