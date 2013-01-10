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
public class MiscellaniaShip extends Transportable {
    
    // id _1304 , pos (2629,3694), "Travel-Miscellania"
    // id _1385 , pos (2581,3874), "Travel-Rellekka"

    public MiscellaniaShip(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<MiscellaniaShip>(1));
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
