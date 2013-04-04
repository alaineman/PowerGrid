package powergrid;

import java.awt.Window;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.List;
import java.util.logging.ConsoleHandler;
import java.util.logging.Formatter;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.LogRecord;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import org.powerbot.Boot;
import org.powerbot.game.client.Client;
import powergrid.control.Mapper;
import powergrid.control.ScriptLoader;
import powergrid.control.TaskManager;
import powergrid.control.interaction.InteractionController;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.WorldMap;
import powergrid.plugins.Plugin;
import powergrid.plugins.PluginInfo;
import powergrid.plugins.PluginLoader;
import powergrid.plugins.PowerGridPlugin;
import powergrid.task.Task;
import powergrid.view.ControlPanel;

/**
 * Main class for PowerGrid.
 * <p/>
 * This class deals with starting and stopping PowerGrid, loading and starting 
 * available scripts, and handling configuration settings and parameters.
 * <p/>
 * PowerGrid's main method can take the following arguments:
 * <dl>
 *   <dt>-dev</dt>
 *   <dd>PowerGrid developer mode. Setting this flag logs more detailed messages
 *       to the console.</dd>
 *   <dt>-splitui (or -s)</dt>
 *   <dd>Split PowerGrid's user interface from RSBot window. This means that the
 *       PowerGrid control panel will appear in a separate frame.</dd>
 *   <dt>-plugins (or -p)</dt>
 *   <dd>Specify a custom Plugins directory. For example: 
 *       <code>java -jar PowerGrid.jar -p someFolder\customPluginDirectory</code> will look 
 *       for plugins in the directory named <code>someFolder\customPluginDirectory</code>
 *       instead of the default "plugins" directory.</dd>
 * </dl>
 * <p/>
 * @author Chronio
 */
public class PowerGrid {
    
    /** The name of PowerGrid, which is "PowerGrid". */
    public static final String NAME = "PowerGrid";
    
    /** The PowerGrid version. */
    public static final double VERSION = 0.1;
    
    /** The PowerGrid Logger. */
    public static final Logger LOGGER = Logger.getLogger(NAME);
    
    /** The PowerGrid instance. */
    public static PowerGrid PG = null;
    /** The default TaskManager instance. */
    public static final TaskManager TM = new TaskManager();
    /** The default Mapper instance. */
    public static final Mapper MAPPER = new Mapper();
    
    
    /** The plugin directory, default is "plugins". */
    public static File pluginDirectory = new File("plugins");
    
    /** Thread that shuts down PowerGrid in case of RSBot shutdown. 
     * <p/>
     * Ensures that everything is cleaned up and terminated gracefully. 
     */
    private static Thread terminatorThread 
            = new Thread("PowerGrid-Terminator") {
        @Override public void run() {
            if (!PG.terminate())
                System.err.println("WARNING: PowerGrid termination failed");
        }
    };
    
    
    
