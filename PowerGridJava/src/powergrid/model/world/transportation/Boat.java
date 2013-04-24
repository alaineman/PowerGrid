package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;

/**
 * Superclass for Boat-like Transportation Tiles.
 * @author Chronio
 */
public class Boat extends TransportTile {
    public Boat(Point pos, RSGround ground, int colFlag) {
        super(pos, ground, colFlag);
    }
}