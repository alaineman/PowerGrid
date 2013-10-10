/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 * 
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
package net.pgrid.loader.bridge.injection.keyboard;

import java.awt.Canvas;
import java.awt.Component;
import java.awt.event.KeyEvent;
import static java.awt.event.KeyEvent.*;
import java.awt.event.KeyListener;
import net.pgrid.loader.AppletFrame;

/**
 * Simple KeyInjector that works by pushing KeyEvent objects into the target
 * KeyListeners.
 * 
 * @author Chronio
 */
public class AWTKeyInjector implements KeyInjector {

    private static final long serialVersionUID = 305601930419824L;
    
    private Component target;
    private transient KeyListener listener;

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
     * @throws IllegalArgumentException when the ID of the KeyEvent is not one 
     *         of KEY_PRESSED, KEY_RELEASED, or KEY_TYPED.
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
                break;
            default:
                throw new IllegalArgumentException("Invalid ID for Event");
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
