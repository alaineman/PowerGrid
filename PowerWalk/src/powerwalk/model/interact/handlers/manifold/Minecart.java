package powerwalk.model.interact.handlers.manifold;

import java.util.Collection;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 * 
 * @author Alaineman
 */
public class Minecart extends Transportable {
        
    public Minecart(Point p, Collection<? extends Minecart> dests){
        super(p.x, p.y, p.z, -1, dests);        
    }
    
    @Override
    protected void handle(Transportable dest) {
        if(dest.getDestinations().length > 1){
            //toServer();
        } else {
            //toClient(dest);
        }
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
   
}
