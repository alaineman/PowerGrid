package powergrid.model.rsbot;

import org.powerbot.game.client.BaseInfo;

/**
 * Minimal implementation class for the BaseInfo interface.
 * @author Chronio
 */
public class BaseInfoImpl implements BaseInfo {

    private int x,y;

    /**
     * Creates a new BaseInfoImpl object with the provided coordinates.
     * @param x the x coordinate
     * @param y the y coordinate
     */
    public BaseInfoImpl(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    @Override
    public int getX() {
        return x;
    }

    @Override
    public int getY() {
        return y;
    }
    
}
