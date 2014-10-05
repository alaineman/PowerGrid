/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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
package net.pgrid.loader;

import java.applet.Applet;
import java.applet.AppletContext;
import java.applet.AppletStub;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Insets;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;
import net.pgrid.loader.util.Logger;

/**
 * This class functions as the window in which the Applet can run.
 * 
 * It implements AppletStub to provide the Applet with a valid environment and
 * sets up the itself as a JFrame in which the Applet can draw.
 * 
 * @author Patrick Kramer
 */
public class AppletFrame extends JFrame implements AppletStub {

    /** The Logger instance of this class. */
    private static final Logger LOGGER = Logger.get("APPLET");
    
    /**
     * The JLabel that shows the logging message.
     */
    private JLabel label;
    private Applet applet = null;
    private RSVersionInfo info = null;

    /**
     * Creates a new AppletFrame instance.
     */
    public AppletFrame() {
        super("PowerGrid (Runescape client)");
        label = new JLabel();
    }

    /**
     * @return the loaded Applet, or null if no Applet is loaded.
     */
    public Applet getApplet() {
        return applet;
    }

    /**
     * Sets up the AppletFrame and shows it.
     */
    public synchronized void initComponents() {
        try {
            setIconImage(ImageIO.read(ClassLoader.getSystemResourceAsStream("net/pgrid/loader/icon.png")));
        } catch (IOException e) {
            LOGGER.log("Unexpected Exception", e);
            // Since the icon is embedded in the jar file, this should never happen
            throw new AssertionError("Cannot find jar resource");
        }
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        
        Insets in = getInsets();
        int bHeight = in.top + in.bottom;
        int bWidth = in.right + in.left;
        setSize(1056 + bWidth, 750 + bHeight);
        setMinimumSize(new Dimension(765 + bWidth, 540 + bHeight));
        setMaximumSize(new Dimension(3200 + bWidth, 1200 + bHeight));

        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        getContentPane().setBackground(Color.BLACK);

        label.setForeground(Color.GRAY.brighter());
        label.setFont(new Font("Consolas", Font.BOLD, 21));
        label.setHorizontalAlignment(JLabel.CENTER);
        add(label, "Center");

        setVisible(true);
    }

    /**
     * Takes the provided Applet instance and starts it in this Window.
     * 
     * @param info the RSVersionInfo object to use for getting parameters for the client
     * @param a the Applet to start (should not be null)
     * @return true if the Applet started without Exceptions, false if an Exception occurred.
     * @throws NullPointerException if the provided Applet is null.
     */
    public synchronized boolean startApplet(RSVersionInfo info, Applet a) {
        showMessage("Starting Applet");
        this.info = info;
        applet = a;
        applet.setStub(this);
        try {
            applet.init();
            getContentPane().add(applet, BorderLayout.CENTER);
            getContentPane().remove(label);
            label = null;
            revalidate();
            applet.start();
            LOGGER.log("Applet started");
            return true;
        } catch (RuntimeException e) {
            LOGGER.log("Failed to start client.", e);
            return false;
        }
    }
    
    /**
     * Shows the given log message in the AppletFrame.
     * 
     * If the client is already started, this method does nothing (as the 
     * message will never be visible anyway).
     * @param text the message to display
     */
    public synchronized void showMessage(final String text) {
        if (applet == null) {
            EventQueue.invokeLater(() -> label.setText(text));
        }
    }

    @Override
    public void appletResize(int width, int height) {}

    @Override
    public String getParameter(String name) {
        return info.getAppletParameter(name);
    }

    @Override
    public URL getDocumentBase() {
        String codebase = info.getClientParameter("codebase");
        if (codebase != null) {
            try {
                return new URL(codebase);
            } catch (MalformedURLException e) {
                // This normally never happens, as the codebase was validated when
                // the client was downloaded. The reason we don't throw 
                // anything here is, that we don't want to interfere 
                // with the running Runescape client.
                LOGGER.log("[WARNING] Applet requested codebase URL, but the codebase was invalid.", e);
            }
        }
        return null;
    }

    @Override
    public URL getCodeBase() {
        return getDocumentBase();
    }

    /**
     * Returns the AppletContext. 
     * 
     * Since the Runescape Applet does not care about this, this method will 
     * always return {@code null}.
     * @return {@code null}
     */
    @Override
    public AppletContext getAppletContext() {
        return null;
    }
}
