/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package net.pgrid.loader.bridge;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Vincent W
 */
public class RSAccessor {    
            
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
    
    public byte getByteField(){        
        
        try {
            Class<?> forName;
            forName = Class.forName("");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(RSAccessor.class.getName()).log(Level.SEVERE, null, ex);
        }
        return 0;
        
    }
    
    public short getShortField(){
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
