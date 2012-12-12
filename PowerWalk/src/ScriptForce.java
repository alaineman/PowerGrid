import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.FileInputStream;
import java.lang.reflect.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.*;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import org.powerbot.game.api.Manifest;

public class ScriptForce {

        private static Level level = null;
        private static final Logger Logger = java.util.logging.Logger.getLogger(ScriptForce.class.getName());
        private static final String Dictionary = "..\\lib\\RSBot-4045.jar";
        private static URLClassLoader RSBot = null;

        public static void main(final String[] args) throws Exception {
                System.out.println("[ScriptForce] Launching RSBot @ "+Dictionary+"...");
                RSBot = URLClassLoader.newInstance(new URL[]{new File(Dictionary).toURI().toURL()});

                final Method mainClazz = RSBot.loadClass("org.powerbot.Boot").getDeclaredMethod("main", String[].class);
                mainClazz.setAccessible(true);
                mainClazz.invoke(null, (Object) new String[]{"-dev"});

                System.out.println("[ScriptForce] Getting classes");

                final List<Class<?>> classes = new ArrayList();
                final JarInputStream jar = new JarInputStream(new FileInputStream(Dictionary));
                while(true) {
                        final JarEntry entry = jar.getNextJarEntry();
                        if(entry == null)
                                break;
                        else if(entry.getName().endsWith(".class")) {
                                classes.add(RSBot.loadClass(entry.getName().replaceAll("/", "\\.").replaceAll("\\.class", "")));
                        }
                }
                final Constructor<?> constructor = Level.class.getDeclaredConstructor(String.class, int.class, String.class);
                if(constructor != null) {
                        constructor.setAccessible(true);
                        level = (Level) constructor.newInstance("ScriptForce", 900, "sun.util.logging.resources.logging");
                }

                Logger.log(level, "[UI] UI visible, searching RSBot for needed classes...");
                Logger.log(level, "---------------------------");

                ActiveScript = RSBot.loadClass("org.powerbot.core.script.ActiveScript");
                Manifest = RSBot.loadClass("org.powerbot.game.api.Manifest");
                ScriptHandler = RSBot.loadClass("org.powerbot.core.bot.handlers.ScriptHandler");
                if(ActiveScript != null && Manifest != null && ScriptHandler != null) {
                        Logger.log(level, "[Class] ActiveScript and Manifest class loaded.");
                        for(final Method method : ActiveScript.getDeclaredMethods())
                                if(method.getName().equals("getDefinition")) {
                                        final String name = method.getReturnType().getName();
                                        ScriptDef = RSBot.loadClass(name);
                                        Logger.log(level, "[Class] ScriptDefinition[" + name + "] class loaded.");
                                        break;
                                }
                        for(final Class<?> clazz : classes) {
                                if(JFrame.class.isAssignableFrom(clazz)) {
                                        if(Reflect.inter(clazz, WindowListener.class)) {
                                                Canvas = RSBot.loadClass(clazz.getName());
                                                Logger.log(level, "[Class] Canvas[" + clazz.getName() + "] class loaded.");
                                        }
                                } else if(JToolBar.class.isAssignableFrom(clazz)) {
                                        Toolbar = RSBot.loadClass(clazz.getName());
                                        Logger.log(level, "[Class] Toolbar[" + clazz.getName() + "] class loaded.");
                                } else if(clazz.getName().endsWith("Bot")) {
                                        Bot = RSBot.loadClass(clazz.getName());
                                        Logger.log(level, "[Class] Bot[" + clazz.getName() + "] class loaded.");
                                } else if(clazz.getModifiers() == (Modifier.PUBLIC | Modifier.FINAL)) {
                                        if(Reflect.method(clazz, Map.class, Modifier.PUBLIC | Modifier.SYNCHRONIZED, int.class) != null) {
                                                Network = RSBot.loadClass(clazz.getName());
                                                Logger.log(level, "[Class] Network[" + clazz.getName() + "] class loaded;");
                                        } else if(Reflect.inter(clazz, Runnable.class)) {
                                                Socket = RSBot.loadClass(clazz.getName());
                                                Logger.log(level, "[Class] Socket[" + clazz.getName() + "] class loaded.");
                                        }
                                }
                        }
                        if(ScriptDef == null || Canvas == null || Toolbar == null || Bot == null || Network == null || Socket == null) {
                                Logger.log(level, "Unable to load all preset classes.");
                        } else {
                                Logger.log(level, "[Class] All classes found and loaded.");
                                Logger.log(level, "---------------------------");
                        }
                } else Logger.log(level, "Unable to load preset classes.");
                Logger.log(level, "Loading complete, Showing UI.");
                new UI().setVisible(true);
        }

