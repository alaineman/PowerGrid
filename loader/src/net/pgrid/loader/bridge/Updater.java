package net.pgrid.loader.bridge;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
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
    
    private final RSVersionInfo info;
    private String updaterServer = null;
    private int port = -1;

    /**
     * Creates a new Updater object
     * @param info the RSVersionInfo
     */
    public Updater(RSVersionInfo info) {
        if (info == null) {
            throw new IllegalArgumentException("null");
        }
        this.info = info;
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
        ClassMapDownloader loader;
        if (updaterServer == null) {
            loader = new ClassMapDownloader(info);
        } else {
            loader = new ClassMapDownloader(info, updaterServer, port);
        }
        
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
