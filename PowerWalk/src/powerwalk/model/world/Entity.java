package powerwalk.model.world;

import powerwalk.control.ToolBox;
import powerwalk.model.GameObject;
import powerwalk.model.Interactable;

/**
 * Class representing mobile objects from the RSBot environment
 * @author P.Kramer
 */
public abstract class Entity extends GameObject implements Interactable {
    
    public static final int[] values = {};
    
    protected Entity(int x,int y,int z,int rawValue) {
        super(x,y,z,rawValue);
        if (ToolBox.arrayIndexOf(rawValue, values) == -1) 
            throw new IllegalArgumentException("value " + rawValue + " does not represent an Entity");
    }
}
