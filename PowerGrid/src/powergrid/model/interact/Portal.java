package powergrid.model.interact;

import java.util.ArrayList;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powergrid.model.OutOfReachException;

/**
 *
 * @author Alaineman
 */
public class Portal extends Transportable {
    
    public Portal(int x,int y,int z,int rawNumber){
        super(x, y, z, rawNumber, new ArrayList<Portal>(1));
    } 

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        SceneObject po = SceneEntities.getAt(this.getPosition());
        if(po != null){
            po.interact("Enter");
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    
    
}
