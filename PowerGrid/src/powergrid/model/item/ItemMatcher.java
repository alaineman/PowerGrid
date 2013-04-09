package powergrid.model.item;

import powergrid.model.Matcher;

/**
 * Matcher for Items.
 * <p/>
 * This class matches on 
 * @author Chronio
 */
public class ItemMatcher implements Matcher<Item> {
    
    private String name;
    private int id;
    
    /**
     * Creates a new ItemMatcher
     * @param requiredName the name of the specified item.
     */
    public ItemMatcher(String requiredName) {
        assert name != null && !name.isEmpty();
        name = requiredName;
        id = -1;
    }
    
    /**
     * Creates a new ItemMatcher
     * @param id the id of the specified item.
     */
    public ItemMatcher(int id) {
        assert id >= 0;
        this.id = id;
    }

    /**
     * 
     * @return the name value of the ItemMatcher
     */
    public String getName() {
        return name;
    }

    /**
     * 
     * @return the id value of the ItemMatcher
     */
    public int getId() {
        return id;
    }
    
    @Override 
    public boolean matches(Item i) {
        if (name != null) {
            return i.getName().equalsIgnoreCase(name);
        } else {
            return i.getId() == id;
        }
    }
}
