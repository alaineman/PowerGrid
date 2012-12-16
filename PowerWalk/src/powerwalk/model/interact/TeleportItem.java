package powerwalk.model.interact;

import java.util.ArrayList;
import powerwalk.model.Item;
import powerwalk.model.OutOfReachException;

/**
 *
 * @author vync job
 */
public class TeleportItem extends Item {
    
    protected ArrayList<Teleport> destinations = new ArrayList<>();
    
    protected ArrayList<Integer> values = new ArrayList<>();
    
    public TeleportItem(org.powerbot.game.api.wrappers.node.Item rsItem){
        super(rsItem); 
        values.add(rsItem.getId());
    }
    
    
    public class Teleport extends Teleportable{
        
        public Teleport(int x,int y,int z,int rawNumber){
            super(x, y, z, rawNumber);
        }

        @Override
        public void follow() throws OutOfReachException {
            throw new UnsupportedOperationException("Not supported yet.");
        }

        @Override
        public boolean isAllowed(String method) {
            throw new UnsupportedOperationException("Not supported yet.");
        }
        
    }
}
