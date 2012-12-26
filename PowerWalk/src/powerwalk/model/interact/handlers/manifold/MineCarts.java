package powerwalk.model.interact.handlers.manifold;

import java.util.ArrayList;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

public class MineCarts extends Transportable {
    
    public MineCarts(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<MineCarts>(5));
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
