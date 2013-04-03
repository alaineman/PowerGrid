package powergrid.control;

import java.util.HashMap;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.Node;
import org.powerbot.game.client.RSObject;
import org.powerbot.game.client.RSObjectDef;
import org.powerbot.game.client.RSObjectDefLoader;

/**
 * Class that maintains references to RS definition objects.
 * <p/>
 * It provides methods to lookup the definition for a certain object.
 * <p/>
 * @author Chronio
 */
public class DefinitionCache {

    private Client client;
    private HashMap<Integer, RSObjectDef> objectDefs;
    
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
     * Updates the cache of RSObjectDefs.
     * <p/>
     * This method will overwrite an exisiting RSObjectDef objects when the 
     * Client's RSObjectDefLoader provides another RSObjectDef.
     */
    public void updateObjectCache() {
        RSObjectDefLoader loader = client.getRSGroundInfo()
                .getRSObjectDefLoaders();
        for (Node n : loader.getCache().getTable().getBuckets()) {
            Node current = n;
            while (current.getNext() != null && !current.getNext().equals(n)
                    && !current.getNext().equals(current)) {
                if (current instanceof RSObjectDef) {
                    objectDefs.put((int) current.getId(), 
                            (RSObjectDef) current);
                }
            }
        }
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
            updateObjectCache();
            def = objectDefs.get(id);
        }
        return def;
    }
    
    
}
