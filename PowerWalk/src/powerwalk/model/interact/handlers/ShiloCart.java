/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Vincent W
 */
public class ShiloCart extends Transportable {

   /**
     * These are the cart GameObject values.
     * @see GameObject
     */
    public final static int[] values = {2230,2265};
    
    public ShiloCart(Point p) {
        super(p.x, p.y, p.z, -1, new ArrayList<ShiloCart>(1));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        SceneObject cart = SceneEntities.getNearest(values);
        if (cart == null || !cart.isOnScreen()) {
            throw new OutOfReachException(dest.getPosition(), "No cart nearby.");
            
        }
        cart.interact("Pay-fare");
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Task.sleep(4000,5000);
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
