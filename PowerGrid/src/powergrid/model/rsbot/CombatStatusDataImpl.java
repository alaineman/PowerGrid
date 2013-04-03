package powergrid.model.rsbot;

import org.powerbot.game.client.CombatStatusData;
import org.powerbot.game.client.LinkedListNode;

/**
 * Minimal implementation class for the CombatStatusData interface.
 * @author Chronio
 */
public class CombatStatusDataImpl extends LinkedListNodeImpl 
            implements CombatStatusData {

    private int lcs, hp;
    
    /**
     * Creates a new CombatStatusDataImpl object with the specified data
     * @param next the next LinkedListNode
     * @param loopCycleStatus the loop cycle status
     * @param hpRatio the hp ratio
     */
    public CombatStatusDataImpl(LinkedListNode next, int loopCycleStatus, 
            int hpRatio) {
        super(next);
        lcs = loopCycleStatus;
        hp = hpRatio;
    }
    
    @Override
    public int getLoopCycleStatus() {
        return lcs;
    }

    @Override
    public int getHPRatio() {
        return hp;
    }
    
}
