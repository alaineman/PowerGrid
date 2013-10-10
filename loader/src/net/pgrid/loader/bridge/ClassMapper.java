/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 * 
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
package net.pgrid.loader.bridge;

import java.io.IOException;
import java.util.Collections;
import java.util.Map;
import net.pgrid.loader.Logger;

/**
 * This class reads a byte array and maps the received data.
 * <p/>
 * The data from the MapDownloader should be used to build a ClassMapper.
 * The array will be read one byte at the time and groups of bytes will form 
 * objects to store in the mapper.
 * <p/> 
 * There are three types of maps stored per ClassMapper. 
 * <ul>
 * <li>The class map; Stores the obfuscated name using the de-obfuscated name as a key.</li>
 * <li>The field map; Stores the field info using the de-obfuscated name as a key. </li>
 * <li>The constant map; Stores its value using the obfuscated name as a key. </li>
 * </ul>
 * <p/>
 * @author Alaineman
 */
public class ClassMapper {

    private static final Logger LOGGER = Logger.get("UPDATER");
    
    private byte[] source;
    private Map<String, String> classes;
    private Map<String, Object> fieldData;
    private Map<String, Object> fields;
    private Map<String, Long> constants;
    
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
        return Collections.unmodifiableMap(classes);
    }

    /**
     * Returns an unmodifiable version of the Field map.
     * @return Field map
     */
    public Map<String, Object> getFieldMap() {
        return Collections.unmodifiableMap(fields);
    }

    /**
     * Returns an unmodifiable version of the map containing the constants.
     * @return Constant map
     */
    public Map<String, Long> getConstMap() {
        return Collections.unmodifiableMap(constants);
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
        revision = (short) ((source[0] << 8) + (source[1] & 0xff));
        cursor = 2;
        gamepack = parseString();

        while (cursor < source.length) {
            switch (source[cursor]) {
                case 0x00:
                    String obfClassName = parseString();
                    String unobfClassName = parseString();
                    classes.put(unobfClassName, obfClassName);
                    break;
                case 0x01:
                    String obfFieldName = parseString();
                    String unobfFieldName = parseString();
                    String sign = parseString();
                    byte stat = source[cursor];
                    cursor++;
                    String owner = parseString();
                    long flag = parseLong(8);
                    Object data = new Object();
                    //try {
                        fields.put(unobfFieldName, new Object());
                    //} catch (ClassNotFoundException | NoSuchFieldException e) {
                    //    LOGGER.describe(e);
                    //}
                    break;
                case 0x02:
                    String obfConstName = parseString();
                    long value = parseLong(8);
                    constants.put(obfConstName, value);
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
     * @param length 
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
            f <<= 8;
            f |= (b & 0xff);
        }
        return f;
    }
}
