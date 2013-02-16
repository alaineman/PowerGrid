package powerwalk.model.world;

import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powerwalk.model.OutOfReachException;

/**
 * This class represents a mobile, non-aggressive Entity in the RSBot environment 
 * that can be interacted with.
 * @author Chronio
 */
public class Person extends Entity {

    /**
     * Values that specifically define Persons or NPCs in the RSBot environment.
     */
    public static final int[] values = new int[] {};
    
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
        for (String action : getInteractMethods()) {
            if (action.contains("talk") || action.contains("speak")) {
                theNpc.interact(action);
                return;
            }
        }
        throw new UnsupportedOperationException("No talk or speak method for this Person");
    }
    
}
