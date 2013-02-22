package powergrid.plugins;

import java.util.Collection;
import powergrid.tasks.Task;

/**
 * Standard interface for PowerGrid plugins. 
 * <p/>
 * Classes that implement this interface can be loaded and run in PowerGrid.
 * <p/>
 * Important to note, is the setUp() method. This method is executed as soon as 
 * PowerGrid finds the plugin, which is even before RSBot starts. As such, it is 
 * possible to execute code that would otherwise be prohibited by RSBot's 
 * SecurityManager.
 * <p/>
 * @author Chronio
 */
public interface Plugin {
    /**
     * This method is executed when the plugin is loaded.
     * <p/>
     * PowerGrid loads available plugins at startup. Therefore, to prevent long 
     * startup times, try to execute only small amounts of code here.
     * <p/>
     * Code executed in this method is not restricted by RSBot's SecurityManager.
     * Also, since this method is executed before RSBot loads, some RSBot classes 
     * and methods might not work as expected.
     */
    public void setUp();
    
    /**
     * This method is executed when RSBot has loaded.
     * <p/>
     * This guarantees that RSBot classes are correctly initialized, but it also means 
     * that code executed in this method is restricted by RSBot's SecurityManager.
     * <p/>
     */
    public void onLoad();
    
    /**
     * This method is executed by PowerGrid after the setUp() and onLoad() methods 
     * have been called.
     * <p/>
     * PowerGrid expects a Collection of Tasks that should be provided to the end-user
     * as runnable tasks.
     * @return a Collection of the tasks that PowerGrid is allowed to provide to the user
     */
    public Collection<Class<? extends Task>> getPublicTasks();
    
    
    /**
     * This method is called when PowerGrid unloads and RSBot shuts down.
     * <p/>
     * This is also the last chance for the plugin to save data, close streams 
     * and sockets, or clean up any other Objects that need proper finalization.
     * <p/>
     * Code executed in this method is restricted by RSBot's SecurityManager
     */
    public void tearDown();
}
