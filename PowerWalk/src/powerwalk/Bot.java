package powerwalk;

import java.util.ArrayList;
import java.util.PriorityQueue;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.interactive.Players;
import powerwalk.control.PathFinder;
import powerwalk.model.Destinations;
import powerwalk.model.Grid;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 * Bot-class representing the Player. 
 * The Bot can execute high-level tasks such as "travel to [destination]", 
 * "go to nearest [place of interest]", and others.
 * @author Alaineman
 * @author Chronio
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
     * @param priority The priority of this Task
     */
    public void travelTo(String dest,int priority) {
        Point p = Point.fromTile(Destinations.getDestination(dest));
        travelTo(p,priority);
    }
    
    /**
     * Registers a Task that moves to the specified Point in the World
     * @param p The Point to move to
     * @param asap The priority of this Task
     */
    public void travelTo(Point p, int priority) { 
        try {
            final ArrayList<Point> path = PathFinder.calculatePath(getPosition(), p);
            StepTask travelTask = new StepTask(priority) {
                private int target = 0;
                @Override public void start() {
                    if (path.size() > 0) {
                        Point t = path.get(target);
                        Starter.logMessage("[Task] issueing walk to " + t + " from player position " + Bot.getBot().getPosition());
                        Walking.walk(t.toTile());
                    }
                }
                @Override public void step() {
                    setStepsLeft(path.size() - target);
                    Point playerPos = getPosition();
                    // check the distance to our next point.
                    double distToTarget = Math.sqrt( 
                            Math.pow(playerPos.x-path.get(target).x,2) + 
                            Math.pow(playerPos.y-path.get(target).y,2) );
                    
                    // Are we are close enough?
                    if (distToTarget < (3 + 3 * Math.random())) {
                        // Are there more points?
                        Starter.logMessage("[Task] <debug> points left in path: " + (path.size() - target));
                        if (target + 1 < path.size()) {
                            ++target;
                            // Then we walk to the next tile.
                            Point t = path.get(target);
                            Starter.logMessage("[Task] walk to " + t + " from player position " + playerPos);
                            Walking.walk(t.toTile());
                        } else {
                            // There are no more points, so we are done.
                            cancel();
                        }
                    } else {
                        Starter.logMessage("[Task] <debug> walking to next point: " + path.get(target) + ", still " + (int)distToTarget + " tiles to go.");
                    }
                    // wait a while before checking again
                    try { Thread.sleep((long)(134 + 86 * Math.random())); }
                    catch (InterruptedException e) {}
                }
                @Override public void finish() {
                    Starter.logMessage("[Task] Destination " + path.get(path.size()-1) + " reached");
                }
            };
            travelTask.setName("Travel to " + p);
            assignTask(travelTask); 
        } catch (OutOfReachException e) {
            Starter.logMessage("WARNING: Cannot travel to " + p + ", no path found");
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
    public void gotoNearest(String dest) {
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
        Starter.logMessage(task.getClass().getSimpleName() + " \"" + task.getName() + "\" assigned with priority " + task.getPriority());
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
        Starter.logMessage("The Bot has become idle");
    }
}
