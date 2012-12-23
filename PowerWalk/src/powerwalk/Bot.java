package powerwalk;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.interactive.Players;
import powerwalk.control.PathFinder;
import powerwalk.model.Destinations;
import powerwalk.model.GameObject;
import powerwalk.model.Grid;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Interactable;

/**
 * Bot-class representing the Player. 
 * The Bot can execute high-level tasks such as "travel to [destination]", 
 * "go to nearest [place of interest]", and others.
 * @author Vincent W
 * @author P.Kramer
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
     * @param asap whether to insert this task before other tasks in the queue
     */
    public void travelTo(String dest,boolean asap) {
        Point p = Point.fromTile(Destinations.getDestination(dest));
        travelTo(p,asap);
    }
    
    /**
     * Registers a Task that moves to the specified Point in the World
     * @param p The Point to move to
     * @param asap whether to insert this task before other tasks in the queue
     */
    public void travelTo(Point p, boolean asap) { 
        
        try { 
            final ArrayList<Point> path = PathFinder.calculatePath(Bot.getBot().getPosition(), p);
            int priority = (asap ? Integer.MAX_VALUE : 0);
            Task travelTask = new Task(priority) {
                private boolean stopNow = false;
                @Override public void execute() {
                    int targetPoint = 1;
                    int threshold = (int)(3 + 3 * Math.random());
                    while (targetPoint < path.size()) {
                        Point playerPos = getPosition();
                        if (stopNow) { // we have to stop
                            // set move to current position
                            Walking.walk(playerPos.toTile());
                            break;
                        }
                        
                        // are we there yet?
                        int dx = playerPos.x - path.get(targetPoint).x;
                        int dy = playerPos.y - path.get(targetPoint).y;
                        double dist_to_point = Math.sqrt( dx*dx + dy*dy );
                        if (dist_to_point < threshold) {
                            // yes, we are close enough
                            targetPoint++;
                            threshold = (int)(3 + 3 * Math.random());
                            Walking.walk(path.get(targetPoint).toTile());
                            GameObject g = getWorldMap().get(path.get(targetPoint));
                            if (g instanceof Interactable) {
                                try {
                                    ((Interactable)g).interact(); // default action
                                } catch (OutOfReachException ex) {
                                    Logger.getLogger("Bot").log(Level.SEVERE, "Could not reach interactable", ex);
                                }
                            }
                        }
                    }
                }
                @Override public void cancel() {
                    stopNow = true;
                }
            };
            travelTask.setName("Travel to " + p);
            taskQueue.offer(travelTask); 
        } catch (OutOfReachException e) {
            Logger.getLogger("Bot").log(Level.WARNING, "The path could not be computed", e);
        }
        
    }
    
    /**
     * returns the Player's current Position
     * @return the Player's current Position
     */
    public Point getPosition() {
        return Point.fromTile(Players.getLocal().getLocation());
    }
    
    /**
     * registers a Task that moves to the nearest destination that matches the description in dest.
     * @param dest The target destination
     */
    void gotoNearest(String dest) {
        throw new UnsupportedOperationException("not yet supported");
    } //TODO (--) implement gotoNearest stub method
    
    /**
     * Queues the given Runnable in the Bot. 
     * <p>The Runnable will be executed when all tasks with a higher priority
     * are executed. When multiple tasks have the same priority, the tasks will 
     * be executed in order of assignment.</p>
     * @param task The Runnable to store in the Queue
     */
    public void assignTask(Task task) {
        taskQueue.offer(task);
        System.out.println("[PowerWalk] Task \"" + task.getName() + "\" assigned with priority " + task.getPriority());
    }
    
    /**
     * Polls the first task in the task Queue
     * @return the Task to be executed next
     */
    Task retrieveTask() {
        return taskQueue.poll();
    }
    
    /**
     * Returns the amount of pending tasks
     * @return the amount of pending tasks
     */
    public int tasksPending() {
        return taskQueue.size();
    }
    
    /**
     * clears the task queue and attempts to cancel the running task, if any.
     * <p>When this method returns, the current task doesn't need to have be 
     * stopped directly.</p>
     * <p>Note that Tasks that do not override the cancel() method cannot be 
     * canceled. Most Tasks created by PowerWalk are cancelable</p>
     * 
     * 
     */
    public void becomeIdle() {
        taskQueue.clear();
        Task current = Starter.currentTask();
        if (current != null) current.cancel();
    }
}
