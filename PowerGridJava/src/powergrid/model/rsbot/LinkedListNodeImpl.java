package powergrid.model.rsbot;

import org.powerbot.game.client.LinkedListNode;

/**
 * Minimal implementation class for the LinkedListNode interface.
 * @author Chronio
 */
public class LinkedListNodeImpl implements LinkedListNode {
    
    private LinkedListNode next;

    public LinkedListNodeImpl(LinkedListNode next) {
        this.next = next;
    }
    
    @Override
    public LinkedListNode getNext() {
        return next;
    }
    
}
