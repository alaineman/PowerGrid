package powergrid.core;

/**
 * Fast version of a ByteArrayOutputStream that prevents unnecessary copying.
 * <p/>
 * Writing the entire contents of an InputStream to a byte array using this 
 * class will only copy the entire contents once, while using a 
 * ByteArrayOutputStream will copy the contents three times when using an 
 * intermediate buffer.
 * <p/>
 * @author Chronio
 */
public class ByteArrayBuilder {
    
    private byte[] buf;
    private boolean done = false;
    
    public ByteArrayBuilder(int capacity) {
        buf = new byte[capacity];
    }
    
    public byte[] get() {
        if (!done) {
            done = true;
            return buf;
        }
        return null;
    }
    
    
}
