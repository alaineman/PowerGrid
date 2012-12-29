package powerwalk.control;

import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.model.Collision;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.model.world.Wall;

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
    
    /**
     * run-method for the Mapper. 
     * <p>It should not be called directly. Instead, the <code>startMapping(int)</code>
     * and <code>stopMapping()</code> methods should be used.
     */
    @Override public void run() {
        
        setName("Mapper");
        Starter.logMessage("started mapping","Mapper");
        while (mappingPolicy != MAP_NONE) {
            
            Grid map = Bot.getBot().getWorldMap();
            SceneObject[] objects = SceneEntities.getLoaded();
            
            // Store all SceneObjects in the World Map
            for (SceneObject o : objects) {
                Point dest = Point.fromTile(o.getLocation());
                //if (map.get(dest) == null || map.get(dest).getRawNumber() == -1) {
                    map.set(dest,o.getId());
                //}
            }
            /*// Override the (incomplete) detection of collisions with the 
            // collisions according to the environment when the world map doesn't
            // already have a collision set at that point.
            int blocked = 0x20000;//org.powerbot.game.api.wrappers.Tile.Flag.BLOCKED; // indicates that a tile is not walkable
            int plane = Bot.getBot().getPosition().z;
            int[][] collisions = Walking.getCollisionFlags(plane);
            Point offset = Point.fromTile(Game.getMapBase());
            for (int y=0;y<collisions.length;y++) {
                for (int x=0;x<collisions[y].length;x++) {
                    int cell = collisions[x][y];
                    
                    if ((cell & blocked) != 0 && cell != -1) { // if bitmask results in non-zero, it matches the pattern for a blocked tile
                        Point dest = new Point(x+offset.x,y+offset.y,plane);
                        if (!(map.get(dest) instanceof Collision)) {
                            //Starter.logMessage(dest + " set to Collision using cellValue " + cell,"Mapper <debug>");
                            map.set(dest,new Wall(dest.x,dest.y,dest.z,-1));
                        }
                    }
                }
            }*/
            
            if (!ToolBox.writeToFile(map.toString(), Starter.worldMapFile)) {
                Starter.logMessage("updating the WorldMap in " + Starter.worldMapFile + " failed","Mapper");
            }
            Starter.logMessage("Map updated","Mapper");
            if (mappingPolicy == MAP_ONCE) {
                setPolicy(MAP_NONE);
                Starter.logMessage("stopped after runOnce","Mapper");
                return;
            }
        }
        Starter.logMessage("stopped mapping","Mapper");
    }
}
