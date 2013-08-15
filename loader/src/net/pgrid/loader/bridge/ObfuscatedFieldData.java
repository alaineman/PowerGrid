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
package net.pgrid.loader.bridge;

import java.util.ArrayList;

/**
 * Represents the obfuscation info of a given Field.
 * <p/>
 * The main advantage of using this Class over storing the mapping data raw is,
 * that this Class performs a syntactical check on the input Strings. As such, 
 * invalid or illegal java identifiers are directly uncovered.
 * <p/>
 * @author Patrick Kramer
 */
public class ObfuscatedFieldData {
    
    private String obfName;
    private String semanticName;
    private long fieldMultiplier;

    /**
     * Creates a new ObfuscatedFieldData binding from obfName to realName.
     * <p/>
     * @param obfName the obfuscated (actual) name of the Field
     * @param semanticName the semantic name of the Field
     * 
     * @param multiplier the multiplier of the Field
     * @throws IllegalArgumentException when one of the given names is not a 
     *                                  valid Java identifier.
     */
    public ObfuscatedFieldData(String obfName, String semanticName, long multiplier) {
        if (!checkValidJavaIdentifier(obfName) || 
            !checkValidJavaIdentifier(semanticName)) {
            throw new IllegalArgumentException("Invalid Java identifier");
        }
        if (obfName.indexOf('.') < 0 || semanticName.indexOf('.') < 0) {
            throw new IllegalArgumentException("Java identifier cannot relate to a field");
        }
        this.obfName = obfName;
        this.semanticName = semanticName;
        this.fieldMultiplier = multiplier;
    }

    /**
     * @return the obfuscated (actual) name of this Field, 
     *         given as package.className.fieldName
     */
    public String getObfName() {
        return obfName;
    }
    
    /**
     * @return the obfuscated class name
     */
    public String getClassName() {
        return obfName.substring(obfName.lastIndexOf('.'));
    }
    
    /**
     * @return the obfuscated field name (without the class prefixed)
     */
    public String getFieldName() {
        return obfName.substring(obfName.lastIndexOf('.'));
    }

    /**
     * @return the semantic name of the Field
     */
    public String getSemanticName() {
        return semanticName;
    }

    /**
     * @return the Field multiplier to be used for the Field given by this Object.
     */
    public long getFieldMultiplier() {
        return fieldMultiplier;
    }
    
    /**
     * Returns whether this ObfuscatedFieldData is equal to the given Object.
     * <p/>
     * This method returns true if and only if all of the following conditions are met:
     * <ul>
     *  <li>This Object and the other Object have the same Class.</li>
     *  <li>This Object's obfuscated name is equal to the other Object's 
     *      obfuscated name. That is, both Objects refer to the same 
     *      obfuscated field.</li>
     * </ul>
     * @param other the Object to check for equivalence
     * @return true if and only if this Object is equal to the given Object, false otherwise.
     */
    @Override
    public boolean equals(Object other) {
        if (other != null && other.getClass() == this.getClass()) {
            ObfuscatedFieldData that = (ObfuscatedFieldData) other;
            
            return this.getObfName().equals(that.getObfName());
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 79 * hash + obfName.hashCode();
        return hash;
    }

    @Override
    public String toString() {
        return "ObfuscatedFieldData(\"" + obfName + "\" => \"" + semanticName + "\")";
    }
    
    /**
     * Verifies that the given String is a valid Java identifier.
     * <p/>
     * @param s the String to check
     * @return true if and only if the given String is a valid Java identifier, false otherwise.
     */
    public static boolean checkValidJavaIdentifier(String s) {
        if (s != null && !s.isEmpty()) {
            // manually split the String on the '.' char, since String.split throws away trailing empty Strings.
            // As such, Strings ending in a period would be accepted, but they are invalid Java identifiers.
            ArrayList<String> parts = new ArrayList<>(Math.max(s.length() / 3, 3));
            int pos = -1;
            do {
                int start = pos + 1;
                pos = s.indexOf('.', start);
                if (pos < 0) {
                    parts.add(s.substring(start));
                    break;
                } else {
                    parts.add(s.substring(start, pos));
                }
            } while (pos < s.length());
            // Check for validity of each part of the Java identifier.
            // The first character of each part must be checked separately, since 
            // not all valid characters are also valid start characters.
            for (String part : parts) {
                if (part.isEmpty() || !Character.isJavaIdentifierStart(part.charAt(0))) {
                    return false;
                } else {
                    for (int index = 1; index < part.length(); index++) {
                        if (!Character.isJavaIdentifierPart(part.charAt(index))) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
    
    
}