    /**
     * Main method of PowerGrid. 
     * <p/>
     * This method starts RSBot and integrates PowerGrid in it. 
     * <p/>
     * @param args the command-line arguments
     */
    public static void main(String[] args) {
        ConsoleHandler handler = new ConsoleHandler();
        handler.setFormatter(new PGFormatter());
        LOGGER.setUseParentHandlers(false);
        LOGGER.addHandler(handler);
        RSBotUpdater updater = new RSBotUpdater();
        // launch RSBot
        try {
            try {
                // the main runner method of RSBot. Frankly, the rest is 
                // optional (also, this does not load the SecurityManager).
                org.powerbot.qb.a();
                LOGGER.info("RSBot started - no SecurityManager set");
            } catch (Exception e) {
                Boot.main(new String[0]);
                LOGGER.log(Level.WARNING, "RSBot started normally", e);
            }
            updater.hook();
            LOGGER.info("RSBot started.");
        } catch (Exception e) {
            LOGGER.log(Level.SEVERE, "RSBot failed to start.", e);
            System.exit(1);
        }
        
        
        Iterator<String> it = Arrays.asList(args).iterator();
        while (it.hasNext()) {
            String arg = it.next();
            if (arg.equals("-p") || arg.equals("-plugins")) {
                if (it.hasNext()) {
                    File pluginDir = new File(it.next());
                    if (pluginDir.isDirectory()) {
                        pluginDirectory = pluginDir;
                        LOGGER.info("Custom plugin directory set at " 
                                + pluginDir.getPath());
                    }
                }
            }
        }
        // Wait for Client's Thread to start
        waitForClient();
        
        // when RSBot has loaded the client, there are no updates.
        updater.unhook();
        
        PG = new PowerGrid(org.powerbot.core.Bot.client());
        // Load the default PowerGridPlugin and any custom Plugins.
        PG.loadPlugin(new PowerGridPlugin());
        PG.loadPlugins(pluginDirectory);
        LOGGER.info("Plugins loaded. Starting PowerGrid...");
        if (PG.launch(true, false)) {
            LOGGER.info("PowerGrid started and running");
        } else {
            LOGGER.severe("PowerGrid failed to start, shutting down");
            System.exit(1);
        }
    }
    
    /**
     * Waits for the RSBot client to start, and returns after that.
     */
    private static void waitForClient() {
        Thread main = Thread.currentThread();
        ThreadGroup mainGroup = main.getThreadGroup();
        ThreadGroup[] groups = new ThreadGroup[1];
        // 25 seconds is the maximum wait time before deciding RSBot takes too 
        // long.
        long destTime = System.currentTimeMillis() + 30000;
        
        JFrame frame =  null;
        while (frame == null) {
            Window[] ws = Window.getWindows();
            if (ws.length > 0 && ws[0] instanceof JFrame) {
                frame = (JFrame) ws[0];
            }
        }
        
        
        
        while (true) {
            // find all ThreadGroups directly in the main ThreadGroup
            mainGroup.enumerate(groups, false);
            if (groups[0] != null && 
                    org.powerbot.core.Bot.instantiated() &&
                    org.powerbot.core.Bot.client() != null) {
                // RSBot's ThreadGroup is active and the bot is instantiated.
                break;
            }
            Task.sleep(50);
            String text = ""; //notificationLabel.getText().toLowerCase();
            
            if (System.currentTimeMillis() > destTime 
                    || text.contains("newer version")) {
                // in case of a timeout, prompt the user to update
                
                break;
            }
        }
        // Give the GUI time to properly initialize before continuing.
        Task.sleep(1200);
    }
    
    private boolean isRunning = false;
    private boolean devmode = false; 
    private boolean splitUI = false;
    
    private ControlPanel theControlPanel = null;
    
    private List<Plugin> plugins;
    
    private Client client;
    private InteractionController iController;
    private Mapper mapper;
    private RSInteractor rsInteractor;
    private TaskManager taskManager;
    private Bot bot;
    private ScriptLoader taskManagerLoader;
    
    public PowerGrid(Client c) {
        assert c != null;
        plugins = new ArrayList<>();
        client = c;
        iController = new InteractionController();
        mapper = new Mapper().withClient(client);
        rsInteractor = new RSInteractor().useClient(client)
                .useWorldMap(mapper.getWorldMap());
        taskManager = new TaskManager();
        bot = new Bot(taskManager);
        taskManagerLoader = new ScriptLoader(taskManager);
    }
    
    /**
     * Loads Plugins from the specified directory.
     * @param directory the directory from which to load.
     */
    public void loadPlugins(File directory) {
        assert directory != null && directory.isDirectory();
        PluginLoader pl = new PluginLoader(directory);
        List<Plugin> ps = Arrays.asList(pl.getLoadedPlugins());
        if (plugins == null) {
            plugins = new ArrayList<>(ps);
        } else {
            plugins.addAll(ps);
        }
        for (Plugin p : ps) {
            /* try to setUp each Plugin instance or discard upon Exception.
             * This way it is certain that PowerGrid will not crash because of 
             * loading a failing Plugin.
             */
            String name = p.getClass().getAnnotation(PluginInfo.class).name();
            try {
                p.withPowerGrid(this);
                p.setUp();
                LOGGER.info("Plugin loaded: " + name);
            } catch (Exception e) {
                LOGGER.log(Level.WARNING, "Failed to load Plugin " + name, e);
                plugins.remove(p);
            }
        }
    }
    
