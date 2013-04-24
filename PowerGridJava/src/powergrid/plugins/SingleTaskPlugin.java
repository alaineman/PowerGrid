package powergrid.plugins;

import java.util.Arrays;
import java.util.Collection;
import javax.swing.ImageIcon;
import powergrid.PowerGrid;
import powergrid.task.Task;

/**
 * This class is a convenience class for defining Plugins that only provide one
 * Task. 
 * <p/>
 * The supported Class object must be passed into this Plugin's constructor.
 * Then, the <code>getInstance()</code> method must be implemented to return
 * a new instance of the supported Task class.
 * <p/>
 * Other methods, like <code>getPluginIcon()</code>, or the <code>setUp()</code>
 * and <code>tearDown()</code> methods, are optional and have a minimalistic 
 * behavior by default.
 * @param <T> the single Task type this Plugin provides
 * @author Chronio
 */
public abstract class SingleTaskPlugin<T extends Task> implements Plugin {
    
    private PowerGrid powergrid = null;
    private Class<T> clazz;
    
    public SingleTaskPlugin(Class<T> clazz) {
        if (clazz == null) {
            throw new IllegalArgumentException("Not a Task subclass");
        }
        this.clazz = clazz;
    }
    
    @Override
    public ImageIcon getPluginIcon() {
        return null;
    }

    @Override
    public void withPowerGrid(PowerGrid pg) {
        assert pg != null && powergrid == null;
        powergrid = pg;
    }

    @Override
    public void setUp() {}

    @Override
    public Collection<Class> getPublicTasks() {
        return Arrays.asList(new Class[] {clazz});
    }

    /**
     * Asserts that the provided Class is supported by this Plugin and returns 
     * an instance of the specified Class.
     * <p/>
     * An UnsupportedOperationException will be thrown if the provided Class 
     * object does not equal the Class object contained in this 
     * SingleTaskPlugin.
     * @param <N> the type of the expected returned Task
     * @param clazz the Class object representing the type
     * @return an instance of the provided Class
     */
    @Override
    public <N extends Task> N instantiate(Class<N> clazz) {
        if (!this.clazz.equals(clazz)) {
            throw new UnsupportedOperationException("Unsupported Class");
        } 
        /* We know the cast is allowed, since an UnsupportedOperationException
         * would already have been thrown if the method's type (N) was not the 
         * same as the Class' type (T).
         */
        return (N) getInstance();
    }
    
    /**
     * Creates and returns an instance of the single Task class this Plugin 
     * provides.
     * <p/>
     * This method should never fail. To be more precise, this method should 
     * not return null or throw an Exception.
     * @return an instance of the single Task class this Plugin provides
     */
    public abstract T getInstance();

    /**
     * Called when PowerGrid unloads.
     * <p/>
     * This method does nothing by default.
     */
    @Override
    public void tearDown() {}
    
}
