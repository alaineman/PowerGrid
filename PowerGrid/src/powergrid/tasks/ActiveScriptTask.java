package powergrid.tasks;

import org.powerbot.core.script.ActiveScript;

/**
 * Task that runs an ActiveScript instance inside of PowerGrid as if it where running in RSBot.
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
     * @return the ActiveScript instance connected to this ActiveScriptTask
     */
    public ActiveScript getInstance() {
        return theScript;
    }

    /**
     * Run when this Task is started. 
     * <p/>
     * This method should not be called directly, as this Task's execute method
     * does this automatically.
     * <p/>
     * This methods calls the onStart() method of the ActiveScript.
     */
    @Override public void start() {
        theScript.onStart();
    }
    
    /**
     * Returns the region of spread between waiting times returned from the loop() method of the ActiveScript.
     * @see ActiveScriptTask#setWaitSpread(int) for info about the waitSpread feature
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
     * This method is executed each step in this Task's execute method.
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
     * It is not required to call this method manually, the execute method of this
     * StepTask will do this automatically.
     */
    @Override public void finish() {
        theScript.onStop();
    }
}
