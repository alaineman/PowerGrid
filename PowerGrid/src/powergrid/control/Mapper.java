package powergrid.control;

import java.util.HashMap;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powergrid.PowerGrid;
import powergrid.model.GameObject;
import powergrid.model.Grid;
import powergrid.model.Point;
import powergrid.model.interact.Interactable;
import powergrid.model.world.Wall;
import powergrid.view.MapViewer;

/**
 * This class collects data from the RSBot environment and stores it in the singleton Grid-object.
 * <p/>
 * The Mapper has two main policies that can be set: 
 * <code>MAP_CONTINUOUSLY</code> and <code>MAP_ONCE</code>.
 * <code>MAP_CONTINUOUSLY</code> continuously polls the RSBot environment for 
 * map data and processes it, while the <code>MAP_ONCE</code> policy only polls
 * for data once and then stops.
 * <p/>
 * The Mapper can be started and stopped using the <code>startMapping(int policy)</code> 
 * and <code>stopMapping()</code> methods.
 * <p/>
 * When the mapper is running, the mapping policy can be set using the 
 * <code>setPolicy(int policy)</code> method.
 * <p/>
 * @author Chronio
 */
public class Mapper extends Thread {

    /**
     * Policy for the Mapper, indicating that the world map should be updated 
     * continuously.
     */
    public static final int MAP_CONTINUOUSLY = 0;
    /**
     * Policy for the Mapper, indicating that the world map should be updated once, 
     * after which the Mapper stops.
     */
    public static final int MAP_ONCE = 1;
    /**
     * Policy for the Mapper, indicating that the Mapper should not update the map.
     * <p/>It is not possible to set this Mapping policy directly. Use 
     * <code>stopMapping()</code> instead.
     */
    public static final int MAP_NONE = 2;
    
    private static volatile int mappingPolicy = MAP_NONE;
    private static Mapper theMapper = null;
    private static boolean eco_mode = false;

    /**
     * Changes the mapping policy to the given policy.
     * <p/>
     * When the given policy is not valid or the mapper is not currently mapping, 
     * this method does nothing.
     * <p/>
     * @param policy the new mapping policy (<code>MAP_ONCE</code> or <code>MAP_CONTINUOUSLY</code>)
     */
    public static synchronized void setPolicy(int policy) {
        if (mappingPolicy != MAP_NONE && policy >= 0 && policy < 2) {
            mappingPolicy = policy;
        }
    }

    /**
     * Starts the Mapper with the given policy.
     * When the given policy is not valid, the MAP_ONCE policy will be used.
     * <p/>
     * @param policy the policy to use for the Mapper (MAP_CONTINOUSLY or MAP_ONCE)
     * @throws IllegalThreadStateException when the Mapper is already / still running
     */
    public static synchronized void startMapping(int policy) {
        if (theMapper != null) {
            if (theMapper.isAlive())
                throw new IllegalThreadStateException("Thread is still running");
        }
        if (policy < 0 || policy > 1) {
            PowerGrid.logMessage("Illegal State set for Mapper: " + policy + ", state set to MAP_ONCE");
            policy = MAP_ONCE;
        }
        theMapper = new Mapper();
        mappingPolicy = policy;
        theMapper.start();
    }

    /**
     * Turns the Eco-mode of the Mapper on or off. When the Mapper runs in Eco-mode,
     * the Mapper tries to prevent mapping already mapped areas, preventing
     * unnecessary World Map writes. Instead, the Mapper tries to reduce CPU-load
     * by checking for map data less frequently, but still frequent enough to not miss any data.
     * <p/>
     * @param mode whether to enable Eco mode
     */
    public static synchronized void setEcoMode(boolean mode) {
        eco_mode = mode;
    }

    /**
     * Returns wheather the Mapper is running in eco-mode.
     * @return wheather the Mapper is running in eco-mode
     */
    public static boolean ecoMode() {
        return eco_mode;
    }

    /**
     * Stops the currently running Mapper.
     * <p/>
     * If there is no running Mapper, this method does nothing.
     * Otherwise, it sets the mapping policy to MAP_NONE and lets the Mapper end gracefully.
     * <p/>
     * Please note that the Mapper might not be stopped directly when this method returns.
     * However, after this method returns, it is possible to start a new Mapper.
     */
    public static synchronized void stopMapping() {
        mappingPolicy = MAP_NONE;
        theMapper = null;
    }

    /**
     * Returns whether or not the Mapper is mapping.
     * <p/>
     * When the stopMapping method has been called, but the Mapper hasn't
     * ended gracefully yet, this method returns false.
     * <p/>
     * @return true if and only if the Mapper is currently mapping, returns false otherwise.
     */
    public static boolean isMapping() {
        return (mappingPolicy != MAP_NONE);
    }
    
    /**
     * Returns the currently set Mapping policy.
     * <p/>
     * When the Mapper is not mapping, this method returns <code>MAP_NONE</code>
     * @return the current Mapping policy
     */
    public int getMappingPolicy() {
        return mappingPolicy;
    }
    
    /** Collision Mask for Blocked tiles */
    public static final int BLOCKED = 0x260100;
    /** Collision Mask for Water tiles, as well as mountain ranges and some other obstacles */
    public static final int WATER = 0x200000;
    /** Collision Mask for Walls */
    public static final int WALL = (0x400  | 0x1000 | 0x4000 | 0x10000);
    /** Collision Mask for low walls and fences */
    public static final int RANGEDWALL = (0x800000  | 0x2000000  | 0x8000000 | 0x20000000);
    
    private static Grid map = new Grid();
    
