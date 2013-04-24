package powergrid.task;

import java.awt.Dimension;
import java.awt.Image;
import java.io.IOException;
import java.net.URL;
import java.util.logging.Level;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import org.powerbot.game.api.methods.Walking;
import powergrid.PowerGrid;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.view.TaskConfigurationPanel;

/**
 * Creates a Task that rests the local Player. 
 * <p/>
 * A boolean can be set to abort resting when there are other Tasks in the Queue.
 * <p/>
 * This Task is Configurable and publicly accessible to end-users.
 * <p/>
 * @author Chronio
 */
public class RestTask extends StepTask implements Configurable {

    private boolean abortOnTask = false;
    private int targetEnergy = 100;
    
    private ConfigPanel panel = null;
    
    public RestTask() {}
    
    /**
     * Creates a new RestTask with the given priority.
     * <p />
     * <code>abortOnTask</code> indicates whether this Task should be aborted
     * when another Task is added to the TaskQueue.
     * <p/>
     * @param priority    the priority of this Task
     * @param abortOnTask when true, aborts this Task when other Tasks are pending
     */
    public RestTask(int priority, boolean abortOnTask) {
        super(priority);
        super.setName("Rest at current location");
        this.abortOnTask = abortOnTask;
    }
    
    /**
     * Creates a new RestTask with the given priority.
     * <p />
     * <code>abortOnTask</code> indicates whether this Task should be aborted
     * when another Task is added to the TaskQueue.
     * <p />
     * <code>requiredEnergy</code> indicates the energy the local Player must
     * have before this Task ends. When <code>abortOnTask</code> is set, this
     * amount of energy may not have been achieved when this Task ends.
     * <p/>
     * @param priority       the priority of this Task
     * @param abortOnTask    when true, aborts this Task when other Tasks are pending
     * @param requiredEnergy the amount of energy the Player must have before
     *                       this Task ends.
     */
    public RestTask(int priority, boolean abortOnTask, int requiredEnergy) {
        super(priority);
        super.setName("Rest at current location");
        targetEnergy = Math.max(0, Math.min(100, requiredEnergy));
        this.abortOnTask = abortOnTask;
    }

    /**
     * Returns whether this Task will abort when another Task is in the task 
     * queue.
     * @return true if this Task cancels itself when another Task is pending.
     */
    public boolean willAbortOnTask() {
        return abortOnTask;
    }
    
    /**
     * Returns the target energy level that this Task tries to achieve before
     * finishing.
     * @return the minimal energy level before this Task completes.
     */
    public int targetEnergy() {
        return targetEnergy;
    }
    
    /**
     * Attempts to issue the rest command to the RSBot environment.
     * <p/>
     * This Task will be canceled here when the required energy is already
     * achieved.
     */
    @Override public void start() {
        RSInteractor in = PowerGrid.PG.rsInteractor();
        for (int attempt=0;attempt<5;attempt++) {
            //if (in.getState() == Bot.STATE_RESTING) break;
            in.click(in.getWidgetChild(750, 5));
        }
//        if (bot.getState() != Bot.STATE_RESTING) {
//            cancel();
//            PowerGrid.LOGGER.info("RestTask: Resting Failed");
//        }
        if (Walking.getEnergy() >= targetEnergy) {
            cancel();
            PowerGrid.LOGGER.info("RestTask: Energy is already sufficient, task has been canceled");
        }
    }
    
    /**
     * Checks if the Player is resting. If not, it restarts this Task.
     * If the Player is resting and the targetEnergy has been achieved, this
     * Task ends.
     */
    @Override public synchronized void step() {
        if (willAbortOnTask() && PowerGrid.PG.taskManager().tasksPending() > 0) {
            cancel();
        } else {
            if (targetReached()) {
                cancel();
                PowerGrid.LOGGER.info("RestTask: Target Energy (" + targetEnergy + ") achieved, RestTask completed");
            }
//            if (PowerGrid.PG.bot().getState() != Bot.STATE_RESTING) {
//                // re-run the start method to start resting
//                PowerGrid.LOGGER.info("Currently not resting, restarting RestTask");
//                start();
//            }
        }
    }
    
    private boolean targetReached() {
        RSInteractor in = PowerGrid.PG.rsInteractor();
        int energy = Integer.parseInt(in.getWidgetChild(750, 6).getText());
        return energy >= targetEnergy();
    }

    @Override public TaskConfigurationPanel configPanel() {
         panel = new ConfigPanel(this);
         return panel;
    }

    @Override public boolean apply() {
        if (panel != null) {
            targetEnergy = panel.getEnergy();
        }
        return true;
    }

    @Override public void configCanceled() {
        panel = null;
    }
    
    private class ConfigPanel extends TaskConfigurationPanel {
        private JTextField targetEnergy = new JTextField("100");
        private ConfigPanel(RestTask instance) {
            super(instance);
            try {
                ImageIcon icon = new ImageIcon(new URL("powergrid/images/logo.png"));
                icon = new ImageIcon(icon.getImage().getScaledInstance(240, 61, Image.SCALE_SMOOTH));
                add(new JLabel(icon),"North");
            } catch (IOException ex) {
                PowerGrid.LOGGER.log(Level.WARNING, 
                        "Could not load the specified icon", ex);
            }
            add(new JLabel("Value:"),"West");
            add(targetEnergy,"Center");
            setPreferredSize(new Dimension(240,85));
        }
        
        private int getEnergy() {
            try {
                return Integer.parseInt(targetEnergy.getText());
            } catch (NumberFormatException nfe) {
                JOptionPane.showMessageDialog(null, "The given value is not valid, the value will be taken as 100.","Invalid value",JOptionPane.WARNING_MESSAGE);
                return 100;
            }
        }
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 37 * hash + (abortOnTask ? 1 : 0);
        hash = 37 * hash + targetEnergy;
        return hash;
    }

    @Override public boolean equals(Object other) {
        if (other instanceof RestTask) {
            RestTask that = (RestTask)other;
            return this.getPriority() == that.getPriority() 
                    && this.targetEnergy() == that.targetEnergy()
                    && this.willAbortOnTask() == that.willAbortOnTask();
        }
        return false;
    }
}
