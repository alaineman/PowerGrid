/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact;

import java.util.HashMap;
import org.powerbot.game.api.methods.tab.Quest;
import powerwalk.model.GameObject;
import powerwalk.model.Item;
import powerwalk.model.OutOfReachException;

/**
 *
 * @author vync job
 */
public abstract class Teleportable extends GameObject implements ComplexInteractable {
    
    
    
    public Teleportable(int x,int y,int z,int rawNumber){
        super(x, y, z, rawNumber);
        
    }
    
    /**
     * Cost to perform this transport.
     * @return a Map containing the required Items for the transport.
     */
    public abstract HashMap<Item, Integer> getCost();
    
    public abstract void follow() throws OutOfReachException;
    
    /**
     * Returns the Quests needed for this Teleprotable.
     * @return the required Quests.
     */
    public abstract Quest[] getRequiredQuests();
    
}
