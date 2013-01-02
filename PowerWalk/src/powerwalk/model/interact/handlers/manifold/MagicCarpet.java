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
public class MagicCarpet extends Transportable{
    
    public MagicCarpet(Point p){
        super(p.x, p.y, p.z, -1, new ArrayList<MagicCarpet>(10));
    }

    @Override
    protected void handle(Transportable dest) {
        NPC merchant = NPCs.getNearest(34343434);//something
        merchant.interact("Travel");
        Timer chat = new Timer(5000);
        while(chat.isRunning() && !Widgets.get(1188).validate()){
            Task.sleep(50, 100);
        }
        //TODO: select option
        
    }
    
    @Override
    protected void waitForCompletion(Transportable dest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

}