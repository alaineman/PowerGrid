package net.pgrid.loader;

import java.applet.Applet;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import net.pgrid.loader.bridge.ClassMapDownloader;
import net.pgrid.loader.bridge.injection.ControlFrame;
import net.pgrid.loader.bridge.injection.keyboard.AWTKeyInjector;
import net.pgrid.loader.bridge.injection.keyboard.KeyInjector;

/**
 * Main class of the Runescape loader.
 * <p/>
 * The AppletLoader class is responsible for managing a ClientDownloader
 * instance to download the client, and to create an
 * <code>Applet</code> instance from the downloaded client.
 * <p/>
 * @author Chronio
 */
public class AppletLoader implements Runnable {

    private static final Logger LOGGER = Logger.get("CORE");
    
    /**
     * The global AppletLoader instance.
     */
    public static AppletLoader theLoader = null;
    /**
     * The global AppletFrame instance.
     */
    public static AppletFrame theGUI = null;

    /**
     * Starts the AppletLoader.
     * <p/>
     * The AppletLoader works on three Threads: one for the AppletFrame, one for loading
     * the Runescape client, and one for acquiring the updater data.
     * <p/>
     * Passing <code>--quickload</code> as a parameter skips checking for a new client
     * version. This dramatically decreases load times, but requires rebooting
     * if the server rejects because of an outdated client.
     * <p/>
     * Passing <code>--update</code> as a parameter explicitly enables the updater.
     * Default this option is disabled because it speeds up loading time for users that use this 
     * application without the PowerGrid loader, since in that case you don't need the updater.
     * However, the option exists to allow users to explicitly load the updater information if they want to.
     * <p/>
     * Similarly, <code>--no-update</code> explicitly disables updating. 
     * <p/>
     * Passing an empty array (or no arguments from the command line) the 
     * application assumes it's running in standalone mode. In that case, the 
     * updater is disabled by default. If null is passed as the argument to this 
     * method, it is assumes there is a client invoking it (since Java itself 
     * passes an empty array when no arguments are given). In that case the 
     * updater is enabled by default. To explicitly state a client is invoking 
     * this application, the <code>--no-standalone</code> parameter can be used.
     * <p/>
     * If conflicting arguments occur, the last is always valid. This method 
     * iterates over each argument and applies the corresponding settings, but 
     * also allows these settings to be overridden again.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // default arguments for standalone
        boolean quickload = false,
                update = false,
                devel = false;
        
        // the PowerGrid C++ client calls main with null, while Java default 
        // passes an empty array if there are no arguments. This way we can 
        // a) easily distinct between the two startup modes.
        // b) get the settings right for the PowerGrid C++ client without 
        //    having to create a String array through JNI.
        if (args == null) {
            // default arguments for non-standalone
            update = true;
        } else {
            // parse the actual arguments to override 
            for (String s : args) {
                switch (s) {
                    case "--quickload":
                        quickload = true;
                        break;
                    case "--update": 
                        update = true; 
                        break;
                    case "--devmode":
                        devel = true;
                        break;
                    default:
                        LOGGER.log("Unknown parameter found: \"" + s + "\"");
                }
            }
        }
        // Report the used parameters to the Logger
        if (quickload)  LOGGER.log("Quickload enabled");
        if (update)     LOGGER.log("Updater enabled");
        if (devel)      LOGGER.log("DevMode enabled");
        
        theLoader = new AppletLoader(quickload, update, devel);
        theGUI = new AppletFrame();
        
        // First load the client.
        Thread loaderThread = new Thread(theLoader, "AppletLoader");
        loaderThread.start();

        // Meanwhile start and show the AppletFrame.
        theGUI.init(theLoader.getDownloader());

        // And start the Applet once the client is loaded
        try {
            loaderThread.join();
        } catch (InterruptedException e) {
            LOGGER.describe(e);
        }
        Applet a = theLoader.getApplet();
        theGUI.startApplet(a);
        
        try {
            Thread.sleep(10000);
        } catch (InterruptedException ex) {}
        
        
        LOGGER.log("Client loaded");
    }
    
    private ClientDownloader downloader;
    private Applet applet;
    private boolean quickload, update, devel; 
    

    /**
     * Constructs a new AppletLoader instance
     *
     * @param quickload true to skip reloading the client, false to always
     * download it.
     * @param update true to enable updater, false to disable it.
     * @param devel true to enable development tools, false to disable. 
     */
    public AppletLoader(boolean quickload, boolean update, boolean devel) {
        downloader = new ClientDownloader();
        applet = null;
        this.quickload = quickload;
        this.update = update;
        this.devel = devel;
    }

