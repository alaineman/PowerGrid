package net.pgrid.loader;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.security.AccessController;
import java.security.PrivilegedAction;
import net.pgrid.loader.logging.Logger;
import net.pgrid.loader.util.DummyOutputStream;

/**
 * Launcher class for the PowerGrid loader application.
 * @author Patrick Kramer
 */
public class PGLoader {
    // The Logger instance of this class.
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
    // log information. This prevents printstacktrace contents of obfuscated 
    // classes from showing up in the console. It saves a lot of searching during
    // debugging.
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
     * Main method of the application.
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Thread.currentThread().setName("PG_Main");
        Thread.setDefaultUncaughtExceptionHandler(new PGExceptionHandler());
        ClientLoader.main(args);
    }
    
    /**
     * The AppletFrame instance containing the Runescape Applet.
     */
    public final AppletFrame frame;
    
    /**
     * The ClientLoader instance responsible for loading the Runescape client.
     */
    public final ClientLoader loader;
    
    
    /**
     * Creates a new PGLoader instance.
     */
    public PGLoader() {
        frame = new AppletFrame();
        loader = new ClientLoader();
    }
    
    /**
     * Starts the client.
     * @throws java.io.IOException if collecting the data failed 
     */
    public void start() throws IOException {
        start(false);
    }
    
    /**
     * Starts the client with the specified debug mode enabled. 
     * @param debugMode true to enable debugging features, false to disable
     * @throws java.io.IOException
     */
    public synchronized void start(boolean debugMode) throws IOException {
        // Record the start time for profiling purposes
        long startTime = System.currentTimeMillis();
        
        ClientDownloader downloader = new ClientDownloader();
        downloader.loadConfig();
        
        if (debugMode) {
            long timePassed = System.currentTimeMillis() - startTime;
            LOGGER.log("Total startup time: " + timePassed);
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
            if (thread.getName().startsWith("PG_")) {
                LOGGER.log("Exception on Thread \"" + thread.getName() + "\":");
                LOGGER.describe(t);
            } else {
                // do not print stack traces of (obfuscated) RS classes
                LOGGER.log("Exception in Runescape or on AWT Thread: " 
                        + t.getClass().getSimpleName());
            }
        }
    }
    
    private static class OutputInterceptor implements PrivilegedAction<Boolean> {
        @Override
        public Boolean run() {
            try {
                Field outField = System.class.getDeclaredField("out");
                Field errField = System.class.getDeclaredField("err");

                File destination = new File("runescape.log");
                PrintStream replacement;
                if (destination.exists() || destination.createNewFile()) {
                    replacement = new PrintStream(destination, "UTF-8");
                } else {
                    replacement = new PrintStream(new DummyOutputStream(), false, "UTF-8");
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
}
