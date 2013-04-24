package powergrid.view;

import java.awt.BorderLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Set;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import powergrid.model.structure.DestinationMap;
import powergrid.model.Point;

/**
 * This Panel shows the available destinations and allows the user to search 
 * for specific entries using a text field.
 * @author Chronio
 */
public class TravelPanel extends JPanel {
    
    private JTextField destination = new JTextField();
    
    private JPanel entries = new JPanel();
    private JScrollPane scrollpane = new JScrollPane(entries);
    
    private DestinationMap dests = null;
    
    /**
     * Creates a new TravelPanel instance and sets up the destination list.
     */
    public TravelPanel(DestinationMap dests) {
        assert dests != null;
        this.dests = dests;
        createAndShowGUI();
    }
    
    private void createAndShowGUI() {
        setLayout(new BorderLayout());
        
        JPanel top = new JPanel();
        top.setLayout(new BorderLayout());
        top.add(new JLabel("Destination: "),"West");
        top.add(destination,"Center");
        add(top,"North");
        
        scrollpane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        scrollpane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        add(scrollpane,"Center");
        
        entries.setLayout(new GridBagLayout());
        
        destination.addKeyListener(new KeyListener() {
            @Override public void keyTyped(KeyEvent ke) {
                SwingUtilities.invokeLater(new Runnable() {
                    @Override public void run() {
                        setData(destination.getText());
                    }
                });
            }
            @Override public void keyPressed(KeyEvent ke) {}
            @Override public void keyReleased(KeyEvent ke) {}
        });
        setData("");
    }
    
    /**
     * Filters the available Destinations to show only those that match the given query
     * @param query the query to use as a filter
     */
    public void setData(String query) {
        entries.removeAll();
        query = query.toLowerCase();
        
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx=0;
        gbc.gridy=0;
        gbc.weightx=1;
        gbc.insets.top = 2;
        Set<String> names = dests.destinationNames();
        for (String name : names) {
            Point p = dests.getPoint(name);
            if (p != null && name.toLowerCase().contains(query)) {
                entries.add(new DestinationPanel(name,p),gbc);
                gbc.gridy++;
            }
        }
        // fill remaining space
        gbc.weighty = 1;
        gbc.fill = GridBagConstraints.BOTH;
        entries.add(new JPanel(),gbc);
        
        revalidate();
    }
}
