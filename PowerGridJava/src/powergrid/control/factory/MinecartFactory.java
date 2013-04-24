package powergrid.control.factory;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.world.transportation.Minecart;

/**
 * Creates a Minecart from the data provided to it.
 * 
 * @author Chronio
 */
public class MinecartFactory extends ObjectIdSelectFactory {
    
    @Override public int objectFilter() {
        return FILTER_BOUNDARY;
    }
    
    @Override public int[] acceptedValues() {
        return new int[] {
            7028, 7029, 7030, 28094
        };
    }
    
    @Override public Minecart create(Point p, RSGround g, int c) {
        if (accept(p,g,c)) {
            return new Minecart(p,g,c);
        } else {
            return null;
        }
    }
}
