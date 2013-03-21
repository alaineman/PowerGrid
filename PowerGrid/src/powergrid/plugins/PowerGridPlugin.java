package powergrid.plugins;

import powergrid.task.TravelNearestTask;
import powergrid.task.Task;
import powergrid.task.RestTask;
import powergrid.task.TravelTask;
import java.util.ArrayList;
import java.util.Collection;
import powergrid.PowerGrid;

/**
 * This class acts as the container for the PowerGrid publicly accessible tasks.
 * <p/>
 * It provides the standard PowerGrid tasks in the same way as external plugins, 
 * meaning they can be handled in the same way.
 * <p/>
 * The publicly accessible tasks that this plugin provides are RestTask, 
 * TravelTask, and TravelNearestTask.
 * <p/>
 * @author Chronio
 */
@PluginInfo(
        name = "PowerGrid default Plugin",
        authors = {"Chronio","Alaineman"},
        description = "The default PowerGrid plugin.",
        version = PowerGrid.VERSION
)
public class PowerGridPlugin implements Plugin {
    @Override public void setUp() {}
    @Override public void onLoad() {}
    @Override public Collection<Class<? extends Task>> getPublicTasks() {
        ArrayList<Class<? extends Task>> tasks = new ArrayList<>();
        tasks.add(RestTask.class);
        tasks.add(TravelNearestTask.class);
        tasks.add(TravelTask.class);
        return tasks;
    }
    @Override public void tearDown() {}
}
