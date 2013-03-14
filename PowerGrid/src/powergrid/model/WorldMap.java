package powergrid.model;

import java.util.HashMap;
import org.powerbot.game.client.RSGround;

/**
 * Custom extension of a HashMap designed for Mapping purposes, where data 
 * safety is ensured by copying incoming Point-objects and checking for null-values.
 * <p/>
 * It is also possible to extract GameObjects by calling the <code>getObject</code>
 * method.
 * 
 * @author Chronio 
 */
public class WorldMap {
    
    private HashMap<Point,GameObject> data;
    
    public WorldMap() {
        this(150);
    }
    
    public WorldMap(int capacity) {
        data = new HashMap<>(capacity);
    }

    public void put(Point point, RSGround ground, int mask) {
        if (point != null) {
            data.put(point, new GameObject(point,ground,mask));
        }
    }
    
    public void putGround(Point p, RSGround ground) {
        int mask = 0;
        GameObject go = data.get(p);
        if (go != null) 
            mask = go.getCollisionFlag();
        put(p, ground, mask);
    }
    
    public void putMask(Point p, int mask) {
        RSGround ground = null;
        GameObject go = data.get(p);
        if (go != null)
            ground = go.getRSGround();
        put(p, ground, mask);
    }
    
    public boolean isBoundary(Point p, int mask) {
        return (get(p).getCollisionFlag() & mask) != 0;
    }
    
    public GameObject get(Point p) {
        return data.get(p);
    }
}
