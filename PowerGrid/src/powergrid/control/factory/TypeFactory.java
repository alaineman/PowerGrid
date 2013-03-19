/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.control.factory;

import org.powerbot.game.client.RSGround;
import powergrid.model.GameTile;
import powergrid.model.Point;

/**
 * Interface for the Factories that are linked to the TileFactory.
 * <p/>
 * A TypeFactory is a factory class that handles a part of the object types
 * when mapping the Runescape environment.
 * <p/>
 * Implement this interface into a custom Factory class and register it in the 
 * TileFactory of the Mapper to have the Mapper map instances of your custom 
 * classes.
 * <p/>
 * @author Chronio
 */
public interface TypeFactory extends Comparable<TypeFactory> {

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
    public boolean accept(Point p, RSGround g, int c);

    /**
     * Creates and returns a new GameTile from the given information
     * @param p the Point the GameTile is on
     * @param g the RSGround object corresponding to the Point
     * @param c the collision flag on that Point
     * @return a GameTile constructed from the given data
     */
    public GameTile create(Point p, RSGround g, int c);
    
}
