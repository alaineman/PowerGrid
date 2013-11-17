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
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.HashMap;
import javax.swing.KeyStroke;
import net.pgrid.loader.logging.Logger;

/**
 * This class wraps a KeyInjector to write a String as a series of key presses.
 * <p/>
 * It does so by using a Map containing the character mappings. For each 
 * character in the String to be typed, the StringInjector calls the keyTyped 
 * method of the underlying KeyInjector with the appropriate arguments.
 * <p/>
 * The StringInjector can act as a perfectly valid KeyInjector, delegating the 
 * methods defined in the KeyInjector interface to the underlying KeyInjector
 * instance.
 * <p/>
 * @author Chronio
 */
public class StringInjector extends AbstractKeyInjector {
    
    private static final long serialVersionUID = 32581134834L;
    
    private static final Logger LOGGER = Logger.get("INJECT");
    
    private final KeyInjector injector;
    /**
     * The standard keyboard layout file to load.
     * <p/>
     * It is loaded automatically when the StringInjector's typeString or typeChar 
     * method is called for the first time.
     * <p/>
     * The same keyStroke map is shared between all StringInjector instances,
     * so once it is loaded for one StringInjector, it is also loaded for every 
     * other StringInjector instance.
     */
    public static final URL keyboardFile = ClassLoader.getSystemResource("net/pgrid/loader/bridge/injection/keyboard/international.keys");
    
    /**
     * Map containing the KeyStroke objects for each individual character.
     * <p/>
     * It is filled automatically and through calling the loadDefinitions methods.
     */
    private static volatile HashMap<Character, KeyStroke> keyStrokes;
    
    /**
     * Indicates if the default keyboard File has been loaded.
     * @see StringInjector#keyboardFile
     */
    private static volatile boolean loadedCharDefinitions = false;
    
    /**
     * Convenience method that wraps the given KeyInjector in a StringInjector
     * unless the KeyInjector already was a StringInjector, in which case the
     * parameter is returned as a StringInjector.
     * <p/>
     * This prevents redundant StringInjectors wrapping other StringInjectors.
     * <p/>
     * @param ki the KeyInjector
     * @return a StringInjector delegating to the given KeyInjector, or the 
     *         KeyInjector cast to StringInjector is it is already an instance
     *         of StringInjector.
     */
    public static StringInjector wrap(KeyInjector ki) {
        if (ki instanceof StringInjector) {
            return (StringInjector) ki;
        } else {
            return new StringInjector(ki);
        }
    }
    
    /**
     * Returns a KeyStroke object for typing the given character.
     * <p/>
     * If the KeyStroke is unknown, this method returns null.
     * @param c the character to type
     * @return the KeyStroke corresponding to the typed character
     */
    public static synchronized KeyStroke getKeyStroke(char c) {
        KeyStroke stroke = keyStrokes.get(c);
        if (stroke == null) {
            if (Character.isLowerCase(c) || Character.isDigit(c)) {
                stroke = KeyStroke.getKeyStroke(c);
            } else if (Character.isUpperCase(c)) {
                stroke = KeyStroke.getKeyStroke("shift typed " + Character.toLowerCase(c));
            } else {
                loadDefinitions();
                stroke = keyStrokes.get(c);
                if (stroke == null) {
                    stroke = KeyStroke.getKeyStroke("typed " + c);
                }
            }
            if (stroke != null) {
                keyStrokes.put(c, stroke);
            } else {
                LOGGER.log("Cannot create keystroke for character " + c);
            }
        }
        return stroke;
    }
    
    /**
     * Loads Character definitions from the specified InputStream.
     * <p/>
     * This method overwrites all key bindings that were already defined and are 
     * also defined in the data from the InputStream parameter.
     * <p/>
     * This method does not throw Exceptions upon failure, but instead parses 
     * the entire InputStream for usable data. Any incorrectly formatted data is 
     * ignored, and a warning is printed to the Logger labeled "INJECT".
     * <p/>
     * @param in the InputStream to read from.
     */
    public static synchronized void loadDefinitions(InputStream in) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(in, "UTF-8"))) {
            while (reader.ready()) {
                String line = reader.readLine();
                if (!line.isEmpty() && !line.startsWith("//")) {
                    char c = line.charAt(0);
                    KeyStroke kStroke = KeyStroke.getKeyStroke(line.substring(2).trim());
                    if (kStroke == null) {
                        LOGGER.log("WARNING: definition for " + c + " is no valid KeyStroke");
                    } else {
                        keyStrokes.put(c, kStroke);
                    }
                }
            }
        } catch (IOException e) {
            LOGGER.describe(e);
        }
    }
    
    /**
     * Loads Character definitions from the default Keyboard File.
     * <p/>
     * If the default keyboard File has been loaded before, this method does 
     * nothing.
     * <p/>
     * This method delegates to <code>loadDefinitions(InputStream)</code>.
     * <p/>
     * @see StringInjector#keyboardFile
     * @see StringInjector#loadDefinitions(java.io.InputStream) 
     */
    public static synchronized void loadDefinitions() {
        if (!loadedCharDefinitions) {
            try {
                loadDefinitions(keyboardFile.openStream());
                LOGGER.log("Character definitions have been loaded");
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
                    c, 
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
    public void setTarget(Component comp) {
        getInjector().setTarget(comp);
    }

    /**
     * Returns the wrapped KeyInjector's target Component.
     * <p/>
     * If the wrapped KeyInjector is an AbstractKeyInjector, this method returns
     * the value returned by the AbstractKeyInjector's <code>getTarget()</code>
     * method.
     * Else, this method returns null.
     * @return the target Component of this KeyInjector
     */
    @Override
    public Component getTarget() {
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
