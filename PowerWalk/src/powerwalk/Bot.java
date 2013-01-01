package powerwalk;

import java.util.PriorityQueue;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.Players;
import powerwalk.model.Destinations;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.tasks.TravelTask;

/**
 * Bot-class representing the Player. 
 * The Bot can execute high-level tasks such as "travel to [destination]", 
 * "go to nearest [place of interest]", and others.
 * @author Alaineman
 * @author Chronio
 */
public class Bot {
    
    // The Bot's States
    public static final int STATE_UNKNOWN = 0;
    public static final int STATE_IDLE = 1;
    public static final int STATE_RESTING = 2;
    public static final int STATE_WALKING = 3;
    
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
    private Task idleTask = null;
    
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
     * @param priority The priority of this Task
     */
    public void travelTo(Point p, int priority) { 
        TravelTask task = new TravelTask(p,priority);
        assignTask(task);
    }
    
    public void rest(final boolean abortOnTask) {
        int priority = 0;
        if (abortOnTask) priority = Integer.MIN_VALUE;
        Task restTask = new Task(priority) {
            boolean stop = false;
            @Override public void execute() {
                for (int d = 0; d < 5; d++) {
                    Widgets.get(750, 5).interact("Rest");

                    int anim = Players.getLocal().getAnimation();
                    if (anim == 12108 || anim == 2033 || anim == 2716 || anim == 11786 || anim == 5713) {
                        while (!stop) {
                            // cancel when there are tasks waiting, or when done resting
                            if ((abortOnTask && Bot.getBot().tasksPending() > 0)
                                || Walking.getEnergy() >= 100) {
                                cancel();
                            }
                        }
                        break;
                    }
                }
            }
            @Override public void cancel() {
                stop = true;
            }
        };
        restTask.setName("Rest");
        assignTask(restTask);
    }
    
    public int getState() {
        if (tasksPending() == 0) return STATE_IDLE;
        if (Players.getLocal().isMoving()) return STATE_WALKING;
        int anim = Players.getLocal().getAnimation();
        if (anim == 12108 || anim == 2033 || anim == 2716 || anim == 11786 || anim == 5713) return STATE_RESTING;
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
     * Sets a Task that is executed repeatedly as long as there are no other Tasks.
     * <p />
     * The Task will not automatically canceled when a new Task is added to the TaskQueue, 
     * so this Task should check if there are any tasks and cancel itself, or run 
     * for only a short time, allowing the Task to end gracefully and start the 
     * Task in the TaskQueue.
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
     * Returns the Task that is used 
     * @return 
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
     * clears the task queue and attempts to cancel the running task, if any.
     * <p>When this method returns, the current task doesn't need to have be 
     * stopped directly.</p>
     * <p>Note that Tasks that do not override the cancel() method cannot be 
     * canceled. StepTasks and most Tasks created by PowerWalk are cancelable</p>
     */
    public void becomeIdle() {
        taskQueue.clear();
        Task current = Starter.currentTask();
        if (current != null) current.cancel();
        Starter.logMessage("The Bot has become idle");
    }
}
