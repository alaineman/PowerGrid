package powergrid.plugins;

import java.io.File;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
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
    private ClassLoader loader;
    private Collection<Class<?>> classes;
    
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
        ArrayList<URL> urls = new ArrayList<>(files.length);
        for (File f : files) {
            if (f.isFile() && (f.getName().endsWith(".jar") || f.getName().endsWith(".class"))) {
                try { 
                    urls.add(f.toURI().toURL()); 
                    PowerGrid.debugMessage("Plugin found: " + f.getName());
                } catch(MalformedURLException e) {
                    PowerGrid.logMessage("Found malformed url for file: " + f.getName());
                }
            }
        }
        loader = new URLClassLoader(urls.toArray(new URL[urls.size()]));
        
        try {
            Field f = ClassLoader.class.getDeclaredField("classes");
            f.setAccessible(true);
            classes = Collections.unmodifiableCollection((Collection<Class<?>>)f.get(loader));
            f.setAccessible(false);
        } catch (NoSuchFieldException | IllegalAccessException e) {
            PowerGrid.logMessage("Could not retrieve classes from ClassLoader: ",e);
        } catch (NullPointerException npe) {
            PowerGrid.logMessage("Could not load plugins, no plugins found",npe);
        }
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
                if (info.requiredVersion() > PowerGrid.VERSION)
                    continue;
            }
            try {
                Constructor<? extends Plugin> cons = p.getConstructor();
                Plugin plugin = cons.newInstance();
                ps.add(plugin);
            } catch (IllegalAccessException | NoSuchMethodException | InstantiationException | InvocationTargetException e) {
                PowerGrid.logMessage("Could not load the Plugin, since the plugin could not be instantiated",e);
            }
        }
        return ps.toArray(new Plugin[ps.size()]);
    }
}
