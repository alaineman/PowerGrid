package powergrid.control.interaction.interactor;

import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Set;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.control.interaction.Interactor;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.WorldMap;
import powergrid.model.network.NetworkElement;
import powergrid.model.network.TreeNetwork;
import powergrid.model.world.Player;
import powergrid.model.world.transportation.Minecart;
import powergrid.task.Task;

/**
 * Interactor for Minecart instances.
 * <p/>
 * @author Chronio
 */
public class MinecartInteractor extends Interactor {

    /**
     * Creates a new MinecartInteractor that uses the specified information to
     * perform interactions with Minecart objects.
     * @param map the WorldMap instance
     * @param interactor the RSInteractor object that allows interaction with 
     *                   the Runescape environment
     */
    public MinecartInteractor(WorldMap map, RSInteractor interactor) {
        super(map,interactor);
    }
    
    /**
     * Verifies that the provided Object is a Minecart Object and automatically
     * casts it to Minecart.
     * <p/>
     * An IllegalArgumentException is thrown when the provided Object is no
     * Minecart.
     * @param o the Object to verify and cast
     * @return the provided Object, cast to Minecart
     * @throws IllegalArgumentException when the Object is no Minecart
     */
    public Minecart verify(Object o) {
        if (o instanceof Minecart) {
            return (Minecart) o;
        } else {
            throw new IllegalArgumentException(
                    "Invalid object type: not a Minecart instance");
        }
    }
    
    /**
     * Returns the a Set of the elements in the given Object's TransportNetwork,
     * if the provided Object is a Minecart instance.
     * <p/>
     * If the provided Object is not a Minecart instance, this method throws an
     * IllegalArgumentException.
     * <p/>
     * @param o the Object to look up the options for
     * @return the Set of available options for the provided Object
     */
    @Override public Set<Minecart> getOptions(Object o) {
        Minecart elem = verify(o);
        Set<? extends NetworkElement> elems = elem.getNetwork().getElements();
        elems.remove(elem);
        Set<Minecart> res = new HashSet<>(elems.size() * 4 / 3);
        for (NetworkElement e : elems) {
            if (e instanceof Minecart) {
                res.add((Minecart) e);
            }
        }
        return res;
    }

    
    @Override public boolean interact(Object o) {
        Set<Minecart> options = getOptions(o);
        Iterator it = options.iterator();
        if (it.hasNext()) {
            return interact(o,it.next());
        } else {
            return false;
        }
    }
    
    /**
     * Interacts with the Minecart to travel to the provided destination.
     * <p/>
     * When the destination is not on the same network, this method returns 
     * false. Otherwise, a path is calculated using the findPath method of the 
     * Object's TransportNetwork. Then, that path is executed step by step.
     * @param o the Object to interact with
     * @param destination the destination of the Minecart transportation.
     * @return true if the operation was successful, or false if the interaction
     *         failed.
     */
    @Override public boolean interact(Object o, Object destination) {
        Minecart elem = verify(o);
        Minecart dest = verify(destination);
        TreeNetwork nw = elem.getNetwork();
        Set<? extends NetworkElement> dests = nw.getElements();
        for (NetworkElement t : dests) {
            if (t.equals(dest) && travelPath(elem,nw.findPath(elem, t))) {
                return true;
            }
        }
        return false;
    }

    /**
     * Returns a Set containing the Minecart class object.
     * @return a Set containing the Minecart class object
     */
    @Override public Set<Class<?>> getTypes() {
        HashSet<Class<?>> res = new HashSet<>(3);
        res.add(Minecart.class);
        return res;
    }

    /**
     * Returns if this Interactor is more favorable than the provided 
     * Interactor to handle Objects of the given Class.
     * <p/>
     * This method returns true if and only if the given Interactor provides no
     * support for the exact class, and the class is the Minecart class or a 
     * Minecart subclass.
     * <p/>
     * @param i the Interactor to compare with
     * @param c the Object Class to compare for
     * @return true if this Interactor is more favorable to handle the given 
     *         Class than the given Interactor, false otherwise.
     */
    @Override public boolean isMoreFavorableThan(Interactor i, Class<?> c) {
        if (Minecart.class.isAssignableFrom(c)) {
            if (!Minecart.class.equals(c) || i.getTypes().contains(c)) {
                return false;
            }
            return true;
        } else {
            return false;
        }
    }
    
    
    private boolean travelPath(Minecart start, List<NetworkElement> path) {
        if (path.isEmpty()) {
            return true;
        }
        ListIterator<NetworkElement> li = path.listIterator();
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
        int widgetNum = 0; //TODO getWidgetNum()
        if (widgetNum != -1) {
            RSInteractor i = getInteractor();
            Tile startTile = start.getPosition().toTile();
            if (startTile.isOnScreen()) {
                i.click(start);
                Widget w = i.getWidget(889);
                if (getInteractor().waitForVisible(w, 4000)) {
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
