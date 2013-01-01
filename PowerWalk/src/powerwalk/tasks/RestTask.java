package powerwalk.tasks;

import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.Players;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.StepTask;
import powerwalk.Task;

/**
 * Creates a Task that rests the local Player. A boolean can be set to abort 
 * resting when there are other Tasks in the Queue. 
 * @author Chronio
 */
public class RestTask extends StepTask {

    private boolean abortOnTask = false;
    private int targetEnergy = 100;
    
    public RestTask(int priority, boolean abortOnTask) {
        super(priority);
        super.setName("Rest at current location");
        this.abortOnTask = abortOnTask;
    }
    
    public RestTask(int priority, boolean abortOnTask, int requiredEnergy) {
        super(priority);
        super.setName("Rest at current location");
        targetEnergy = Math.max(0, Math.min(100, requiredEnergy));
        this.abortOnTask = abortOnTask;
    }

    @Override public void start() {
        for (int attempt=0;attempt<5;attempt++) {
            if (Bot.getBot().getState() == Bot.STATE_RESTING) break;
            Widgets.get(750, 5).interact("Rest");
        }
        if (Bot.getBot().getState() != Bot.STATE_RESTING) {
            cancel();
            Starter.logMessage("Resting Failed");
        }
    }
    
    @Override public void step() {
        if (abortOnTask && Bot.getBot().tasksPending() > 0) {
            cancel();
        } else {
            if (Walking.getEnergy() >= targetEnergy) {
                cancel();
            }
            int anim = Players.getLocal().getAnimation();
            if (Bot.getBot().getState() != Bot.STATE_RESTING) {
                start();
            }
        }
    }
    
}
