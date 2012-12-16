package powerwalk.model.world;

import powerwalk.model.GameObject;
import powerwalk.model.interact.Interactable;

/**
 * Class representing mobile objects from the RSBot environment
 * @author P.Kramer
 */
public abstract class Entity extends GameObject implements Interactable {
    
    /**
     * The raw values that belong to Entities.
     */
    public static final int[] values = {};
    
    /**
     * Creates a new Entity at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param z the z-coordinate of this object
     * @param rawNumber the raw value from the environment specifying the type
     */
    protected Entity(int x,int y,int z,int rawValue) {
        super(x,y,z,rawValue);
    }
}
