package powerwalk.model.interact;

import java.util.ArrayList;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 *
 * @author Alaineman
 */
public class Shortcut extends Transportable {

    public Shortcut(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<Shortcut>(1));
    } 

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
