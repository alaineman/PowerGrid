package net.pgrid.loader.bridge;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.Objects;
import net.pgrid.loader.Logger;

/**
 * This class is the representation of a field object.
 * <p/>
 * Since a map store a key and a value the value has to be an object in order 
 * to store multiple values. Hence, ObfuscatedField provides us with 
 * the information we need to know about a field.  
 * Please check the getters to find the stores values.
 * <p/>
 * @param <T> the type of the Field
 * @author Alaineman
 */
public class ObfuscatedField<T> {
    
    private static final Logger LOGGER = Logger.get("UPDATER");
    
    private Class<? extends T> type;
    private Field reference;
    private String semanticName;
    private long multiplier;

    @SuppressWarnings("unchecked")
    public ObfuscatedField(Field reference, String semanticName, long multiplier) {
        assert reference != null && type != null && semanticName != null && !semanticName.isEmpty();
        this.type = (Class<? extends T>) reference.getType();
        this.reference = reference;
        this.semanticName = semanticName;
        this.multiplier = multiplier;
    }
    
    public ObfuscatedField(ObfuscatedFieldData data) throws ClassNotFoundException, NoSuchFieldException {
        assert data != null;
        this.semanticName = data.getSemanticName();
        reference = collectReference(data.getClassName(), data.getFieldName());
    }
    
    private Field collectReference(String className, String fieldName) 
            throws ClassNotFoundException, NoSuchFieldException {
        return Class.forName(className).getDeclaredField(fieldName);
    }
    
    public Class<? extends T> getType() {
        return type;
    }

    /**
     * @return the de-obfuscated, semantic name.
     */
    public String getSemanticName() {
        return semanticName;
    }  

    /**
     * @return the Field reference that this ObfuscatedField Object represents.
     */
    public Field getField() {
        return reference;
    }
    
    /**
     * @return whether or not the field is static.
     */
    public boolean isStatic() {
        return Modifier.isStatic(getField().getModifiers());
    }
    
    /**
     * Retrieves and returns the value of this Field from the given Object.
     * @param from the Object to get the Field content for
     * @return the value of the Field from the given Object
     * 
     * @throws IllegalArgumentException when the provided Object cannot be cast to the
     *                                  required type.
     * 
     */
    public T get(Object from) {
        if (isStatic()) {
            return getStatic();
        } else {
            try {
                reference.setAccessible(true);
                T value = type.cast(reference.get(from));
                return value;
            } catch (IllegalAccessException e) {
                LOGGER.describe(e);
                throw new InternalError("Failed to disable accessiblity checking");
            } finally {
                reference.setAccessible(false);
            }
        }
    }
    
    /**
     * Retrieves and returns the value of this Field.
     * <p/>
     * The Field has to be static in order for this method to function correctly.
     * If the Field is not static, an UnsupportedOperationException is thrown.
     * <p/>
     * @return the value of this static Field
     * 
     * @throws UnsupportedOperationException when this Field is not static
     */
    public T getStatic() {
        try {
            reference.setAccessible(true);
            T value = type.cast(reference.get(null));
            return value;
        } catch (IllegalAccessException e) {
            LOGGER.describe(e);
            throw new InternalError("Failed to disable accessiblity checking");
        } catch (IllegalArgumentException e) {
            throw new UnsupportedOperationException("This Field is not static", e);
        } finally {
            reference.setAccessible(false);
        }
    }

    /**
     * @return the multiplier of the field.
     */
    public long getMultiplier() {
        return multiplier;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 19 * hash + Objects.hashCode(semanticName);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        // the '==' operator can be used here since each Java language component 
        // has exactly one java.reflect meta-object referencing it.
        if (obj != null && getClass() == obj.getClass()) {
            return getField().equals(((ObfuscatedField)obj).getField());
        }
        return false;
    }

    @Override
    public String toString() {
        return "ObfuscatedField(" + getField().getDeclaringClass().getName() 
                + "." + getField().getName() + " => " + getSemanticName() + ")";
    }
}
