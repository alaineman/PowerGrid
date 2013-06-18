package net.pgrid.loader;

import java.applet.Applet;
import java.io.IOException;
import java.net.URL;
import java.net.URLClassLoader;

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
     * Passing
     * <code>--quickload</code> as a parameter skips checking for a new client
     * version. This dramatically decreases load times, but requires rebooting
     * if the server rejects because of an outdated client.
     *
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        if (args.length > 0 && args[0].equals("--quickload")) {
            Logger.log("QuickLoad enabled");
            theLoader = new AppletLoader(true);
        } else {
            theLoader = new AppletLoader(false);
        }
        // First load the client.
        Thread loaderThread = new Thread(theLoader, "AppletLoader");
        loaderThread.start();

        // Meanwhile start and show the AppletFrame.
        theGUI = new AppletFrame();
        theGUI.init(theLoader.getDownloader());

        // And start the Applet once the client is loaded
        try {
            loaderThread.join();
        } catch (InterruptedException e) {
            Logger.describe(e);
        }
        theGUI.startApplet(theLoader.getApplet());

        Logger.log("Client loaded");
    }
    private ClientDownloader downloader;
    private Applet applet;
    private boolean quickload;

    /**
     * Constructs a new AppletLoader instance
     *
     * @param quickload true to skip reloading the client, false to always
     * download it.
     */
    public AppletLoader(boolean quickload) {
        downloader = new ClientDownloader();
        applet = null;
        this.quickload = quickload;
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
     * Downloads the client and creates a new
     * <code>Applet</code> instance.
     */
    @Override
    public void run() {
        long startTime = System.currentTimeMillis();
        try {

            // First we collect the required data...
            downloader.loadConfig();

            if (!quickload) {
                theGUI.showMessage("Downloading client");
                downloader.loadClient();
            } else {
                Logger.log("Reusing existing client data (May not work)");
            }
            // Meanwhile we can send the request for the mapping
            // TODO: send updater request.

            theGUI.showMessage("loading Classes");

            // ...then we load the classes...
            ClassLoader loader = new URLClassLoader(new URL[]{
                new URL("jar:file:client.jar!/")});
            Class<?> Rs2Applet = loader.loadClass("Rs2Applet");
            theGUI.showMessage("Creating Applet");

            // ...and create the Applet
            applet = (Applet) Rs2Applet.newInstance();

            long timeTaken = System.currentTimeMillis() - startTime;
            Logger.log("Total loading time: " + timeTaken + "ms");
        } catch (IOException | InstantiationException | IllegalAccessException | ClassNotFoundException e) {
            Logger.describe(e);
        }
    }
}
