package powergrid.control.interaction;

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
 * An Interactor is an Object that can handle interactions with certain Object 
 * types.
 * <p/>
 * They are used throughout PowerGrid to interact with Objects in the Runescape
 * environment.
 * @author Chronio
 */
public abstract class Interactor {
    
    private WorldMap map = null;
    private RSInteractor interactor = null;
    
    /**
     * Creates a new Interactor, which uses the specified Client
     * @param i the RSInteractor this Interactor connects to
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
     * Returns a Set containing the actions this Interactor can perform on
     * the given object.
     * <p/>
     * This does not have to be equal to the possible actions in the Runescape
     * environment, it simply means this Interactor can handle the operation.
     * However, to avoid confusion, it is highly recommended to stick to the 
     * options as given in the Runescape environment.
     * <p/>
     * This method may throw an IllegalArgumentException when the provided 
     * Object is not supported.
     * <p/>
     * @param elem the element to check the actions for
     * @return an array containing the options for the provided Object
     * @throws IllegalArgumentException when the Interactor does not provide
     *                                  support for the provided Object.
     */
    public abstract Set<?> getOptions(Object elem);
    
    /**
     * Interacts with the element using the default action.
     * <p/>
     * The Interactor is free to decide what the default action is, but it 
     * should generally be the default action in the Runescape environment to
     * avoid confusion. When a subclass does not map this method call to the 
     * default action in Runescape, the method's documentation should state
     * that the action performed is inconsistent with the default action in 
     * the Runescape environment.
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
     * Returns a set of the classes this Interactor can handle.
     * <p/>
     * When including a class in this method's result set, the Interactor 
     * must make sure that it accepts at least one interaction method for that 
     * type.
     * @return a set containing the Classes this Interactor can handle.
     */
    public abstract Set<Class<?>> getTypes();
    
    /**
     * Returns whether this Interactor should be preferred over another.
     * <p/>
     * The InteractionController will take the result of this method into 
     * account when selecting the most appropriate Interactor for a certain 
     * object class.
     * <p/>
     * The default implementation checks compatibility based on the most 
     * specific matching class. However, interfaces are not taken account for. 
     * Therefore, when result set of the getTypes method of an Interactor 
     * subclass contains an interface class object, that Interactor should 
     * override this method to provide suitable support for checking 
     * compatibility.
     * <p/>
     * @param i the other Interactor
     * @param c the Class for which to check
     * @return whether this Interactor is more suited to handling interactions 
     *         for the given class.
     */
    public boolean isMoreFavorableThan(Interactor i, Class<?> c) {
        if (i == null) {
            return true;
        } else if (c == null) {
            return false;
        }
        Set<Class<?>> myTypes = getTypes();
        Set<Class<?>> hisTypes = i.getTypes();
        Class<?> myClass = null, hisClass = null;
        // Select the most appropriate class from my classes
        for (Class<?> clazz : myTypes) {
            if (clazz.isAssignableFrom(c)) {
                if (myClass == null || myClass.isAssignableFrom(clazz)) {
                    myClass = clazz;
                }
            }
        }
        // Select the most appriopriate class from his classes
        for (Class<?> clazz : hisTypes) {
            if (clazz.isAssignableFrom(c)) {
                if (hisClass == null || hisClass.isAssignableFrom(clazz)) {
                    hisClass = clazz;
                }
            }
        }
        // Compare results
        if (myClass == null) {
            return false;
        } else if (hisClass == null) {
            return true;
        } else {
            return hisClass.isAssignableFrom(myClass);
        }
    }
    
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
