package powergrid.view.status;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.util.ArrayList;
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

/**
 * Panel that offers functionality to monitor and modify the task queue of
 * PowerGrid.
 * <p/>
 * @author Alaineman
 * @author Chronio
 */
//TODO finish initalize and data load
//TODO implement actions
public class TaskControlPanel extends JPanel {

    private PowerGrid pg;
    
    private JLabel taskName;
    private JLabel taskPlugin;
    private JLabel taskType;
    private JScrollPane descriptionScroller;
    private JTextArea description;
    
    private JButton removeButton;
    private JButton moveUpButton;
    private JButton moveDownButton;
    private JButton configButton;
    
    private JScrollPane listScroller;
    private GridBagConstraints listGBC;
    private JPanel listPanel;
    
    private ArrayList<TaskEntry> entries;
    private TaskEntry selected;

    /**
     * Creates a new TaskControlPanel.
     */
    public TaskControlPanel() {
        super(new BorderLayout());
        pg = null;
        taskName = new JLabel();
        taskType = new JLabel();
        taskPlugin = new JLabel();
        description = new JTextArea();
        descriptionScroller = new JScrollPane(description);
        removeButton = new JButton("Remove Task");
        moveUpButton = new JButton("Move up");
        moveDownButton = new JButton("Move down");
        configButton = new JButton("Configure");
        listPanel = new JPanel(new GridBagLayout());
        listScroller = new JScrollPane(listPanel);
        listGBC = new GridBagConstraints();
        entries = new ArrayList<>(6);
    }

    /**
     * Sets the PowerGrid instance to show the information of.
     * <p/>
     * This method should only be called once.
     *
     * @param p the PowerGrid instance
     * @return itself for fluency
     */
    public TaskControlPanel withPowerGrid(PowerGrid p) {
        assert pg == null && p != null;
        pg = p;
        return this;
    }

    /**
     * @return the PowerGrid instance.
     */
    public PowerGrid getPowerGrid() {
        return pg;
    }

    /**
     * Setup the TaskControlPanel.
     * @return itself for fluency.
     */
    public TaskControlPanel initialize() {
        setPreferredSize(null);
        pg.taskManager().addTaskListener(new TaskListUpdater());
        
        List<Task> pendingTasks = pg.taskManager().getPendingTasks();
        entries.ensureCapacity(pendingTasks.size());
        listGBC.gridx = 0;
        listGBC.gridy = 0;
        listGBC.fill = GridBagConstraints.HORIZONTAL;
        listGBC.anchor = GridBagConstraints.NORTHWEST;
        listGBC.weightx = 1;
        
        for (Task t : pendingTasks) {
            TaskEntry e = new TaskEntry(t).initialize();
            entries.add(e);
            listPanel.add(e, listGBC);
            listGBC.gridy++;
        }
        
        setSelectedEntry(null);
        return this;
    }
    
    /**
     * Sets the selected TaskEntry on this TaskControlPanel.
     * @param entry the TaskEntry to select
     */
    public void setSelectedEntry(TaskEntry entry) {
         if (entry != null) {
             entry.setSelected(true);
         }
         selected.setSelected(false);
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
    public void updateList() {
        entries.clear();
        // Store the selected Task to try and match the Task to a Task in the 
        // updated list of tasks. This provides a smoother experience when 
        // performing operations on the Task queue.
        Task selectedTask = (selected == null ? null : selected.getTask());
        setSelectedEntry(null);
        listPanel.removeAll();
        TaskEntry newSelection = null;
        listGBC.gridy = 0;
        for (Task t : pg.taskManager().getPendingTasks()) {
            TaskEntry e = new TaskEntry(t).initialize();
            entries.add(e);
            add(e, listGBC);
            listGBC.gridy++;
            // if the current Task is equal to the previously selected Task,
            // we take the current TaskEntry as the new selection.
            if (t.equals(selectedTask)) {
                newSelection = e;
            }
        }
        // add a filler component to the listPanel to push the TaskEntries to 
        // the top of the listPanel. Otherwise the GridBagLayout will center
        // them on screen. Because the size is set 
        listGBC.fill = GridBagConstraints.BOTH;
        listGBC.weighty = 1;
        add(new Container(), listGBC);
        listGBC.weighty = 0;
        listGBC.fill = GridBagConstraints.HORIZONTAL;
        
        // restore the original selection
        setSelectedEntry(newSelection);
    }
    
    /**
     * Updates the information of the selected TaskEntry.
     * <p/>
     * When no entry is selected, the text fields will be set to a generic 
     * value and the control buttons will be disabled.
     */
    public void updateTaskData() {
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
            Plugin p = pg.lookupPluginForTask(t);
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
    public class TaskEntry extends JPanel {

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

        /**
         * Setup the TaskControlPanel.
         * @return itself for fluency.
         */
        public TaskEntry initialize() {
            setBackground(Color.WHITE);
            setBorder(new LineBorder(Color.BLACK));
            
            Icon image = pg.lookupPluginForTask(task).getPluginIcon();
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
