package net.pgrid.loader.bridge.injection.keyboard;

import java.awt.Window;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.HashMap;
import javax.swing.KeyStroke;
import net.pgrid.loader.Logger;

/**
 * This class wraps a KeyInjector to write a String as a series of key presses.
 * <p/>
 * It does so by using a Map containing the character mappings. For each 
 * character in the String to be typed, the StringInjector calls the keyTyped method 
 * of the KeyInjector with the appropriate arguments.
 * 
 * @author Chronio
 */
public class StringInjector extends AbstractKeyInjector {
    
    private static Logger LOGGER = Logger.get("INJECT");
    
    private KeyInjector injector;
    private static URL keyboardFile = ClassLoader.getSystemResource("net/pgrid/loader/injection/keyboard/international.keys");
    private static HashMap<Character, KeyStroke> keyStrokes;
    private static volatile boolean loadedCharDefinitions = false;
    
    public static synchronized KeyStroke getKeyStroke(char c) {
        KeyStroke stroke = keyStrokes.get(c);
        if (stroke == null) {
            if (Character.isLowerCase(c) || Character.isDigit(c)) {
                stroke = KeyStroke.getKeyStroke(c);
            } else if (Character.isUpperCase(c)) {
                stroke = KeyStroke.getKeyStroke("shift typed " + Character.toLowerCase(c));
            } else {
                // trial-and-error mode for finding the correct puntuation:
                // first try simply the key itself.
                stroke = KeyStroke.getKeyStroke("typed " + c);
                
                // if that fails, try to load the external definitions (in the keybindings file)
                if (stroke == null) {
                    loadDefinitions();
                    stroke = keyStrokes.get(c);
                }
            }
            if (stroke != null) {
                keyStrokes.put(c, stroke);
            } else {
                LOGGER.log("Cannot detect keystroke for character " + c);
            }
        }
        return stroke;
    }
    
    public static synchronized void loadDefinitions() {
        if (!loadedCharDefinitions) {
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(keyboardFile.openStream()))) {
                while (reader.ready()) {
                    String line = reader.readLine();
                    if (!line.isEmpty() && !line.startsWith("//")) {
                        char c = line.charAt(0);
                        KeyStroke kStroke = KeyStroke.getKeyStroke(line.substring(2).trim());
                        if (kStroke != null) {
                            keyStrokes.put(c, kStroke);
                        } else {
                            LOGGER.log("WARNING: definition for " + c + " is no valid KeyStroke");
                        }
                    }
                }
            } catch (IOException e) {
                LOGGER.describe(e);
            }
        }
    }
    
    /**
     * Creates a new StringInjector that delegates to the given KeyInjector
     * @param injector the KeyInjector this StringInjector should use
     */
    public StringInjector(KeyInjector injector) {
        assert injector != null;
        this.injector = injector;
        if (keyStrokes == null) {
            keyStrokes = new HashMap<>(128);
        }
    }

    /**
     * @return the KeyInjector this StringInjector uses.
     */
    public KeyInjector getInjector() {
        return injector;
    }

    /**
     * Types the given String using this StringInjector's KeyInjector.
     * <p/>
     * If there are undefined or unknown characters in the String, these may 
     * not be typed correctly. If a character cannot be typed, it is ignored and
     * this method continues with the next character without any warning.
     * <p/>
     * This method simply calls typeChar for each character in the String.
     * <p/>
     * @param s the String to type
     */
    public void typeString(String s) {
        for (char c : s.toCharArray()) {
            typeChar(c);
        }
    }
    
    /**
     * Types a single character using this StringInjector's KeyInjector.
     * <p/>
     * Subclasses can override this method but should call their super 
     * implementation when they cannot type the character themselves.
     * <p/>
     * This method should not throw Exceptions when the character cannot be typed.
     * Instead, this method should do nothing as to not interrupt the typing of 
     * the possible remainder of a String typed by the typeString method.
     * @param c the character to type.
     */
    public void typeChar(char c) {
        KeyStroke stroke = getKeyStroke(c);
        if (stroke != null) {
            getInjector().keyTyped(
                    stroke.getKeyChar(), 
                    KeyEvent.getExtendedKeyCodeForChar(stroke.getKeyChar()), 
                    stroke.getModifiers());
        }
    }

    @Override
    public void keyPressed(int keyCode, int modifiers) {
        getInjector().keyPressed(keyCode, modifiers);
    }

    @Override
    public void keyReleased(int keyCode, int modifiers) {
        getInjector().keyReleased(keyCode, modifiers);
    }

    @Override
    public void keyTyped(char c, int keyCode, int modifiers) {
        getInjector().keyTyped(c, keyCode, modifiers);
    }

    @Override
    public void setTarget(Window comp) {
        getInjector().setTarget(comp);
    }

    @Override
    public Window getTarget() {
        if (getInjector() instanceof AbstractKeyInjector) {
            return ((AbstractKeyInjector)getInjector()).getTarget();
        } else {
            return null;
        }
    }

    @Override
    public boolean isDurationSupported() {
        if (getInjector() instanceof AbstractKeyInjector) {
            return ((AbstractKeyInjector)getInjector()).isDurationSupported();
        } else {
            return false;
        }
    }
}
