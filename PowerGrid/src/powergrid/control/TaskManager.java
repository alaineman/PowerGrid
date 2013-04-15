package powergrid.control;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import powergrid.PowerGrid;
import static powergrid.PowerGrid.LOGGER;
import powergrid.control.listener.TaskListener;
import powergrid.task.Task;

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
    
    private PriorityQueue<Task> pendingTasks = new PriorityQueue<>();
    private Task currentTask = null;
    private HashSet<TaskListener> listeners = new HashSet<>(5);
    
    /**
     * Assigns a Task to the TaskManager.
     * @param t the Task to assign
     * @return true if the Task was not already in the TaskQueue, and has been assigned, false otherwise.
     */
    public boolean assignTask(Task t) {
        if (pendingTasks.contains(t))
            return false;
        for (TaskListener l : listeners) {
            l.taskAdded(t);
        }
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
     * Removes the given Task from the Task Queue.
     * @param t the Task to remove
     * @return true if the Task was in the queue, false otherwise
     */
    public boolean removeTask(Task t) {
        if (pendingTasks.contains(t)) {
            for (TaskListener l : listeners) {
                l.taskRemoved(t);
            }
            return pendingTasks.remove(t);
        }
        return false;
    }
    
    /**
     * executes a Task from the TaskQueue.
     *
     * @return an integer specifying the amount of milliseconds the caller
     * should wait before calling this method again.
     */
    @Override public int loop() {
        if (tasksPending() > 0) {
            currentTask = pendingTasks.poll();
            LOGGER.info("Beginning " + currentTask.getClass().getSimpleName() + " \"" + currentTask.getName() + "\"...");
            for (TaskListener l : listeners) {
                l.taskStarted(currentTask);
            }
            currentTask.execute();
            LOGGER.info(currentTask.getClass().getSimpleName() + " \"" + currentTask.getName() + "\" has ended.");
            
            for (TaskListener l : listeners) {
                l.taskFinished(currentTask);
            }
            currentTask = null;
            return 20;
        } else {
            return 10;
        }
    }

    /**
     * clears all Tasks from the Task queue.
     */
    @Override public void onStop() {
        clear();
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
        for (TaskListener l : listeners) {
            l.taskRemoved(currentTask);
        }
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
     * Returns a List of all pending Tasks.
     * @return a List of all pending Tasks
     */
    public List<Task> getPendingTasks() {
        ArrayList<Task> tasks = new ArrayList<>(pendingTasks.size());
        for (Task t : pendingTasks) {
            tasks.add(t);
        }
        Collections.sort(tasks);
        return tasks;
    }
    
    /**
     * clears the TaskManager's queue and cancels the currently running task, 
     * if any.
     */
    public void clear() {
        while (!pendingTasks.isEmpty()) {
            removeTask(pendingTasks.peek());
        }
        if (currentTask != null)
            currentTask.cancel();
    }
    
    /**
     * Adds a TaskListener to the set of listeners
     * @param l the TaskListener to add
     */
    public void addTaskListener(TaskListener l) {
        if (!listeners.contains(l))
            listeners.add(l);
    }
    
    /**
     * Removes a TaskListener from the set of listeners
     * @param l the TaskListener to remove
     */
    public void removeTaskListener(TaskListener l) {
        listeners.remove(l);
    }
    
    /**
     * Moves a Task up in the queue.
     * <p/>
     * When this method returns normally, and the provided Task was not the 
     * first Task in the queue, it is guaranteed that the Task's position in 
     * the queue is now above the Task which was first above the specified Task.
     * <p/>
     * @param t the Task to move
     * @return the new priority of the Task
     * @throws IllegalArgumentException when <code>t == null</code> or t is not 
     *                                  in the task queue.
     */
    public int moveTaskUp(Task t) {
        if (t == null) {
            throw new IllegalArgumentException("Null value");
        }
        Task[] tasks = pendingTasks.toArray(new Task[pendingTasks.size()]);
        Arrays.sort(tasks);
        int index = Arrays.binarySearch(tasks, t);
        if (index < 0) {
            throw new IllegalArgumentException("Task not in Queue");
        }
        if (index != 0) {
            Task higherTask = tasks[index - 1];
            removeTask(t);
            t.setPriority(higherTask.getPriority() + 1);
            assignTask(t);
        }
        return t.getPriority();
    }
    
    /**
     * Moves a Task down in the queue.
     * <p/>
     * When this method returns normally, and the provided Task was not the 
     * last Task in the queue, it is guaranteed that the Task's position in 
     * the queue is now below the Task which was first below the specified Task.
     * <p/>
     * @param t the Task to move
     * @return the new priority of the Task
     * @throws IllegalArgumentException when <code>t == null</code> or t is not 
     *                                  in the task queue.
     */
    public int moveTaskDown(Task t) {
        if (t == null) {
            throw new IllegalArgumentException("Null value");
        }
        Task[] tasks = pendingTasks.toArray(new Task[pendingTasks.size()]);
        Arrays.sort(tasks);
        int index = Arrays.binarySearch(tasks, t);
        if (index < 0) {
            throw new IllegalArgumentException("Task not in Queue");
        }
        if (index != tasks.length - 1) {
            Task lowerTask = tasks[index + 1];
            removeTask(t);
            t.setPriority(lowerTask.getPriority() - 1);
            assignTask(t);
        }
        return t.getPriority();
    }
}
