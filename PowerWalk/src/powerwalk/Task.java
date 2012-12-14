package powerwalk;

/**
 * Task Class that is used to queue tasks for the Bot to execute
 * @author P.Kramer
 */
public abstract class Task implements Comparable<Task> {
    private int priority = 0;
    
    /**
     * Creates a new Task with the specified priority.
     * @param priority The priority of the Task
     */
    public Task(int priority) {
        this.priority = priority;
    }
    
    /**
     * The method that is run by the Bot when this task is scheduled.
     * <p>Classes that override this method must make sure that this method does not 
     * throw any Exceptions, for they will not be caught.</p>
     */
    public abstract void execute();
    
    /**
     * Returns the priority of this Task
     * @return the priority of this Task
     */
    public int getPriority() {
        return priority;
    }
    
    /**
     * Returns the difference in Priority between this Task and Task t
     * @param t The Task to compare this Task to
     * @return a negative number when this Task has a lower Priority, 
     *         a positive number when this Task has a higher Priority,
     *         and zero when the Priorities are equal.
     */
    @Override public int compareTo(Task t) {
        return priority-t.getPriority();
    }
    
    /**
     * Cancels this Task as quickly as possible.
     * 
     * <p>By default this method does nothing. Subclasses of this class should 
     * override this method when the action is taking quite some time to 
     * complete.</p>
     * 
     * <p>This method should return without throwing exceptions and calling 
     * cancel on a running task should not cause exceptions to occur in the 
     * execute method.</p>
     */
    public void cancel() {}
}
