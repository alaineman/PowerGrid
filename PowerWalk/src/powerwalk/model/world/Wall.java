package powerwalk.model.world;

import powerwalk.model.Collision;

/**
 * Class representing all sorts of walls in the RSBot environment
 * @author Chronio
 */
public class Wall extends Collision {
    
    public static final int[] values = {
        -2, // Wall objects according to Walking.getCollsionFlags(), unknown wall type
        
        870,872,937,957,982,983,984, // Draynor village house walls
        
        1000,1378,1379, // generic blocks / walls
        
        
        4203, // Fremmenik city house walls
        4262, // Fremmenik region fences
        
        4676,4677,4679,4681, // Fremmenik city outer house walls
        4711,4713, // Fremmenik city door post walls
        4730,4732,4760,4761,4882,4888, //Fremmenik city inner house walls
        
        12993,12994,12996,12997,12998, // Varrock Tent
        
        16746,16747,16749,16750,16751,16752, // Lunar house Walls
        16761, // Lunar city inner fence
        16782,16783, // Lunar city walls
        
        23638,23641,23642,23643,23655,23662,23676,23689,23692,23694, // (older) Varrock walls
        23710,23711,23735,23738,23739,23740,23744,23745,23748,23750,23751,23755,23756,23757,23779,23780, // Varrock walls
        23806,23818,23824,23825,23826,23829,23834,23835,23836, // Varrock walls/fences
        23837,23841,23842,23844,23849,23851,23870, // Varrock walls/fences
        23922,23923, // Varrock walls
        
        35305,35306,35330,35331,35332,35333,35336,35340,35341 // Varrock walls
    };
    
    public Wall(int x,int y,int z,int rawValue) {
        super (x,y,z,rawValue);
    }
}
