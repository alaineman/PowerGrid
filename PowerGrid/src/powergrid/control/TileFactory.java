package powergrid.control;

import java.util.ArrayList;
import java.util.Collections;
import java.util.ListIterator;
import org.powerbot.game.client.RSGround;
import powergrid.control.factory.TypeFactory;
import powergrid.model.world.GameTile;
import powergrid.model.Point;

/**
 * This class takes in raw information from the Runescape environment, and 
 * calls the appropriate factory object to instantiate the object.
 * <p/>
 * @author Chronio
 */
public class TileFactory {
    
    private ArrayList<TypeFactory> factories = new ArrayList<>();
    
    /**
     * Adds the given factory to the List of TypeFactories.
     * <p/>
     * When this TileFactory already contains the given factory, this method 
     * returns false
     * @param f the factory to add
     * @return true if and only if the factory was added, false otherwise.
     */
    public boolean addFactory(TypeFactory f) {
        if (f == null || factories.contains(f)) {
            return false;
        } else {
            factories.add(f);
            /* put the factory in the right place, according to its natural
             * ordering. 
             */
            Collections.sort(factories);
            return true;
        }
    }
    
    /**
     * Removes the given factory from the List of TypeFactories.
     * <p/>
     * If this TileFactory does not contain the given factory, null is returned.
     * <p/>
     * @param f the factory to remove
     * @return the factory that was removed, or null if no factory was removed.
     */
    public TypeFactory removeFactory(TypeFactory f) {
        assert f != null;
        for (TypeFactory tf : factories) {
            if (tf.equals(f)) {
                factories.remove(tf);
                return tf;
            }
        }
        return null;
    }
    
    /**
     * Returns a factory that matches the given information.
     * <p/>
     * The factory is selected based on that factory's natural ordering. In 
     * other words, the factory that has the highest ordering as given by that 
     * factory's compareTo method is returned.
     * <p/>
     * @param p the position
     * @param g the RSGround object
     * @param c the collision flag
     * @return the factory best matching the given information.
     */
    public TypeFactory getFactory(Point p, RSGround g, int c) {
        assert p != null && g != null;
        ListIterator<TypeFactory> li = factories.listIterator(factories.size());
        /* Collections.sort sorts the Factories ascending. Since we want to 
         * check the highest scoring factory first, we iterate over the List in
         * reverse.
         */
        while (li.hasPrevious()) {
            TypeFactory tf = li.previous();
            if (tf.accept(p,g,c)) {
                return tf;
            }
        }
        return null;
    }
    
    /**
     * Creates an instance using the appropriate factory based on the given 
     * information.
     * <p/>
     * This method is equivalent to calling 
     * <code>getFactory(p,g,c).create(p,g,c)</code>.
     * <p/>
     * @param p the position
     * @param g the RSGround object
     * @param c the collision flag
     * @return the GameTile instance created from the given information
     */
    public GameTile instantiate(Point p, RSGround g, int c) {
        TypeFactory theFactory = getFactory(p,g,c);
        if (theFactory == null) {
            return null;
        } else { 
            return theFactory.create(p, g, c);
        }
    }
}
