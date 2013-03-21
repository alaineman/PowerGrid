
package powergrid.model.world.resource;

import powergrid.model.Item;

/**
 *
 * @author Alaineman
 */
public class Tree extends AbstractResource {
    
    public Tree(int x, int y, int rawValue, Item... it) {
        super(x, y, rawValue, it);
    }

    @Override
    public void gather() {
        if (canGather()) {
            //get id and interact "chop"
        }
    }

    @Override
    public boolean isAvailable() {
        return true;
    }

    @Override
    public boolean canGather() {
        if (isAvailable()) return true;
        return false;
    }
    
}
