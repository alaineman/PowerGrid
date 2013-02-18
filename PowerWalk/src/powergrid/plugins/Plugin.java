package powergrid.plugins;

/**
 * Standard interface for PowerGrid plugins. 
 * <p/>
 * Classes that implement this interface can be loaded and run in PowerGrid.
 * <p/>
 * Important to note, is the onLoad() method. This method is executed as soon as 
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
     * PowerGrid loads available plugins at startup, but does not directly run them.
     * To prevent long startup times, try to execute only small amounts of code here.
     * <p/>
     * Code executed in this method is unaffected by RSBot's SecurityManager.
     */
    public void onLoad();
    
    /**
     * This method is executed when the plugin is started.
     * <p/>
     * Be sure to startup anything the plugin needs in this method. Once this method returns,
     * PowerGrid assumes the plugin is running.
     * <p/>
     * It is allowed to throw an Exception to indicate failure to start. PowerGrid will 
     * then assume the startup failed.
     */
    public void onStart();
    
    /**
     * This method is executed when the plugin is stopped.
     * <p/>
     * This method should reset the state of the plugin, since PowerGrid assumes 
     * stopped plugins can be restarted.
     */
    public void onFinish();
    
    /**
     * This method is called the PowerGrid unloads.
     * <p/>
     * This is also the last chance for the plugin to save data, close streams 
     * and sockets, or clean up any other Objects that need proper finalization.
     */
    public void onUnload();
}
