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
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Modifier;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.security.AccessController;
import java.security.PrivilegedAction;
import java.security.PrivilegedActionException;
import java.security.PrivilegedExceptionAction;
import java.util.jar.JarInputStream;
import net.pgrid.loader.bridge.Reflection;
import net.pgrid.loader.util.ArgumentParser;
import net.pgrid.loader.util.Logger;

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
 *   <li><strong>--intercept-output (or -i)</strong>
 *              Intercepts output from the client and redirects it to a file
 *              named "runescape.log" in the working directory."</li>
 *   <li><strong>--enable-exceptions (or -e)</strong>
 *              Enables throwing of Exceptions from {@code main(String[])}. 
 *              Useful for external applications that start this loader, but
 *              it should not be used when using this loader stand-alone.</li>
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
 * If the {@code -i} flag is present, this class arbitrates the {@code System.out} 
 * and {@code System.err} PrintStreams and replaces them with a PrintStream 
 * that writes to a file named {@code runescape.log}. This is done to prevent 
 * any Exception stack traces and other messages printed from within RS to 
 * clutter the real console output and error streams. The real versions are 
 * kept in this class, making them available as {@code PowerGrid.out} and 
 * {@code PowerGrid.err}, respectively. All logging output by PowerGrid is still
 * output to the console.
 * 
 * If the {@code -e} flag is provided, any Exceptions that occur during startup
 * will be propagated through the main method. If this flag is not present, they
 * will be caught and logged within application code. Providing this flag when 
 * running the client stand-alone will cause the application to crash upon any
 * Exception on the main Thread.
 * 
 * @author Patrick Kramer
 */
public class PowerGrid {
    /** The Logger instance of this class. */
    private static final Logger LOGGER = Logger.get("LAUNCHER");
    
    /**
     * The standard output stream (use this over System.out).
     */
    public static final PrintStream out = System.out;
    /**
     * The standard error stream (use this over System.err).
     */
    public static final PrintStream err = System.err;
    
    /**
     * The Path to the local client.
     */
    public static final Path CLIENT_PATH = Paths.get("cache/client.jar");
    
    /**
     * The Path to the keys file.
     */
    public static final Path KEYS_PATH   = Paths.get("cache/keys.dat");
    
    /**
     * The global PowerGrid instance.
     */
    public static final PowerGrid INSTANCE = new PowerGrid();
    
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
     * Enables intercepting of output to {@code System.out} and {@code System.err},
     * allowing Runescape log output to be split off to a separate file.
     * 
     * @param parser The ArgumentParser with the command-line arguments.
     * @throws Exception if an Exception occurred while intercepting the output,
     *                   and the parser has the "enable-exceptions" flag.
     */
    public static void enableOutputIntercepting(ArgumentParser parser) throws Exception {
        if (!parser.hasFlag("intercept-output")) {
            return;
        }
        try {
            boolean success = AccessController.doPrivileged(
                (PrivilegedExceptionAction<Boolean>) PowerGrid::interceptOutput);
            if (success) {
                Logger.setDefaultTarget(PowerGrid.out, true);
            } else if (parser.hasFlag("enable-exceptions")) {
                throw new Exception("Failed to intercept output");
            }
        } catch (PrivilegedActionException ex) {
            Exception cause = ex.getException();
            if (parser.hasFlag("enable-exceptions")) {
                throw cause;
            } else {
                LOGGER.log("Exception while intercepting output", ex);
            }
        }
    }
    
    /**
     * Sets the Logger Verbosity based on the provided arguments.
     * 
     * @param parser The ArgumentParser.
     */
    public static void setLoggerVerbosity(ArgumentParser parser) {
        if (parser.hasFlag("debug")) {
            Logger.setVerbosity(Logger.Verbosity.DEBUG);
        } else if (parser.hasFlag("quiet")) {
            Logger.setVerbosity(Logger.Verbosity.QUIET);
        } else if (parser.hasFlag("verbose")) {
            Logger.setVerbosity(Logger.Verbosity.VERBOSE);
        } // else we leave it on NORMAL
    }
    
    /**
     * Returns the hash of the local client.
     * 
     * The hash is computed by computing an hashCode from the Manifest of the 
     * client jar file.
     * 
     * @return the hash of the local client.
     * @throws IOException when an I/O error occurs.
     */
    public static int computeClientHash() throws IOException {
        try (JarInputStream in = new JarInputStream(Files.newInputStream(CLIENT_PATH))) {
            return in.getManifest().hashCode();
        }
    }
    
    /**
     * Tries to find a Class in the RS client.
     * 
     * @param name The real (obfuscated) name of the class.
     * @return The Class with the given name, or null if no such class exists.
     */
    public static Class<?> findClass(String name) {
        return INSTANCE.getClassProvider().findClass(name);
    }
    
    /**
     * Parses the arguments and returns an ArgumentParser instance with the 
     * provided arguments.
     * 
     * {@code args} can be null, and in that case this method behaves the same 
     * as if {@code args} were an array of length 0.
     * 
     * @param args The command-line arguments.
     * @return The parsed arguments as an ArgumentParser instance.
     */
    public static ArgumentParser parseArguments(String[] args) {
        ArgumentParser parser = new ArgumentParser();
        parser.analyse(args);
        // Merge the shortcuts into their respective full flag names.
        parser.merge("debug", "d");
        parser.merge("quiet", "q");
        parser.merge("verbose", "v");
        parser.merge("force-download", "f");
        parser.merge("intercept-output", "i");
        parser.merge("enable-exceptions", "e");
        
        return parser;
    }
    
