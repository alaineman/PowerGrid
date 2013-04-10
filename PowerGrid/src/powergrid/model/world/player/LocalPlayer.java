package powergrid.model.world.player;

import org.powerbot.game.client.RSPlayer;
import powergrid.model.item.Equipment;
import powergrid.model.item.Inventory;
/**
 *
 * @author Vincent W
 */
public class LocalPlayer extends Player {
 
    private Inventory inventory;
    private Equipment equipment;
    
    /**
     * Creates an object representing the local Player.
     * @param player the local Player
     */
    public LocalPlayer(RSPlayer player) {
        super(player);
    }    
    
    /**
     * This method returns a copy of the Player's Inventory. 
     * Note: Inventory is mutable
     * @return a copy of Player's Inventory
     */
    public Inventory getInventory(){
        return inventory.copy();
    }
    
     /**
     * This method returns a copy of the Player's Equipment. 
     * Note: Equipment is mutable
     * @return a copy of Player's Equipment
     */
    public Equipment getEquipment(){
        return equipment.copy();
    }
    
    
    //TODO the following methods below
    
    public int getTotalCash(){
        return -1;
    }
    
    public int getMoneyPouchTotal(){
        return -1;
    }
    
    //public Bank getBank(){}      
    //Quests
    //Achievements
        
    public boolean isLoggedIn(){
        return true;
    }
    
    
    
}