        private static Class<?> loadClass(final File file) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException,
                        IllegalAccessException, InstantiationException, MalformedURLException {
                final Object scriptLoader = RSBot.loadClass("org.powerbot.game.loader.RSClassLoader").getConstructor(Map.class, URL.class)
                                .newInstance(new HashMap<String, byte[]>(), (file.toURI().toURL()));
                final Method method = Reflect.method(scriptLoader.getClass(), Class.class, Modifier.PUBLIC | Modifier.FINAL, String.class);
                method.setAccessible(true);
                return (Class<?>) method.invoke(scriptLoader, file.getName().replaceFirst("\\.class", ""));
        }

        private static class Reflect {

                private static Field field(final Class<?> clazz, final Class<?> type, final int modifiers) {
                        for(final Field field : clazz.getDeclaredFields()) {
                                if(field.getType().equals(type) && field.getModifiers() == modifiers)
                                        return field;
                        }
                        return null;
                }

                private static Method method(final Class<?> clazz, final Class<?> returnType, final int modifiers, final Class<?>... param) {
                        for(final Method method : clazz.getDeclaredMethods()) {
                                if(method.getReturnType().equals(returnType) && method.getModifiers() == modifiers
                                                && Arrays.equals(method.getParameterTypes(), param)) {
                                        return method;
                                }
                        }
                        return null;
                }

                private static boolean inter(final Class<?> clazz, final Class<?> inter) {
                        for(final Class<?> c : clazz.getInterfaces())
                                if(c != null && c.equals(inter)) {
                                        return true;
                                }
                        return false;
                }
        }

        private static class UI extends JFrame {

