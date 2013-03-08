package powergrid.model.world.elevator;

import java.util.Arrays;
import powergrid.model.GameObject;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.interact.Interactable;

/**
 * Represents a GameObject that can be used to move from one plane to another.
 * @author Chronio
 * @author Alaineman
 */
public abstract class Elevator extends GameObject implements Interactable {
    /** Specifies movement upward */
    public static final int UP = 1;
    /** Specifies movement downward */
    public static final int DOWN = 2;
    
    private int[] otherPlanes = new int[0];
    
    /**
     * Creates a new Elevator object
     * @param x the x-coordinate
     * @param y the y-coordinate
     * @param z the z-coordinate
     * @param rawValue 
     * @param otherPlanes 
     */
    public Elevator(int x,int y,int z,int rawValue,int[] otherPlanes) {
        super(new Point(x,y,z),rawValue);
        if (otherPlanes == null) throw new IllegalArgumentException("Null-array for other planes");
        this.otherPlanes = otherPlanes;
        Arrays.sort(this.otherPlanes);
    }
    
    public abstract void move(int direction) throws OutOfReachException;
    
    public synchronized boolean connectsTo(int plane) {
        return -1 != Arrays.binarySearch(otherPlanes,plane);
    }
    
    public synchronized void addPlane(int plane) {
        if (!connectsTo(plane)) {
            int[] extended = new int[otherPlanes.length+1];
            System.arraycopy(otherPlanes, 0, extended, 0, otherPlanes.length);
            extended[otherPlanes.length] = plane;
            Arrays.sort(extended);
            otherPlanes = extended;
        }
    }
    
    public synchronized int[] getOtherPlanes() {
        return otherPlanes.clone();
    }
}
