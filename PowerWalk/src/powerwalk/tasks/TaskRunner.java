package powerwalk.tasks;

import powerwalk.Starter;

/**
 * Runs a Task instance separate from PowerWalk. It can be used to run tasks 
 * inside of other tasks.
 * @author Chronio
 */
public class TaskRunner {
    
    private Task task = null;
    
    /**
     * Creates a new TaskRunner set to run the specified Task instance.
     * @param t the Task this TaskRunner will run.
     * @throws IllegalArgumentException when the specified task is null
     */
    public TaskRunner(Task t) {
        if (t == null) throw new IllegalArgumentException("Null-value as Task is not allowed");
        task = t;
    }
    
    /**
     * Runs this task. This method will not return before the Task has completed.
     */
    public synchronized void run() {
        if (task instanceof StepTask) {
            StepTask t = (StepTask) task;
            Starter.logMessage("Beginning StepTask \"" + t.getName() + "\"...", "TaskRunner");
            t.start();
            while (t.hasMoreSteps()) {
                t.execute();
            }
            t.finish();
            Starter.logMessage("StepTask \"" + t.getName() + "\" has ended", "TaskRunner");
        } else {
            Starter.logMessage("Beginning Task \"" + task.getName() + "\"...", "TaskRunner");
            task.execute();
            Starter.logMessage("Task \"" + task.getName() + "\" has ended.", "TaskRunner");
        }
    }
    
    /**
     * Returns the Task object associated with this TaskRunner
     * @return the associated Task instance
     */
    public Task getTask() {
        return task;
    }
}
