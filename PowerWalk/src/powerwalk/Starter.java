package powerwalk;

import org.powerbot.core.script.ActiveScript;
import powerwalk.model.Destinations;

/**
 * Starter class for the entire plug-in 
 * @author P.Kramer
 */
public class Starter extends ActiveScript {

    private static Task currentTask = null;
    
    @Override public int loop() {
        if (Bot.getBot().tasksPending() > 0) {
            currentTask = Bot.getBot().retrieveTask();
            currentTask.execute();
            return 20;
        } else {
            return 5;
        }
    }
    
    /**
     * returns the currently running task.
     * @return the currently running task
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
        //TODO (--) reduce World Map
    }
    
}
