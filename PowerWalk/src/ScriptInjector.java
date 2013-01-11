import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.Serializable;
import java.lang.annotation.Annotation;
import java.lang.reflect.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.List;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;
import java.util.logging.*;
import java.util.logging.Formatter;
import javax.swing.*;

/**
 * @author Float [powerbot.org]
 */
public class ScriptInjector {

    private static final String RSBOT_DICTIONARY = "..\\lib\\RSBot.jar"; // = "C:\\Users\\Public\\Documents\\RSBot\\RSBot.jar"; - EXAMPLE (This is not a requirement if rsbot is in project folder)
    private static final boolean DEV_MODE = true; //true runs RSBot.jar with the -dev flag, false doesn't

    private static final Logger logger = Logger.getLogger(ScriptInjector.class.getName());

    public static void main(String[] args) {
        File rsbot = null;
        if(RSBOT_DICTIONARY != null)
            rsbot = new File(RSBOT_DICTIONARY);
        else {
            List<File> possible = getContent(new File("./"));
            if(possible != null && possible.size() > 0) {
                for(File file : possible)
                    if(file != null && file.exists() && file.isFile() && file
                            .getName().toLowerCase().contains("rsbot")) {
                        String name = file.getName().toLowerCase();
                        if(name.contains("rsbot") && name.endsWith(".jar")) {
                            rsbot = file;
                            break;
                        }
                    }
            }
        }
        logger.setUseParentHandlers(false);

        ConsoleHandler handler = new ConsoleHandler();
        handler.setFormatter(new Formatter() {
            private DateFormat df = new SimpleDateFormat("hh:mm:ss");

            @Override
            public String format(LogRecord record) {
                StringBuilder builder = new StringBuilder();
                String[] source = record.getSourceClassName().split("\\$");
                builder.append("[").append(df.format(new Date(record.getMillis()))).append("]");
                builder.append("[").append(source[source.length - 1]).append(".");
                builder.append(record.getSourceMethodName()).append("] ");
                builder.append(super.formatMessage(record)).append("\n");
                return builder.toString();
            }
        });
        logger.addHandler(handler);
        if(rsbot != null && rsbot.exists()) {
            logger.info("Located RSBot, retrieving class files.");
            URLClassLoader loader = null;
            try {
                loader = URLClassLoader.newInstance(new URL[]{rsbot.toURI().toURL()});
            } catch(MalformedURLException e) {
                logger.log(Level.WARNING, "{0}: {1}", new Object[]{e.getClass().getName(), e.getMessage()});
            }
            if(loader == null) {
                logger.severe("Unable to load RSBot, stopping.");
            } else {
                if(getRSBotClasses(rsbot, loader)) {
                    logger.info("Loaded all of the necessary RSBot classes.");
                    logger.log(Level.INFO, "Loading RSBot, Developer Mode: {0}", DEV_MODE);
                    try {
                        Class<?> mainClazz = loader.loadClass("powerwalk.Starter");
                        if(mainClazz != null) {
                            Method mainMethod = mainClazz.getDeclaredMethod("main", String[].class);
                            if(mainMethod != null) {
                                mainMethod.setAccessible(true);
                                if (DEV_MODE) {
                                    ArrayList<String> l = new ArrayList<>(Arrays.asList(args));
                                    l.add("-dev");
                                    args = l.toArray(new String[0]);
                                }
                                mainMethod.invoke(null,(Object)args);
                            }
                        }
                    } catch(ClassNotFoundException | NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
                        e.printStackTrace(System.err);
                        logger.severe("Unable to start RSBot, stopping.");
                        return;
                    }
                    try {
                        Method getCanvas = Reflect.getMethod(Canvas, Canvas);
                        Object canvas = getCanvas.invoke(null);
                        if(canvas != null) {
                            Field getToolbar = Reflect.getField(canvas.getClass(), Toolbar);
                            Object toolbar = getToolbar.get(canvas);
                            for(Field field : toolbar.getClass().getDeclaredFields()) {
                                if(field.getType() != null && JLabel.class.isAssignableFrom(field.getType())
                                        && MouseListener.class.isAssignableFrom(field.getType())) {
                                    field.setAccessible(true);
                                    JLabel label = (JLabel) field.get(toolbar);
                                    if(label != null && label.getToolTipText() != null && label
                                            .getToolTipText().toLowerCase().contains("script")) {
                                        for(MouseListener ml : label.getMouseListeners())
                                            label.removeMouseListener(ml);
                                        label.addMouseListener(new MouseAdapter() {
                                            @Override
                                            public void mousePressed(MouseEvent e) {
                                                new ScriptListener(e.getWhen(), "ScriptListener", null).start();
                                            }
                                        });
                                        label.addMouseListener((MouseListener) label);

                                        logger.info("RSBot successfully loaded. ScriptInjector has officially started.");
                                        break;
                                    }
                                }
                            }
                        }
                    } catch(IllegalAccessException | InvocationTargetException e) {
                        e.printStackTrace(System.err);
                    }
                } else logger.severe("Unable to load all of RSBots needed class files, stopping.");
            }
        } else {
            logger.severe("Unable to locate RSBot.jar, please specify a dictionary in the ScriptInjector class.");
        }
    }

