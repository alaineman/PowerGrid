package powergrid.core;

import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * @author Paris, Chronio
 */
public class XORInputStream extends FilterInputStream {

    private XOR xor;

    public XORInputStream(InputStream in, byte[] key, int opmode) {
        super(in);
        xor = new XOR(key, opmode);
    }

    @Override
    public synchronized int read() throws IOException {
        return xor.rotateOne((byte) super.read()) & 0xff;
    }

    @Override
    public synchronized int read(byte[] bytes, int off, int len)
            throws IOException {
        int result = super.read(bytes, off, len);
        xor.rotate(bytes, off, len);
        return result;
    }
}
