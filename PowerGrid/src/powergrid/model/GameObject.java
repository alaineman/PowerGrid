package powergrid.model;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSObject;

/**
 * This class represents an object from the RSbot environment.
 * @author Chronio
 */
public class GameObject {
    private Point position;
    private int rawNumber = -1;
    private int collFlag = 0;
    private RSGround ground = null;
    
    /**
     * Creates a new GameObject at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * <p/>
     * @param p the position of this GameObject
     * @param rawNumber the raw value from the environment specifying the type
     * @throws IllegalArgumentException when the provided Point is null
     */
    public GameObject(Point p, int rawNumber) {
        assert p != null;
        position = p;
        this.rawNumber = rawNumber;
    }
    
    public GameObject(Point p, RSGround g, int collFlag) {
        assert p != null && g != null;
        position = p;
        ground = g;
        this.collFlag = collFlag;
    }
    
    /**
     * returns the position of this GameObject.
     * @return the position of this GameObject
     */
    public Point getPosition() {
        return position;
    }
    
    /**
     * Returns a raw number as given by the RSBot environment.
     * <p/>
     * <strong>Deprecated: use <code>containsRawNumber(int)</code> and/or 
     * <code>rawValues()</code> instead.</strong>
     * <p/>
     * It returns a value &lt; 0 when there are no objects at this position.
     * @return the raw number as given by the RSBot environment
     */
    @Deprecated public int getRawNumber() {
        if (ground == null)
            return -1;
        /* Sorry for the messy syntax, but this basically polls each object type
         * in order until a non-null value is found. This is a bit cleaner 
         * than having 6 return statements (and most likely faster, too).
         */
        RSObject obj;
        if ((obj = ground.getBoundary1()) == null)
            if ((obj = ground.getBoundary2()) == null)
                if ((obj = ground.getFloorDecoration()) == null)
                    if ((obj = ground.getWallDecoration1()) == null)
                        if ((obj = ground.getWallDecoration2()) == null)
                            return -1; // There are no objects on this position
        return obj.getId();
    }
    
    /**
     * Returns an array containing the RSObjects on this GameObject
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
     * Returns the collision flag for this GameObject
     * @return this GameObject's collision flag
     */
    public int getCollisionFlag() {
        return collFlag;
    }
    
    /**
     * Returns an array containing the raw values of the RSObjects on this GameObject.
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
     * Returns whether this GameObject contains an RSObject with the specified value as ID.
     * @param value the value to check
     * @return true if this GameObject contains an RSObject with the specified value, false otherwise
     */
    public boolean containsRawValue(int value) {
        for (int i : rawValues()) {
            if (i == value) return true;
        }
        return false;
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
     * Returns the hash code of this GameObject
     * @return the hash code of this GameObject
     */
    @Override public int hashCode() {
        int hash = 3;
        hash = 47 * hash + Objects.hashCode(position);
        hash = 47 * hash + this.rawNumber;
        return hash;
    }
    
    /**
     * Returns whether or not this object is equal to <code>other</code>.
     * <p>More specifically, this method returns true if and only if:
     * <ul>
     *   <li>other is an instance of GameObject</li>
     *   <li>other is at the same position as given by the method <code>getPosition()</code></li>
     *   <li>other has the same raw type, as given by the method <code>getRawNumber()</code></li>
     * </ul>
     * This method returns false otherwise.
     * </p>
     * @param other the object to compare with
     * @return true if and only if this object is equal to other
     */
    @Override public boolean equals(Object other) {
        if (other instanceof GameObject) {
            GameObject that = (GameObject)other;
            return this.getPosition().equals(that.getPosition()) && Arrays.equals(this.rawValues(), that.rawValues());
        }
        return false;
    }

    /**
     * Returns a String-representation of this GameObject containing the position 
     * and raw values.
     * <p/>
     * @return a String-representation of this GameObject
     */
    @Override public String toString() {
        String lead = "GameObject@" + position + "[";
        String objects = "";
        for (RSObject o : objects()) {
            objects += "," + o.getId();
        }
        return lead + objects.substring(1) + "]";
    }
}
