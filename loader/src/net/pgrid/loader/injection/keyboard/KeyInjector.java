package net.pgrid.loader.injection.keyboard;

import java.awt.Component;

/**
 * Interface for classes that can inject keystrokes into the virtual machine.
 * <p/>
 * Implementing classes need not be Thread-safe, since AWT/Swing event handling 
 * is not Thread-safe either. Implementing classes must assert that their 
 * implementations are re-entrant, since multiple events can happen at the 
 * same time.
 * <p/>
 * @author Chronio
 */
public interface KeyInjector {

    /**
     * Sets the target Component for future keystrokes.
     * <p/>
     * Any keyPressed, keyReleased or keyTyped method call done after this 
     * invocation should use the new Component (if applicable).
     * <p/>
     * When calling this method, please assert beforehand that the provided 
     * component is not null. Similarly, implementing classes need not check for
     * null values here, the behavior of calling this method with null as 
     * parameter is undefined.
     * <p/>
     * @param comp the target component.
     */
    public void setTargetComponent(Component comp);
    
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
