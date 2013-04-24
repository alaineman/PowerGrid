package powergrid.control;

import java.util.HashMap;
import java.util.Map;
import org.powerbot.game.client.Cache;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.HardReference;
import org.powerbot.game.client.Node;
import org.powerbot.game.client.RSItem;
import org.powerbot.game.client.RSItemDef;
import org.powerbot.game.client.RSObject;
import org.powerbot.game.client.RSObjectDef;
import org.powerbot.game.client.SoftReference;

/**
 * Class that maintains references to RS definition objects.
 * <p/>
 * It provides methods to lookup the definition for a certain object, as well 
 * as the possibility to dump an arbitrary Cache object into a Map, mapping id 
 * to the element with that id in the Cache.
 * <p/>
 * @author Chronio
 */
public class DefinitionCache {

    private Client client;
    private HashMap<Integer, RSObjectDef> objectDefs;
    private HashMap<Integer, RSItemDef> itemDefs;
    
    /**
     * Creates a new DefinitionCache that uses the given Client.
     * @param client the Client to use, which cannot be null
     */
    public DefinitionCache(Client client) {
        assert client != null;
        this.client = client;
        objectDefs = new HashMap<>(64, 7/8f);
    }
    
    /**
     * Looks up the RSObjectDef for the specified RSObject.
     * <p/>
     * If the RSObjectDef is not found, the cache is updated once before 
     * returning. This method will return null if and only if there is no 
     * RSObjectDef object present within the Client for the provided RSObject.
     * <p/>
     * @param object the object to look up
     * @return the RSObjectDef for the given RSObject
     */
    public RSObjectDef lookupObjectDef(RSObject object) {
        if (object == null) {
           return null;
        }
        return lookupObjectDef(object.getId());
    }
    
    /**
     * Looks up the RSObjectDef for the specified id.
     * <p/>
     * If the RSObjectDef is not found, the cache is updated once before 
     * returning. This method will return null if and only if there is no 
     * RSObjectDef object present within the Client for the provided id.
     * <p/>
     * @param id the id to look up
     * @return the RSObjectDef for the given id
     */
    public RSObjectDef lookupObjectDef(int id) {
        RSObjectDef def = objectDefs.get(id);
        if (def == null) {
            Cache c = client.getRSGroundInfo().getRSObjectDefLoaders()
                    .getCache();
            dumpCache(RSObjectDef.class, c, objectDefs);
            def = objectDefs.get(id);
        }
        return def;
    }
    
    /**
     * Looks up the RSItemDef for the specified RSItem.
     * <p/>
     * If the RSItemDef is not found, the cache is updated once before 
     * returning. This method will return null if and only if there is no 
     * RSItemDef object present within the Client for the provided RSItem.
     * <p/>
     * @param item the RSItem to look up
     * @return the RSItemDef for the given RSItem
     */
    public RSItemDef lookupItemDef(RSItem item) {
        if (item == null) {
            return null;
        }
        return lookupItemDef(item.getId());
    }
    
    /**
     * Looks up the RSItemDef for the specified id.
     * <p/>
     * If the RSItemDef is not found, the cache is updated once before 
     * returning. This method will return null if and only if there is no 
     * RSItemDef object present within the Client for the provided id.
     * <p/>
     * @param id the id to look up
     * @return the RSItemDef for the given id
     */
    public RSItemDef lookupItemDef(int id) {
        RSItemDef def = itemDefs.get(id);
        if (def == null) {
            Cache c = client.getRSItemDefLoader().getCache();
            dumpCache(RSItemDef.class, c, itemDefs);
            def = itemDefs.get(id);
        }
        return def;
    }
    
    /**
     * Dumps all values in the specified Cache in the given Map.
     * <p/>
     * The elements in the provided Cache are placed in the provided Map, 
     * mapping the element's id (as given by the corresponding Node's 
     * <code>getId()</code> method) to the element.
     * <p/>
     * This method works similarly to Nodes.lookup, except that this method 
     * dumps the found elements in the provided Map and automatically casts
     * the elements to the expected type. Type checking will be performed and 
     * only elements that are instances of the provided Class are put into the 
     * Map.
     * <p/>
     * @param <T> the expected type of elements
     * @param clazz the Class object representing the element type
     * @param c the Cache to load the elements from
     * @param map the Map to dump the Cache's contents in
     */
    public <T> void dumpCache(Class<T> clazz, Cache c, 
            Map<Integer, T> map) {
        for (Node n : c.getTable().getBuckets()) {
            for (Node node = n.getNext(); node != n && node != null; 
                    node = node.getNext()) {
                Object elem;
                if (node instanceof SoftReference) {
                    elem = ((java.lang.ref.SoftReference) 
                            ((SoftReference) node).get()).get();
                } else if (node instanceof HardReference) {
                    elem = ((HardReference) node).get();
                } else {
                    elem = node;
                }
                if (clazz.isInstance(elem)) {
                    map.put((int) node.getId(), clazz.cast(elem));
                }
            }
        }
    }
    
}
