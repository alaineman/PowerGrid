package powergrid.view;

import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Control Panel that allows control and overview of PowerGrid functionality.
 * <p/>
 * It provides buttons to show the World map, PowerGrid's state, and also provides
 * access to available scripts.
 * <p/>
 * @author Chronio
 */
public class ControlPanel extends JPanel {
    
    /**
     * Creates a new ControlPanel and adds it to the given JFrame.
     * <p/>
     * An option can be given that will be used as the option parameter in the 
     * <code>Container.add(Component,Object)</code> method.
     * <p/>
     * If null is passed as the target, a new JFrame with a BorderLayout is created.
     * In that case, the option will always be taken as "Center".
     * <p/>
     * @param target the target JFrame. null means a new JFrame will be created.
     * @param addOption the add option. null means no option will be used.
     * @return the ControlPanel instance that was added to the JFrame.
     */
    public static ControlPanel addControlPanel(JFrame target, Object addOption) {
        ControlPanel cp = new ControlPanel();
        if (target == null) {
            target = new JFrame("PowerGrid controls");
            target.setLayout(new BorderLayout());
            target.add(cp,"Center");
            target.pack();
            target.setVisible(true);
        } else {
            if (addOption == null) 
                target.add(cp);
            else
                target.add(cp,addOption);
        }
        return cp;
    }
    
    public static final Dimension buttonSize = new Dimension(160,28);
    
    private JButton showWorldMap = new JButton("Show Worldmap");
    private JButton runScripts = new JButton("Scripts/Tasks");
    private JButton showStatus = new JButton("Show PG status");
    
    public ControlPanel() {
        super(new BorderLayout());
        setupPanel();
    }
    
    private void setupPanel() {
        showWorldMap.setPreferredSize(buttonSize);
        runScripts.setPreferredSize(buttonSize);
        showStatus.setPreferredSize(buttonSize);
        
        showWorldMap.addActionListener(new MapViewer());
        runScripts.addActionListener(null);
        showStatus.addActionListener(null);
        
        add(showWorldMap,"West");
        add(runScripts,"East");
        add(showStatus,"Center");
        
        setPreferredSize(new Dimension(buttonSize.width*3+12,buttonSize.height+8));
    }
}