    private static List<File> getContent(final File dict) {
        List<File> list = new ArrayList<>();
        if(dict != null && dict.exists()) {
            File[] files = dict.listFiles();
            if(files != null && files.length > 0)
                for(File file : files) {
                    if(file.isDirectory())
                        list.addAll(getContent(file));
                    else {
                        list.add(file);
                    }
                }
        }
        return list;
    }

    @SuppressWarnings("unchecked")
    private static boolean getRSBotClasses(final File rsbot, final URLClassLoader loader) {
        try {
            JarInputStream jar = new JarInputStream(new FileInputStream(rsbot));
            while(true) {
                try {
                    JarEntry entry = jar.getNextJarEntry();
                    if(entry == null)
                        break;
                    else if(entry.getName().endsWith(".class")) {
                        Class<?> clazz = loader.loadClass(entry.getName().replaceAll("/", "\\.").replaceAll("\\.class", ""));
                        if(clazz != null) {
                            if(clazz.getName().endsWith(".Bot"))
                                logger.info("[Class] Bot[" + (Bot = clazz).getName() + "] class loaded.");
                            if(clazz.getName().endsWith(".Script"))
                                logger.info("[Class] Script[" + (Script = clazz).getName() + "] class loaded.");
                            if(clazz.getName().endsWith(".Manifest"))
                                logger.info("[Class] Manifest[" + (Manifest = (Class<? extends Annotation>) clazz).getName() + "] class loaded.");
                            if(clazz.getName().endsWith(".ScriptHandler"))
                                logger.info("[Class] ScriptHandler[" + (ScriptHandler = clazz).getName() + "] class loaded.");
                            if(JFrame.class.isAssignableFrom(clazz) && WindowListener.class.isAssignableFrom(clazz))
                                logger.info("[Class] Canvas[" + (Canvas = clazz).getName() + "] class loaded.");
                            if(JToolBar.class.isAssignableFrom(clazz))
                                logger.info("[Class] Toolbar[" + (Toolbar = clazz).getName() + "] class loaded.");
                            if(Comparable.class.isAssignableFrom(clazz) && Serializable.class.isAssignableFrom(clazz)
                                    && clazz.getModifiers() == (Modifier.PUBLIC | Modifier.FINAL))
                                logger.info("[Class] ScriptDef[" + (ScriptDef = clazz).getName() + "] class loaded.");
                            if(ArrayList.class.isAssignableFrom(clazz)) {
                                logger.info("[Class] AccList[" + (AccList = clazz).getName() + "] class loaded.");
                                final Class<?>[] classes = AccList.getDeclaredClasses();
                                if(classes != null && classes.length == 1)
                                    logger.info("[Class] AccInfo[" + (AccInfo = classes[0]).getName() + "] class loaded.");
                            }
                            if(JDialog.class.isAssignableFrom(clazz) && ActionListener.class.isAssignableFrom(clazz)) {
                                for(final Field field : clazz.getDeclaredFields())
                                    if(field != null && (field.getModifiers() & Modifier.STATIC) != 0) {
                                        field.setAccessible(true);
                                        final Object obj;
                                        try {
                                            obj = field.get(null);
                                            if(obj != null && obj instanceof Logger) {
                                                logger.info("[Class] ScriptSelector[" + (ScriptSelector = clazz).getName() + "] class loaded.");
                                                for(final Class<?> subject : ScriptSelector.getDeclaredClasses()) {
                                                    if(subject != null && JPanel.class.isAssignableFrom(subject))
                                                        logger.info("[Class] ScriptPanel[" + (ScriptPanel = subject).getName() + "] class loaded.");
                                                }
                                                break;
                                            }
                                        } catch(final IllegalAccessException e) {
                                            e.printStackTrace(System.err);
                                        }
                                    }
                            }
                        }
                    }
                } catch(final IOException | ClassNotFoundException e) {
                    e.printStackTrace(System.err);
                }
            }
            return ScriptSelector != null && Manifest != null && Toolbar != null && Canvas != null && Script != null && AccInfo != null
                    && ScriptDef != null && Bot != null && AccList != null && ScriptHandler != null && ScriptPanel != null;
        } catch(final IOException e) {
            e.printStackTrace(System.err);
        }
        return false;
    }

