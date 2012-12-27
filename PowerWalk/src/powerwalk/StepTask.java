/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk;

/**
 *
 * @author Patrick
 */
public abstract class StepTask extends Task {
    
    private int numSteps = -1;
    
    public StepTask(int priority) {
        super(priority);
    }
    
    public StepTask(int priority, int numSteps) {
        super(priority);
        this.numSteps = numSteps;
    }
    
    @Override public void execute() {
        if (numSteps != 0) {
            if (numSteps > 0) numSteps--;
            step();
        } else {
            
        }
    }
    
    public int stepsLeft() {
        return (numSteps<0 ? Integer.MAX_VALUE : numSteps);
    }
    
    public boolean hasMoreSteps() {
        return numSteps != 0;
    }
    
    public boolean isOnLoop() {
        return numSteps < 0;
    }
    
    protected void setStepsLeft(int stepsLeft) {
        numSteps = stepsLeft;
    }
    
    protected void setOnLoop() {
        numSteps = -1;
    }
    
    public abstract void step();
    
    protected void done() {
        numSteps = 0;
    }
}
