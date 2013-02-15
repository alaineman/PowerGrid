/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powerwalk.model.OutOfReachException;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Vincent W
 */
public class MusaPointShip extends Transportable {
    //380, 378, 377, 376

    public MusaPointShip(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<MusaPointShip>(1));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        int[] npcids = dest.getNPCIDs();
        if (npcids == null) {
            return;
        }
        NPC merchant = NPCs.getNearest(npcids);
        if (merchant != null) {
            merchant.interact("Pay-Fare");
        } else {
            throw new OutOfReachException(dest.getPosition(), "No NPC nearby.");
        }
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer map = new Timer(5000);
        while (map.isRunning() && !Widgets.get(299).validate()) {
            Task.sleep(100, 200);
        }
        map.reset();
        while (map.isRunning() && Widgets.get(299).validate()) {
            Task.sleep(200, 500);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
