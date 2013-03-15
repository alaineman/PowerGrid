package powergrid.model.world;

import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powergrid.model.GameTile;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.interact.Interactable;

/**
 * Class representing mobile objects from the RSBot environment
 * @author Chronio
 */
public abstract class Entity extends GameTile implements Interactable {
        
    /**
     * Creates a new Entity at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param z the z-coordinate of this object
     * @param rawValue the raw value from the environment specifying the type
     */
    protected Entity(int x,int y,int z,int rawValue) {
        super(new Point(x,y,z),rawValue);
    }
    
    /**
     * Interacts with this Entity using the default method.
     * @throws OutOfReachException when the interaction could not be completed
     * @throws UnsupportedOperationException when this Entity has no interactions,
     *                                       or when the interaction could not be completed
     */
    @Override public void interact() throws OutOfReachException {
        NPC theNpc = NPCs.getNearest(getRawNumber());
        if (theNpc == null)
            throw new OutOfReachException(getPosition(),"No " + getClass().getSimpleName() + " like this nearby");
        String[] actions = theNpc.getActions();
        if (actions.length == 0)
            throw new UnsupportedOperationException("This " + getClass().getSimpleName() + " has no interactions");
        if (!theNpc.interact(actions[0]))
            throw new UnsupportedOperationException("The action failed");
    }
    
    /**
     * Interacts with this Entity using the given method
     * @param method the method of interaction
     * @throws OutOfReachException when the interaction could not be completed
     * @throws UnsupportedOperationException when the provided method cannot be used for this Entity
     */
    @Override public void interact(String method) throws OutOfReachException {
        NPC theNpc = NPCs.getNearest(getRawNumber());
        if (theNpc == null)
            throw new OutOfReachException(getPosition(),"No Person like this nearby");
        if (!theNpc.interact(method))
            throw new UnsupportedOperationException("The interact could not be performed.");
    }
    
    /**
     * returns the available actions for this Entity.
     * <p>When the entity is not currently loaded, this method returns an empty array.
     * @return the available actions for this Entity.
     */
    public String[] getInteractMethods() {
        NPC theNPC = NPCs.getNearest(getRawNumber());
        if (theNPC == null)
            return new String[0];
        return theNPC.getActions();
    }
}
