package powergrid.model;

import powergrid.model.item.Item;

/**
 * Matcher for Items.
 * <p/>
 * This class matches on 
 * @author Chronio
 */
public class ItemMatcher implements Matcher<Item> {
    
    private String name;
    private int id;
    
    public ItemMatcher(String requiredName) {
        assert name != null && !name.isEmpty();
        name = requiredName;
        id = -1;
    }
    
    public ItemMatcher(int id) {
        assert id >= 0;
        this.id = id;
    }

    public String getName() {
        return name;
    }

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
