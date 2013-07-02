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
        
        add(new JLabel("Type a String and click send to send it to the Applet. "
                + "You can change the character delay using the lower field"), "North");
        add(textField,  "West");
        add(submit,     "East");
        add(delayField, "South");
        
        pack();
        final AppletFrame frame = AppletLoader.theGUI;
        if (frame == null) {
            setLocationRelativeTo(null);
        } else {
            setLocation(frame.getX() + frame.getWidth(), frame.getY());
        }
        
        submit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Thread( new Runnable() {
                    @Override
                    public void run() {
                        int i = 0;
                        try {
                            i = Integer.parseInt(delayField.getText());
                        } catch (NumberFormatException e) {}
                        RobotKeyInjector inj = (RobotKeyInjector) injector.getInjector();
                        inj.setCharacterDelay(i);
                        injector.typeString(textField.getText());
                    }
                }, "StringInjector").start();
            }
        });
        
        if (frame != null) {
            delayField.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    frame.toggleFullscreen();
                    frame.revalidate();
                }
            });
        } else {
            delayField.setEnabled(false);
        }
        setVisible(true);
    }
}
