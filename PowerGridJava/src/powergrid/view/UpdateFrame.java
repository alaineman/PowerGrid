package powergrid.view;

import java.io.IOException;
import java.util.logging.Level;
import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;
import powergrid.PowerGrid;
import powergrid.task.Task;

/**
 * Small Frame that is shown when updating. 
 * <p/>
 * It offers the possiblity to show the current progress using the 
 * <code>setMessage(String)</code> method.
 * @author Chronio
 */
public class UpdateFrame extends JFrame {
    
    private JLabel message = new JLabel("Preparing update...");
    
    /**
     * Creates a new UpdateFrame.
     */
    public UpdateFrame() {
        super("PowerGrid Updater");
        setupFrame();
    }
    
    private void setupFrame() {
        add(message);
        try {
            setIconImage(ImageIO.read(ClassLoader.getSystemResource(ControlPanel.ICON_PATH)));
        } catch (IOException e) {
            PowerGrid.LOGGER.log(Level.WARNING, "Failed to set icon", e);
        }
        setSize(320, 64);
        setLocationRelativeTo(null);
        setResizable(false);
        setVisible(true);
    }
    
    /**
     * Sets the display message on this UpdateFrame.
     * @param message the message to show
     */
    public void setMessage(String message) {
        this.message.setText(message);
    }

    @Override
    public void dispose() {
        setMessage("Restarting...");
        Task.sleep(1000);
        super.dispose();
    }
}
