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
package net.pgrid.loader.bridge.injection;

import java.awt.Component;
import java.awt.Window;
import net.pgrid.loader.bridge.injection.keyboard.KeyInjector;
import net.pgrid.loader.bridge.injection.mouse.MouseInjector;

/**
 * Relatively Thread-safe implementation of a wrapper around both a KeyInjector 
 * and a MouseInjector.
 * <p/>
 * This Class aims to provide a thread-safe wrapper around all event injection 
 * functionality for clients that use this loader.
 * <p/>
 * @author Patrick Kramer
 */
public class InjectionController implements KeyInjector, MouseInjector{

    private static final long serialVersionUID = 932497346598723L;
    
    private KeyInjector keyDelegate;
    private MouseInjector mouseDelegate;
    private Component target;
    
    // Locks used to synchronize on the fields.
    private final Object keyboardLock, mouseLock;
    
    /**
     * Creates a new InjectionController.
     * @param keyboard the KeyInjector to use
     * @param mouse the MouseInjector to use
     * @param target the target Window
     */
    public InjectionController(KeyInjector keyboard, MouseInjector mouse, Window target) {
        if (keyboard == null || mouse == null) {
            throw new IllegalArgumentException("Null-value");
        }
        keyDelegate = keyboard;
        mouseDelegate = mouse;
        this.target = target;
        
        keyboardLock = new Object();
        mouseLock = new Object();
        
        // Ensure the key and mouse use the correct target component
        keyDelegate.setTarget(target);
        mouseDelegate.setTarget(target);
    }

    /**
     * @return the KeyInjector
     */
    public KeyInjector getKeyDelegate() {
        return keyDelegate;
    }

    /**
     * @return the MouseInjector
     */
    public MouseInjector getMouseDelegate() {
        return mouseDelegate;
    }

    /**
     * Sets the KeyInjector to use
     * @param keyDelegate the KeyInjector to use
     */
    public void setKeyDelegate(KeyInjector keyDelegate) {
        if (keyDelegate == null) {
            throw new IllegalArgumentException("Null-value");
        }
        synchronized (keyboardLock) {
            this.keyDelegate = keyDelegate;
        }
    }

    /**
     * Sets the MouseInjector to use.
     * @param mouseDelegate the MouseInjector to use
     */
    public void setMouseDelegate(MouseInjector mouseDelegate) {
        if (mouseDelegate == null) {
            throw new IllegalArgumentException("Null-value");
        }
        synchronized (mouseLock) {
            this.mouseDelegate = mouseDelegate;
        }
    }
    
    @Override
    public void setTarget(Component comp) {
        synchronized (keyboardLock) {
            keyDelegate.setTarget(comp);
        }
        try {
            synchronized (mouseLock) {
                mouseDelegate.setTarget(comp);
            }
            target = comp;
        } catch (IllegalArgumentException e) {
            synchronized (keyboardLock) {
                keyDelegate.setTarget(target);
            }
        }
    }

    /**
     * @return the target Component
     */
    public Component getTarget() {
        return target;
    }

    @Override
    public void keyPressed(int keyCode, int modifiers) {
        synchronized (keyboardLock) {
            keyDelegate.keyPressed(keyCode, modifiers);
        }
    }

    @Override
    public void keyReleased(int keyCode, int modifiers) {
        synchronized (keyboardLock) {
            keyDelegate.keyReleased(keyCode, modifiers);
        }
    }

    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        synchronized (keyboardLock) {
            keyDelegate.keyTyped(c, keyCode, modifiers);
        }
    }

    @Override
    public void moveMouse(int x, int y) {
        synchronized (mouseLock) {
            mouseDelegate.moveMouse(x, y);
        }
    }

    @Override
    public void dragMouse(int x, int y, int button) {
        synchronized (mouseLock) {
            mouseDelegate.dragMouse(x, y, button);
        }
    }

    @Override
    public void clickMouse(int button) {
        synchronized (mouseLock) {
            mouseDelegate.clickMouse(button);
        }
    }

    @Override
    public void pressMouse(int button) {
        synchronized (mouseLock) {
            mouseDelegate.pressMouse(button);
        }
    }

    @Override
    public void releaseMouse(int button) {
        synchronized (mouseLock) {
            mouseDelegate.releaseMouse(button);
        }
    }

    @Override
    public void scrollUp() {
        synchronized (mouseLock) {
            mouseDelegate.scrollUp();
        }
    }

    @Override
    public void scrollDown() {
        synchronized (mouseLock) {
            mouseDelegate.scrollDown();
        }
    }

    @Override
    public int getX() {
        synchronized (mouseLock) {
            return mouseDelegate.getX();
        }
    }

    @Override
    public int getY() {
        synchronized (mouseLock) {
            return mouseDelegate.getY();
        }
    }

    @Override
    public boolean isBlocking() {
        synchronized (mouseLock) {
            return mouseDelegate.isBlocking();
        }
    }
    
}
