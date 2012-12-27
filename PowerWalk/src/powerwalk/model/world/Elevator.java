package powerwalk.model.world;

import java.util.Arrays;
import powerwalk.control.ToolBox;
import powerwalk.model.GameObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.interact.Interactable;

/**
 * Represents a GameObject that can be used to move from one plane to another.
 * @author Chronio
 * @author Alaineman
 */
public abstract class Elevator extends GameObject implements Interactable {
    
    public static final int[] values = new int[] {};
    
    private int[] otherPlanes;
    
    public Elevator(int x,int y,int z,int rawValue,int[] otherPlanes) {
        super(x,y,z,rawValue);
        if (otherPlanes == null) throw new IllegalArgumentException("Null-array for other planes");
        this.otherPlanes = otherPlanes;
        Arrays.sort(this.otherPlanes);
    }
    
    public abstract void ascend() throws OutOfReachException;
    public abstract void descend() throws OutOfReachException;
    
    public boolean connectsTo(int plane) {
        return -1 != ToolBox.sortedArrayIndexOf(plane, otherPlanes);
    }
    
    public int[] getOtherPlanes() {
        return otherPlanes.clone();
    }
}
