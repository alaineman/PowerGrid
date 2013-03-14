package powergrid.model;

import org.powerbot.game.client.RSItem;
import org.powerbot.game.client.RSItemDef;

/**
 * Class that represents an Item in the RSBot environment
 * @author Chronio
 */
public class Item {
    
    private RSItem item;
    private RSItemDef itemDef;
    
    /**
     * creates an Item object that represents the given RSbot Item 
     * @param rsItem the Item object as given by the RSBot environment.
     */
    public Item(RSItem rsItem,RSItemDef rsItemDef) {
        item = rsItem;
        itemDef = rsItemDef;
    }
    
    /**
     * Returns a String containing the name of the Item
     * @return the name of the Item
     */
    public String getName() {
        return itemDef.getName();
    }
    
    /**
     * returns the unique id for this item
     * @return the unique id for this item
     */
    public int getId() {
        return item.getId();
    }
    
    /**
     * returns the RSBot item this Item represents
     * @return the RSBot item this Item represents
     */
    public RSItem getRSItem() {
        return item;
    }
    
    /**
     * returns how many instances of this Item's type are represented by this Item object
     * @return the amount of instances this Item represents
     */
    public int getStackSize() {
        return item.getStackSize();
    }
    
    /**
     * Returns the RSItemDef object corresponding to this Item type.
     * @return the RSItemDef object corresponding to this Item type
     */
    public RSItemDef getRSItemDef() {
        return itemDef;
    }
    
    /**
     * Returns whether this Item is a member's Item.
     * @return true if this Item is a member's Item, false otherwise
     */
    public boolean isMemberItem() {
        return itemDef.isMembersObject();
    }
    
    /**
     * Returns a String array of the actions available to this item.
     * @return a String array of the actions available to this item
     */
    public String[] getActions() {
        return itemDef.getActions();
    }
}
