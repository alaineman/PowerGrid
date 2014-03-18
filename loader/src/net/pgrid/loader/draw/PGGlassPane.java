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
import java.awt.Component;
import java.awt.Graphics;
import java.awt.event.InputEvent;
import java.util.HashSet;
import java.util.Set;
import javax.swing.JComponent;
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
public class PGGlassPane extends JComponent {
    
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
    public void paintComponents(Graphics g) {
        super.paintComponents(g);
        
        // Don't bother drawing if we're not visible
        if (!isShowing()) return;
        
        for (DrawAction a : drawActions) {
            try {
                a.draw(g);
            } catch (RuntimeException e) {
                // We want to continue drawing even if one of the DrawActions
                // throws a RuntimeException.
                Logger.get("OVERLAY").log("DrawAction \"" + e.toString() + "\" failed: ", e);
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
    
}
