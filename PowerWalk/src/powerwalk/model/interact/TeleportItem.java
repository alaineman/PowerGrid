package powerwalk.model.interact;

import java.util.ArrayList;
import powerwalk.model.Item;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 * Represents an Item that can be used to teleport to one or more locations
 * @author Alaineman
 */
public abstract class TeleportItem extends Item {
    
    protected ArrayList<Destination> destinations = new ArrayList<>();
    
    protected ArrayList<Integer> values = new ArrayList<>();
    
    private String teleportCommand;
        
    /**
     * Creates a new TeleportItem using the given Item from the RSBot API.
     * The provided Item's id will be stored in a list denoting all item id 
     * values that represent the Item in all its possible states
     * @param rsItem 
     */
    public TeleportItem(org.powerbot.game.api.wrappers.node.Item rsItem, String teleportCommand){
        super(rsItem); 
        values.add(rsItem.getId());
        this.teleportCommand = teleportCommand;
    }
    
    /**
     * Returns all Item id values that represent the different states of this TeleportItem
     * @return all Item id values that represent this Item
     */
    public int[] getAllIds() {
        int res[] = new int[values.size()];
        // Because of the stupidest part of Java (Generics), a for loop is 
        // required to "cast" Integer[] to int[] by manual copy
        for (int i=0;i<values.size();i++) {
            res[i] = values.get(i);
        }
        return res;
    }
    
    /**
     * Uses the TeleportItem to travel to the specified destination
     * @param dest the destination to travel to
     * @throws OutOfReachException when the destination cannot be traveled to using this Item
     */
    public boolean use(Point dest) throws OutOfReachException {
        for (Destination d : destinations) {
            if (d.getPosition().equals(dest)) {
                if (d.isAllowed(teleportCommand)) {
                    d.follow();
                    return true;
                }
                return false;
            }
        }
        throw new OutOfReachException(dest,"This point cannot be traveled to.");
    }
    
    /**
     * The <code>Teleportable</code> that is linked to this TeleportItem.
     * <p>subclasses of this class should override this inner class to provide a
     */
    protected static abstract class Destination extends Teleportable{
        
        /**
         * Sets the location for this <code>Destination</code>
         * @param x the x-coordinate of the destination
         * @param y the y-coordinate of the destination
         * @param z the z-coordinate of the destination
         */
        public Destination(int x,int y,int z){
            super(x, y, z, -1);
        }        
    }
}
