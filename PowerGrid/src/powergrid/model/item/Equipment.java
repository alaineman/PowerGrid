package powergrid.model.item;

import powergrid.model.Copyable;

/**
 * Represents the equipment window
 * @author Vincent W
 */
public class Equipment extends FixedItemList implements Copyable {
    
    /**
     * The amount of items that fit in the Inventory
     */
    public static final int EQUIPMENT_SIZE = 13;
    
    /**
     * Creates a new Equipment.
     */
    public Equipment(){
        super(EQUIPMENT_SIZE);
    }
    
    /**
     * Creates a new Equipment with the specified Items
     * @param items the Items
     */
    public Equipment(Item[] items){
        super(EQUIPMENT_SIZE, items);
    }

    @Override
    public Equipment copy() {
        return new Equipment(getAllItems());
    }
    
}
