package net.pgrid.loader.injection.keyboard;

import java.awt.Component;
import java.awt.EventQueue;
import java.awt.Window;
import java.awt.event.KeyEvent;

/**
 * Simple KeyInjector that works by pushing KeyEvent objects onto the 
 * target AWT Component's EventQueue.
 * 
 * @author Chronio
 */
public class AWTKeyInjector implements KeyInjector {

    private Window target;
    private EventQueue queue;
    
    /**
     * @return the EventQueue object for the target Component.
     */
    public EventQueue getEventQueue() {
        return queue;
    }
    
    /**
     * @return the Component previously set with the setTargetComponent method.
     */
    public Component getTargetComponent() {
        return target;
    }
    
    /**
     * Posts the given KeyEvent on the AWT EventQueue given by 
     * <code>getEventQueue()</code>.
     * @param event the KeyEvent to post
     * 
     * @throws NullPointerException if the event is null
     */
    protected void postKeyEvent(KeyEvent event) {
        getEventQueue().postEvent(event);
    }
    
    @Override
    public void keyPressed(int keyCode, int modifiers) {
        //TODO: this
    }

    @Override
    public void keyReleased(int keyCode, int modifiers) {
        //TODO: this
    }

    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        //TODO: this
    }

    @Override
    public void setTargetComponent(Window comp) {
        target = comp;
        queue = target.getToolkit().getSystemEventQueue();
    }
    
}
