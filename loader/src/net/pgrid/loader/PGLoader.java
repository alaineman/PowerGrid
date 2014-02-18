package net.pgrid.loader;

import java.applet.Applet;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Modifier;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.security.AccessController;
import java.security.PrivilegedAction;
import net.pgrid.loader.bridge.UpdaterRunner;
import net.pgrid.loader.logging.Logger;
import net.pgrid.loader.util.ArgumentParser;
import net.pgrid.loader.util.NullOutputStream;

/**
 * Launcher class for the PowerGrid loader application.
 * @author Patrick Kramer
 */
public class PGLoader {
    /** The Logger instance of this class. */
    private static final Logger LOGGER;
    
    /**
     * The standard output stream (use this over System.out).
     */
    public static final PrintStream out;
    /**
     * The standard error stream (use this over System.err).
     */
    public static final PrintStream err;
    
    // This piece of code replaces the standard System.out and System.err with
    // different ones, to split the Runescape log information from PowerGrid 
    // log information. This prevents stacktrace contents of obfuscated 
    // classes from showing up in the console. It saves a lot of searching during
    // debugging, as obfuscated stack traces are of little use to anyone.
    static {
        out = System.out;
        err = System.err;
        
        boolean success = AccessController.doPrivileged(new OutputInterceptor());
        
        // Set our Loggers to use the original out PrintStream
        if (success) {
            Logger.setDefaultTarget(out);
        }
        LOGGER = Logger.get("CORE");
        INSTANCE = new PGLoader();
    }
    
    /**
     * The global PGLoader instance.
     */
    public static final PGLoader INSTANCE;
    
    /**
     * Convenience method for displaying a message to the user prior to starting
     * the client. 
     * <p/>
     * Calling this method is equivalent to calling 
     * {@code INSTANCE.getFrame().showMessage}, but this method additionally 
     * performs some safety checks.
     * <p/>
     * If the frame does not (yet) exist, this method does nothing.
     * @param message the message to report
     */
    public static void report(String message) {
        AppletFrame frame = INSTANCE.getFrame();
        if (frame != null) {
            frame.showMessage(message);
        }
    }
    
    /**
     * Main method of the application.
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Thread.currentThread().setName("PG_Main");
        Thread.setDefaultUncaughtExceptionHandler(new PGExceptionHandler());
        
        ArgumentParser parser = new ArgumentParser();
        parser.analyse(args);
        // Add more parameters and flags here as needed
        parser.merge("debug", "d");   // debug mode enabled
        parser.merge("quiet", "q");   // quiet mode enabled (ignored when "debug" is specified)
        parser.merge("verbose", "v"); // verbose mode (ignored when "debug" or "quiet" is specified)
        parser.merge("client-load", "c"); // loaded from native client (do not set this manually!)
        parser.merge("force-download", "f"); // force redownloading client
        
        if (parser.hasFlag("debug")) {
            Logger.setVerbosity(Logger.Verbosity.DEBUG);
        } else if (parser.hasFlag("quiet")) {
            Logger.setVerbosity(Logger.Verbosity.QUIET);
        } else if (parser.hasFlag("verbose")) {
            Logger.setVerbosity(Logger.Verbosity.VERBOSE);
        } // else we leave it on NORMAL
        
        try {
            INSTANCE.start(parser.hasFlag("debug"),
                           parser.hasFlag("client-load"),
                           parser.hasFlag("force-download"));
        } catch (IOException e) {
            LOGGER.log("Exception during PowerGrid startup", e);
        }
    }
    
    /**
     * The AppletFrame instance containing the Runescape Applet.
     */
    private final AppletFrame frame;
    
    /**
     * Creates a new PGLoader instance.
     */
    public PGLoader() {
        frame = new AppletFrame();
    }
    
    /**
     * @return the AppletFrame in which the Applet is displayed.
     */
    public AppletFrame getFrame() {
        return frame;
    }
    
