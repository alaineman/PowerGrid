package powerwalk.model.world.resources;

import powerwalk.model.GameObject;
import powerwalk.model.Item;

/**
 *
 * @author Alaineman
 */
public abstract class AbstractResource extends GameObject {
        
    private Item[] items;
    
    public AbstractResource(int x, int y, int rawValue, Item... it){
        super(x,y,rawValue);
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
