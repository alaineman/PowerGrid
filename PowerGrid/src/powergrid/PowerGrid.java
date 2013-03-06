package powergrid;

import java.awt.Color;
import java.awt.Window;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import org.powerbot.Boot;
import powergrid.control.Mapper;
import powergrid.control.ScriptLoader;
import powergrid.control.TaskManager;
import powergrid.plugins.Plugin;
import powergrid.plugins.PluginInfo;
import powergrid.plugins.PluginLoader;
import powergrid.plugins.PowerGridPlugin;
import powergrid.tasks.Task;
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
 *   <dt>-eco (or -e)</dt>
 *   <dd>Eco-mode. Setting this flag will cause PowerGrid to put more effort into
 *       maintaining a low memory footprint. Might increase performance on low-end
 *       computers.</dd>
 *   <dt>-splitui (or -s)</dt>
 *   <dd>Split PowerGrid's user interface from RSBot window. This means that the
 *       PowerGrid control panel will appear in a separate frame.</dd>
 *   <dt>-plugins (or -p)</dt>
 *   <dd>Specify a custom Plugins directory. For example: 
 *       <code>java -jar PowerGrid.jar -p C:\customPluginDirectory</code> will look 
 *       for plugins in the directory named <code>C:\customPluginDirectory</code>
 *       instead of the default "plugins" directory.</dd>
 * </dl>
 * <p/>
 * @author Chronio
 */
public class PowerGrid {
    
    /** The PowerGrid version. */
    public static final double VERSION = 0.1;
    
    /** The PowerGrid instance. */
    public static final PowerGrid PG = new PowerGrid();
    /** The default Bot instance. */
    public static final Bot BOT = new Bot(null,TaskManager.getTM());
    /** The default Mapper instance. */
    public static final Mapper MAPPER = new Mapper(false);
    
    
    /** The plugin directory, default is "plugins". */
    public static File pluginDirectory = new File("plugins");
    
    /** Thread that shut down PowerGrid in case of RSBot shutdown. 
     * <p/>
     * Ensures that everything is cleaned up and terminated gracefully. 
     */
    private static Thread terminatorThread = new Thread("Terminator") {
        @Override public void run() {
            if (!PG.terminate())
                System.err.println("WARNING: PowerGrid termination failed");
        }
    };
    
    private static Plugin[] plugins = null;
    
    /**
     * Main method of PowerGrid. 
     * <p/>
     * This method starts RSBot and integrates PowerGrid in it. 
     * <p/>
     * @param args the command-line arguments
     */
    public static void main(String[] args) {
        System.out.println("Launching RSBot...");
        boolean dev=false,split=false,eco=false;
        Iterator<String> it = Arrays.asList(args).iterator();
        while (it.hasNext()) {
            String arg = it.next().toLowerCase();
            switch(arg) {
                case "-dev":
                    dev = true;
                    break;
                case "-splitui":
                case "-s":
                    split = true;
                    break;
                case "-eco":
                case "-e":
                    eco = true;
                    break;
                case "-plugins":
                case "-p":
                    File f = new File(it.next());
                    if (f.isDirectory())
                        pluginDirectory = f;
                    else
                        logMessage("The provided plugins folder (" + f.getName() + ") is not a valid directory");
                    break;
                default:
                    debugMessage("Unknown command-line parameter: " + arg);
            }
        }
        // Load the plugins in the plugin folder
        PluginLoader pl = new PluginLoader(pluginDirectory);
        plugins = pl.getLoadedPlugins();
        plugins = Arrays.copyOf(plugins, plugins.length+1);
        plugins[plugins.length-1] = new PowerGridPlugin();
        for (Plugin plugin : plugins) {
            String pluginName = plugin.getClass().getAnnotation(PluginInfo.class).name();
            plugin.setUp();
            logMessage("Plugin \"" + pluginName + "\" loaded");
        }
        logMessage("Total " + plugins.length + " Plugins loaded");
        
        // launch RSBot
        try {
            Boot.main(new String[0]);
            logMessage("RSBot started");
        } catch (Exception e) {
            logMessage("RSBot failed to start because of a " + e.getClass().getSimpleName() + ": " + e.getMessage());
            System.exit(1);
        }
        
        // Wait for Client's Thread to start
        Thread main = Thread.currentThread();
        ThreadGroup mainGroup = main.getThreadGroup();
        ThreadGroup[] groups = new ThreadGroup[1];
        while (true) {
            mainGroup.enumerate(groups, false);
            if (groups[0] != null && 
                    org.powerbot.core.Bot.instantiated() &&
                    org.powerbot.core.Bot.client() != null) {
                break;
            }
            Task.sleep(50);
        }
        Task.sleep(1200);
        
        // Launch PowerGrid
        PG.launch(dev,split,eco);
        
        
    }
    
