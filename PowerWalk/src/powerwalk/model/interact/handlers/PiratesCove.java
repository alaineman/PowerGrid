package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 * 
 * @author Alaineman
 */
public class PiratesCove extends Transportable {    
    
    // id _4537 , pos (2214,3794) "Travel" 
    // id _413 , pos (2621,3688) "Travel"
    
     public PiratesCove(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<PiratesCove>(1));
    }

    @Override
    protected void handle(Transportable dest) {
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
