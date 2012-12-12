package powerwalk.model;

import java.awt.Point;

/**
 *
 * @author Vincent W, P.Kramer
 */
public class DungeonMap {
    
    private Point offset = new Point(0,0);
    
    
    public DungeonMap(Point offset) {
        this.offset = new Point(offset.x,offset.y);
    }
    
    public Point getOffset() {
        return new Point(offset.x,offset.y);
    }
    
    
    
}
