package powergrid.model.interaction.interactors;

import java.util.HashSet;
import java.util.Set;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;
import powergrid.model.interact.Transportable;
import powergrid.model.interact.handlers.manifold.Minecart;
import powergrid.model.interaction.Interactor;
import powergrid.tasks.Task;

/**
 * Interactor for Minecarts.
 * <p/>
 * 
 * @author Chronio
 */
public class MinecartInteractor extends Interactor<Minecart> {

    /**
     * Creates a new MinecartInteractor that uses the specified information to
     * perform interactions with Minecart objects.
     * @param c the Client
     * @param map the WorldMap instance
     * @param interactor the RSInteractor object that allows interaction with 
     *                   the Runescape environment
     */
    public MinecartInteractor(WorldMap map, RSInteractor interactor) {
        super(map,interactor);
    }
    
    @Override public Transportable[] getOptions(Minecart elem) {
        if (elem == null) {
            return new Transportable[0];
        } else {
            return elem.getDestinations();
        }
    }

    @Override public boolean interact(Minecart elem) 
            throws OutOfReachException {
        Transportable[] dests = getOptions(elem);
        if (dests.length > 0 && dests[0] instanceof Minecart) {
            return travel(elem, (Minecart) dests[0]);
        } else {
            return false;
        }
    }

    @Override public boolean interact(Minecart elem, Object destination) 
            throws OutOfReachException {
        if (destination == null || !(destination instanceof Minecart)) {
            return false;
        }
        Minecart dest = (Minecart) destination;
        Transportable[] dests = elem.getDestinations();
        for (Transportable t : dests) {
            if (t.equals(dest) && travel(elem,dest)) {
                return true;
            }
        }
        return false;
    }

    @Override public Set<Class<?>> getTypes() {
        HashSet<Class<?>> res = new HashSet<>(3);
        res.add(Minecart.class);
        return res;
    }

    @Override public boolean isMoreFavorableThan(Interactor i, Minecart elem) {
        return false;
    }
    
    private boolean travel(Minecart start, Minecart goal) {
        int widgetNum = goal.getWidgetNumber();
        if (widgetNum == -1) {
            return false;
        }
        RSInteractor i = getInteractor();
        Tile startTile = start.getPosition().toTile();
        if (!startTile.isOnScreen()) {
            return false;
        }
        i.click(start);
        Widget w = i.getWidget(889);
        long startTime = System.currentTimeMillis();
        while (System.currentTimeMillis() >= startTime+4000 && !w.validate()) {
            Task.sleep(15,35);
        }
        if (!i.getWidget(889).validate()) {
            return false;
        }
        WidgetChild wc = w.getChild(widgetNum);
        i.click(wc);
        waitForComplete();
        return true;
    }
    
    private void waitForComplete() {
        Player local = getInteractor().getLocalPlayer();
        long endTime = System.currentTimeMillis() + 6000;
        while (System.currentTimeMillis() < endTime) {
            if (local.getAnimation() == 2148) {
                break;
            }
            Task.sleep(50,100);
        }
        endTime = System.currentTimeMillis() + 6000;
        while (System.currentTimeMillis() < endTime) {
            if (local.getAnimation() != 2148) {
                break;
            }
            Task.sleep(50,100);
        }
    }
    
}
