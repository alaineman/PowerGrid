package powergrid.model.world.player;

import org.powerbot.game.client.RSPlayer;
import powergrid.model.item.Bank;
import powergrid.model.item.Equipment;
import powergrid.model.item.GrandExchange;
import powergrid.model.item.Inventory;
import powergrid.model.item.Item;
/**
 *
 * @author Vincent W
 */
public class LocalPlayer extends Player {
 
    private GrandExchange grandexchange;
    private Inventory inventory;
    private Equipment equipment;
    private Bank bank;
    
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
    
    public Bank getBank(){
        return bank.copy();
    }
    
    //TODO the following methods below
    
    public int getTotalCash(){
        int inventoryMoney  = 0;
        Inventory inv = getInventory();
        for(Item i : inv){
            if(i.getId() == 995){
                inventoryMoney = i.getStackSize();
                break;
            }
        }
        return inventoryMoney + getMoneyPouch();
        
        
    }
    
    public int getMoneyPouch(){
        //Where is the money??
        //Widget 548, child 199
        return -1;
    }
    
    
    public GrandExchange getGrandExchange(){
        return grandexchange.copy();
    }
    
    //Quests
    //Summoning
    //Achievements
        
    public boolean isLoggedIn(){
        return true;
    }
    
    
    
}

