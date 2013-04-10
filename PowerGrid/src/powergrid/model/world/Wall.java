package powergrid.model.world;

import powergrid.model.Point;
import powergrid.model.rsbot.RSGroundImpl;

/**
 * Class representing all sorts of walls in the RSBot environment
 * @author Chronio
 * @deprecated 
 */
@Deprecated
public class Wall extends GameTile {
    /** No Walls */
    public static final int EMPTY = 0x0;
    /** Wall on North side */
    public static final int NORTH = 0x1;
    /** Wall on East side */
    public static final int EAST  = 0x2;
    /** Wall on South side */
    public static final int SOUTH = 0x4;
    /** Wall on West side */
    public static final int WEST  = 0x8;
    
    /** Wall on all sides, This tile cannot be entered at all */
    public static final int BLOCK = NORTH | EAST | SOUTH | WEST;
    
    private int type = 0;
    
    /**
     * Creates a new Wall object at the specified location and with the specified raw value and type
     * <p/>
     * @param p the position of the Wall
     * @param rawValue the Raw Value of the wall
     * @param type the wall type, specified as a bitwise OR between the Wall.NORTH, Wall.SOUTH, Wall.WEST, and WALL.EAST values
     */
    public Wall(Point p,int rawValue, int type) {
        super (p, new RSGroundImpl(rawValue), -1);
        this.type = type;
    }
    
    public Wall(int x, int y, int z, int rawValue) {
        this(new Point(x,y,z),rawValue,BLOCK);
    }
    
    public boolean containsType(int type) {
        return (this.type & type) != 0;
    }
    
    public boolean isType(int type) {
        return this.type == type;
    }
    
    public boolean isFree(int type) {
        return (this.type & type) == 0;
    }
    
    public int getType() {
        return type;
    }
    
    public void setType(int type) {
        if (type <= 0 || type > BLOCK) 
            throw new IllegalArgumentException("Invalid Wall Type");
        this.type = type;
    }
}
