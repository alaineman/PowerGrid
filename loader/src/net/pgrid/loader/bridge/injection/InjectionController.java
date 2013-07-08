package net.pgrid.loader.bridge.injection;

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
 * @author Chronio
 */
public class InjectionController implements KeyInjector, MouseInjector{

    private KeyInjector keyDelegate;
    private MouseInjector mouseDelegate;
    private Window target;
    
    // Locks used to synchronize on the fields.
    private final Object keyboardLock, mouseLock;
    
    
    public InjectionController(KeyInjector keyboard, MouseInjector mouse, Window target) {
        if (keyboard == null || mouse == null) {
            throw new IllegalArgumentException("Null-value");
        }
        keyDelegate = keyboard;
        mouseDelegate = mouse;
        this.target = target;
        
        keyboardLock = new Object();
        mouseLock = new Object();
    }

    public KeyInjector getKeyDelegate() {
        return keyDelegate;
    }

    public MouseInjector getMouseDelegate() {
        return mouseDelegate;
    }

    public void setKeyDelegate(KeyInjector keyDelegate) {
        if (keyDelegate == null) {
            throw new IllegalArgumentException("Null-value");
        }
        synchronized (keyboardLock) {
            this.keyDelegate = keyDelegate;
        }
    }

    public void setMouseDelegate(MouseInjector mouseDelegate) {
        if (mouseDelegate == null) {
            throw new IllegalArgumentException("Null-value");
        }
        synchronized (mouseLock) {
            this.mouseDelegate = mouseDelegate;
        }
    }
    
    @Override
    public void setTarget(Window comp) {
        synchronized (keyboardLock) {
            keyDelegate.setTarget(comp);
        }
        try {
            synchronized (mouseLock) {
                mouseDelegate.setTarget(comp);
            }
            target = comp;
        } catch (IllegalArgumentException e) {
            synchronized (keyDelegate) {
                keyDelegate.setTarget(target);
            }
        }
    }

    public Window getTarget() {
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
