package net.pgrid.loader.bridge;

import java.io.IOException;
import java.util.Collections;
import java.util.Map;

/**
 * This class reads a byte array and maps the received data.
 * <p/>
 * The data from the MapDownloader should be used to build a ClassMapper.
 * The array will be read one byte at the time and groups of bytes will form 
 * objects to store in the mapper.
 * <p/> 
 * There are three types of maps stored per ClassMapper. 
 * <ol>
 * <li>The class map; Stores the obfuscated name using the unobfuscated name as a key.</li>
 * <li>The field map; Stores the field info using the unobfuscated name as a key. </li>
 * <li>The constant map; Stores it's value using the obfuscated name as a key. </li>
 * </ol>
 * <p/>
 * @author Alaineman
 */
public class ClassMapper {

    private byte[] source;
    private Map<String, String> classMap;
    private Map<String, ObfuscatedField> fieldMap;
    private Map<String, Long> constMap;
    private short revision;
    private String gamepack;
    private int cursor;
    
    /**
     * Creates a new ClassMapper provided with a specified <code>byte</code> array.
     * <p/>
     * The cursor and revision will be set to 0 and -1 respectively upon creation.
     * <p/> 
     * @param other the specified byte array.
     */
    public ClassMapper(byte[] other) {
        if(other == null || other.length==0){
            throw new IllegalArgumentException("Found data is not suitable.");
        }
        cursor = 0;
        revision = -1;
        source = other;
    }
    
    /**
     * Returns an unmodifiable version of the Class map. 
     * @return Class map
     */
    public Map<String, String> getClassMapper() {
        return Collections.unmodifiableMap(classMap);
    }

    /**
     * Returns an unmodifiable version of the Field map.
     * @return Field map
     */
    public Map<String, ObfuscatedField> getFieldMap() {
        return Collections.unmodifiableMap(fieldMap);
    }

    /**
     * Returns an unmodifiable version of the map containing the constants.
     * @return Constant map
     */
    public Map<String, Long> getConstMap() {
        return Collections.unmodifiableMap(constMap);
    }

    /**
     * Return the gamepack string.
     * <p/>
     * This string is the unique game pack serial.
     * <p/>
     * @return unique gamepack key.
     */
    public String getGamepack() {
        return gamepack;
    }

    /**
     * Returns the revision of the byte data if it has been build.     * 
     * @return the revision number if the data is valid and the maps have 
     * been build, returns -1 otherwise.
     */
    public short getRevision() {
        return revision;
    }    

    /**
     * Converts the byte data to objects and other primitives and store those 
     * in the maps.
     * <p/> 
     * The protocol used can be found in the PowerGrid documentation.
     * <p/>
     * @throws IOException when the data is insufficient, is corrupted or 
     * unexpected tokens are found.
     */
    public void buildMaps() throws IOException {
        if (source.length < 2) {
            throw new IOException("Insufficient data found.");
        }
        revision = (short) ((source[0] << 8) + source[1]);
        cursor = 2;
        gamepack = parseString();

        while (cursor < source.length) {
            switch (source[cursor]) {
                case 0x00:
                    String obfClassName = parseString();
                    String unobfClassName = parseString();
                    classMap.put(unobfClassName, obfClassName);
                    break;
                case 0x01:
                    String obfFieldName = parseString();
                    String unobfFieldName = parseString();
                    String sign = parseString();
                    byte stat = source[cursor];
                    cursor++;
                    String owner = parseString();
                    long flag = parseLong(8);
                    fieldMap.put(unobfFieldName, new ObfuscatedField(obfFieldName, sign, stat, owner, flag));
                    break;
                case 0x02:
                    String obfConstName = parseString();
                    long value = parseLong(8);
                    constMap.put(obfConstName, value);
                    break;
                default:
                    throw new IOException("Parsing data failed - Unexpected token found.");
            }
        }
    }

    /**
     * Protected method which is used to build Strings from the byte data.
     * @return a String object
     * @throws IOException when the byte data is insufficient.
     */
    protected String parseString() throws IOException {
        int i = cursor;
        if (source.length <= i) {
            throw new IOException("Insufficient data found to parse the string.");
        }
        cursor += source[i] + 1;
        return new String(source, i + 1, source[i]);
    }

    /**
     * Protected method which is used to build Longs from the byte data.
     * @return a Long value
     * @throws IOException when the byte data is insufficient.
     */
    protected long parseLong(int length) throws IOException {
        if(source.length < cursor+7){
            throw new IOException("Insufficient data found to parse the string.");            
        }
        if(length < 0 || length>8){
            throw new IllegalArgumentException("Length out of range (0 ... 8).");
        }
        long f = 0;
        for (int i = 0; i < length; i++) {
            byte b = source[cursor];
            cursor++;
            f = f << 8;
            f |= b;
        }
        return f;
    }
}
