package powerwalk.model.interact.handlers.manifold;

import java.util.ArrayList;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class SpiritTree extends Transportable {

    /**
     * These are the spirit tree GameObject values.
     *
     * @see GameObject
     */
    public final static int[] values = {1317};
    
    private static WidgetChild optionMenu = Widgets.get(864, 6);

    public SpiritTree(Point p) {
        super(p.x, p.y, p.z, -1, new ArrayList<SpiritTree>(5));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        SceneObject spirit = SceneEntities.getNearest(values);
        if (spirit == null || !spirit.isOnScreen()) {
            throw new OutOfReachException(dest.getPosition(), "No basket nearby.");
        }
        spirit.interact("Teleport");
        //if(questdone){
            
        //} else {
            
        //}        
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