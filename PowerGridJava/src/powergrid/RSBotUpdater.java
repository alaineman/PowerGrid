package powergrid;

import java.awt.EventQueue;
import java.awt.Window;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.management.ManagementFactory;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.util.Enumeration;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.LogRecord;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import static powergrid.PowerGrid.LOGGER;
import powergrid.view.UpdateFrame;

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
    private String[] args;
    
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
     * Sets the command line arguments for use with the restart option.
     * @param args the command line arguments.
     * @return itself for fluency
     */
    public RSBotUpdater useCmdArgs(String[] args) {
        this.args = args;
        return this;
    }
    
    /**
     * Downloads (and possibly replaces) the RSBot.jar file at the target 
     * destination.
     * <p/>
     * The transfer itself is done using Java NIO Channels.
     */
    public void update() {
        UpdateFrame frame = new UpdateFrame();
        try {
            File targetFile = new File(target);
        
            if (!targetFile.exists()) {
                // ensure the file exists
                targetFile.getParentFile().mkdirs();
                targetFile.createNewFile();
            }
        
            try (InputStream in = link.openStream(); 
                    FileOutputStream out = new FileOutputStream(target)) {

                LOGGER.info("Update started");
                frame.setMessage("Downloading update...");
                ReadableByteChannel rbc = Channels
                        .newChannel(in);

                out.getChannel().transferFrom(rbc, 0, 1 << 24);

                LOGGER.info("Update complete");
                frame.setMessage("Update complete. Restarting...");
            }
        } catch (IOException e) {
            LOGGER.log(Level.SEVERE, "Update failed", e);
            frame.setMessage("Update failed because of a " + e.getClass().getSimpleName());
        }
    }
    
    /**
     * Notifies the user that a new update is available and asks to update it.
     */
    public void askForUpdate() {
        LOGGER.info("There appears to be a new RSBot version");
        int reply = JOptionPane.showConfirmDialog(null, 
            "It appears RSBot can be updated. Should PowerGrid download the\n"
                + "RSBot update? (PowerGrid will shut down)", 
            "Check for update?", JOptionPane.YES_NO_OPTION, 
            JOptionPane.QUESTION_MESSAGE);
        if (reply == JOptionPane.YES_OPTION) {
            try {
                // prepend "--update" to command line args and restart
                String[] newArgs = new String[args.length + 1];
                newArgs[0] = "--update";
                System.arraycopy(args, 0, newArgs, 1, args.length);
                useCmdArgs(newArgs).restart();
            } catch (IOException e) {
                LOGGER.log(Level.SEVERE, "Could not restart for update", e);
            }
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
                if (!updateFound() && message != null 
                        && message.contains("newer version")) {
                    updateFound = true;
                    EventQueue.invokeLater(new Runnable() {
                                @Override public void run() {
                                    askForUpdate();
                                }
                            });
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
     * Restarts the entire application with the specified command line 
     * arguments.
     * <p/>
     * This method calls the <code>exit</code> method in class
     * <code>Runtime</code>. This method never returns normally.
     * <p/>
     * This method tries to restart the JVM with the same settings. However, 
     * it may be possible that the JVM cannot be restarted when using specific 
     * configurations. Therefore, it is advised to run PowerGrid by calling
     * <blockquote><pre>
     * java -jar PowerGrid.jar
     * </pre></blockquote>
     * Where <code>(vmargs)<code> is a series of arguments supported by the 
     * Java Virtual machine, and <code>(pgargs)</code> is a series of arguments 
     * supported by PowerGrid. Note that some arguments to the java command
     * cannot be passed to the JVM, and therefore cannot be used when 
     * restarting.
     * <p/>
     * @see powergrid.PowerGrid powergrid.PowerGrid (for information on the 
     *                          supported command line arguments for PowerGrid)
     * @throws IOException when the restart operation could not be completed.
     */
    public void restart() throws IOException {
        StringBuilder builder = new StringBuilder(100);
        // Java binary
        builder.append("\"").append(System.getProperty("java.home"))
                .append(File.separator).append("bin").append(File.separator)
                .append("java").append("\" ");
        // JVM arguments
        for (String jvmArg : ManagementFactory.getRuntimeMXBean()
                .getInputArguments()) {
            builder.append(jvmArg).append(" ");
        }
        // ClassPath
        builder.append("-cp ").append(ManagementFactory.getRuntimeMXBean()
                .getClassPath()).append(" ");
        
        // Main class + arguments
        builder.append(PowerGrid.class.getName()).append(" ");
        for (String arg : args) {
            builder.append(arg).append(" ");
        }
        
        // Dispose of all windows.
        for (Window w : Window.getWindows()) {
            w.dispose();
        }
        
        // Execute the command and exit
        String command = builder.toString();
        LOGGER.info("Executing: " + command);
        Runtime.getRuntime().exec(command);
        
        Runtime.getRuntime().exit(0);
    }
    
    /**
     * @return whether the updater detected an update.
     */
    public boolean updateFound() {
        return updateFound;
    }
}
