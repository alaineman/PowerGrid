package powerwalk.control;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.Bot;
import powerwalk.model.GameObject;

/**
 * This class collects data from the RSBot environment and stores it in the singleton WorldMap-object
 * @author P.Kramer
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
     * @param policy the policy to use for the Mapper
     * 
     * @throws IllegalThreadStateException when the Mapper is already running
     */
    public static synchronized void startMapping(int policy) {
        if (theMapper != null) {
            if (theMapper.isAlive()) throw new IllegalThreadStateException("Thread is still running");
        }
        if (policy < 0 || policy > 1) {
            Logger.getLogger("Mapper").log(Level.WARNING, "Invalid policy: {0}", policy);
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
     * Returns whether or not the Mapper is mapping
     * @return true if and only if the Mapper is currently mapping, returns false otherwise.
     */
    public static boolean isMapping() {
        return (mappingPolicy != MAP_NONE);
    }
    
    /**
     * run-method for the Mapper. It should not be called directly.
     */
    @Override public void run() {
        setName("Mapper");
        
        while (mappingPolicy != MAP_NONE) {
            
            SceneObject[] objects = SceneEntities.getLoaded();
            
            for (SceneObject o : objects) {
                Tile tile = o.getLocation();
                GameObject go = new GameObject(tile.getX(),tile.getY(),o.getType());
                GameObject orig = Bot.getBot().getWorldMap().set(go.getPosition(),go);
                if (orig != null) {
                    Logger.getLogger("Mapper").log(Level.INFO, "{0} is overwritten by {1}", new Object[] {orig, go});
                }
            }
            
            if (mappingPolicy == MAP_ONCE) {
                setPolicy(MAP_NONE);
                return;
            }
        }
    }
}
