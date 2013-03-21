package powergrid.task;

import java.awt.Dimension;
import java.awt.Image;
import java.io.IOException;
import java.net.URL;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.Widgets;
import powergrid.Bot;
import powergrid.PowerGrid;
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
     * Attempts to issue the rest command to the RSBot environment.
     * <p/>
     * This Task will be canceled here when the required energy is already
     * achieved.
     */
    @Override public void start() {
        for (int attempt=0;attempt<5;attempt++) {
            if (PowerGrid.BOT.getState() == Bot.STATE_RESTING) break;
            Widgets.get(750, 5).interact("Rest");
        }
        if (PowerGrid.BOT.getState() != Bot.STATE_RESTING) {
            cancel();
            PowerGrid.logMessage("RestTask: Resting Failed");
        }
        if (Walking.getEnergy() >= targetEnergy) {
            cancel();
            PowerGrid.logMessage("RestTask: Energy is already sufficient, task has been canceled");
        }
    }
    
    /**
     * Checks if the Player is resting. If not, it restarts this Task.
     * If the Player is resting and the targetEnergy has been achieved, this
     * Task ends.
     */
    @Override public synchronized void step() {
        if (abortOnTask && PowerGrid.TM.tasksPending() > 0) {
            cancel();
        } else {
            if (Walking.getEnergy() >= targetEnergy) {
                cancel();
                PowerGrid.logMessage("RestTask: Target Energy (" + targetEnergy + ") achieved, RestTask completed");
            }
            if (PowerGrid.BOT.getState() != Bot.STATE_RESTING) {
                // re-run the start method to start resting
                PowerGrid.logMessage("Currently not resting, restarting RestTask");
                start();
            }
        }
    }

    @Override public TaskConfigurationPanel configPanel() {
         panel = new ConfigPanel(this);
         return panel;
    }

    @Override public void apply() {
        if (panel != null) {
            targetEnergy = panel.getEnergy();
        }
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
                System.err.println("Could not load the specified icon:\n"+ex);
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

    @Override public boolean equals(Object other) {
        if (other instanceof RestTask) {
            RestTask that = (RestTask)other;
            return this.getPriority() == that.getPriority() 
                    && this.abortOnTask == that.abortOnTask;
        }
        return false;
    }
}
