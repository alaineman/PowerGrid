package net.pgrid.loader.bridge;

import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Map;
import net.pgrid.loader.bridge.deobfucation.RSClassDescriptor;

/**
 *
 * @author Patrick Kramer
 */
public abstract class AbstractClassMapBuilder {
    
    private byte[] source;
    private Charset encoding;
    
    private int position = 0;

    public AbstractClassMapBuilder(byte[] source, Charset encoding) {
        this.source = Arrays.copyOf(source, source.length);
        this.encoding = encoding;
    }
    
    public abstract Map<String, RSClassDescriptor> parse();
    
    public Charset getEncoding() {
        return encoding;
    }

    public synchronized int getPosition() {
        return position;
    }
    
    public int getSourceLength() {
        return source.length;
    }
    
    private void assertAvailable(int numBytes) {
        if (source.length - position < numBytes) {
            throw new IllegalStateException("Insufficient amount of bytes");
        }
    }
    
    public synchronized byte nextByte() {
        assertAvailable(1);
        return source[position++];
    }
    
    public synchronized String nextString() {
        byte length = nextByte();
        return null;
    }
}
