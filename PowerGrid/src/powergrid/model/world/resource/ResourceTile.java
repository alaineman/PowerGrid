package powergrid.model.world.resource;

import powergrid.model.Point;
import powergrid.model.item.Item;
import powergrid.model.rsbot.RSGroundImpl;
import powergrid.model.world.GameTile;

/**
 *
 * @author Alaineman
 */
public abstract class ResourceTile extends GameTile {
        
    private Item[] items;
    
    public ResourceTile(int x, int y, int rawValue, Item... it){
        super(new Point(x,y), new RSGroundImpl(rawValue), -1);
        items = new Item[it.length];
        System.arraycopy(it, 0, items, 0, it.length);
    }
    
    public abstract void gather();
    
    public abstract boolean isAvailable();
    
    public Item[] getItems() {
        Item[] its = new Item[items.length];
        System.arraycopy(items, 0, its, 0, items.length);
        return its;
    }
    
    public abstract boolean canGather();
}
