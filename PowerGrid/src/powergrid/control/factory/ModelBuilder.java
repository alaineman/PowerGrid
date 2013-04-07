package powergrid.control.factory;

import org.powerbot.game.client.RSItem;
import org.powerbot.game.client.RSItemDef;
import powergrid.PowerGrid;
import powergrid.control.DefinitionCache;
import powergrid.model.item.Item;
import powergrid.model.rsbot.RSItemImpl;

/**
 * This class contains the required functionality to build and set up elements 
 * from the Runescape environment.
 * <p/>
 * The ModelBuilder is used for instantiating GameTiles and Items, set up 
 * TransportNetworks, and in this way building and maintaining the model that 
 * is used to represent the Runescape world.
 * <p/>
 * @author Chronio
 */
public class ModelBuilder {
    
    private PowerGrid pg;
    
    private DefinitionCache cache;
    
    /**
     * Creates a new ModelBuilder.
     */
    public ModelBuilder() {
        pg = null;
        cache = null;
    }
    
    /**
     * Sets the PowerGrid instance to use if one was not already set.
     * <p/>
     * If a PowerGrid instance is already set, this method does nothing.
     * Else, the PowerGrid instance is set and this ModelBuilder creates a new 
     * DefinitionCache that is linked to the Client object in the PowerGrid 
     * instance.
     * <p/>
     * @param pg the PowerGrid instance to use
     * @return itself for fluency
     */
    public ModelBuilder usePowerGrid(PowerGrid pg) {
        if (this.pg == null && pg != null) {
            this.pg = pg;
            cache = new DefinitionCache(pg.client());
        }
        return this;
    }
    
    /**
     * Returns the PowerGrid instance this ModelBuilder uses.
     * @return the PowerGrid instance
     */
    public PowerGrid getPowerGrid() {
        return pg;
    }
    
    /**
     * Returns an Item instance that contains the specified Item id.
     * <p/>
     * When an Item was already created with this id using this method, the 
     * RSItemDef of that Item is the same Object as the RSItemDef in the 
     * returned Item.
     * <p/>
     * @param itemId the Item id
     * @return an Item with the specified Item id.
     */
    public Item createItem(int itemId) {
        return createItem(new RSItemImpl(itemId, 1));
    }
    
    /**
     * Returns an Item instance that contains the specified RSItem.
     * <p/>
     * When an Item was already created with the RSItem's id using this method, 
     * the RSItemDef of that Item is the same Object as the RSItemDef in the 
     * returned Item.
     * <p/>
     * @param item the RSItem object
     * @return an Item with the specified Item id.
     */
    public Item createItem(RSItem item) {
        RSItemDef def = cache.lookupItemDef(item);
        if (def == null) {
            return null;
        }
        return new Item(item, def);
    }
}
