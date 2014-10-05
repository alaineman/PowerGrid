/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 * 
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
package net.pgrid.loader;

import java.applet.Applet;
import java.awt.EventQueue;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Modifier;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.file.Paths;
import java.security.AccessController;
import java.security.PrivilegedAction;
import net.pgrid.loader.bridge.Reflection;
import net.pgrid.loader.bridge.UpdaterRunner;
import net.pgrid.loader.util.ArgumentParser;
import net.pgrid.loader.util.Logger;
import net.pgrid.loader.util.NullOutputStream;

/**
 * Launcher class for the PowerGrid loader application.
 * 
 * The main method of this class accepts a set of command-line parameters, which
 * are mentioned below:
 * 
 * <ul>
 *   <li><strong>--debug (or -d):</strong> 
 *              Enables debug mode.</li>
 *   <li><strong>--quiet (or -q):</strong> 
 *              Enables quiet mode (unless -d is specified).</li>
 *   <li><strong>--verbose (or -v):</strong> 
 *              Enables verbose mode (unless -d or -q is specified).</li>
 *   <li><strong>--force-download (or -f):</strong> 
 *              Forces re-downloading the client.</li>
 * </ul>
 * 
 * The {@code -d}, {@code q} and {@code v} options change the verbosity of the 
 * messages logged by PowerGrid. 
 * 
 * The {@code -f} flag forces re-downloading the client. Normal behavior is to
 * re-use an already downloaded client when there is no newer version available.
 * This option disables this behavior and downloads all client data (including
 * the client itself and the updater data) regardless of any existing client 
 * data.
 * 
 * Also important to note is, that this class arbitrates the {@code System.out} 
 * and {@code System.err} PrintStreams and replaces them with a PrintStream 
 * that writes to a file named {@code runescape.log}. This is done to prevent 
 * any Exception stack traces and other messages printed from within RS to 
 * clutter the real console output and error streams. The real versions are 
 * kept in this class, making them available as {@code PowerGrid.out} and 
 * {@code PowerGrid.err}, respectively.
 * 
 * @author Patrick Kramer
 */
public class PowerGrid {
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
    
    /**
     * The global PowerGrid instance.
     */
    public static final PowerGrid INSTANCE;
    
    /**
     * Convenience method for displaying a message to the user prior to starting
     * the client. 
     * 
     * Calling this method is equivalent to calling 
     * {@code INSTANCE.getFrame().showMessage}, but this method additionally 
     * performs some safety checks.
     * 
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
        parser.merge("force-download", "f"); // force redownloading client
        
        if (parser.hasFlag("debug")) {
            Logger.setVerbosity(Logger.Verbosity.DEBUG);
        } else if (parser.hasFlag("quiet")) {
            Logger.setVerbosity(Logger.Verbosity.QUIET);
        } else if (parser.hasFlag("verbose")) {
            Logger.setVerbosity(Logger.Verbosity.VERBOSE);
        } // else we leave it on NORMAL
        
        // Touch the Reflection class so that it's loaded when the native client
        // needs it. At the same time, checks if the Agent is loaded.
        if (!Reflection.checkAvailability()) {
            // Log a warning message to the console.
            LOGGER.log("Cannot load Reflection component, some debug tools may not be available");
        }
        
        try {
            INSTANCE.start(parser.hasFlag("debug"),
                           parser.hasFlag("force-download"));
        } catch (IOException e) {
            LOGGER.log("Exception during PowerGrid startup", e);
        }
    }
    
    /**
     * The AppletFrame instance containing the Runescape Applet.
     */
    private final AppletFrame frame;
    private RSClassProvider classProvider = null;
    
    /**
     * Creates a new PGLoader instance.
     */
    public PowerGrid() {
        frame = new AppletFrame();
    }
    
    /**
     * @return the AppletFrame in which the Applet is displayed.
     */
    public AppletFrame getFrame() {
        return frame;
    }

    public RSClassProvider getClassProvider() {
        return classProvider;
    }
    
