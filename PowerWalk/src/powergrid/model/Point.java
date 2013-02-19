package powergrid.model;

import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;

/**
 * This model class represents a Point in 3D space. 
 * <p/>
 * It offers many mathematical operations, such as adding / substracting other 
 * Points, multiplication with a scalar, and conversion from/to polar coordinates.
 * <p/>
 * It replaces RSBot's Tile class, yet for compatibility it still offers possibility 
 * to convert from Tile to Point (using the static fromTile(tile) method), and from 
 * Point to Tile (using the toTile() method).
 * Point also implements RSBot's Locatable interface, allowing Points to be used 
 * in most RSBot methods as-is.
 * <p/>
 * @author Chronio
 */
public class Point implements Locatable {
    /** The X-coordinate of this Point */
    public int x = 0;
    /** The Y-coordinate of this Point */
    public int y = 0;
    /** The Z-coordinate of this Point (this was known as the plane in the RSBot environment) */
    public int z = 0;
    
    /**
     * Creates a new Point at (0,0,0).
     */
    public Point() {}
    
    /**
     * Creates a new Point with the given coordinates. 
     * The z-coordinate is taken as 0.
     * @param x the x-coordinate of the Point
     * @param y the y-coordinate of the Point
     */
    public Point(int x,int y) {
        this.x = x;
        this.y = y;
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
        this(p.x,p.y,p.z);
    }
    
    /**
     * Returns the Tile corresponding to this Point, conforming to the Locatable
     * interface.
     * <p/>
     * This makes it possible to use Points directly as Locatables in RSBot classes and methods.
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
     * This method has no real purpose whatsoever, and is only here so that Point 
     * conforms to the Locatable interface, allowing Points to be used in RSBot methods.
     * <p/>
     * @return a RegionOffset object set to (0,0,0)
     */
    @Override public RegionOffset getRegionOffset() {
        return null;
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
     * Calculates and returns the distance between (0,0) and this Point, ignoring the plane.
     * @return the length of the vector denoted by this Point, where this Point's z coordinate is taken as 0.
     */
    public double lengthOnPlane() {
        return Math.sqrt(x*x + y*y);
    }
    
    /**
     * returns the angle of the vector denoted by this Point.
     * <p/>
     * The returned angle is the angle between the vector and the x-axis. 
     * Positive angles rotate counterclockwise.
     * @return the angle of the vector denoted by this Point.
     */
    public double theta() {
        return Math.atan2(y, x);
    }
    
    /**
     * returns a normalized version of this Point, treating it as a vector in 2D space (the (x,y) plane).
     * It discards the plane information of Point, the z-coordinate of the resulting Point is 0.
     * @return the normalized version of this Point
     */
    public Point normalize() {
        double theta = theta();
        return new Point((int)Math.cos(theta),(int)Math.sin(theta));
    }
    
    /**
     * returns a copy of this Point where each coordinate is multiplied with the scalar s.
     * @param s the number to multiply this Point with
     * @return a copy of this Point where each coordinate is multiplied with the scalar s
     */
    public Point multiply(double s) {
        return new Point((int)(s*x), (int)(s*y), (int)(s*z));
    }
    
    /**
     * Returns a Point that represents the position of this Point relative to offset
     * @param offset the offset to subtract from this Point
     * @return a Point representing the position of this Point relative to offset
     */
    public Point subtract(Point offset) {
        return new Point(x-offset.x,y-offset.y,z-offset.z);
    }
    
    /**
     * Returns whether this Point is equal to the given object.
     * This Point is equal if and only if:
     * <ul>
     *  <li>The given object is an instance of Point</li>
     *  <li>The object points to the same position</li>
     * </ul>
     * @param obj the Object to compare this Point with
     * @return true if and only if this Point is equal to the given Object, false otherwise.
     */
    @Override public boolean equals(Object obj) {
        if (obj instanceof Point) {
            Point p = (Point)obj;
            return (x==p.x && y==p.y && z==p.z);
        }
        return false;
    }
    
    /**
     * calculates the hashCode corresponding to this Point.
     * @return the hashCode corresponding to this Point
     */
    @Override public int hashCode() {
        int hash = 5;
        hash = 7 * hash + x;
        hash = 7 * hash + y;
        hash = 7 * hash + z;
        return hash;
    }
    
    /**
     * Returns a String-representation of this Point.
     * The returned string is of the form "(x,y,z)"
     * @return a String-representation of this Point
     */
    @Override public String toString() {
        return "(" + x + "," + y + (z == 0 ? ")" : "," + z + ")");
    }
    
    /**
     * Parses a Point from a String that contains one or more values separated by "," and surrounded by braces.
     * 
     * @param s the String to parse
     * @throws NumberFormatException when one or more values could not be parsed
     * @return the Point denoted by this String
     */
    public static Point fromString(String s) {
        int start = s.indexOf("(")+1;
        int end   = s.indexOf(")");
        String[] vals = s.substring(start,end).split(",");
        int x=0,y=0,z=0;
        if (vals.length>0) x = Integer.parseInt(vals[0]);
        if (vals.length>1) y = Integer.parseInt(vals[1]);
        if (vals.length>2) z = Integer.parseInt(vals[2]);
        
        return new Point(x,y,z);
    }
    
    /**
     * Returns a Tile-representative of this Point
     * @return a Tile object indicating the same location as this Point
     */
    public Tile toTile() {
        return new Tile(x,y,z);
    }
    
    /**
     * Returns a Point-representative of the given Tile
     * @param t the Tile to create a Point object for.
     * @return a Point object indicating the same location as the given Tile
     */
    public static Point fromTile(Tile t) {
        return new Point(t.getX(),t.getY(),t.getPlane());
    }
    
    /**
     * Creates a new Point from the given Polar coordinates.
     * @param theta the angle
     * @param r the length
     * @return a Point representing the position denoted by the given polar coordinates.
     */
    public static Point fromPolar(double theta, double r) {
        int x = (int)(r * Math.cos(theta));
        int y = (int)(r * Math.sin(theta));
        return new Point(x,y);
    }
   
}
