package powergrid.core;

import java.awt.Component;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.EventObject;

/**
 *
 * @author Patrick Kramer
 */
public class EventInjector {
    
    private final Deque<EventObject> eventQueue = new ArrayDeque<>();
    private volatile boolean queueActive = false;
    
    private Component component = null;
    
    public void setComponent(Component comp) {
        component = comp;
    }
    
    public Component getComponent() {
        return component;
    }
    
    public void dispatchEvent(EventObject e) {
        synchronized (eventQueue) {
            eventQueue.addLast(e);
        }
    }
}
