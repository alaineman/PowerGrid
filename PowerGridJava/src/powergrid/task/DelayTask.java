package powergrid.task;

import java.awt.Dimension;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import powergrid.PowerGrid;
import powergrid.view.TaskConfigurationPanel;

/**
 * Task that waits a set amount of time before returning.
 * 
 * @author Chronio
 */
public class DelayTask extends Task implements Configurable {

    private int waitingTime;
    
    private TaskConfigurationPanel configPanel = null;
    private JTextField text = null;
    
    /**
     * Creates a new DelayTask with its waiting time set to 0.
     */
    public DelayTask() {
        this(0);
    }
    
    /**
     * Creates a new DelayTask set to wait the indicated amount of milliseconds
     * when executed.
     * @param time the amount of milliseconds to wait
     */
    public DelayTask(int time) {
        waitingTime = time;
    }
    
    /**
     * Sets the amount of time to wait.
     * @param time the amount of time to wait
     */
    public void setTime(int time) {
        waitingTime = time;
    }
    
    /**
     * Returns the amount of time this DelayTask waits.
     * @return the amount of time this DelayTask waits
     */
    public int getTime() {
        return waitingTime;
    }
    
    /**
     * Waits the amount of time indicated by <code>getTime()</code> and then 
     * returns.
     * <p/>
     * If this time is less than 0, the time is taken as 0.
     */
    @Override
    public void execute() {
        try {
            Thread.sleep(Math.max(getTime(), 0));
        } catch (InterruptedException e) {}
    }

    @Override
    public TaskConfigurationPanel configPanel() {
        if (configPanel == null) {
            configPanel = new TaskConfigurationPanel(this);
            configPanel.setLayout(new GridLayout(2, 1));
            configPanel.add(new JLabel("Time (ms): "));
            text = new JTextField();
            configPanel.add(text);
            configPanel.setPreferredSize(new Dimension(200, 32));
        }
        return configPanel;
    }

    @Override
    public boolean apply() {
        if (configPanel != null && text != null) {
            try {
                int time = (int) Double.parseDouble(text.getText());
                if (time < 0) {
                    throw new NumberFormatException("Negative time");
                }
                waitingTime = time;
                text = null;
                configPanel = null;
                return true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, 
                        "The input \"" + text.getText() + 
                        "\" is not valid.\nPlease enter a positive number.", 
                        "Invalid input", JOptionPane.ERROR_MESSAGE, 
                        PowerGrid.getIcon());
                return false;
            }
        } else {
            throw new IllegalStateException(
                    "apply not allowed without active config panel");
        }
    }

    @Override
    public void configCanceled() {
        configPanel = null;
        text = null;
    }
    
}