    private static class Reflect {

        private static Field getField(final Class<?> clazz, final Class<?> returnType) {
            for(final Field field : clazz.getDeclaredFields()) {
                if(field.getType() != null && field.getType().equals(returnType)) {
                    field.setAccessible(true);
                    return field;
                }
            }
            return null;
        }

        private static Constructor getConstructor(final Class<?> clazz, final Class<?>... params) {
            try {
                return clazz.getConstructor(params);
            } catch(final NoSuchMethodException e) {
                e.printStackTrace(System.err);
            }
            return null;
        }

        private static Method getMethod(final Class<?> clazz, final Class<?> returnType, final Class<?>... params) {
            for(final Method method : clazz.getDeclaredMethods()) {
                if(method.getReturnType().equals(returnType) && Arrays.equals(method.getParameterTypes(), params)) {
                    method.setAccessible(true);
                    return method;
                }
            }
            return null;
        }
    }

    private static class ScriptRunner implements ActionListener {

        private final Object scriptDef;
        private final Class<?> scriptClazz;
        private final JDialog scriptSelector;

        private ScriptRunner(final Class<?> scriptClazz, final JDialog scriptSelector, final Object scriptDef) {
            this.scriptDef = scriptDef;
            this.scriptClazz = scriptClazz;
            this.scriptSelector = scriptSelector;
        }

        @Override
        public void actionPerformed(final ActionEvent e) {
            final Object manifest = scriptClazz.getAnnotation(Manifest);
            if(manifest != null) {
                try {
                    final Method method = manifest.getClass().getMethod("name");
                    method.setAccessible(true);
                    logger.info("Loading injected script: " + method.invoke(manifest));

                    final Object script = scriptClazz.asSubclass(Script).newInstance();
                    if(script != null) {
                        scriptSelector.dispose();
                        final Method getInstance = Reflect.getMethod(Bot, Bot);
                        final Object bot = getInstance.invoke(null);
                        if(bot != null) {
                            //account
                            final Method setAccount = Reflect.getMethod(bot.getClass(), Void.TYPE, AccInfo);
                            setAccount.invoke(bot, (Object) null);
                            String currentAcc = null;
                            for(final Field field : scriptSelector.getClass().getDeclaredFields())
                                if(field != null && field.getType().equals(JButton.class)) {
                                    field.setAccessible(true);
                                    final JButton button = (JButton) field.get(scriptSelector);
                                    if(button.getText() != null && button.getText().trim().length() > 0)
                                        currentAcc = button.getText();
                                }
                            final Method getAccList = Reflect.getMethod(AccList, AccList);
                            for(final Object acc : (List<?>) getAccList.invoke(null)) {
                                final Method toString = acc.getClass().getDeclaredMethod("toString");
                                if(!((String) toString.invoke(acc)).equalsIgnoreCase(currentAcc))
                                    continue;
                                setAccount.invoke(bot, acc);
                                break;
                            }
                            //script
                            final Method getHandler = Reflect.getMethod(bot.getClass(), ScriptHandler);
                            final Object handler = getHandler.invoke(bot);
                            final Method startMethod = Reflect.getMethod(handler.getClass(), Boolean.TYPE, Script, ScriptDef);
                            startMethod.invoke(handler, script, scriptDef);
                            logger.info("Script successfully loaded and executed with " + currentAcc);
                        } else logger.severe("No bot running. Script execution failed.");
                    } else logger.severe("Unable to instantiate script.");
                } catch(final NoSuchMethodException | InvocationTargetException | IllegalAccessException | InstantiationException e1) {
                    e1.printStackTrace(System.err);
                }
            } else logger.severe("Error getting script manifest.");
        }

    }

