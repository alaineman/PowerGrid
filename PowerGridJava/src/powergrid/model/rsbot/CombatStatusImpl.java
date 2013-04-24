package powergrid.model.rsbot;

import org.powerbot.game.client.CombatStatus;
import org.powerbot.game.client.LinkedList;
import org.powerbot.game.client.LinkedListNode;

/**
 * Minimal implementation class for the CombatStatus interface.
 * @author Chronio
 */
public class CombatStatusImpl extends LinkedListNodeImpl 
        implements CombatStatus {

    private LinkedList list;

    public CombatStatusImpl(LinkedList list, LinkedListNode next) {
        super(next);
        this.list = list;
    }
    
    @Override
    public LinkedList getData() {
        return list;
    }
    
}
