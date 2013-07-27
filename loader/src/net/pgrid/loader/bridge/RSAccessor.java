package net.pgrid.loader.bridge;

import net.pgrid.loader.Logger;


/**
 * The bridge core used to aid the JNI porting and reduce the load between java 
 * and c++.
 * @author Vincent W
 */
public class RSAccessor {
    
    private static final Logger LOGGER = Logger.get("BRIDGE");
    
    private ClassMapper map;
    
    public RSAccessor (ClassMapper mapData) {
        assert mapData != null;
        map = mapData;
    }
    
    public Class<?> getClassByID(int id) {
        return null;
    }
    
    public ObfuscatedField<?> getFieldByID(int classID, int fieldID) {
        return null;
    }
    
//    public XXX getXXXField(Object o, int classID, int fieldID) {
//    get class with classID
//    if null: look up classID in map data
//    if not o instanceof class throw Exception();
//
//  get field with fieldID
//  if null: look up fieldID in map data
//  
//   get field data from field using Object o
//  return field data    
    
    public byte getByteField(String name){        
        
        try {
            Class<?> forName = Class.forName("");
        } catch (ClassNotFoundException ex) {
            LOGGER.describe(ex);
        }
        return 0;
        
    }
    
    public short getShortField(Object o, int classID, int fieldID) {
        Class<?> c = getClassByID(classID);
        if (c == null) {
            throw new RuntimeException("No such Class");
        }
        if (!c.isInstance(o)) {
            throw new RuntimeException("Invalid Object");
        }
        return 0;
    }
    
    public int getIntegerField(){
        return 0;
        
    }
    
    public double getDoubleField(){
        return 0;
                
    }
    
    public double getFloatField(){
        return 0;
        
    }
    
    public double getLongField(){
        return 0;
        
    }
    
    public char getCharField(){
        return 0;
        
    }
    
    public boolean getBooleanField(){
        return false;
        
    }
    
    public Object getObjectField(){
        return null;
        
    }    
    
    //Static equivalents
    
    public byte getStaticByteField(){
        return 0;
        
    }
    
    public short getStaticShortField(){
        return 0;
        
    }
    
    public int getStaticIntegerField(){
        return 0;
        
    }
    
    public double getStaticDoubleField(){
        return 0;
                
    }
    
    public double getStaticFloatField(){
        return 0;
        
    }
    
    public double getStaticLongField(){
        return 0;
        
    }
    
    public char getStaticCharField(){
        return 0;
        
    }
    
    public boolean getStaticBooleanField(){
        return false;
        
    }
    
    public Object getStaticObjectField(){
        return null;
        
    } 
          
}
