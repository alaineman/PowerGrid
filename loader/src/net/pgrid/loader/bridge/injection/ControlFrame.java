/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 * 
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
package net.pgrid.loader.bridge.injection;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import net.pgrid.loader.AppletFrame;
import net.pgrid.loader.AppletLoader;
import net.pgrid.loader.bridge.injection.keyboard.AbstractKeyInjector;
import net.pgrid.loader.bridge.injection.keyboard.KeyInjector;
import net.pgrid.loader.bridge.injection.keyboard.RobotKeyInjector;
import net.pgrid.loader.bridge.injection.keyboard.StringInjector;

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
        injector = StringInjector.wrap(ki);
        createAndShowFrame();
    }
    
    private void createAndShowFrame() {
        setLayout(new BorderLayout(12,12));
        textField.setPreferredSize(new Dimension(300, 32));
        submit.setPreferredSize(new Dimension(70, 32));
        delayField.setPreferredSize(new Dimension(370, 32));
        
        add(textField,  "North");
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
            add (delayField, "West");
        } else {
            // we add a filler component to ensure the correct layout
            Container c = new Container();
            c.setSize(delayField.getSize());
            add(c, "West");
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
