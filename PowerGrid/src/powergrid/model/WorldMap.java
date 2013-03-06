package powergrid.model;

import java.util.HashMap;
import org.powerbot.game.client.RSGround;
import powergrid.model.WorldMap.Field;

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
    
    private HashMap<Point,Field> data;
    
    public WorldMap() {
        this(150);
    }
    
    public WorldMap(int capacity) {
        data = new HashMap<>(capacity);
    }

    public void put(Point point, RSGround ground, int mask) {
        if (point != null) {
            data.put(point, new Field(ground,mask));
        }
    }
    
    public void putGround(Point p, RSGround ground) {
        int mask = 0;
        Field f = data.get(p);
        if (f != null) 
            mask = f.mask();
        put(p, ground, mask);
    }
    
    public void putMask(Point p, int mask) {
        RSGround ground = null;
        Field f = data.get(p);
        if (f != null)
            ground = f.ground();
        put(p, ground, mask);
    }
    
    public boolean isBoundary(Point p, int mask) {
        Field f = data.get(p);
        if (f == null) return false;
        return (f.mask() & mask) != 0;
    }
    
    public Field getField(Point p) {
        return data.get(p);
    }
    
    public RSGround getGround(Point p) {
        Field f = data.get(p);
        if (f == null) return null;
        return f.ground();
    }
    
    public GameObject getObject(Point p) {
        Field f = data.get(p);
        if (f == null || f.ground() == null) 
            return null;
        //TODO instantiate GameObject
        return null;
    }
    
    public static class Field {
        private RSGround ground;
        private int mask;
        public Field (RSGround ground, int mask) {
            this.ground = ground;
            this.mask = mask;
        }
        public RSGround ground() {
            return ground;
        }
        public int mask() {
            return mask;
        }
    }
}
