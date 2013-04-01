package powergrid.control.uicontrols;

import java.awt.Canvas;
import java.util.HashMap;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.Tile;
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
 * This class also contains constants that define the widget numbers of various 
 * commonly used widgets for easy access.
 * <p/>
 * @author Chronio
 */
public class RSInteractor {
    
    /** The minimum waiting time for wait operations. */
    public static final int DEFAULT_MIN_WAIT = 50;
    /** The maximum waiting time for wait operations. */
    public static final int DEFAULT_MAX_WAIT = 100;
    
    /** The Widget on which the FairyRing destination is chosen. */
    public static final int FAIRYRING_PANEL = 735;
    
    private Client client = null;
    private WorldMap map = null;
    private HashMap<Integer, Widget> loadedWidgets = new HashMap<>(8,7/8f);
    
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
     * Waits and returns after the object is visible, or the timeout has been 
     * reached.
     * <p/>
     * This method checks with intervals between <code>DEFAULT_MIN_WAIT</code>
     * and <code>DEFAULT_MAX_WAIT</code>.
     * @param object the object to wait for.
     * @param timeout the maximum amount of time to wait, in milliseconds.
     * @return true if the entity became visible within the timelimit, false if
     *         the timelimit was reached and the entity was not yet visible.
     * @throws UnsupportedOperationException when the provided object is not
     *                                       supported.
     */
    public boolean waitForVisible(Object object, int timeout) {
        return waitForVisible(object, timeout, DEFAULT_MIN_WAIT, 
                DEFAULT_MAX_WAIT);
    }
    
    /**
     * Waits and returns after the entity is visible, or the timeout has been 
     * reached.
     * <p/>
     * This method is a shorthand for the following piece of code:
     * <code><pre>
     * Timer timer = new Timer(timeout);
     * while (timer.isRunning() && !object.validate()) {
     *     Task.sleep(minTime,maxTime);
     * }
     * </pre></code>
     * The main difference here is that the method to check for the object's 
     * validation is performed using <code>isVisible(object)</code> and 
     * therefore highly dynamic.
     * @param object the entity to wait for.
     * @param timeout the maximum amount of time to wait, in milliseconds.
     * @param minTime the minimum interval between checks
     * @param maxTime the maximum interval between checks
     * @return true if the entity became visible within the timelimit, false if
     *         the timelimit was reached and the entity was not yet visible.
     * @throws UnsupportedOperationException when the provided object is not
     *                                       supported.
     */
    public boolean waitForVisible(Object object, int timeout, 
            int minTime, int maxTime) {
        
        long destTime = System.currentTimeMillis() + timeout;
        while (System.currentTimeMillis() < destTime) {
            if (isVisible(object)) {
                return true;
            } else {
                Task.sleep(minTime, maxTime);
            }
        }
        return isVisible(object);
    }
    
    /**
     * Tries to decide if the specified object is visible on the screen.
     * <p/>
     * The correct checking method is performed based on the provided object's 
     * type. If the object is not supported, an UnsupportedOperationException 
     * is thrown.
     * <p/>
     * @param object the object to check
     * @return whether the object is visible on the screen
     * @throws UnsupportedOperationException when the provided object is not
     *                                       supported.
     */
    public boolean isVisible(Object object) {
        if (object instanceof ViewportEntity) {
            return ((ViewportEntity) object).validate();
        }
        if (object instanceof Widget) {
            return ((Widget) object).validate();
        }
        if (object instanceof Locatable) {
            Tile tile = ((Locatable) object).getLocation();
            for (int xOff = 0; xOff <= 1; xOff++) {
                for (int yOff = 0; yOff <= 1; yOff++) {
                    if (!isOnScreen(tile.getPoint(xOff, yOff, 0))) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (object instanceof java.awt.Point) {
            return isOnScreen((java.awt.Point) object);
        }
        throw new UnsupportedOperationException("Unsupported object");
    }
    
    public boolean isOnScreen(java.awt.Point p) {
        Canvas c = getClient().getCanvas();
        return p.x >= 0 && p.y >= 0 && p.x < c.getWidth() 
                && p.y < c.getHeight();
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
    public synchronized WidgetChild getWidgetChild(int widget, 
            int widgetChild) {
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
     * Waits until the provided animations have passed.
     * @param timeout the maximum wait time
     * @param animIds the animations to wait for
     * @return true if all animations have finished, false when the time limit
     *         was reached before all animations ended
     */
    public boolean waitForAnimations(long timeout, int... animIds) {
        Player p = getLocalPlayer();
        long endTime = System.currentTimeMillis() + timeout;
        for (int animId : animIds) {
            // wait until the animation starts
            while (System.currentTimeMillis() < endTime) {
                if (p.getAnimation() == animId) {
                    break;
                } else {
                    Task.sleep(DEFAULT_MIN_WAIT, DEFAULT_MAX_WAIT);
                }
            }
            // wait until the animation finishes
            while (System.currentTimeMillis() < endTime) {
                if (p.getAnimation() != animId) {
                    break;
                } else {
                    Task.sleep(DEFAULT_MIN_WAIT, DEFAULT_MAX_WAIT);
                }
            }
            // exit when time limit passed
            if (System.currentTimeMillis() > endTime) {
                return false;
            }
        }
        return true;
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
