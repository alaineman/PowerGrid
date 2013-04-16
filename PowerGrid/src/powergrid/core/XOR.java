package powergrid.core;

import javax.crypto.Cipher;

/**
 * @author Paris, Chronio
 */
public final class XOR {

    private byte[] key;
    private int opmode, length;
    private int count, d;

    public XOR(byte[] key, int opmode) {
        assert key != null;
        this.key = key;
        if (opmode != Cipher.DECRYPT_MODE && opmode != Cipher.ENCRYPT_MODE) {
            throw new UnsupportedOperationException("Unsupported mode");
        }
        this.opmode = opmode;
        length = key.length;
        count = 0;
        d = 0x9e3779b9;
    }

    public void rotate(final byte[] b, final int off, final int len) {
        for (int i = off; i < off + len; i++) {
            b[i] = rotateOne(b[i]);
        }
    }

    public byte rotateOne(byte b) {
        count = (count + 1) % length;
        d += key[length - count - 1];
        if (opmode == Cipher.DECRYPT_MODE) {
            return (byte) ((b + (d & 0x7f)) % 0xff ^ key[count]);
        } else {
            return (byte) ((b ^ key[count]) - (d & 0x7f) % 0xff);
        }
    }
}
