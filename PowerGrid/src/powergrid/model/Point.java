package powergrid.model;

import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;

/**
 * This model class represents an immutable Point in 3D space. 
 * <p/>
 * It offers many mathematical operations, such as adding / substracting other 
 * Points, multiplication with a scalar, and conversion from/to polar 
 * coordinates. It also offers methods such as normalize, treating Points as 
 * vectors in 2D space.
 * <p/>
 * It replaces RSBot's Tile class, yet for compatibility it still offers 
 * possibility to convert from Tile to Point (using the appropriate 
 * constructor), and from Point to Tile (using the toTile() method).
 * Point also implements RSBot's Locatable interface, allowing Points to be 
 * used in most RSBot methods as-is.
 * <p/>
 * @author Chronio
 */
public class Point implements Locatable, Copyable {
    /** The X-coordinate of this Point. */
    public final int x;
    /** The Y-coordinate of this Point. */
    public final int y;
    /** The Z-coordinate of this Point (known as the plane in the 
     * RSBot environment). 
     */
    public final int z;
    
    /**
     * Creates a new Point at (0,0,0).
     */
    public Point() {
        x = y = z = 0;
    }
    
    /**
     * Creates a new Point with the given coordinates. 
     * The z-coordinate is taken as 0.
     * @param x the x-coordinate of the Point
     * @param y the y-coordinate of the Point
     */
    public Point(int x,int y) {
        this.x = x;
        this.y = y;
        this.z = 0;
    }
    
