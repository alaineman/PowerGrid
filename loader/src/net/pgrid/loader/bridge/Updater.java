package net.pgrid.loader.bridge;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.rmi.server.RMIServerSocketFactory;
import net.pgrid.loader.RSDownloader;
import net.pgrid.loader.RSVersionInfo;
import net.pgrid.loader.logging.Logger;

/**
 * Runnable class that combines and executes all updater-related actions when 
 * required.
 * 
 * @author Patrick Kramer
 */
public class Updater implements Runnable {

    private static final Logger LOGGER = Logger.get("UPDATER");
    
    /**
     * The default destination File.
     */
    public static final File DESTINATION = new File("cache", "updaterInfo.dat");
    
    private final RSVersionInfo downloader;
    private String updaterServer = null;
    private int port = -1;

    public Updater(RSVersionInfo downloader) {
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
            try (FileOutputStream out = new FileOutputStream(DESTINATION)) {
                out.write(data);
            }
        } catch (IOException e) {
            LOGGER.log("Could not write update File", e);
        }
    }
    
}
