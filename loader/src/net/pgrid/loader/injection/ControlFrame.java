package net.pgrid.loader.injection;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import net.pgrid.loader.AppletFrame;
import net.pgrid.loader.AppletLoader;
import net.pgrid.loader.injection.keyboard.AbstractKeyInjector;
import net.pgrid.loader.injection.keyboard.KeyInjector;
import net.pgrid.loader.injection.keyboard.RobotKeyInjector;
import net.pgrid.loader.injection.keyboard.StringInjector;

/**
 * Frame providing various functions to directly control the various components 
 * that act on the Applet at runtime.
 * 
 * @author Chronio
 */
public class ControlFrame extends JFrame {

    private StringInjector injector;
    
    private JTextField textField = new JTextField();
    private JButton submit = new JButton("Send");
    private JTextField delayField = new JTextField("0");
    
    public ControlFrame(KeyInjector ki) {
        super("PowerGrid development Control Panel");
        injector = new StringInjector(ki);
        createAndShowFrame();
    }
    
    private void createAndShowFrame() {
        setLayout(new BorderLayout(12,12));
        textField.setPreferredSize(new Dimension(500, 32));
        submit.setPreferredSize(new Dimension(100, 32));
        delayField.setPreferredSize(new Dimension(600, 32));
        
        add(textField,  "West");
        add(submit,     "East");
        
        submit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Hmm... Anonymus inner class inside an anonymus inner class...
                // might need to refactor this for readability...
                new Thread( new Runnable() {
                    @Override
                    public void run() {
                        KeyInjector ki = injector.getInjector();
                        if (ki instanceof AbstractKeyInjector) {
                            int n = 0;
                            try {
                                n = Integer.parseInt(delayField.getText());
                            } catch (NumberFormatException e) {}
                            AbstractKeyInjector robInjector = (AbstractKeyInjector) ki;
                            robInjector.setDuration(n);
                        }
                        injector.typeString(textField.getText());
                    }
                }, "StringInjector").start();
            }
        });
        
        // Setting the typing duration only works if our Injector supports it.
        if (injector.isDurationSupported()) {
            add (delayField, "South");
        }
        
        pack();
        AppletFrame frame = AppletLoader.theGUI;
        if (frame == null) {
            setLocationRelativeTo(null);
        } else {
            setLocation(frame.getX() + frame.getWidth(), frame.getY());
        }
        setVisible(true);
    }
    
    
}
