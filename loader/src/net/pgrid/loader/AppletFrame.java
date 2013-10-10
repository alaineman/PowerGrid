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
package net.pgrid.loader;

import java.applet.Applet;
import java.applet.AppletContext;
import java.applet.AppletStub;
import java.awt.BorderLayout;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Insets;
import java.io.IOException;
import java.net.URL;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 * This class functions as the window in which the Applet can run.
 * <p/>
 * It implements AppletStub to provide the Applet with a valid environment and
 * sets up the itself as a JFrame in which the Applet can draw.
 * <p/>
 * @author Patrick Kramer
 */
public class AppletFrame extends JFrame implements AppletStub {

    private static final Logger LOGGER = Logger.get("CORE");
        
    protected JLabel label;
    private Applet applet = null;
    private transient ClientDownloader dloader = null;

    /**
     * Initializes the AppletFrame with the specified the ClientDownloader.
     * <p/>
     * The ClientDownloader instance will be used to provide the Applet running
     * inside this AppletFrame with parameters. It also provides the codebase
     * information to the Applet.
     * <p/>
     * When this method returns the AppletFrame has been correctly set up and
     * made visible.
     * <p/>
     * @param dl the ClientDownloader instance containing the configuration
     * info.
     */
    public void init(ClientDownloader dl) {
        assert dloader == null;
        dloader = dl;
        label = new JLabel();
        createAndShowFrame();
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
    private void createAndShowFrame() {
        setTitle("Runescape (running through PowerGrid loader)");
        try {
            setIconImage(ImageIO.read(ClassLoader.getSystemResourceAsStream("net/pgrid/loader/icon.png")));
        } catch (IOException shouldNotHappen) {}
        
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
        showMessage("Loading client...");

        setVisible(true);

        createBufferStrategy(2);
    }

    /**
     * Takes the provided Applet instance and starts it in this Window.
     * <p/>
     * @param a the Applet to start (should not be null)
     * @return true if the Applet started without Exceptions, false if an Exception occurred.
     * @throws NullPointerException if the provided Applet is null.
     */
    public boolean startApplet(Applet a) {
        showMessage("Starting Applet");
        applet = a;
        applet.setStub(this);
        try {
            applet.init();
            applet.start();
            getContentPane().add(applet, BorderLayout.CENTER);
            getContentPane().remove(label);
            revalidate();
            LOGGER.log("Applet started");
            return true;
        } catch (Throwable t) {
            LOGGER.log("Failed to start client.");
            LOGGER.describe(t);
            setIgnoreRepaint(false);
            return false;
        }
    }
    
    /**
     * Finds and returns the Applet drawing Canvas.
     * <p/>
     * If either the Applet is null, or no Canvas is found, this method returns
     * null.
     * <p/>
     * This method is relatively slow, so consider caching the result instead
     * of calling this method repeatedly.
     * @return the Applet Canvas, or null if it wasn't found.
     */
    public Canvas getCanvas() {
        if (applet != null) {
            // We look for a Canvas instance inside the Applet's Component
            // hierarchy. This makes the Canvas accessible to external 
            // applications for drawing overlays, for example.
            synchronized (applet.getTreeLock()) {
                for (Component c : applet.getComponents()) {
                    if (c instanceof Canvas) {
                        return (Canvas) c;
                    }
                }
            }
        }
        LOGGER.log("No Canvas found in Applet.");
        return null;
    }

    /**
     * Shows the given log message in the AppletFrame and also logs it to the
     * console using
     * <code>LOGGER.log(text)</code>.
     *
     * @param text the message to display
     * @see pgloader.Logger
     */
    public void showMessage(final String text) {
        LOGGER.log(text);
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                label.setText(text);
            }
        });
    }

    @Override
    public void appletResize(int width, int height) {}

    @Override
    public String getParameter(String name) {
        return dloader.getAppletParameter(name);
    }

    @Override
    public URL getDocumentBase() {
        return dloader.getCodeBaseUrl();
    }

    @Override
    public URL getCodeBase() {
        return dloader.getCodeBaseUrl();
    }

    @Override
    public AppletContext getAppletContext() {
        // The AppletContext is not explicitly required to run the Applet, so 
        // we can safely return null here.
        return null;
    }
    
}
