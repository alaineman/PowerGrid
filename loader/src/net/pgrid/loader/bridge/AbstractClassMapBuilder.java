package net.pgrid.loader.bridge;

import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Map;
import net.pgrid.loader.bridge.deobfucation.RSClassDescriptor;

/**
 * Abstract class to construct a ClassMapBuilder.
 * 
 * The exact format of the source is unspecified, the Charset of the source should
 * be provided to prevent parse issues due to the text encoding.
 * @author Patrick Kramer
 */
public abstract class AbstractClassMapBuilder {
    
    private final byte[] source;
    private final Charset encoding;
    
    private int position = 0;

    /**
     * Creates a new AbstractClassMapBuilder to parse the given byte array.
     * 
     * The provided Charset will be used as encoding to read Strings from the 
     * source byte array
     * @param source the byte array to parse from
     * @param encoding the encoding of the String data in the byte array
     */
    public AbstractClassMapBuilder(byte[] source, Charset encoding) {
        this.source = Arrays.copyOf(source, source.length);
        this.encoding = encoding;
    }
    
    /**
     * Parses the source byte array.
     * @return a Map from class name to RSClassDescriptor object containing the 
     *         data.
     */
    public abstract Map<String, RSClassDescriptor> parse();
    
    /**
     * @return the encoding used for decoding the String values in the source
     */
    public Charset getEncoding() {
        return encoding;
    }

    /**
     * @return the position in the source file in bytes.
     */
    public synchronized int getPosition() {
        return position;
    }
    
    /**
     * @return the length of the source in bytes.
     */
    public int getSourceLength() {
        return source.length;
    }
    
    /**
     * Asserts that the requested number of bytes are available.
     * @param numBytes the requested amount of bytes
     * @throws IllegalArgumentException when not enough bytes are available.
     */
    protected synchronized void assertAvailable(int numBytes) {
        if (source.length - position < numBytes) {
            throw new IllegalArgumentException("Insufficient amount of bytes");
        }
    }
    
    /**
     * Returns the next byte in the source, or throws an 
     * IllegalArgumentException when no bytes are left to read
     * @return the next byte
     * @throws IllegalArgumentException when no bytes are left to read
     */
    protected synchronized byte nextByte() {
        assertAvailable(1);
        return source[position++];
    }
    
    /**
     * Reads the next String from the source array according to this 
     * {@code AbstractClassMapBuilder}'s encoding.
     * 
     * This implementation reads Strings with the format:
     * <pre><code>
     *      [len][data*]
     * </code></pre>
     * where {@literal [len]} is a single byte containing the length of the 
     * String (in bytes), and {@literal [data*]} is the next {@literal len} 
     * bytes representing the actual String.
     * 
     * This method can be overridden to read differently formatted Strings.
     * 
     * @return the next String in the source array
     * @throws IllegalArgumentException when not enough bytes are available in 
     *         the source array
     */
    protected synchronized String nextString() {
        int length = nextByte() & 0xFF; // we want the byte explicitly unsigned
        assertAvailable(length);
        return new String(source, position, length, encoding);
    }
}
