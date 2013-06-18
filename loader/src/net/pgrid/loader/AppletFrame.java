package net.pgrid.loader;

import java.applet.Applet;
import java.applet.AppletContext;
import java.applet.AppletStub;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.DisplayMode;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.Insets;
import java.awt.Toolkit;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 * This class functions as the window in which the Runescape Applet can run.
 * <p/>
 * It implements AppletStub to provide the Applet with a valid environment and
 * sets up the itself as a JFrame in which the Applet can draw.
 * <p/>
 * @author Chronio
 */
public class AppletFrame extends JFrame implements AppletStub {

    private GraphicsDevice device = null;
    
    private DisplayMode fullscreenMode = null;
    private DisplayMode windowedMode = null;
    
    private boolean fullscreen = false;
    
    private JLabel label;
    private Applet theApplet = null;
    private ClientDownloader dloader = null;

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
        createAndShowFrame();
        device = GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice();
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        fullscreenMode = new DisplayMode(screenSize.width, screenSize.height, 32, 60);
        windowedMode = device.getDisplayMode();
    }

    /**
     * Sets up the AppletFrame and shows it.
     */
    private void createAndShowFrame() {
        label = new JLabel();

        setTitle("Runescape (running through PowerGrid)");
        try {
            setIconImage(ImageIO.read(ClassLoader.getSystemResourceAsStream("net/pgrid/loader/icon.png")));
        } catch (IOException e) {
            Logger.describe(e);
        }
        getToolkit().setDynamicLayout(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Insets in = getInsets();
        int bHeight = in.top + in.bottom;
        int bWidth = in.right + in.left;
        setSize(1056 + bWidth, 600 + bHeight);
        setMinimumSize(new Dimension(765 + bWidth, 540 + bHeight));
        setMaximumSize(new Dimension(3200 + bWidth, 1200 + bHeight));

        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        getContentPane().setBackground(Color.BLACK);


        label.setForeground(Color.GRAY.brighter());
        label.setFont(new Font("Consolas", Font.BOLD, 21));
        label.setHorizontalAlignment(JLabel.CENTER);
        getContentPane().add(label);
        showMessage("Loading client...");

        setVisible(true);

        createBufferStrategy(2);
    }

    /**
     * Takes the provided Applet instance and starts it in this Window.
     *
     * @param a the Applet to start (should not be null)
     */
    public void startApplet(Applet a) {
        showMessage("Starting Applet");
        theApplet = a;
        theApplet.setStub(this);
        try {
            theApplet.init();
            theApplet.start();
        } catch (Throwable t) {
            if (AppletLoader.theLoader.isQuickload()) {
                // Might need to reload the client data...
                AppletLoader.theLoader = new AppletLoader(false);
                AppletLoader.theLoader.run();
                theApplet = AppletLoader.theLoader.getApplet();
                theApplet.setStub(this);
                theApplet.init();
                theApplet.start();
            } else {
                Logger.describe(t);
            }
        }
        getContentPane().add(theApplet, BorderLayout.CENTER);
        getContentPane().remove(label);
        revalidate();
    }

    /**
     * Shows the given log message in the AppletFrame and also logs it to the
     * console using
     * <code>Logger.log(text)</code>.
     *
     * @param text the message to display
     * @see pgloader.Logger
     */
    public void showMessage(final String text) {
        Logger.log(text);
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                label.setText(text);
            }
        });
    }

    @Override
    public void appletResize(int width, int height) {
    }

    @Override
    public final String getParameter(String name) {
        String value = dloader.getParameter(name);
        return value;
    }

    @Override
    public final URL getDocumentBase() {
        try {
            return new URL(dloader.getCodebase());
        } catch (MalformedURLException e) {
            return null;
        }
    }

    @Override
    public final URL getCodeBase() {
        try {
            return new URL(dloader.getCodebase());
        } catch (MalformedURLException e) {
            return null;
        }
    }

    @Override
    public final AppletContext getAppletContext() {
        return null;
    }
    
    /**
     * Sets whether to display in full screen mode. 
     * @param fullscreen true for full screen, false for windowed mode.
     */
    public void setFullscreen(boolean fullscreen) {
        if (this.fullscreen != fullscreen) {
            this.fullscreen = fullscreen;
            if (fullscreen) {
                setVisible(false);
                dispose();
                
                setUndecorated(true);
                device.setFullScreenWindow(this);
                device.setDisplayMode(fullscreenMode);
            } else {
                device.setDisplayMode(windowedMode);
                setVisible(false);
                dispose();
                
                setUndecorated(false);
                setSize(1056, 600);
                setLocationRelativeTo(null);
                
                setVisible(true);
            }
            repaint();
        }
    }
}
