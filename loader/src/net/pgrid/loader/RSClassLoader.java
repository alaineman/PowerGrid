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

package net.pgrid.loader;

/**
 * Provides Class instances to the native client by loading them from the 
 * Runescape client's ClassLoader.
 * 
 * @author Patrick Kramer
 */
public class RSClassLoader {
    public static final RSClassLoader INSTANCE = new RSClassLoader();
    
    private ClassLoader classLoader = null;
    
    private RSClassLoader() {
    }
    
    public synchronized void provideClassLoader(ClassLoader loader) {
        if (classLoader == null) {
            classLoader = loader;
        } else {
            throw new IllegalStateException("ClassLoader already set");
        }
    }
    
    public synchronized Class<?> findClass(String name) {
        if (classLoader == null) {
            return null;
        }
        try {
            // First try to get the Class from the RS class loader.
            return classLoader.loadClass(name);
        } catch (ClassNotFoundException e1) {
            // If that didn't work, try to get the Class from our Agent:
            try {
                // If the Agent is started, we can get any Class that is loaded
                // by the JVM, so this should always work (if the Agent is started)
                return Agent.findClass(name);
            } catch (IllegalStateException e2) {
                // The Agent was not started, do there's nothing we can do...
                return null;
            }
        }
        
    }
}
