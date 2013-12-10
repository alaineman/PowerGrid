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
package net.pgrid.loader.bridge.injection.mouse;

import java.awt.Canvas;
import java.awt.Component;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import net.pgrid.loader.AppletFrame;

/**
 * Simple MouseInjector that works by pushing MouseEvent, MouseMotionEvent and
 * MouseWheelEvent objects into the target MouseListeners, MouseMotionListener, 
 * and MouseWheelListener.
 * 
 * @author Patrick Kramer
 */
public class AWTMouseInjector implements MouseInjector {

    private static final long serialVersionUID = 837320987402L;
    
    private Component target = null;
    
    private int mouseX = 0, mouseY = 0;
    
    private transient MouseListener mListener = null;
    private transient MouseMotionListener mmListener = null;
    private transient MouseWheelListener mwListener = null;
    
    @Override
    public void setTarget(Component comp) {
        target = comp;
        mListener = null;
        mmListener = null;
        mwListener = null;
    }
    
    /**
     * @return the MouseListener of the Canvas for placing events on
     */
    public MouseListener getMouseListener() {
        if (mListener == null) {
            if (!(target instanceof AppletFrame)) {
                throw new IllegalStateException("Target component must be a AppletFrame");
            }
            AppletFrame f = (AppletFrame) target;
            Canvas canvas = f.getCanvas();
            // we blindly assume here the Canvas has a MouseListener, for it 
            // always has unless it gets changed in the RS Applet code.
            // In that case, this piece of code fails (throws an 
            // ArrayIndexOutOfBoundsException), and the cause is made clear 
            // through this explanatory comment.
            mListener = canvas.getMouseListeners()[0];
        }
        return mListener;
    }
    
    /**
     * @return the MouseMotionListener of the Canvas for placing events on
     */
    public MouseMotionListener getMouseMotionListener() {
        if (mmListener == null) {
            if (!(target instanceof AppletFrame)) {
                throw new IllegalStateException("Target component must be a AppletFrame");
            }
            AppletFrame f = (AppletFrame) target;
            Canvas canvas = f.getCanvas();
            mmListener = canvas.getMouseMotionListeners()[0];
        }
        return mmListener;
    }
    
    /**
     * @return the MouseWheelListener of the Canvas for placing events on
     */
    public MouseWheelListener getMouseWheelListener() {
        if (mwListener == null) {
            if (!(target instanceof AppletFrame)) {
                throw new IllegalStateException("Target component must be a AppletFrame");
            }
            AppletFrame f = (AppletFrame) target;
            Canvas canvas = f.getCanvas();
            mwListener = canvas.getMouseWheelListeners()[0];
        }
        return mwListener;
    }

    @Override
    public void moveMouse(int x, int y) {
        getMouseMotionListener().mouseMoved(new MouseEvent(target, 
                MouseEvent.MOUSE_MOVED, System.currentTimeMillis(), 
                0, x, y, 0, false, MouseEvent.BUTTON1));
        mouseX = x;
    }

    @Override
    public void dragMouse(int x, int y, int button) {
        getMouseMotionListener().mouseDragged(new MouseEvent(target, 
                MouseEvent.MOUSE_DRAGGED, System.currentTimeMillis(), 
                0, x, y, 0, false, button));
        mouseY = y;
    }

    @Override
    public void clickMouse(int button) {
        getMouseListener().mouseClicked(new MouseEvent(target, 
                MouseEvent.MOUSE_CLICKED, System.currentTimeMillis(), 
                0, getX(), getY(), 0, false, button));
    }

    @Override
    public void pressMouse(int button) {
        getMouseListener().mouseClicked(new MouseEvent(target, 
                MouseEvent.MOUSE_PRESSED, System.currentTimeMillis(), 
                0, getX(), getY(), 0, false, button));
    }

    @Override
    public void releaseMouse(int button) {
        getMouseListener().mouseClicked(new MouseEvent(target, 
                MouseEvent.MOUSE_RELEASED, System.currentTimeMillis(), 
                0, getX(), getY(), 0, false, button));
    }

    @Override
    public void scrollUp() {
        getMouseWheelListener().mouseWheelMoved(new MouseWheelEvent(target, 
                MouseEvent.MOUSE_WHEEL, System.currentTimeMillis(), 0, getX(), 
                getY(), 0, false, MouseWheelEvent.WHEEL_UNIT_SCROLL, 1, -1));
    }

    @Override
    public void scrollDown() {
        getMouseWheelListener().mouseWheelMoved(new MouseWheelEvent(target, 
                MouseEvent.MOUSE_WHEEL, System.currentTimeMillis(), 0, getX(), 
                getY(), 0, false, MouseWheelEvent.WHEEL_UNIT_SCROLL, 1, 1));
    }

    @Override
    public int getX() {
        return mouseX;
    }

    @Override
    public int getY() {
        return mouseY;
    }

    @Override
    public boolean isBlocking() {
        // when the method returns, the event has already been delivered.
        // So, this class blocks until the event has been 'executed'.
        return true;
    }
    
}
