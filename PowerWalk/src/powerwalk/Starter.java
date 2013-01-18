package powerwalk;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.logging.*;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.LineBorder;
import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import org.powerbot.game.api.methods.Environment;
import powerwalk.control.Mapper;
import powerwalk.control.XMLToolBox;
import powerwalk.model.Destinations;
import powerwalk.model.XMLNode;
import powerwalk.tasks.StepTask;
import powerwalk.tasks.Task;
import powerwalk.view.ContentFrame;
import powerwalk.view.MapViewer;

/**
 * Starter and Task Manager class for the entire plug-in.
 *
 * @author Chronio
 * @author Alaineman
 */
@Manifest(
        authors        = { "Alaineman" , "Chronio" },
        name           = Starter.productName,
        description    = "Runs all day!",
        version        = Starter.version,
        singleinstance = true)
public class Starter extends ActiveScript {
    
    private static boolean isStarted = false;
    
    public static final Logger theLogger = Logger.getLogger(Starter.class.getName());
    private static boolean loggerOk = false; // set to true when logger initialized
    public static final String worldMapFile = "worldmap.xml";
    /** The name of the Plug-in */
    public static final String productName = "PowerWalk";
    /** The version number */
    public static final double version = 0.1;
    private static Task currentTask = null;
    
    private static boolean DEV_MODE = false;
    
    /* Placeholder for controlpanel handle */
    private static ControlPanel theControlPanel = null;
    
    /**
     * Creates a ContentFrame instance and shows it.
     */
    @Override public void onStart() {
        setLoggerFormatAndHandlers();
        
        logMessage("Loading required resources...");
        
        try (FileInputStream worldMapIn = new FileInputStream(Environment.getStorageDirectory().toString() + "\\" + worldMapFile)) {
            XMLNode worldMap = XMLToolBox.getXMLTree(worldMapIn);
            Bot.getBot().getWorldMap().fillFromXML(worldMap);
            logMessage("WorldMap loaded");
        } catch (FileNotFoundException e) {
            logMessage("WorldMap file does not exist; starting with empty WorldMap");
            try { new File(Environment.getStorageDirectory().toString() + "\\" + worldMapFile).createNewFile(); }
            catch (IOException iox) {
                logMessage("The worldMap file could not be created. Map data will not be saved",iox);
            }
        } catch (IOException e) {
            logMessage("WorldMap failed to load",e);
        }
        Mapper.startMapping(Mapper.MAP_CONTINOUSLY);
        
        // Load Quest data directly from Noticeboard, since Quest class doesn't seem to work properly
        //Quests.updateQuestData(); // try not to, it's really annoying
        
        // try to run a implementing script, if it exists
        (new Thread() {
            @Override public void run() {
                try { init(); }
                catch (RuntimeException e) {
                    Starter.logMessage("No script loaded on top of PowerWalk, running stand-alone");
                }
            }
        }).start();
        ContentFrame.theFrame = new ContentFrame();
        logMessage("PowerWalk started, waiting for tasks...");
        isStarted = true;
        if (theControlPanel != null) theControlPanel.notifyStateChange(isStarted);
    }

    /**
     * This method is intended for scripters who want to build their script on
     * the PowerWalk API, and should be overridden to start their own script.
     * <p/>
     * This method is called on a separate Thread, so
     * any methods calls made from this method will be asynchronous with PowerWalk
     * or RSBot.
     * <p/>
     * It is not advised to build scripts on RSBot's script loader when intending
     * to use PowerWalk. Instead, scripts that use PowerWalk should override
     * this method to start their script.
     * <p/>
     * Furthermore, scripts that are run from this method should implement a
     * looping mechanism themselves, since the script will end once this method
     * returns.
     * <p/>
     * @throws RuntimeException when calling this method without having overridden it.
     */
    public void init() {
        throw new RuntimeException("no implementing subclass");
    }
    
    /**
     * executes a Task from the TaskQueue.
     *
     * @return an integer specifying the amount of milliseconds the caller
     * should wait before calling this method again.
     */
    @Override public int loop() {
        if (Bot.getBot().tasksPending() > 0) {
            currentTask = Bot.getBot().retrieveTask();
            if (currentTask instanceof StepTask) {
                StepTask task = (StepTask) currentTask;
                logMessage("Beginning StepTask \"" + task.getName() + "\"...","TaskManager");
                task.start();
                while (task.hasMoreSteps()) {
                    task.execute();
                }
                task.finish();
                logMessage("StepTask \"" + task.getName() + "\" has ended","TaskManager");
            } else {
                logMessage("Beginning Task \"" + currentTask.getName() + "\"...","TaskManager");
                currentTask.execute();
                logMessage("Task \"" + currentTask.getName() + "\" has ended.","TaskManager");
            }
            currentTask = null;
            return 20;
        } else {
            return 10;
        }
    }

