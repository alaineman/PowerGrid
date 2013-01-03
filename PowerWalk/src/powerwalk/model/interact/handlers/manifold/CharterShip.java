package powerwalk.model.interact.handlers.manifold;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class CharterShip extends Transportable {

    public final static int[] values = {};

    public CharterShip(Point p) {
        super(p.x, p.y, p.z, -1, new ArrayList<CharterShip>(5));
    }

    @Override
    protected void handle(Transportable dest) {
        int[] npcids = dest.getNPCIDs();
        if (npcids == null) {
            return;
        }
        NPC captain = NPCs.getNearest(npcids);
        captain.interact("Charter");
        Timer wait = new Timer(6000);
        while (wait.isRunning()
                && !Widgets.get(95).validate()) {
            Task.sleep(50, 100);
        }
        Widgets.get(95, dest.getWidgetNumber()).click(true);
        wait.reset();
        while (wait.isRunning() && !Widgets.canContinue()) {
            Task.sleep(50, 100);
        }
        wait.reset();
        Widgets.clickContinue();
        while (wait.isRunning() && !Widgets.get(1188).validate()) {
            Task.sleep(50, 100);
        }
        Widgets.get(1188, 3).click(true);

        waitForCompletion(dest);
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Task.sleep(800, 1200);
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}