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
public class GnomeGlider extends Transportable {

    public final static int[] values = {};

    public GnomeGlider(Point p) {
        super(p.x, p.y, p.z, -1, new ArrayList<GnomeGlider>(7));
    }

    @Override
    protected void handle(Transportable dest) {
        NPC gnome = NPCs.getNearest(values);
        gnome.interact("Glider");
        Timer wait = new Timer(5000);
        while (wait.isRunning() && !Widgets.get(138).validate()) {
            Task.sleep(50, 100);
        }
        if(dest.getDestinations().length > 1){
        Widgets.get(138, dest.getWidgetNumber()).click(true);
        }
        waitForCompletion(dest);
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer wait = new Timer(5000);
        while (wait.isRunning() && Widgets.get(138).validate()) {
            Task.sleep(50, 100);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}