package net.pgrid.loader.bridge.injection.keyboard;

import java.awt.Canvas;
import java.awt.Component;
import java.awt.event.KeyEvent;
import static java.awt.event.KeyEvent.*;
import java.awt.event.KeyListener;
import net.pgrid.loader.AppletFrame;

/**
 * Simple KeyInjector that works by pushing KeyEvent objects onto the 
 * target AWT Component's EventQueue.
 * 
 * @author Chronio
 */
public class AWTKeyInjector implements KeyInjector {

    private Component target;
    private KeyListener listener;

    /**
     * @return the KeyListener on which KeyEvents are placed
     * 
     * @throws ArrayIndexOutOfBoundsException when no listener was found in the component.
     */
    public KeyListener getListener() {
        if (listener == null) {
            Component c = getTargetComponent();
            if (!(c instanceof AppletFrame)) {
                throw new IllegalStateException("Target component must be a AppletFrame");
            }
            AppletFrame f = (AppletFrame) c;
            Canvas canvas = f.getCanvas();
            // we blindly assume here the Canvas has a KeyListener, for it 
            // always has unless it gets changed in the RS Applet code.
            listener = canvas.getKeyListeners()[0];
        }
        return listener;
    }
    
    /**
     * @return the Component previously set with the setTarget method.
     */
    public Component getTargetComponent() {
        return target;
    }
    
    /**
     * Forwards the given KeyEvent to the set listener given by 
     * <code>getEventQueue()</code>.
     * @param event the KeyEvent to post
     * 
     * @throws NullPointerException if the event is null
     */
    protected void postKeyEvent(KeyEvent event) {
        switch (event.getID()) {
            case KEY_PRESSED:
                getListener().keyPressed(event);
                break;
            case KEY_RELEASED:
                getListener().keyReleased(event);
                break;
            case KEY_TYPED:
                getListener().keyTyped(event);
        }
    }
    
    @Override
    public void keyPressed(int keyCode, int modifiers) {
        KeyEvent ev = new KeyEvent(target, KEY_PRESSED, 
                System.currentTimeMillis(), modifiers, keyCode, (char)keyCode);
        postKeyEvent(ev);
    }

    @Override
    public void keyReleased(int keyCode, int modifiers) {
        KeyEvent ev = new KeyEvent(target, KEY_RELEASED, 
                System.currentTimeMillis(), modifiers, keyCode, (char)keyCode);
        postKeyEvent(ev);
    }

    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        KeyEvent ev = new KeyEvent(target, KEY_TYPED, 
                System.currentTimeMillis(), modifiers, VK_UNDEFINED, c);
        postKeyEvent(ev);
    }

    @Override
    public void setTarget(Component comp) {
        assert comp != null;
        target = comp;
        // reset the listener, it is collected upon calling getListener()
        listener = null; 
    }
    
}
