package powergrid.view;

import java.awt.Component;
import java.awt.LayoutManager;
import javax.swing.JPanel;
import powergrid.PowerGrid;

/**
 * Template JPanel that contains a PowerGrid instance and provides a consistent
 * way of defining Swing user interfaces.
 * <p/>
 * PGPanels are designed to only construct the required objects in the 
 * constructor. Linking the objects and setting up the user interface happens
 * in the <code>initialize()</code> method. This class also provides a way to 
 * pass along the PowerGrid instance in the Swing tree.
 * <p/>
 * The addImpl method has been extended to check if the initialize method has 
 * been called. It throws an IllegalStateException when it has not. The
 * initialize method itself throws an IllegalStateException when the PGPanel
 * already has been initialized, or no PowerGrid instance is set. This 
 * guarantees that the PGPanels are set up correctly before any Components are
 * added. Note that this also means that every add method of this Container
 * will act the same and throw an IllegalStateException when the PGPanel is 
 * not initialized.
 * <p/>
 * It is advised that subclasses override the initialize method and set up 
 * the PGPanel there. Subclasses will have to make a call to the PGPanel's 
 * initialize first, to assert that everything is set up correctly. 
 * <p/>
 * @author Chronio
 */
public class PGPanel extends JPanel {
    
    private PowerGrid powergrid;
    private boolean initialized;
    
    /**
     * Creates a new PGPanel with a FlowLayout.
     */
    public PGPanel() {
        initialized = false;
        powergrid = null;
    }
    
    /**
     * Creates a new PGPanel with the specified LayoutManager.
     * @param lm the LayoutManager to use for this PGPanel
     */
    public PGPanel(LayoutManager lm) {
        super(lm);
        initialized = false;
        powergrid = null;
    }
    
    /**
     * Sets the PowerGrid instance to use for this PGPanel.
     * <p/>
     * If <code>pg == null</code>, or a valid PowerGrid instance has already 
     * been set, this method does nothing.
     * @param pg the PowerGrid instance to use
     * @return itself for fluency
     */
    public PGPanel withPowerGrid(PowerGrid pg) {
        if (powergrid == null && pg != null) {
            powergrid = pg;
        }
        return this;
    }
    
    /**
     * Returns the PowerGrid instance that is used in this PGPanel.
     * @return The PowerGrid instance this PGPanel references
     */
    public PowerGrid getPowerGrid() {
        return powergrid;
    }
    
    /**
     * Returns whether this PGPanel instance is initialized.
     * <p/>
     * A PGPanel is considered initialized when it's <code>initialize</code> 
     * method has been called after setting a valid PowerGrid instance using 
     * <code>withPowerGrid(PowerGrid)</code>.
     * @return true if the PGPanel is initialized, false if it is not.
     */
    public boolean isInitialized() {
        return initialized;
    }
    
    /**
     * Initializes this PGPanel.
     * <p/>
     * When a PGPanel is initialized, Components can be added to the PGPanel.
     * When the initialize method was already called before, this method throws
     * an IllegalStateException.
     * 
     * @return itself for fluency
     * @throws IllegalStateException when <code>getPowerGrid()</code>
     *            returns <code>null</code> or this PGPanel has already been 
     *            initialized.
     */
    public PGPanel initialize() {
        if (getPowerGrid() == null) {
            throw new IllegalStateException("Invalid PowerGrid instance");
        }
        if (isInitialized()) {
            throw new IllegalStateException("Already initialized");
        }
        initialized = true;
        return this;
    }
    
    /**
     * Adds the specified component to this container at the specified
     * index. This method also notifies the layout manager to add
     * the component to this container's layout using the specified
     * constraints object via the <code>addLayoutComponent</code>
     * method.
     * <p/>
     * If the component is not an ancestor of this container and has a non-null
     * parent, it is removed from its current parent before it is added to this
     * container.
     * <p/>
     * This is the method to override if a program needs to track
     * every add request to a container as all other add methods defer
     * to this one. An overriding method should
     * usually include a call to the superclass's version of the method.
     * <p/>
     * This method changes layout-related information, and therefore,
     * invalidates the component hierarchy. If the container has already been
     * displayed, the hierarchy must be validated thereafter in order to
     * display the added component.
     * <p/>
     * In the case of a PGPanel, the addImpl method throws an 
     * IllegalStateException when the PGPanel's initialize method has not been
     * called yet.
     * <p/>
     * If the provided Component is a PGPanel instance, the PGPanel's 
     * <code>withPowerGrid(PowerGrid)</code> method and it's 
     * <code>initialize()</code> method is called before adding the PGPanel 
     * when the PGPanel's <code>isInitialized()</code> method returns false.
     * <p/>
     *
     * @param comp        the component to be added
     * @param constraints an object expressing layout constraints
     *                    for this component
     * @param index       the position in the container's list at which to
     *                    insert the component, where <code>-1</code>
     *                    means append to the end
     * 
     * @throws IllegalArgumentException if the combination of parameters is 
     *            invalid according to the specification of
     *            <code>Container.addImpl(Component, Object, int)</code>
     * @throws NullPointerException if <code>comp == null</code>
     * @throws IllegalStateException if the PGPanel has not yet been 
     *            initialized using the <code>initialize</code> method
     */
    @Override
    protected void addImpl(Component comp, Object constraints, int index) {
        if (!isInitialized()) {
            throw new IllegalStateException("Not initialized yet");
        }
        if (comp instanceof PGPanel) {
            ((PGPanel) comp).withPowerGrid(getPowerGrid()).initialize();
        }
        super.addImpl(comp, constraints, index);
    }
}
