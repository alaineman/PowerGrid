package powergrid.view;

import javax.swing.JPanel;
import powergrid.task.Configurable;

/**
 * This abstract class is meant as a supertype for the configuration panel of Tasks.
 * @author Chronio
 */
public class TaskConfigurationPanel extends JPanel {
    
    /** The Task that this TaskConfigurationPanel configures. */
    protected Configurable task = null;
    
    /** Create a new TaskConfigurationPanel that configures the given Task. */
    public TaskConfigurationPanel(Configurable t) {
        this.task = t;
    }
    
    /** Retrieve the Task that this method configures. 
     * @return the Task that this method configures.
     */ 
    public Configurable getTask() {
        configure();
        return task;
    }
    
    /** Called before Task is run to ensure that the Task is properly configured.
     *  <p/>
     *  Subclasses should override this method to update the settings and 
     *  configuration of the Task to match that of the configuration settings.
     */
    public void configure() {}
    
    /**
     * Called to indicate that the configuration is canceled. 
     * <p/> 
     * The Task will not be run after this method has been called, and as such it
     * can serve as a clean up. The TaskConfigurationPanel will be discarded after this method returns.
     */
    public void cancel() {}
    
    /**
     * Returns the title for this TaskConfigurationPanel. It will be shown on the
     * ConfigureFrame that contains this TaskConfigurationPanel. The default value 
     * is "Configure Task".
     * <p/>
     * Override this method for a custom title.
     * <p/>
     * @return the String "Configure Task"
     */
    public String getTitle() {
        return "Configure Task";
    }
}