    /**
     * @return the ClientDownloader used for downloading the required data from
     * the Runescape servers
     */
    public ClientDownloader getDownloader() {
        return downloader;
    }

    /**
     * @return the Runescape <code>Applet</code> instance created by this
     * AppletLoader, or null if none has been created yet.
     */
    public Applet getApplet() {
        return applet;
    }

    /**
     * @return true if this AppletLoader will try to skip re-downloading the
     * client.
     */
    public boolean isQuickload() {
        return quickload;
    }
    
    
    /**
     * Safe version of the run method. It first disables quickload and provides 
     * more detailed logging in the event something goes wrong.
     * <p/>
     * It also creates a new ClientDownloader to use and any existing Applet 
     * instance is removed to prevent possible issues with that.
     */
    public void runSafe() {
        LOGGER.log("Attempting to start Applet in safe mode");
        try {
            downloader = new ClientDownloader();
        } catch (InternalError e) {
            LOGGER.log("The URL used by the ClientDownloader is invalid");
            LOGGER.describe(e);
            return;
        }
        applet = null;
        quickload = false;
        
        theGUI.showMessage("Reloading client");
        
        try {
            downloader.loadConfig();
        } catch (IOException e) {
            LOGGER.log("Error loading config");
            LOGGER.describe(e);
            return;
        }
        
        if (update) {
            new Thread(new ClassMapDownloader(downloader)).start();
        }
        
        try {
            downloader.loadClient();
        } catch (IOException e) {
            LOGGER.log("Error loading config");
            LOGGER.describe(e);
            return;
        }
        
        Class<?> appletClass;
        try {
            ClassLoader loader = new URLClassLoader( 
                    new URL[] { new URL("jar:file:client.jar!/") } );
            appletClass = loader.loadClass("Rs2Applet");
        } catch (MalformedURLException | ClassNotFoundException e) {
            LOGGER.log("Error loading Rs2Applet class");
            LOGGER.describe(e);
            return;
        }
        if (appletClass == null) {
            LOGGER.log("Error: Rs2Applet class == null");
            return;
        }
        try {
            applet = (Applet) appletClass.getConstructor().newInstance();
        } catch (NoSuchMethodException | InstantiationException | InvocationTargetException | IllegalAccessException e) {
            LOGGER.log("Cannot create Applet");
            LOGGER.describe(e);
        }
        LOGGER.log("Loading done");
    }

    /**
     * Downloads the client and creates a new <code>Applet</code> instance.
     */
    @Override
    public void run() {
        long startTime = System.currentTimeMillis();
        try {

            // First we collect the required data...
            downloader.loadConfig();
            
            // Note that we can just start and otherwise ignore the 
            // ClassMapDownloader, it will complete the process on its own.
            if (update) {
                new Thread(new ClassMapDownloader(downloader)).start();
            }
            
            if (!quickload) {
                theGUI.showMessage("Downloading client");
                downloader.loadClient();
            } else {
                LOGGER.log("Reusing existing client data (May not work)");
            }
            
            theGUI.showMessage("loading Classes");

            // ...then we load the classes...
            ClassLoader loader = new URLClassLoader(new URL[]{
                new URL("jar:file:client.jar!/")});
            Class<?> Rs2Applet = loader.loadClass("Rs2Applet");
            theGUI.showMessage("Creating Applet");

            // ...and create the Applet
            applet = (Applet) Rs2Applet.getConstructor().newInstance();
            
            if (devel) {
                KeyInjector injector = new AWTKeyInjector();
                injector.setTarget(theGUI);
                new ControlFrame(injector);
                
                // In order to get feedback on loading times with different settings,
                // the loading time is reported when development mode is enabled.
                long timeTaken = System.currentTimeMillis() - startTime;
                LOGGER.log("Total loading time: " + timeTaken + "ms");
            }
        } catch (IOException | ClassNotFoundException | InstantiationException | 
                IllegalAccessException | NoSuchMethodException | 
                InvocationTargetException e) {
            LOGGER.describe(e);
        }
    }
}
