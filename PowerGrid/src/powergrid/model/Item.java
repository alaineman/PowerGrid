package powergrid.model;

/**
 * Class that represents an Item in the RSBot environment
 * @author Chronio
 */
public class Item {
    
    private org.powerbot.game.api.wrappers.node.Item theItem;
    
    /**
     * creates an Item object that represents the given RSbot Item 
     * @param rsItem the Item object as given by the RSBot environment.
     */
    public Item(org.powerbot.game.api.wrappers.node.Item rsItem) {
        theItem = rsItem;
    }
    
    /**
     * Returns a String containing the name of the Item
     * @return the name of the Item
     */
    public String getName() {
        return theItem.getName();
    }
    
    /**
     * returns the unique id for this item
     * @return the unique id for this item
     */
    public int getId() {
        return theItem.getId();
    }
    
    /**
     * returns the raw value indicating the item's type
     * @return the raw value indicating the item's type
     */
    public int getRawValue() {
        return theItem.getDefinition().getId();
    }
    
    /**
     * returns the RSBot item this Item represents
     * @return the RSBot item this Item represents
     */
    public org.powerbot.game.api.wrappers.node.Item getRSItem() {
        return theItem;
    }
    
    /**
     * returns how many instances of this Item's type are represented by this Item object
     * @return the amount of instances this Item represents
     */
    public int getStackSize() {
        return theItem.getStackSize();
    }
}
