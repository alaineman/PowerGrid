package powerwalk.model.world;

import powerwalk.control.ToolBox;
import powerwalk.model.Collision;

/**
 * Class representing all sorts of walls in the RSBot environment
 * @author P.Kramer
 */
public class Wall extends Collision {
    
    public static final int[] values = {
        1000,1378,1379, // generic blocks / walls
        
        12993,12994,12996,12997,12998, // Varrock Tent
        
        23638,23641,23642,23643,23655,23662,23676,23689,23692,23694, // (older) Varrock walls
        23710,23711,23735,23738,23739,23740,23745,23748,23750,23751,23755,23756,23757,23779,23780, // Varrock walls
        23806,23818,23824,23825,23826,23829,23834,23835,23836, // Varrock walls/fences
        23837,23841,23842,23844,23849,23851,23870, // Varrock walls/fences
        23922,23923, // Varrock walls
        
        35305,35306,35330,35331,35332,35333,35336,35340,35341 // Varrock walls
    };
    
    public Wall(int x,int y,int z,int rawValue) {
        super (x,y,z,rawValue);
        if (ToolBox.sortedArrayIndexOf(rawValue, values) == -1) {
            throw new IllegalArgumentException("value " + rawValue + " does not represent a wall");
        }
    }
}
