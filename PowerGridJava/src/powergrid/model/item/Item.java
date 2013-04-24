package powergrid.model.item;

import org.powerbot.game.client.RSItem;
import org.powerbot.game.client.RSItemDef;

/**
 * Class that represents an Item in the RSBot environment.
 * @author Chronio
 */
public class Item {
    
    private RSItem item;
    private RSItemDef itemDef;
    
    /**
     * Creates an Item object that represents the given RSbot Item 
     * @param rsItem the Item object as given by the RSBot environment.
     * @param rsItemDef the RSItemDef object describing this Item 
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
     * returns how many instances of this Item's type are represented by this 
     * Item object.
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

    @Override public int hashCode() {
        int hash = 5;
        hash = 97 * hash + item.getId();
        hash = 97 * hash + item.getStackSize();
        hash = 97 * hash + itemDef.getID();
        return hash;
    }
    
    /**
     * Returns whether this Item is equal to another Object.
     * <p/>
     * This method returns true if and only if the following is true:
     * <ul>
     *  <li>other is also an Item object</li>
     *  <li>the other Item's RSItem is equal to this Item's RSItem</li>
     *  <li>the other Item's RSItemDef is equals to this Item's RSItemDef</li>
     * </ul>
     * This method returns false otherwise.
     * <p/>
     * @param other the Object to compare with
     * @return whether this Item is equal to the given Object
     */
    @Override public boolean equals(Object other) {
        if (other instanceof Item) {
            Item that = (Item) other;
            RSItem myItem = this.getRSItem();
            RSItem theirItem = that.getRSItem();
            RSItemDef myDef = this.getRSItemDef();
            RSItemDef theirDef = that.getRSItemDef();
            return (myItem.getId() == theirItem.getId() &&
                    myItem.getStackSize() == theirItem.getStackSize() &&
                    myDef.getID() == theirDef.getID());
        }
        return false;
    }
    
    /**
     * Returns a String representing this Item, containing the RSItem's id and 
     * the stack size.
     * @return a String representing this Item.
     */
    @Override public String toString() {
        return "Item(" + item.getId() + "," + item.getStackSize() + ")";
    }
}
