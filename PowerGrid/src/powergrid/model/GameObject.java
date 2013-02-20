package powergrid.model;

/**
 * This class represents an object from the RSbot environment.
 * 
 * @author Chronio
 * 
 */
public class GameObject {
    private int x = 0;
    private int y = 0;
    private int z = 0;
    
    private int rawNumber = -1;
    
    /**
     * Creates a new GameObject at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param rawNumber the raw value from the environment specifying the type
     */
    public GameObject(int x,int y,int rawNumber) {
        this.x = x;
        this.y = y;
        this.rawNumber = rawNumber;
    }
    /**
     * Creates a new GameObject at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param z the z-coordinate of this object
     * @param rawNumber the raw value from the environment specifying the type
     */
    public GameObject(int x,int y,int z,int rawNumber) {
        this(x,y,rawNumber);
        this.z = z;
    }
    
    /**
     * Creates a new GameObject at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param p the position of this GameObject
     * @param rawNumber the raw value from the environment specifying the type
     * @throws IllegalArgumentException when the provided Point is null
     */
    public GameObject(Point p, int rawNumber) {
        if (p == null)
            throw new IllegalArgumentException("");
        x = p.x;
        y = p.y;
        z = p.z;
        this.rawNumber = rawNumber;
    }
    /**
     * returns the position of this GameObject. 
     * The location corresponds to the Tile object it's found on
     * @return the position of this GameObject.
     */
    public Point getPosition() {
        return new Point(x,y,z);
    }
    
    /**
     * returns the raw number as given by the RSBot environment.
     * @return the raw number as given by the RSBot environment.
     */
    public int getRawNumber() {
        return rawNumber;
    }

    /**
     * Sets the position of this GameObject to the new Position, when the given 
     * position is not null.
     * <p/>
     * Note that, obviously, this does not actually move the corresponding RS Object.
     * Therefore, calling this without a good reason will probably lead to data 
     * inconsistency and therefore prevent PowerWalk from creating correct paths.
     * <p/>
     * @param p the new Position of this Object
     */
    public void setPosition(Point p) {
        if (p != null) {
            x = p.x;
            y = p.y;
            z = p.z;
        }
    }
    
    /**
     * Sets the raw value of this GameObject.
     * <p/>
     * Note that, obviously, this does not actually change the corresponding RS Object.
     * Therefore, calling this without a good reason will probably lead to data 
     * inconsistency and therefore prevent PowerWalk from creating correct paths.
     * <p/>
     * @param value the new raw value for this Object
     */
    public void setRawValue(int value) {
        rawNumber = value;
    }
    
    /**
     * Returns the hash code of this GameObject
     * @return the hash code of this GameObject
     */
    @Override public int hashCode() {
        int hash = 3;
        hash = 47 * hash + this.x;
        hash = 47 * hash + this.y;
        hash = 47 * hash + this.z;
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
            return this.getPosition().equals(that.getPosition()) && this.getRawNumber() == that.getRawNumber();
        }
        return false;
    }
    
}
