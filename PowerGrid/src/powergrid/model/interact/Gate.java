package powergrid.model.interact;

import java.util.ArrayList;
import powergrid.model.OutOfReachException;

/**
 *
 * @author Alaineman
 */
public class Gate extends Transportable {
    
    public Gate(int x,int y,int z,int rawNumber){
        super(x, y, z, rawNumber, new ArrayList<Gate>(1));
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