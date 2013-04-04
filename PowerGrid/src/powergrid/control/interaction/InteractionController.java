package powergrid.control.interaction;

import java.util.HashMap;
import java.util.Iterator;
import powergrid.model.OutOfReachException;

/**
 * Class that handles all interactions with GameTiles.
 * <p/>
 * This class maintains a Map mapping Classes to Interactors. When the interact
 * method is invoked, the InteractionController finds the closest matching 
 * Interactor to perform the interaction with.
 * <p/>
 * The InteractionController first checks the class of the Object to interact 
 * with. If an Interactor exists for that class, that Interactor will be used.
 * If such an Interactor does not exist, the InteractionController will check
 * all interfaces that the Object's class implements for matching Interactors.
 * If after that, there is still no matching Interactor, the 
 * InteractionController will check the Object's superclasses one by one for 
 * a matching Interactor. If no Interactor is found, null is returned.
 * <p/>
 * @see Interactor for more information on how Interactors work
 * @author Chronio
 */
public class InteractionController {
    private HashMap<Class<?>,Interactor> types = new HashMap<>();
    private Interactor defaultInteractor = null;
    
    /**
     * Sets the default Interactor that is used when no other Interactor is 
     * available. 
     * <p/>
     * The provided Interactor should be able to handle as many types as 
     * possible.
     * <p/>
     * @param i the default Interactor to use.
     */
    public void useDefault(Interactor i) {
        defaultInteractor = i;
    }
    
    public Interactor getDefault() {
        return defaultInteractor;
    }
    
    /**
     * Adds an Interactor to the InteractionController. 
     * <p/>
     * The InteractionController will match this Iterator against other 
     * Iterators that cover the same classes, to decide which Interactor to
     * use.
     * <p/>
     * @param i the Interactor to add
     * @return true if the Interactor was added and is used for at least one 
     *         class, false otherwise.
     */
    public boolean addInteractor(Interactor i) {
        if (i == null) {
            return false;
        }
        boolean used = false;
        for (Class c : i.getTypes()) {
            Interactor original = types.get(c);
            if (original == null) {
                // update when no Interactor exists yet
                used = true;
                types.put(c,i);
            } else {
                boolean preferOld = original.isMoreFavorableThan(i, c);
                boolean preferNew = i.isMoreFavorableThan(original, c);
                // update when prefer new, or don't care
                if ((!preferOld && preferNew) || (preferOld == preferNew)) {
                    used = true;
                    types.put(c, i);
                }
            }
            
        }
        return used;
    }
    
    /**
     * Removes the provided Interactor from all it's connected classes.
     * <p/>
     * Note that this sets the Interactor for the  
     * @param i
     * @return 
     */
    public boolean removeInteractor(Interactor i) {
        int oldSize = types.size();
        Iterator<Interactor> it = types.values().iterator();
        while (it.hasNext()) {
            if (it.next().equals(i)) {
                it.remove();
            }
        }
        return oldSize != types.size();
    }
    
    /**
     * Interacts with the provided Object.
     * <p/>
     * The InteractionController automatically selects the appropriate
     * Interactor based on the provided Object's class.
     * <p/>
     * @param o the Object to interact with
     * @return whether the interaction was successful
     * @throws OutOfReachException when the Object could not be reached
     */
    public boolean interact(Object o) throws OutOfReachException {
        Interactor i = findInteractor(o.getClass());
        if (i == null) {
            i = getDefault();
            if (i == null) {
                return false;
            }
        }
        return i.interact(o);
    }
    
    /**
     * Interacts with the provided Object using the given option.
     * <p/>
     * The InteractionController automatically selects the appropriate
     * Interactor based on the provided Object's class.
     * <p/>
     * The option will be passed on to the selected Interactor
     * <p/>
     * @param o the Object to interact with
     * @param option the option to use
     * @return whether the interaction was successful
     * @throws OutOfReachException when the Object could not be reached
     */
    public boolean interact(Object o, Object option) 
            throws OutOfReachException {
        Interactor i = findInteractor(o.getClass());
        if (i == null) {
            i = getDefault();
            if (i == null) {
                return false;
            }
        }
        return i.interact(o, option);
    }
    
    /**
     * Returns the Interactor that is used for the given Class.
     * <p/>
     * This method navigates up the Class tree, also checking interfaces.
     * <p/>
     * Interfaces are checked before the superclass, so if an Interactor exists 
     * for both the superclass and an interface, the Interactor for the 
     * interface is returned.
     * <p/>
     * @param c the Class to look up.
     * @return the Interactor used for this Class, or null if no Interactor for 
     *         that Class exists.
     */
    public Interactor findInteractor(Class<?> c) {
        Interactor in = types.get(c);
        if (in == null) {
            Class<?>[] ifs = c.getInterfaces();
            for (Class<?> i : ifs) {
                in = types.get(i);
                if (in != null) {
                    return in;
                }
            }
            c = c.getSuperclass();
            while (c != null) {
                in = types.get(c);
                if (in != null) {
                    return in;
                }
                c = c.getSuperclass();
            }
        } else {
            return in;
        }
        return null;
    }
}
