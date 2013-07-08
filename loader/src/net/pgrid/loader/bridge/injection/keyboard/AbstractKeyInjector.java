package net.pgrid.loader.bridge.injection.keyboard;

import java.awt.Window;
import java.util.Objects;

/**
 * Abstract implementation of the KeyInjector interface.
 * <p/>
 * It provides a basic getter and setter for the KeyInjector's target, as well 
 * as a mechanism to control the delay between typed characters. 
 * <p/>
 * @author Chronio
 */
public abstract class AbstractKeyInjector implements KeyInjector {

    private Window target = null;
    private int duration = 0;

    /**
     * @return this KeyInjector's target
     */
    public Window getTarget() {
        return target;
    }
    
    /**
     * Sets this KeyInjector's target. 
     * <p/>
     * Subclasses may override this method and throw an IllegalArgumentException
     * when the given Window is not valid.
     * @param comp the new target component.
     * @throws IllegalArgumentException when the provided Window is invalid.
     */
    @Override
    public void setTarget(Window comp) {
        target = comp;
    }

    /**
     * Sets the duration (in milliseconds) of a single key press.
     * <p/>
     * If <code>duration &lt;= 0</code>, the duration is set to 0.
     * <p/>
     * Note that due to required computations the actual duration of the 
     * keyPressed, keyReleased and keyTyped method calls may be longer than 
     * the provided duration.
     * However, if <code>isDurationSupported()</code> returns true for this 
     * AbstractKeyInjector, these methods take at least the time given by 
     * <code>getDuration()</code> to complete. If this AbstractKeyInjector does 
     * not support event duration, this setting is ignored.
     * @param duration the duration (in milliseconds)
     */
    public void setDuration(int duration) {
        this.duration = (duration < 0 ? 0 : duration);
    }

    /**
     * @return the duration set using <code>setDuration(int)</code>, or 0 as a default value.
     */
    public int getDuration() {
        return duration;
    }

    /**
     * Returns whether this KeyInjector supports timed events.
     * <p/>
     * If this method returns true, this KeyInjector waits the amount of 
     * milliseconds indicated by <code>getDuration()</code> for each keyTyped 
     * method invocation. It is possible to change this value by calling the 
     * <code>setDuration(int)</code> method.
     * <p/>
     * If this method returns false, 
     * @return true if this AbstractKeyInjector supports durations, false otherwise.
     */
    public abstract boolean isDurationSupported();

    /**
     * Sends a keyTyped event using this KeyInjector.
     * <p/>
     * The default implementation simply calls the keyPressed method, then waits
     * the amount of milliseconds given by <code>getDuration()</code>, and then 
     * calls keyRelease.
     * <p/>
     * If <code>isDurationSupported()</code> returns false for this KeyInjector, 
     * then the wait between the keyPressed and keyReleased method calls is 
     * skipped.
     * <p/>
     * @param c the typed character, ignored in this implementation
     * @param keyCode the keyCode of the typed key
     * @param modifiers the modifiers for the given key
     */
    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        keyPressed(keyCode, modifiers);
        if (isDurationSupported()) {
            try {
                Thread.sleep(getDuration());
            } catch (InterruptedException e) {}
        }
        keyReleased(keyCode, modifiers);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null && obj.getClass().equals(this.getClass())) {
            AbstractKeyInjector that = (AbstractKeyInjector) obj;
            return (Objects.equals(this.getTarget(), that.getTarget()) &&
                    this.isDurationSupported() == that.isDurationSupported());
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 79 * hash + Objects.hashCode(target);
        hash = 79 * hash + (isDurationSupported() ? 13 : 0);
        return hash;
    }

    @Override
    public String toString() {
        return "KeyInjector(" + target + (isDurationSupported() ? ", " + getDuration() : "") + ")";
    }
}
