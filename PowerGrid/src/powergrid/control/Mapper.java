package powergrid.control;

import org.powerbot.core.Bot;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSInfo;
import org.powerbot.game.client.RSInteractable;
import org.powerbot.game.client.RSInteractableLocation;
import powergrid.model.Point;
import powergrid.model.WorldMap;
import powergrid.model.world.Wall;
import powergrid.tasks.Task;

/**
 * This class collects data from the RSBot environment and stores it in its Grid-object.
 * <p/>
 * This class provides functionality similar to RSBot's SceneEntities class, 
 * but on a larger scale. It is possible to load cached data from areas that are 
 * not loaded in the RS client. This information may be out of date, however.
 * <p/>
 * @author Chronio
 */
public class Mapper {
    
    private volatile boolean stop = false;
    private WorldMap map = null;
    private Client client = null;
    private MapperThread thread = null;

    public Mapper() {
        assert Bot.instantiated();
        client = Bot.client();
        assert invariant();
    }
    
    public Mapper(Client client) {
        assert client != null;
        this.client = client;
        assert invariant();
    }
    
    public Mapper withMap(WorldMap map) {
        assert this.map == null;
        assert map != null;
        this.map = map;
        return this;
    }

    /**
     * Starts the Mapper with the given policy.
     * <p/>
     * @param policy the policy to use for the Mapper (MAP_CONTINOUSLY or MAP_ONCE)
     * @throws IllegalStateException when the Mapper is already / still running
     */
    public synchronized void startMapping() {
        if (thread != null)
            throw new IllegalStateException("Mapper is already active");
        assert invariant();
        stop = false;
        thread = new MapperThread();
        thread.start();
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
    public synchronized void stopMapping() {
        if (thread == null)
            throw new IllegalStateException("Mapper is not running");
        stop = true;
        thread = null;
        assert invariant();
    }
    
    public void mapOneRound() {
        if (thread != null)
            throw new IllegalStateException("This Mapper is already mapping");
        mapOnce();
    }
    
    public boolean isMapping() {
        return thread != null;
    }

    private synchronized void mapOnce() {
        assert invariant();
        RSInfo info = client.getRSGroundInfo();
        Point basePoint = new Point(
                info.getBaseInfo().getX(),
                info.getBaseInfo().getY(),
                client.getPlane());
        
        RSGround[][][] data = info.getRSGroundInfo().getRSGroundArray();
        assert data != null;
        
        for (int y=0;y<data.length;y++) {
            RSGround[][] row = data[y];
            for (int x=0;x<row.length;x++) {
                RSGround[] cell = row[x];
                for (int plane = 0;plane<cell.length;plane++) {
                    RSGround value = cell[plane];
                    RSInteractableLocation location = ((RSInteractable)value).getData().getLocation();
                    Point position = new Point(
                            (int)(location.getX()/512),
                            (int)(location.getY()/512),
                            -1 ).add(basePoint);
                    map.putGround(position, value);
                }
            }
        }
        
        int[][] colFlags = info.getGroundData()[basePoint.z].getBlocks();
        assert colFlags != null;
        
        for (int y=0;y<colFlags.length;y++) {
            int[] row = colFlags[y];
            for (int x=0;x<row.length;x++) {
                Point position = new Point(x,y).add(basePoint);
                map.putMask(position, row[x]);
            }
        }
        
        assert invariant();
    }
    
    /**
     * Returns the Grid that the Mapper maps to.
     * @return the Grid that the Mapper maps to
     */
    public WorldMap getWorldMap() {
        return map;
    }
    
    private static int convertToSides(int flag) {
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
    
    private boolean invariant() {
        // The client must be valid
        if (client == null || client.getRSGroundInfo() == null) return false;
        if (client.getRSGroundInfo().getRSGroundInfo() == null) return false;
        // We only have a reference to a MapperThread if the MapperThread is actually mapping.
        if (thread != null && !thread.isAlive()) return false;
        if ( (thread == null) != stop ) return false;
        
        return true;
    }
    
    public Mapper copy() {
        return new Mapper(client).withMap(map);
    }
    
    public class MapperThread extends Thread {
        public MapperThread() {
            setName("MapperThread");
        }
        @Override public void run() {
            while (!stop) {
                mapOnce();
                Task.sleep(5000);
            }
        }
    }
}