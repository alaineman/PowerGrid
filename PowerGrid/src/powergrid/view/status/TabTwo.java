/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.view.status;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 *
 * @author Vincent W
 */
public class TabTwo extends JPanel implements ChangeListener, ActionListener {
    
    static JRadioButton cmdPrimus = null, cmdSecundus = null, cmdTertius = null;
    static ButtonGroup group = null;
    static JButton cmdButtonRun = null;    
    
    public TabTwo() {
        setLayout(new GridLayout(0, 1, 0, 0));

        cmdPrimus = new JRadioButton("Option 1");
        add(cmdPrimus);
        cmdPrimus.addChangeListener(this);

        cmdSecundus = new JRadioButton("Option 2");
        add(cmdSecundus);
        cmdSecundus.addChangeListener(this);

        cmdTertius = new JRadioButton("Option 3");
        add(cmdTertius);
        cmdTertius.addChangeListener(this);

        cmdButtonRun = new JButton("Run");
        add(cmdButtonRun);
        cmdButtonRun.addActionListener(this);

        group = new ButtonGroup();

        group.add(cmdPrimus);
        group.add(cmdSecundus);
        group.add(cmdTertius);
        
        
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
