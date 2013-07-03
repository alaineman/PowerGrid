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

    private static final Logger LOGGER = Logger.get("CORE");
    
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
        label = new JLabel();
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
        setTitle("Runescape (running through PowerGrid)");
        try {
            setIconImage(ImageIO.read(ClassLoader.getSystemResourceAsStream("net/pgrid/loader/icon.png")));
        } catch (IOException e) {
            LOGGER.describe(e);
        }
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Insets in = getInsets();
        int bHeight = in.top + in.bottom;
        int bWidth = in.right + in.left;
        setSize(1056 + bWidth, 600 + bHeight);
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
     * If for any reason the Applet throws an Exception, this method tries to load the client using the AppletLoader's runSafe method.
     * @param a the Applet to start (should not be null)
     * @return true if the Applet started without Exceptions, false if an Exception occurred.
     * @throws NullPointerException if the provided Applet is null.
     */
    public boolean startApplet(Applet a) {
        showMessage("Starting Applet");
        theApplet = a;
        theApplet.setStub(this);
        try {
            theApplet.init();
            theApplet.start();
            getContentPane().add(theApplet, BorderLayout.CENTER);
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
    public void appletResize(int width, int height) {
    }

    @Override
    public final String getParameter(String name) {
        return dloader.getParameter(name);
    }

    @Override
    public final URL getDocumentBase() {
        return dloader.getCodeBaseUrl();
    }

    @Override
    public final URL getCodeBase() {
        return dloader.getCodeBaseUrl();
    }

    @Override
    public final AppletContext getAppletContext() {
        return null;
    }
    
    /**
     * Convenience method for toggling full screen mode.
     */
    public void toggleFullscreen() {
        setFullscreen(!fullscreen);
    }
    
    public boolean isFullScreenSupported() {
        return device.isFullScreenSupported();
    }
    
    /**
     * Sets whether to display in full screen mode. 
     * @param fullscreen true for full screen, false for windowed mode.
     */
    public void setFullscreen(boolean fullscreen) {
        if (this.fullscreen != fullscreen) {
            if (fullscreen) {
                if (!isFullScreenSupported()) {
                    LOGGER.log("Fullscreen mode not supported in this Virtual Machine");
                    return;
                }
                setVisible(false);
                dispose();
                
                setUndecorated(true);
                device.setFullScreenWindow(this);
                device.setDisplayMode(fullscreenMode);
                setResizable(false);
            } else {
                setResizable(true);
                device.setDisplayMode(windowedMode);
                device.setFullScreenWindow(null);
                setVisible(false);
                dispose();
                
                setUndecorated(false);
                setSize(1056, 600);
                
                setLocationRelativeTo(null);
                
                setVisible(true);
            }
            this.fullscreen = fullscreen;
            repaint();
        }
    }
}
