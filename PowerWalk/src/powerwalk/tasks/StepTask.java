package powerwalk.tasks;

/**
 * Represents a Task that can be split in a number of similar tasks.
 * 
 * <p>When a Task is a StepTask instance, the Task is composed of three parts:
 * <ol>
 *   <li>The beginning</li>
 *   <li>The main loop</li>
 *   <li>The end</li>
 * </ol>
 * </p>
 * 
 * <p>The Task is initialized by calling the start method. 
 * Then the step method is called continously. 
 * Executing a StepTask reduces the step counter of the Task. 
 * When there are no more steps to execute, the finish method is called. 
 * After the finish method has been called, the entire task has been executed.
 * </p>
 * 
 * @author Chronio
 */
public abstract class StepTask extends Task {
    
    private int numSteps = -1;
    
    /**
     * Creates a new StepTask with the specified priority, set to loop indefinitely
     * @param priority the priority of the Task
     */
    public StepTask(int priority) {
        super(priority);
    }
    
    /**
     * Creates a new StepTask with the specified priority, set to run for <code>numSteps</code> steps.
     * <p>When <code>numSteps &lt; 0</code>, this Task loops indefinitely.</p>
     * @param priority the priority of the Task
     * @param numSteps the amount of times the Task needs to be stepped 
     */
    public StepTask(int priority, int numSteps) {
        super(priority);
        this.numSteps = numSteps;
    }
    
    /**
     * The main method of the Task. 
     * <p>This method should not be overridden. Instead, the step method 
     * should be overridden</p>
     * @throws IllegalStateException when this Task has already finished running
     */
    @Override public synchronized void execute() {
        if (numSteps != 0) {
            if (numSteps > 0) numSteps--;
            step();
        } else throw new IllegalStateException("StepTask has already finished");
    }
    
    /**
     * returns the number of times this Task still has to execute, or Integer.MAX_VALUE when this Task is set to loop.
     * @return the number of times this Task still has to execute
     */
    public int stepsLeft() {
        return (numSteps<0 ? Integer.MAX_VALUE : numSteps);
    }
    
    /**
     * returns whether this Task will step at least one more time.
     * @return true if and only if this Task has to be executed at least one 
     *         more time, false otherwise.
     */
    public boolean hasMoreSteps() {
        return numSteps != 0;
    }
    
    /**
     * returns whether this Task is set to loop
     * @return true if and only if this Task is set to loop, false otherwise.
     */
    public boolean isOnLoop() {
        return numSteps < 0;
    }
    
    /**
     * sets the number of steps left for this Task. If 
     * <code>stepsLeft &lt; 0</code>, this Task is set to loop indefinitely.
     * @param stepsLeft the new number of steps left
     */
    protected void setStepsLeft(int stepsLeft) {
        numSteps = stepsLeft;
    }
    
    /**
     * Sets this Task to loop indefinitely.
     */
    protected void setOnLoop() {
        numSteps = -1;
    }
    
    /**
     * This method is called before the first step of this StepTask. Subclasses 
     * can override this method to 
     */
    public synchronized void start() {}
    
    /**
     * This method contains the code that will be executed each step until this StepTask is done.
     */
    public abstract void step();
    
    /**
     * This method is called after the last step of this Task has been executed.
     */
    public synchronized void finish() {}
    
    /**
     * Cancel this StepTask.
     * <p>After calling this method, no more steps will be executed. This method
     * is equivalent to calling <code>setStepsLeft(0)</code>.</p>
     */
    @Override public void cancel() {
        numSteps = 0;
    }
    
    
}
