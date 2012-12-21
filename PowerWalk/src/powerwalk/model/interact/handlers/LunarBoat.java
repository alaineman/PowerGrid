package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 * 
 * @author Alaineman
 */
public class LunarBoat extends Transportable{
    
    public static final Point startPoint = new Point(0, 0);
    
    public static final Point endPoint = new Point(0, 0);
    
    public LunarBoat(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<LunarBoat>(1));
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