                private UI() {
                        final JButton button1 = new JButton("Reload"), button2 = new JButton("Force logout"), button3 = new JButton("Execute");
                        final JScrollPane scrollPane = new JScrollPane();
                        final JTable table = new JTable(getModel());

                        this.setDefaultCloseOperation(WindowConstants.HIDE_ON_CLOSE);
                        this.setTitle("ScriptForce");
                        this.setResizable(false);
                        this.setAlwaysOnTop(true);
                        this.setLocationRelativeTo(null);

                        table.setTableHeader(null);
                        scrollPane.setViewportView(table);

                        button1.setFocusable(false);
                        button1.addActionListener(new ActionListener() {
                                @Override
                                public void actionPerformed(final ActionEvent e) {
                                        table.setModel(getModel());
                                }
                        });
                        button2.setFocusable(false);
                        button2.addActionListener(new ActionListener() {
                                @Override
                                @SuppressWarnings("unchecked")
                                public void actionPerformed(final ActionEvent e) {
                                        try {
                                                final Method getNetwork = Reflect.method(Network, Network, Modifier.PUBLIC | Modifier.STATIC | Modifier.SYNCHRONIZED);
                                                getNetwork.setAccessible(true);
                                                final Object network = getNetwork.invoke(null);
                                                if(network != null) {
                                                        final Method getSocket = Reflect.method(Socket, Socket, Modifier.PUBLIC | Modifier.STATIC);
                                                        getSocket.setAccessible(true);
                                                        final Object socket = getSocket.invoke(null);
                                                        if(socket != null) {
                                                                final Method logout = Reflect.method(network.getClass(), Map.class, Modifier.PUBLIC | Modifier.SYNCHRONIZED, int.class);
                                                                final Method socketInt = Reflect.method(socket.getClass(), int.class, Modifier.PUBLIC);
                                                                logout.setAccessible(true);
                                                                socketInt.setAccessible(true);
                                                                logout.invoke(network, socketInt.invoke(socket));

                                                                final Method logoutMethod = Reflect.method(network.getClass(), Void.TYPE, Modifier.PUBLIC | Modifier.SYNCHRONIZED);
                                                                logoutMethod.setAccessible(true);
                                                                logoutMethod.invoke(network);

                                                                Logger.log(level, "Force logged out, this prevents the tab from closing.");
                                                        }
                                                }
                                        } catch(final Exception _e) {
                                                //_e.printStackTrace(System.err);
                                        }
                                }
                        });
                        button3.setFocusable(false);
                        button3.addActionListener(new ActionListener() {
                                @Override
                                @SuppressWarnings("unchecked")
                                public void actionPerformed(final ActionEvent e) {
                                        if(table.getSelectedRow() == -1)
                                                return;
                                        try {
                                                final Class<?> script = loadClass(new File("build/classes/" + table.getValueAt(table.getSelectedRow(), 0).toString() + ".class"));
                                                if(script != null) {
                                                        final Object activeScript = script.asSubclass(ActiveScript).newInstance();
                                                        //final Method setDef = Reflect.method(activeScript.getClass().getSuperclass(), Void.TYPE, Modifier.PUBLIC, ScriptDef);
                                                        //setDef.setAccessible(true);
                                                        //setDef.invoke(activeScript, ScriptDef.getConstructor(Manifest).newInstance(script.getAnnotation(Manifest)));

                                                        final Method getBot = Reflect.method(Bot, Bot, Modifier.PUBLIC | Modifier.STATIC | Modifier.SYNCHRONIZED);
                                                        getBot.setAccessible(true);
                                                        final Object bot = getBot.invoke(null);
                                                        if(bot != null) {
                                                                final Method getScriptHandler = Bot.getMethod("getScriptHandler", new Class[] {});
                                                                getScriptHandler.setAccessible(true);
                                                                final Object scriptHandler = getScriptHandler.invoke(bot);
                                                                Method runScript = null;
                                                                for (Method m : ScriptHandler.getDeclaredMethods()) {
                                                                        if (m.getName().equalsIgnoreCase("start")) {
                                                                                runScript = m;
                                                                                break;
                                                                        }
                                                                }
                                                                runScript.setAccessible(true);
                                                                for (Class c : runScript.getParameterTypes()) {
                                                                        System.out.println(c);
                                                                }
                                                                Class pClass = runScript.getParameterTypes()[1];
                                                                Object pObj = pClass.getConstructor(Manifest).newInstance(script.getAnnotation(Manifest));
                                                                try {
                                                                        runScript.invoke(scriptHandler, activeScript, pObj);
                                                                        Logger.log(level, "Script Executed.");

                                                                        final Method canvasClazz = Reflect.method(Canvas, Canvas, Modifier.PUBLIC | Modifier.STATIC);
                                                                        canvasClazz.setAccessible(true);
                                                                        final Object canvas = canvasClazz.invoke(null);
                                                                        final Field toolbarClazz = Reflect.field(canvas.getClass(), Toolbar, Modifier.PUBLIC);
                                                                        toolbarClazz.setAccessible(true);

                                                                        final Object toolbar = toolbarClazz.get(canvas);
                                                                        final Method toolbarUpdate = toolbar.getClass().getDeclaredMethod(ToolbarUpdateMethod);
                                                                        if(toolbarUpdate != null) {
                                                                                toolbarUpdate.setAccessible(true);
                                                                                toolbarUpdate.invoke(toolbar);
                                                                        } else
                                                                                Logger.log(level, "Unable to update toolbar when loading script, this method requires manual updating.");
                                                                } catch(final Exception ignored) {
                                                                        Logger.log(level, "RSBot gave off an error while executing the script, make sure another isn't already running.");
                                                                }
                                                        }
                                                }
                                        } catch(final Exception _e) {
                                                _e.printStackTrace(System.err);
                                        }
                                }
                        });

                        final GroupLayout layout = new GroupLayout(this.getContentPane());
                        this.getContentPane().setLayout(layout);
                        layout.setHorizontalGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(layout.createSequentialGroup()
                                        .addComponent(scrollPane, GroupLayout.PREFERRED_SIZE, 183, GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(LayoutStyle.ComponentPlacement.UNRELATED).addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                                                        .addComponent(button1, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 93, Short.MAX_VALUE)
                                                        .addComponent(button2, GroupLayout.Alignment.TRAILING)
                                                        .addComponent(button3, GroupLayout.DEFAULT_SIZE, 93, Short.MAX_VALUE)).addContainerGap()));
                        layout.setVerticalGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(layout.createSequentialGroup()
                                        .addContainerGap().addComponent(button1).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(button2).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED, 7, Short.MAX_VALUE)
                                        .addComponent(button3).addContainerGap()).addComponent(scrollPane, GroupLayout.DEFAULT_SIZE, 104, Short.MAX_VALUE));

                        this.pack();
                }

                private DefaultTableModel getModel() {
                        final File scripts = new File("bin/");
                        final java.util.List<String> valid = new ArrayList();
                        if(scripts.exists()) {
                                for(final File file : scripts.listFiles()) {
                                        if(file.isFile() && !file.getName().contains("$") && file.getName().contains(".class")) {
                                                try {
                                                        final Class<?> clazz = loadClass(file);
                                                        if(clazz.getAnnotation(Manifest.class) != null)
                                                                valid.add(file.getName().replaceFirst("\\.class", ""));
                                                } catch(final Exception e) {
                                                        e.printStackTrace(System.err);
                                                }
                                        }
                                }
                                final Object[][] model = new Object[valid.size()][1];
                                for(int i = 0; i < valid.size(); i++)
                                        model[i][0] = valid.get(i);
                                return new DefaultTableModel(model, new String[]{"Script"}) {
                                        public final Class<?> getColumnClass(final int columnIndex) {
                                                return String.class;
                                        }

                                        public final boolean isCellEditable(final int rowIndex, final int columnIndex) {
                                                return false;
                                        }
                                };
                        }
                        return null;
                }
        }

        private static Class Manifest = null, ScriptDef = null, Bot = null, ActiveScript = null,
                        Canvas = null, Toolbar = null, Network = null, Socket = null, ScriptHandler = null;
        private static final String ToolbarUpdateMethod = "c";

}