    private static class ScriptListener extends Thread {

        private final long start;
        private JDialog scriptSelector = null;

        private ScriptListener(final long start, final String title, final JDialog scriptSelector) {
            super(title);
            this.start = start;
            this.scriptSelector = scriptSelector;
            for(final Thread thread : Thread.getAllStackTraces().keySet()) {
                if(thread.getName().equals(this.getName()))
                    thread.interrupt();
            }
        }

        @Override
        public void run() {
            while(System.currentTimeMillis() - start < 4000 && !this.isInterrupted()) {
                if(scriptSelector == null)
                    for(final Window window : Window.getWindows())
                        if(window != null && window.isVisible() && window instanceof JDialog) {
                            final JDialog dialog = (JDialog) window;
                            if(dialog.getTitle() != null && dialog.getTitle().startsWith("Scripts")) {
                                scriptSelector = dialog;
                                for(final Field field : scriptSelector.getClass().getDeclaredFields()) {
                                    if(field.getType() != null && JButton.class.isAssignableFrom(field.getType())) {
                                        field.setAccessible(true);
                                        try {
                                            final JButton button = (JButton) field.get(scriptSelector);
                                            if(button.getToolTipText() != null && button.getToolTipText().toLowerCase().contains("refresh"))
                                                button.addActionListener(new ActionListener() {
                                                    @Override
                                                    public void actionPerformed(final ActionEvent e) {
                                                        new ScriptListener(e.getWhen(), "ScriptListener", scriptSelector).start();
                                                    }
                                                });
                                        } catch(final IllegalAccessException e) {
                                            e.printStackTrace(System.err);
                                        }
                                    }
                                }
                                break;
                            }
                        }
                if(scriptSelector != null) {
                    logger.info("ScriptSelector detected, manually adding scripts to display.");
                    scriptSelector.setTitle("ScriptInjector: Loading scripts...");

                    final Class<?>[] scripts = getScripts();
                    if(scripts != null && scripts.length > 0) {
                        final Constructor constructor = Reflect.getConstructor(ScriptDef, Manifest);
                        if(constructor != null) {
                            final Map<Class<?>, Object> scriptDef = new HashMap<>(scripts.length);
                            constructor.setAccessible(true);
                            for(final Class<?> clazz : scripts)
                                if(clazz.isAnnotationPresent(Manifest) && Script.isAssignableFrom(clazz)) {
                                    try {
                                        scriptDef.put(clazz, constructor.newInstance(clazz.getAnnotation(Manifest)));
                                    } catch(final InstantiationException | IllegalAccessException | InvocationTargetException e) {
                                        e.printStackTrace(System.err);
                                    }
                                }
                            if(scriptDef.size() > 0) {
                                JPanel panel = null;
                                for(final Field field : scriptSelector.getClass().getDeclaredFields())
                                    if(field.getType() != null && field.getType().equals(JPanel.class)) {
                                        field.setAccessible(true);
                                        try {
                                            panel = (JPanel) field.get(scriptSelector);
                                        } catch(final IllegalAccessException e) {
                                            e.printStackTrace();
                                        }
                                    }
                                if(panel != null) {
                                    final Constructor sectionConst = Reflect.getConstructor(ScriptPanel, ScriptSelector, Component.class, ScriptDef);
                                    if(sectionConst != null) {
                                        sectionConst.setAccessible(true);
                                        for(final Class<?> clazz : scriptDef.keySet()) {
                                            final Object obj = scriptDef.get(clazz);
                                            try {
                                                final JPanel section = (JPanel) sectionConst.newInstance(scriptSelector, panel, obj);
                                                if(section != null) {
                                                    final JButton button = getJButton(section);
                                                    if(button != null) {
                                                        for(final ActionListener al : button.getActionListeners())
                                                            button.removeActionListener(al);
                                                        button.addActionListener(new ScriptRunner(clazz, scriptSelector, obj));
                                                    }
                                                    panel.add(section);
                                                }
                                            } catch(final InstantiationException | IllegalAccessException | InvocationTargetException e) {
                                                e.printStackTrace(System.err);
                                            }
                                        }
                                        panel.validate();
                                        panel.repaint();
                                    }
                                } else logger.severe("Unable to find JPanel to place scripts on!");
                            }
                        }
                    } else logger.severe("No scripts available, or error reading scripts.");
                    try {
                        final Field getPanel = Reflect.getField(scriptSelector.getClass(), JPanel.class);
                        final JPanel panel = (JPanel) getPanel.get(scriptSelector);
                        for(final Component inner : panel.getComponents()) {
                            if(inner != null && inner instanceof JPanel) {
                                for(final Component comp : ((Container) inner).getComponents())
                                    if(comp != null && comp instanceof JProgressBar) {
                                        inner.setVisible(false);
                                        break;
                                    }
                            }
                        }
                    } catch(final IllegalAccessException e) {
                        e.printStackTrace(System.err);
                    }
                    scriptSelector.setTitle("ScriptInjector: Scripts successfully displayed");
                    break;
                } else {
                    try {
                        Thread.sleep(50l);
                    } catch(final InterruptedException ignored) {
                    }
                }
            }
        }

