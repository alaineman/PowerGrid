package powerwalk.model.interact.handlers.manifold;

import java.util.Collection;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 * 
 * @author Alaineman
 */
public class Minecart extends Transportable {
    
    public final static int[] values = { 28094, 7030, 7029, 7028 };
        
    public Minecart(Point p, Collection<? extends Minecart> dests){
        super(p.x, p.y, p.z, -1, dests);        
    }
    
    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        Minecart current = (Minecart) dest;
        if(dest.getDestinations().length > 1){
            int widgetCode = current.getWidgetNumber();
            if(widgetCode != -1){
                SceneObject cart = SceneEntities.getNearest(values);          
                if(cart == null || !cart.isOnScreen()) {
                    throw new OutOfReachException(dest.getPosition(), "No cart nearby.");
                } 
                cart.click(true); 
                waitForCompletion(dest);
            } else {
                throw new OutOfReachException(dest.getPosition(), "Has no widget value.");
            }
        } else {
            //toClient(dest);
        }
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
