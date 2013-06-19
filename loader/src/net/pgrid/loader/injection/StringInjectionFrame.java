package net.pgrid.loader.injection;

import net.pgrid.loader.injection.keyboard.KeyInjector;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import net.pgrid.loader.AppletFrame;
import net.pgrid.loader.AppletLoader;

/**
 * Frame containing a JTextfield and a submit button to test injecting Strings
 * into the Runescape Applet.
 * 
 * @author Chronio
 */
public class StringInjectionFrame extends JFrame {

    private KeyInjector injector;
    
    private JTextField field = new JTextField();
    private JButton submit = new JButton("Submit");
    
    public StringInjectionFrame() {
        super("Type a String and press Submit");
        createAndShowFrame();
    }
    
    private void createAndShowFrame() {
        setLayout(new BorderLayout(12,12));
        field.setPreferredSize(new Dimension(300, 32));
        submit.setPreferredSize(new Dimension(120, 24));
        
        add(field, "North");
        add(submit, "South");
        
        pack();
        AppletFrame frame = AppletLoader.theGUI;
        if (frame == null) {
            setLocationRelativeTo(null);
        } else {
            setLocation(frame.getX() + frame.getWidth(), frame.getY());
        }
        
        submit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String text = field.getText();
                for (char c : text.toCharArray()) {
                    injector.keyTyped(c, WIDTH, WIDTH);
                }
            }
        });
        
        setVisible(true);
    }
}