    /**
     * Starts the client with the specified settings.
     * @param debugMode true to enable debugging features, false to disable
     * @param force true to force re-downloading the client, even when no new version is found
     * @throws java.io.IOException if collecting the data failed.
     */
    public synchronized void start(boolean debugMode, boolean force) throws IOException {
        long startTime;
        if (debugMode) {
            LOGGER.log("Debug mode enabled");
            // Record the start time for profiling purposes
            startTime = System.currentTimeMillis();
        } else {
            startTime = 0;
        }
        
        showFrame();
        
        getFrame().showMessage("Loading config...");
        RSVersionInfo newVersion = loadClient();
        
        UpdaterRunner updaterRunner = new UpdaterRunner(newVersion.isLocal(), false);
        new Thread(updaterRunner, "PG_updater").start();
        
        getFrame().showMessage("Starting Applet...");
        initApplet(newVersion);
        initClassProvider();
        
        
        LOGGER.log("Java Library Path: ", System.getProperty("java.library.path"));
        
        if (debugMode) {
            long timePassed = System.currentTimeMillis() - startTime;
            LOGGER.log("Total startup time: " + (timePassed/1000d) + 's');
        }
    }
    
    public RSVersionInfo loadClient() throws IOException {
        RSVersionInfo currentVersion = 
                RSVersionInfo.fromPath(Paths.get("cache/keys.dat"));
        
        RSDownloader downloader = new RSDownloader();
        RSVersionInfo newVersion = downloader.loadConfig(currentVersion);
        
        boolean canUseLocal = currentVersion != null && 
                currentVersion.equals(newVersion);
        
        if (canUseLocal) {
            // re-use the existing client
            LOGGER.log("Client version not changed; skipping client re-downloading");
        } else {
            // download the client
            LOGGER.log("Downloading client");
            getFrame().showMessage("Downloading client...");
            downloader.loadClient(Paths.get("cache/client.jar"));
        }
        try {
            newVersion.writeTo(Paths.get("cache/keys.dat"));
        } catch (IOException e) {
            LOGGER.log("Failed to write the current version info", e);
        }
        return newVersion;
    }
    
    public void initApplet(RSVersionInfo newVersion) {
        ClassLoader rsClassLoader = AccessController.doPrivileged(GET_CLIENT_LOADER);
        try {
            Class<? extends Applet> rs2AppletClass = 
                    rsClassLoader.loadClass("Rs2Applet").asSubclass(Applet.class);
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
    }
    
    public void showFrame() {
        EventQueue.invokeLater(() -> getFrame().initComponents());
    }
    
    /**
     * Waits for the client class to be loaded and then initializes the 
     * RSClassProvider instance.
     */
    public void initClassProvider() {
        assert classProvider == null : "initClassProvider() invoked twice";
        // This class is always named the same, so we can easily access that 
        // Class through our Agent.
        try {
            Class<?> clientClass;
            do {
                clientClass = Agent.findClass("client");
            } while (clientClass == null);
            classProvider = new RSClassProvider(clientClass.getClassLoader());
        } catch (IllegalStateException e) {
            LOGGER.log("Could not find ClassLoader, RS classes may not be available", e);
        }
    }
     
    /**
     * PriviledgedAction class that replaces the default System.out and System.err
     * with a PrintStream that prints to a File. 
     * 
     * This prevents Runescape classes from printing their stack traces to the 
     * console, keeping the console output clean.
     */
    public static final Privileged<Boolean> INTERCEPT_OUTPUT = () -> {
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
    };
    
    public static final Privileged<ClassLoader> GET_CLIENT_LOADER = () -> {
        try {
            return new URLClassLoader(new URL[]{new URL("jar:file:cache/client.jar!/")});
        } catch (MalformedURLException ex) {
            throw new AssertionError("Local Client URL invalid: " + ex.getMessage());
        }
    };
    
    // This piece of code replaces the standard System.out and System.err with
    // different ones, to split the Runescape log information from PowerGrid 
    // log information. This prevents stacktrace contents of obfuscated 
    // classes from showing up in the console. It saves a lot of searching during
    // debugging, as obfuscated stack traces are of little use to anyone.
    static {
        out = System.out;
        err = System.err;
        
        boolean success = AccessController.doPrivileged(INTERCEPT_OUTPUT);
        
        // Set our Loggers to use the original out PrintStream
        if (success) {
            Logger.setDefaultTarget(out);
        }
        LOGGER = Logger.get("CORE");
        INSTANCE = new PowerGrid();
    }
    
    /**
     * Functional Interface wrapper for PrivilegedAction, allowing 
     * PrivilegedActions to be defined as lambdas.
     * 
     * @param <T> the return type of this PrivilegedAction
     */
    @FunctionalInterface
    @SuppressWarnings("MarkerInterface")
    public static interface Privileged<T> extends PrivilegedAction<T> {}
}
