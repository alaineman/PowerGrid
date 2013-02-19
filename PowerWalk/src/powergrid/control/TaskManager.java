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
        singleinstance = false)
public class TaskManager extends ActiveScript {
    
    private static TaskManager tm = new TaskManager();
    public static TaskManager getTM() {
        return tm;
    }
    
    private PriorityQueue<Task> pendingTasks = new PriorityQueue<>();
    private Task currentTask = null;
    
    private TaskManager() {
        tm = this;
    }
    
    public boolean assignTask(Task t) {
        if (pendingTasks.contains(t))
            return false;
        return pendingTasks.offer(t);
    }
    
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
    
    public Task retrieveTask() {
        return pendingTasks.poll();
    }
    
    public Task checkNextTask() {
        return pendingTasks.peek();
    }
    
    public int tasksPending() {
        return pendingTasks.size();
    }
    
    public void emptyQueue() {
        pendingTasks.clear();
        if (currentTask != null)
            currentTask.cancel();
    }
    
}
