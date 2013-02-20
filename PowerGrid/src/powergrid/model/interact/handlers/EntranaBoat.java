/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
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
public class EntranaBoat extends Transportable {

    // npc="_657|_2728|_2729"  , pos="(3045,3235)"
    // npc="_658|_2730|_2731"  , pos="(2833,3335)"  
    public EntranaBoat(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<EntranaBoat>(1));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        int[] npcids = dest.getNPCIDs();
        if (npcids == null) {
            return;
        }
        NPC merchant = NPCs.getNearest(npcids);
        if (merchant != null) {
            merchant.interact("Travel");
            while (!Widgets.canContinue()) {
                Task.sleep(300, 500);
            }
            Widgets.clickContinue();
        } else {
            throw new OutOfReachException(dest.getPosition(), "No NPC nearby.");
        }
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer map = new Timer(6000);
        while (map.isRunning() && !Widgets.get(299).validate()) {
            powergrid.tasks.Task.sleep(200, 300);
        }
        map.reset();
        while (map.isRunning() && Widgets.get(299).validate()) {
            powergrid.tasks.Task.sleep(500, 1000);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}