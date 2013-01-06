package powerwalk.control;

import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.node.SceneObject;
import org.powerbot.x;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.view.MapViewer;

/**
 * This class collects data from the RSBot environment and stores it in the singleton WorldMap-object
 * <p/>
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
    private static boolean eco_mode = false;

    /**
     * Changes the mapping policy to the given policy.
     * When the given policy is not valid, this method does nothing.
     * <p/>
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
     * <p/>
     * @param policy the policy to use for the Mapper (MAP_CONTINOUSLY or MAP_ONCE)
     * <p/>
     * @throws IllegalThreadStateException when the Mapper is already / still running
     */
    public static synchronized void startMapping(int policy) {
        if (theMapper != null) {
            if (theMapper.isAlive())
                throw new IllegalThreadStateException("Thread is still running");
        }
        if (policy < 0 || policy > 1) {
            Starter.logMessage("Illegal State set for Mapper: " + policy + ", state set to MAP_ONCE", "Mapper");
            policy = MAP_ONCE;
        }
        theMapper = new Mapper();
        setPolicy(policy);
        theMapper.start();
    }

    /**
     * Turns the Eco-mode of the Mapper on or off. When the Mapper runs in Eco-mode,
     * the Mapper tries to prevent mapping already mapped areas, preventing
     * unnecessary World Map writes. Instead, the Mapper tries to reduce CPU-load
     * by checking for map data less frequently, but still frequent enough to not miss any data.
     * <p/>
     * @param mode
     */
    public static synchronized void setEcoMode(boolean mode) {
        eco_mode = mode;
    }

    public static boolean ecoMode() {
        return eco_mode;
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
     * <p/>
     * <p>When the mapping policy has been set to MAP_NONE, but the Mapper hasn't
     * completed gracefully yet, this method returns false.</p>
     * <p/>
     * @return true if and only if the Mapper is currently mapping, returns false otherwise.
     */
    public static boolean isMapping() {
        return (mappingPolicy != MAP_NONE);
    }
    public static final int BLOCKED = 0x260100;
    public static final int WALL = (0x200 | 0x400 | 0x800 | 0x1000 | 0x2000 | 0x4000 | 0x8000 | 0x10000);

    /**
     * run-method for the Mapper.
     * <p>It should not be called directly. Instead, the
     * <code>startMapping(int)</code>
     * and
     * <code>stopMapping()</code> methods should be used.
     */
    @Override
    public void run() {

        setName("Mapper");
        Starter.logMessage("started mapping with policy: " + mappingPolicy, "Mapper");
        while (mappingPolicy != MAP_NONE) {
            Grid map = Bot.getBot().getWorldMap();
            boolean skip = false;
            if (eco_mode) {
                // optimize CPU-load and reduce CPU-intensity before mapping.
                // check if four corners of mappable area are set, then exit if true
                int range = 100;
                Point loc = Point.fromTile(Game.getMapBase());
                boolean mapped = true; // check for mapped area
                mapped &= (map.get(loc.add(new Point( range,  range))) != null);
                mapped &= (map.get(loc.add(new Point(1,  range))) != null);
                mapped &= (map.get(loc.add(new Point( range, 1))) != null);
                mapped &= (map.get(loc.add(new Point(1,1))) != null);

                skip |= mapped; // skip if area is mapped
            }
            if (skip) {
                // wait for a bit.
                try { Thread.sleep(3500); } catch (Exception e) {}
            } else {
                try {
                    // Store all SceneObjects in the World Map
                    for (SceneObject o : SceneEntities.getLoaded())
                        map.set(Point.fromTile(o.getLocation()), o.getId());
                    
                    // Mark reachable tiles as walkable (takes long time at first
                    // but ignores non-null tiles, so gets faster with more iterations)
                    Tile base = Game.getMapBase();
                    int plane = Game.getPlane();
                    for (int x=base.getX(); x < base.getX() + 104; x++) {
                        for (int y=base.getY(); y < base.getY() + 104; y++) {
                            Point p = new Point(x,y,plane);
                            if (map.get(p) != null && map.get(p).getRawNumber() > 0) continue;
                            if (!p.toTile().canReach())
                                // set as collision (unwalkable tile)
                                map.set(p, -2);
                            else {
                                // set as paved (permanently walkable tile)
                                map.set(p, 0);
                            }
                        }
                    }
                    
                    if (!ToolBox.writeToFile(map.toString(), Starter.worldMapFile)) {
                        Starter.logMessage("updating the WorldMap in " + Starter.worldMapFile + " failed", "Mapper");
                    }
                } catch (Throwable t) { 
                    // catch anything that passes by: The mapper must not crash or hang!
                    Starter.logMessage("An error has occurred: " + t.getClass().getSimpleName(),"Mapper");
                } 
            }
            // update the mapviewer
            if (MapViewer.theMapViewer != null) {
                MapViewer.theMapViewer.repaint();
            }

            if (mappingPolicy == MAP_ONCE) {
                setPolicy(MAP_NONE);
                Starter.logMessage("stopped after runOnce", "Mapper");
                return;
            }

        }
        Starter.logMessage("stopped mapping", "Mapper");
    }
}