    /**
     * Returns the Grid that the Mapper maps to.
     * @return the Grid that the Mapper maps to
     */
    public static Grid getWorldMap() {
        return map;
    }
    
    /**
     * run-method for the Mapper.
     * <p>It should not be called directly. Instead, the
     * <code>startMapping(int policy)</code>
     * and
     * <code>stopMapping()</code> methods should be used.
     */
    @Override 
    /* Any performance issue caused by sleep in loop is not a problem here.*/
    @SuppressWarnings("SleepWhileInLoop") 
    public void run() {

        setName("Mapper");
        PowerGrid.logMessage("started mapping with policy: " + mappingPolicy);
        while (mappingPolicy != MAP_NONE) {
            boolean skip = false;
            if (eco_mode) {
                // optimize CPU-load and reduce CPU-intensity before mapping.
                // check if four corners of mappable area are set, then exit if true
                int range = 100;
                Point base = Point.fromTile(Game.getMapBase());
                boolean mapped = true; // check for mapped area
                mapped &= (map.get(base.add(new Point( range,  range))) != null);
                mapped &= (map.get(base.add(new Point(1,  range))) != null);
                mapped &= (map.get(base.add(new Point( range, 1))) != null);
                mapped &= (map.get(base.add(new Point(1,1))) != null);
                
                skip |= mapped; // skip if area is mapped
            }
            if (skip) {
                Task.sleep(3500);
            } else {
                try {
                    // get data and create data structures
                    SceneObject[] loaded;
                    int[][] flags;
                    Point offset;
                    try {
                        loaded = SceneEntities.getLoaded();
                        flags = Walking.getCollisionFlags(Game.getPlane());
                        offset = Point.fromTile(Game.getMapBase()).add(new Point(-1,-1));
                    } catch (NullPointerException e) {
                        PowerGrid.logMessage("Detected Environment unloading");
                        stopMapping();
                        break;
                    }
                    
                    HashMap<Point, GameObject> gos = new HashMap<>((int)(flags.length*flags[0].length*1.5+3));
                    HashMap<Point, Integer> ses = new HashMap<>((int)(loaded.length*1.5+3));
                    
                    // parse all data and store in data structures
                    for (SceneObject o : loaded)
                        ses.put(Point.fromTile(o.getLocation()), o.getId());
                    
                    for (int x=0;x<flags.length;x++) {
                        for (int y=0;y<flags[0].length;y++) {
                            Point p = offset.add(new Point(x,y));
                            GameObject g = map.get(p);
                            if (g instanceof Interactable)
                                continue; // don't change interactables
                            int num = -1;
                            if (ses.get(p) != null)
                                num = ses.get(p);
                            else if (g != null)
                                num = g.getRawNumber();
                            
                            switch (flags[x][y]) {
                                case -1: // ignore -1 values
                                    break;
                                case 0: // set walkable tile
                                    if (g == null) gos.put(p, new GameObject(p,0));
                                    else if (g instanceof Wall)
                                        gos.put(p, new GameObject(p, Math.abs(g.getRawNumber())));
                                    break;
                                case WATER: // set water as -5 in the Grid
                                    gos.put(p, new Wall(p, -5, Wall.BLOCK));
                                    break;
                                default:
                                    int sides = convertToSides(flags[x][y]);
                                    if (num == 85) 
                                        gos.put(p, new Wall(p, -5, Wall.BLOCK));
                                    else if (sides != 0)
                                        gos.put(p, new Wall(p,num,sides));
                                    else if (g instanceof Wall)
                                        gos.put(p, new GameObject(p,g.getRawNumber()));
                            }
                        }
                    }
                    // all data parsed; put all found GameObjects in the Grid
                    for (Point p : gos.keySet())
                        ses.remove(p);
                    if (MapViewer.theMapViewer != null) {
                        // If the MapViewer is open, hold drawing while the map 
                        // is being updated.
                        MapViewer.theMapViewer.hold(true);
                        map.addAll(ses);
                        map.addAll(gos);
                        MapViewer.theMapViewer.hold(false);
                    } else {
                        map.addAll(ses);
                        map.addAll(gos);
                    }
                    if (!XMLToolBox.writeToFile(map.toString(), "worldmap.xml")) {
                        PowerGrid.logMessage("updating the WorldMap in " + "worldmap.xml" + " failed");
                    }
                } catch (Throwable t) { 
                    // catch anything that passes by: The mapper cannot crash or hang.
                    PowerGrid.logMessage("Something went wrong while Mapping; Mapping round aborted",t);
                } 
            }

            if (mappingPolicy == MAP_ONCE) {
                setPolicy(MAP_NONE);
                PowerGrid.logMessage("Mapper stopped after runOnce");
                return;
            }

        }
        PowerGrid.logMessage("stopped mapping");
    }
    
    private int convertToSides(int flag) {
        if ((flag | 0x20100) == flag)    // Object_Block | Object_Tile flag => Collision (normal walls and such)
            return Wall.BLOCK;
        if ((flag | 0x40000100) == flag) // Object_Allow_Range | Object_Tile => Collision (fences and such)
            return Wall.BLOCK;
        int res = 0;
        if ((flag & (0x800402)) != 0)    // RangedWall_North | Wall_North => North
            res |= Wall.NORTH;
        if ((flag & (0x2001008)) != 0)   // RangedWall_East | Wall_East => East
            res |= Wall.EAST;
        if ((flag & (0x8004020)) != 0)   // RangedWall_South | Wall_South => South
            res |= Wall.SOUTH;
        if ((flag & (0x20010080)) != 0)  // RangedWall_West | Wall_West => West
            res |= Wall.WEST;
        return res;
    }
}
