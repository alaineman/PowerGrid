package powerwalk.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.Set;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.border.LineBorder;
import powerwalk.Bot;
import powerwalk.model.Destinations;

/**
 * Concept GUI layout for PowerWalk.
 * Uses active searching to search for matching destinations in the destinationList.
 * @author P.Kramer
 */
public class MainFrame extends JFrame {
    
    private JTextField destinationField = new JTextField();
    private JPanel entryList = new JPanel();
    
    public static void main(String[] args) { new MainFrame(); }
    
    public MainFrame() {
        createAndShowGUI();
    }
    
    private void createAndShowGUI() {
        setLayout(new BorderLayout());
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JPanel top = new JPanel();
        top.setLayout(new BorderLayout());
        top.add(new JLabel("  destination: "),"West");
        top.add(destinationField,"Center");
        
        add(top,"North");
        
        entryList.setLayout(new GridBagLayout());
        entryList.setBackground(Color.WHITE);
        
        destinationField.addKeyListener(new KeyListener() {
            @Override public void keyTyped(KeyEvent ke) {
                SwingUtilities.invokeLater(new Runnable() {
                    @Override public void run() {
                        setResults(destinationField.getText());
                    }
                });
            }
            @Override public void keyPressed(KeyEvent ke) {}
            @Override public void keyReleased(KeyEvent ke) {}
        });
        
        setResults("");
        
        add(entryList,"Center");
        
        setSize(480,320);
        setVisible(true);
    }
    
    
    
    private void setResults(String query) {
        entryList.removeAll();
        ArrayList<String> results = new ArrayList<>();
        query = query.toLowerCase();
        
        Set<String> ds = Destinations.getAvailableDestinations();
        for (String s : ds) {
            s = s.toLowerCase();
            if (s.contains(query)) {
                results.add(s);
            }
        }
        
        System.out.println("Results: " + results);
        
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx=0;
        gbc.gridy=0;
        gbc.weightx=1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        
        for (String dest : results) {
            entryList.add(createEntryFromLocation(dest));
            gbc.gridy++;
        }
        revalidate();
    }
    
    private JPanel createEntryFromLocation(final String name) {
        // Note: name is final here because it needs to be used in an inner class.
        
        JPanel entry = new JPanel();
        entry.setBackground(Color.LIGHT_GRAY);
        entry.setBorder(new LineBorder(Color.BLACK));
        entry.setLayout(new BorderLayout());
        
        JButton travel = new JButton("Travel here");
        travel.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent ae) {
                Bot.getBot().travelTo(name,true);
            }
        });
        entry.add(new JLabel("  " + name),"Center");
        entry.add(travel,"East");
        entry.setPreferredSize(new Dimension(120,24));
        return new JPanel();
    }
}
