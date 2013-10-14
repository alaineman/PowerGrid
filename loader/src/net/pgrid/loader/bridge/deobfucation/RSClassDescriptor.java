package net.pgrid.loader.bridge.deobfucation;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Patrick Kramer
 */
public class RSClassDescriptor {
    
    private Class<?> rsClass;
    private String className;
    private Map<String, Field> fields;

    public RSClassDescriptor(Class<?> clazz, String name) {
        this.rsClass    = clazz;
        this.className  = name;
        this.fields     = new HashMap<>(16);
    }

    public String getClassName() {
        return className;
    }

    public Class<?> getRsClass() {
        return rsClass;
    }

    public Map<String, Field> getFields() {
        return fields;
    }
    
    public void putField(String name, Field f) {
        fields.put(name, f);
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
