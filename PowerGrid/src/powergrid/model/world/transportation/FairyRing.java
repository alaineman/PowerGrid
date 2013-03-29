package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.TransportTile;
import powergrid.model.network.TransportNetwork;

/**
 * Represents a FairyRing in the Runescape world.
 * @author Chronio
 */
public class FairyRing extends TransportTile {

    /** The length of a FairyRing code. */
    public static final int CODE_LENGTH = 4;
    
    private String code;
    
    public FairyRing(Point pos, RSGround ground, int colFlag) {
        super(pos, ground, colFlag);
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        assert code != null && code.length() == CODE_LENGTH;
        this.code = code.toUpperCase();
    }
    
    @Override
    public FairyRing withNetwork(TransportNetwork nw) {
        super.withNetwork(nw);
        return this;
    }
    
    
}
