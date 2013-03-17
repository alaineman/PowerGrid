package powergrid.model;

import org.powerbot.game.client.RSGround;
import powergrid.model.network.TransportNetwork;

/**
 * Represents a GameTile that contains an object that can be used as 
 * transportation.
 * <p/>
 * 
 * @author Chronio
 */
public class TransportTile extends GameTile {
    
    private TransportNetwork network = null;
    
    /**
     * Creates a new TransportTile with the given information.
     * @param pos the position of this TransportTile
     * @param ground the RSGround object containing the Tile information
     * @param colFlag the Collision flag of this Tile
     */
    public TransportTile(Point pos, RSGround ground, int colFlag) {
        super(pos,ground,colFlag);
    }
    
    /**
     * Makes this TransportTile a part of the specified network.
     * @param nw the network to add this TransportTile to
     * @return itself for fluency
     */
    public TransportTile withNetwork(TransportNetwork nw) {
        network = nw;
        return this;
    }
    
    /**
     * Returns the network of TransportTiles associated with this 
     * TransportTile.
     * <p/>
     * @return the TransportNetwork this TransportTile is a part of, or null if
     *         this TransportTile is not a part of a network
     */
    public TransportNetwork getNetwork() {
        return network;
    }
}
