package powerwalk.model.interact.handlers.manifold;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
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
public class HotAirBalloon extends Transportable {

    private static int destSelectWidget = 469;
    public final static int[] values = {19133,};

    public HotAirBalloon(Point p) {
        super(p.x, p.y, p.z, -1, new ArrayList<HotAirBalloon>(5));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        SceneObject basket = SceneEntities.getNearest(values);
        if (basket == null || !basket.isOnScreen()) {
            throw new OutOfReachException(dest.getPosition(), "No basket nearby.");
        }
        basket.click(true);
        Timer convo = new Timer(6000);
        while (convo.isRunning() && !Widgets.get(1184).validate()) {
            Task.sleep(50, 100);
        }
        Widgets.clickContinue();
        Task.sleep(200, 300);
        if (Widgets.canContinue()) {
            Widgets.clickContinue();
        }
        convo.reset();
        while (convo.isRunning() && !Widgets.get(1188).validate()) {
            Task.sleep(50, 100);
        }
        Widgets.get(1188, 3).click(true);
        convo.reset();
        while (convo.isRunning() && !Widgets.get(destSelectWidget).validate()) {
            Task.sleep(50, 100);
        }
        Widgets.get(destSelectWidget, dest.getWidgetNumber()).click(true);
        waitForCompletion(dest);
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer map = new Timer(7000);
        while (map.isRunning() && !Widgets.get(destSelectWidget).validate()) {
            Task.sleep(50, 100);
        }
        while (map.isRunning() && Widgets.get(destSelectWidget).validate()) {
            Task.sleep(100, 300);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}