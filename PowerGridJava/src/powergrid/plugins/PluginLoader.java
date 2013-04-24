package powergrid.plugins;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Enumeration;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;
import java.util.logging.Level;
import powergrid.PowerGrid;

/**
 * This class checks the plugins folder for jar files and loads their classes.
 * <p/>
 * It can also filter the loaded classes so that all loaded classes that extend a 
 * certain class can be retrieved.
 * @author Chronio
 */
public class PluginLoader {
    
    private File folder;
    private static ClassLoader loader;
    private static Collection<Class<?>> classes;
    
    /**
     * Create a new PluginLoader that loads all jar files in the specified folder.
     * <p/>
     * 
     * @param folder the folder to load
     * @throws IllegalArgumentException when the folder is null, or is no directory
     */
    public PluginLoader(File folder) {
        if (folder == null) 
            throw new IllegalArgumentException("folder is null");
        if (!folder.isDirectory()) {
            if (folder.exists()) 
                throw new IllegalArgumentException("Plugin folder exists but is no directory");
            else {
                if (!folder.mkdir()) 
                    throw new IllegalArgumentException("Could not create plugin directory");
            }
        }
        this.folder = folder;
        loadClasses();
    }
    
    @SuppressWarnings("unchecked") 
    private void loadClasses() {
        File[] files = folder.listFiles();
        URL[] urls = new URL[files.length];
        for (int i = 0; i < files.length; i++) {
            try { urls[i] = files[i].toURI().toURL(); }
            catch (MalformedURLException e) {}
        }
        loader = new URLClassLoader(urls);
        classes = new ArrayList<>();
        for (File f : files) {
            if (f.getName().endsWith(".jar") && f.isFile()) {
                try { 
                    classes.addAll(getClasses(new JarFile(f)));
                } catch (IOException e) {
                    System.out.println("Error while reading from jar file: " + f.getName() + "\n  " + e.getMessage());
                }
            }
        }
        
    }

    private Collection<Class<?>> getClasses(JarFile jar) {
        Enumeration<JarEntry> entries = jar.entries();
        ArrayList<Class<?>> cls = new ArrayList<>();
        while (entries.hasMoreElements()) {
            JarEntry entry = entries.nextElement();
            String className = entry.getName().replaceAll("/", ".");
            int index = className.lastIndexOf(".class");
            if (index < 0) continue;
            className = className.substring(0,index);
            try {
                cls.add(loader.loadClass(className));
            } catch (ClassNotFoundException e) {
                System.out.println("Could not load entry: " + jar.getName() + ":" + className);
            }
        }
        return cls;
    }
    
    /**
     * Returns the folder that this PluginLoader loaded from
     * @return the folder that this PluginLoader loaded from
     */
    public File getFolder() {
        return folder;
    }
    
    /**
     * Returns all classes that were loaded in this PluginLoader.
     * <p/>
     * The returned Collection is immutable.
     * @return all loaded classes in this PluginLoader
     */
    public Collection<Class<?>> getAllClasses() {
        return classes;
    }
    
    /**
     * Returns a Collection of all classes that are equal to or a subclass of the Class parameter.
     * <p/>
     * @param <U> the type of the class modeled by the given Class object
     * @param clazz the Class object that models the required superclass
     * @return a Collection of all classes that are equal to or a subclass of the Class parameter
     */
    public<U> Collection<Class<? extends U>> getSubclasses(Class<U> clazz) {
        ArrayList<Class<? extends U>> subclasses = new ArrayList<>();
        for (Class<?> c : classes) {
            if (clazz.isAssignableFrom(c)) {
                Class<? extends U> subclass = c.asSubclass(clazz);
                subclasses.add(subclass);
            }
        }
        return subclasses;
    }
    
    public Plugin[] getLoadedPlugins() {
        Collection<Class<? extends Plugin>> plugins = getSubclasses(Plugin.class);
        ArrayList<Plugin> ps = new ArrayList<>(plugins.size());
        for (Class<? extends Plugin> p : plugins) {
            if (p.isAnnotationPresent(PluginInfo.class)) {
                PluginInfo info = p.getAnnotation(PluginInfo.class);
                if (info.requiredVersion() > PowerGrid.VERSION) {
                    PowerGrid.LOGGER.log(Level.WARNING, "Plugin \"" 
                            + info.name() + "\" needs PowerGrid v" + 
                            info.requiredVersion() + 
                            " or higher to work. Please update PowerGrid");
                    continue;
                }
            }
            try {
                Constructor<? extends Plugin> cons = p.getConstructor();
                Plugin plugin = cons.newInstance();
                ps.add(plugin);
            } catch (IllegalAccessException | NoSuchMethodException | InstantiationException | InvocationTargetException e) {
                PowerGrid.LOGGER.log(Level.SEVERE, 
                        "Could not load the Plugin, since the plugin could not be instantiated", e);
            }
        }
        return ps.toArray(new Plugin[ps.size()]);
    }
}
