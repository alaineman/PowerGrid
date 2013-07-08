package net.pgrid.loader.bridge;

import java.io.IOException;
import java.util.Collections;
import java.util.Map;

/**
 *
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
        
    public ClassMapper(byte[] other) {
        if(other == null || other.length==0){
            throw new IllegalArgumentException("Found data is not suitable.");
        }
        cursor = 0;
        revision = 0;
        source = other;
    }
    
    public Map<String, String> getClassMapper() {
        return Collections.unmodifiableMap(classMap);
    }

    public Map<String, ObfuscatedField> getFieldMap() {
        return Collections.unmodifiableMap(fieldMap);
    }

    public Map<String, Long> getConstMap() {
        return Collections.unmodifiableMap(constMap);
    }

    public String getGamepack() {
        return gamepack;
    }

    public short getReversion() {
        return revision;
    }    

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

    protected String parseString() throws IOException {
        int i = cursor;
        if (source.length <= i) {
            throw new IOException("Insufficient data found to parse the string.");
        }
        cursor += source[i] + 1;
        return new String(source, i + 1, source[i]);
    }

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
