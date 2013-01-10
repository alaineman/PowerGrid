/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Vincent W
 */
public class JatizsoBoat extends Transportable {
    
    // id _5481 , pos (2644,3709), "Travel-Jatizso"
    // id _5482 , pos (2421,3781), "Travel-Rellekka"

    public JatizsoBoat(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<JatizsoBoat>(1));
    }
    
    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
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