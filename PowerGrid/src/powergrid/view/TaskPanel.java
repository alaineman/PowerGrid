package powergrid.view;

import java.awt.BorderLayout;
import java.util.ArrayList;
import javax.swing.JPanel;
import powergrid.PowerGrid;
import powergrid.plugins.Plugin;
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
}
