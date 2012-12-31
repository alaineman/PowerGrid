package powerwalk.control;

import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.model.world.Wall;
import powerwalk.view.MapViewer;

/**
 * This class collects data from the RSBot environment and stores it in the singleton WorldMap-object
 * @author Chronio
 */
public class Mapper extends Thread {
    
    /**
     * Policy for the Mapper, indicating that the world map should be updated continously.
     */
    public static final int MAP_CONTINOUSLY = 0;
    /**
     * Policy for the Mapper, indicating that the world map should be updated once, and then stop.
     */
    public static final int MAP_ONCE = 1;
    /**
     * Policy for the Mapper, indicating that the Mapper should not update the map.
     * Warning: Setting this policy manually may cause an IllegalThreadStateException 
     * to be thrown when trying to start mapping again.
     */
    public static final int MAP_NONE = 2;
    
    private static int mappingPolicy = MAP_NONE;
    private static Mapper theMapper = null;
    
    /**
     * Changes the mapping policy to the given policy.
     * When the given policy is not valid, this method does nothing.
     * @param policy the new mapping policy
     */
    public static synchronized void setPolicy(int policy) {
        if (policy >= 0 && policy <= 2) {
            mappingPolicy = policy;
        }
    }
    
    /**
     * Starts the Mapper with the given policy.
     * When the given policy is not valid, the MAP_ONCE policy will be used.
     * @param policy the policy to use for the Mapper (MAP_CONTINOUSLY or MAP_ONCE)
     * 
     * @throws IllegalThreadStateException when the Mapper is already / still running
     */
    public static synchronized void startMapping(int policy) {
        if (theMapper != null) {
            if (theMapper.isAlive()) throw new IllegalThreadStateException("Thread is still running");
        }
        if (policy < 0 || policy > 1) {
            Starter.logMessage("Illegal State set for Mapper: " + policy + ", state set to MAP_ONCE","Mapper");
            policy = MAP_ONCE;
        }
        theMapper = new Mapper();
        setPolicy(policy);
        theMapper.start();
    }
    
    /**
     * Stops the currently running Mapper.
     * <p> If there is no running Mapper, this method does nothing.
     * Otherwise, it sets the mapping policy to MAP_NONE and lets the Mapper end gracefully.
     * </p>
     * <p>
     * Please note that the Mapper might not be stopped directly when this method returns.
     * However, after this method returns, it is possible to start a new Mapper.
     * </p>
     */
    public static synchronized void stopMapping() {
        setPolicy(MAP_NONE);
        theMapper = null;
    }
    
    /**
     * Returns whether or not the Mapper is mapping.
     * 
     * <p>When the mapping policy has been set to MAP_NONE, but the Mapper hasn't 
     * completed gracefully yet, this method returns false.</p>
     * 
     * @return true if and only if the Mapper is currently mapping, returns false otherwise.
     */
    public static boolean isMapping() {
        return (mappingPolicy != MAP_NONE);
    }
    
    public static final int WATER = 0x20000;
    public static final int BLOCKED = 0x1280100;
    public static final int WALL = (0x200 | 0x400 | 0x800 | 0x1000 | 0x2000 | 0x4000 | 0x8000 | 0x10000);
    
    /**
     * run-method for the Mapper. 
     * <p>It should not be called directly. Instead, the <code>startMapping(int)</code>
     * and <code>stopMapping()</code> methods should be used.
     */
    @Override public void run() {
        
        setName("Mapper");
        Starter.logMessage("started mapping with policy: " + mappingPolicy,"Mapper");
        while (mappingPolicy != MAP_NONE) {
            try {
                Grid map = Bot.getBot().getWorldMap();
                SceneObject[] objects = SceneEntities.getLoaded();
                // Store all SceneObjects in the World Map
                for (SceneObject o : objects) {
                    Point dest = Point.fromTile(o.getLocation());
                    map.set(dest,o.getId());
                }
                if (!ToolBox.writeToFile(map.toString(), Starter.worldMapFile)) {
                    Starter.logMessage("updating the WorldMap in " + Starter.worldMapFile + " failed","Mapper");
                }
                Point pos = Bot.getBot().getPosition();
                int[][] colls = Walking.getCollisionFlags(pos.z);
                
                RegionOffset r = Players.getLocal().getRegionOffset();
                Point playerPos = Bot.getBot().getPosition();
                Point rOffset = new Point(r.getX(),r.getY(),r.getPlane());
                Point offset = playerPos.subtract(rOffset);
                Point cOffset = Point.fromTile(Walking.getCollisionOffset(pos.z));
                Point off = offset.add(cOffset);
                for (int y=-cOffset.y;y<colls.length;y++) {
                    for (int x=-cOffset.x;x<colls[0].length;x++) {
                        int cell = colls[x][y];
                        if (cell == -1) continue;
                        Point loc = new Point(off.x+x,off.x+y,pos.z);
                        if ((cell & WALL) != 0) //Walls
                            map.set(loc, -2);
                        else if ((cell & WATER) != 0) { // water
                            map.set(loc,new Wall(loc.x,loc.y,loc.z,-3));
                        } else if ((cell & BLOCKED) != 0) { // some other block type (not sure how)
                            map.set(loc, -4);
                            
                        }
                    }
                }
                
                // update the mapviewer
                if (MapViewer.theMapViewer != null) {
                    MapViewer.theMapViewer.repaint();
                }

                if (mappingPolicy == MAP_ONCE) {
                    setPolicy(MAP_NONE);
                    Starter.logMessage("stopped after runOnce","Mapper");
                    return;
                }
            } catch (Throwable t) {}
        }
        Starter.logMessage("stopped mapping","Mapper");
    }
}
