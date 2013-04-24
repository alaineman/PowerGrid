/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.control.factory;

import java.util.ArrayList;
import java.util.Arrays;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSObject;
import powergrid.model.Point;

/**
 * Abstract Factory whose accept depends on the existence of a particular 
 * Object ID on the RSGround.
 * <p/>
 * It accepts if and only if the RSGround contains a RSObject with the required
 * type as given by <code>objectFilter()<code>, with an id value in 
 * <code>acceptedValues()</code>.
 * <p/>
 * @author Chronio
 */
public abstract class ObjectIdSelectFactory extends DefaultGameTileFactory {
    
    public static final int FILTER_BOUNDARY = 1;
    public static final int FILTER_FLOORDEC = 2;
    public static final int FILTER_WALLDEC  = 4;
    public static final int FILTER_ALL = 
            FILTER_BOUNDARY | FILTER_FLOORDEC | FILTER_WALLDEC;
    
    /**
     * A mask defining the types of Objects to look for.
     * <p/>
     * The mask should be an or-operation between the appropriate filter values.
     * The default response is <code>FILTER_ALL</code>
     * @return the value given by <code>FILTER_ALL</code>
     */
    public int objectFilter() {
        return FILTER_ALL;
    }
    
    /**
     * Returns the accepted ID values for this Factory.
     * @return the accepted ID values for this Factory
     */
    public abstract int[] acceptedValues();
    
    
    @Override public boolean accept(Point p, RSGround g, int c) {
        ArrayList<Integer> ids = new ArrayList<>(5);
        int mask = objectFilter();
        RSObject o;
        if ((mask & FILTER_BOUNDARY) != 0) {
            o = g.getBoundary1();
            if (o != null) ids.add(o.getId());
            o = g.getBoundary2();
            if (o != null) ids.add(o.getId());
        }
        if ((mask & FILTER_FLOORDEC) != 0) {
            o = g.getFloorDecoration();
            if (o != null) ids.add(o.getId());
        }
        if ((mask & FILTER_WALLDEC) != 0) {
            o = g.getWallDecoration1();
            if (o != null) ids.add(o.getId());
            o = g.getWallDecoration2();
            if (o != null) ids.add(o.getId());
        }
        int[] values = acceptedValues();
        for (int i : ids) {
            if (Arrays.binarySearch(values,i) >= 0) {
                return true;
            }
        }
        return false;
    }
}
