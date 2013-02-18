package powerwalk.model.interact;

import java.util.ArrayList;
import powerwalk.model.OutOfReachException;

/**
 *
 * @author Alaineman
 */
public class Shortcut extends Transportable {
    
    protected String[] commands = {"Squeeze-through"};

    public Shortcut(int x,int y,int z,int rawNumber){
        super(x, y, z, rawNumber, new ArrayList<Shortcut>(1));
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
