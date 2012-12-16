package powerwalk.model.interact;

import java.util.HashMap;
import org.powerbot.game.api.methods.tab.Quest;
import powerwalk.model.GameObject;
import powerwalk.model.Item;
import powerwalk.model.OutOfReachException;

/**
 * @author P.Kramer
 * @author Alaineman
 */
public abstract class Teleportable extends GameObject implements ComplexInteractable {
    
    
    /**
     * 
     * @param x
     * @param y
     * @param z
     * @param rawNumber 
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
     * 
     * @throws OutOfReachException 
     */
    public abstract void follow() throws OutOfReachException;
    
    
    @Override
    public void interact() throws OutOfReachException {
        follow();
    }
    
    @Override
    public void interact(String method) throws OutOfReachException {
        follow();
    }
    
    /**
     * Returns the Quests needed for this Teleprotable.
     * @return the required Quests.
     */
    public Quest[] getRequiredQuests() {
        return new Quest[0];
    }
    
}