    /**
     * Starts the client with the specified settings.
     * @param debugMode true to enable debugging features, false to disable
     * @param client true when loaded from native client, false otherwise
     * @param force true to force re-downloading the client, even when no new version is found
     * @throws java.io.IOException if collecting the data failed.
     */
    public synchronized void start(boolean debugMode, boolean client, boolean force) throws IOException {
        long startTime;
        if (debugMode) {
            LOGGER.log("Debug mode enabled");
            // Record the start time for profiling purposes
            startTime = System.currentTimeMillis();
        } else {
            startTime = 0;
        }
        
        getFrame().init();
        getFrame().showMessage("Loading config...");
        
        RSVersionManager versionManager = new RSVersionManager();
        RSVersionInfo currentVersion = (force ? null : versionManager.getCurrentVersion());
        
        RSDownloader downloader = new RSDownloader();
        RSVersionInfo newVersion = downloader.loadConfig(currentVersion);
        
        if (!force && currentVersion != null && newVersion != null && 
                versionManager.checkVersions(currentVersion, newVersion)) {
            // re-use the encryption keys
            LOGGER.log("Client version not changed; skipping client re-downloading");
        } else {
            // download the client
            if (!force) {
                LOGGER.log("New client version; downloading client");
            } else {
                LOGGER.log("Forcing client redownloading");
            }
            getFrame().showMessage("Downloading client...");
            downloader.loadClient();
            UpdaterRunner updaterRunner = new UpdaterRunner(newVersion, debugMode, downloader.getChecksum());
            new Thread(updaterRunner, "PG_updater").start();
        }
        
        try {
            versionManager.writeCurrentVersion(newVersion);
        } catch (IOException e) {
            LOGGER.log("Failed to write the current version info", e);
        }
        
        getFrame().showMessage("Starting Applet...");
        
        ClassLoader rsClassLoader = AccessController.doPrivileged(new PrivilegedClassLoaderAction());
        
        try {
            Class<? extends Applet> rs2AppletClass = rsClassLoader.loadClass("Rs2Applet").asSubclass(Applet.class);
            Applet a = rs2AppletClass.getConstructor().newInstance();
            
            if (!getFrame().startApplet(newVersion, a)) {
                getFrame().showMessage("Exception in Applet");
                LOGGER.log("Failed to start Applet");
            }
        } catch (ClassNotFoundException | NoSuchMethodException | 
                 InstantiationException | IllegalAccessException | 
                 InvocationTargetException | ClassCastException e) {
            getFrame().showMessage("Error in loader");
            LOGGER.log("Failed to create RS Applet", e);
        }
        
        if (debugMode) {
            long timePassed = System.currentTimeMillis() - startTime;
            LOGGER.log("Total startup time: " + (timePassed/1000d) + 's');
        }
    }
    
    /**
     * Custom UncaughtExceptionHandler.
     * 
     * This class checks if the Exception was caused on a PG Thread or some 
     * other Thread. In the last case, no stack trace is printed to prevent
     * long obfuscated (and as such useless) Runescape stack traces.
     */
    public static class PGExceptionHandler 
            implements Thread.UncaughtExceptionHandler {
        private static final Logger LOGGER = Logger.get("UNCAUGHT");
        @Override
        public void uncaughtException(Thread thread, Throwable t) {
            LOGGER.log("Exception on Thread \"" + thread.getName() + "\":", t);
            if (!thread.getName().startsWith("PG_")) {
                // do not print stack traces of (obfuscated) RS classes,
                // but use the System.out PrintStream to send it to the 
                // runescape.log file.
                System.out.append("Uncaught Exception in Runescape or on AWT Thread \"").append(thread.getName()).println("\":");
                System.out.append("  ").append(t.getClass().getSimpleName()).append(": ").println(t.getMessage());
            }
        }
    }
    
    /**
     * PriviledgedAction class that replaces the default System.out and System.err
     * with a PrintStream that prints to a File. 
     * 
     * This prevents Runescape classes from printing their stack traces to the 
     * console, keeping the console output clean.
     */
    private static class OutputInterceptor implements PrivilegedAction<Boolean> {
        @Override
        public Boolean run() {
            try {
                Field outField = System.class.getDeclaredField("out");
                Field errField = System.class.getDeclaredField("err");

                File destination = new File("runescape.log");
                PrintStream replacement;
                if (destination.isFile() || destination.createNewFile()) {
                    replacement = new PrintStream(destination, "UTF-8");
                } else {
                    replacement = new PrintStream(new NullOutputStream(), false, "UTF-8");
                }
                Field modifiersField = Field.class.getDeclaredField("modifiers");
                modifiersField.setAccessible(true);
                
                outField.setAccessible(true);
                errField.setAccessible(true);
                
                // required to change a both static AND final Field: remove the final modifier from the Field
                modifiersField.setInt(outField, outField.getModifiers() & ~Modifier.FINAL);
                modifiersField.setInt(errField, errField.getModifiers() & ~Modifier.FINAL);
                
                outField.set(null, replacement);
                errField.set(null, replacement);
                
                return true;
            } catch (NoSuchFieldException | IOException | IllegalAccessException e) {
                System.err.println("Failed to intercept System.out / err: " + 
                        e.getClass().getSimpleName() + ": " + e.getMessage());
                return false;
            }
        }
    }
    
    private static class PrivilegedClassLoaderAction implements PrivilegedAction<ClassLoader> {
        @Override
        public ClassLoader run() {
            try {
                return new URLClassLoader(new URL[]{new URL("jar:file:cache/client.jar!/")});
            } catch (MalformedURLException e) {
                return null;
            }
        }
    }
    
    
}
