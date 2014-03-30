/*
 * Copyright (C) 2014 Patrick Kramer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package net.pgrid.loader.draw;

import java.awt.AWTEvent;
import java.awt.Canvas;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.event.InputEvent;
import java.awt.image.BufferStrategy;
import java.util.HashSet;
import java.util.Set;
import net.pgrid.loader.PGLoader;
import net.pgrid.loader.logging.Logger;

/**
 * GlassPane for the RS Applet window.
 * 
 * It provides a transparent pane over the RS Applet window to draw overlays on.
 * Since the overlays are drawn on a different component, they do not interfere 
 * with the Runescape client at all. 
 * 
 * Additionally, using a glass pane allows our client to block input events from 
 * the user. This behavior can be set using {@code setBlockInput(boolean)}. Note 
 * that input can only be blocked when the glass pane is visible.
 * 
 * @author Patrick Kramer
 * @internal not sure if event intercepting works due to the event handling 
 *           workarounds in RS. Well, in that case we can still just use this
 *           as a nice (as well as a non-intrusive and undetectable) way to 
 *           draw overlays...
 */
public class PGGlassPane extends Canvas {
    
    private final Component parent;
    private final Set<DrawAction> drawActions;
    private volatile boolean block = false;
    
    /**
     * Creates a new PGGlassPane.
     * @param parent the Component to forward events to
     */
    public PGGlassPane(Component parent) {
        this.parent = parent;
        this.drawActions = new HashSet<>(8);
    }

    @Override
    public boolean isLightweight() {
        return false; // hack override
    }
    
    @Override
    public void paint(Graphics g) {
        PGLoader.out.println("paintComponents called");
        
        // Don't bother drawing if we're not visible
        if (!isShowing()) return;
        
        for (DrawAction a : drawActions) {
            // Create a copy of our original Graphics object to pass around.
            Graphics scratchGraphics = g.create();
            try {
                a.draw(scratchGraphics);
            } catch (RuntimeException e) {
                // We want to continue drawing even if one of the DrawActions
                // throws a RuntimeException.
                Logger.get("OVERLAY").log("DrawAction \"" + a.toString() + "\" failed: ", e);
            } finally {
                scratchGraphics.dispose();
            }
        }
    }
    
    /**
     * Adds a DrawAction to this PGGlassPane
     * @param a the action to add
     * @return true if the action was added, false otherwise
     */
    public boolean addDrawAction(DrawAction a) {
        if (a != null) {
            boolean changed = drawActions.add(a);
            if (changed) checkEnableGlassPane();
            return changed;
        } else {
            return false;
        }
    }
    
    /**
     * Removes a DrawAction from this PGGlassPane
     * @param a the action to remove
     * @return true if this PGGlassPane contained the action and it was removed,
     *         false otherwise
     */
    public boolean removeDrawAction(DrawAction a) {
        boolean changed = drawActions.remove(a);
        if (changed) checkEnableGlassPane();
        return changed;
    }
    
    /**
     * Sets whether to block input events
     * @param block true to block input, false to allow input
     */
    public void setBlockInput(boolean block) {
        this.block = block;
        checkEnableGlassPane();
    }
    
    /**
     * Returns whether input is being blocked.
     * @return true if input is blocked, false otherwise
     */
    public boolean getBlockInput() {
        return block;
    }
    
    /**
     * Checks to see if the glass pane can be disabled.
     * The GlassPane can be automatically disabled when no DrawActions are 
     * registered, and the glass pane is not blocking events.
     */
    protected void checkEnableGlassPane() {
        if (getBlockInput()) {
            setVisible(true);
        } else if (drawActions.isEmpty()) {
            setVisible(false);
        } else {
            setVisible(true);
        }
    }

    /**
     * Forwards AWT Events to the parent.
     * 
     * If {@code getBlockInput()} returns true and the event is an InputEvent, 
     * the event is not forwarded. In that case, this method does nothing. In all
     * other cases, the event is forwarded to the parent Component provided in 
     * this PGGlassPane's constructor.
     * 
     * @param e the AWTEvent to forward
     */
    @Override
    protected void processEvent(AWTEvent e) {
        if (!getBlockInput() || !(e instanceof InputEvent)) {
            parent.dispatchEvent(e);
        }
    }
    
    public RepaintHelper createPaintScheduler(BufferStrategy strategy) {
        RepaintHelper helper = new RepaintHelper(strategy);
        setIgnoreRepaint(true);
        return helper;
    }
    
    public class RepaintHelper implements Runnable {
        private final BufferStrategy strategy;
        public RepaintHelper(BufferStrategy strategy) {
            this.strategy = strategy;
        }
        @Override
        @SuppressWarnings("SleepWhileInLoop")
        public void run() {
            // Calls paint(Graphics) roughly every 37-40 milliseconds.
            // This is equivalent to approximately 25 frames/second.
            while (true) {
                long start = System.nanoTime();
                Graphics g = strategy.getDrawGraphics();
                paint(g);
                strategy.show();
                try {
                    long timeTaken = System.nanoTime() - start;
                    if (timeTaken < 37000000) { // (37 ms)
                        // The remaining 3 ms can be lost in the computation
                        // and System.nanoTime() calls. 
                        Thread.sleep(40 - (timeTaken/1000000));
                    }
                } catch (InterruptedException e) {
                }
            }
        }
    }
}
