import java.io.Serializable;
import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import org.powerbot.core.bot.Bot;
import org.powerbot.core.bot.handlers.ScriptHandler;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.core.script.Script;
import org.powerbot.game.api.Manifest;

public class ScriptLoader {
    
    private Class<? extends ActiveScript> scriptClass = null;
    
    public ScriptLoader(String scriptClassName) {
        try {
            // load and verify the Class Name using reflection
            Class<?> c = Class.forName(scriptClassName);
            if (ActiveScript.class.isAssignableFrom(c) && c.isAnnotationPresent(Manifest.class)) {
                scriptClass = c.asSubclass(ActiveScript.class);
            } else // if the class is not an ActiveScript subclass, throw an Exception
                throw new IllegalArgumentException(scriptClassName + " does not resemble an ActiveScript subclass");
        } catch (ClassNotFoundException e) {
            // if the class could not be found, throw an Exception
            throw new IllegalArgumentException("Invalid Class Name", e);
        }
    }
    
    public ActiveScript getInstance() {
        try {
            // try to create a new instance to return
            return scriptClass.newInstance();
        } catch (InstantiationException | IllegalAccessException ex) {
            // upon failure, throw an Exception
            throw new UnsupportedOperationException("The class cannot be instantiated", ex);
        }
    }
    
    public Manifest getManifest() {
        // return the Manifest associated with this class
        return scriptClass.getAnnotation(Manifest.class);
    }
    
    public void run() {
        // get scriptClass instance and run it.
        // at this moment, reflection has to be used to get to the ScriptLoader class
        Bot bot = Bot.getInstance();
        if (bot != null) {
            try {
                Method getHandler = fetchMethod(Bot.class, ScriptHandler.class);
                Object handler = getHandler.invoke(bot);
                Class<?> scriptDef = null;
                for (Class<?> c : getClasses(getClass().getClassLoader())) {
                    if (Comparable.class.isAssignableFrom(c) && Serializable.class.isAssignableFrom(c) &&
                        c.getModifiers() == (Modifier.PUBLIC | Modifier.FINAL)) {
                        scriptDef = c;
                    }
                }
                if (scriptDef == null) throw new NoClassDefFoundError("scriptDef");
                Method startMethod = fetchMethod(ScriptHandler.class, Boolean.TYPE, Script.class, scriptDef);
                
                Script s = scriptClass.newInstance();
                Constructor<?> cons = scriptDef.getDeclaredConstructor(Manifest.class);
                Object scriptDefinition = cons.newInstance(getManifest());
                startMethod.invoke(handler, s, scriptDefinition);
                System.out.println("[PowerWalk > ScriptLauncher] Script launched");
            } catch (NoSuchMethodException     | IllegalAccessException | IllegalArgumentException | 
                     InvocationTargetException | NoClassDefFoundError   | InstantiationException   |
                     SecurityException e) {}
        }
    }
    
    private Method fetchMethod(Class<?> clazz, Class<?> returnType, Class<?>... params) throws NoSuchMethodException {
        for (Method m : clazz.getDeclaredMethods()) {
            if (m.getReturnType().equals(returnType) &&
                Arrays.equals(params, m.getParameterTypes()))
                return m;
        }
        throw new NoSuchMethodException();
    }
    
    private static ArrayList<Class<?>> getClasses(ClassLoader cl) {
        try {
            Field f = ClassLoader.class.getDeclaredField("classes");
            f.setAccessible(true);
            
            @SuppressWarnings("unchecked")
            ArrayList<Class<?>> list = new ArrayList<>((Collection<? extends Class<?>>)f.get(cl));
            
            // restore original "private" status of ClassLoader's classes field
            f.setAccessible(false);
            
            return list;
        } catch (IllegalAccessException | IllegalArgumentException | NoSuchFieldException | SecurityException ex) {
            System.out.println("Something went wrong: \n" + ex);
        }
        return null;
    }
}