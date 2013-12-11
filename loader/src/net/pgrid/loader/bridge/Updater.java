package net.pgrid.loader.bridge;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import net.pgrid.loader.RSVersionInfo;
import net.pgrid.loader.logging.Logger;

/**
 * Runnable class that combines and executes all updater-related actions.
 * 
 * @author Patrick Kramer
 */
public class Updater implements Runnable {

    private static final Logger LOGGER = Logger.get("UPDATER");
    
    /**
     * The default destination File.
     */
    public static final File DESTINATION = new File("cache", "updaterInfo.dat");
    
    private final RSVersionInfo info;
    private String updaterServer = null;
    private int port = -1;
    
    private boolean profile;

    /**
     * Creates a new Updater object
     * @param info the RSVersionInfo
     * @param profile true to profile the updater and print the results, false to disable
     */
    public Updater(RSVersionInfo info, boolean profile) {
        if (info == null) {
            throw new IllegalArgumentException("null");
        }
        this.info = info;
        this.profile = profile;
    }
    
    /**
     * Sets the updater server to connect to.
     * <p/>
     * If {@code server == null}, the default server will be used
     * @param server the server to connect to
     * @param port the port to connect to
     */
    public synchronized void setUpdaterServer(String server, int port) {
        this.updaterServer = server;
        this.port = port;
    }
    
    @Override
    public synchronized void run() {
        long timeStarted;
        if (profile) {
            timeStarted = System.currentTimeMillis();
        } else {
            timeStarted = 0;
        }
        
        ClassMapDownloader loader;
        if (updaterServer == null) {
            // we use the default server and port
            loader = new ClassMapDownloader(info);
        } else {
            // we use the custom updater server
            loader = new ClassMapDownloader(info, updaterServer, port);
        }
        
        try {
            byte[] data = loader.getData();
            try (FileOutputStream out = new FileOutputStream(DESTINATION)) {
                out.write(data);
            }
            LOGGER.log("Updater data acquired");
            
            if (profile) {
                long timeTaken = System.currentTimeMillis() - timeStarted;
                LOGGER.log("Updater took " + (timeTaken/1000d) + "s to finish");
            }
        } catch (IOException e) {
            LOGGER.log("Failed to save the updater data", e);
        }
    }
    
}
