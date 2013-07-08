package net.pgrid.loader;

/**
 *
 * @author Alaineman
 */
public class ObfuscatedField {
    
    String obfuscatedName;
    String signature;
    byte staticStatus;
    String owner;
    long multiplier;
    
    public ObfuscatedField(String name,String sign,byte state,String parent,long flagInfo){
        obfuscatedName = name;
        signature = sign;
        owner = parent;
        multiplier = flagInfo;
    }

    public String getRealName() {
        return obfuscatedName;
    }

    public void setRealName(String realName) {
        this.obfuscatedName = realName;
    }

    public String getSignature() {
        return signature;
    }

    public void setSignature(String signature) {
        this.signature = signature;
    }

    public byte getStaticStatus() {
        return staticStatus;
    }

    public void setStaticStatus(byte staticStatus) {
        this.staticStatus = staticStatus;
    }

    public String getOwner() {
        return owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public long getFlags() {
        return multiplier;
    }

    public void setFlags(long flags) {
        this.multiplier = flags;
    }    
    
}