        private JButton getJButton(final JPanel panel) {
            for(final Component comp : panel.getComponents())
                if(comp != null) {
                    if(comp instanceof JPanel) {
                        final JButton button = getJButton((JPanel) comp);
                        if(button != null)
                            return button;
                    } else if(comp instanceof JButton)
                        return (JButton) comp;
                }
            return null;
        }

        private static Class<?>[] getScripts() {
            final File bin = new File("./build/classes"), out = new File("./out");
            final File[] content = (bin.exists() ? bin : out).listFiles();
            final List<Class<?>> scripts = new ArrayList<>();
            if(content != null && content.length > 0) {
                for(final File file : content) {
                    URLClassLoader loader = null;
                    try {
                        loader = URLClassLoader.newInstance(new URL[]{file.toURI().toURL()});
                    } catch(final MalformedURLException e) {
                        e.printStackTrace(System.err);
                    }
                    if(loader == null)
                        continue;
                    final List<File> innerContent = file.isDirectory() ? getContent(file) : Arrays.asList(file);
                    for(final File inner : innerContent)
                        if(inner != null && inner.exists() && inner.getName().toLowerCase().endsWith(".class")) {
                            try {
                                final Class<?> clazz = loader.loadClass(inner.getCanonicalPath().replace(file.getCanonicalPath()
                                        .replace(file.getName(), ""), "").replaceAll("\\\\", "\\.").replace(".class", ""));
                                if(clazz != null && Script.isAssignableFrom(clazz))
                                    scripts.add(clazz);
                            } catch(final ClassNotFoundException | IOException e) {
                                e.printStackTrace(System.err);
                            }
                        }
                }
                return scripts.toArray(new Class<?>[scripts.size()]);
            }
            return null;
        }
    }

    private static Class<?> ScriptSelector, Toolbar, Canvas, Script, ScriptDef, Bot, AccList, ScriptHandler, ScriptPanel, AccInfo;
    private static Class<? extends Annotation> Manifest;

}