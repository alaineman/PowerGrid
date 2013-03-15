/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.interaction;

import java.util.Objects;
import org.powerbot.game.client.Client;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;

/**
 * Abstract class that defines methods that allows interaction with a certain
 * kind of object.
 * <p/>
 * @param T The type of object the Interactor handles
 * @author Chronio
 */
public abstract class Interactor<T> {
    
    private Client client = null;
    private WorldMap map = null;
    
    /**
     * Creates a new Interactor, which uses the specified Client
     * @param theClient the Runescape client this Interactor connects to
     * @param map the WorldMap on which this Interactor works
     */
    public Interactor(Client theClient, WorldMap map) {
        this.client = theClient;
        this.map = map;
    }
    
    /**
     * Returns the client that this Interactor is connected to
     * @return the client
     */
    public Client getClient() {
        return client;
    }

    /**
     * Returns the WorldMap instance associated with this Interactor.
     * @return the WorldMap instance associated with this Interactor
     */
    public WorldMap getMap() {
        return map;
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
    public abstract Object[] getOptions(T elem);
    
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
    public abstract boolean interact(T elem) throws OutOfReachException;
    
    /**
     * Interacts with the element using the given option.
     * @param elem the element to interact with
     * @param option the option that goes with the interaction
     * @return whether the interaction was successful
     * @throws OutOfReachException when the element cannot be reached
     */
    public abstract boolean interact(T elem, Object option) throws OutOfReachException;
    
    /**
     * Returns an array of all classes this Interactor can handle.
     * <p/>
     * When including a class in this method's result array, the Interactor 
     * must make sure that it accepts at least one interaction method for that 
     * type.
     * @return 
     */
    public abstract Class<?>[] getTypes();
    
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
    public abstract boolean isMoreFavorableThan(Interactor i, T elem);
    
    @Override public boolean equals(Object other) {
        if (other instanceof Interactor) {
            Interactor that = (Interactor) other;
            Class<?>[] theirTypes = that.getTypes();
            Class<?>[] myTypes = this.getTypes();
            if (theirTypes.length != myTypes.length) {
                return false;
            }
            for (Class<?> myc : getTypes()) {
                Class<?> match = null;
                for (Class<?> theirc : theirTypes) {
                    if (Objects.equals(myc, theirc)) {
                        match = theirc;
                        break;
                    }
                }
                if (match == null) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
