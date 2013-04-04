package powergrid;

import java.awt.HeadlessException;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.util.Enumeration;
import java.util.logging.Handler;
import java.util.logging.LogManager;
import java.util.logging.LogRecord;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import static powergrid.PowerGrid.LOGGER;

/**
 * Updater for RSBot, which can auto-download RSBot from the PowerBot website.
 * <p/>
 * 
 * @author Chronio
 */
public class RSBotUpdater {
    
    /**
     * The default RSBot download link.
     */
    public static final String DOWNLOAD_LINK = "http://powerbot.org/download";
    /**
     * The target File path for the RSBot library.
     */
    public static final String TARGET = "lib" + File.separator + "RSBot.jar";
    
    private URL link;
    private String target;
    private Handler listener;
    
    /**
     * Indicates that it has been detected that an update exists for RSBot.
     */
    private boolean updateFound = false;
    
    /**
     * Creates a new RSBotUpdater that transfers between the default locations.
     */
    public RSBotUpdater() {
        this(DOWNLOAD_LINK, TARGET);
    }
    
    /**
     * Create a new RSBotUpdater that transfers between the given locations.
     * @param url the url to fetch from
     * @param target the target File.
     */
    public RSBotUpdater(String url, String target) {
        assert url != null && target != null;
        try {
            this.link = new URL(url);
            this.target = target;
        } catch (MalformedURLException e) {
            throw new IllegalArgumentException("Invalid url", e);
        }
    }
    
    /**
     * Downloads (and possibly replaces) the RSBot.jar file at the target 
     * destination.
     * <p/>
     * @throws IOException when the transfer fails
     */
    public void update() {
        assert updateFound();
        LOGGER.info("There appears to be a new RSBot version");
        int reply = JOptionPane.showConfirmDialog(null, 
            "It appears RSBot can be updated. Should PowerGrid check for an \n"
                + "RSBot update? (PowerGrid will shut down)", 
            "Check for update?", JOptionPane.YES_NO_OPTION, 
            JOptionPane.QUESTION_MESSAGE);
        if (reply == JOptionPane.YES_OPTION) {
            
            Thread updateAtShutdown = new Thread("Updater") {
                @Override public void run() {
                    try {
                        System.out.println("Update started");
                        ReadableByteChannel rbc = Channels
                                .newChannel(link.openStream());
                        File targetFile = new File(target);
                        if (!targetFile.exists()) {
                            targetFile.getParentFile().mkdirs();
                            targetFile.createNewFile();
                        }
                        FileOutputStream out = new FileOutputStream(target);
                        out.getChannel().transferFrom(rbc, 0, 1 << 24);
                        System.out.println("Update complete");
                    } catch (IOException | HeadlessException e) {
                        System.out.println("Update failed:");
                        e.printStackTrace(System.out);
                    }
                }
            };
            
            //updateAtShutdown.start();
            // Add the update Thread itself as a shutdown hook and shutdown.
            // This prevents the JVM from locking the RSBot jar file 
            // while writing.
            Runtime.getRuntime().addShutdownHook(updateAtShutdown);
            System.exit(0);
        }
    }
    
    /**
     * Hooks the RSBotUpdater in the RSBot's loggers, so that it can be 
     * detected when RSBot detects a new version.
     */
    public void hook() {
        Enumeration<String> e = LogManager.getLogManager().getLoggerNames();
        listener = new Handler() {
            @Override
            public void publish(LogRecord record) {
                String message = record.getMessage();
                if (!updateFound && message != null 
                        && message.contains("newer version")) {
                    updateFound = true;
                    update();
                }
            }
            @Override public void flush() {}
            @Override public void close() throws SecurityException {}
        };
        
        while (e.hasMoreElements()) {
            Logger.getLogger(e.nextElement()).addHandler(listener);
        }
    }
    
    /**
     * Unhooks this updater from all Loggers, so that updates will no longer be
     * detected.
     */
    public void unhook() {
        Enumeration<String> e = LogManager.getLogManager().getLoggerNames();
        while (e.hasMoreElements()) {
            Logger.getLogger(e.nextElement()).removeHandler(listener);
        }
    }
    
    /**
     * @return whether the updater detected an update.
     */
    public boolean updateFound() {
        return updateFound;
    }
}
