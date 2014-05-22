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

import java.lang.instrument.Instrumentation;

/**
 * Agent class to get a JVM Instrumentation instance.
 * 
 * This allows us to inspect / monitor the JVM and RS client at runtime. This 
 * mainly provides access to the classes of the running RS client, without 
 * needing to worry about getting the ClassLoaders right and such. The Agent 
 * is capable of getting any loaded Class in the JVM by name regardless of the 
 * ClassLoader used to load that Class.
 * 
 * It also holds an Instrumentation object, which provides precise, low-level 
 * control over all classes in the JVM (such as applying Class transformations, 
 * or getting the size of an Object instance (in bytes).
 * 
 * @see java.lang.instrument.Instrumentation
 * 
 * @author Patrick Kramer
 */
public class Agent {
    
    private static Instrumentation instrumentation;
    
    /**
     * Prevent instantiation of this JVM agent (utility) class.
     */
    private Agent() {}
    
    /**
     * @return the Instrumentation instance assigned to the Agent.
     */
    public static Instrumentation getInstrumentation() {
        return instrumentation;
    }
    
    /**
     * Called by the JVM when the Agent is loaded (before main is invoked).
     * 
     * @param agentArgs the arguments for the Agent (ignored)
     * @param inst the Instrumentation instance for the Agent
     * @internal Note that you cannot use the agent from within an IDE. In fact,
     *           the agent needs to be set when the JVM is started. The native
     *           client does this automatically, making this construction work 
     *           when running PowerGrid normally (through the native C++ client).
     */
    public static void premain(String agentArgs, Instrumentation inst) {
        System.out.println("AGENT        | Agent started");
        instrumentation = inst;
    }
    
    /**
     * The agent's main method. 
     * 
     * Since our Agent performs its initialization in {@code premain}, and does 
     * not need to perform any additional actions, this method does nothing.
     * 
     * 
     * @param agentArgs the arguments for the Agent (ignored)
     * @param inst the Instrumentation instance for the Agent.
     */
    public static void agentmain(String agentArgs, Instrumentation inst) {
    }
    
    /**
     * Searches the classes in the JVM for a Class with the specified name.
     * 
     * This method is different from Class.forName in that this does not 
     * silently load the class, or depend on the ClassLoader. Instead, this 
     * method makes use of the Instrumentation interface to get ALL loaded 
     * classes.
     * 
     * Please note that this method may take a relatively long time to complete,
     * as it may have to go over a large number of classes in the JVM.
     * 
     * @param name the name of the desired Class
     * @return the Class with the provided name, or null if it doesn't exist.
     */
    public static Class<?> findClass(String name) {
        if (instrumentation == null) {
            throw new IllegalStateException("The Agent was not started");
        }
        Class<?>[] classes = instrumentation.getAllLoadedClasses();
        for (Class<?> c : classes) {
            if (c.getName().equals(name)) {
                return c;
            }
        }
        PGLoader.out.println("AGENT        | Failed to find class: " + name);
        return null;
    } 
}
