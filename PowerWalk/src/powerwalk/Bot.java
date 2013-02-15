package powerwalk;

import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import org.powerbot.game.api.methods.interactive.Players;
import powerwalk.control.XMLToolBox;
import powerwalk.model.Destination;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.model.XMLNode;
import powerwalk.tasks.RestTask;
import powerwalk.tasks.Task;
import powerwalk.tasks.TravelTask;

/**
 * Bot-class representing the Player.
 * The Bot can execute high-level tasks such as "travel to [destination]",
 * "go to nearest [place of interest]", and others. It makes use of the Task 
 * subclasses in the <code>powerwalk.tasks</code> package to achieve these tasks.
 * <p />
 * The Bot also provides top-level access to PowerWalk's functionality, and can 
 * be used either issue commands, or retrieve information about the Player's 
 * current state.
 * <p />
 * @author Alaineman
 * @author Chronio
 */
public class Bot {
    
    // The Bot's States
    /** This State represents any state that is not recognized by PowerWalk. */
    public static final int STATE_UNKNOWN = 0;
    /** This State represents the state of the Bot when there are no Tasks. */
    public static final int STATE_IDLE = 1;
    /** This State represents the state of the Bot while resting. */
    public static final int STATE_RESTING = 2;
    /** This State represents the state of the Bot while walking or running. */
    public static final int STATE_WALKING = 3;
    
    private static Bot theBot = new Bot();
    
    /**
     * returns the Bot object that represents the Player in the RSBot environment.
     * @return the Bot object
     */
    public static Bot getBot() {
        return theBot;
    }
    
    private Grid theWorldMap = new Grid();
    private PriorityQueue<Task> taskQueue = new PriorityQueue<>();
    private Task idleTask = new RestTask(Integer.MIN_VALUE,true);
    
    private Bot() {}
    
    /**
     * returns the World Map data that is known to the bot.
     *
     * @return the World Map
     */
    public Grid getWorldMap() {
        return theWorldMap;
    }
    
    /**
     * Registers a Task that moves to the destination specified in name.
     * <p/>
     * @param name The target destination (providing correct casing is faster, but not required)
     * @param priority The priority of this Task
     */
    public void travelTo(String name,int priority) {
        if (name == null || name.isEmpty()) // null values or empty Strings are invalid
            throw new IllegalArgumentException("Invalid Name");
        Destination dest = Destination.getDestination(name); // attempt to fetch Destination
        if (dest == null) { // there is no destination with that exact name, searching for case-insensitive match
            for (Destination d : Destination.getDestinations()) {
                if (name.equalsIgnoreCase(d.getName())) {
                    dest = d;
                    break;
                }
            }
        }
        if (dest == null) // the destination could not be matched
            throw new IllegalArgumentException("No such Destination:" + name);
        
        // travel to the matched destination
        assignTask(new TravelTask(dest,priority));
    }
    
    /**
     * Registers a Task that moves to the specified Point in the World
     * <p/>
     * @param p        The Point to move to
     * @param priority The priority of this Task
     */
    public void travelTo(Point p, int priority) {
        assignTask(new TravelTask(p,priority));
    }
    
    /**
     * Registers a RestTask instance that rests until the player's energy is at 
     * 100% again.
     * @param priority the priority of this Task
     * @param abortOnTask whether this Task should be aborted when other Tasks are present.
     */
    public void rest(int priority, boolean abortOnTask) {
        assignTask(new RestTask(priority,abortOnTask));
    }
    
