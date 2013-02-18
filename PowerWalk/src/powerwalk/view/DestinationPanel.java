package powerwalk.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;
import powerwalk.Bot;
import powerwalk.model.Point;

/**
 * This Panel shows an available destination, and a button that orders the Bot 
 * to travel to this destination when clicked.
 * @author Chronio
 */
public class DestinationPanel extends JPanel {
    
    private String destinationName = "Unknown";
    private Point destination = null;
    
    private JLabel name = new JLabel(destinationName);
    private JButton go = new JButton("go here");
    
    /**
     * Create a new DestinationPanel with the specified name and destination.
     * @param name
     * @param dest 
     */
    public DestinationPanel(String name, Point dest) {
        if (name != null) {
            destinationName = name;
            this.name.setText(destinationName);
        }
        if (dest == null) {
            go.setText("not found");
            go.setEnabled(false);
            this.name.setText(destinationName + " (unavailable)");
        } else {
            destination = new Point(dest);
        }
        createAndShowGUI();
    }
    
    private void createAndShowGUI() {
        setLayout(new BorderLayout());
        setPreferredSize(new Dimension(250,24));
        setBorder(new LineBorder(Color.BLACK));
        
        // if there is a valid destination linked to this entry
        if (destination != null) {
            setBackground(Color.WHITE);
            go.addActionListener(new ActionListener() {
                @Override public void actionPerformed(ActionEvent e) {
                    Bot.travelTo(destination, 0);
                }
            });
        }
        go.setPreferredSize(new Dimension(100,24));
        add(go,"East");
        add(name,"Center");
    }
    
    /**
     * Returns the Destination linked to this DestinationPanel.
     * @return the Destination linked to this DestinationPanel
     */
    public Point getDestination() {
        return new Point(destination);
    }
    
    /**
     * Returns the name associated with the linked Destination.
     * @return the name associated with the linked Destination
     */
    public String getDestinationName() {
        return destinationName;
    }
}
