package powergrid.core.decoding;

import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * @author Chronio, Alaineman
 */
public class XORInputStream extends FilterInputStream {

    private byte[] key;
    private int opmode;

    public XORInputStream(InputStream in, byte[] key, int opmode) {
        super(in);
        this.key = key;
        this.opmode = opmode;
    }

    public int getOpmode() {
        return opmode;
    }

    public byte[] getKey() {
        return key;
    }
    
    private native void rotate(byte[] b, int off, int l, byte[] key, int opmode);
    
    @Override
    public synchronized int read() throws IOException {
        byte[] bs = new byte[1];
        bs[0] = (byte) super.read();
        rotate(bs, 0, 1, key, opmode);
        return bs[0];
        
    }

    @Override
    public synchronized int read(byte[] bytes, int off, int len)
            throws IOException {
        int result = super.read(bytes, off, len);
        rotate(bytes, off, len, key, opmode);
        return result;
    }
}
