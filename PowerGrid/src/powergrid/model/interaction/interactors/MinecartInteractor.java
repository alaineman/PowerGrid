package powergrid.model.interaction.interactors;

import java.util.HashSet;
import java.util.List;
import java.util.ListIterator;
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
import powergrid.model.interaction.network.TransportNetwork;
import powergrid.tasks.Task;

/**
 * Interactor for Minecarts.
 * <p/>
 * @author Chronio
 */
public class MinecartInteractor extends Interactor {

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
    
    private Minecart verify(Object o) {
        if (o instanceof Minecart) {
            return (Minecart) o;
        } else {
            throw new IllegalArgumentException("Invalid object type");
        }
    }
    
    @Override public Set<Minecart> getOptions(Object o) {
        if (o == null) {
            return new HashSet<>(2);
        } else {
            Minecart elem = verify(o);
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

    @Override public boolean interact(Object o, Object destination) 
            throws OutOfReachException {
        Minecart elem = verify(o);
        Minecart dest = verify(destination);
        TransportNetwork nw = elem.getNetwork();
        Set<TransportTile> dests = nw.getElements();
        for (TransportTile t : dests) {
            if (t.equals(dest) && travelPath(elem,nw.findPath(elem, t))) {
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

    @Override public boolean isMoreFavorableThan(Interactor i, Object o) {
        return false;
    }
    
    private boolean travelPath(Minecart start, List<TransportTile> path) {
        if (path.isEmpty()) {
            return true;
        }
        ListIterator<TransportTile> li = path.listIterator();
        Minecart current = start;
        Minecart next;
        while (li.hasNext()) {
            next = verify(li.next());
            travel(current,next);
            current = next;
        }
        return true;
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
