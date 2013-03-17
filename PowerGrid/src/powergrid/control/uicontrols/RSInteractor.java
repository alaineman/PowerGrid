package powergrid.control.uicontrols;

import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.ViewportEntity;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.client.Client;
import powergrid.model.GameTile;
import powergrid.model.Point;
import powergrid.model.WorldMap;

/**
 * This class deals with interactions with the Runescape GUI, such as retrieving
 * and interacting with widgets.
 * <p/>
 * @author Chronio
 */
public class RSInteractor {
    
    private Client client = null;
    private WorldMap map = null;
    
    public RSInteractor useClient(Client c) {
        client = c;
        return this;
    }
    
    public RSInteractor useWorldMap(WorldMap m) {
        map = m;
        return this;
    }
    
    /**
     * Returns the client this RSInteractor uses.
     * @return the client this RSInteractor uses
     */
    public Client getClient() {
        return client;
    }
    
    /**
     * Returns the WorldMap his RSInteractor uses.
     * @return the WorldMap his RSInteractor uses
     */
    public WorldMap getMap() {
        return map;
    }
    
    public Widget getWidget(int num) {
        if (num < 0) {
            throw new IllegalArgumentException("widget value < 0");
        }
        return null;
    }
    
    public WidgetChild getWidgetChild(int widget, int widgetChild) {
        if (widget < 0 || widgetChild < 0) {
            throw new IllegalArgumentException("widget value < 0");
        }
        Widget w = getWidget(widget);
        if (w == null) {
            return null;
        } else {
            return w.getChild(widgetChild);
        }
    }
    
    public boolean click(ViewportEntity object) {
        return click(object,true);
    }
    public boolean click(Locatable object) {
        return click(object.getLocation(),true);
    }
    
    public boolean click(ViewportEntity object, final boolean left) {
        return Mouse.apply(object,new Filter<java.awt.Point>(){
            @Override public boolean accept(java.awt.Point p) {
                Mouse.click(left);
                return true;
            }
        });
    }
    
    public boolean clickRight(ViewportEntity object) {
        return click(object,false);
    }
    public boolean clickRight(Locatable object) {
        return click(object.getLocation(),false);
    }
    
    public Player getLocalPlayer() {
        return new Player(getClient().getMyRSPlayer());
    }
    
    public GameTile getTile(Point p) {
        WorldMap theMap = getMap();
        if (theMap == null) {
            return null;
        } else {
            return theMap.get(p);
        }
    }
}
