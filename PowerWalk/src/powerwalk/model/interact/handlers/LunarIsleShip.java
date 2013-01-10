package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 * 
 * @author Alaineman
 */
public class LunarIsleShip extends Transportable{
    
    // 414 captain
    // 431 widget ship map
    // 2223 3792
    // 2138 3900
    // y diff 50
    // 18019
        
    public LunarIsleShip(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<LunarIsleShip>(1));
    }

    @Override
    public void handle(Transportable dest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void waitForCompletion(Transportable dest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
