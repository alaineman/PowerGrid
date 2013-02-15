package powerwalk.model.interact.handlers.manifold;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.interactive.NPC;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powerwalk.model.OutOfReachException;
import powerwalk.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class MagicCarpet extends Transportable {

    private static Widget optionMenu = Widgets.get(1188);

    public MagicCarpet(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<MagicCarpet>(10));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        int[] npcids = dest.getNPCIDs();
        if (npcids == null) {
            return;
        }
        NPC merchant = NPCs.getNearest(npcids);
        if(merchant != null){
        merchant.interact("Travel");
        } else {
            throw new OutOfReachException(dest.getPosition(), "No NPC nearby.");
        }
        Timer chat = new Timer(5000);
        while (chat.isRunning() && !Widgets.get(1188).validate()) {
            Task.sleep(50, 100);
        }
        WidgetChild[] childs = optionMenu.getChildren();
        for (WidgetChild i : childs) {
            if (i.getText().contains(dest.getTraits())) {
                i.click(true);
                return;
            }
        }
        while(Widgets.canContinue() && Players.getLocal().getAnimation() != 654 ){
            Widgets.clickContinue();
            Task.sleep(400,700);
        }
        
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer ride = new Timer(120000);
        while (ride.isRunning() && Players.getLocal().getAnimation() != 330) {
            Task.sleep(200, 500);
        }
        while (ride.isRunning() && Players.getLocal().getAnimation() == 330) {
            Task.sleep(200, 500);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}