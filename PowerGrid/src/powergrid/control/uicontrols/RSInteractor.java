package powergrid.control.uicontrols;

import java.util.HashMap;
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
    private HashMap<Integer, Widget> loadedWidgets = new HashMap(8,7/8f);
    
    /**
     * Sets the Client to be used in this RSInteractor.
     * @param c the Client to use
     * @return itself for fluency
     */
    public RSInteractor useClient(Client c) {
        client = c;
        return this;
    }
    
    /**
     * Sets the WorldMap to be used in this RSInteractor.
     * @param m the WorldMap to use
     * @return itself for fluency
     */
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
    
    /**
     * Returns the RSBot widget with the given number.
     * @param num the widget number
     * @return the RSBot widget with the specified number
     * @throws IllegalArgumentException when num &lt; 0
     */
    public synchronized Widget getWidget(int num) {
        if (num < 0) {
            throw new IllegalArgumentException("widget value < 0");
        }
        Widget w = loadedWidgets.get(num);
        if (w == null) {
            w = new Widget(num);
            loadedWidgets.put(num, w);
        }
        return w;
    }
    
    /**
     * Returns the WidgetChild with the specified id, from the Widget with the 
     * specified id
     * @param widget the Widget id
     * @param widgetChild the WidgetChild id
     * @return the WidgetChild with the specified id.
     * @throws IllegalArgumentException when either parameter &lt; 0
     */
    public synchronized WidgetChild getWidgetChild(int widget, int widgetChild) {
        if (widgetChild < 0) {
            throw new IllegalArgumentException("widgetchild value < 0");
        }
        return getWidget(widget).getChild(widgetChild);
    }
    
    /**
     * Left-clicks the given ViewportEntity.
     * @param object the ViewportEntity to click
     * @return whether the operation was successful
     */
    public boolean click(ViewportEntity object) {
        return click(object,true);
    }
    
    /**
     * Left-clicks the given Locatable Object.
     * @param object the Locatable Object to click
     * @return whether the operation was successful
     */
    public boolean click(Locatable object) {
        return click(object.getLocation(),true);
    }
    
    /**
     * Clicks the given ViewportEntity.
     * @param object the ViewportObject to click
     * @param left true to left-click, false to right-click
     * @return whether the operation was successful
     */
    public boolean click(ViewportEntity object, final boolean left) {
        return Mouse.apply(object,new Filter<java.awt.Point>(){
            @Override public boolean accept(java.awt.Point p) {
                Mouse.click(left);
                return true;
            }
        });
    }
    
    /**
     * Right-clicks the given ViewportEntity.
     * @param object the ViewportEntity to click
     * @return whether the operation was successful
     */
    public boolean clickRight(ViewportEntity object) {
        return click(object,false);
    }
    
    /**
     * Right-clicks the given Locatable Object.
     * @param object the Locatable Object to click
     * @return whether the operation was successful
     */
    public boolean clickRight(Locatable object) {
        return click(object.getLocation(),false);
    }
    
    /**
     * Returns the currently logged in Player in the Runescape environment
     * @return the local Player
     */
    public Player getLocalPlayer() {
        return new Player(getClient().getMyRSPlayer());
    }
    
    /**
     * Retrieves the GameTile at the specified Point from the WorldMap.
     * 
     * @param p the position of the GameTile to retrieve
     * @return the GameTile at position p, or null if no GameTile exists there.
     */
    public GameTile getTile(Point p) {
        WorldMap theMap = getMap();
        if (theMap == null) {
            return null;
        } else {
            return theMap.get(p);
        }
    }
}
