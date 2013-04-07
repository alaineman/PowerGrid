package powergrid.model.world.resource;

import powergrid.model.item.Item;

/**
 *
 * @author Alaineman
 */
public class Fishspot extends AbstractResource {
    
    public Fishspot(int x, int y, int rawValue, Item... it) {
        super(x, y, rawValue, it);
    }

    @Override
    public void gather() {
        if (canGather()) {
            // interact
        }
    }

    @Override
    public boolean isAvailable() {
        return true;
    }

    @Override
    public boolean canGather() {
        return isAvailable();
    }
    
}
