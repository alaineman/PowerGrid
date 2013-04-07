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
 * Each element can be any type of Component. This allows for a smoother
 * user interface than by using JLists or similar.
 * <p/>
 * @author Chronio
 */
public class ScrollableElementList extends JScrollPane {
    
    private GridBagConstraints gbc;
    private Container contents;
    private ArrayList<Component> entries;
    private Container filler;
    
    /**
     * Creates a new empty ScrollableElementList.
     * <p/>
     * A JPanel will be used to layout the elements.
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
    public ScrollableElementList(Container contents) {
        super(contents);
        assert contents != null;
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
     * @return itself for fluency
     */
    public ScrollableElementList initialize() {
        
        contents.setLayout(new GridBagLayout());
        setHorizontalScrollBarPolicy(HORIZONTAL_SCROLLBAR_NEVER);
        setVerticalScrollBarPolicy(VERTICAL_SCROLLBAR_ALWAYS);
        
        contents.setSize(getSize());
        
        return this;
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
    public synchronized void configureGBC(GridBagConstraints gbc) {
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
    public synchronized void add(Collection<? extends Component> elements) {
        if (elements != null) {
            contents.remove(filler);
            
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
            filler.setPreferredSize(getSize());
            contents.add(filler, gbc);
        }
    }
    
    /**
     * Adds the specified elements to the list.
     * @param elements the elements to add
     */
    public synchronized void add(Component... elements) {
        add(Arrays.asList(elements));
    }
    
    /**
     * Returns the Component at the specified index.
     * <p/>
     * When no Component exists with that index, null is returned.
     * @param index the index
     * @return the Component at the index, if it exists
     */
    public Component getAtIndex(int index) {
        if (index < 0 && index > entries.size()) {
            return null;
        } else {
            return entries.get(index);
        }
    }
    
    /**
     * Clears the contents of this List.
     */
    public synchronized void clear() {
        entries.clear();
        contents.removeAll();
    }
    
    /**
     * @return an array containing the elements on this ScrollableElementList.
     */
    public Component[] getElements() {
        return entries.toArray(new Component[entries.size()]);
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
        
        // Note that calling getSize() on a component causes an additional
        // Dimension object to be created, which is a bit slower than keeping
        // the width and height as integers.
        int newWidth = getWidth();
        int newHeight = getHeight();
        
        // Validation is an exensive operation. Therefore, we only resize 
        // (and therefore invalidate) the contents when the size has changed.
        if (oldWidth != newWidth || oldHeight != newHeight) {
            
            contents.setSize(newWidth - getVerticalScrollBar().getWidth(), 
                    Math.max(getHeight(), contents.getHeight()));
        }
    }
}
