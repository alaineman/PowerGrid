package powergrid.control;

import java.util.PriorityQueue;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import powergrid.PowerGrid;
import powergrid.tasks.Task;

/**
 * Task Manager class for the entire plug-in.
 * <p/>
 * This method deals continously polling and executing Tasks from its Task Queue. 
 * This is also the ActiveScript class that runs in RSBot.
 * <p/>
 * The TaskManager uses RSBot to run.
 * @author Chronio
 * @author Alaineman
 */
@Manifest(
        authors        = { "Alaineman" , "Chronio" },
        name           = "PowerGrid TaskManager",
        description    = "TaskManager for PowerGrid. It runs the Tasks it receives.",
        version        = PowerGrid.VERSION,
        singleinstance = true)
public class TaskManager extends ActiveScript {
    
    private static TaskManager tm = new TaskManager();
    /**
     * Returns the TaskManager instance.
     * @return the TaskManager instance
     */
    public static TaskManager getTM() {
        if (tm == null) {
            tm = new TaskManager();
        }
        return tm;
    }
    
    private PriorityQueue<Task> pendingTasks = new PriorityQueue<>();
    private Task currentTask = null;
    
    private TaskManager() {}
    
    /**
     * Assigns a Task to the TaskManager.
     * @param t the Task to assign
     * @return true if the Task was not already in the TaskQueue, and has been assigned, false otherwise.
     */
    public boolean assignTask(Task t) {
        if (pendingTasks.contains(t))
            return false;
        return pendingTasks.offer(t);
    }
    
    /**
     * Assigns a Task to the TaskManager with the speicified priority.
     * <p/>
     * The Task's own priority is overwritten by the given priority.
     * @param t the Task to assign
     * @param priority the priority of this Task.
     * @return true if the Task was not already in the TaskQueue, and has been assigned, false otherwise.
     */
    public boolean assignTask(Task t, int priority) {
        t.setPriority(priority);
        return assignTask(t);
    }
    
    /**
     * Logs a message to the console stating the TaskManager has started.
     */
    @Override public void onStart() {
        PowerGrid.logMessage("TaskManager started");
    }
    
    /**
     * executes a Task from the TaskQueue.
     *
     * @return an integer specifying the amount of milliseconds the caller
     * should wait before calling this method again.
     */
    @Override public int loop() {
        if (tasksPending() > 0) {
            currentTask = retrieveTask();
            PowerGrid.logMessage("Beginning " + currentTask.getClass().getSimpleName() + " \"" + currentTask.getName() + "\"...");
            currentTask.execute();
            PowerGrid.logMessage(currentTask.getClass().getSimpleName() + " \"" + currentTask.getName() + "\" has ended.");
            currentTask = null;
            return 20;
        } else {
            return 10;
        }
    }

    /**
     * Logs a message to the console stating the TaskManager has stopped.
     */
    @Override public void onStop() {
        PowerGrid.logMessage("TaskManager stopped");
    }

    /**
     * returns the currently running task.
     *
     * @return the currently running task, or null is no task is running
     */
    public Task currentTask() {
        return currentTask;
    }
    
    /**
     * Removes and returns the next Task from the TaskManager.
     * <p/>
     * When this method is called, the Task will no longer be executed in the 
     * TaskManager.
     * <p/>
     * @return the next Task in the TaskManager
     */
    public Task retrieveTask() {
        return pendingTasks.poll();
    }
    
    /**
     * Returns, but does not remove, the first Task in the TaskManager.
     * @return the next Task in the TaskManager
     */
    public Task checkNextTask() {
        return pendingTasks.peek();
    }
    
    /**
     * Returns the amount of Tasks in the TaskManager awaiting execution.
     * <p/>
     * This does not include any currently running Task.
     * <p/>
     * @return the amount of Tasks in the TaskManager awaiting execution
     */
    public int tasksPending() {
        return pendingTasks.size();
    }
    
    /**
     * clears the TaskManager's queue and cancels the currently running task, 
     * if any.
     */
    public void clear() {
        pendingTasks.clear();
        if (currentTask != null)
            currentTask.cancel();
    }
    
}
