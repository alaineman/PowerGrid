package powergrid.model;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSObject;

/**
 * This class represents a Tile in the Runescape world.
 * @author Chronio
 */
public class GameTile {
    private Point position;
    private int rawNumber = -1;
    private int collFlag = 0;
    private RSGround ground = null;
    
    /**
     * Creates a new GameTile at the given position. the <code>rawNumber</code> 
     * indicates the type of object on this Tile as provided by the RSBot 
     * environment.
     * <p/>
     * @param p the position of this GameTile
     * @param rawNumber the raw value from the environment specifying the type
     * @throws IllegalArgumentException when the provided Point is null
     * @deprecated Use GameTile(Point,RSGround,int) instead
     */
    @Deprecated public GameTile(Point p, int rawNumber) {
        assert p != null;
        position = p;
        this.rawNumber = rawNumber;
    }
    
    /**
     * Creates a new GameTile with the given information.
     * @param p the position of this GameTile
     * @param g the RSGround object with the contents of this GameTile
     * @param collFlag the collision flag of this Tile
     */
    public GameTile(Point p, RSGround g, int collFlag) {
        assert p != null;
        position = p;
        ground = g;
        this.collFlag = collFlag;
    }
    
    /**
     * returns the position of this GameTile.
     * @return the position of this GameTile
     */
    public Point getPosition() {
        return position;
    }
    
    /**
     * Returns a raw number as given by the RSBot environment.
     * <p/>
     * It returns -1 when there are no objects at this position.
     * @return the raw number as given by the RSBot environment
     * @deprecated use <code>containsRawNumber(int)</code> or 
     *             <code>objects()</code> instead.
     */
    @Deprecated public int getRawNumber() {
        RSObject[] objects = objects();
        if (objects.length > 0) {
            return objects[0].getId();
        } else {
            return -1;
        }
    }
    
    /**
     * Returns the RSGround object linked to this GameTile.
     * @return the RSGround object at the position of this GameTile
     */
    public RSGround getRSGround() {
        return ground;
    }
    
    /**
     * Returns an array containing the RSObjects on this GameTile
     * @return an array containing the RSObjects
     */
    public RSObject[] objects() {
        if (ground == null) 
            return new RSObject[0];
        ArrayList<RSObject> objects = new ArrayList<>(5);
        RSObject obj;
        if ((obj = ground.getBoundary1()) != null)
            objects.add(obj);
        if ((obj = ground.getBoundary2()) != null)
            objects.add(obj);
        if ((obj = ground.getFloorDecoration()) != null)
            objects.add(obj);
        if ((obj = ground.getWallDecoration1()) != null)
            objects.add(obj);
        if ((obj = ground.getWallDecoration2()) != null)
            objects.add(obj);
        return objects.toArray(new RSObject[objects.size()]);
    }
    
    /**
     * Returns the collision flag for this GameTile
     * @return this GameTile's collision flag
     */
    public int getCollisionFlag() {
        return collFlag;
    }
    
    /**
     * Returns an array containing the raw values of the RSObjects on this GameTile.
     * @return an array containing the raw values of the RSObjects
     */
    public int[] rawValues() {
        if (ground == null) 
            return new int[] {rawNumber};
        RSObject[] rsos = objects();
        int[] vals = new int[rsos.length];
        for (int i = 0; i < rsos.length; i++) {
            vals[i] = rsos[i].getId();
        }
        return vals;
    }
    
    /**
     * Returns whether this GameTile contains an RSObject with the specified value as ID.
     * @param value the value to check
     * @return true if this GameTile contains an RSObject with the specified value, false otherwise
     */
    public boolean containsRawValue(int value) {
        for (int i : rawValues()) {
            if (i == value) return true;
        }
        return false;
    }
    
    /**
     * Returns whether this GameTile contains the given Wall type.
     * @param type the type of Wall
     * @return whether this GameTile contains the given Wall type.
     */
    public boolean containsWall(int type) {
        return (type & collFlag) != 0;
    }
    
    /**
     * Returns the raw value of a boundary on this Tile, if any.
     * <p/>
     * If there are multiple boundary values for this Tile, the first one is returned.
     * <p/>
     * When no boundaries are on this Tile, -1 is returned.
     * @return the raw value of a boundary on this Tile, or -1 is no boundary exists.
     */
    public int getBoundary() {
        RSObject o = ground.getBoundary1();
        if (o == null)
            o = ground.getBoundary2();
        if (o == null)
            return -1;
        return o.getId();
    }
    
    /**
     * Returns the hash code of this GameTile
     * @return the hash code of this GameTile
     */
    @Override public int hashCode() {
        int hash = 3;
        hash = 47 * hash + Objects.hashCode(position);
        hash = 47 * hash + Objects.hashCode(objects());
        return hash;
    }
    
    /**
     * Returns whether or not this object is equal to <code>other</code>.
     * <p>More specifically, this method returns true if and only if:
     * <ul>
     *   <li>other is an instance of GameTile</li>
     *   <li>other is at the same position as given by the method <code>getPosition()</code></li>
     *   <li>other has the same raw values, as given by the method <code>rawValues()</code></li>
     * </ul>
     * This method returns false otherwise.
     * </p>
     * @param other the object to compare with
     * @return true if and only if this object is equal to other
     */
    @Override public boolean equals(Object other) {
        if (other instanceof GameTile) {
            GameTile that = (GameTile)other;
            return this.getPosition().equals(that.getPosition()) 
                    && Arrays.equals(this.rawValues(), that.rawValues())
                    && this.getCollisionFlag() == that.getCollisionFlag();
        }
        return false;
    }

    /**
     * Returns a String-representation of this GameTile containing the position 
     * and raw values.
     * <p/>
     * @return a String-representation of this GameTile
     */
    @Override public String toString() {
        String lead = "GameTile@" + position + "(" + collFlag + ",{";
        String objects = "";
        for (RSObject o : objects()) {
            objects += "," + o.getId();
        }
        return lead + objects.substring(1) + "})";
    }
}