    /**
     * Ensures the Mapper is stopped and the ContentFrame is destroyed. Also
     * cleans up as much objects related to PowerWalk as possible.
     */
    @Override public void onStop() {
        logMessage("stopping PowerWalk...");
        Bot.getBot().becomeIdle();
        Mapper.stopMapping();
        if (ContentFrame.theFrame != null) {
            ContentFrame.theFrame.dispose();
            ContentFrame.theFrame = null;
        }
        purge(); // free all data structures and objects they contain
        System.gc(); // running Garbage Collector to ensure any potentially problematic objects (Readers/Writers, Task instances, etc..) are finalized and destroyed
        logMessage("PowerWalk has been terminated");
        
        isStarted = false;
        if (theControlPanel != null) theControlPanel.notifyStateChange(isStarted);
    }

    /**
     * returns the currently running task.
     *
     * @return the currently running task, or null is no task is running
     */
    public static Task currentTask() {
        return currentTask;
    }

    /**
     * removes non-essential data structures and reduces the size of essential
     * data structures in order to free memory or speed up general performance.
     *
     * <p>Since most non-essential data structures are used for caching, calling
     * this method repeatedly will cause reduction of performance.</p>
     *
     * <p>Furthermore, after calling this method, some smaller data structures
     * will be automatically rebuilt when performing actions on the Bot, and
     * these action may be slower due to missing / reduced caches.</p>
     */
    public synchronized static void purge() {
        // purge the destination list used by the travelTo(String dest) command
        Destinations.purge();

        // purge the World Map (takes potentially long)
        Bot.getBot().getWorldMap().purge();

        logMessage("The caches have been purged");
    }

    /**
     * Logs a message to the console. The message will be prefixed by "[PowerWalk] "
     * <p>The logged message will have a logging level identical to <code>Level.INFO</code></p>
     * @param message the message to log
     */
    public static void logMessage(String message) {
        if (!loggerOk) setLoggerFormatAndHandlers();
        theLogger.info(message);
    }
    
    /**
     * Logs the given message to the console. The message will be prefixed by "[PowerWalk] ".
     * <p>Group specifies the name that must be displayed along with the message</p>
     * @param message the message to log
     * @param group the group to display for this message
     */
    public static void logMessage(String message,String group) {
        if (!loggerOk) setLoggerFormatAndHandlers();
        theLogger.log(Level.INFO,message,group);
    }
    
    /**
     * Logs the given message to the console. The message will be prefixed by "[PowerWalk] ".
     * <p>Group specifies the name that must be displayed along with the message</p>
     * <p>t specifies the Throwable that caused the message, if any</p>
     * @param message the message to log
     * @param group the group to display for this message
     * @param t the Throwable that caused the message
     */
    public static void logMessage(String message,String group, Throwable t) {
        if (!loggerOk) setLoggerFormatAndHandlers();
        theLogger.log(Level.INFO,message,new Object[] {group,t});
    }
    
    public static void logMessage(String message,Throwable t) {
        if (!loggerOk) setLoggerFormatAndHandlers();
        theLogger.log(Level.INFO,message,new Object[]{null,t});
    }
    
    public static void main(String[] args) {
        setLoggerFormatAndHandlers();
        
        
        ArrayList<String> params = new ArrayList<>(args.length);
        for (String param : args) {
            switch (param) {
                case "-pwdebug":
                    DEV_MODE = true;
                    logMessage("Powerwalk started in developer mode");
                    break;
                default:
                    params.add(param);
            }
        }
        
        // start RSBot
        Starter.logMessage("Loading RSBot");
        org.powerbot.Boot.main(params.toArray(new String[0]));
        Starter.logMessage("RSBot loaded, modifying RSBot JFrame");
        
        // set our awesome custom controls to the JFrame
        SwingUtilities.invokeLater(new Runnable() {
            @Override public void run() {
                for (Window w : Window.getWindows()) {
                    if (w instanceof JFrame) {
                        JFrame theFrame = (JFrame)w;
                        if (!theFrame.getTitle().startsWith("RSBot"))
                            continue;
                        // Canvas used to draw the RSBot environment on is inside a JRootPane in the "Center" 
                        // area of a BorderLayout applied to the JFrame.
                        // because of this, it is possible to add controls to the north, 
                        // west, east and south of the JRootPane by assigning JPanels 
                        // to those areas of the BorderLayout.
                        theControlPanel = new ControlPanel();
                        
                        Dimension frameSize = theFrame.getSize();
                        frameSize.height += theControlPanel.getPreferredSize().height; // resize the frame to make room for the controlpanel
                        theFrame.setSize(frameSize);
                        theFrame.setMinimumSize(frameSize);
                        
                        theFrame.add(theControlPanel,"South");
                        // we replace RSBot's logo with our own and adapt the title a little
                        URL url = ClassLoader.getSystemResource("icon_small.png");
                        theFrame.setTitle(theFrame.getTitle() + " (running through PowerWalk)");
                        try { theFrame.setIconImage(ImageIO.read(url)); 
                        Starter.logMessage("The PowerWalk Control panel has been successfully added to the RSBot JFrame");
                        } 
                        catch (IOException | IllegalArgumentException e) {
                            Starter.logMessage("Error while setting JFrame icon",e);
                        }
                        break;
                    }
                }
            }
        });
    }
    
