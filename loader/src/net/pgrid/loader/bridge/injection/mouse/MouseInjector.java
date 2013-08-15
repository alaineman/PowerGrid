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

import java.awt.Component;
import java.awt.event.MouseEvent;

/**
 * Interface for classes that can inject mouse movements and clicks into the
 * virtual machine.
 * <p/>
 * All coordinates given are window coordinates, meaning that the top-left
 * corner of the target Window is taken as (0,0) and the bottom and right 
 * directions are positive.
 * <p/>
 * Implementing classes need not be Thread-safe, since AWT/Swing event handling 
 * is not Thread-safe either. Implementing classes must assert that their 
 * implementations are re-entrant, since multiple events can happen at the 
 * same time.
 * <p/>
 * @author Chronio
 */
public interface MouseInjector {

    /**
     * Constant specifying the primary mouse button. Usually the left button.
     */
    public static final int BUTTON1 = MouseEvent.BUTTON1;
    /**
     * Constant specifying the secondary mouse button. Usually the right button.
     */
    public static final int BUTTON2 = MouseEvent.BUTTON2;
    /**
     * Constant specifying the tertiary mouse button. Usually the middle button
     */
    public static final int BUTTON3 = MouseEvent.BUTTON3;

    /**
     * Sets the target Component for future mouse events.
     * <p/>
     * Any event-related method call done after this 
     * invocation should use the new Component (if applicable).
     * <p/>
     * When calling this method, please assert beforehand that the provided 
     * component is not null. Similarly, implementing classes need not check for
     * null values here, the behavior of calling this method with null as 
     * parameter is undefined.
     * <p/>
     * @param comp the target Component.
     */
    public void setTarget(Component comp);
    
    /**
     * Moves the mouse to the position (x,y).
     *
     * @param x the x coordinate of the desired mouse position
     * @param y the y coordinate of the desired mouse position
     */
    public void moveMouse(int x, int y);

    /**
     * Drags the mouse from the current position to the given position (x,y).
     *
     * @param x the x coordinate of the desired mouse position
     * @param y the y coordinate of the desired mouse position
     * @param button the mouse button to use
     *
     * @throws IllegalArgumentException when the mouse button is invalid
     */
    public void dragMouse(int x, int y, int button);

    /**
     * Clicks the given button at the current position.
     *
     * @param button the mouse button to use
     *
     * @throws IllegalArgumentException when the mouse button is invalid
     */
    public void clickMouse(int button);

    /**
     * Presses the given button at the current position.
     * <p/>
     * If the mouse button was already pressed, this method should do nothing.
     *
     * @param button the mouse button to use
     *
     * @throws IllegalArgumentException when the mouse button is invalid
     */
    public void pressMouse(int button);

    /**
     * Releases the given button at the current position.
     * <p/>
     * If the mouse button was already released, this method should do nothing.
     *
     * @param button the mouse button to use
     *
     * @throws IllegalArgumentException when the mouse button is invalid
     */
    public void releaseMouse(int button);

    /**
     * Scrolls the page up one block. The amount scrolled should be equivalent
     * to a single "page up" key press.
     *
     * @throws UnsupportedOperationException when this MouseInjector does not
     * support mouse wheel events
     */
    public void scrollUp();

    /**
     * Scrolls the page down one block. The amount scrolled should be equivalent
     * to a single "page down" key press.
     *
     * @throws UnsupportedOperationException when this MouseInjector does not
     * support mouse wheel events
     */
    public void scrollDown();

    /**
     * @return the x-coordinate of the mouse pointer (according to this
     * injector)
     */
    public int getX();

    /**
     * @return the y-coordinate of the mouse pointer (according to this
     * injector)
     */
    public int getY();

    /**
     * Returns whether this MouseInjector blocks until the event has been
     * completed before returning.
     * <p/>
     * Implementations that return "true" guarantee to block until the event has
     * been completely processed and done. For implementations that return
     * "false" this need not be the case.
     *
     * @return whether this MouseInjector is blocking
     */
    public boolean isBlocking();
}
