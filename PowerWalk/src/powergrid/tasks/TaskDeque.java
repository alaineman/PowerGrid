package powergrid.tasks;

import java.util.ArrayDeque;
import java.util.Collection;
import powergrid.control.TaskManager;

/**
 * This class executes multiple Tasks in sequence.
 * <p/>
 * Tasks can be added to both the begin and the end, so this class can be used 
 * as both a Stack and a Queue.
 * <p/>
 * It is possible to execute any number of Tasks in the Deque at once using the 
 * executeXXX methods. These methods will return after the Task has finished.
 * <p/>
 * Tasks can be moved to the central PowerWalk Task Queue using the moveXXXtoQueue methods.
 * <p/>
 * @author Chronio
 */
public class TaskDeque {
    
    private ArrayDeque<Task> theTasks = new ArrayDeque<>(2);
    
    /**
     * Creates an empty TaskDeque.
     */
    public TaskDeque() {}
    
    /**
     * Creates a TaskDeque filled with the given tasks.
     * @param tasks the Tasks to add to this TaskDeque
     */
    public TaskDeque(Collection<? extends Task> tasks) {
        theTasks.addAll(tasks);
    }
    
    /**
     * Adds a Task to the end of this Deque.
     * <p/>
     * Using this method to add Tasks makes the Deque behave like a Queue
     * @param t the Task to add
     */
    public void append(Task t) {
        theTasks.addLast(t);
    }
    
    /**
     * Adds a task to the beginning of this Deque.
     * <p/>
     * Using this method to add Tasks makes the Deque behave like a Stack
     * @param t the Task to add
     */
    public synchronized void prepend(Task t) {
        theTasks.addFirst(t);
    }
    
    /**
     * Returns the amount of Tasks in the Deque.
     * @return the amount of Tasks in the Deque.
     */
    public int size() {
        return theTasks.size();
    }
    
    /**
     * Returns the first Task in the Deque.
     * @return the first Task in the Deque.
     */
    public Task getFirst() {
        return theTasks.getFirst();
    }
    
    /**
     * Returns the last Task in the Deque.
     * @return the last Task in the Deque.
     */
    public Task getLast() {
        return theTasks.getLast();
    }
    
    /**
     * Removes the first Task from the Deque and executes it. 
     */
    public synchronized void executeOne() {
        Task t = theTasks.pollFirst();
        if (t != null)
            new TaskRunner(t).run();
    }
    
    /**
     * Removes the first n Tasks from the Deque and executes them in order.
     * <p/>
     * if <code>n &lt; 0</code>, no tasks will be executed. If <code>n &gt; size()</code>
     * @param n the number of tasks to execute
     */
    public synchronized void executeN(int n) {
        n = Math.min(Math.max(0, n),theTasks.size());
        for (;n>0;n--) {
            executeOne();
        }
    }
    
    /**
     * Removes and executes all Tasks from the Deque.
     * <p/>
     * This method is effectively the same as calling <code>executeN(Integer.MAX_VALUE);</code>
     */
    public synchronized void executeAll() {
        executeN(Integer.MAX_VALUE);
    }
    
    /**
     * removes the first Task from this Deque and adds it to the PowerWalk 
     * Task Queue.
     */
    public synchronized void moveFirstToQueue() {
        if (theTasks.isEmpty()) return;
        Task t = theTasks.pollFirst();
        TaskManager.getTM().assignTask(t);
    }
    
    /**
     * Removes all Tasks from this Deque and add them all to the PowerWalk Task
     * Queue.
     */
    public synchronized void moveAllToQueue() {
        while (!theTasks.isEmpty()) {
            moveFirstToQueue();
        }
    }
}
