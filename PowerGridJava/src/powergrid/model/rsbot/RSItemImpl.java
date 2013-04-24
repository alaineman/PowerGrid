package powergrid.model.rsbot;

import org.powerbot.game.client.RSItem;

/**
 * Minimal implementation class for RSItem
 * @author Chronio
 */
public class RSItemImpl implements RSItem {

    private int id;
    private int stackSize;
    
    public RSItemImpl(int id, int stackSize) {
        assert id >= 0;
        this.id = id;
        this.stackSize = stackSize;
    }
    
    @Override
    public int getId() {
        return id;
    }

    @Override
    public int getStackSize() {
        return stackSize;
    }
    
}
