package powergrid.view;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import powergrid.control.TaskManager;
import powergrid.tasks.Configurable;
import powergrid.tasks.Task;

/**
 * Frame that holds the run and cancel buttons along with the Task's Configuration panel.
 * @author Chronio
 */
public class ConfigureFrame extends JFrame {
    
    private TaskConfigurationPanel config = null;
    
    public ConfigureFrame(TaskConfigurationPanel panel) {
        if (panel == null) 
            throw new IllegalArgumentException("Null-value for ConfigPanel.");
        config = panel;
        setTitle(config.getTitle());
        setupPanel();
    }
    
    private void setupPanel() {
        setLayout(new BorderLayout());
        add(config,"Center");
        
        JPanel buttons = new JPanel();
        Dimension buttonDim = new Dimension(90, 32);
        JButton cancel = new JButton("Cancel");
        cancel.setPreferredSize(buttonDim);
        cancel.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent ae) {
                dispose();
            }
        });
        JButton run = new JButton ("Run");
        run.setPreferredSize(buttonDim);
        run.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent ae) {
                Configurable c = config.getTask();
                if (c instanceof Task) {
                    c.apply();
                    TaskManager.getTM().assignTask((Task)c);
                    dispose();
                } else {
                    c.configCanceled();
                    JOptionPane.showMessageDialog(null, "Error creating Task, configuration failed.","Failed to assign Task",JOptionPane.ERROR_MESSAGE);
                    dispose();
                }
            }
        });
        buttons.add(cancel);
        buttons.add(run);
        add(buttons,"South");
        setMinimumSize(new Dimension(200,60));
        pack();
    }

    /**
     * Notifies the TaskConfigurationPanel in this ConfigureFrame before 
     * disposing the Frame.
     */
    @Override public void dispose() {
        config.cancel();
        super.dispose();
    }
    
    
}
