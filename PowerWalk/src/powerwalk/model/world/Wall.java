package powerwalk.model.world;

import powerwalk.control.ToolBox;
import powerwalk.model.Collision;

/**
 * Class representing all sorts of walls in the RSBot environment
 * @author P.Kramer
 */
public class Wall extends Collision {
    
    public static final int[] values = {};
    
    public Wall(int x,int y,int z,int rawValue) {
        super (x,y,z,rawValue);
        if (ToolBox.arrayIndexOf(rawValue, values) == -1) {
            throw new IllegalArgumentException("value " + rawValue + " does not represent a wall");
        }
    }
}
