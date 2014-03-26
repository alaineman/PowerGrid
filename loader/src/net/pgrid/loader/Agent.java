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

import java.lang.instrument.Instrumentation;

/**
 * Agent class to get a JVM Instrumentation instance.
 * 
 * This allows us to inspect / monitor the JVM and RS client at runtime.
 * @author Patrick Kramer
 */
public class Agent {
    
    private static Instrumentation instrumentation;
    
    public Instrumentation getInstrumentation() {
        return instrumentation;
    }
    
    /**
     * Called by the JVM when this Agent is loaded (before main is invoked).
     * 
     * @param agentArgs the arguments for this Agent (ignored)
     * @param inst the Instrumentation instance for this Agent
     */
    public static void premain(String agentArgs, Instrumentation inst) {
        System.out.println("Agent started");
        instrumentation = inst;
    }
    
    
    public static void agentmain(String agentArgs, Instrumentation inst) {
    }
    
    /**
     * Searches the classes in the JVM for a Class with the specified name.
     * 
     * This method is different from Class.forName in that this does not silently
     * load the class, or depend on the ClassLoader. Instead, this method makes
     * use of the Instrumentation interface to get ALL loaded classes.
     * 
     * Please note that this method may take a relatively long time to complete,
     * as it may have to go over a large number of classes in the JVM.
     * 
     * @param name the name of the desired Class
     * @return the Class with the provided name, or null if it doesn't exist.
     */
    public static Class<?> findClass(String name) {
        if (instrumentation == null) {
            PGLoader.out.println("Failed to get Instrumentation");
            return null;
        }
        Class[] classes = instrumentation.getAllLoadedClasses();
        for (Class<?> c : classes) {
            if (c.getName().equals(name)) {
                return c;
            }
        }
        PGLoader.out.println("Failed to find class: " + name);
        return null;
    } 
}
