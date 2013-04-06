package powergrid.view.status;

import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import powergrid.PowerGrid;
import powergrid.control.listener.TaskListener;
import powergrid.task.Task;

/**
 * Panel that offers functionality to monitor and modify the task queue of
 * PowerGrid.
 *
 * @author Vincent W
 */
public class TaskControlPanel extends JPanel {

    private PowerGrid pg;
    private JTextArea besch;
    private JButton removeButton;
    private JButton moveUpButton;
    private JButton moveDownButton;
    private JButton onHoldButton;
    private JScrollPane scrolly;
    private JPanel listPanel;

    /**
     * Creates a new TaskControlPanel.
     */
    public TaskControlPanel() {
        super(new BorderLayout());
        pg = null;
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
     * @return PowerGrid instance.
     */
    public PowerGrid getPowerGrid() {
        return pg;
    }

    /**
     * Setup to the TaskControlPanel.
     *
     * @return Itself.
     */
    public TaskControlPanel initialize() {
        setPreferredSize(null);
        pg.taskManager().addTaskListener(new TaskListener() {
            @Override
            public void taskAdded(Task t) {
            }

            @Override
            public void taskRemoved(Task t) {
            }

            @Override
            public void taskStarted(Task t) {
            }

            @Override
            public void taskFinished(Task t) {
            }
        });
        return this;


    }

    /**
     * Represents a Task object.
     */
    public class TaskEntry extends JPanel {

        private Task task;

        /**
         * Creates a Task object.
         */
        public TaskEntry(Task t) {
            assert t != null;
            task = t;
        }

        /**
         * Setup to the TaskControlPanel.
         * @return Itself.
         */
        public TaskEntry initialize() {
            return this;
        }
    }
}
