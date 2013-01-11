/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact.handlers;

import java.util.ArrayList;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.interactive.NPC;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Vincent W
 */
public class NeitiznotBoat extends Transportable {
    
    // id _5508 , pos (2644,3710), "Travel-Neitiznot"
    // id _5507 , pos (2311,3781), "Travel-Rellekka"

    public NeitiznotBoat(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<NeitiznotBoat>(1));
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
                if (i.contains("Travel-Neitiznot")) {
                    merchant.interact("Travel-Neitiznot");
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
            powerwalk.tasks.Task.sleep(200, 300);
        }
        map.reset();
        while (map.isRunning() && Widgets.get(224).validate()) {
            powerwalk.tasks.Task.sleep(500, 1000);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
