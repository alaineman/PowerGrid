/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powergrid.model.OutOfReachException;
import powergrid.model.interact.Transportable;

/**
 *
 * @author Vincent W
 */
public class IcebergBoat extends Transportable {

   /**
     * These are boat GameObject values.
     * @see ShiloCart
     */
    public final static int[] values = {21176,};
    
    public IcebergBoat(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<IcebergBoat>(1));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        SceneObject cart = SceneEntities.getNearest(values);
        if (cart == null || !cart.isOnScreen()) {
            throw new OutOfReachException(dest.getPosition(), "No boat nearby.");
            
        }
        cart.interact("Travel");
        Timer map = new Timer(6000);
        while(map.isRunning() && !Widgets.get(1188).validate()){
            Task.sleep(50,100);
        }
        Widgets.get(1188, 3).click(true);
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer map = new Timer(6000);
        while(map.isRunning() && !Widgets.get(120).validate()){
            Task.sleep(50,100);
        }
        map.reset();
        while(map.isRunning() && Widgets.get(120).validate()){
            Task.sleep(50,100);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
