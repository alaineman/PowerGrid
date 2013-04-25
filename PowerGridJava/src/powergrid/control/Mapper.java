package powergrid.control;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Objects;
import static org.powerbot.game.api.wrappers.Tile.Flag.*;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSGroundData;
import org.powerbot.game.client.RSGroundInfo;
import org.powerbot.game.client.RSInfo;
import org.powerbot.game.client.RSInteractable;
import org.powerbot.game.client.RSInteractableLocation;
import powergrid.control.factory.DefaultGameTileFactory;
import powergrid.control.factory.ModelBuilder;
import powergrid.control.listener.MapperListener;
import powergrid.model.Copyable;
import powergrid.model.Point;
import powergrid.model.structure.WorldMap;
import powergrid.model.world.GameTile;
import powergrid.task.Task;

/**
 * This class collects data from the RSBot environment and stores it in its Grid-object.
 * <p/>
 * This class provides functionality similar to RSBot's SceneEntities class, 
 * but on a larger scale. It is possible to load cached data from areas that are 
 * not loaded in the RS client. This information may be out of date, however.
 * <p/>
 * @author Chronio
 */
public class Mapper implements Copyable {
    
    private volatile boolean stop = true;
    private WorldMap map = null;
    private Client client = null;
    private ModelBuilder builder = null;
    private MapperThread thread = null;
    
    private HashSet<MapperListener> listeners = new HashSet<>(5);

    public Mapper() {}
    
    public Mapper(Client client) {
        assert client != null;
        this.client = client;
        //assert invariant();
    }
    
    public Mapper withMap(WorldMap map) {
        assert this.map == null && map != null;
        this.map = map;
        return this;
    }

    public Mapper withClient(Client client) {
        assert this.client == null && client != null;
        this.client = client;
        //assert invariant();
        return this;
    }
    
    public Mapper withBuilder(ModelBuilder builder){
        assert this.builder == null && builder != null;
        this.builder = builder;
        return this;
    }
    
    /**
     * Starts the Mapper.
     * <p/>
     * @throws IllegalStateException when the Mapper is running, or no client 
     *                               has been defined
     */
    public synchronized void startMapping() {
        if (thread != null)
             throw new IllegalStateException("Mapper is already active");
        if (client == null) 
            throw new IllegalStateException("Undefined Client");
        stop = false;
        thread = new MapperThread(5000);
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
        //assert invariant();
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
        //assert invariant();
        if (map == null) {
            map = new WorldMap();
        }
        if (client == null) {
            throw new IllegalStateException("Undefined Client");
        }        
        if (builder == null) {
            builder = new ModelBuilder();
            builder.addFactory(new DefaultGameTileFactory());
        }
        RSInfo info = client.getRSGroundInfo();
        
        Map<Point, RSGround> grounds = new HashMap<>(104 * 104 * 8 / 7, 7 / 8f);
        
        RSGroundInfo ginfo = info.getRSGroundInfo();
        Point basePoint = new Point(
                info.getBaseInfo().getX(),
                info.getBaseInfo().getY(),
                client.getPlane());
        RSGround[][][] data = null;
        if (ginfo != null)
            data = ginfo.getRSGroundArray();
        
        if (data != null) {
            for (RSGround[][] row : data) {
                for (RSGround[] cell : row) {
                    for (RSGround value : cell) {
                        if (value != null) {
                            RSInteractableLocation location = 
                                    ((RSInteractable) value).getData()
                                    .getLocation();
                            Point position = new Point(
                                    (int)(location.getX()/512),
                                    (int)(location.getY()/512)
                                    ).add(basePoint);
                            grounds.put(position, value);
                        }
                    }
                }
            }
        }
        
        int[][] colFlags = null;
        RSGroundData[] gdatas = info.getGroundData();
        if (gdatas.length > basePoint.z) {
            RSGroundData gdata = gdatas[basePoint.z];
            if (gdata != null) {
                colFlags = gdata.getBlocks();
            }
        }
        
        if (colFlags != null) {
            for (int y=0;y<colFlags.length;y++) {
                int[] row = colFlags[y];
                for (int x=0;x<row.length;x++) {
                    Point position = new Point(x,y).add(basePoint);
                    RSGround ground = grounds.get(position);
                    int flag = convertToSides(row[x]);
                    GameTile gt = builder.createGameTile(position, ground, flag);
                    map.put(gt);
                }
            }
        }
        
        for (MapperListener l : listeners) {
            l.mapUpdated(this);
        }        
        
        //assert invariant();
    }
    
    /**
     * Returns the Grid that the Mapper maps to.
     * @return the Grid that the Mapper maps to
     */
    public WorldMap getWorldMap() {
        if (map == null) {
            map = new WorldMap();
        }
        return map;
    }
    
    public Client getClient() {
        return client;
    }
    
    private static int convertToSides(int flag) {
        if ((flag | OBJECT_BLOCK | OBJECT_TILE) == flag)
            return GameTile.BLOCK;
        if ((flag | OBJECT_ALLOW_RANGE | OBJECT_TILE) == flag) 
            return GameTile.BLOCK;
        int res = 0;
        if ((flag & (WALL_ALLOW_RANGE_NORTH | WALL_BLOCK_NORTH)) != 0)
            res |= GameTile.NORTH;
        if ((flag & (WALL_ALLOW_RANGE_EAST | WALL_BLOCK_EAST)) != 0)
            res |= GameTile.EAST;
        if ((flag & (WALL_ALLOW_RANGE_SOUTH | WALL_BLOCK_SOUTH)) != 0)
            res |= GameTile.SOUTH;
        if ((flag & (WALL_ALLOW_RANGE_WEST | WALL_BLOCK_WEST)) != 0)
            res |= GameTile.WEST;
        return res;
    }
    
    private boolean invariant() {
        // We only have a reference to a MapperThread if the MapperThread 
        // is actually mapping.
        if (thread != null && !thread.isAlive()) return false;
        if ((thread == null) != stop) return false;
        
        return true;
    }
    
    @Override public Mapper copy() {
        return new Mapper(client).withMap(map);
    }
    
    public class MapperThread extends Thread {
        private int delay;
        public MapperThread(int delayBetweenRounds) {
            setName("MapperThread");
            delay = delayBetweenRounds;
        }
        @Override public void run() {
            do {
                mapOnce();
                Task.sleep(delay);
            } while (!stop);
        }
    }

    public void addMapperListener(MapperListener l) {
        if (!listeners.contains(l))
            listeners.add(l);
    }
    
    public void removeMapperListener(MapperListener l) {
        listeners.remove(l);
    }
    
    @Override public int hashCode() {
        int hash = 3;
        hash = 61 * hash + Objects.hashCode(this.map);
        hash = 61 * hash + Objects.hashCode(this.client);
        return hash;
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof Mapper) {
            Mapper that = (Mapper)other;
            return this.getWorldMap().equals(that.getWorldMap()) &&
                    this.getClient().equals(that.getClient());
        }
        return false;
    }
}