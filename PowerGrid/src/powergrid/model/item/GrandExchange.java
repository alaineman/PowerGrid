package powergrid.model.item;

import java.util.Arrays;
import java.util.Objects;
import powergrid.model.Copyable;

/**
 * This class represents the Grand Exchange panel available to each Runescape 
 * player at the Grand Exchange. 
 * <p> 
 * Please note that the GrandSlot are numbered from 0-5 
 * and are from top left to bottom right. See below:
 * <p>
 * [ 0 1 2 ] 
 * [ 3 4 5 ] (members only) 
 * <p>
 * Also note this is build mainly for members to optimize for 6 GrandSlots.
 *  
 * @author Alaineman
 */
public class GrandExchange implements Copyable {

    /**
     * The maximum amount of slots (member is default)
     */
    public static final int GE_CAPACITY = 6;
    
    private GrandSlot[] slots;
   
    /**
     * Creates a new Grand Exchange object (members).
     */
    public GrandExchange() {
        slots = new GrandSlot[GE_CAPACITY];
    }
    
    /**
     * Creates a new Grand Exchange object with the given GrandSlots
     * @param gslots the GrandSlot elements
     */
    public GrandExchange(GrandSlot[] gslots) {
        assert gslots.length >= 0 && gslots.length < 6;
        slots = Arrays.copyOf(gslots, GE_CAPACITY);              // ??? 
    }    
    
    /**
     * Returns all the GrandSlots in the Grand Exchange.
     * @return the GrandSlot objects
     */
    public GrandSlot[] getAllSlots(){
        return Arrays.copyOf(slots, GE_CAPACITY);    
    }
    
    /**
     * Returns the GrandSlot at the specified index.
     * @param index
     * @return the GrandSlot at that index
     * @throws IndexOutOfBoundsException if the index is not in 0-5
     */
    public GrandSlot getSlot(int index) throws IndexOutOfBoundsException{
        if(index<0 || index>5) throw new IndexOutOfBoundsException();
        return copy().slots[index];
    }       
    
    /**
     * Finds the GrandSlot matching to the given Item.
     * @param it the given Item
     * @return the Slot if found, null otherwise.
     */
    public GrandSlot getSlot(Item it){
        GrandSlot gs = null;
        for(int i = 0 ; i < GE_CAPACITY; i++){
            if(slots[i].getItem().equals(it)){
                gs = slots[i];
            }
        }
        return gs;
    }
    
    /**
     * Checks if the specified index contains a valid GrandSlot 
     * and if that slot contains a valid Item.
     * @param index the specified index
     * @return true if occupied, false otherwise
     */
    public boolean isOccupied(int index){
        return slots[index] == null || slots[index].getItem() == null;
    }   
    
    /**
     * Returns the index of the first free GrandSlot in the Grand Exchange.
     * @return 
     */
    public int getFreeSlot(){
        for(int i = 0; i < GE_CAPACITY; i++){
            if(!isOccupied(i)){
                return i;
            }
        }
        return -1;
    }
    
    /**
     * Checks if there is a slot available or not.
     * @return true if not, false otherwise.
     */
    public boolean isFull(){
        return getFreeSlot() == -1;
    }
    
    /**
     * Sets an Item to the first free slot, if such slot exists.
     * @param it the Item
     * @return true if succeeded.
     */
    public boolean setSlot(Item it){        
         if(!isFull()){
             return false;
         }
         int fs = getFreeSlot();
         slots[fs] = new GrandSlot(fs, it);
         return true;
    }
    
    /**
     * Sets an Item to the first free slot, if such GrandSlot exists.
     * @param index the index
     * @return true if succeeded, false otherwise.
     * @throws IndexOutOfBoundsException checks if the index is a valid GrandSlot
     */
    public boolean setSlot(int index) throws IndexOutOfBoundsException {
        if(index < 0 || index > 5){
            throw new IndexOutOfBoundsException();
        }
        if(isOccupied(index)){
            return false;
        }
        slots[index] = new GrandSlot(index, null);
        return true;
    }
    
    /**
     * Removes the last GrandSlot which matches the Item. 
     * <p>
     * Note that multiple slots can contain the same Item type (multiple apples)
     * the last slot containing the item will be cleared.
     * @param it
     * @return the last GrandSlot with the specified Item, 
     * if such Item has not been matched to any GrandSlot null.
     */    
    public GrandSlot clearSlot(Item it){
        GrandSlot g = getSlot(it);
        if(g==null) return null;
        int index = g.getIndex();
        slots[index] = new GrandSlot(index, null);                
        return g;
    }
    
    /**
     * Clears the GrandSlot at the specified index.
     * @param index the specified index
     * @return the removed GrandSlot
     * @throws IndexOutOfBoundsException if the index is not in 0-5
     */
    public GrandSlot clearSlot(int index) throws IndexOutOfBoundsException{
        if(index<0||index>5) throw new IndexOutOfBoundsException();
        GrandSlot g = slots[index];
        slots[index] = new GrandSlot(index, null);
        return g;
    }
    
