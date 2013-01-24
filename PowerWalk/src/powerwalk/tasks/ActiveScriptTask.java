package powerwalk.tasks;

import java.util.List;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.core.script.job.Job;
import powerwalk.Starter;

/**
 * Task that runs an ActiveScript instance inside of PowerWalk as if it where running in RSBot.
 * <p/>
 * Note that the ActiveScriptTask might not run the ActiveScript instance in the 
 * exact same way, so it cannot be guaranteed that the provided script will perform 
 * the same.
 * <p/>
 * @author Chronio
 */
public class ActiveScriptTask extends StepTask {
    
    private ActiveScript theScript;
    private int waitSpread = 0;
    
    /**
     * Creates an ActiveScriptTask with the given ActiveScript instance and priority.
     * <p/>
     * @param script the script to start when this Task runs.
     * @param priority the priority of this Task
     * @throws IllegalArgumentException when the provided script is null
     */
    public ActiveScriptTask(ActiveScript script, int priority) {
        super(priority);
        if (script == null)
            throw new IllegalArgumentException("invalid script");
        theScript = script;
    }
    
    /**
     * Creates an ActiveScriptTask with the given Script class and priority
     * @param scriptClass the Class object of the ActiveScript subclass to load
     * @param priority the prioriryt of this Task
     * @throws IllegalArgumentException when the provided scriptClass is null or could not be instantiated.
     */
    public ActiveScriptTask(Class<? extends ActiveScript> scriptClass, int priority) {
        super(priority);
        if (scriptClass == null)
            throw new IllegalArgumentException("invalid script class");
        try {
            theScript = scriptClass.newInstance();
        } catch (InstantiationException | IllegalAccessException ex) {
            throw new IllegalArgumentException("Class could not be instantiated",ex);
        }
    }
    
    /**
     * Returns the ActiveScript instance connected to this ActiveScriptTask
     * @return 
     */
    public ActiveScript getInstance() {
        return theScript;
    }

    /**
     * run when this Task is started. This method should not be called directly, 
     * as a TaskRunner or the PowerWalk TaskManager will do this automatically.
     * <p/>
     * In the case of an ActiveScriptTask, the onStart() method of the ActiveScript is called.
     */
    @Override public void start() {
        List<Job> jobs = theScript.getStartupJobs();
        if (Starter.starter != null) {
            for (Job j : jobs) {
                Starter.starter.getContainer().submit(j);
            }
        }
        theScript.onStart();
    }
    
    /**
     * Returns the region of spread between waiting times returned from the loop() method of the ActiveScript.
     * @see ActiveScriptTask#setWaitSpread(double) for info about the waitSpread feature
     * @return the waitSpread setting of this ActiveScriptTask
     */
    public double getWaitSpread() {
        return waitSpread;
    }
    
    /**
     * Sets the waitSpread value of this ActiveScriptTask.
     * <p/>
     * This value will be used to modify the waiting times between loop() method calls.
     * When this value is set, the Task will wait for a pseudo-random amount of time before calling loop() again.
     * <p/>
     * More specifically, when the returned value from the loop() method is <code>t</code>, 
     * and the waitSpread is set to <code>w</code>, then the actual waiting time 
     * lies anywhere between <code>t-w</code> and <code>t+w</code>.
     * <p/>
     * Setting the waitSpread to a negative value <code>w</code> will have the same 
     * effect as setting it to <code>-w</code>, since the sign of the parameter is ignored.
     * <p/>
     * The default value for the waitSpread is 0.
     * <p/>
     * @param waitSpread 
     */
    public void setWaitSpread(int waitSpread) {
        this.waitSpread = Math.abs(waitSpread);
    }
    
    /**
     * This method is executed each step by a TaskRunner or the PowerWalk TaskManager.
     * <p/>
     * In the case of an ActiveScriptTask, it calls the loop() method once and 
     * then waits the appropriate amount of time.
     * <p/>
     * This method should not be called directly.
     */
    @Override public void step() {
        int waitTime = theScript.loop();
        if (waitTime >= 0) {
            Task.sleep(Math.abs((int)(2*Math.random()*waitSpread + waitTime - waitSpread)));
        } else {
            cancel();
        }
    }
    
    /**
     * This method is called when the last iteration of the step() method has taken place.
     * <p/>
     * Do not use this method to stop a running Task. Instead, use the cancel() method.
     * <p/>
     * It is not required to call this method manually, as a TaskRunner or 
     * the PowerWalk TaskManager will do this automatically.
     */
    @Override public void finish() {
        theScript.onStop();
    }
}
