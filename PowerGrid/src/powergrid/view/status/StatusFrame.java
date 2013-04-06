package powergrid.view.status;

import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;
import powergrid.PowerGrid;

// NOTE especially in GUI components, Javadoc should not be omitted, because 
//      Swing initialize code tends to get messy, and Javadoc helps to keep 
//      things clear.
/**
 * The Frame that holds the main status information of PowerGrid.
 * @author Chronio
 */
public class StatusFrame extends JFrame {
    
    // NOTE defining the PowerGrid instance as a member makes it easier to 
    //      change the implementation details later without scanning through 
    //      the code.
    private PowerGrid pg;
    
    // TODO define fields as members that are used as main control components
    private JPanel content;
    
    /**
     * Creates a new StatusFrame.
     */
    public StatusFrame() {
        // NOTE The GUI is not set up here. This is because a Java principle is
        //      that the constructor should only construct. Setting up the GUI 
        //      is done in the initialize method. Also note that even though 
        //      This object has prerequirements in order to work as expected,
        //      construction never fails.
        super("PowerGrid status"); // Directly sets the given String as title
        pg = null;
        content = new JPanel(); // TODO change to default JPanel
    }
    
    /**
     * Sets the PowerGrid instance to show the information of.
     * <p/>
     * This method should only be called once.
     * @param p the PowerGrid instance
     * @return itself for fluency
     */
    public StatusFrame withPowerGrid(PowerGrid p) {
        // NOTE Having a setup or initialize method return itself is useful 
        //      during instantiation. It is nice to be able to say this:
        //        StatusFrame f = new StatusFrame()
        //                          .withPowerGrid(pg)
        //                          .initialize();
        //      So it allows you to put any amount of options in between of the
        //      form withXXX(XXX option), to easily chain a series of commands 
        //      together in a single statement that configures the entire 
        //      object at once.
        assert pg == null && p != null;
        pg = p;
        return this;
    }
    
    /**
     * @return the used PowerGrid instance
     */
    public PowerGrid getPowerGrid() {
        return pg;
    }
    
    /**
     * Sets the content of this StatusFrame.
     * @param content the new content
     * @return the old content
     */
    public JPanel setContent(JPanel content) {
        // NOTE creating a setter like this makes it easier to make a dynamic 
        //      GUI without the GUI classes becoming messy and hard to read. 
        //      This works around a common problem that using Swing produces 
        //      messy code. 
        assert content != null;
        JPanel oldContent = this.content;
        remove(oldContent);
        this.content = content;
        add(content, BorderLayout.CENTER);
        return oldContent;
    }
    
    /**
     * @return the content of this StatusFrame.
     */
    public JPanel getContent() {
        // NOTE it is almost never wrong to add a getter for an important GUI 
        //      component. There is almost always a use for it.
        return content;
    }
    
    /**
     * Initializes and sets up the Frame.
     * @return itself for fluency
     */
    public StatusFrame initialize() {
        // NOTE we verify here that the StatusFrame is properly configured 
        //      (in this case, a PowerGrid instance is set). This ensures that
        //      the object is properly configured before setting up the GUI.
        if (getPowerGrid() == null) {
            throw new IllegalStateException("PowerGrid instance undefined");
        }
        
        // NOTE BorderLayout makes it easy to add a top bar and bottom bar that 
        //      display global information, and also makes it easy to change the 
        //      center area's content (see method setContent(JPanel)).
        setLayout(new BorderLayout());
        
        // NOTE a common mistake is to disable resizing. A good GUI design 
        //      works with most sizes, and should therefore define a maximum
        //      and minimum preferred size. If the maximum does not matter, it
        //      can be omitted. However, ommitting a minimum size allows the 
        //      JFrame to be resized to roughly 80 x 32 px, which is too small.
        setMinimumSize(new Dimension(320, 240));
        
        // NOTE sets a default JPanel to the StatusFrame.
        add(content, BorderLayout.CENTER);
                
        // NOTE packing is a useful thing to do since it sets the size to what 
        //      the content wants. This ensures the initial display closely 
        //      matches the optimal presentation.
        pack();
        setVisible(true);
        return this;
    }
}
