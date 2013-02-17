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
 * A ScriptLoader can be instantiated with either a String denoting an ActiveScript subclass,
 * a Class object representing a ActiveScript subclass, or an ActiveScript instance.
 * Because of this, ScriptLoader can be used in nearly all situations and setups.
 * <p/>
 * Special thanks to Float's ScriptInjector class for providing insight into RSBot's
 * way of loading and starting scripts.
 * <p/>
 * <strong>How to use ScriptLoader to run your own plugins from outside RSBot</strong>
 * <p/>
 * The following example demonstrates how to use ScriptLoader to run plugins 
 * without needing to use the RSBot's internal loading mechanism. ScriptLoader will 
 * perform all required method calls to start the ActiveScript in RSBot.
 * <p/>
 * <pre>
 * // Create a main method of your own that creates the ScriptLoader instance and starts RSBot
 * public static void main(String[] args) {
 *     // The ActiveScript subclass that will be used.
 *     // Replace this with your own class.
 *     Class&lt;? extends ActiveScript&gt; script = MyScript.class;
 * 
 *     // Start RSBot using RSBot's own main method
 *     org.powerbot.Boot.main(args);
 * 
 *     // Create the ScriptLoader instance
 *     ScriptLoader loader = new ScriptLoader(script);
 *     
 *     // Alternatively, instantiate the ActiveScript yourself and pass it as an argument.
 *     // This allows you to configure your script instance before loading it.
 *     // ScriptLoader loader = new ScriptLoader(new MyScript());
 *     
 *     // Create a JFrame with a JButton that runs the Script when clicked
 *     // (or use any other kind of trigger, whatever fits your needs)
 *     JFrame f = new JFrame("Launch " + loader.getName());
 *     JButton startButton = loader.createPlayButton(); // convenience method that delivers a working play button
 *     startButton.setPreferredSize(new Dimension(240,32));
 *     f.add(startButton);
 *     f.pack();
 *     f.setResizable(false);
 *     f.setVisible(true);
 * }
 * </pre>
 * <p/>
 * The above method will launch RSBot, and after that show a Button that allows the script
 * given in the field <code>script</code> to be started by the RSBot client. 
 * The script can be stopped using RSBot's native stop button.
 * <p/>
 * Note that this class provides a light-weight solution to manually loading scripts.
 * This is to minimize any delay in RSBot loading time, and also to minimize the amount of 
 * reflection done on the RSBot client.
 * <p/>
 * Another thing to note is that instead of searching the filesystem for classes 
 * (like Float's ScriptInjector), ScriptLoader depends on Java's ClassLoader to 
 * get the required classes. 
 * This means that it must be possible for the ClassLoader to find the Script class(es)
 * and the RSBot jar file. This implies importing RSBot.jar into your (Eclipse) project.
 * <p/>
 * One last thing: Feel free to use and/or modify this file to your heart's content, 
 * but please provide credit when using it publicly.
 * <p/>
 * @author Chronio
 */
public class ScriptLoader {
    
    private ActiveScript script = null;
    
    public static final int stopped = 0;
    public static final int busy = 1;
    public static final int running = 2;
    public static final int paused = 3;
    
    private boolean isBusy = false;
    
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
            if (ActiveScript.class.isAssignableFrom(c) && c.isAnnotationPresent(Manifest.class)) {
                Class<? extends ActiveScript> scriptClass = c.asSubclass(ActiveScript.class);
                try { 
                    script = scriptClass.getConstructor().newInstance();
                } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
                    throw new IllegalArgumentException("The given script cannot be instantiated", e);
                }
            } else // if the class is not an ActiveScript subclass, throw an Exception
                throw new IllegalArgumentException(scriptClassName + " does not resemble a valid ActiveScript subclass");
        } catch (ClassNotFoundException e) {
            // if the class could not be found, throw an Exception
            throw new IllegalArgumentException("Invalid Class Name", e);
        }
    }
    
    /**
     * Creates a new ScriptLoader instance that runs an instance of the ActiveScript subclass 
     * modeled by the Class object.
     * @param script the ActiveScript subclass that this ScriptLoader will load
     * @throws IllegalArgumentException when <code>script == null</code>, or the 
     *                                  provided ActiveScript class could not be 
     *                                  instantiated.
     */
    public ScriptLoader(Class<? extends ActiveScript> script) {
        if (script == null)
            throw new IllegalArgumentException("Null-value for ActiveScript class");
        try { 
            this.script = script.getConstructor().newInstance();
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            throw new IllegalArgumentException("The given script cannot be instantiated", e);
        }
    }
    
    /**
     * Creates a new ScriptLoader instance that runs the given ActiveScript.
     * @param script the ActiveScript to run
     * @throws IllegalArgumentException when <code>script == null</code>.
     */
    public ScriptLoader(ActiveScript script) {
        if (script == null)
            throw new IllegalArgumentException("null value for script");
        this.script = script;
    }
    
    /**
     * Returns the ActiveScript instance that this ScriptLoader holds.
     * @return the ActiveScript instance
     */
    public ActiveScript getScript() {
        return script;
    }
    
    /**
     * instructs RSBot to set the ActiveScript instance to the desired state.
     * <p/>
     * Valid states are running, paused and stopped.
     * <p/>
     * Since this method delegates to RSBot for the actual instruction, no guarantees 
     * can be made that this method behaves as expected in all situations.
     * <p/>
     * If the ScriptLoader's state as given by <code>getState()</code> is <code>busy</code>,
     * this method does nothing and returns false.
     * <p/>
     * @param state the desired state
     * @return true if the operation was succesful, false if it was not.
     */
    public boolean setState(int state) {
        if (getState() == state) 
            return true;
        if (isBusy)
            return false;
        isBusy = true;
        switch (state) {
            case stopped:
                script.shutdown();
                break;
            case paused:
                script.setPaused(true);
                break;
            case running:
                if (script.isPaused())
                    script.setPaused(false);
                else
                    run();
                break;
        }
        isBusy = false;
        return getState() == state;
    }
    
    /**
     * Returns the name of the ActiveScript subclass, as described in the class' Manifest annotation.
     * @return the name of the ActiveScript according to its Manifest
     */
    public String getName() {
        // return the Manifest associated with this class
        return script.getClass().getAnnotation(Manifest.class).name();
    }

    /**
     * Determines and returns the state of the ActiveScript.
     * <p/>
     * When this method returns <code>busy</code>, it means that this ScriptLoader
     * is performing operations on the Script.
     * @return the state of the ActiveScript
     */
    public int getState() {
        if (isBusy) return busy;
        if (script.isActive()) return running;
        if (script.isPaused()) return paused;
        return stopped;
    }
    
    /**
     * Instantiates the linked ActiveScript subclass and starts it on the RSBot client.
     * <p/>
     * When this is called once, any further calls to this method are ignored.
     */
    public synchronized void run() {
        if (getState() != stopped) return;
        // get scriptClass instance and run it.
        // at this moment, reflection has to be used to get to the ScriptLoader class
        isBusy = true;
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
                
                Constructor<?> cons = scriptDef.getDeclaredConstructor(Manifest.class);
                Object scriptDefinition = cons.newInstance(script.getClass().getAnnotation(Manifest.class));
                startMethod.invoke(handler, script, scriptDefinition);
                logMessage(getName() + " launched",null);
            } catch (NoSuchMethodException     | IllegalAccessException | IllegalArgumentException | 
                     InvocationTargetException | NoClassDefFoundError   | InstantiationException   |
                     SecurityException e) {
                logMessage("An error occurred while trying to load script.",e);
            }
        }
        isBusy = false;
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
        // used to access this field. When modifying this class to your own needs, 
        // be sure not to change the result of this method, since this will also 
        // alter the ClassLoader's loaded classes.
        try {
            Field f = ClassLoader.class.getDeclaredField("classes");
            f.setAccessible(true);

            @SuppressWarnings("unchecked") // << We know it is a Collection of Class objects
            Collection<Class<?>> cls = (Collection<Class<?>>)f.get(cl);
            
            // restore original "private" status of ClassLoader's classes field
            f.setAccessible(false);
            return cls;
        } catch (IllegalAccessException | IllegalArgumentException | NoSuchFieldException | SecurityException ex) {
            logMessage("Exception while reading RSBot classes",ex);
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
                if (getState() == stopped) {
                    JButton theButton = (JButton)e.getSource();
                    theButton.setText(getName() + " running");
                    theButton.setEnabled(false);
                    run();
                }
            }
        });
        return play;
    }
    
    /**
     * Logs a message to the console using <code>System.err</code>. 
     * <p/>
     * Also displays a StackTrace when the given Throwable is not null.
     * @param message the message to log.
     * @param t the throwable that caused the message, can be null
     */
    public static void logMessage(String message, Throwable t) {
        StringBuilder sb = new StringBuilder(message).append("\n");
        if (t != null) {
            sb.append("  caused by: ").append(t.getClass().getSimpleName()).append("\n");
            for (StackTraceElement e : t.getStackTrace()) {
                sb.append("in ")
                        .append(e.getClassName()).append(": ")
                        .append(e.getLineNumber()).append(" (")
                        .append(e.getMethodName()).append(")\n");
            }
        }
        System.err.print(sb.toString());
    }
}