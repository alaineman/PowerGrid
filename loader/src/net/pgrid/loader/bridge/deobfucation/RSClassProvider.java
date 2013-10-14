package net.pgrid.loader.bridge.deobfucation;

import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Map;
import net.pgrid.loader.AppletLoader;
import net.pgrid.loader.Logger;
import net.pgrid.loader.bridge.ClassMapDownloader;

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
    private RSClassProvider() {}
    
    private static final Logger LOGGER = Logger.get("RSClasses");
    
    private static short revision = -1;
    private static Map<String, RSClassDescriptor> descriptors = new HashMap<>(64);
    private static Map<String, Long> constants = new HashMap<>(32);
    
    public static void parseUpdateFile(byte[] input) {
        if (input == null || input.length < 2) {
            throw new IllegalArgumentException();
        }
        revision = (short) ((input[0] << 8) + (input[1] & 0xFF));
        int pos = 2, l = input.length;
        
        pos = skipString(input, pos); // gamepack
        
        ClassLoader loader = AppletLoader.getLoader().getRsClassLoader();
        String obfName, deobName;
        
        while (pos < l) {
            switch (input[pos]) {
                case 0x00:
                    // Class map
                    obfName = readString(input, pos);
                    pos += obfName.length() + 1;
                    deobName = readString(input, pos);
                    pos += deobName.length() + 1;
                    try {Class<?> rsClass = loader.loadClass(obfName);
                        descriptors.put(deobName, new RSClassDescriptor(rsClass, deobName));
                    } catch (ClassNotFoundException e) {
                        LOGGER.log("Could not find Class " + obfName + 
                                " (identified as " + deobName + ")");
                    }
                    break;
                case 0x01:
                    // Field map
                    obfName = readString(input, pos);
                    pos += obfName.length() + 1;
                    deobName = readString(input, pos);
                    pos += deobName.length() + 1;
                    // skipping the following redundant info...
                    pos = skipString(input, pos); // Signature
                    pos++; // static byte
                    String owner = readString(input, pos);
                    pos += owner.length() + 1;
                    pos += 8; // long (8 bytes)
                    
                    try {
                       Class<?> owningClass = loader.loadClass(owner);
                       Field f = owningClass.getDeclaredField(obfName);
                       RSClassDescriptor desc = lookupForClass(owningClass);
                       if (desc != null) {
                           desc.putField(deobName, f);
                       } else {
                           LOGGER.log("Missing RSClassDescriptor for Class " + owner + 
                                   ", required for field " + obfName + 
                                   " (identified as " + deobName + ")");
                       }
                    } catch (NoSuchFieldException e) {
                        LOGGER.log("Cannot find Field " + obfName + 
                                " (identified as" + deobName + 
                                ") in Class " + owner);
                    } catch (ClassNotFoundException e) {
                        LOGGER.log("Cannot find Class " + owner + 
                                ", required for field " + obfName + 
                                " (identified as " + deobName + ")");
                    }
                    break;
                case 0x02:
                    // Constant map
                    String name = readString(input, pos);
                    pos += name.length() + 1;
                    long value = readLong(input, pos);
                    pos += 8;
                    constants.put(name, value);
                    break;
                default:
                    throw new IllegalArgumentException("Unexpected token in data");
            }
        }
    }
    
    private static RSClassDescriptor lookupForClass(Class<?> rsClass) {
        for (RSClassDescriptor desc : descriptors.values()) {
            if (desc.getRsClass() == rsClass) {
                return desc;
            }
        }
        return null;
    }
    
    private static long readLong(byte[] input, int offset) {
        long result;
        result  = ((long)(input[offset  ] & 0xFF)) << 55;
        result |= ((long)(input[offset+1] & 0xFF)) << 47;
        result |= ((long)(input[offset+2] & 0xFF)) << 39;
        result |= ((long)(input[offset+3] & 0xFF)) << 31;
        result |= ((long)(input[offset+4] & 0xFF)) << 23;
        result |= ((long)(input[offset+5] & 0xFF)) << 15;
        result |= ((long)(input[offset+6] & 0xFF)) << 7;
        result |= input[offset+7] & 0xFF;
        return result;
    }
    
    private static String readString(byte[] input, int offset) {
        int length = input[offset] & 0xFF;
        return new String(input, offset + 1, offset + length + 1, 
                ClassMapDownloader.CHARSET);
    }
    
    private static int skipString(byte[] input, int offset) {
        return offset + (input[offset] & 0xFF) + 1;
    }
    
    public static short revision() {
        return revision;
    }
    
    public static RSClassDescriptor findClassDescriptor(String name) {
        return descriptors.get(name);
    }
    
    
}
