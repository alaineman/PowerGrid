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

import java.awt.AWTException;
import java.awt.Component;
import java.awt.Robot;
import java.awt.Window;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;
import net.pgrid.loader.Logger;

/**
 *
 * @author Chronio
 */
public class RobotKeyInjector extends AbstractKeyInjector {

    private static final long serialVersionUID = 98160654835098234L;
    
    private Component target;
    private transient Robot rob = null;
    
    /**
     * Creates a new RobotKeyInjector for the specified Window
     * @param comp
     * @throws AWTException 
     */
    public RobotKeyInjector(Window comp) throws AWTException {
        target = comp;
    }

    /**
     * @return the Robot instance, or null if none can be created.
     */
    protected Robot getRob() {
        if (rob == null) {
            try {
                rob = new Robot();
            } catch (AWTException e) {
                Logger.get("Injection").describe(e);
            }
        }
        return rob;
    }
    
    /**
     * Ensures that the target window has focus. This prevents issues where 
     * the Robot starts sending keystrokes to other applications. 
     */
    protected void ensureFocus() {
        if (target instanceof Window) {
            if (((Window)target).getFocusOwner() == null) {
                // if the FocusOwner of our target is null, it means the target window is not in focus.
                // So we display a message that gives the user the oppertunity to set the focus correctly before printing.
                // Later, this should happen automatically when required, but it's a stable solution for now.
                JOptionPane.showMessageDialog(null, 
                        "Please ensure the Applet window has focus\nAfter this dialog closes, printing will start in 3 seconds", 
                        "Ensure correct focus", JOptionPane.INFORMATION_MESSAGE);
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException e) {}
            }
        } else {
            throw new IllegalStateException("Target Component is no Window");
        }
    }
    
    @Override 
    public void setTarget(Component comp) {
        target = comp;
    }

    @Override
    public void keyPressed(int keyCode, int modifiers) {
        ensureFocus();
        getRob().keyPress(keyCode);
    }

    @Override
    public void keyReleased(int keyCode, int modifiers) {
        ensureFocus();
        getRob().keyRelease(keyCode);
    }

    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        ensureFocus();
        boolean use_alt = (modifiers & KeyEvent.ALT_DOWN_MASK) != 0, 
                use_shift = (modifiers & KeyEvent.SHIFT_DOWN_MASK) != 0, 
                use_ctrl = (modifiers & KeyEvent.CTRL_DOWN_MASK) != 0;
        if (use_ctrl) {
            getRob().keyPress(KeyEvent.VK_CONTROL);
        }
        if (use_alt) {
            getRob().keyPress(KeyEvent.VK_ALT);
        }
        if (use_shift) {
            getRob().keyPress(KeyEvent.VK_SHIFT);
        }
        try {
            getRob().keyPress(keyCode);
            try {
                Thread.sleep(getDuration());
            } catch (InterruptedException e) {}
            getRob().keyRelease(keyCode);
        } catch (IllegalArgumentException e) {
            String modifierString = (use_shift ? "shift " : "") + (use_ctrl ? "ctrl " : "") + (use_alt ? "alt " : "");
            System.out.println("Warning: Invalid keyCode (" + keyCode + "), supposed char: " + c + ", modifiers = { " + modifierString + "}");
        }
        if (use_shift) {
            getRob().keyRelease(KeyEvent.VK_SHIFT);
        }
        if (use_alt) {
            getRob().keyRelease(KeyEvent.VK_ALT);
        }
        if (use_ctrl) {
            getRob().keyRelease(KeyEvent.VK_CONTROL);
        }
    }

    @Override
    public boolean isDurationSupported() {
        return true;
    }
}
