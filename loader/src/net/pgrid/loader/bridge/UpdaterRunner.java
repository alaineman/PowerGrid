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
public class UpdaterRunner implements Runnable {

    private static final Logger LOGGER = Logger.get("UPDATER");
    
    /**
     * The default destination File.
     */
    public static final File DESTINATION = new File("cache", "updaterInfo.dat");
    
    private final RSVersionInfo info;
    private String updaterServer = null;
    private int port = -1;
    private final String checksum;
    
    private boolean profile;

    /**
     * Creates a new Updater object
     * @param info the RSVersionInfo
     * @param profile true to profile the updater and print the results, false to disable
     * @param checksum the MD5 checksum of the client
     */
    public UpdaterRunner(RSVersionInfo info, boolean profile, String checksum) {
        if (info == null || checksum == null) {
            throw new IllegalArgumentException("null");
        }
        this.checksum = checksum;
        this.info = info;
        this.profile = profile;
    }

    public String getChecksum() {
        return checksum;
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
        
        Updater update;
        if (updaterServer == null) {
            // we use the default server and port
            update = new Updater(info);
        } else {
            // we use the custom updater server
            update = new Updater(info, updaterServer, port);
        }
        
        try {
            
            byte[] data = update.getData();
            LOGGER.log("Updater data acquired (" + data.length + " bytes)");
            
            if (!DESTINATION.isFile() && !DESTINATION.createNewFile()) {
                throw new IOException("Cannot write to updater info destination");
            }
            
            try (FileOutputStream out = new FileOutputStream(DESTINATION)) {
                out.write(data);
            }
            
            // Tell the native code the updater is done
            signalUpdaterReady(checksum, data);
            
            if (profile) {
                long timeTaken = System.currentTimeMillis() - timeStarted;
                LOGGER.log("Updater took " + (timeTaken/1000d) + "s to finish");
            }
        } catch (IOException e) {
            LOGGER.log("Failed to save the updater data", e);
        }
    }
    
    /**
     * Notifies the C++ client the updater is ready.
     * This will parse and store the updater data.
     * @param checksum the checksum of the client
     * @param data the bytes of the updater data.
     */
    private native void signalUpdaterReady(String checksum, byte[] data);
}
