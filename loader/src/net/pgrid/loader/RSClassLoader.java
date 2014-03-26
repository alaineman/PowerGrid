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
            return classLoader.loadClass(name);
        } catch (ClassNotFoundException e) {
            PGLoader.err.append(e.getClass().getSimpleName()).append(": ").println(e.getMessage());
            // simplify things on the C++ end by returning null
            return null;
        }
    }
}
