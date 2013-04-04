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
     * This method is executed just after the Plugin is instantiated.
     * <p/>
     * It serves to provide the PowerGrid instance to the plugin, so that it 
     * can be used to hook custom classes into the framework.
     * @param pg the PowerGrid instance.
     */
    public void withPowerGrid(PowerGrid pg);
    
    /**
     * This method is executed when the plugin is loaded.
     * <p/>
     * When the Plugin fails to load, any Exception may be thrown indicating the
     * cause, and PowerGrid will not load the Plugin.
     */
    public void setUp() throws Exception;
    
    /**
     * Returns a List of the public Task classes that 
     * <p/>
     * PowerGrid expects a Collection of Tasks that should be provided to 
     * the end-user as runnable tasks.
     * @return a Collection of the tasks that PowerGrid is allowed to provide 
     *         to the user. This Collection should not be null
     */
    public Collection<Class> getPublicTasks();
    
    /**
     * Creates a Task instance of the provided Class type.
     * <p/>
     * This method may throw an UnsupportedOperationException when the provided
     * Class cannot be instantiated by this Plugin.
     * <p/>
     * This method exists to ensure that custom Tasks can be instantiated 
     * properly, and it provides the freedom to Plugin developers to ensure 
     * that the Tasks are set up correctly before running the Task.
     * <p/>
     * @param clazz the Class Object to instantiate
     * @return a Task instance of the provided class type
     * @throws UnsupportedOperationException when the provided Class cannot be 
     *                                       instantiated by this Plugin.
     */
    public <T extends Task> T instantiate(Class<T> clazz); 
    
    /**
     * This method is called when the Plugin is unloaded from PowerGrid.
     * <p/>
     * The Plugin should remove any custom classes that it previously hooked 
     * into PowerGrid and clean up the Plugin's data. The Plugin should be able 
     * to be set up again when required.
     * <p/>
     * This is also the last chance for the plugin to save data, close streams 
     * and sockets, or clean up any other Objects that need proper finalization.
     * <p/>
     * This method should not throw Exceptions.
     */
    public void tearDown();
}
