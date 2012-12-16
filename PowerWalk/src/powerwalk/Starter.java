package powerwalk;

import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import powerwalk.model.Destinations;

/**
 * Starter and Task Manager class for the entire plug-in 
 * @author P.Kramer
 * @author Alaineman
 */
@Manifest(
        authors     = "alaineman", 
        name        = Starter.productName, 
        description = "Runs all day!", 
        version     = Starter.version 
         )
public class Starter extends ActiveScript {
    
    /** The name of the Plug-in */
    public static final String productName = "PowerWalk";
    /** The version number */
    public static final double version = 0.1;
    
    private static Task currentTask = null;
    
    /**
     * executes a Task from the TaskQueue.
     * @return an integer specifying the amount of milliseconds the caller 
     *         should wait before calling this method again.
     */
    @Override public int loop() {
        if (Bot.getBot().tasksPending() > 0) {
            currentTask = Bot.getBot().retrieveTask();
            currentTask.execute();
            currentTask = null;
            return 20;
        } else {
            return 5;
        }
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
     * data structures in order to free memory. 
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
        
        // purge the World Map (takes potentially really, really long)
        Bot.getBot().getWorldMap().purge();
    }
}
