package powergrid.model.rsbot;

import org.powerbot.game.client.Cache;
import org.powerbot.game.client.HashTable;

/**
 * Minimal implementation class for the Cache interface.
 * @author Chronio
 */
public class CacheImpl implements Cache {

    private HashTable table;

    /**
     * Creates a new CacheImpl with the given HashTable
     * @param table the HashTable in this Cache
     */
    public CacheImpl(HashTable table) {
        this.table = table;
    }
    
    @Override
    public HashTable getTable() {
        return table;
    }
    
}
