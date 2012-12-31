package powerwalk.view;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import powerwalk.Starter;

/**
 * This JFrame provides a user-friendly way of accessing the functionality of 
 * the PowerWalk plug-in.
 * It contains buttons for issuing travel commands, and to view information about 
 * the current state of the Bot.
 * @author Chronio
 */
public class ContentFrame extends JFrame {
    
    /**
     * Creates a ContentFrame instance without loading the plug-in
     * @param args the command-line arguments, which are ignored
     */
    public static void main(String args[]) {
        theFrame = new ContentFrame();
    }
    
    /**
     * Contains the currently visible ContentFrame.
     * If no ContentFrame is visible, this field is null
     */
    public static ContentFrame theFrame = null;
    
    private JButton travel = new JButton("Travel to...");
    private JButton view = new JButton("View Map");
    
    private JPanel content = new JPanel();
    
    /*
     * Creates a new ContentFrame and shows it.
     */
    public ContentFrame() {
        super("PowerWalk - version " + Starter.version);
        createAndShowGUI();
    }
    
    private void createAndShowGUI() {
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setLayout(new BorderLayout());
        JPanel buttons = new JPanel();
        buttons.setLayout(new GridLayout(1,2));
        buttons.add(travel);
        buttons.add(view);
        
        // add a WindowListener to ask for confirmation before closing the Frame
        addWindowListener(new WindowAdapter() {
            @Override public void windowClosing(WindowEvent e) {
                if (JOptionPane.YES_OPTION == JOptionPane.showConfirmDialog(null, 
                        "Warning: Once this window is closed, it cannot be opened anymore.\n"
                      + "Do you really want to close the window?", "Are you sure?", 
                        JOptionPane.YES_NO_OPTION, JOptionPane.WARNING_MESSAGE)) {
                    dispose();
                    theFrame = null;
                }
            }
        });
        
        travel.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent e) {
                setPanel(new TravelPanel());
            }
        });
        
        view.addActionListener(new ActionListener() {
            @Override public void actionPerformed(ActionEvent e) {
                MapViewer.showMapViewer();
            }
        });
        
        add(buttons,"North");
        add(content,"Center");
        
        setSize(280,240);
        setResizable(false);
        setVisible(true);
    }
    
    /**
     * Sets the visible panel on the ContentFrame
     * @param panel 
     */
    public void setPanel(JPanel panel) {
        if (panel != null) {
            //view.setEnabled(true); // XXX uncomment after view action has been implemented
            travel.setEnabled(true);
            remove(content);
            content = panel;
            add(content,"Center");
            
            if (panel instanceof TravelPanel) 
                travel.setEnabled(false);
            //if (panel instanceof ViewPanel) // XXX uncomment after view action has been implemented
            //    view.setEnabled(false);
            
            revalidate();
        }
    }
}
