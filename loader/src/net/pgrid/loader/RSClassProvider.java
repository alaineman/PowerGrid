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
package net.pgrid.loader;

/**
 * Provides Class instances to the native client by loading them from the 
 * Runescape client's ClassLoader.
 * 
 * @author Patrick Kramer
 */
public class RSClassProvider {
    
    private final ClassLoader classLoader;
    
    public static void main(String[] args) {
        Class<?> intType = Integer.TYPE;
        System.out.println(intType.getSuperclass());
    }
    
    /**
     * Creates a new RSClassProvider using the provided ClassLoader.
     * @param loader the ClassLoader to use.
     */
    public RSClassProvider(ClassLoader loader) {
        assert loader != null;
        this.classLoader = loader;
    }

    /**
     * Returns the ClassLoader this RSClassProvider loads from
     * @return the ClassLoader
     */
    public ClassLoader getClassLoader() {
        return classLoader;
    }
    
    /**
     * Returns the runtime Class object for the RS Class with the given name.
     * 
     * The name refers to the normal, obfuscated name.
     * 
     * This method first tries to load the Class through the RS ClassLoader. If 
     * that fails, it tries to get the Class from the Agent using 
     * {@code findClassFromAgent(String)}.
     * 
     * @param name the name of the class.
     * @return the Class with the given name, or null if the Class could 
     *         not be found
     */
    public synchronized Class<?> findClass(String name) {
        try {
            // First try to get the Class from the RS class loader.
            return classLoader.loadClass(name);
        } catch (ClassNotFoundException e) {
            // If that didn't work, try to get the Class from our Agent:
            return findClassFromAgent(name);
        }
    }
    
    /**
     * Returns the runtime Class object for the RS Class with the given name.
     * 
     * This method makes use of the PowerGrid Agent to find the Class. This 
     * method returns null if either the Agent was not started, or the Class
     * could not be found. If the Agent is started, then every Class is 
     * accessible through the Agent. In that case, this method returns null
     * if and only if no Class with the given name exists.
     * 
     * @param name the name of the Class
     * @return the Class, or null if the Class could not be found
     */
    public synchronized Class<?> findClassFromAgent(String name) {
        try {
            return Agent.findClass(name);
        } catch (IllegalStateException e) {
            // The Agent was not started, do there's nothing we can do...
            return null;
        }
    }
}
