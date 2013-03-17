package powergrid.control.listener;

import powergrid.tasks.Task;

/**
 * Listener for the TaskManager class for when the status of the Task queue 
 * changes.
 * <p/>
 * The methods this interface specifies are called just before the actual event 
 * happens.
 * <p/>
 * @see powergrid.control.TaskManager
 * @author Chronio
 */
public interface TaskListener {
    /**
     * Called whenever a Task is added to the Task queue.
     * @param t the Task that was added
     */
    public void taskAdded(Task t);
    /**
     * Called when a Task is removed from the Task queue.
     * <p/>
     * This method is only called when a Task is removed from the Task queue 
     * without being executed. 
     * <p/>
     * @param t the Task that was removed
     */
    public void taskRemoved(Task t);
    /**
     * Called whenever the TaskManager starts a new Task.
     * @param t the Task that was started
     */
    public void taskStarted(Task t);
    /**
     * Called whenever the TaskManager finishes a Task
     * @param t the Task that finished execution
     */
    public void taskFinished(Task t);
}
