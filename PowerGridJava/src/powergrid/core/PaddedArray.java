package powergrid.core;

import java.lang.reflect.Array;

/**
 * Represents an array of which it is known that the array contains additional
 * padding.
 * <p/>
 * Wrapping the array in an instance of this class prevents the need to copy 
 * the array to an array of the correct size, and as such may give a reasonably
 * large performance increase for large arrays.
 * <p/>
 * Type safety cannot be guaranteed when using this class. It's the 
 * responsibility of the developer to ensure that array is casted to the 
 * correct type. This decision was made in favor of performance over safety.
 * <p/>
 * @author Chronio
 */
public class PaddedArray {
    
    private Object arr;
    private int off;
    private int len;
    
    /**
     * Creates a new PaddedArray with the given array. The offset is set to 0,
     * and the length is set to the length of the array. This allows non-padded 
     * arrays to be used alongside padded arrays without needing special 
     * treatment.
     * @param arr the array this PaddedArray references
     */
    public PaddedArray(Object arr) {
        assert arr != null;
        this.arr = arr;
        this.off = 0;
        this.len = Array.getLength(arr);
    }
    
    /**
     * Creates a new PaddedArray using the given array, and the specified offset 
     * and length.
     * <p/>
     * the array should not be null and the offset and length should not be 
     * negative. Also, {@code len + off} should not be larger than 
     * {@code arr.length}.
     * @param arr the array this PaddedArray references
     * @param off the offset of the array
     * @param len the unpadded length of the array
     */
    public PaddedArray(Object arr, int off, int len) {
        assert arr != null && off >= 0 && len >= 0 
                && off + len - Array.getLength(arr) < 0;
        this.arr = arr;
        this.off = off;
        this.len = len;
    }
    
    public Object getArray() {
        return arr;
    }
    
    public int size() {
        return len;
    }
    
    public int getArrayLength() {
        return Array.getLength(arr);
    }
    
    public int getOffset() {
        return off;
    }
    
    public Object getTrimmedCopy() {
        @SuppressWarnings("unchecked") // since we know it's going to be that type
        Object copy = Array.newInstance(arr.getClass().getComponentType(), len);
        // Even though arr and copy are technically not array types, this class
        // assumes they are, and so the invocation of System.arraycopy is 
        // perfectly valid here.
        System.arraycopy(arr, off, copy, 0, len);
        return copy;
    }
}
