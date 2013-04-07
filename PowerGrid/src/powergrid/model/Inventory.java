package powergrid.model;

/**
 * Represents the Inventory of the local player.
 *
 * @author Vincent W
 */
public class Inventory extends FixedItemList implements Copyable {

    /**
     * The amount of items that fit in the Inventory
     */
    public static final int INVENTORY_SIZE = 28;

    /**
     * Creates a new empty Inventory
     */
    public Inventory() {
        super(INVENTORY_SIZE);
    }

    /**
     * Creates a new Inventory filled with the specified items
     * @param items the Items
     */
    public Inventory(Item[] items) {
        super(INVENTORY_SIZE, items);
    }
    
    @Override
    public Inventory copy() {
        return new Inventory(getAllItems());
    }
}
