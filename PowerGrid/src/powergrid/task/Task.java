package powergrid.task;

import java.util.Objects;

/**
 * Task Class that is used to queue tasks for the Bot to execute.
 * <p />
 * Every Task has a priority and a name. The priority is used by the Bot class to 
 * sort the Tasks by priority, and execute the Task with the highest priority 
 * first. The default priority is 0. After the Task is created, the priority 
 * cannot be changed anymore.
 * <p />
 * The name is used in log messages and can also be used for identification. If 
 * an invalid name is set (either <code>null</code> or an empty String), the old 
 * name is kept. When no valid name has been set, the name of the Task is 
 * "Generic Task".
 * 
 * @author Chronio
 */
public abstract class Task implements Comparable<Task> {
    
    public static final int URGENT = 900;
    public static final int HIGHEST = 800;
    public static final int HIGHER = 700;
    public static final int HIGH = 600;
    public static final int MEDIUM = 500;
    public static final int LOW = 400;
    public static final int LOWER = 300;
    public static final int LOWEST = 200;
    public static final int BACKGROUND = 100;
    
    private int priority = 500;
    private String name = "Generic Task";
    
    /**
     * Creates a new Task with the specified name and priority
     * @param priority the priority of the Task
     * @param name the name of the Task
     */
    public Task(int priority, String name) {
        this.priority = priority;
        if (name != null && !name.isEmpty())
            this.name = name;
    }
    
    /**
     * Creates a new Task with the specified name. The priority of this Task is 
     * set to 0.
     * @param name the name of the Task
     */
    public Task(String name) {
        this(MEDIUM,name);
    }
    
    /**
     * Creates a new Task with the specified priority. The name of this Task will
     * be "Generic Task".
     * @param priority The priority of the Task
     */
    public Task(int priority) {
        this.priority = priority;
    }
    
    /**
     * Creates a new Task with priority set to 0 and "Generic Task" as its name.
     */
    public Task() {}
    
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
     * Sets the priority of the Task to the new value.
     * <p/>
     * Note that this does not mean that the Task is moved in the TaskManager 
     * if it was already assigned.
     * <p/>
     * @param priority the new priority of this Task
     */
    public void setPriority(int priority) {
        this.priority = priority;
    }
    
    /**
     * Returns the difference in Priority between this Task and Task t
     * @param t The Task to compare this Task to
     * @return a negative number when this Task has a lower Priority, 
     *         a positive number when this Task has a higher Priority,
     *         and zero when the Priorities are equal.
     */
    @Override public int compareTo(Task t) {
        return t.getPriority()-getPriority();
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
    
    /**
     * Sets a name for this Task. The name can be used for identification and 
     * can be found back in logs. If the given name is either null or the empty 
     * String, this method does nothing.
     * @param name the new name for this Task
     */
    public void setName(String name) {
        if (name != null && !name.isEmpty())
            this.name = name;
    }
    
    /**
     * returns the assigned name for this Task.
     * When no name has been assigned, this method returns "Generic Task".
     * @return the name of this Task
     */
    public String getName() {
        return name;
    }
    
    /**
     * Returns the description of this Task.
     * <p/>
     * Subclasses should override this method to provide a detailed description
     * about the functionality and purpose of the Task.
     * <p/>
     * The default value is "&lt;no description&gt;".
     * @return the String "&lt;no description&gt;"
     */
    public String getDescription() {
        return "<no description>";
    }
    
    /**
     * Resets this Task, allowing it to be run again.
     * <p />
     * By default, this method throws an UnsupportedOperationException. Classes 
     * that do not override this method are considered to be able to run only once.
     * <p />
     * If a subclass of Task overrides this method, and does not throw an 
     * UnsupportedOperationException, the Bot assumes the Task is reset and 
     * ready to be run again when this method returns.
     * @throws UnsupportedOperationException when this Task is not resettable
     */
    public void reset() {
        throw new UnsupportedOperationException("Reset is not supported for this Task");
    }
    
    /**
     * Returns whether this Task is equal to a given Object.
     * <p/>
     * This method returns true if all the following conditions are met.
     * <ul>
     *   <li>The given Object has the same class as this Task-object</li>
     *   <li>The given Object has the same name as this Task-object</li>
     *   <li>The given Object has the same priority as this Task-object</li>
     *   <li>The given Object has the same description as this Task-object</li>
     * </ul>
     * If any of the above conditions are false, this method returns false.
     * @param other the Object to compare to this Task
     * @return true if this Task is equal to the given Object, false otherwise.
     */
    @Override public boolean equals(Object other) {
        if (other == null) {
            return false;
        }
        if (getClass().equals(other.getClass())) {
            Task that = (Task) other;
            if (getPriority() != that.getPriority()) {
                return false;
            }
            if (!Objects.equals(getName(), that.getName())) {
                return false;
            }
            return Objects.equals(getDescription(), that.getDescription());
        }
        return false;
    }
    
    /**
     * returns the hashCode for this Object.
     * @return the hashCode for this Object.
     */
    @Override public int hashCode() {
        int hash =  7;
        hash = 2*hash + 3 * name.hashCode();
        hash = 2*hash + 5 * priority;
        return hash;
    }
    
    /**
     * This method waits a pseudo-random time between min and max milliseconds,
     * and then returns.
     * <p/>
     * This method is effectively the same as calling 
     * <code>org.powerbot.core.script.job.Task.sleep(min,max);</code>
     * <p/>
     * @param min the minimum waiting time.
     * @param max the maximum waiting time.
     */
    public static void sleep(int min, int max) {
        int wait = (int) (Math.min(min, max) + (max - min) * Math.random());
        sleep(wait);
    }
    
    /**
     * This method waits <code>time</code> milliseconds,
     * and then returns.
     * <p/>
     * This method is effectively the same as calling 
     * <code>org.powerbot.core.script.job.Task.sleep(time);</code>
     * <p/>
     * @param time the waiting time
     */
    public static void sleep(int time) {
        try {
            Thread.sleep(time);
        } catch (InterruptedException ignored) {
            throw new ThreadDeath();
        }
    }
}
