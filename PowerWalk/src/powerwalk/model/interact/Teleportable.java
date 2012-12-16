package powerwalk.model.interact;

import java.util.HashMap;
import org.powerbot.game.api.methods.tab.Quest;
import powerwalk.model.GameObject;
import powerwalk.model.Item;
import powerwalk.model.OutOfReachException;

/**
 * Represents a GameObject that can be teleported to.
 * @author P.Kramer
 * @author Alaineman
 */
public abstract class Teleportable extends GameObject implements ComplexInteractable {
    
    /**
     * Creates a new <code>Teleportable</code> at the specified position and with the specified raw value
     * @param x the x-coordinate of the <code>Teleportable</code>
     * @param y the y-coordinate of the <code>Teleportable</code>
     * @param z the z-coordinate of the <code>Teleportable</code>
     * @param rawNumber the raw value for this object from the RSBot environment
     */
    public Teleportable(int x,int y,int z,int rawNumber){
        super(x, y, z, rawNumber);
        
    }
    
    /**
     * Cost to perform this transport.
     * @return a Map containing the required Items for the transport.
     */
   public HashMap<Item, Integer> getCost() {
        return new HashMap<>();
    }
    
    /**
     * Performs the teleport. When the teleport could not be performed, an <code>OutOfReachException</code> will be thrown.
     * @throws OutOfReachException when the teleport could not be performed.
     */
    public abstract void follow() throws OutOfReachException;
    
    
    /**
     * Performs the teleport. When the teleport could not be performed, an <code>OutOfReachException</code> will be thrown.
     * <p>This method is effectively the same as calling <code>follow()</code></p>
     * @throws OutOfReachException when the teleport could not be performed.
     */
    @Override public void interact() throws OutOfReachException {
        follow();
    }
    
    /**
     * Performs the teleport. When the teleport could not be performed, an <code>OutOfReachException</code> will be thrown.
     * <p>This method is effectively the same as calling <code>follow()</code></p>
     * @throws OutOfReachException when the teleport could not be performed.
     * @param method the method of interaction. This is ignored for Teleportables
     */
    @Override public void interact(String method) throws OutOfReachException {
        follow();
    }
    
    /**
     * Returns an array containing the Quests needed for this Teleportable.
     * @return the required Quests.
     */
    public Quest[] getRequiredQuests() {
        return new Quest[0];
    }
    
}
