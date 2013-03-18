package powergrid.control;

import java.util.HashMap;
import org.powerbot.game.client.RSGround;
import powergrid.control.factory.DefaultGameTileFactory;
import powergrid.model.Point;

/**
 *
 * @author Chronio
 */
public class TileFactory {
    
    private HashMap<DefaultGameTileFactory,Integer> factories = new HashMap<>();
    
    public boolean addFactory(DefaultGameTileFactory f) {
        if (factories.containsKey(f)) {
            return false;
        } else {
            factories.put(f, 0);
            return true;
        }
    }
    
    public DefaultGameTileFactory removeFactory(DefaultGameTileFactory f) {
        for (DefaultGameTileFactory d : factories.keySet()) {
            if (d.equals(f)) {
                factories.remove(d);
                return d;
            }
        }
        return null;
    }
    
    public DefaultGameTileFactory getFactory(Point p, RSGround g, int c) {
        for (DefaultGameTileFactory d : factories.keySet()) {
            if (d.accept(p,g,c)) {
                factories.put(d, factories.get(d) + 1);
                return d;
            } else {
                
            }
        }
        return null;
    }
}