    /**
     * Returns an unmodifiable List containing the loaded Plugins.
     * @return an unmodifiable List containing the loaded Plugins.
     */
    public List<Plugin> getPlugins() {
        return Collections.unmodifiableList(plugins);
    }
    
    
    /**
     * Loads the specified Plugin.
     * @param p the Plugin to load.
     */
    public void loadPlugin(Plugin p) {
        assert p != null : "Null value for Plugin";
        String name = p.getClass().getAnnotation(PluginInfo.class).name();
        plugins.add(p);
        try {
            p.withPowerGrid(this);
            p.setUp();
            LOGGER.info("Plugin loaded: " + name);
        } catch (Exception e) {
            LOGGER.log(Level.WARNING, "Failed to load Plugin " + name, e);
            plugins.remove(p);
        }
    }
    
    /**
     * unloads the specified Plugin
     * @param p the Plugin to unload
     * @return true if the plugin list changed as a result of this call, false 
     *         otherwise.
     */
    public boolean removePlugin(Plugin p) {
        assert p != null : "Null value for Plugin";
        int index = plugins.indexOf(p);
        if (index < 0) {
            return false;
        } else {
            plugins.remove(index);
            p.tearDown();
            return true;
        }
    }
    
    public Client client() {
        return client;
    }
    
    public InteractionController interactionController() {
        return iController;
    }
    
    public Mapper mapper() {
        return mapper;
    }
    
    public RSInteractor rsInteractor() {
        return rsInteractor;
    }
    
    public TaskManager taskManager() {
        return taskManager;
    }
    
    public WorldMap worldmap() {
        return mapper().getWorldMap();
    }
    
    public Bot bot() {
        return bot;
    }
    
    /**
     * Launches PowerGrid with the given settings.
     * <p/>
     * @param devmode true to enable developer mode, false to disable
     * @param splitUI true to split the user interface in a separate frame
     * @return whether the launch was successful
     */
    public boolean launch(boolean devmode, boolean splitUI) {
        assert plugins != null;
        if (isRunning) {
            return false;
        }
        this.devmode = devmode;
        this.splitUI = splitUI;
        return launch();
    }
    
    /**
     * Launches PowerGrid with the current (or default) settings.
     * <p/>
     * After launching PowerGrid, the Mapper will automatically start mapping 
     * and Tasks will be executed from the Task queue.
     * @return whether the launch was successful
     */
    public boolean launch() {
        assert plugins != null;
        if (isRunning) 
            return false;
        logMessage("starting PowerGrid...");
        debugMessage("With parameters: Developer mode"
                + (splitUI ? ", Split user interface":""));
        if (splitUI) {
            ControlPanel.addControlPanel(null, null);
        } else {
            PowerGrid.debugMessage("Modifying RSBot JFrame...");
            Window[] ws = Window.getWindows();
            if (ws.length > 0 && ws[0] instanceof JFrame) {
                theControlPanel = ControlPanel.addControlPanel(ws[0], "South");
            }
        }
        debugMessage("ControlPanel created");
        
        taskManagerLoader.run();
        
        mapper().startMapping();
        debugMessage("Mapper Started");
        
        Runtime.getRuntime().addShutdownHook(terminatorThread);
        logMessage("PowerGrid started");
        theControlPanel.setMessage("PowerGrid has started");
        isRunning = true;
        
        return true;
    }
    
