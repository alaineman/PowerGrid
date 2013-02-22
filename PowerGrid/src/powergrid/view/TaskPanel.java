package powergrid.view;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import powergrid.PowerGrid;
import powergrid.control.TaskManager;
import powergrid.plugins.Plugin;
import powergrid.tasks.Configurable;
import powergrid.tasks.Task;

/**
 * This Panel shows all available tasks of each Loaded Plugin.
 * @author Chronio
 */
public class TaskPanel extends JPanel {
    
    private Class<?>[] tasks;
    
    public TaskPanel () {
        super(new BorderLayout());
        ArrayList<Class<? extends Task>> ts = new ArrayList<>();
        for (Plugin p : PowerGrid.getPlugins()) {
            ts.addAll(p.getPublicTasks());
        }
        tasks = ts.toArray(new Class<?>[ts.size()]);
        
        setupPanel();
    }
    
    private void setupPanel() {
        
    }
    
    public static class TaskEntry extends JPanel {
        private Class<? extends Task> task = null;
        
        public TaskEntry(Class<? extends Task> t) {
            super(new BorderLayout());
            if (task == null)
                throw new IllegalArgumentException("Null-value for Task");
            task = t;
            setupPanel();
        }
        
        private void setupPanel() {
            JLabel name = new JLabel(task.getName());
            JButton run = new JButton("run");
            run.setPreferredSize(new Dimension(60,24));
            add(name,"Center");
            add(run,"East");
            
            run.addActionListener(new ActionListener() {
                @Override public void actionPerformed(ActionEvent ae) {
                    try {
                        Task t = task.getConstructor().newInstance();
                        
                        if (Configurable.class.isAssignableFrom(task)) {
                            TaskConfigurationPanel configPanel = ((Configurable)t).configPanel();
                            ConfigureFrame frame = new ConfigureFrame(configPanel);
                            frame.setLocationByPlatform(true);
                            frame.setVisible(true);
                        } else {
                            if (JOptionPane.showConfirmDialog(null, "Run the Task \"" + task.getName() + "\"?", "Run this Task", JOptionPane.QUESTION_MESSAGE)
                                    == JOptionPane.YES_OPTION) {
                                TaskManager.getTM().assignTask(t);
                            }
                        }
                    } catch (NoSuchMethodException | IllegalAccessException | InstantiationException | InvocationTargetException e) {
                        JOptionPane.showMessageDialog(null, "The Task could not be instantiated.", "Error creating Task", JOptionPane.ERROR_MESSAGE);
                    }
                }
            });
        }
    }
}
