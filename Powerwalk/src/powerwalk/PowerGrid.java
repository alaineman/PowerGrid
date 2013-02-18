package powerwalk;

import java.awt.Window;
import java.io.File;
import java.util.Arrays;
import java.util.Iterator;
import java.util.logging.ConsoleHandler;
import java.util.logging.Formatter;
import java.util.logging.LogRecord;
import java.util.logging.Logger;
import javax.swing.JFrame;
import org.powerbot.Boot;
import powerwalk.control.Mapper;
import powerwalk.view.ControlPanel;

/**
 * Main class for PowerGrid.
 * <p/>
 * This class deals with starting and stopping PowerGrid, loading and starting 
 * available scripts, and handling configuration settings and parameters.
 * <p/>
 * PowerGrid's main method can take the following arguments:
 * <dl>
 *   <dt>-pgdev</dt>
 *   <dd>PowerGrid developer mode. Setting this flag logs more detailed messages
 *       to the console.</dd>
 *   <dt>-eco</dt>
 *   <dd>Eco-mode. Setting this flag will cause PowerGrid to put more effort into
 *       maintaining a low memory footprint. Might increase performance on low-end
 *       computers.</dd>
 *   <dt>-splitui</dt>
 *   <dd>Split PowerGrid's user interface from RSBot window. This means that the
 *       PowerGrid control panel will appear in a separate frame.</dd>
 * </dl>
 * <p/>
 * @author Chronio
 */
public class PowerGrid {
    
    public static final Logger LOGGER = Logger.getLogger("PowerGrid");
    /** The PowerGrid version */
    public static final double VERSION = 0.1;
    
    /** The PowerGrid instance. */
    public static final PowerGrid PG = new PowerGrid();
    /** The plugin directory. Default is "plugins". */
    public static File pluginDirectory = new File("plugins");
    
    /** Thread that terminates PowerGrid in case of shutdown. Ensures that everything is cleaned up. */
    private static Thread terminatorThread = new Thread("Terminator") {
        @Override public void run() {
            PG.terminate();
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
        System.out.println("Launching RSBot...");
        boolean rsBotDevMode = false;
        boolean dev=false,split=false,eco=false;
        Iterator<String> it = Arrays.asList(args).iterator();
        while (it.hasNext()) {
            String arg = it.next().toLowerCase();
            switch(arg) {
                case "-dev": 
                    rsBotDevMode = true; 
                    break;
                case "-pgdev":
                    dev = true;
                    break;
                case "-splitui":
                    split = true;
                    break;
                case "-eco":
                    eco = true;
                    break;
                case "-plugins":
                    File f = new File(it.next());
                    if (f.isDirectory())
                        pluginDirectory = f;
                    break;
                default:
                    debugMessage("Unknown command-line parameter: " + arg);
            }
        }
        
        // Start RSBot
        if (rsBotDevMode) {
            Boot.main(new String[]{"-dev"});
        } else {
            Boot.main(new String[]{});
        }
        
        if (!PG.launch(dev,split,eco)) {
            logMessage("PowerGrid failed to launch");
        }
        
    }
    
    private boolean isRunning = false;
    private boolean devmode = false; 
    private boolean splitUI = false;
    private boolean ecoMode = false;
    
    private boolean loggersInitialized = false;
    
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
        
        Mapper.startMapping(Mapper.MAP_CONTINOUSLY);
        Mapper.setEcoMode(ecoMode);
        debugMessage("Mapper started");
        if (splitUI) {
            ControlPanel.addControlPanel(null, null);
        } else {
            for (Window w : Window.getWindows()) {
                if (w instanceof JFrame)
                    ControlPanel.addControlPanel((JFrame)w, "South");
            }
        }
        debugMessage("ControlPanel created");
        Runtime.getRuntime().addShutdownHook(terminatorThread);
        logMessage("PowerGrid started");
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
        try {
            Runtime.getRuntime().removeShutdownHook(terminatorThread);
        } catch (IllegalStateException e) {} // was already shutting down
        Mapper.stopMapping();
        debugMessage("Mapper stopped");
        logMessage("PowerGrid stopped");
        isRunning = false;
        return false;
    }
    
    /**
     * terminates PowerGrid and launches it again using the same settings.
     * <p/>
     * This does not affect RSBot or any running scripts.
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
     * Logs a message to the console only if PowerGrid is running in devmode.
     * @param message the message to log
     */
    public static void debugMessage(String message) {
        if (PG.devmode) System.out.println("[PowerGrid] <debug> " + message);
    }
    
    
    
    private void setLoggerFormatAndHandlers() {
        if (loggersInitialized) return;
        LOGGER.setUseParentHandlers(false);
        ConsoleHandler handler = new ConsoleHandler();
        handler.setFormatter(new Formatter() {
            @Override public String format(final LogRecord record) {
                Object[] params = record.getParameters();
                StringBuilder sb = new StringBuilder("[PowerGrid");
                if (params != null && params.length > 0 && params[0] != null) {
                    sb.append(" > ").append(record.getParameters()[0]);
                }
                sb.append("] ").append(record.getMessage()).append("\r\n");
                if (params != null && params.length > 1 && params[1] instanceof Throwable) {
                    Throwable t = (Throwable)params[1];
                    sb.append("      caused by ").append(t.getClass().getSimpleName());
                    sb.append(": ").append(t.getMessage()).append("\r\n");
                    if (devmode) {
                        // print stack trace
                        StackTraceElement[] traces = t.getStackTrace();
                        for (StackTraceElement e : traces) {
                            sb.append("        at ").append(e.getClassName()).append(".");
                            sb.append(e.getMethodName()).append(": ");
                            int ln = e.getLineNumber();
                            if (ln > 0) 
                                sb.append(e.getLineNumber());
                            else // line numbers less than 0 are invalid
                                sb.append("(unknown line number)");
                            sb.append("\r\n");
                        }
                    }
                }
                return sb.toString();
            }
        });
        LOGGER.addHandler(handler);
        loggersInitialized = true;
    }
}
