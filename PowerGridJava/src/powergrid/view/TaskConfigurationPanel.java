package powergrid.view;

import javax.swing.JPanel;
import powergrid.task.Configurable;

/**
 * This class is meant as a supertype for the configuration panel of Tasks.
 * @author Chronio
 */
public class TaskConfigurationPanel extends JPanel {
    
    /**
     * The default title for TaskConfigurationPanels.
     */
    public static final String DEFAULT_TITLE = "Configure Task";
    
    /** The Task that this TaskConfigurationPanel configures. */
    private Configurable task = null;
    
    /** 
     * Create a new TaskConfigurationPanel that configures the given Task. 
     */
    public TaskConfigurationPanel(Configurable t) {
        this.task = t;
    }
    
    /** 
     * Configures and returns the Task that this TaskConfigurationPanel 
     * configures. 
     * @return the Task that this method configures.
     */ 
    public Configurable getTask() {
        configure();
        return task;
    }
    
    /** 
     * Called before Task is run to ensure that the Task is properly 
     * configured.
     *  <p/>
     *  Subclasses should override this method to update the settings and 
     *  configuration of the Task to match that of the configuration settings.
     */
    public void configure() {}
    
    /**
     * Called to indicate that the configuration is canceled. 
     * <p/> 
     * The Task will not be run after this method has been called, and as such 
     * it can serve as a clean up. The TaskConfigurationPanel will be discarded
     * after this method returns.
     */
    public void cancel() {}
    
    /**
     * Returns the title for this TaskConfigurationPanel. It will be shown on 
     * the ConfigureFrame that contains this TaskConfigurationPanel. The 
     * default value is the String in <code>DEFAULT_TITLE</code>.
     * <p/>
     * Override this method for a custom title.
     * <p/>
     * @return <code>DEFAULT_TITLE</code>
     */
    public String getTitle() {
        return DEFAULT_TITLE;
    }
}
