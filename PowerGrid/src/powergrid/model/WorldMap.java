package powergrid.model;

import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Objects;
import org.powerbot.game.client.RSGround;

/**
 * This class represents a World Map containing data in the Runescape world.
 * <p/>
 * It uses a HashMap to map the various Points to GameObjects, where data 
 * safety is ensured by checking for null-values.
 * <p/>
 * @author Chronio 
 */
public class WorldMap {
    
    /** The default size for a WorldMap instance. */
    public static final int DEFAULT_SIZE = 150;
    
    private HashMap<Point,GameTile> data;
    
    /**
     * Creates a new WorldMap with an initial capacity of 150.
     */
    public WorldMap() {
        this(DEFAULT_SIZE);
    }
    
    /**
     * Creates a new WorldMap with the given capacity.
     * <p/>
     * When the capacity is less than or equal to 0, the default capacity of 
     * 150 is used.
     * <p/>
     * @param capacity the initial capacity of the WorldMap
     */
    public WorldMap(int capacity) {
        if (capacity <= 0) {
            capacity = DEFAULT_SIZE;
        }
        data = new HashMap<>(capacity);
    }

    /**
     * Stores the given GameTile in this WorldMap
     * @param object the GameTile to store
     */
    public void put(GameTile object) {
        if (object != null) {
            data.put(object.getPosition(),object);
        }
    }
    
    /**
     * Stores the given RSGround and mask at the given Position.
     * @param point the Position to store
     * @param ground the RSGround object at this position
     * @param mask the collision mask of this Position
     */
    public void put(Point point, RSGround ground, int mask) {
        if (point != null) {
            data.put(point, new GameTile(point,ground,mask));
        }
    }
    
    /**
     * Returns the amount of GameObjects stored in this WorldMap.
     * <p/>
     * @return the amount of GameObjects stored in this WorldMap.
     */
    public int size() {
        return data.size();
    }
    
    /**
     * Stores the given RSGround at the given position
     * @param p the Position to store
     * @param ground the RSGround object at this position
     */
    public void putGround(Point p, RSGround ground) {
        int mask = 0;
        GameTile go = data.get(p);
        if (go != null) 
            mask = go.getCollisionFlag();
        put(p, ground, mask);
    }
    
    /**
     * Stores the given collision mask at the given position.
     * @param p the position to store
     * @param mask the collision mask at this position
     */
    public void putMask(Point p, int mask) {
        RSGround ground = null;
        GameTile go = data.get(p);
        if (go != null)
            ground = go.getRSGround();
        put(p, ground, mask);
    }
    
    /**
     * Returns whether there is a boundary (specified by mask) at the given
     * position.
     * @param p the position to check
     * @param mask the collision mask to check
     * @return true if the given position contains the boundary specified by 
     *         mask, false otherwise.
     */
    public boolean isBoundary(Point p, int mask) {
        return (get(p).getCollisionFlag() & mask) != 0;
    }
    
    /**
     * Returns the GameTile at the specified position.
     * @param p the position
     * @return the GameTile at the given position
     */
    public GameTile get(Point p) {
        return data.get(p);
    }

    @Override public int hashCode() {
        return 13 + 5 * Objects.hashCode(data);
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof WorldMap) {
            WorldMap that = (WorldMap) other;
            if (this.size() != that.size()) {
                return false;
            }
            for (Entry<Point,GameTile> e : data.entrySet()) {
                GameTile mine = e.getValue();
                GameTile theirs = that.get(e.getKey());
                if (theirs == null || !mine.equals(theirs)) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
