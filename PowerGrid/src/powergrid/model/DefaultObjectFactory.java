package powergrid.model;

import org.powerbot.game.client.RSGround;

/**
 * Default factory class for GameObjects.
 * <p/>
 * This class can be subclassed to provide factories for GameObject subclasses.
 * <p/>
 * @author Chronio
 */
public class DefaultObjectFactory {
    
    /**
     * Returns whether this factory can create a GameObject with the specified 
     * Point, RSGround, and collision flag.
     * <p/>
     * This method returns true by default.
     * <p/>
     * @param p the Point this GameObject is on
     * @param g the RSGround object for the Tile the GameObject is on
     * @param c the Collision flag for the Tile
     * @return true
     */
    public boolean accept(Point p, RSGround g, int c) {
        return true;
    }
    
    /**
     * Creates and returns a new GameObject from the given information
     * @param p the Point the GameObject is on
     * @param g the RSGround object corresponding to the Point
     * @param c the collision flag on that Point
     * @return a GameObject constructed from the given data
     */
    public GameObject create(Point p, RSGround g, int c) {
        return new GameObject(p,g,c);
    }
}