    @Override
    public GrandExchange copy() {
        return new GrandExchange(getAllSlots());
    }    
    
    /**
     * This class represents a slot within the grand exchange which is used
     * to trade Items.
     */
    public class GrandSlot {
        
        //The slot index
        private int index;
        
        //Item type;
        private Item it;         
        
        //The price you set them for
        private int value;
        
        //The standard daily GE price
        private int normal;
        
        //The amount of items already traded (bought/sold)
        private int tradedStack;
        
        //True if not cancelled and not tradedStack == stack.
        private boolean pending;       

        /**
         * The creation of a slot for the Grand Exchange.
         * @param index the index of this slot
         * @param item the item this slot contains
         */
        public GrandSlot(int index, Item item) {
            this.index = index;
            this.it = item;
            value = -1;
            normal = -1; // TODO get this price from website by dump??
            tradedStack = 0;
            pending = false;
        }

        /**
        * The creation of a slot for the Grand Exchange.
         * @param index the index of this slot
         * @param item the item this slot contains
         * @param stack the amount of this items you want to sell/buy
         * @param value the value per item you want to sell/buy
         */
        public GrandSlot(int index, Item item, int stack, int value) {            
            this.index = index;
            this.it = item;
            this.value = value;
            this.normal = -1;
            this.tradedStack = 0;
            this.pending = true;
        }

        /**
         * 
         * @return The index of this GrandSlot
         */
        public int getIndex() {
            return index;
        }
        
        /**
         * 
         * @return the Item type which is sold/bought in this slot
         */
        public Item getItem() {
            return it;
        }

        /**
         * Sets the Item container to another Item for this slot.
         * @param it the Item
         */
        public void setItem(Item it) {
            this.it = it;
        }

        /**
         * 
         * @return The current value set to buy/sell 1 of this Item for
         */
        public int getValue() {
            return value;
        }

        /**
         * Sets the value to the new value provided
         * @param value the provided value
         */
        public void setValue(int value) {
            this.value = value;
        }

        /**
         * 
         * @return The standard daily Grand Exchange price for this Item.
         */
        public int getNormal() {
            return normal;
        }

        /**
         * This is a port for a price checker to set the normal value.
         * Note this method should not be used normally. 
         * When in doubt please contact a developer about this method.
         * @param normal 
         */
        public void setNormal(int normal) {
            this.normal = normal;
        }

        /**
         * 
         * @return The amount of the Item you want to sell/buy.
         */
        public int getTradedStack() {
            return tradedStack;
        }

        /**
         * Sets the amount of the Item you want to sell/buy.
         * @param tradedStack 
         */
        public void setTradedStack(int tradedStack) {
            this.tradedStack = tradedStack;
        }

        /**
         * Checks if the offer is still pending.
         * <p>
         * The meaning of pending here has 2 key points: 
         * The trade is not completed, like bought/sold 100 out of 100 items, 
         * nor is it canceled.
         *  
         * @return true if it's a pending offer
         */
        public boolean isPending() {
            return pending;
        }

        private void setPending(boolean pending) {
            this.pending = pending;
        }
        
        /**
         * Calculates the total value of the slot offer.
         * <p>
         * Example: 50 bronze daggers of 30 coins value 
         * should give a total value of 1500 coins.
         * @return the estimated value of this offer.
         */
        public int getTotalValue(){
            return value*it.getStackSize();
        }
        
        /**
         * Calculates the total value of the traded items so far
         * <p>
         * Example: 30/50 bronze daggers sold for 30 coins value
         * should sum up to 900 coins.
         * @return the estimated value of the traded items so far
         */
        public int getTradedValue(){
            return value*tradedStack;
        }
        
        /**
         * Check how many items yet have to be traded
         * @return the amount of items yet to be traded
         */
        public int getRemainingTrade(){
            return it.getStackSize()-tradedStack;
        }
        
        /**
         * Calculates the total value of the non traded items so far.
         * @return the estimated value of the items yet to be traded
         */
        public int getPendingValue(){
            return (it.getStackSize()-tradedStack)*value;
        }
        
        @Override
        public String toString() {
            return "GrandSlot{" + "index=" + index + ", it=" + it + ", value=" + value + ", normal=" + normal + ", tradedStack=" + tradedStack + ", pending=" + pending + '}';
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 29 * hash + this.index;
            hash = 29 * hash + Objects.hashCode(this.it);
            hash = 29 * hash + this.value;
            hash = 29 * hash + this.tradedStack;
            hash = 29 * hash + (this.pending ? 1 : 0);
            return hash;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final GrandSlot other = (GrandSlot) obj;
            if (this.index != other.index) {
                return false;
            }
            if (!Objects.equals(this.it, other.it)) {
                return false;
            }          
            if (this.value != other.value) {
                return false;
            }
            if (this.tradedStack != other.tradedStack) {
                return false;
            }
            if (this.pending != other.pending) {
                return false;
            }
            return true;
        }        
    }    
}
