package powergrid.control.factory;

import org.powerbot.game.client.RSGround;
import powergrid.model.GameTile;
import powergrid.model.Point;

/**
 * Default factory class for GameObjects.
 * <p/>
 * This class can be extended to provide factories for GameTile subclasses.
 * Please do be aware that, since the accept method might be invoked often, that 
 * subclasses that override this method (which they should), make the method 
 * return the correct result as soon as possible to avoid delay in the Mapping.
 * <p/>
 * @author Chronio
 */
public class DefaultGameTileFactory {
    
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
        if (accept(p,g,c)) {
            return new GameTile(p,g,c);
        } else {
            return null;
        }
    }
}
