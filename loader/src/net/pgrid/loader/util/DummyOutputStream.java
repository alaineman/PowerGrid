package net.pgrid.loader.util;

import java.io.OutputStream;

/**
 * An OutputStream object that does absolutely nothing.
 * @author Patrick Kramer
 */
public class DummyOutputStream extends OutputStream {
    @Override
    public void write(int i) {
        
    }
}
