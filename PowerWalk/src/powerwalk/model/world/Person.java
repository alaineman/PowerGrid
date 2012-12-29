package powerwalk.model.world;

import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powerwalk.model.OutOfReachException;

/**
 * This class represents a mobile, non-aggressive object in the RSBot environment that can be interacted with.
 * @author Chronio
 */
public class Person extends Entity {

    /**
     *
     */
    public static final int[] pValues = new int[] {};
    
    /**
     * Creates a new Person at the given position. the <code>rawValue</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param z the z-coordinate of this object
     * @param rawValue the raw value from the environment specifying the type
     */
    public Person(int x,int y, int z, int rawValue) {
        super(x,y,z,rawValue);
    }
    
    /**
     * Interacts with this Person using the default method.
     * <p>For most Characters, the default interaction method is "talk to" or "speak to".</p>
     * @throws OutOfReachException when the interaction could not be completed
     * @throws UnsupportedOperationException when this person has no interactions
     */
    @Override public void interact() throws OutOfReachException {
        NPC theNpc = NPCs.getNearest(getRawNumber());
        if (theNpc == null) {
            throw new OutOfReachException(getPosition(),"No Person like this nearby");
        }
        String[] actions = theNpc.getActions();
        if (actions.length > 0) {
            theNpc.interact(actions[0]);
        } else {
            throw new UnsupportedOperationException("This Person has no interactions");
        }
    }
    
    /**
     * This method tries the first method of interaction that this Person can 
     * perform that contains either "talk" or "speak".
     * @throws OutOfReachException when the Person is not nearby.
     * @throws UnsupportedOperationException when no suitable method was found.
     */
    public void talkTo() throws OutOfReachException {
        NPC theNpc = NPCs.getNearest(getRawNumber());
        if (theNpc == null) {
            throw new OutOfReachException(getPosition(),"No Person like this nearby");
        }
        String[] actions = theNpc.getActions();
        for (String action : actions) {
            if (action.contains("talk") || action.contains("speak")) {
                theNpc.interact(action);
                return;
            }
        }
        throw new UnsupportedOperationException("No talk or speak method for this Person");
    }

    /**
     * Interacts with this Person using the given method
     * @param method the method of interaction
     * @throws OutOfReachException when the interaction could not be completed
     * @throws UnsupportedOperationException when the provided method cannot be used for this Person
     */
    @Override public void interact(String method) throws OutOfReachException {
        NPC theNpc = NPCs.getNearest(getRawNumber());
        if (theNpc == null) {
            throw new OutOfReachException(getPosition(),"No Person like this nearby");
        }
        if (!theNpc.interact(method)) {
            throw new UnsupportedOperationException("The interact could not be performed.");
        }
    }
    
}
