package powergrid.view.status;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JLabel;
import powergrid.PowerGrid;
import powergrid.view.PGPanel;

/**
 * Panel containing various settings that modify the way PowerGrid manages 
 * Plugins and deals with events and changes in the Runescape client.
 * @author Chronio
 */
public class SettingsPanel extends PGPanel {
    
    /** Using pseudo-optimal paths inserts noise into the PathFinder, which 
     *  reduces bot detection rate (in theory).
     */
    private JCheckBox usePseudoOptimalPaths;
    /** Simulating mouse movements should not affect the detection rate, but
     *  no one knows. Disabling it speeds up interactions, though.
     */
    private JCheckBox simulateMouseMovements;
    
    private JButton apply, cancel;
    
    /**
     * Creates a new SettingsPanel.
     */
    public SettingsPanel() {
        super(new GridBagLayout());
        usePseudoOptimalPaths = new JCheckBox("Use Pseudo-optimal paths");
        apply = new JButton("Apply");
        cancel = new JButton("Cancel");
    }
    
    @Override public SettingsPanel withPowerGrid(PowerGrid pg) {
        super.withPowerGrid(pg);
        return this;
    }
    
    @Override public SettingsPanel initialize() {
        super.initialize();
        
        GridBagConstraints gbc = new GridBagConstraints();
        
        usePseudoOptimalPaths.setSelected(true);
        simulateMouseMovements.setSelected(false);
        
        usePseudoOptimalPaths.setEnabled(false);
        simulateMouseMovements.setEnabled(false);
        
        gbc.gridx = gbc.gridy = 0;
        add(new JLabel("This panel allows modifying the way PowerGrid"
                + "deals with simulating various events and components.\n"
                + "Modifying these settings may increase performance, but may "
                + "also lead to higher detection rates. Use these settings with"
                + "care."), gbc);
        
        return this;
    }
}
