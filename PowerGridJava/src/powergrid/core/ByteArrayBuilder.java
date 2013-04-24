package powergrid.core;

import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Formatter;

/**
 * Fast version of a ByteArrayOutputStream that prevents unnecessary copying.
 * <p/>
 * Writing the entire contents of an InputStream to a byte array using this 
 * class will only copy the entire contents once, while using a 
 * ByteArrayOutputStream will copy the contents three times when using an 
 * intermediate buffer. Therefore this implementation is faster in most cases.
 * <p/>
 * @author Chronio
 */
public class ByteArrayBuilder {
    
    private byte[] buf;
    private int count;
    
    /**
     * Creates a new ByteArrayBuilder with the given initial capacity.
     * @param capacity the initial capacity, should not be negative.
     */
    public ByteArrayBuilder(int capacity) {
        assert capacity >= 0;
        buf = new byte[capacity];
        count = 0;
    }
    
    /**
     * Clears the ByteArrayBuilder and creates a new buffer with the specified 
     * initial capacity.
     * @param capacity the capacity for the new buffer
     */
    public synchronized void reset(int capacity) {
        assert capacity >= 0;
        buf = new byte[capacity];
        count = 0;
    }
    
    /**
     * Returns the contents of the buffer without copying the buffer. 
     * <p/>
     * The buffer is then set to null to prevent external modification.
     * <p/>
     * This means the {@code reset(int)} method must be called before the 
     * ByteArrayBuilder can be used again.
     * <p/>
     * Note that the contents of the buffer are not trimmed, but the length of 
     * the read data can be retrieved using {@code getCount()}.
     * @return this ByteArrayBuilder's buffer.
     */
    public synchronized byte[] get() {
        byte[] res = buf;
        buf = null;
        return res;
    }
    
    /**
     * returns copy of the ByteArrayBuilder's buffer with the correct size.
     * <p/>
     * Note that this requires the array to be copied, negatively affecting 
     * performance. The buffer is left as is when calling this method, so
     * the contents of the buffer are still present within this ByteArrayBuilder.
     * @return a trimmed copy of the buffer
     */
    public synchronized byte[] getTrimmed() {
        return Arrays.copyOf(buf, count);
    }
    
    /**
     * Returns a PaddedArray instance of the buffer of this ByteArrayBuilder.
     * <p/>
     * Since this invalidates the constraint that the buffer should be private, 
     * the buffer is set to null when this method is called, similar to the 
     * {@code get()} method.
     * @return a PaddedArray containing the buffer of this ByteArayBuilder
     */
    public synchronized PaddedArray getPaddedArray() {
        return new PaddedArray(get(), 0, getCount());
    }
    
    /**
     * Returns the amount of bytes that was read with this ByteArrayBuilder.
     * @return the size of this ByteArrayBuilder's buffer
     */
    public int getCount() {
        return count;
    }
    
    /**
     * Loads all bytes in the given InputStream in this ByteArrayBuilder.
     * @param in the InputStream to read
     * @return the amount of bytes read.
     * @throws IOException when reading the InputStream failed. 
     * @throws IllegalStateException when the buffer is not initialized.
     */
    public synchronized int load(InputStream in) throws IOException {
        if (buf == null) {
            throw new IllegalStateException("Not initialized; needs resetting");
        }
        int n = 0;
        int available = in.available();
        while (available > 0) {
            if (buf.length - count - available < 0) {
                ensureCapacity(Math.max(2 * buf.length, count + available + 4));
            }
            n += in.read(buf, count, available);
            available = in.available();
        }
        count += n;
        return n;
    }
    
    /**
     * Copies the contents of the given byte array into this ByteArrayBuilder.
     * @param bytes the byte array to copy
     * @return the amount of bytes copied, equal to {@code bytes.length}
     * @throws IllegalStateException when the buffer is not initialized.
     */
    public synchronized int load(byte[] bytes) {
        if (buf == null) {
            throw new IllegalStateException("Not initialized; needs resetting");
        }
        if (buf.length - count - bytes.length < 0) {
            ensureCapacity(Math.max(2 * buf.length, count + bytes.length + 4));
        }
        System.arraycopy(bytes, 0, buf, count, bytes.length);
        count += bytes.length;
        return bytes.length;
    }
    
    /**
     * Resizes the byte array to the desired capacity if and only if the 
     * desired capacity is higher than the current capacity.
     * <p/>
     * Note that this operation takes {@code O(n)} time.
     * <p/>
     * If the buffer is null, a new byte array with the desired size is created
     * to be used as buffer.
     * 
     * @param n the desired capacity.
     */
    public synchronized void ensureCapacity(int n) {
        if (buf == null) {
            buf = new byte[n];
        } else if (n > buf.length) {
            buf = Arrays.copyOf(buf, n);
        }
    }
    
    @Override public synchronized String toString() {
        StringBuilder res = new StringBuilder(20 + 3 * getCount());
        res.append("ByteArrayBuilder(");
        if (buf != null) {
            Formatter formatter = new Formatter(res);
            for (byte b : buf) {
                res.append(" ");
                formatter.format("%02X", b);
            }
        }
        return res.append(")").toString();
    }
}
