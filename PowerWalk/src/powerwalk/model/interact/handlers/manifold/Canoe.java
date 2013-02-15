package powerwalk.model.interact.handlers.manifold;

import java.util.ArrayList;
import powerwalk.model.interact.Transportable;

/**
 * 
 * @author Alaineman
 */
public class Canoe extends Transportable{
    
    public Canoe(int x,int y,int z,int rawNumber){
        super(x, y, z, rawNumber, new ArrayList<Canoe>(5));
    }

    @Override
    protected void handle(Transportable dest) {
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
