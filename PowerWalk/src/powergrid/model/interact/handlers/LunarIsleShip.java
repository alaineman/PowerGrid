package powergrid.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class LunarIsleShip extends Transportable {

    public static Point shift;
    
    public LunarIsleShip(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<LunarIsleShip>(1));
    }

    @Override
    public void handle(Transportable dest) throws OutOfReachException {
        int[] npcids = dest.getNPCIDs();
        if (npcids == null) {
            return;
        }
        NPC merchant = NPCs.getNearest(npcids);
        if (merchant != null) {
            merchant.interact("Travel");
        } else {
            throw new OutOfReachException(dest.getPosition(), "No NPC nearby.");
        }
    }

    @Override
    public void waitForCompletion(Transportable dest) {
        Timer map = new Timer(5000);
        while(map.isRunning() && !Widgets.get(431).validate()){
            Task.sleep(100, 200);
        }
        map.reset();
        while(map.isRunning() && Widgets.get(431).validate()){
            Task.sleep(300,500);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
