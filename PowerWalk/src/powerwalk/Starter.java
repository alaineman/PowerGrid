package powerwalk;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.ConsoleHandler;
import java.util.logging.Formatter;
import java.util.logging.LogRecord;
import java.util.logging.Logger;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import org.powerbot.game.api.methods.Environment;
import powerwalk.control.Mapper;
import powerwalk.control.ToolBox;
import powerwalk.model.Destinations;
import powerwalk.model.XMLNode;
import powerwalk.view.ContentFrame;

/**
 * Starter and Task Manager class for the entire plug-in 
 * @author Chronio
 * @author Alaineman
 */
@Manifest(
        authors     = "alaineman", 
        name        = Starter.productName, 
        description = "Runs all day!", 
        version     = Starter.version 
         )
public class Starter extends ActiveScript {
    
    private static final Logger theLogger = Logger.getLogger(Starter.class.getName());
    
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
                return "[PowerWalk] " + record.getMessage() + "\n";
            }
        });
        theLogger.addHandler(handler);
        logMessage("Starting...");
        logMessage("Storage directory set as " + Environment.getStorageDirectory().toString());
        logMessage("loading WorldMap from File: \"" + worldMapFile + "\"...");
        try (FileInputStream worldMapIn = new FileInputStream(Environment.getStorageDirectory().toString() + "\\" + worldMapFile)) {
            XMLNode worldMap = ToolBox.getXMLTree(worldMapIn);
            Bot.getBot().getWorldMap().fillFromXML(worldMap);
            logMessage("WorldMap loaded");
        } catch (IOException e) {
            if (e instanceof FileNotFoundException) {
                logMessage("WorldMap file does not exist; starting with empty WorldMap");
            } else {
                logMessage("WorldMap failed to load");
            }
        }
        Mapper.startMapping(Mapper.MAP_CONTINOUSLY);
        
        ContentFrame.theFrame = new ContentFrame();
        logMessage("PowerWalk started, waiting for tasks...");
    }
    
    /**
     * executes a Task from the TaskQueue.
     * @return an integer specifying the amount of milliseconds the caller 
     *         should wait before calling this method again.
     */
    @Override public int loop() {
        if (Bot.getBot().tasksPending() > 0) {
            currentTask = Bot.getBot().retrieveTask();
            if (currentTask instanceof StepTask) {
                StepTask task = (StepTask)currentTask;
                logMessage("Beginning StepTask \"" + task.getName() + "\"...");
                task.start();
                while (task.hasMoreSteps()) {
                    task.execute();
                }
                task.finish();
                logMessage("StepTask \"" + task.getName() + "\" has ended");
            } else {
                logMessage("Beginning Task \"" + currentTask.getName() + "\"...");
                currentTask.execute();
                logMessage("Task \"" + currentTask.getName() + "\" has ended.");
            }
            currentTask = null;
            return 20;
        } else {
            return 10;
        }
    }
    
    /**
     * Ensures the Mapper is stopped and the ContentFrame is destroyed.
     * Also cleans up as much objects related to PowerWalk as possible.
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
    
    public static void logMessage(String message) {
        theLogger.info(message);
    }
}
