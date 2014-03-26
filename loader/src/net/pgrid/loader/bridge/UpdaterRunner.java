package net.pgrid.loader.bridge;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
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
    private boolean useLocal;
    
    private boolean profile;
    

    /**
     * Creates a new UpdaterRunner object
     * @param info the RSVersionInfo
     * @param useLocal true to use local updater data, false to call the Updater server
     * @param profile true to profile the updater and print the results, false to disable
     */
    public UpdaterRunner(RSVersionInfo info, boolean useLocal, boolean profile) {
        if (info == null) {
            throw new IllegalArgumentException("null");
        }
        this.info = info;
        this.useLocal = useLocal;
        this.profile = profile;
    }
    
    /**
     * Sets the updater server to connect to.
     * <p/>
     * If {@code server == null}, the default server will be used
     * @param server the server to connect to
     */
    public synchronized void setUpdaterServer(String server) {
        this.updaterServer = server;
    }
    
    @Override
    public synchronized void run() {
        try {
            long timeStarted;
            if (profile) {
                timeStarted = System.currentTimeMillis();
            } else {
                timeStarted = 0;
            }
            
            byte[] data;
            if (useLocal) {
                data = Files.readAllBytes(DESTINATION.toPath());
                LOGGER.log("Re-used local updater data");
            } else {
                Updater update;
                if (updaterServer == null) {
                    // we use the default server and port
                    update = new Updater(info);
                } else {
                    // we use the custom updater server
                    update = new Updater(info, updaterServer);
                }

                data = update.getData();
                if (!DESTINATION.isFile() && !DESTINATION.createNewFile()) {
                    throw new IOException("Cannot write to updater info destination");
                }

                try (FileOutputStream out = new FileOutputStream(DESTINATION)) {
                    out.write(data);
                }
                LOGGER.log("Updater data acquired (" + data.length + " bytes)");
            }
            // Tell the native code the updater is done
            signalUpdaterReady(data);
            
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
    private static native void signalUpdaterReady(byte[] data);
}
