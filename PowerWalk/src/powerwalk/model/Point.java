package powerwalk.model;

/**
 * Three dimensional Point.
 * @author P.Kramer
 */
public class Point {
    /** The X-coordinate of this Point */
    public int x;
    /** The Y-coordinate of this Point */
    public int y;
    /** The Z-coordinate of this Point */
    public int z;
    
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
        this(p.x,p.y,p.z);
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
        int dx = x - that.x;
        int dy = y - that.y;
        int dz = z - that.z;
        return Math.sqrt(dx*dx + dy*dy + dz*dz);
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
     * The returned String is a valid XML tag.
     * @return an XML-tag that represents this String
     */
    @Override public String toString() {
        return "<point x=\"" + x + "\" y=\"" + y + "\" z=\"" + z + "\" />";
    }
}
