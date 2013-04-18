package powergrid.model.item;

import java.util.Arrays;
import java.util.Objects;
import powergrid.model.Copyable;

/**
 *
 * @author Alaineman
 */
public class GrandExchange implements Copyable {

    public static final int GE_CAPACITY = 6;
    
    private GrandSlot[] slots;
   
    public GrandExchange() {
        slots = new GrandSlot[GE_CAPACITY];
    }
    
    public GrandExchange(GrandSlot[] gslots) {
        assert gslots.length >= 0 && gslots.length < 7;
        slots = Arrays.copyOf(gslots, GE_CAPACITY);              // ??? 
    }    
    
    public GrandSlot[] getAllSlots(){
        return Arrays.copyOf(slots, GE_CAPACITY);    
    }
    
    public GrandSlot getSlot(int index){
        return copy().slots[index];
    }       
    
    public GrandSlot getSlot(Item it){
        GrandSlot gs = null;
        for(int i = 0 ; i < GE_CAPACITY; i++){
            if(slots[i].getItem().equals(it)){
                gs = slots[i];
            }
        }
        return gs;
    }
    
    public boolean isOccupied(int index){
        return slots[index] == null || slots[index].getItem() == null;
    }   
    
    public int getFreeSlot(){
        for(int i = 0; i < GE_CAPACITY; i++){
            if(!isOccupied(i)){
                return i;
            }
        }
        return -1;
    }
    
    public boolean isFull(){
        return getFreeSlot() == -1;
    }
    
    public boolean setSlot(Item it){        
         if(!isFull()){
             return false;
         }
         int fs = getFreeSlot();
         slots[fs] = new GrandSlot(fs, it);
         return true;
    }
    
    public boolean setSlot(int index) throws IndexOutOfBoundsException {
        if(index < 0 || index > 6){
            throw new IndexOutOfBoundsException();
        }
        if(isOccupied(index)){
            return false;
        }
        slots[index] = new GrandSlot(index, null);
        return true;
    }
    
    public GrandSlot clearSlot(Item it){
        GrandSlot g = getSlot(it);
        int index = g.getIndex();
        slots[index] = new GrandSlot(index, null);                
        return g;
    }
    
    public GrandSlot clearSlot(int index) {
        GrandSlot g = slots[index];
        slots[index] = new GrandSlot(index, null);
        return g;
    }
    
    
    
    @Override
    public GrandExchange copy() {
        return new GrandExchange(getAllSlots());
    }
    
    
    public class GrandSlot {
        
        //The slot index
        private int index;
        
        //Item type;
        private Item it;
         
        //The amount of items you set to buy or sell
        private int stack;
        
        //The price you set them for
        private int value;
        
        //The standard daily GE price
        private int normal;
        
        //The amount of items already traded (bought/sold)
        private int tradedStack;
        
        //True if not cancelled and not tradedStack == stack.
        private boolean pending;       

        public GrandSlot(int index, Item item) {
            this.index = index;
            this.it = item;
            stack = 0;
            value = -1;
            normal = -1; // TODO get this price from website by dump??
            tradedStack = 0;
            pending = false;
        }

        public GrandSlot(int index, Item item, int stack, int value) {            
            this.index = index;
            this.it = item;
            this.stack = stack;
            this.value = value;
            this.normal = -1;
            this.tradedStack = -1;
            this.pending = true;
        }

        public int getIndex() {
            return index;
        }

        public void setIndex(int index) {
            this.index = index;
        }

        public Item getItem() {
            return it;
        }

        public void setItem(Item it) {
            this.it = it;
        }

        public int getStack() {
            return stack;
        }

        public void setStack(int stack) {
            this.stack = stack;
            this.pending = true;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }

        public int getNormal() {
            return normal;
        }

        public void setNormal(int normal) {
            this.normal = normal;
        }

        public int getTradedStack() {
            return tradedStack;
        }

        public void setTradedStack(int tradedStack) {
            this.tradedStack = tradedStack;
        }

        public boolean isPending() {
            return pending;
        }

        public void setPending(boolean pending) {
            this.pending = pending;
        }
        
        public int getTotalValue(){
            return value*stack;
        }
        
        public int getTradedValue(){
            return value*tradedStack;
        }
        
        public int getRemainingTrade(){
            return stack-tradedStack;
        }
        
        public int getPendingValue(){
            return (stack-tradedStack)*value;
        }
        
        
        
        
        
        
        
        
        

        @Override
        public String toString() {
            return "GrandSlot{" + "index=" + index + ", it=" + it + ", stack=" + stack + ", value=" + value + ", normal=" + normal + ", tradedStack=" + tradedStack + ", pending=" + pending + '}';
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 29 * hash + this.index;
            hash = 29 * hash + Objects.hashCode(this.it);
            hash = 29 * hash + this.stack;
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
            if (this.stack != other.stack) {
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
