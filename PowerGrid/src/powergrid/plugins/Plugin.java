package powergrid.plugins;

import java.util.Collection;
import powergrid.PowerGrid;
import powergrid.task.Task;

/**
 * Interface for PowerGrid plugins. 
 * <p/>
 * Classes that implement this interface can be loaded and run in PowerGrid.
 * <p/>
 * A plugin can hook custom classes into PowerGrid in the setUp method, which 
 * is executed as soon as the Plugin is loaded in PowerGrid. Similarly, these 
 * classes should be unloaded again in the tearDown method, which is called 
 * when PowerGrid unloads the Plugin. 
 * <p/>
 * @author Chronio
 */
public interface Plugin {
    
    /**
     * This method is executed when the Plugin is loaded.
     * <p/>
     * It serves to provide the PowerGrid instance to the plugin, so that it 
     * can be used to hook custom classes into the framework.
     * @param pg the PowerGrid instance.
     */
    public void withPowerGrid(PowerGrid pg);
    
    /**
     * This method is executed when the plugin is loaded.
     * <p/>
     * PowerGrid loads available plugins at startup. Therefore, to prevent long 
     * startup times, try to execute only small amounts of code here.
     */
    public void setUp();
    
    /**
     * Returns a List of the public Task classes that 
     * <p/>
     * PowerGrid expects a Collection of Tasks that should be provided to the end-user
     * as runnable tasks.
     * @return a Collection of the tasks that PowerGrid is allowed to provide to the user
     */
    public Collection<Class<? extends Task>> getPublicTasks();
    
    /**
     * Creates an instance of the provided Class type.
     * <p/>
     * This method may throw an UnsupportedOperationException when the provided
     * Class cannot be instantiated by this Plugin.
     * <p/>
     * @param clazz the Class Object to instantiate
     * @return an instance of the provided class type
     * @throws UnsupportedOperationException when the provided Class cannot be 
     *                                       instantiated by this Plugin.
     */
    public Task instantiate(Class<? extends Task> clazz); 
    
    /**
     * This method is called when the Plugin is unloaded from PowerGrid.
     * <p/>
     * This is also the last chance for the plugin to save data, close streams 
     * and sockets, or clean up any other Objects that need proper finalization.
     */
    public void tearDown();
}
