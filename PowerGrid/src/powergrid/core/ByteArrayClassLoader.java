package powergrid.core;

import java.awt.AWTPermission;
import java.io.File;
import java.io.FilePermission;
import java.net.SocketPermission;
import java.net.URL;
import java.security.CodeSigner;
import java.security.CodeSource;
import java.security.Permissions;
import java.security.ProtectionDomain;
import java.util.PropertyPermission;

/**
 * Loads classes from the given ByteArray.
 * @author Chronio
 */
public class ByteArrayClassLoader extends ClassLoader {
    
    private byte[] source;
    private ProtectionDomain domain;
    
    /**
     * Creates a new ByteArrayClassLoader that loads from the given byte array 
     * and uses the given URL as base for the ProtectionDomain. 
     * <p/>
     * The ProtectionDomain ensures that the permissions that the classes 
     * loaded in this ClassLoader have the permissions that are required for 
     * correctly loading and setting up Runescape related classes.
     * 
     * @param source the byte array to load from
     * @param url the URL to use for the ProtectionDomain
     */
    public ByteArrayClassLoader(byte[] source, URL url) {
        assert source != null && url != null;
        this.source = source;
        this.domain = new ProtectionDomain(
                new CodeSource(url, (CodeSigner[]) null), 
                createPermissions());
    }
    
    /**
     * Creates the Permission required to be able to set up the 
     * ProtectionDomain correctly.
     * @return the Permissions required for the ProtectionDomain
     */
    private Permissions createPermissions() {
        Permissions perms = new Permissions();
        // basic JVM permissions
        perms.add(new AWTPermission("accessEventQueue"));
        perms.add(new PropertyPermission("user.home", "read"));
        perms.add(new PropertyPermission("java.vendor", "read"));
        perms.add(new PropertyPermission("java.version", "read"));
        perms.add(new PropertyPermission("os.name", "read"));
        perms.add(new PropertyPermission("os.arch", "read"));
        perms.add(new PropertyPermission("os.version", "read"));
        perms.add(new SocketPermission("*", "connect,resolve"));
        
        // File permissions (read or read/write)
        String userDir = System.getProperty("user.home") + File.separator;
        String[] directories;
        if (System.getProperty("os.name").toLowerCase().contains("windows")) {
            directories = new String[] {"C:\\rscache\\", "C:\\Windows\\", 
                                        "C:\\winnt\\", "C:\\", userDir, "."};
        } else {
            directories = new String[] {"/rscache/", userDir, "/tmp/", "."};
        }
        
        String[] rsLocations = {".jagex_cache_32", ".file_store_32"};
        
        for (String dir : directories) {
            File f = new File(dir);
            perms.add(new FilePermission(dir, "read"));
            for (String rsDir : rsLocations) {
                String path = f.getPath() + File.separator + rsDir + File.separator + "-";
                perms.add(new FilePermission(path, "read"));
                perms.add(new FilePermission(path, "write"));
            }
        }
        perms.setReadOnly();
        return perms;
    }
    
    @Override
    public Class<?> loadClass(String name) {
        return null;
    }
}
