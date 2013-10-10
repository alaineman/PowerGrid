package net.pgrid.loader.bridge.deobfucation;

import java.util.Map;
import net.pgrid.loader.Logger;

/**
 * Looks up and returns obfuscated RS Classes by their semantic name.
 * <p/>
 * This Class combines the entire Java end of the PowerGrid-Runescape bridge 
 * into a single Class, allowing JACE to request the RS Classes and provide them
 * to the C++ core as if the classes were not obfuscated. 
 * <p/>
 * @author Patrick Kramer
 */
public class RSClassProvider {
    
    private static final Object singletonLock = new Object();
    private static RSClassProvider instance = null;
    
    public static RSClassProvider create(Map<String, RSClassDescriptor> classes) {
        synchronized (singletonLock) {
            if (classes != null) {
                instance = new RSClassProvider(classes);
            } 
            return instance;
        }
    }
    
    public static RSClassProvider getInstance() {
        synchronized (singletonLock) {
            return instance;
        }
    }
    
    private static final Logger LOGGER = Logger.get("Provider");
    
    private Map<String, RSClassDescriptor> classes;
    
    public RSClassProvider(Map<String, RSClassDescriptor> classes) {
        this.classes = classes;
    }
    
    /**
     * Returns the Class with the given (semantic) name.
     * <p/>
     * If the class name does not correspond to a Runescape class, the Class object
     * with the provided name is returned, if it exists. 
     * <p/>
     * If the Class object cannot be found, this method returns null.
     * <p/>
     * @param className the (semantic) name of the desired class
     * @return the Class with the given name, or null if no such Class exists.
     */
    public Class<?> forName(String className) {
        RSClassDescriptor desc = classes.get(className);
        if (desc != null) {
            return desc.getRsClass();
        } else {
            try {
                return Class.forName(className);
            } catch (ClassNotFoundException e) {
                LOGGER.describe(e);
                return null;
            }
        }
    }
    
    public String getRealName(String semanticName) {
        RSClassDescriptor desc = classes.get(semanticName);
        if (desc != null) {
            return desc.getRsClass().getName();
        } else {
            try {
                return Class.forName(semanticName).getName();
            } catch (ClassNotFoundException e) {
                return null;
            }
        }
    }
    
    public RSClassDescriptor getDescriptor(String className) {
        if (classes.containsKey(className)) {
            return classes.get(className);
        } else {
            LOGGER.log("Missing descriptor for " + className);
            return null;
        }
    }
    
    public boolean isRSClass(String name) {
        return classes.containsKey(name);
    }
}
