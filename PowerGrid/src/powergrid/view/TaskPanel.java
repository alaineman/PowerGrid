package powergrid.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;
import powergrid.PowerGrid;
import powergrid.control.TaskManager;
import powergrid.plugins.Plugin;
import powergrid.plugins.PluginInfo;
import powergrid.tasks.Configurable;
import powergrid.tasks.Task;

/**
 * This Panel shows all available tasks of each Loaded Plugin.
 * @author Chronio
 */
public class TaskPanel extends JPanel {
    
    private static TaskPanel theTaskPanel = null;
    private static JFrame taskFrame = null;
    
    public static TaskPanel showTaskPanel() {
        if (theTaskPanel == null) {
            theTaskPanel = new TaskPanel();
        }
        if (taskFrame == null) {
            taskFrame = new JFrame("PowerGrid - Tasks");
            try {
                taskFrame.setIconImage(ImageIO.read(ClassLoader.getSystemResource("powergrid/images/icon_small.png")));
            } catch (IOException e) {
                PowerGrid.logMessage("Could not set Icon Image to Task Frame",e);
            }
            taskFrame.setLayout(new BorderLayout());
            taskFrame.add(theTaskPanel,"Center");
            taskFrame.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
            
            taskFrame.pack();
        }
        taskFrame.setVisible(true);
        
        taskFrame.setAlwaysOnTop(true);
        taskFrame.setAlwaysOnTop(false);
        
        return theTaskPanel;
    }
    
    private Class<?>[] tasks;
    
    public TaskPanel () {
        super(new BorderLayout());
        ArrayList<Class<? extends Task>> ts = new ArrayList<>();
        
        tasks = ts.toArray(new Class<?>[ts.size()]);
        
        setupPanel();
    }
    
    private void setupPanel() {
        JPanel entries = new JPanel (new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        entries.setPreferredSize(new Dimension(250,200));
        setPreferredSize(new Dimension(250,200));
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        for (Plugin p : PowerGrid.getPlugins()) {
            for (Class<? extends Task> c : p.getPublicTasks()) {
                entries.add(new TaskEntry(p.getClass().getAnnotation(PluginInfo.class).name(),c),gbc);
                gbc.gridy++;
            }
        }
        gbc.weighty=1;
        gbc.fill = GridBagConstraints.BOTH;
        entries.add(new Container(),gbc);
        add(entries,"Center");
    }
    
    public static class TaskEntry extends JPanel {
        private String pluginName = "Unknown Plugin";
        private Class<? extends Task> task = null;
        
        public TaskEntry(String pluginName, Class<? extends Task> t) {
            super(new BorderLayout());
            if (t == null)
                throw new IllegalArgumentException("Null-value for Task");
            System.out.println("Task " + t.getName() + " loaded.");
            task = t;
            if (pluginName != null)
                this.pluginName = pluginName;
            setupPanel();
        }
        
        private void setupPanel() {
            JLabel name = new JLabel(task.getSimpleName() + "  (" + pluginName + ")");
            JButton run = new JButton("run");
            run.setPreferredSize(new Dimension(60,24));
            setPreferredSize(new Dimension(240,32));
            add(name,"Center");
            add(run,"East");
            
            setBorder(new LineBorder(Color.BLACK));
            
            run.addActionListener(new ActionListener() {
                @Override public void actionPerformed(ActionEvent ae) {
                    try {
                        Task t = task.getConstructor().newInstance();
                        
                        if (t instanceof Configurable) {
                            Configurable cfg = (Configurable)t;
                            TaskConfigurationPanel configPanel = cfg.configPanel();
                            ConfigureFrame frame = new ConfigureFrame(configPanel);
                            frame.setLocationByPlatform(true);
                            frame.setVisible(true);
                        } else {
                            if (JOptionPane.showConfirmDialog(null, "Run the Task \"" + task.getName() + "\"?", "Run this Task", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE)
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