    /**
     * Terminates PowerGrid, disabling core functionality.
     * <p/>
     * PowerGrid can still be used for Pathfinding and such, but be aware that 
     * the Worldmap will not be updated and Tasks will not be executed anymore.
     * <p/>
     * @return whether the termination was succesful
     */
    public boolean terminate() {
        if (!isRunning)
            return false;
        logMessage("stopping PowerGrid...");
        theControlPanel.setMessage("PowerGrid stopping...");
        try {
            Runtime.getRuntime().removeShutdownHook(terminatorThread);
        } catch (IllegalStateException e) {} // was already shutting down
        if (MAPPER.isMapping()) 
            MAPPER.stopMapping();
        debugMessage("Mapper stopped");
        
        theControlPanel.getParent().remove(theControlPanel);
        theControlPanel = null;
        debugMessage("ControlPanel removed");
        
        taskManagerLoader.stop();
        taskManagerLoader = taskManagerLoader.copy();
        debugMessage("TaskManager stopped");
        
        for (Plugin p : plugins) {
            p.tearDown();
        }
        debugMessage("Plugins finalized");
        
        logMessage("PowerGrid stopped");
        isRunning = false;
        return true;
    }

    /**
     * Returns whether PowerGrid is started in DevMode.
     * <p/>
     * Plugin developers can use this to enable or disable certain options depending
     * on this setting.
     * @return whether PowerGrid is running in Developer Mode.
     */
    public boolean isDevmode() {
        return devmode;
    }
    
    /**
     * Logs a message to the console.
     * @param message the message to log
     */
    public static void logMessage(String message) {
        System.out.println("[PowerGrid] " + message);
    }
    
    /**
     * Logs a message to the console, followed by a stack trace (max 10 items) of 
     * the provided Throwable if PowerGrid runs in devmode.
     * <p/>
     * If PowerGrid is not running in devmode, only a line with "caused by 
     * ExceptionClass: Exception message" will be displayed.
     * @param message the message to log
     * @param cause the Throwable that caused the message to be logged
     */
    public static void logMessage(String message, Throwable cause) {
        if (cause == null) {
            logMessage(message);
            return;
        }
        System.out.println("[PowerGrid] " + message);
        System.out.println("  caused by: " + cause.getClass().getSimpleName() + ": " + cause.getMessage());
        if (PG.isDevmode()) {
            StackTraceElement[] trace = cause.getStackTrace();
            int elementCount = 0;
            for (StackTraceElement e : trace) {
                System.out.println("    in " + e.getClassName() + ": " + e.getLineNumber() + " (" + e.getMethodName() + ")");
                elementCount++;
                if (elementCount >= 10) {
                    System.out.println("    (" + (trace.length-10) + " more...)");
                    break;
                }
            }
        }
    }
    
    /**
     * Logs a message to the console only if PowerGrid is running in devmode.
     * @param message the message to log
     */
    public static void debugMessage(String message) {
        if (PG.isDevmode()) System.out.println("[PowerGrid] <debug> " + message);
    }
    
    /**
     * Logs a message to the console followed by the stack trace of the provided 
     * Throwable if and only if PowerGrid is started in Developer mode.
     * @param message the message to log
     * @param cause the Throwable that caused this message to be logged.
     */
    public static void debugMessage(String message, Throwable cause) {
        if (PG.isDevmode()) {
            logMessage("<debug> " + message, cause);
        }
    }
    
    public static class PGFormatter extends Formatter {
        @Override
        public String format(LogRecord record) {
            StringBuilder sb = new StringBuilder("[")
                    .append(record.getLoggerName())
                    .append(": ").append(record.getLevel()).append("] ")
                    .append(record.getMessage());
            Throwable thrown = record.getThrown();
            while (thrown != null) {
                sb.append("\n  caused by: ")
                        .append(thrown.getClass().getSimpleName())
                        .append("\n    ").append(thrown.getMessage());
                thrown = thrown.getCause();
            }
            return sb.append("\n").toString();
        }
    }
}
