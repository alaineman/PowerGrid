package powerwalk.model.interact.handlers.manifold;

import java.util.Collection;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class Minecart extends Transportable {

    /**
     * These are the hatch and minecart object values.
     */
    public final static int[] values = {28094, 7030, 7029, 7028};

    public Minecart(Point p, Collection<? extends Minecart> dests) {
        super(p.x, p.y, p.z, -1, dests);
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        Minecart current = (Minecart) dest;
        SceneObject cart = SceneEntities.getNearest(values);
        if (cart == null || !cart.isOnScreen()) {
            throw new OutOfReachException(dest.getPosition(), "No cart nearby.");
        }
        cart.click(true);
        if (dest.getDestinations().length > 1) {
            int widgetCode = current.getWidgetNumber();
            if (widgetCode != -1) {
                Timer widgetTimer = new Timer(4000);
                while (widgetTimer.isRunning() && !Widgets.get(889).validate()) {
                    Task.sleep(15, 35);
                }
                Widgets.get(889, dest.getWidgetNumber()).click(true);
            } else {
                throw new OutOfReachException(dest.getPosition(), "Has no widget value.");
            }
        }
        waitForCompletion(dest);
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer riding = new Timer(6000);
        while (riding.isRunning() && Players.getLocal().getAnimation() != 2148) {
            Task.sleep(50, 100);
        }
        riding.reset();
        while (riding.isRunning() && Players.getLocal().getAnimation() == 2148) {
            Task.sleep(50, 100);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
