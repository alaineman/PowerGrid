/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powergrid.model.OutOfReachException;
import powergrid.model.interact.Transportable;

/**
 *
 * @author Vincent W
 */
public class JatizsoBoat extends Transportable {

    // id _5481 , pos (2644,3709), "Travel-Jatizso"
    // id _5482 , pos (2421,3781), "Travel-Rellekka"
    public JatizsoBoat(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<JatizsoBoat>(1));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        int[] npcids = dest.getNPCIDs();
        if (npcids == null) {
            return;
        }
        NPC merchant = NPCs.getNearest(npcids);
        if (merchant != null) {
            for (String i : merchant.getActions()) {
                if (i.contains("Travel-Jatizso")) {
                    merchant.interact("Travel-Jatizso");
                } else {
                    merchant.interact("Travel-Rellekka");
                }
            }
        } else {
            throw new OutOfReachException(dest.getPosition(), "No NPC nearby.");
        }
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer map = new Timer(6000);
        while (map.isRunning() && !Widgets.get(224).validate()) {
            powergrid.tasks.Task.sleep(200, 300);
        }
        map.reset();
        while (map.isRunning() && Widgets.get(224).validate()) {
            powergrid.tasks.Task.sleep(500, 1000);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}