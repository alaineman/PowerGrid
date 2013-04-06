package powergrid.view.status;

import java.awt.Component;
import java.awt.Container;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

/**
 * Represents a scrollable list of elements.
 * <p/>
 * Each element can be any arbitrary Container. This allows for a smoother
 * user interface than by using JLists or similar.
 * <p/>
 * @author Chronio
 */
//TODO test this class
public class ScrollableElementList extends JScrollPane {
    
    private GridBagConstraints gbc;
    private Container contents;
    private ArrayList<Component> entries;
    private Container filler;
    
    /**
     * Creates a new empty ScrollableElementList.
     */
    public ScrollableElementList() {
        this(new JPanel());
    }
    
    /**
     * Creates a new ScrollableElementList that uses the specified Container 
     * to layout the elements on. 
     * <p/>
     * This allows overriding classes to have more control over the structure 
     * of the List.
     * @param contents the Container to layout the components on.
     */
    protected ScrollableElementList(Container contents) {
        super(contents);
        this.contents = contents;
        gbc = new GridBagConstraints();
        entries = new ArrayList<>(5);
        filler = new Container();
    }
    
    /**
     * Initializes the ScrollableElementList.
     * <p/>
     * Overriding classes should call this method to ensure the 
     * ScrollableElementList is set up correctly.
     */
    public void initialize() {
        contents.setLayout(new GridBagLayout());
        setHorizontalScrollBarPolicy(HORIZONTAL_SCROLLBAR_NEVER);
        setVerticalScrollBarPolicy(VERTICAL_SCROLLBAR_ALWAYS);
        
        // set up the GridBagConstraints properties
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        
        contents.setSize(getSize());
    }
    
    /**
     * Sets the GridBagConstraints' settings to the default values for this
     * ScrollableElementList.
     * <p/>
     * Subclasses of this class can override this method to provide a
     * customized presentation of the ScrollableElementList.
     * <p/>
     * The gridx and gridy parameters of the GridBagConstraints should be set 
     * at 0.
     * @param gbc the GridBagConstraints to configure
     */
    public void configureGBC(GridBagConstraints gbc) {
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        gbc.insets = new Insets(0, 0, 0, 0);
        gbc.weightx = 1;
        gbc.weighty = 0;
        gbc.gridheight = 1;
        gbc.gridwidth = 1;
        gbc.ipadx = 0;
        gbc.ipady = 0;
    }
    
    /**
     * Adds the specified elements to the list.
     * @param elements the elements to add
     */
    public void add(Collection<? extends Component> elements) {
        if (elements != null) {
            remove(filler);
            
            // ensure a one-time resize only for adding many elements.
            if (elements.size() > entries.size()) {
                entries.ensureCapacity(entries.size() + elements.size() + 1);
            }
            configureGBC(gbc);
            gbc.gridy = entries.size();
            for (Component c : elements) {
                entries.add(c);
                contents.add(c, gbc);
                gbc.gridy++;
            }
            
            // Add a filler to push the elements upward.
            gbc.weightx = gbc.weighty = 1;
            gbc.fill = GridBagConstraints.BOTH;
            add(filler, gbc);
        }
    }
    
    /**
     * Adds the specified elements to the list.
     * @param elements the elements to add
     */
    public void add(Component... elements) {
        add(Arrays.asList(elements));
    }
    
    /**
     * Validates this component as defined by 
     * <code>Container.validate()</code>, and additionally resizes the content
     * of this JScrollPane as required.
     * <p/>
     * This ensures that resizing the ScrollableElementList or one of its 
     * parents will not cause layout problems in the list itself.
     * <p/>
     * This override is required because a JScrollPane does not resize its 
     * contained component when being revalidated. In the case of a 
     * ScrollableElementList, the width of the components in the list must be 
     * the same as the width of the ScrollPane 
     * <p/>
     * @see Container#validate() Container.validate()
     */
    @Override public void validate() {
        // We first store the original width and height before validating this 
        // component so we can check if the size has changed later.
        int oldHeight = getHeight();
        int oldWidth = getWidth();
        
        // Call the super validate method to ensure this ScrollPane is 
        // validated correctly.
        super.validate();
        
        int newWidth = getWidth();
        int newHeight = getHeight();
        
        // Validation is an exensive operation. Therefore, we only resize 
        // (and therefore invalidate) the contents when the size has changed.
        if (oldWidth != newWidth || oldHeight != newHeight) {
            // We set the height according to the 
            contents.setSize(newWidth - getVerticalScrollBar().getWidth(), 
                    Math.max(getHeight(), contents.getHeight()));
            
            // Revalidate the ScrollPane's component to update changes in size.
            // Revalidating here is preferred since in this case it means that 
            // the ongoing validation continues in the children of the 
            // ScrollPane's viewport component.
            contents.revalidate();
        }
    }
}
