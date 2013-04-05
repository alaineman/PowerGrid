package powergrid.view.status;

import com.bvscripting.bankedboner.FilledTitleTabbedPane;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.IOException;
import java.net.URL;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTabbedPane;
import javax.swing.KeyStroke;
import org.powerbot.core.Bot;

/**
 *
 * @author Vincent W
 */
public class StatusPanel extends JFrame implements ActionListener {

    static boolean start = false;
    static boolean isRunning = true;
    static JEditorPane mainPane = null;    
    static JTabbedPane basictab;
    
    static JMenuItem cmdRun = null;
    static JMenu cmdExtra = null;    
    static JMenuItem cmdClose = null;

    public StatusPanel() throws IOException {
        setName("Powergrid Stati Overview");
        setSize(720, 480);
        //setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setResizable(false);
        JMenuBar bar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        fileMenu.setMnemonic(KeyEvent.VK_F);
        bar.add(fileMenu);
        setJMenuBar(bar);
        setVisible(true);
        
        Image image1 = getImage("http://www.eclipse.org/equinox-portal/tutorials/server-side/images/RunIcon.png");
        ImageIcon runIcon = new ImageIcon(image1);
        cmdRun = new JMenuItem("Run", runIcon);
        cmdRun.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R,
                ActionEvent.CTRL_MASK));
        cmdRun.addActionListener(this);
        fileMenu.add(cmdRun);
        
        fileMenu.addSeparator();        
        
        cmdExtra = new JMenu("Info");
        cmdExtra.addActionListener(this);
        fileMenu.add(cmdExtra);        
        
        JMenuItem side1 = new JMenuItem("Will soon be added.");
        JMenuItem side2 = new JMenuItem("Same.");
        cmdExtra.add(side1);
        cmdExtra.add(side2);
        
        fileMenu.addSeparator();
        
        Image image4 = getImage("http://i48.tinypic.com/ifwhgl.png");
        ImageIcon exiticon = new ImageIcon(image4);
        cmdClose = new JMenuItem("Exit", exiticon); // file adds menu items
        cmdClose.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W,
                ActionEvent.CTRL_MASK));
        cmdClose.addActionListener(this);
        fileMenu.add(cmdClose);
        
        basictab = new FilledTitleTabbedPane();
        basictab.setBackground(Color.GRAY);
        basictab.add("Welcome", new TabOne());
        basictab.add("Stati", new TabTwo());
        basictab.add("Listeners", new TabOne());
        
        getContentPane().add(basictab, BorderLayout.CENTER);
        
        
    }   
    
    public static void main(String[] args){
        try {
            JFrame f = new StatusPanel();
            f.setVisible(true);
        } catch (IOException ex) {
            Logger.getLogger(StatusPanel.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    // Method to import
    static Image getImage(String url) {
        try {
            return ImageIO.read(new URL(url));
        } catch (IOException e) {
            return null;
        }
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        Object cmd = e.getSource();
            try {
                if (cmd == cmdClose) {
                    System.out
                            .println("Something wrong? Please contact us if it's a bug.");
                    //dispose...
                    Bot.context().getScriptHandler().stop();
                } else if (cmd == cmdRun) {
                }
            } catch (Exception f) {
                System.out.println(f.toString());
            }
    }
}
