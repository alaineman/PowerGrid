package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.TransportTile;
import powergrid.model.network.TreeNetwork;

/**
 * Represents a Minecart Tile in the Runescape environment.
 * @author Chronio
 */
public class Minecart extends TransportTile {
    
    /**
     * Creates a new Minecart instance with the specified information.
     * @param pos the position in the Runescape world
     * @param ground the RSGround object containing the Tile information
     * @param flag the Collision flag for this object
     */
    public Minecart(Point pos, RSGround ground, int flag) {
        super(pos,ground,flag);
    }
    
    @Override public TreeNetwork getNetwork() {
        return (TreeNetwork) super.getNetwork();
    }
}
