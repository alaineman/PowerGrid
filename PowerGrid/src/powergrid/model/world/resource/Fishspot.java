package powergrid.model.world.resource;

import powergrid.model.item.Item;
import powergrid.model.world.player.Skill;

/**
 *
 * @author Alaineman
 */
public class Fishspot extends ResourceTile {
    
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

    @Override
    public boolean requirementMet(Skill object, Object option) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
