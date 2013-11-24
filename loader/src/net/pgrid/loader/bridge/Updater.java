package net.pgrid.loader.bridge;

import java.io.File;
import java.io.IOException;
import net.pgrid.loader.ClientDownloader;

/**
 * Runnable class that combines and executes all updater-related actions when 
 * required.
 * 
 * External tools should use this class when trying to get data from the 
 * Updater server. It should be noted, however, that repeated calls to the 
 * updater server are strongly discouraged, and the server holds the right to 
 * refuse a connection.
 * 
 * @author Patrick Kramer
 */
public class Updater implements Runnable {

    /**
     * The default destination File.
     */
    public static final File DESTINATION = new File("cache", "updaterInfo.dat");
    
    private final ClientDownloader downloader;
    private String updaterServer = null;
    private int port = -1;

    public Updater(ClientDownloader downloader) {
        if (downloader == null) {
            throw new IllegalArgumentException("null");
        }
        this.downloader = downloader;
    }
    
    public void setUpdaterServer(String server, int port) {
        this.updaterServer = server;
        this.port = port;
    }
    
    public void resetDefaults() {
        updaterServer = null;
    }
    
    @Override
    public void run() {
        ClassMapDownloader loader;
        if (updaterServer == null) {
            loader = new ClassMapDownloader(downloader);
        } else {
            loader = new ClassMapDownloader(downloader, updaterServer, port);
        }
        loader.run();
        
        try {
            byte[] data = loader.getData();
            
            
        } catch (IOException e) {
            
        }
    }
    
}
