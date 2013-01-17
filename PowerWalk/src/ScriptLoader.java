import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.Serializable;
import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import org.powerbot.core.bot.Bot;
import org.powerbot.core.bot.handlers.ScriptHandler;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.core.script.Script;
import org.powerbot.game.api.Manifest;
import powerwalk.Starter;

/**
 * Loads a script and executes it on the RSBot client. Since a required class is 
 * obfuscated, some reflection is done on the client.
 * @author Chronio
 */
public class ScriptLoader {
    
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
                System.err.println("[PowerWalk > ScriptLoader] Script launched");
                state = running;
            } catch (NoSuchMethodException     | IllegalAccessException | IllegalArgumentException | 
                     InvocationTargetException | NoClassDefFoundError   | InstantiationException   |
                     SecurityException e) {
                System.err.println("[PowerWalk] An error occurred while trying to load script:\n  " + e.getClass().getSimpleName() + ": " + e.getLocalizedMessage());
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
    
    public static void main(String[] args) {
        Starter.main(new String[]{"-dev"});
        ScriptLoader l = new ScriptLoader("powerwalk.Starter");
        JButton b = l.createPlayButton();
        b.setPreferredSize(new Dimension(200, 32));
        JFrame lFrame = new JFrame("PW launcher");
        try {
            lFrame.setIconImage(ImageIO.read(ClassLoader.getSystemResource("icon_small.png")));
        } catch (IOException e) {
            System.err.println("[PowerWalk] failed to load imageicon due to " + e.getClass().getSimpleName());
        }
        lFrame.setResizable(false);
        lFrame.setLayout(new BorderLayout(10, 5));
        lFrame.add(b,"Center");
        lFrame.pack();
        lFrame.setVisible(true);
    }
}