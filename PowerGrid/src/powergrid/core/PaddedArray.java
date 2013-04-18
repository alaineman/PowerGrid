package powergrid.core;

import java.lang.reflect.Array;

/**
 * Represents an array of which it is known that the array contains additional
 * padding.
 * <p/>
 * Wrapping the array in an instance of this class prevents the need to copy 
 * the array to an array of the correct size, and as such may give a reasonably
 * large performance increase for large arrays.
 * 
 * @param <T> the type of this sub array
 * @author Chronio
 */
public class PaddedArray<T> {
    
    private T[] arr;
    private int off;
    private int len;
    
    /**
     * Creates a new PaddedArray with the given array. The offset is set to 0,
     * and the length is set to the length of the array. This allows non-padded 
     * arrays to be used alongside padded arrays without needing special 
     * treatment.
     * @param arr the array this PaddedArray references
     */
    public PaddedArray(T[] arr) {
        assert arr != null;
        this.arr = arr;
        this.off = 0;
        this.len = arr.length;
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
    public PaddedArray(T[] arr, int off, int len) {
        assert arr != null && off >= 0 && len >= 0 
                && off + len - arr.length < 0;
        this.arr = arr;
        this.off = off;
        this.len = len;
    }
    
    public T[] getArray() {
        return arr;
    }
    
    public int size() {
        return len;
    }
    
    public int getArrayLength() {
        return getArray().length;
    }
    
    public int getOffset() {
        return off;
    }
    
    public T[] getTrimmedCopy() {
        @SuppressWarnings("unchecked") // since we know it's going to be that type
        T[] copy = (T[]) Array.newInstance(arr.getClass().getComponentType(), len);
        System.arraycopy(arr, off, copy, 0, len);
        return copy;
    }
}
