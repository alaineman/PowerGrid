package powergrid.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.InvocationTargetException;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.LineBorder;
import powergrid.PowerGrid;
import powergrid.plugins.Plugin;
import powergrid.plugins.PluginInfo;
import powergrid.task.Configurable;
import powergrid.task.Task;

/**
 * This Panel shows all available tasks of each Loaded Plugin.
 * @author Chronio
 */
public class TaskPanel extends PGPanel {
    
    /**
     * The size (in pixels) of the icons displayed before each Task entry.
     */
    public static final int ICON_SIZE = 32;
    
    /**
     * Creates a new TaskPanel.
     */
    public TaskPanel () {
        super(new BorderLayout());
    }
    
    @Override 
    public TaskPanel withPowerGrid(PowerGrid pg) {
        super.withPowerGrid(pg);
        return this;
    }
    
    @Override
    public TaskPanel initialize() {
        super.initialize();
        
        JPanel entries = new JPanel (new GridBagLayout());
        JScrollPane scrollPane = new JScrollPane(entries);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        
        GridBagConstraints gbc = new GridBagConstraints();
        entries.setPreferredSize(new Dimension(250,200));
        Dimension dim = new Dimension(300,240);
        setMinimumSize(dim);
        setPreferredSize(dim);
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        
        ImageIcon defaultIcon = new ImageIcon(new ImageIcon(
                ClassLoader.getSystemResource(Plugin.DEFAULT_PLUGIN_ICON))
                .getImage().getScaledInstance(ICON_SIZE, ICON_SIZE, Image.SCALE_SMOOTH));
        for (Plugin p : getPowerGrid().getPlugins()) {
            String name = p.getClass().getAnnotation(PluginInfo.class).name();
            ImageIcon icon = p.getPluginIcon();
            if (icon == null) {
                icon = defaultIcon;
            } else {
                icon = new ImageIcon(icon.getImage()
                        .getScaledInstance(ICON_SIZE, ICON_SIZE, Image.SCALE_SMOOTH));
            }
            for (Class<? extends Task> c : p.getPublicTasks()) {
                entries.add(new TaskEntry(icon, name, c), gbc);
                gbc.gridy++;
            }
        }
        gbc.weighty=1;
        gbc.fill = GridBagConstraints.BOTH;
        entries.add(new Container(),gbc);
        add(entries,"Center");
        
        return this;
    }
    
    /**
     * A JPanel placed on the TaskPanel to represent a single Task.
     */
    public class TaskEntry extends JPanel {
        private Icon icon = null;
        private String pluginName = "Unknown Plugin";
        private Class<? extends Task> task = null;
        
        /**
         * Constructs a new TaskEntry with the specified information.
         * @param icon the Icon to use for the entry
         * @param pluginName the pluginName to display
         * @param t the Task class this entry represents
         */
        public TaskEntry(Icon icon, String pluginName, Class<? extends Task> t) {
            super(new BorderLayout(4, 0));
            if (t == null)
                throw new IllegalArgumentException("Null-value for Task");
            task = t;
            this.icon = icon;
            if (pluginName != null)
                this.pluginName = pluginName;
            setupPanel();
        }
        
        private void setupPanel() {
            JLabel iconLabel = new JLabel(icon);
            JLabel name = new JLabel(task.getSimpleName() + "  (" + pluginName + ")");
            JButton run = new JButton("run");
            iconLabel.setPreferredSize(new Dimension(ICON_SIZE, ICON_SIZE));
            run.setPreferredSize(new Dimension(60,24));
            setPreferredSize(new Dimension(240, Math.max(32, ICON_SIZE)));
            add(iconLabel, "West");
            add(name, "Center");
            add(run, "East");
            
            setBorder(new LineBorder(Color.BLACK));
            setBackground(Color.WHITE);
            
            run.addActionListener(new ActionListener() {
                @Override public void actionPerformed(ActionEvent ae) {
                    try {
                        Task t = task.getConstructor().newInstance();
                        
                        if (t instanceof Configurable) {
                            Configurable cfg = (Configurable)t;
                            TaskConfigurationPanel configPanel = cfg.configPanel();
                            ConfigureFrame frame = new ConfigureFrame(configPanel);
                            frame.setLocationByPlatform(true);
                            frame.setVisible(true);
                        } else {
                            if (JOptionPane.showConfirmDialog(null, "Run the Task \"" + task.getName() + "\"?", "Run this Task", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE)
                                    == JOptionPane.YES_OPTION) {
                                getPowerGrid().taskManager().assignTask(t);
                            }
                        }
                    } catch (NoSuchMethodException | IllegalAccessException | InstantiationException | InvocationTargetException e) {
                        JOptionPane.showMessageDialog(null, "The Task could not be instantiated.", "Error creating Task", JOptionPane.ERROR_MESSAGE);
                    }
                }
            });
        }
    }
}
