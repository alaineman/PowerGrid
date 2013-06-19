package net.pgrid.loader.injection.keyboard;

import java.awt.Component;
import static java.awt.event.KeyEvent.*;
import java.util.HashMap;

/**
 * This class wraps a KeyInjector to write a String as a series of key presses.
 * <p/>
 * It does so by using a Map containing the character mappings. For each 
 * character in the String to be typed, the StringInjector calls the keyTyped method 
 * of the KeyInjector with the appropriate arguments.
 * 
 * @author Chronio
 */
public class StringInjector implements KeyInjector {
    
    private KeyInjector injector;
    private static HashMap<Character, Integer> charBindings;
    
    /**
     * Creates a new StringInjector that delegates to the given KeyInjector
     * @param injector the KeyInjector this StringInjector should use
     */
    public StringInjector(KeyInjector injector) {
        assert injector != null;
        this.injector = injector;
        charBindings = new HashMap<>(128);
    }
    
    /**
     * Populates the map with the character data.
     * <p/>
     * This is called automatically by the typeString method when called for the 
     * first time, but can be called on beforehand to save time later.
     */
    public static void populateMap() {
        for (int code = 0x00; code <= 0x300; code++) {
            char c = getCharFromKeyCode(code);
            if (c != CHAR_UNDEFINED) {
                charBindings.put(c, code);
            }
        }
    }
    
    public static Integer getFromMap(Character c) {
        return charBindings.get(c);
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
     * not be typed correctly. Only the Shift-modifier is used and only for 
     * alphabetic characters. All other characters are typed without modifier 
     * keys.
     * <p/>
     * This method simply calls typeChar for each character in the String.
     * <p/>
     * @param s the String to type
     */
    public void typeString(String s) {
        if (charBindings.isEmpty()) {
            populateMap();
        }
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
     * Instead, this method should do nothing as to not interrupt the typing of the possible remainder of a String typed by the typeString method
     * @param c the character to type.
     */
    public void typeChar(char c) {
        Integer code = getFromMap(c);
        int modifiers;
        if (code == null) {
            return;
        }
        if (Character.isUpperCase(c)) {
            modifiers = SHIFT_DOWN_MASK;
        } else {
            modifiers = 0;
        }
        keyTyped(c, code, modifiers);
    }
    
    public static char getCharFromKeyCode(int keyCode) {
        if (keyCode >= VK_0 && keyCode <= VK_9 ||
            keyCode >= VK_A && keyCode <= VK_Z) {
            return (char)keyCode;
        }
        switch (keyCode) {
            case VK_SPACE: return ' ';
            case VK_TAB: return '\t';
            case VK_ENTER: return '\n';
                
            case VK_COMMA: return ',';
            case VK_PERIOD: return '.';
            case VK_SLASH: return '/';
            case VK_SEMICOLON: return ';';
            case VK_EQUALS: return '=';
            case VK_OPEN_BRACKET: return '[';
            case VK_CLOSE_BRACKET: return ']';
            case VK_BACK_SLASH: return '\\';
                
            case VK_MULTIPLY: return '*';
            case VK_ADD: return '+';
            case VK_SEPARATOR: return ',';
            case VK_SUBTRACT: return '-';
            case VK_DECIMAL: return '.';
            case VK_DIVIDE: return '/';
                
            case VK_AMPERSAND: return '&';
            case VK_ASTERISK: return '*';
            case VK_QUOTE: return '\'';
            case VK_QUOTEDBL: return '"';
            case VK_LESS: return '<';
            case VK_GREATER: return '>';
            case VK_BRACELEFT: return '{';
            case VK_BRACERIGHT: return '}';
            case VK_AT: return '@';
            case VK_COLON: return ':';
            case VK_CIRCUMFLEX: return '^';
            case VK_DOLLAR: return '$';
            case VK_EURO_SIGN: return '€';
            case VK_EXCLAMATION_MARK: return '!';
            case VK_INVERTED_EXCLAMATION_MARK: return '¡';
            case VK_LEFT_PARENTHESIS: return '(';
            case VK_RIGHT_PARENTHESIS: return ')';
            case VK_MINUS: return '-';
            case VK_PLUS: return '+';
            case VK_UNDERSCORE: return '_';
            case VK_NUMBER_SIGN: return '#';
        }
        if (keyCode >= VK_NUMPAD0 && keyCode <= VK_NUMPAD9) {
            return (char)(keyCode - VK_NUMPAD0 + '0');
        }
        if ((keyCode & 0x01000000) != 0) {
            return (char)(keyCode ^ 0x01000000);
        }
        return CHAR_UNDEFINED;
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
    public void setTargetComponent(Component comp) {
        getInjector().setTargetComponent(comp);
    }
}
