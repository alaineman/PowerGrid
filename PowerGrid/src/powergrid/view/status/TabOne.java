/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.view.status;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;

/**
 *
 * @author Vincent W
 */
public class TabOne extends JPanel {

    public TabOne() {
        setBorder(new EmptyBorder(5, 5, 5, 5));
        GridBagLayout gbl_contentPane = new GridBagLayout();
        gbl_contentPane.columnWidths = new int[]{0, 0};
        gbl_contentPane.rowHeights = new int[]{0, 0, 0, 0};
        gbl_contentPane.columnWeights = new double[]{1.0, Double.MIN_VALUE};
        gbl_contentPane.rowWeights = new double[]{0.0, 0.0, 1.0,
            Double.MIN_VALUE};
        setLayout(gbl_contentPane);

        JLabel lblNewLabel = new JLabel("Stati Info");
        GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
        gbc_lblNewLabel.insets = new Insets(0, 0, 5, 0);
        gbc_lblNewLabel.gridx = 0;
        gbc_lblNewLabel.gridy = 0;
        add(lblNewLabel, gbc_lblNewLabel);

        JSeparator separator = new JSeparator();
        GridBagConstraints gbc_separator = new GridBagConstraints();
        gbc_separator.insets = new Insets(0, 0, 5, 0);
        gbc_separator.fill = GridBagConstraints.HORIZONTAL;
        gbc_separator.gridx = 0;
        gbc_separator.gridy = 1;
        add(separator, gbc_separator);

        JTextArea textArea = new JTextArea();
        textArea.append("Test text");
        textArea.setEditable(false);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        GridBagConstraints gbc_textArea = new GridBagConstraints();
        gbc_textArea.fill = GridBagConstraints.BOTH;
        gbc_textArea.gridx = 0;
        gbc_textArea.gridy = 2;
        add(textArea, gbc_textArea);
    }
}
