package powergrid.view.status;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import javax.swing.Icon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.border.LineBorder;
import powergrid.PowerGrid;
import powergrid.control.listener.TaskListener;
import powergrid.plugins.Plugin;
import powergrid.plugins.PluginInfo;
import powergrid.task.Task;
import powergrid.view.ControlPanel;
import powergrid.view.PGPanel;

/**
 * Panel that offers functionality to monitor and modify the task queue of
 * PowerGrid.
 * <p/>
 * @author Alaineman
 * @author Chronio
 */
//TODO implement actions
public class TaskControlPanel extends PGPanel {

    public static final int SIDEPANEL_WIDTH = 200;    
    
    private JLabel taskName;
    private JLabel taskPlugin;
    private JLabel taskType;
    private JScrollPane descriptionScroller;
    private JTextArea description;
    
    private JButton removeButton;
    private JButton moveUpButton;
    private JButton moveDownButton;
    private JButton configButton;
    
    private ScrollableElementList list;
    
    private TaskEntry selected;

    /**
     * Creates a new TaskControlPanel.
     */
    public TaskControlPanel() {
        super(new BorderLayout());
        taskName = new JLabel();
        taskType = new JLabel();
        taskPlugin = new JLabel();
        description = new JTextArea();
        descriptionScroller = new JScrollPane(description);
        removeButton = new JButton("Remove Task");
        moveUpButton = new JButton("Move up");
        moveDownButton = new JButton("Move down");
        configButton = new JButton("Configure");
        list = new ScrollableElementList();
    }

    @Override 
    public TaskControlPanel withPowerGrid(PowerGrid pg) {
        super.withPowerGrid(pg);
        return this;
    }
    
