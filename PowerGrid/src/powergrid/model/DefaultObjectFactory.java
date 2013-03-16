package powergrid.model;

import org.powerbot.game.client.RSGround;

/**
 * Default factory class for GameObjects.
 * <p/>
 * This class can be extended to provide factories for GameTile subclasses.
 * <p/>
 * @author Chronio
 */
public class DefaultObjectFactory {
    
    /**
     * Returns whether this factory can create a GameTile with the specified 
     * Point, RSGround, and collision flag.
     * <p/>
     * This method returns true by default.
     * <p/>
     * @param p the Point this GameTile is on
     * @param g the RSGround object for the Tile the GameTile is on
     * @param c the Collision flag for the Tile
     * @return true
     */
    public boolean accept(Point p, RSGround g, int c) {
        return true;
    }
    
    /**
     * Creates and returns a new GameTile from the given information
     * @param p the Point the GameTile is on
     * @param g the RSGround object corresponding to the Point
     * @param c the collision flag on that Point
     * @return a GameTile constructed from the given data
     */
    public GameTile create(Point p, RSGround g, int c) {
        return new GameTile(p,g,c);
    }
}
