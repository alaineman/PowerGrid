package powerwalk;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;
import java.lang.reflect.*;
import java.util.Arrays;
import java.util.Collection;
import javax.swing.JButton;
import org.powerbot.core.bot.Bot;
import org.powerbot.core.bot.handlers.ScriptHandler;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.core.script.Script;
import org.powerbot.game.api.Manifest;

/**
 * Loads a script and executes it on the RSBot client. Since a required class is 
 * obfuscated, some reflection is done on the client.
 * @author Chronio
 */
public class ScriptLoader {
    
    public static ScriptLoader pwLoader = new ScriptLoader("powerwalk.Starter");
    
    private Class<? extends ActiveScript> scriptClass = null;
    
    private static int stopped = 0;
    private static int busy = 1;
    private static int running = 2;
    
    private int state = stopped;
    
    public ScriptLoader(String scriptClassName) {
        try {
            // load and verify the Class Name using reflection
            Class<?> c = Class.forName(scriptClassName);
            if (ActiveScript.class.isAssignableFrom(c) && c.isAnnotationPresent(Manifest.class)) {
                scriptClass = c.asSubclass(ActiveScript.class);
            } else // if the class is not an ActiveScript subclass, throw an Exception
                throw new IllegalArgumentException(scriptClassName + " does not resemble a valid ActiveScript subclass");
        } catch (ClassNotFoundException e) {
            // if the class could not be found, throw an Exception
            throw new IllegalArgumentException("Invalid Class Name", e);
        }
    }
        
    public String getName() {
        // return the Manifest associated with this class
        return scriptClass.getAnnotation(Manifest.class).name();
    }
    
    public void run() {
        // get scriptClass instance and run it.
        // at this moment, reflection has to be used to get to the ScriptLoader class
        state = busy;
        Bot bot = Bot.getInstance();
        if (bot != null) {
            try {
                Method getHandler = fetchMethod(Bot.class, ScriptHandler.class);
                ScriptHandler handler = (ScriptHandler)getHandler.invoke(bot);
                Class<?> scriptDef = null;
                for (Class<?> c : getClasses(getClass().getClassLoader())) {
                    if (Comparable.class.isAssignableFrom(c) && Serializable.class.isAssignableFrom(c) &&
                        c.getModifiers() == (Modifier.PUBLIC | Modifier.FINAL)) {
                        scriptDef = c; // << the ScriptDefinition class that is used to read the Manifest
                    }
                }
                if (scriptDef == null) throw new NoClassDefFoundError("scriptDef");
                Method startMethod = fetchMethod(ScriptHandler.class, Boolean.TYPE, Script.class, scriptDef);
                
                ActiveScript s = scriptClass.newInstance();
                Constructor<?> cons = scriptDef.getDeclaredConstructor(Manifest.class);
                Object scriptDefinition = cons.newInstance(scriptClass.getAnnotation(Manifest.class));
                startMethod.invoke(handler, s, scriptDefinition);
                Starter.logMessage(getName() + " launched","ScriptLoader");
                state = running;
            } catch (NoSuchMethodException     | IllegalAccessException | IllegalArgumentException | 
                     InvocationTargetException | NoClassDefFoundError   | InstantiationException   |
                     SecurityException e) {
                Starter.logMessage("An error occurred while trying to load script.","ScriptLoader",e);
            }
        }
    }
    
    private static Method fetchMethod(Class<?> clazz, Class<?> returnType, Class<?>... params) throws NoSuchMethodException {
        for (Method m : clazz.getDeclaredMethods()) {
            if (m.getReturnType().equals(returnType) &&
                Arrays.equals(params, m.getParameterTypes()))
                return m;
        }
        throw new NoSuchMethodException();
    }
    
    private static Collection<Class<?>> getClasses(ClassLoader cl) {
        try {
            Field f = ClassLoader.class.getDeclaredField("classes");
            f.setAccessible(true);
            
            @SuppressWarnings("unchecked")
            Collection<Class<?>> cls = (Collection<Class<?>>)f.get(cl);
            
            // restore original "private" status of ClassLoader's classes field
            f.setAccessible(false);
            
            return cls;
        } catch (IllegalAccessException | IllegalArgumentException | NoSuchFieldException | SecurityException ex) {
            Starter.logMessage("Exception while reading RSBot classes","ScriptLoader",ex);
        }
        return null;
    }
    
    public JButton createPlayButton() {
        JButton play = new JButton("Run " + getName());
        play.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent e) {
                if (state == stopped) {
                    JButton theButton = (JButton)e.getSource();
                    theButton.setText(getName() + " running");
                    theButton.setEnabled(false);
                    run();
                }
            }
        });
        return play;
    }
}