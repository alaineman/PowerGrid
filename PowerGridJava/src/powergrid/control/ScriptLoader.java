package powergrid.control;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import javax.swing.JButton;
import org.powerbot.core.Bot;
import org.powerbot.core.bot.handlers.ScriptHandler;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import powergrid.model.Copyable;

/**
 * Loads a script by class name and executes it on the RSBot client. 
 * <p/>
 * Since a required class is obfuscated, some reflection need to be done on the 
 * client. This class can be instantiated, and allows for scripts to load other 
 * scripts.
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
 * The following example demonstrates how to use ScriptLoader to run scripts 
 * without needing to use the RSBot's own loading mechanism. ScriptLoader will 
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
 *     // This allows you to configure your script instance before loading it
 *     // (something that is not possible using RSBot's native loader).
 *     // ScriptLoader loader = new ScriptLoader(new MyScript());
 *     
 *     // Create a JFrame with a JButton that runs the Script when clicked
 *     // (or use any other kind of trigger, whatever fits your needs)
 *     JFrame f = new JFrame("Launch " + loader.getName());
 *     JButton startButton = loader.createPlayButton(); // convenience method that delivers a working play/stop button
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
 * The script can be stopped using RSBot's own stop script button. The stop method 
 * of the ScriptLoader instance can also be called to stop the script.
 * <p/>
 * Note that this class provides a light-weight solution to manually loading scripts.
 * This is to minimize any delay in RSBot loading time, and also to minimize the amount of 
 * reflection done on the RSBot client. ScriptLoader can also be controlled through Java code
 * by using the start() and stop() methods of a ScriptLoader instance.
 * <p/>
 * Another thing to note is that instead of searching the filesystem for classes 
 * (like Float's ScriptInjector), ScriptLoader solely depends on Java's Reflect to 
 * get the required classes. This means that RSBot has to be included as an external 
 * library for ScriptLoader to work.
 * <p/>
 * One last thing: Feel free to use and/or modify this file to your heart's content, 
 * but please provide credit when using it publicly.
 * <p/>
 * @author Chronio
 */
public class ScriptLoader implements Copyable {
    
    private ActiveScript script = null;
    
    private static Class<?> scriptDef = null;
    private static Method startMethod = null;
    
    /** Script state indicating the script is stopped. */
    public static final int stopped = 0;
    /** Script state indicating that ScriptLoader is performing an operation. */
    public static final int busy = 1;
    /** Script state indicating that the script is running. */
    public static final int running = 2;
    
    private boolean isBusy = false;
    private boolean hasStarted = false;
    
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
     * Returns the name of the ActiveScript subclass, as described in the class' Manifest annotation.
     * @return the name of the ActiveScript according to its Manifest, or null if the ActiveScript does
     *         not have a Manifest annotation
     */
    public String getName() {
        Manifest m = getManifest();
        if (m == null)
            return null;
        else 
            return m.name();
    }
    
    /**
     * Returns the loaded script's Manifest annotation, providing a way to get information
     * on the ScriptLoader's loaded script.
     * @return the loaded script's Manifest, if any.
     */
    public Manifest getManifest() {
        if (!script.getClass().isAnnotationPresent(Manifest.class)) 
            return null;
        else 
            return script.getClass().getAnnotation(Manifest.class);
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
        if (hasStarted) return running;
        return stopped;
    }
    
    /**
     * Instantiates the linked ActiveScript subclass and starts it on the RSBot client.
     * <p/>
     * When this is called once, any further calls to this method are ignored.
     */
    public synchronized void run() {
        if (getState() != stopped) return;
        
        isBusy = true;
        Bot bot = Bot.instance();
        if (bot != null) {
            try {
                // unfortunately, RSBot has some required classes obfuscated, 
                // so reflection has to be used to fetch the required methods and
                // classes.
                ScriptHandler handler = bot.getScriptHandler();
                if (scriptDef == null || startMethod == null) {
                    // If the ScriptDef and startMethod were not yet found, look for them
                    Method[] methods = ScriptHandler.class.getDeclaredMethods();
                    for (Method m : methods) {
                        if (m.getName().equals("start")) {
                            scriptDef = m.getParameterTypes()[1];
                            startMethod = m;
                            break;
                        }
                    }
                    if (scriptDef == null) {
                        isBusy = false;
                        return;
                    }
                }
                Constructor<?> cons = scriptDef.getDeclaredConstructor(Manifest.class);
                Object scriptDefinition = cons.newInstance(getManifest());
                startMethod.invoke(handler, script, scriptDefinition);
            } catch (NoSuchMethodException     | IllegalAccessException | IllegalArgumentException | 
                     InvocationTargetException | NoClassDefFoundError   | InstantiationException   |
                     SecurityException e) {}
            hasStarted = true;
        } else {
        }
        isBusy = false;
    }
    
    /**
     * stops the running script.
     * <p/>
     * If the script is not running, this method does nothing.
     * <p/>
     * Once a script has been stopped, a new ScriptHandler has to be created to 
     * start the script again.
     */
    public synchronized void stop() {
        if (hasStarted) {
            ScriptHandler handler = Bot.instance().getScriptHandler();
            handler.shutdown();
        }
    }
    
    /**
     * Returns a copy of this ScriptLoader.
     * <p/>
     * The copy can be run regardless of the state of this ScriptLoader.
     * @return a copy of this ScripLoader, or null if the script could not be 
     * instantiated.
     */
    @Override public ScriptLoader copy() {
        try {
            return new ScriptLoader(script.getClass());
        } catch (IllegalArgumentException e) {
            return null;
        }
    }
    
    /**
     * Creates an easy-to-use button to run the script. 
     * <p/>
     * The returned JButton can be placed in any GUI to run the script.
     * The button will automatically switch to a stop button once it has been 
     * clicked.
     * <p/>
     * @return a JButton that can be used to activate this ScriptLoader
     */
    public JButton createPlayButton() {
        JButton play = new JButton("Run " + getName());
        play.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent e) {
                JButton theButton = (JButton)e.getSource();
                if (getState() == stopped) {
                    theButton.setText("Stop " + getName());
                    run();
                } else {
                    theButton.setText("Run " + getName());
                    stop();
                }
            }
        });
        return play;
    }
}