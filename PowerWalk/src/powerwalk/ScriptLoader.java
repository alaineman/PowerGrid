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
 * Loads a script by class name and executes it on the RSBot client. 
 * <p/>
 * Since a required class is obfuscated, some reflection need to be done on the 
 * client. This class can be instantiated, and allows for scripts to load other 
 * scripts. This fills in the gap in PowerBot's functionality, where different 
 * scripts cannot coorporate.
 * <p/>
 * @author Chronio
 */
public class ScriptLoader {
    
    /** The ScriptLoader instance, stored here for global access. */ 
    // Note: consider moving, not an essential part of ScriptLoader
    public static ScriptLoader pwLoader = new ScriptLoader("powerwalk.Starter");
    
    private Class<? extends ActiveScript> scriptClass = null;
    
    private static int stopped = 0;
    private static int busy = 1;
    private static int running = 2;
    
    private int state = stopped;
    
    /**
     * Creates a new ScriptLoader instance linked to the ActiveScript subclass 
     * indicated by the given class name.
     * <p/>
     * @param scriptClassName the fully qualified name of the desired ActiveScript subclass.
     * @throws IllegalArgumentException when the provided class name does not resemble 
     * an available class or the specified class name does not resemble an ActiveScript 
     * subclass.
     */
    public ScriptLoader(String scriptClassName) {
        try {
            // load and verify the Class Name using reflection
            Class<?> c = Class.forName(scriptClassName);
            if (ActiveScript.class.isAssignableFrom(c) && c.isAnnotationPresent(Manifest.class))
                scriptClass = c.asSubclass(ActiveScript.class);
            else // if the class is not an ActiveScript subclass, throw an Exception
                throw new IllegalArgumentException(scriptClassName + " does not resemble a valid ActiveScript subclass");
        } catch (ClassNotFoundException e) {
            // if the class could not be found, throw an Exception
            throw new IllegalArgumentException("Invalid Class Name", e);
        }
    }
    /**
     * Returns the name of the ActiveScript subclass, as described in the class' Manifest annotation.
     * @return the name of the ActiveScript according to its Manifest
     */
    public String getName() {
        // return the Manifest associated with this class
        return scriptClass.getAnnotation(Manifest.class).name();
    }
    
    /**
     * Instantiates the linked ActiveScript subclass and starts it on the RSBot client.
     * <p/>
     * When this is called once, any further calls to this method are ignored.
     */
    public synchronized void run() {
        if (state != stopped) return;
        // get scriptClass instance and run it.
        // at this moment, reflection has to be used to get to the ScriptLoader class
        state = busy;
        Bot bot = Bot.getInstance();
        if (bot != null) {
            try {
                // unfortunately, RSBot has some required classes obfuscated, 
                // so reflection has to be used to fetch the required objects and
                // classes.
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
        // This method checks all methods in a given class to match the given
        // pattern of input and output arguments.
        for (Method m : clazz.getDeclaredMethods()) {
            if (m.getReturnType().equals(returnType) &&
                Arrays.equals(params, m.getParameterTypes()))
                return m;
        }
        throw new NoSuchMethodException();
    }
    
    private static Collection<Class<?>> getClasses(ClassLoader cl) {
        // this method loads all classes available to the given ClassLoader by 
        // checking out the ClassLoader's private "classes" field. Reflection is 
        // used to access this field.
        try {
            Field f = ClassLoader.class.getDeclaredField("classes");
            f.setAccessible(true);

            @SuppressWarnings("unchecked") // << We know it is a Collection of Class objects
            Collection<Class<?>> cls = (Collection<Class<?>>)f.get(cl);

            // restore original "private" status of ClassLoader's classes field
            f.setAccessible(false);
            return cls;
        } catch (IllegalAccessException | IllegalArgumentException | NoSuchFieldException | SecurityException ex) {
            Starter.logMessage("Exception while reading RSBot classes","ScriptLoader",ex);
        }
        return null;
    }
    
    /**
     * Creates an easy-to-use button to run the script. 
     * <p/>
     * The returned JButton can be placed in any GUI to run the script.
     * The button will automatically disable once it has been clicked.
     * <p/>
     * @return a JButton that can be used to activate this ScriptLoader
     */
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