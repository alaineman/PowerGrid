/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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

import java.lang.reflect.Field;
import net.pgrid.loader.Agent;

/**
 * Utility class for providing quick access to various java.reflect utilities.
 * 
 * This class is mainly useful to inspect the JVM from the outside (as some 
 * sort of debugging utility). Due to the reflective nature of this class, some
 * operations in this class can be relatively time-consuming for large inputs.
 * 
 * Some of the methods in this class do not throw Exceptions and return String 
 * values of the result, making these methods particularly useful when accessing 
 * this class through JNI.
 * 
 * @author Patrick Kramer
 */
public class Reflection {
    
    private Reflection() {}
    
    /**
     * Returns the type name of the indicated field.
     * @param cls the Class object
     * @param fieldName the field name
     * @return the type name of the indicated field, or an error message if the
     *         field does not exist.
     */
    public static String getTypeName(Class<?> cls, String fieldName) {
        try {
            Field f = cls.getField(fieldName);
            return f.getType().getTypeName();
        } catch (NoSuchFieldException e) {
            return "ERR: No such field: " + fieldName;
        }
    }
    
    /**
     * Evaluates a sequence of field getters.
     * 
     * For example, you can pass "net/pgrid/loader/PGLoader.INSTANCE.frame" to
     * get the frame of the Runescape client.
     * 
     * Packages should be split by '/', and fields by '.'
     * 
     * Adding brackets has no effect (e.g. "net/pgrid/loader/PGLoader.INSTANCE"
     * behaves the same as "net/pgrid/loader/PGLoader.INSTANCE()").
     * 
     * @param expression the expression to evaluate.
     * @return the result of the expression
     * @throws RuntimeException if the expression could not be evaluated.
     */
    public static Object evaluate(String expression) {
        String[] parts = expression.split(".");
        Object result = Agent.findClass(parts[0].replace('/', '.'));
        if (result == null) {
            throw new RuntimeException("Could not find Class named " + parts[0]);
        }
        // Follow all field references
        for (int i=1; i<parts.length; i++) {
            // remove '()' if it is included.
            String part = parts[i];
            if (part.endsWith("()")) {
                part = part.substring(0, part.length()-2);
            }
            result = getObject(result, part);
        }
        return result;
    }
    
    /**
     * Gets the Object value of the specified field.
     * @param o the Object to get the field value from
     * @param field the field name
     * @return the value of the field for the given Object.
     * @throws RuntimeException if the field does not exist or is not accessible.
     */
    public static Object getObject(Object o, String field) {
        Object target = o;
        Class<?> cls = o.getClass();
        if (cls == Class.class) {
            target = null;
            cls    = (Class<?>) o;
        }
        try {
            Field f = cls.getField(field);
            f.setAccessible(true);
            return f.get(target);
        } catch (NoSuchFieldException | IllegalAccessException e) {
            throw new RuntimeException("Could not access field named " + field 
                                     + " in class " + cls.getName());
        }
    }
    
    /**
     * Evaluates a sequence of field getters.
     * @param expression the expression to evaluate.
     * @return a String representation of the result, or an error message 
     *         formatted as a String
     */
    public static String evaluateToString(String expression) {
        try {
            return String.valueOf(evaluate(expression));
        } catch (RuntimeException e) {
            return e.getMessage();
        }
    }
}