    /**
     * Main method of the application.
     * @param args the command-line arguments
     * @throws Exception if {@code -e} is provided as one of the arguments 
     *                   and an Exception occurs during startup.
     */
    public static void main(String[] args) throws Exception {
        Thread.currentThread().setName("PG_Main");
        Thread.setDefaultUncaughtExceptionHandler(new PGExceptionHandler());
        
        ArgumentParser parser = parseArguments(args);
        setLoggerVerbosity(parser);
        
        enableOutputIntercepting(parser);
        
        // Touch the Reflection class so that it's loaded when the native client
        // needs it. At the same time, checks if the Agent is loaded.
        if (!Reflection.checkAvailability()) {
            // Log a warning message to the console.
            LOGGER.log("Cannot load Reflection component, some debug tools may not be available");
        }
        
        try {
            INSTANCE.start(parser);
        } catch (IOException e) {
            if (parser.hasFlag("enable-exceptions")) {
                throw e;
            }
            report(e.getMessage());
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

    /**
     * @return The RSClassProvider.
     */
    public RSClassProvider getClassProvider() {
        return classProvider;
    }
    
    /**
     * Starts the client with the specified settings.
     * @param parser - the ArgumentParser instance with the command line arguments.
     * @throws IOException if collecting the data failed.
     */
    public synchronized void start(ArgumentParser parser) throws IOException {
        long startTime;
        if (parser.hasFlag("debug")) {
            LOGGER.log("Debug mode enabled");
            // Record the start time for profiling purposes
            startTime = System.currentTimeMillis();
        } else {
            startTime = 0;
        }
        
        showFrame();
        
        getFrame().showMessage("Loading config...");
        RSVersionInfo newVersion = loadClient();
        
        getFrame().showMessage("Starting Applet...");
        initApplet(newVersion);
        initClassProvider();
        
        if (parser.hasFlag("debug")) {
            long timePassed = System.currentTimeMillis() - startTime;
            LOGGER.log("Total startup time: " + (timePassed/1000d) + 's');
        }
    }
    
    /**
     * Loads the Runescape client and returns the version info.
     * @return the version info of the loaded client.
     * @throws IOException if an I/O error occurs.
     */
    public RSVersionInfo loadClient() throws IOException {
        RSVersionInfo currentVersion = RSVersionInfo.fromPath(KEYS_PATH);
        
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
    
    /**
     * Creates and initializes the Runescape Applet.
     * @param version the RSVersionInfo belonging to the current version.
     */
    public void initApplet(RSVersionInfo version) {
        ClassLoader rsClassLoader = AccessController.doPrivileged(
                (PrivilegedAction<ClassLoader>) PowerGrid::getClientClassLoader);
        try {
            Class<? extends Applet> rs2AppletClass = 
                    rsClassLoader.loadClass("Rs2Applet").asSubclass(Applet.class);
            Applet a = rs2AppletClass.getConstructor().newInstance();
            
            if (!getFrame().startApplet(version, a)) {
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
    
    /**
     * Shows the AppletFrame instance.
     */
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
     * Replaces the default System.out and System.err with a PrintStream that 
     * prints to a File.
     * 
     * This prevents Runescape classes from printing their stack traces to the 
     * console, keeping the console output clean.
     * 
     * @return True if the operation succeeded, false otherwise
     * @throws Exception if an error occurs at any point during the intercept 
     *                   operation.
     */
    public static Boolean interceptOutput() throws Exception {
        Field outField = System.class.getDeclaredField("out");
        Field errField = System.class.getDeclaredField("err");

        PrintStream replacement = createRedirectedPrintStream();
        updateStaticFieldContents(outField, replacement);
        updateStaticFieldContents(errField, replacement);

        return true;
    };
    
    /**
     * Creates a new PrintStream that directs to a log file.
     * @return the created PrintStream.
     * @throws IOException When the file to redirect to could not be created, 
     *                     or the JVM does not support UTF-8 encoding.
     */
    public static PrintStream createRedirectedPrintStream() throws IOException {
        Path destination = Paths.get("runescape.log");
        OutputStream redirectStream = Files.newOutputStream(destination,
                StandardOpenOption.WRITE, StandardOpenOption.CREATE);
        return new PrintStream(redirectStream, true, "UTF-8");
        
    }
    
    /**
     * Updates the contents of the given static field.
     * 
     * The {@code FINAL} modifier is removed from the field if it exists.
     * 
     * @param f           The Field to update
     * @param replacement The new value for the Field.
     */
    public static void updateStaticFieldContents(Field f, Object replacement) {
        try {
            f.setAccessible(true);
            Field modField = Field.class.getDeclaredField("modifiers");
            modField.setAccessible(true);
            modField.set(f, f.getModifiers() & ~Modifier.FINAL);
            f.set(null, replacement);
        } catch (NoSuchFieldException ex) {
            throw new AssertionError("Assertion failed: No field named 'modifiers' in Field.class", ex);
        } catch (IllegalAccessException ex) {
            throw new AssertionError("Assertion failed: No access to Field after enabling access", ex);
        }
    }
    
    /**
     * Creates and returns a ClassLoader for the Runescape client.
     * 
     * @return The created ClassLoader
     */
    public static ClassLoader getClientClassLoader() {
        try {
            return new URLClassLoader(new URL[]{new URL("jar:file:cache/client.jar!/")});
        } catch (MalformedURLException ex) {
            throw new AssertionError(ex);
        }
    };
}
