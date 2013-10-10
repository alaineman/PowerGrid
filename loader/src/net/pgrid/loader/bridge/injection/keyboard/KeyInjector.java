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

import java.awt.Component;
import java.io.Serializable;

/**
 * Interface for classes that can inject keystrokes into the virtual machine.
 * <p/>
 * Implementing classes need not be Thread-safe, since AWT/Swing event handling 
 * is not Thread-safe either. Implementing classes must assert that their 
 * implementations are re-entrant, since multiple events may happen at the 
 * same time.
 * <p/>
 * @author Chronio
 */
public interface KeyInjector extends Serializable {

    /**
     * Sets the target Component for future keystrokes.
     * <p/>
     * Any keyPressed, keyReleased or keyTyped method call done after this 
     * invocation should use the new Component's focused component (if applicable).
     * <p/>
     * When calling this method, please assert beforehand that the provided 
     * Component object is not null. Similarly, implementing classes need not 
     * check for null values here, the behavior of calling this method with null as 
     * parameter is undefined and as such may leave the KeyInjector in an 
     * non-working state.
     * <p/>
     * @param comp the target component.
     * 
     * @throws NullPointerException when the component is null (optional)
     */
    public void setTarget(Component comp);
    
    /**
     * Presses the key given by the specified key code. These key codes are all
     * specified in {@link java.awt.event.KeyEvent}. modifiers should be a
     * bitwise or of the desired modifier keys. Again, these can be found in
     * {@link java.awt.event.KeyEvent}.
     *
     * @param keyCode the key code of the key to press.
     * @param modifiers the modifiers for the key press.
     *
     * @throws IllegalArgumentException when the given keyCode or modifiers is
     * invalid, or when the combination is invalid.
     *
     * @see java.awt.event.KeyEvent
     */
    public void keyPressed(int keyCode, int modifiers);

    /**
     * Releases the key given by the specified key code. These key codes are all
     * specified in {@link java.awt.event.KeyEvent}. modifiers should be a
     * bitwise or of the desired modifier keys. Again, these can be found in
     * {@link java.awt.event.KeyEvent}.
     *
     * @param keyCode the key code of the key to release.
     * @param modifiers the modifiers for the key release.
     *
     * @throws IllegalArgumentException when the given keyCode or modifiers is
     * invalid, or when the combination is invalid.
     *
     * @see java.awt.event.KeyEvent
     */
    public void keyReleased(int keyCode, int modifiers);

    /**
     * Types the given char, using the key given by the specified key code.
     * These key codes are all specified in {@link java.awt.event.KeyEvent}.
     * modifiers should be a bitwise or of the desired modifier keys. Again,
     * these can be found in {@link java.awt.event.KeyEvent}.
     * <p/>
     * When the combination of character and key code + modifiers is
     * inconsistent (the given key does not yield the provided character), the
     * effect of this method is undefined.
     *
     * @param c the character that was typed
     * @param keyCode the key code of the typed key.
     * @param modifiers the modifiers for the key.
     *
     * @throws IllegalArgumentException when the given keyCode or modifiers is
     * invalid, or when the combination is invalid.
     *
     * @see java.awt.event.KeyEvent
     */
    public void keyTyped(char c, int keyCode, int modifiers);
}
