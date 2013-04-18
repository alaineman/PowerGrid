package powergrid.core.decoding;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.Map;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;
import powergrid.core.ByteArrayBuilder;
import powergrid.core.PaddedArray;

/**
 * Splits the contents of a byte array that represents a jar file in its 
 * individual classes, and produces a mapping from Class name to the contents
 * of that particular Class.
 * <p/>
 * @author Chronio
 */
public class JarExtractor {
    
    public static final int INNER_PACK_SIZE = 2048;
    
    private byte[] source;
    private Map<String, byte[]> decoded;
    
    public JarExtractor(byte[] source) {
        assert source != null;
        this.source = source;
        this.decoded = null;
    }
    
    /**
     * Returns the raw non decoded byte array that was provided to this 
     * JarExtractor.
     * @return the raw source
     */
    public byte[] getRawSource() {
        return source;
    }
    
    /**
     * Decodes, splits and returns the byte array in this JarExtractor. 
     * @param secretKey the secret key belonging to the byte array
     * @param ivParamKey the ivParam key belonging to the byte array
     * @return the decoded mapping from class name to class source
     * @throws IOException when the decoding failed. 
     */
    public Map<String, byte[]> getDecoded(String secretKey, String ivParamKey) throws IOException {
        if (decoded == null) {
            JarInputStream jarIn = new JarInputStream(
                    new ByteArrayInputStream(getRawSource()));
            PaddedArray inner_pack = null;
            for (JarEntry entry = jarIn.getNextJarEntry(); entry != null; 
                    entry = jarIn.getNextJarEntry()) {
                if (entry.getName().equals("inner.pack.gz")) {
                    ByteArrayBuilder bab = new ByteArrayBuilder(INNER_PACK_SIZE);
                    bab.load(jarIn);
                    inner_pack = bab.getPaddedArray();
                }
            }
            if (inner_pack != null) {
                
            }
        }
        return decoded;
    }
    
}
