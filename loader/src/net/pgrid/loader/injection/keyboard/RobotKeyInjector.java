package net.pgrid.loader.injection.keyboard;

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.Window;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;

/**
 *
 * @author Patrick Kramer
 */
public class RobotKeyInjector implements KeyInjector {

    private Window target;
    private Robot rob;
    private volatile int characterDelay = 0;
    private final FocusWaiter waiter;
    
    public RobotKeyInjector(Window comp) throws AWTException {
        rob = new Robot();
        target = comp;
        waiter = new FocusWaiter();
        target.addFocusListener(waiter);
    }

    public void setCharacterDelay(int characterDelay) {
        this.characterDelay = (characterDelay < 0 ? 0 : characterDelay);
    }

    public int getCharacterDelay() {
        return characterDelay;
    }
    
    /**
     * Ensures that the target window has focus. This prevents issues where 
     * the Robot starts sending keystrokes to other applications. 
     */
    protected void ensureFocus() {
        if (target.getFocusOwner() == null) {
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
    }
    
    @Override 
    public void setTargetComponent(Window comp) {
        target.removeFocusListener(waiter);
        target = comp;
        target.addFocusListener(waiter);
    }

    @Override
    public void keyPressed(int keyCode, int modifiers) {
        ensureFocus();
        rob.keyPress(keyCode);
    }

    @Override
    public void keyReleased(int keyCode, int modifiers) {
        ensureFocus();
        rob.keyRelease(keyCode);
    }

    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        ensureFocus();
        boolean use_alt = (modifiers & KeyEvent.ALT_DOWN_MASK) != 0, 
                use_shift = (modifiers & KeyEvent.SHIFT_DOWN_MASK) != 0, 
                use_ctrl = (modifiers & KeyEvent.CTRL_DOWN_MASK) != 0;
        if (use_ctrl) {
            rob.keyPress(KeyEvent.VK_CONTROL);
        }
        if (use_alt) {
            rob.keyPress(KeyEvent.VK_ALT);
        }
        if (use_shift) {
            rob.keyPress(KeyEvent.VK_SHIFT);
        }
        try {
            rob.keyPress(keyCode);
            try {
                Thread.sleep(getCharacterDelay());
            } catch (InterruptedException e) {}
            rob.keyRelease(keyCode);
        } catch (IllegalArgumentException e) {
            String modifierString = (use_shift ? "shift " : "") + (use_ctrl ? "ctrl " : "") + (use_alt ? "alt " : "");
            System.out.println("Warning: Invalid keyCode (" + keyCode + "), supposed char: " + c + ", modifiers (" + modifierString + ")");
        }
        if (use_shift) {
            rob.keyRelease(KeyEvent.VK_SHIFT);
        }
        if (use_alt) {
            rob.keyRelease(KeyEvent.VK_ALT);
        }
        if (use_ctrl) {
            rob.keyRelease(KeyEvent.VK_CONTROL);
        }
    }
    
    protected class FocusWaiter implements FocusListener {

        @Override
        public void focusGained(FocusEvent e) {
            synchronized (this) {
                notifyAll();
            }
        }

        @Override
        public void focusLost(FocusEvent e) {
        }
        
    }
}
