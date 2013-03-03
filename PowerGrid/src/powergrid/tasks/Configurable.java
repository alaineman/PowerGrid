package powergrid.tasks;

import powergrid.view.TaskConfigurationPanel;

/**
 * This interface represents Tasks that need or can be configured before use.
 * <p/>
 * It requires the Task to provide a configuration panel that provides options 
 * and information on how to use the plugin. These options will be shown in a 
 * separate frame before the Task is run.
 * <p/>
 * PowerGrid supplies a run and cancel button, and calls the <code>apply()</code> 
 * method when the user clicks the run button. When the cancel button is clicked, 
 * PowerGrid calls the <code>configCanceled()</code> method before discarding the 
 * configuration panel.
 * <p/>
 * @author Chronio
 */
public interface Configurable {
    /**
     * Returns a JPanel that contains options / information for the Task.
     * @return a configuration panel.
     */
    public TaskConfigurationPanel configPanel();
    
    /**
     * Called by PowerGrid to indicate that the Task should parse the configuration 
     * panel's data and save the configuration settings.
     * <p/>
     * After this method returns, the Task will be automatically assigned to the 
     * TaskManager.
     */
    public void apply();
    
    /**
     * Called by PowerGrid to indicate the configuration panel is closed without 
     * running the Task.
     */
    public void configCanceled();
}