    @Override
    public TaskControlPanel initialize() {
        super.initialize();
        
        list.initialize();
        
        setPreferredSize(new Dimension(320, 240));
        getPowerGrid().taskManager().addTaskListener(new TaskListUpdater());
        
        JPanel side = new JPanel(new BorderLayout());
        
        JPanel taskInfo = new JPanel(new BorderLayout(0, 4));
        JPanel taskInfoLabels = new JPanel();
        
        Dimension labelSize = new Dimension(SIDEPANEL_WIDTH - 20, 32);
        taskName.setPreferredSize(labelSize);
        taskType.setPreferredSize(labelSize);
        taskPlugin.setPreferredSize(labelSize);
        
        labelSize.setSize(labelSize.getWidth(), 128);
        descriptionScroller.setPreferredSize(labelSize);
        
        taskInfoLabels.add(taskName);
        taskInfoLabels.add(taskType);
        taskInfoLabels.add(taskPlugin);
        
        taskInfo.add(taskInfoLabels, BorderLayout.NORTH);
        taskInfo.add(descriptionScroller, BorderLayout.CENTER);
        
        side.add(taskInfo, BorderLayout.CENTER);
        
        JPanel buttons = new JPanel(new GridLayout(2, 2, 6, 4));
        buttons.add(moveUpButton);
        buttons.add(configButton);
        buttons.add(moveDownButton);
        buttons.add(removeButton);
        
        moveUpButton.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent ae) {
                TaskEntry entry = getSelectedEntry();
                if (entry != null) {
                    getPowerGrid().taskManager().moveTaskUp(entry.getTask());
                }
            }
        });
        moveDownButton.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent ae) {
                TaskEntry entry = getSelectedEntry();
                if (entry != null) {
                    getPowerGrid().taskManager().moveTaskDown(entry.getTask());
                }
            }
        });
        
        buttons.setBorder(new LineBorder(Color.BLACK));
        
        side.add(buttons, BorderLayout.SOUTH);
        side.setPreferredSize(new Dimension(SIDEPANEL_WIDTH, getHeight()));
        add(side, BorderLayout.EAST);
        add(list, BorderLayout.CENTER);
        
        setMinimumSize(new Dimension(640, 480));
        
        updateList();
        return this;
    }
    
    /**
     * Sets the selected TaskEntry on this TaskControlPanel.
     * @param entry the TaskEntry to select
     */
    public synchronized void setSelectedEntry(TaskEntry entry) {
         if (entry != null) {
             entry.setSelected(true);
         }
         if (selected != null) {
             selected.setSelected(false);
         }
         selected = entry;
         
         updateTaskData();
    }
    
    /**
     * @return the selected TaskEntry, or null if no TaskEntry is selected.
     */
    public TaskEntry getSelectedEntry() {
        return selected;
    }
    
    /**
     * Updates the Task list to match the current state of the TaskManager.
     */
    public synchronized void updateList() {
        // Store the selected Task to try and match the Task to a Task in the 
        // updated list of tasks. This provides a smoother experience when 
        // performing operations on the Task queue.
        Task selectedTask = (selected == null ? null : selected.getTask());
        setSelectedEntry(null);
        
        list.clear();
        List<Task> tasks = getPowerGrid().taskManager().getPendingTasks();
        
        if (tasks.isEmpty()) {
            JLabel label = new JLabel("no pending tasks");
            label.setFont(ControlPanel.TITLE_FONT);
            label.setHorizontalAlignment(JLabel.CENTER);
            list.add(label);
        } else {
            TaskEntry newSelection = null;
            TaskEntry[] entries = new TaskEntry[tasks.size()];
            for (int i = 0; i < tasks.size(); i++) {
                entries[i] = new TaskEntry(tasks.get(i))
                        .withPowerGrid(getPowerGrid())
                        .initialize();
                if (tasks.get(i).equals(selectedTask)) {
                    newSelection = entries[i];
                }
            }
            list.add(entries);
            setSelectedEntry(newSelection);
        }
    }
    
    /**
     * Updates the information of the selected TaskEntry.
     * <p/>
     * When no entry is selected, the text fields will be set to a generic 
     * value and the control buttons will be disabled.
     */
    public synchronized void updateTaskData() {
        if (selected == null) {
            // Set each component's text content to a default value
            taskName.setText("no task selected");
            taskType.setText(null);
            taskPlugin.setText(null);
            description.setText(null);
            
            // and disable the control buttons.
            removeButton.setEnabled(false);
            moveUpButton.setEnabled(false);
            moveDownButton.setEnabled(false);
            configButton.setEnabled(false);
        } else {
            // Collect the information about the selected Task
            Task t = selected.getTask();
            Plugin p = getPowerGrid().lookupPluginForTask(t);
            String name = p.getClass().getAnnotation(PluginInfo.class).name();
            
            // set the collected information in the appropriate fields
            taskName.setText(t.getName());
            taskType.setText(t.getClass().getSimpleName());
            taskPlugin.setText(name);
            description.setText(t.getDescription());
            
            // and enable the control buttons.
            removeButton.setEnabled(true);
            moveUpButton.setEnabled(true);
            moveDownButton.setEnabled(true);
            configButton.setEnabled(true);
        }
    }

    /**
     * JPanel that shows the information related to a Task object.
     */
    public class TaskEntry extends PGPanel {

        private Task task;

        /**
         * Creates a TaskEntry instance.
         * @param t the Task this TaskEntry represents
         */
        public TaskEntry(Task t) {
            super(new BorderLayout(4, 0));
            assert t != null;
            task = t;
        }
        
        /** 
         * @return the Task in this TaskEntry.
         */
        public Task getTask() {
            return task;
        }

        @Override
        public TaskEntry withPowerGrid(PowerGrid pg) {
            super.withPowerGrid(pg);
            return this;
        }
        
        @Override
        public TaskEntry initialize() {
            super.initialize();
            
            setBackground(Color.WHITE);
            setBorder(new LineBorder(Color.BLACK));
            
            Icon image = getPowerGrid().lookupPluginForTask(task).getPluginIcon();
            add(new JLabel(image), BorderLayout.WEST);
            add(new JLabel(task.getName()), BorderLayout.CENTER);
            
            return this;
        }
        
        /**
         * Sets the background color to match whether the Entry is selected.
         * @param selected whether the TaskEntry is selected
         */
        public void setSelected(boolean selected) {
            if (selected) {
                setBackground(Color.LIGHT_GRAY);
            } else {
                setBackground(Color.WHITE);
            }
        }
    }
    
    /**
     * TaskListener that updates the list of Tasks whenever a change occurs 
     * in the TaskManager.
     * <p/>
     * All the methods call the updateList() method of the TaskControlPanel 
     * when called.
     */
    public class TaskListUpdater implements TaskListener {
        @Override public void taskAdded(Task t) {
            updateList();
        }

        @Override public void taskRemoved(Task t) {
            updateList();
        }

        @Override public void taskStarted(Task t) {
            updateList();
        }

        @Override public void taskFinished(Task t) {
            updateList();
        }        
    }
}
