package powerwalk.model.interact;

import java.util.ArrayList;
import powerwalk.model.OutOfReachException;

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
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    
    
}