    /**
     * Creates a new Point with the given coordinates
     * @param x the x-coordinate of the Point
     * @param y the y-coordinate of the Point
     * @param z the z-coordinate of the Point
     */
    public Point(int x,int y,int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    /**
     * Creates a Point with the same Position as the given Point
     * @param p The Position this Point will refer to
     */
    public Point(Point p) {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    
    /**
     * Creates a new Point with the same position as the given Tile.
     * @param t The Tile this Point will refer to
     */
    public Point(Tile t) {
        x = t.getX();
        y = t.getY();
        z = t.getPlane();
    }
    
    /**
     * Parses a Point from a String.
     * <p/>
     * The String must contain one or more integer values, separated by commas.
     * The values can be surrounded by braces.
     * <p/>
     * @param s the String to parse
     * @throws IllegalArgumentException when the given String is invalid
     */
    public Point(String s) {
        if (s == null || s.isEmpty())
            throw new IllegalArgumentException("Empty String");
        try {
            s = s.replaceAll("[^,0-9]", "");
            String[] vals = s.split(",");
            if (vals.length < 2) 
                throw new IllegalArgumentException(
                        "Not enough values: minimal 2 required, found " 
                        + vals.length);
            x = Integer.parseInt(vals[0]);
            y = Integer.parseInt(vals[1]);
            if (vals.length > 2) {
                z = Integer.parseInt(vals[2]);
            } else {
                z = 0;
            }
        } catch (NumberFormatException | StringIndexOutOfBoundsException e) {
            throw new IllegalArgumentException("Invalid String: " + s, e);
        }
    }
    
    /**
     * Returns the Tile corresponding to this Point, conforming to the 
     * Locatable interface.
     * <p/>
     * This makes it possible to use Points directly as Locatables in RSBot 
     * classes and methods.
     * <p/>
     * This method is effectively the same as calling <code>toTile()</code>.
     * @return a Tile object indicating the same location as this Point
     */
    @Override public Tile getLocation() {
        return toTile();
    }
    /**
     * returns a RegionOffset object set to (0,0,0).
     * <p/>
     * This method has no real purpose whatsoever, and is only here so that 
     * Point conforms to the Locatable interface, allowing Points to be used in 
     * RSBot methods.
     * <p/>
     * This method is deprecated in the RSBot API, so it is also deprecated 
     * here.
     * <p/>
     * @return a RegionOffset object set to (0,0,0)
     */
    @Deprecated
    @Override public RegionOffset getRegionOffset() {
        return new RegionOffset(0,0,0);
    }
    
    /**
     * Returns the result of adding the given point to this Point.
     * @param p the Point to add
     * @return the sum of this Point and Point p
     */
    public Point add(Point p) {
        return new Point(x+p.x, y+p.y, z+p.z);
    }
    
    /**
     * Calculates the distance between this Point and the given Point
     * @param that the Point to calculate the distance from
     * @return the distance between this Point and the Point that
     */
    public double distance(Point that) {
        return subtract(that).length();
    }
    
    /**
     * Calculates and returns the distance between (0,0,0) and this Point.
     * @return the length of the vector denoted by this Point.
     */
    public double length() {
        return Math.sqrt(x*x + y*y + z*z);
    }
    
    /**
     * Calculates and returns the distance between (0,0) and this Point, 
     * ignoring the plane.
     * @return the length of the vector denoted by this Point, where this 
     *         Point's z coordinate is ignored.
     */
    public double lengthOnPlane() {
        return Math.sqrt(x*x + y*y);
    }
    
    /**
     * returns the angle of the vector denoted by this Point.
     * <p/>
     * The returned angle is the angle between the vector and the x-axis in 
     * radians. Positive angles rotate counterclockwise.
     * <p/>
     * The z-coordinate is ignored when the angle is calculated.
     * <p/>
     * @return the angle of the vector denoted by this Point.
     */
    public double theta() {
        return Math.atan2(y, x);
    }
    
    /**
     * returns a normalized version of this Point, treating it as a vector in 
     * 2D space (the (x,y) plane).
     * <p/>
     * It ignores the z-coordinate of the Point, it will be taken as 0.
     * <p/>
     * @return the normalized version of this Point
     */
    public Point normalize() {
        double theta = theta();
        return new Point((int)Math.cos(theta),(int)Math.sin(theta));
    }
    
    /**
     * returns a copy of this Point where each coordinate is multiplied with 
     * the scalar s.
     * <p/>
     * @param s the value to multiply this Point with
     * @return a copy of this Point where each coordinate is multiplied with 
     *         the scalar s
     */
    public Point multiply(double s) {
        return new Point((int)(s*x), (int)(s*y), (int)(s*z));
    }
    
    /**
     * Returns a Point that represents the position of this Point relative to 
     * offset.
     * <p/>
     * @param offset the offset to subtract from this Point
     * @return a Point representing the position of this Point relative to 
     *         offset
     */
    public Point subtract(Point offset) {
        return new Point(x-offset.x,y-offset.y,z-offset.z);
    }
    
    /**
     * Returns whether this Point is equal to the given object.
     * This Point is equal if and only if:
     * <ul>
     *  <li>The given object is an instance of Point</li>
     *  <li>The object has the same x, y and z coordinates</li>
     * </ul>
     * @param obj the Object to compare this Point with
     * @return true if and only if this Point is equal to the given Object, 
     *         false otherwise.
     */
    @Override public boolean equals(Object obj) {
        if (obj instanceof Point) {
            Point p = (Point)obj;
            return (x==p.x && y==p.y && z==p.z);
        }
        return false;
    }
    
    @Override public int hashCode() {
        int hash = 5;
        hash = 7 * hash + x;
        hash = 7 * hash + y;
        hash = 7 * hash + z;
        return hash;
    }
    
    /**
     * Returns a String-representation of this Point.
     * <p/>
     * The returned string is of the form "(x,y,z)", or "(x,y)" when the 
     * z-coordinate is 0.
     * <p/>
     * @return a String-representation of this Point
     */
    @Override public String toString() {
        return "(" + x + "," + y + (z == 0 ? ")" : "," + z + ")");
    }
    
    /**
     * @return a Tile object indicating the same location as this Point
     */
    public Tile toTile() {
        return new Tile(x,y,z);
    }

    /**
     * Returns a copy of this Point.
     * <p/>
     * The resulting Point has the same x, y, and z coordinates.
     * @return a copy of this Point
     */
    @Override public Point copy() {
        return new Point(x,y,z);
    }
}
