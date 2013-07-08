package net.pgrid.loader.bridge;

import java.util.Objects;

/**
 *
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

    public String getRealName() {
        return realName;
    }  

    public boolean isStatic() {
        return staticStatus;
    }   

    public String getOwner() {
        return owner;
    }

    public String getSignature(){
        return signature;
    }            
    
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
