package powergrid.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
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
    public static ControlPanel addControlPanel(Container target, Object addOption) {
        ControlPanel cp = new ControlPanel();
        if (target == null) {
            JFrame f = new JFrame("PowerGrid controls");
            f.setLayout(new BorderLayout());
            f.add(cp,"Center");
            f.pack();
            f.setVisible(true);
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
    
    private JLabel messageArea = new JLabel("PowerGrid is not yet started");
    
    public ControlPanel() {
        super(new GridBagLayout());
        setupPanel();
    }
    
    private void setupPanel() {
        setBackground(Color.BLACK);
        /*showStatus.setBackground(Color.BLACK);
        runScripts.setBackground(Color.BLACK);
        showWorldMap.setBackground(Color.BLACK);*/
        
        messageArea.setForeground(Color.WHITE);
        
        
        
        showWorldMap.setPreferredSize(buttonSize);
        runScripts.setPreferredSize(buttonSize);
        showStatus.setPreferredSize(buttonSize);
        
        showWorldMap.addActionListener(new MapViewer());
        runScripts.addActionListener(null);
        showStatus.addActionListener(null);
        
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.fill = GridBagConstraints.BOTH;
        gbc.weightx = 1;
        add(showWorldMap,gbc);
        gbc.gridx++;
        add(runScripts,gbc);
        gbc.gridx++;
        add(showStatus,gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        add(messageArea,gbc);
        
        setPreferredSize(new Dimension(buttonSize.width*3+12,buttonSize.height+24));
    }
    
    public void setMessage(String message) {
        if (message != null)
            messageArea.setText(message);
    }
    
    public String getMessage() {
        return messageArea.getText();
    }
}
