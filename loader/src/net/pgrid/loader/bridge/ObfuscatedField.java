package net.pgrid.loader.bridge;

import java.util.Objects;

/**
 * This class is the representation of a field object.
 * <p/>
 * Since a map store a key and a value the value has to be an object in order 
 * to store multiple values. Hence, ObfuscatedField provides us with 
 * the information we need to know about a field.  
 * Please check the getters to find the stores values.
 * <p/>
 * @author Alaineman
 */
public class ObfuscatedField {
    
    private String realName;
    private String signature;
    private boolean staticStatus;
    private String owner;
    private long flags;
    
    public ObfuscatedField(String name,String sign,byte state,String parent,long flagInfo){
        if(name==null || sign==null || parent==null){
            throw new IllegalArgumentException("Invalid strings found.");
        }
        realName = name;
        signature = sign;
        staticStatus = state==1;
        owner = parent;
        flags = flagInfo;
    }

    /**
     * 
     * @return the unobfuscated name.
     */
    public String getRealName() {
        return realName;
    }  

    /**
     * 
     * @return whether or not the field is static.
     */
    public boolean isStatic() {
        return staticStatus;
    }   

    /**
     * 
     * @return the name of the owner.
     */
    public String getOwner() {
        return owner;
    }

    /**
     * 
     * @return the signature flags.
     */
    public String getSignature(){
        return signature;
    }            
    
    /**
     * 
     * @return the multiplier of the field.
     */
    public long getFlags() {
        return flags;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 19 * hash + Objects.hashCode(this.realName);
        hash = 19 * hash + Objects.hashCode(this.owner);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final ObfuscatedField other = (ObfuscatedField) obj;
        if (!Objects.equals(this.realName, other.realName)) {
            return false;
        }
        if (!Objects.equals(this.owner, other.owner)) {
            return false;
        }
        return true;
    }
    
    
}
