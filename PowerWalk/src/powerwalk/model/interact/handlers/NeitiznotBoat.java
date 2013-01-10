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
public class NeitiznotBoat extends Transportable {
    
    // id _5508 , pos (2644,3710), "Travel-Neitiznot"
    // id _5507 , pos (2311,3781), "Travel-Rellekka"

    public NeitiznotBoat(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<NeitiznotBoat>(1));
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