    /**
     * The control panel that appears below the RSBot window when launching through this class
     */
    public static class ControlPanel extends JPanel {
        public static final Dimension buttonSize = new Dimension(180,32);
        
        private JLabel messageBox = new JLabel("  PowerWalk is not started");
        private JButton showMap = new JButton("Show PowerWalk map");
        private JButton toggleMapping = new JButton("Disable Mapping");
        public ControlPanel() {
            super(new BorderLayout(5,3));
            createAndShowGUI();
        }
        private void createAndShowGUI() {
            setBackground(Color.BLACK);
            setBorder(new LineBorder(Color.WHITE,2));
            setPreferredSize(new Dimension(300,72));
            messageBox.setFont(new Font(messageBox.getFont().getName(),Font.BOLD,14));
            messageBox.setForeground(Color.WHITE);
            messageBox.setHorizontalAlignment(JLabel.CENTER);
            
            messageBox.setPreferredSize(new Dimension(300,30));
            showMap.setPreferredSize(buttonSize);
            toggleMapping.setPreferredSize(buttonSize);
            JButton starter = ScriptLoader.pwLoader.createPlayButton();
            starter.setPreferredSize(buttonSize);
            
            toggleMapping.setEnabled(false);
            
            JPanel buttons = new JPanel();
            buttons.setOpaque(false);
            buttons.add(showMap);
            buttons.add(toggleMapping);
            buttons.add(starter);
            
            add(buttons,"North");
            add(messageBox,"Center");
            
            showMap.addActionListener(new ActionListener() {
                @Override public void actionPerformed(ActionEvent ae) {
                    if (isStarted) { // if it's started we can use the existing world map
                        MapViewer.showMapViewer();
                    } else { // else we have to load the world map first
                        MapViewer.showMapViewerStandAlone(false);
                    }
                }
            });
            toggleMapping.addActionListener(new ActionListener() {
                @Override public void actionPerformed(ActionEvent e) {
                    if (Mapper.isMapping()) {
                        Mapper.stopMapping();
                        toggleMapping.setText("Enable Mapping");
                    } else {
                        Mapper.startMapping(Mapper.MAP_CONTINOUSLY);
                        toggleMapping.setText("Disable Mapping");
                    }
                }
            });
        }
        
        public void setMessage(String msg) {
            if (msg != null) 
                messageBox.setText("  Status:  " + msg);
        }
        
        public void notifyStateChange(boolean state) {
            toggleMapping.setEnabled(state);
            if (state) setMessage("PowerWalk started");
            else setMessage("PowerWalk stopped");
        }
    }
    
    private static void setLoggerFormatAndHandlers() {
        if (loggerOk) return;
        theLogger.setUseParentHandlers(false);
        ConsoleHandler handler = new ConsoleHandler();
        handler.setFormatter(new Formatter() {
            @Override public String format(final LogRecord record) {
                Object[] params = record.getParameters();
                StringBuilder sb = new StringBuilder("[PowerWalk");
                if (params != null && params.length > 0 && params[0] != null) {
                    sb.append(" > ").append(record.getParameters()[0]);
                }
                sb.append("] ").append(record.getMessage()).append("\r\n");
                if (params != null && params.length > 1 && params[1] instanceof Throwable) {
                    Throwable t = (Throwable)params[1];
                    sb.append("      caused by ").append(t.getClass().getSimpleName());
                    sb.append(": ").append(t.getMessage()).append("\r\n");
                    if (DEV_MODE) {
                        // print stack trace
                        StackTraceElement[] traces = t.getStackTrace();
                        for (StackTraceElement e : traces) {
                            sb.append("        at ").append(e.getClassName()).append(".");
                            sb.append(e.getMethodName()).append(": ");
                            int ln = e.getLineNumber();
                            if (ln > 0) 
                                sb.append(e.getLineNumber());
                            else // line numbers less than 0 are invalid
                                sb.append("(unknown line number)");
                            sb.append("\r\n");
                        }
                    }
                }
                return sb.toString();
            }
        });
        theLogger.addHandler(handler);
        loggerOk = true;
    }
}
