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
import java.util.List;
import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import powergrid.PowerGrid;
import powergrid.control.listener.TaskListener;
import powergrid.task.Task;

/**
 * Control Panel that allows control and overview of PowerGrid functionality.
 * <p/>
 * It provides buttons to show the World map, PowerGrid's state, and also provides
 * access to available scripts.
 * <p/>
 * @author Chronio
 */
public class ControlPanel extends JPanel {
    
    /**
     * The path to the file that will be used as icon.
     */
    public static final String ICON_PATH = "powergrid/images/icon_small.png";
    
    /**
     * Creates a new ControlPanel and adds it to the given JFrame.
     * <p/>
     * An option can be given that will be used as the option parameter in the 
     * <code>Container.add(Component,Object)</code> method.
     * <p/>
     * If null is passed as the target, a new JFrame with a BorderLayout is created.
     * In that case, the option will always be taken as "Center".
     * <p/>
     * @param target the target JFrame. null means a new JFrame will be created.
     * @param addOption the add option. null means no option will be used.
     * @return the ControlPanel instance that was added to the JFrame.
     */
    public static ControlPanel addControlPanel(Container target, Object addOption) {
        ControlPanel cp = new ControlPanel();
        if (target == null) {
            JFrame f = new JFrame("Control Panel");
            f.setLayout(new BorderLayout());
            f.add(cp,"Center");
            f.setVisible(true);
            target = f;
        } else if (addOption == null) {
            target.add(cp);
        } else {
            target.add(cp,addOption);
        }
        
        if (target instanceof JFrame) {
            JFrame f = (JFrame) target;
            f.setBackground(Color.BLACK);
            f.pack();
            try {
                f.setIconImage(ImageIO.read(ClassLoader
                        .getSystemResource(ICON_PATH)));
                f.setTitle(PowerGrid.NAME + " (" + f.getTitle() + ")");
            } catch (IOException e) {}
        }
        return cp;
    }
    
    private PowerGrid powergrid = null;
    
    private JButton showWorldMap = new JButton("Show Worldmap");
    private JButton runScripts = new JButton("Scripts/Tasks");
    private JButton showStatus = new JButton("Show PG status");
    
    private JLabel messageArea = new JLabel("PowerGrid is not yet started");
    
    public ControlPanel() {
        super(new GridBagLayout());
        powergrid = PowerGrid.PG;
        setupPanel();
    }
    
    public ControlPanel usePowerGrid(PowerGrid pg) {
        assert pg != null;
        powergrid = pg;
        return this;
    }
    
    private void setupPanel() {
        setBackground(Color.BLACK);
        messageArea.setForeground(Color.WHITE);
        
        TaskQueueListener l = new TaskQueueListener();
        powergrid.taskManager().addTaskListener(l);
        
        Dimension buttonSize = new Dimension(160,28);
        showWorldMap.setPreferredSize(buttonSize);
        runScripts.setPreferredSize(buttonSize);
        showStatus.setPreferredSize(buttonSize);
        
        showWorldMap.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent e) {
                new MapViewer()
                        .useMap(powergrid.worldmap())
                        .usePlayer(powergrid.bot().getPlayer())
                        .initialize();
            }
        });
        runScripts.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent ae) {
                TaskPanel.showTaskPanel();
            }
        });
        showStatus.addActionListener(null);
        
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.fill = GridBagConstraints.BOTH;
        gbc.weightx = 1;
        add(showWorldMap,gbc);
        gbc.gridx++;
        add(runScripts,gbc);
        gbc.gridx++;
        add(showStatus,gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        add(messageArea,gbc);
        
        setPreferredSize(new Dimension(buttonSize.width*3+12,buttonSize.height+24));
        
        l.taskAdded(null);
    }
    
    public void setMessage(String message) {
        if (message != null)
            messageArea.setText(message);
    }
    
    public String getMessage() {
        return messageArea.getText();
    }
    
    public class TaskQueueListener implements TaskListener {
        @Override public void taskAdded(Task t) {
            String queue = "Task Queue: ";
            List<Task> tasks = powergrid.taskManager().getPendingTasks();
            if (!tasks.isEmpty()) {
                for (Task task : tasks) {
                    queue += "<< " + task.getName();
                }
                queue = queue.substring(2);
            } else {
                queue += "EMPTY";
            }
            setMessage(queue);
        }
        @Override public void taskRemoved(Task t) {
            taskAdded(t);
        }
        @Override public void taskStarted(Task t) {
            taskAdded(t);
            String queue = getMessage();
            if (queue.startsWith("Task Queue: ")) {
                queue = "Task Queue: (Running \"" + 
                        powergrid.taskManager().currentTask().getName() + 
                        "\") << " + queue.substring(12);
            }
            setMessage(queue);
        }
        @Override public void taskFinished(Task t) {
            taskAdded(t);
        }
    }
}
