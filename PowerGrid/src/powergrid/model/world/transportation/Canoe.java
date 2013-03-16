package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.interaction.TransportTile;

/**
 * Transport Tile containing a Canoe object allowing transportation.
 * @author Chronio
 */
public class Canoe extends TransportTile {
    
    public Canoe(Point pos, RSGround ground, int colFlag) {
        super(pos,ground,colFlag);
    }
}
