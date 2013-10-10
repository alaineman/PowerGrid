package net.pgrid.loader.bridge.deobfucation;

import java.util.Collections;
import java.util.Map;

/**
 *
 * @author Patrick Kramer
 */
public class RSClassDescriptor {
    
    private Class<?> rsClass;
    private String className;
    private Map<String, String> methods;
    private Map<String, String> parameters;
    private Map<String, Long> constants;

    public RSClassDescriptor(Class<?> clazz, String name, 
            Map<String, String> methods, Map<String, String> parameters,
            Map<String, Long> constants) {
        this.rsClass    = clazz;
        this.className  = name;
        this.methods    = Collections.unmodifiableMap(methods);
        this.parameters = Collections.unmodifiableMap(parameters);
        this.constants  = Collections.unmodifiableMap(constants);
    }

    public String getClassName() {
        return className;
    }

    public Class<?> getRsClass() {
        return rsClass;
    }

    public Map<String, String> getMethods() {
        return methods;
    }

    public Map<String, String> getParameters() {
        return parameters;
    }

    public Map<String, Long> getConstants() {
        return constants;
    }
    
    public long getConstant(String name) {
        return constants.get(name);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null && obj.getClass() == getClass()) {
            RSClassDescriptor that = (RSClassDescriptor) obj;
            return this.getRsClass() == that.getRsClass();
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 37 * hash + rsClass.hashCode();
        return hash;
    }
    
    
}
