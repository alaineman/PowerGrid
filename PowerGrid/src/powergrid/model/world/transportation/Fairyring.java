package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.network.TransportNetwork;
import powergrid.model.network.TreeNetwork;

/**
 * Represents a Fairyring in the Runescape world.
 *
 * @author Chronio
 */
public class Fairyring extends TransportTile {

    /**
     * The length of a Fairyring code.
     */
    public static final int CODE_LENGTH = 4;
    private String code;

    public Fairyring(Point pos, RSGround ground, int colFlag) {
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
    public TreeNetwork getNetwork() {
        return (TreeNetwork) super.getNetwork();

    }

    @Override
    public Fairyring withNetwork(TransportNetwork nw) {
        if (nw instanceof TreeNetwork) {
            super.withNetwork(nw);
            return this;
        } else {
            return null;
        }
    }
}
