package powergrid.task;

import powergrid.PowerGrid;
import powergrid.model.Point;

/**
 * Executes a given Task and then returns to the position you were before the 
 * Task was executed.
 * @author Chronio
 */
public class ReturnTask extends Task {

    private Task theTask = null;
    private Task runningTask = null;
    private volatile boolean stop = false;
    
    /**
     * Creates a new ReturnTask that executes the given Task and then makes its 
     * way back to the original position.
     * @param t the Task to execute
     */
    public ReturnTask(Task t) {
        theTask = t;
    }
    
    /**
     * First executes the linked Task of this ReturnTask, and then executes a 
     * TravelTask to the position of the Bot before the Task was executed.
     */
    @Override public synchronized void execute() {
        stop = false;
        // save the position for later
        Point p = PowerGrid.PG.bot().getPosition();
        // run the task that was set to run
        runningTask = theTask;
        theTask.execute();
        
        if (!stop) {
            PowerGrid.LOGGER.info("ReturnTask: Task \"" + theTask.getName() + 
                    "\" completed, returning to " + p);
            Task.sleep(200,300);
            // go back to the original position
            runningTask = new TravelTask(p);
            runningTask.execute();
            runningTask = null;
        }
    }
    
    /**
     * Cancels execution of this ReturnTask.
     * <p/>
     * When the original Task is running, this method cancels that Task and also 
     * prevents execution of the TravelTask. When the TravelTask is running, this 
     * method cancels the TravelTask.
     * <p/> 
     * When the Task is not running, this method does nothing.
     */
    @Override public void cancel() {
        if (runningTask != null) {
            runningTask.cancel();
            stop = true;
        }
    }
    
    /**
     * Cancels the linked Task, but still executes the TravelTask to get back to 
     * the original Point.
     * <p/>
     * When the linked Task is not running or the return Task has already 
     * started, this method does nothing.
     */
    public void cancelAndReturn() {
        if (theTask == runningTask) {
            runningTask.cancel();
            stop = false;
        }
    }
}
