package powerwalk;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.*;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import org.powerbot.game.api.methods.Environment;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powerwalk.control.Mapper;
import powerwalk.control.ToolBox;
import powerwalk.control.noticeboard.Quests;
import powerwalk.model.Destinations;
import powerwalk.model.XMLNode;
import powerwalk.tasks.StepTask;
import powerwalk.tasks.Task;
import powerwalk.view.ContentFrame;

/**
 * Starter and Task Manager class for the entire plug-in.
 *
 * @author Chronio
 * @author Alaineman
 */
@Manifest(
        authors        = { "Alaineman" , "Chronio" },
        name           = Starter.productName,
        description    = "Runs all day!",
        version        = Starter.version,
        singleinstance = true)
public class Starter extends ActiveScript {

    public static final Logger theLogger = Logger.getLogger(Starter.class.getName());
    public static final String worldMapFile = "worldmap.xml";
    /** The name of the Plug-in */
    public static final String productName = "PowerWalk";
    /** The version number */
    public static final double version = 0.1;
    private static Task currentTask = null;

    /**
     * Creates a ContentFrame instance and shows it.
     */
    @Override public void onStart() {
        theLogger.setUseParentHandlers(false);
        ConsoleHandler handler = new ConsoleHandler();
        handler.setFormatter(new Formatter() {
            @Override public String format(final LogRecord record) {
                StringBuilder sb = new StringBuilder();
                sb.append("[PowerWalk] ");
                Object[] params = record.getParameters();
                if (params != null && params.length > 0) {
                    if (record.getParameters()[0] != null)
                        sb.append("[").append(record.getParameters()[0]).append("] ");
                    else
                        sb.append("[none] ");
                } else {
                    sb.append("[Main] ");
                }
                int n = sb.length();
                String indent = "                "; // counted; this is the minimum prefix size
                while (indent.length() < n) {
                    indent += " ";
                }
                String[] lines = record.getMessage().split("\n");
                for (int i=0;i<lines.length;i++) {
                    String l = lines[i];
                    if (i > 0) sb.append(indent);
                    sb.append(l);
                    sb.append("\n");
                }
                return sb.toString();
            }
        });
        theLogger.addHandler(handler);
        logMessage("Loading required resources...");
        try (FileInputStream worldMapIn = new FileInputStream(Environment.getStorageDirectory().toString() + "\\" + worldMapFile)) {
            XMLNode worldMap = ToolBox.getXMLTree(worldMapIn);
            Bot.getBot().getWorldMap().fillFromXML(worldMap);
            logMessage("WorldMap loaded");
        } catch (FileNotFoundException e) {
            logMessage("WorldMap file does not exist; starting with empty WorldMap");
        } catch (IOException e) {
            logMessage("WorldMap failed to load");
        }
        Mapper.startMapping(Mapper.MAP_CONTINOUSLY);
        
        // Load Quest data directly from Noticeboard, since Quest class doesn't seem to work properly
        Quests.updateQuestData();
        
        // try to run a implementing script, if it exists
        (new Thread() {
            @Override public void run() {
                try { init(); }
                catch (RuntimeException e) {
                    Starter.logMessage("No script loaded on top of PowerWalk, running stand-alone");
                }
            }
        }).start();
        ContentFrame.theFrame = new ContentFrame();
        logMessage("PowerWalk started, waiting for tasks...");
    }

    /**
     * This method is intended for scripters who want to build their script on
     * the PowerWalk API, and should be overridden to start their own script.
     * <p/>
     * This method is called on a separate Thread, so
     * any methods calls made from this method will be asynchronous with PowerWalk
     * or RSBot.
     * <p/>
     * It is not advised to build scripts on RSBot's script loader when intending
     * to use PowerWalk. Instead, scripts that use PowerWalk should override
     * this method to start their script.
     * <p/>
     * Furthermore, scripts that are run from this method should implement a
     * looping mechanism themselves, since the script will end once this method
     * returns.
     * <p/>
     * @throws RuntimeException when calling this method without having overridden it.
     */
    public void init() {
        throw new RuntimeException("no implementing subclass");
    }
    
    /**
     * executes a Task from the TaskQueue.
     *
     * @return an integer specifying the amount of milliseconds the caller
     * should wait before calling this method again.
     */
    @Override public int loop() {
        if (Bot.getBot().tasksPending() > 0) {
            currentTask = Bot.getBot().retrieveTask();
            if (currentTask instanceof StepTask) {
                StepTask task = (StepTask) currentTask;
                logMessage("Beginning StepTask \"" + task.getName() + "\"...","TaskManager");
                task.start();
                while (task.hasMoreSteps()) {
                    task.execute();
                }
                task.finish();
                logMessage("StepTask \"" + task.getName() + "\" has ended","TaskManager");
            } else {
                logMessage("Beginning Task \"" + currentTask.getName() + "\"...","TaskManager");
                currentTask.execute();
                logMessage("Task \"" + currentTask.getName() + "\" has ended.","TaskManager");
            }
            currentTask = null;
            return 20;
        } else {
            return 10;
        }
    }

    /**
     * Ensures the Mapper is stopped and the ContentFrame is destroyed. Also
     * cleans up as much objects related to PowerWalk as possible.
     */
    @Override public void onStop() {
        logMessage("stopping PowerWalk...");
        Bot.getBot().becomeIdle();
        Mapper.stopMapping();
        ContentFrame.theFrame.dispose();
        ContentFrame.theFrame = null;
        purge(); // free all data structures and objects they contain
        System.gc(); // running Garbage Collector to ensure any potentially problematic objects (Readers/Writers, Task instances, etc..) are finalized and destroyed
        logMessage("PowerWalk has been terminated");
    }

    /**
     * returns the currently running task.
     *
     * @return the currently running task, or null is no task is running
     */
    public static Task currentTask() {
        return currentTask;
    }

    /**
     * removes non-essential data structures and reduces the size of essential
     * data structures in order to free memory or speed up general performance.
     *
     * <p>Since most non-essential data structures are used for caching, calling
     * this method repeatedly will cause reduction of performance.</p>
     *
     * <p>Furthermore, after calling this method, some smaller data structures
     * will be automatically rebuilt when performing actions on the Bot, and
     * these action may be slower due to missing / reduced caches.</p>
     */
    public synchronized static void purge() {
        // purge the destination list used by the travelTo(String dest) command
        Destinations.purge();

        // purge the World Map (takes potentially long)
        Bot.getBot().getWorldMap().purge();

        logMessage("The caches have been purged");
    }

    /**
     * Logs a message to the console. The message will be prefixed by "[PowerWalk] "
     * <p>The logged message will have a logging level identical to <code>Level.INFO</code></p>
     * @param message the message to log
     */
    public static void logMessage(String message) {
        theLogger.info(message);
    }

    /**
     * Logs the String value of the given object to the console.
     * <p>This method is equivalent to calling <code>Starter.logMessage(String.valueOf(object))</code>
     * @param object the object to log.
     */
    public static void logMessage(Object object) {
        theLogger.info(String.valueOf(object));
    }
    
    /**
     * Logs the given message to the console. The message will be prefixed by "[PowerWalk] ".
     * <p>Group specifies the name that must be displayed along with the message</p>
     * @param message the message to log
     * @param group the group to display for this message
     */
    public static void logMessage(String message,String group) {
        theLogger.log(Level.INFO,message,group);
    }
}
