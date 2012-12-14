package powerwalk;

import java.util.PriorityQueue;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.wrappers.Tile;
import powerwalk.model.Grid;
import powerwalk.model.Point;

/**
 * Bot-class representing the Player. 
 * The Bot can execute high-level tasks such as "travel to [destination]", 
 * "go to nearest [place of interest]", and others.
 * @author Vincent W, P.Kramer
 */
public class Bot {
    private static Bot theBot = new Bot();
    
    /**
     * returns the Bot object that performs the actions in the RSBot environment
     * @return the Bot object
     */
    public static Bot getBot() {
        return theBot;
    }
    
    private Grid theWorldMap = new Grid();
    private PriorityQueue<Task> taskQueue = new PriorityQueue<>();
    
    private Bot() {}
    
    /** returns the World Map data that is known to the bot.
     * @return the World Map
     */
    public Grid getWorldMap() {
        return theWorldMap;
    }
    
    /**
     * registers a Task that moves to the destination specified in dest.
     * 
     * @param dest The target destination
     */
    public void travelTo(String dest) { //TODO (--) implement travelTo stub method 
        
    }
    
    /**
     * Registers a Task that moves to the specified Point in the World
     * @param p The Point to move to
     */
    public void travelTo(Point p) { 
        final Tile t = p.toTile();
        Task travelTask = new Task(0) {
            @Override public void execute() {
                Walking.walk(t); //XXX replace with own move algorithm when we have one
            }
        };
        taskQueue.offer(travelTask);
    }
    
    /**
     * registers a Task that moves to the nearest destination that matches the description in dest.
     * @param dest The target destination
     */
    void gotoNearest(String dest) {} //TODO (--) implement gotoNearest stub method
    
    /**
     * Queues the given Runnable in the Bot. 
     * <p>The Runnable will be executed when all tasks with a higher priority
     * are executed. When multiple tasks have the same priority, the tasks will 
     * be executed in order of assignment.</p>
     * @param task The Runnable to store in the Queue
     */
    public void assignTask(Task task) {
        taskQueue.offer(task);
    }
    
    Task retrieveTask() {
        return taskQueue.poll();
    }
    
    public int tasksPending() {
        return taskQueue.size();
    }
}
