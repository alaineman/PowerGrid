package powergrid.model.interaction.interactors;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;
import powergrid.model.world.transportation.Minecart;
import powergrid.model.interaction.Interactor;
import powergrid.model.interaction.TransportTile;
import powergrid.tasks.Task;

/**
 * Interactor for Minecarts.
 * <p/>
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
    
    @Override public Set<Minecart> getOptions(Minecart elem) {
        if (elem == null) {
            return new HashSet<>(2);
        } else {
            Set<TransportTile> elems = elem.getNetwork().getElements();
            HashSet<Minecart> res = new HashSet<>((int)(1.5*elems.size()));
            for (TransportTile t : elems) {
                if (t instanceof Minecart) {
                    res.add((Minecart) t);
                }
            }
            return res;
        }
    }

    @Override public boolean interact(Minecart elem) 
            throws OutOfReachException {
        Set<Minecart> dests = getOptions(elem);
        Iterator<Minecart> i = dests.iterator();
        if (i.hasNext()) {
            return travel(elem,i.next());
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
        Set<TransportTile> dests = elem.getNetwork().getElements();
        for (TransportTile t : dests) {
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
        int widgetNum = -1; //TODO getWidgetNum()
        if (widgetNum != -1) {
            RSInteractor i = getInteractor();
            Tile startTile = start.getPosition().toTile();
            if (startTile.isOnScreen()) {
                i.click(start);
                Widget w = i.getWidget(889);
                long startTime = System.currentTimeMillis();
                while (System.currentTimeMillis() >= startTime+4000 && !w.validate()) {
                    Task.sleep(15,35);
                }
                if (i.getWidget(889).validate()) {
                    WidgetChild wc = w.getChild(widgetNum);
                    i.click(wc);
                    waitForComplete();
                    return true;
                }
            }
        }
        return false;
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