    /**
     * Returns an integer specifying the current state of the Bot.
     * <p />
     * This integer represents one of the following states:
     * <ul>
     *   <li>Idle (represented by <code>Bot.STATE_IDLE</code></li>
     *   <li>Walking (represented by <code>Bot.STATE_WALKING</code></li>
     *   <li>Resting (represented by <code>Bot.STATE_RESTING</code></li>
     *   <li>Unknown (represented by <code>Bot.STATE_UNKNOWN</code></li>
     * </ul>
     * More states might be added in future releases.
     * @return an integer specifying the current state of the Bot.
     */
    public int getState() {
        if (Players.getLocal().isMoving()) return STATE_WALKING;
        int anim = Players.getLocal().getAnimation();
        if (anim == 12108 || anim == 2033 || anim == 2716 || anim == 11786 || anim == 5713) return STATE_RESTING;
        if (tasksPending() == 0) return STATE_IDLE;
        return STATE_UNKNOWN;
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
     * <p/>
     * @param dest     The target destination
     * @param priority the priority of this Task
     * @throws NoSuchElementException   when no destinations for this destination type are registered
     * @throws IllegalArgumentException when the provided destination type is invalid
     */
    public void gotoNearest(String dest, int priority) {
        XMLNode tree = XMLToolBox.getXMLTree(ClassLoader.getSystemResourceAsStream("powerwalk/data/specialLocations.xml"));
        XMLNode[] nodes = XMLToolBox.filterNodes(tree, "name", dest);
        if (nodes.length > 0) {
            ArrayList<XMLNode> entries = nodes[0].children();
            Point pos = getPosition();
            Point nearest = new Point(Integer.MAX_VALUE,Integer.MAX_VALUE);
            for (XMLNode n : entries) {
                Point p = Point.fromString(n.get("pos"));
                if (p != null) {
                    if (pos.distance(p) < pos.distance(nearest)) nearest = p; 
                }
            }
            if (nearest.x == Integer.MAX_VALUE) {
                throw new NoSuchElementException("There are no valid Points for this destination");
            }
            Starter.logMessage("Nearest " + dest + " found at position " + nearest);
            travelTo(nearest, priority);
        } else {
            throw new IllegalArgumentException("No such location found");
        }
    }
    
    /**
     * Queues the given Runnable in the Bot. 
     * <p/>
     * The Runnable will be executed when all tasks with a higher priority
     * have been executed. When multiple tasks have the same priority, the tasks will 
     * be executed in order of assignment.
     * <p/>
     * @param task The Runnable to store in the Queue
     */
    public void assignTask(Task task) {
        taskQueue.offer(task);
        Starter.logMessage(task.getClass().getSimpleName() + " \"" + task.getName() + "\" assigned with priority " + task.getPriority());
    }
    
    /**
     * Polls the first task in the task Queue.
     * <p/>
     * Note that calling this method permanently removes this Task from the
     * TaskQueue. When this is not intended, use <code>getNextTask()</code> 
     * instead.
     * <p/>
     * @return the Task to be executed next
     */
    public Task retrieveTask() {
        return taskQueue.poll();
    }
    
    /**
     * Returns the Task that is currently being run by PowerWalk.
     * <p />
     * It is advised not to call any methods on this Task, unless calling that 
     * method will not change the state of the Task. This is because changing 
     * certain parameters of a Task while it's being run can interfere with the 
     * actual running of the Task. Please refer to the JavaDoc of Task and its 
     * subclasses for more information on which methods are safe to run and 
     * which are not.
     * <p />
     * @see Task 
     * @return the current Task
     */
    public Task getCurrentTask() {
        return Starter.currentTask();
    }
    
    /**
     * Returns the next Task on the Task Queue without removing it. 
     * <p />
     * Note that it is advised not to call any methods on this Task that will cause 
     * the Task to run, since it might interfere with the PowerWalk's Task manager.
     * <p />
     * When trying to take the Task from the Queue and run it separate from 
     * PowerWalk, it is advised to use the <code>retrieveTask()</code> method, 
     * since this method will also remove the Task from the Queue.
     * <p />
     * @return the next Task on the task Queue.
     */
    public Task getNextTask() {
        return taskQueue.peek();
    }
    
    /**
     * Sets a Task that is executed repeatedly as long as there are no other Tasks.
     * <p />
     * The Task will not automatically canceled when a new Task is added to the TaskQueue,
     * so this Task should check if there are any tasks and cancel itself, or run
     * for only a short time, allowing the Task to end gracefully and start the
     * Task in the TaskQueue.
     * <p/>
     * @param task the Task to run when there are no other Tasks.
     */
    public void setIdleTask(Task task) {
        idleTask = task;
    }
    
    /**
     * Clears any set idle Task, causing the Bot to stay idle when it has no running Tasks.
     */
    public void clearIdleTask() {
        idleTask = null;
    }
    
    /**
     * Returns the Task that is used when the Bot is idle.
     * @return the Task that is used when the Bot is idle.
     */
    public Task getIdleTask() {
        return idleTask;
    }
    
    /**
     * Returns the amount of pending tasks
     * @return the amount of pending tasks
     */
    public int tasksPending() {
        return taskQueue.size();
    }
    
    /**
     * Clears the task queue and attempts to cancel the running task, if any.
     * <p/>
     * When this method returns, the current task doesn't need to have be 
     * stopped directly.
     * <p/>
     * Note that Tasks that do not override the cancel() method cannot be 
     * canceled. All Tasks included with PowerWalk can be canceled.
     */
    public void becomeIdle() {
        taskQueue.clear();
        Task current = Starter.currentTask();
        if (current != null) current.cancel();
        Starter.logMessage("The Bot has become idle","TaskManager");
    }
}
