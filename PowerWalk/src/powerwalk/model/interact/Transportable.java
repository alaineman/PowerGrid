/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import org.powerbot.game.api.methods.tab.Quest;
import powerwalk.model.GameObject;
import powerwalk.model.Item;

/**
 * Represents a GameObject that allows a transport to another Transportable.
 * @author Alaineman
 * @author P.Kramer
 */
public abstract class Transportable extends Teleportable {
    
    /**
     * 
     */
    private ArrayList<Transportable> destinations;
    
    /**
     * 
     * @param x
     * @param y
     * @param z
     * @param rawNumber
     * @param dests 
     */
    public Transportable(int x,int y,int z,int rawNumber, Collection<Transportable> dests) {
        super(x, y, z, rawNumber);
        destinations = new ArrayList<>(dests);
    }    
    
    /**
     * Teleports you to the designated Point.
     * @throws OutOfReachException when the requirements are not met.
     * @param dest the Point of destination.
     */
    public abstract void follow(String dest);
    
    /**
     * Returns available destinations for this Transportable.
     * @return available destinations.
     */
    public Transportable[] getDestinations(){
        return destinations.toArray(new Transportable[0]);
    };
            
}
