package powerwalk.mapping;

import java.awt.Dimension;
import java.awt.Point;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * This class stores data from the RSbot environment.
 * It can be used as a representative of the world map.
 * @author P.Kramer
 */
public class WorldMap {
    /**
     * The map's dimension. Best set it to the world's dimension
     */
    public static final Dimension worldDim = new Dimension(1700,1800); //XXX or sth like that, very large anyways.
    
    private static WorldMap theWorldMap = null;
    
    /**
     * returns the singleton Mapper-object
     * @return the singleton Mapper-object
     */
    public static WorldMap getWorldMap() {
        if (theWorldMap == null) theWorldMap = new WorldMap(worldDim);
        return theWorldMap;
    }
    
    private ArrayList<HashMap<Integer,GameObject>> data;
    
    private WorldMap(Dimension dim) {
        data = new ArrayList<>(dim.width);
    }
    
    /**
     * registers the GameObject in the map.
     * The GameObject will be stored at the position given by its <code>getPosition()</code> method.
     * Any GameObject that is present at this position will be returned.
     * @param obj the GameObject to register
     * @return the GameObject previously at the location of the new GameObject, if any.
     */
    public synchronized GameObject set(GameObject obj) {
        Point p = obj.getPosition();
        GameObject original = get(p);
        HashMap<Integer,GameObject> column = data.get(p.x);
        if (column == null) {
            column = new HashMap<>();
            data.set(p.x,column);
        }
        column.put(p.y, obj);
        return original;
    }
    
    public GameObject get(int x,int y) {
        return data.get(x).get(y);
    }
    public GameObject get(Point p) {
        return get(p.x,p.y);
    }
}
