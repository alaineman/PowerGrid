package powergrid.model.interaction.interactors;

import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.client.Client;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;
import powergrid.model.interact.Transportable;
import powergrid.model.interact.handlers.manifold.Minecart;
import powergrid.model.interaction.Interactor;

/**
 * Interactor for Minecarts.
 * <p/>
 * 
 * @author Chronio
 */
public class MinecartInteractor extends Interactor<Minecart> {

    public MinecartInteractor(Client c, WorldMap map) {
        super(c,map);
    }
    
    @Override public Object[] getOptions(Minecart elem) {
        if (elem == null) {
            return new Object[0];
        } else {
            return elem.getDestinations();
        }
    }

    @Override public boolean interact(Minecart elem) {
        return false;
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

    @Override public Class<?>[] getTypes() {
        return new Class<?>[] {Minecart.class};
    }

    @Override public boolean isMoreFavorableThan(Interactor i, Minecart elem) {
        return false;
    }
    
    private boolean travel(Minecart start, Minecart goal) {
        Client c = getClient();
        WorldMap map = getMap();
        Tile startTile = start.getPosition().toTile();
        if (!startTile.isOnScreen()) {
            return false;
        }
        startTile.click(true);
        int widgetNum = goal.getWidgetNumber();
        
        return false;
    }
}
