package powergrid.model.world.resource;

import powergrid.model.item.Item;
import powergrid.model.world.player.Skill;

/**
 *
 * @author Alaineman
 */
public class Ore extends ResourceTile {
    
    public Ore(int x, int y, int rawValue, Item... it) {
        super(x, y, rawValue, it);
    }

    @Override
    public void gather() {
        if (canGather()) {
            // interact(); << Why is a Resource tile not Interactable? I must disagree!
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
