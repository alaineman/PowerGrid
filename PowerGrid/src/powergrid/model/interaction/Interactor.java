package powergrid.model.interaction;

import java.util.Iterator;
import java.util.Objects;
import java.util.Set;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;

/**
 * Abstract class that defines methods that allows interaction with a certain
 * kind of object.
 * <p/>
 * @author Chronio
 */
public abstract class Interactor {
    
    private WorldMap map = null;
    private RSInteractor interactor = null;
    
    /**
     * Creates a new Interactor, which uses the specified Client
     * @param theClient the Runescape client this Interactor connects to
     * @param map the WorldMap on which this Interactor works
     */
    public Interactor(WorldMap map, RSInteractor i) {
        this.map = map;
        this.interactor = i;
    }

    /**
     * Returns the WorldMap instance associated with this Interactor.
     * @return the WorldMap instance associated with this Interactor
     */
    public WorldMap getMap() {
        return map;
    }
    
    /**
     * Returns the RSInteractor that is used for interaction with the Runescape
     * GUI.
     * @return the RSInteractor instance
     */
    public RSInteractor getInteractor() {
        return interactor;
    }
    
    /**
     * Returns an array containing the actions this Interactor can perform on
     * the given object.
     * <p/>
     * This does not have to be equal to the possible actions in the Runescape
     * environment, it simply means this Interactor can handle the operation.
     * <p/>
     * @param elem the element to check the actions for
     * @return an array containing the 
     */
    public abstract Set<?> getOptions(Object elem);
    
    /**
     * Interacts with the element using the default action.
     * <p/>
     * The Interactor is free to decide what the default action is, but it 
     * should generally be the default action in the Runescape environment to
     * avoid confusion.
     * <p/>
     * @param elem the element to interact with
     * @return whether the interaction was successful
     * @throws OutOfReachException when the element cannot be reached
     */
    public boolean interact(Object elem) throws OutOfReachException {
        Set<?> options = getOptions(elem);
        if (options.isEmpty()) {
            return false;
        } else {
            Iterator it = options.iterator();
            return interact(elem,it.next());
        }
    };
    
    /**
     * Interacts with the element using the given option.
     * @param elem the element to interact with
     * @param option the option that goes with the interaction
     * @return whether the interaction was successful
     * @throws OutOfReachException when the element cannot be reached
     */
    public abstract boolean interact(Object elem, Object option) throws OutOfReachException;
    
    /**
     * Returns an array of all classes this Interactor can handle.
     * <p/>
     * When including a class in this method's result array, the Interactor 
     * must make sure that it accepts at least one interaction method for that 
     * type.
     * @return 
     */
    public abstract Set<Class<?>> getTypes();
    
    /**
     * Returns whether this Interactor should be preferred over another.
     * <p/>
     * The InteractionManager will take the result call of this method into 
     * account when selecting the most appropriate Interactor for a certain 
     * object.
     * <p/>
     * This method should check compatibility carefully, and not simply return 
     * true.
     * <p/>
     * The InteractionManager wil consider this Interactor to be more suited to
     * handling the interaction when this method returns true, and the other 
     * interactor's <code>isMoreFavorableThan</code> method returns false.
     * When both interactors give the same answer, they will be considered 
     * equal and the one chosen to perform the interaction is undefined.
     * <p/>
     * @param i the other Interactor
     * @param elem the object for which 
     * @return whether this Interactor is more suited to handling the given 
     *         object's interactions.
     */
    public abstract boolean isMoreFavorableThan(Interactor i, Object elem);
    
    @Override public int hashCode() {
        return 5 + 3 * Objects.hashCode(getTypes());
    }
    
    /**
     * Checks whether this Interactor is equal to another Object.
     * <p/>
     * This method returns true if each of the following is true:
     * <ul>
     *   <li>the Object is an Interactor instance</li>
     *   <li>the Set of accepted classes contains the exact same elements for 
     *       both this Interactor and the other Interactor</li>
     * </ul>
     * @param other the Object to check equality with
     * @return whether this Interactor is equal to the given Object
     */
    @Override public boolean equals(Object other) {
        if (other instanceof Interactor) {
            Interactor that = (Interactor) other;
            Set<Class<?>> mine = this.getTypes();
            Set<Class<?>> theirs = that.getTypes();
            return mine.equals(theirs);
        }
        return false;
    }
    
    @Override public String toString() {
        String lead = getClass().getSimpleName() + "(";
        Set<Class<?>> types = getTypes();
        if (types.isEmpty()) {
            return lead + "empty)";
        }
        String classes = "";
        for (Class c : types) {
            classes += "," + c.getSimpleName();
        }
        return lead + classes.substring(1) + ")";
    }
}