    public static List<Plugin> getPlugins() {
        return Collections.unmodifiableList(Arrays.asList(plugins));
    }
    
    private boolean isRunning = false;
    private boolean devmode = false; 
    private boolean splitUI = false;
    private boolean ecoMode = false;
    
    private ControlPanel theControlPanel = null;
    private ScriptLoader taskManagerLoader = null;
    
    private PowerGrid() {}
    
    /**
     * Launches PowerGrid with the given settings.
     * <p/>
     * @param devmode true to enable developer mode, false to disable
     * @param splitUI true to split the user interface in a separate frame
     * @param ecoMode true to make PowerGrid more light-weight by saving memory
     * @return whether the launch was succesful
     */
    public boolean launch(boolean devmode, boolean splitUI, boolean ecoMode) {
        this.devmode = devmode;
        this.splitUI = splitUI;
        this.ecoMode = ecoMode;
        return launch();
    }
    
    /**
     * Launches PowerGrid with the current (default) settings.
     * <p/>
     * After launching PowerGrid, the Mapper will automatically start mapping and
     * Tasks will be executed from the Task queue.
     * @return whether the launch was succesful
     */
    public boolean launch() {
        if (isRunning) 
            return false;
        logMessage("starting PowerGrid...");
        debugMessage("With parameters: Developer mode" 
                                        + (splitUI ? ", Split user interface":"") 
                                        + (ecoMode ? ", Eco mode":""));
        if (splitUI) {
            ControlPanel.addControlPanel(null, null);
        } else {
            PowerGrid.debugMessage("Modifying RSBot JFrame...");
            for (Window w : Window.getWindows()) {
                if (w instanceof JFrame) {
                    JFrame f = (JFrame)w;
                    f.setBackground(Color.BLACK);
                    theControlPanel = ControlPanel.addControlPanel(f, "South");
                    f.pack();
                    try {
                        BufferedImage icon = ImageIO.read(ClassLoader.getSystemResource("powergrid/images/icon_small.png"));
                        f.setIconImage(icon);
                        f.setTitle(f.getTitle() + " - Running PowerGrid v" + PowerGrid.VERSION);
                        PowerGrid.debugMessage("JFrame modification complete");
                    } catch (IOException e) {
                        PowerGrid.logMessage("Error setting image on RSBot JFrame: " + e);
                    }
                }
            }
        }
        debugMessage("ControlPanel created");
        
        taskManagerLoader = new ScriptLoader(TaskManager.getTM());
        
        debugMessage("TaskManager created");
        
        BOT.reloadLocalPlayer();
        taskManagerLoader.run();
        MAPPER.withClient(org.powerbot.core.Bot.client());
        MAPPER.startMapping();
        debugMessage("Mapper Started");
        
        Runtime.getRuntime().addShutdownHook(terminatorThread);
        logMessage("PowerGrid started");
        theControlPanel.setMessage("PowerGrid running...");
        isRunning = true;
        return true;
    }
    
    /**
     * Terminates PowerGrid, freeing the memory it used and disables core functionality.
     * <p/>
     * PowerGrid can still be used for Pathfinding and such, but be advised that 
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
        MAPPER.stopMapping();
        debugMessage("Mapper stopped");
        theControlPanel.getParent().remove(theControlPanel);
        theControlPanel = null;
        debugMessage("ControlPanel removed");
        taskManagerLoader.stop();
        taskManagerLoader = taskManagerLoader.copyLoader();
        debugMessage("TaskManager stopped");
        logMessage("PowerGrid stopped");
        isRunning = false;
        return true;
    }
    
    /**
     * terminates PowerGrid and launches it again using the same settings.
     * <p/>
     * This does not affect RSBot or any running scripts, but it will clear the TaskQueue
     * and cause the Mapper to reset to MAP_CONTINOUSLY.
     * <p/>
     * @return whether the operation was succesful
     */
    public boolean reset() {
        if (terminate()) {
            return launch();
        } else {
            return false;
        }
    }

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
     * Logs a message to the console, followed by a stack trace of the provided 
     * Throwable if PowerGrid runs in devmode.
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
                if (elementCount > 10) {
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
}
