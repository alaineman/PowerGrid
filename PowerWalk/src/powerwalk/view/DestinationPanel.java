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
 * @author Chronio
 */
public class DestinationPanel extends JPanel {
    
    private String destinationName = "Unknown";
    private Point destination = null;
    
    private JLabel name = new JLabel(destinationName);
    private JButton go = new JButton("go here");
    
    
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
                    Bot.getBot().travelTo(destination, true);
                }
            });
        }
        go.setPreferredSize(new Dimension(100,24));
        add(go,"East");
        add(name,"Center");
    }
    
    public Point getDestination() {
        return new Point(destination);
    }
    
    public String getDestinationName() {
        return destinationName;
    }
}
