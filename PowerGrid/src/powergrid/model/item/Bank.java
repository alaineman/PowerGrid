package powergrid.model.item;

import java.util.AbstractList;
import java.util.ArrayList;
import java.util.List;
import powergrid.model.ItemMatcher;
import powergrid.model.LinkedList;

/**
 *
 * @author Vincent W
 */
public class Bank extends AbstractList<Item> {
    
    public static final int TAB_COUNT = 9;
    
    private ArrayList<LinkedList<Item>> items;
    private int size;
    
    public Bank() {        
        size = 0;
        items = new ArrayList<>(TAB_COUNT);
    }
    
    public Bank(List<LinkedList<Item>> items){
        size = 0;
        this.items = new ArrayList<>(items);
    }
    
    @Override
    public boolean add(Item item){
        return add(item, 0);
    }
    
    public Slot getSlot(int index) {
        return null;
    }
    
    public boolean add(Item item, int tab) {
        if(tab >= TAB_COUNT || tab < 0) {
            throw new IndexOutOfBoundsException("Invalid tab index");
        }
        while(items.size() - 1 < tab){
            addTab();
        }
        LinkedList<Item> tabContents = items.get(tab);
        if (tabContents.addLast(item)) {
            size++;
            return true;
        }
        return false;
    }
    
    public int addTab(){
        items.add(new LinkedList<Item>());
        return items.size();
    }
    
    public boolean removeTab(int index) {
        if (index < 0 || index >= items.size()) {
            return false;
        }
        //TODO add contents of tab [index] to tab 0.
        return true;
    }
    
    public boolean isOccupied(Slot slot){
        return verifyTab(slot).size() > slot.getIndex();
    }
    
    public Slot getFreeSlot(int tab){
        return new Slot(tab, verifyTab(tab).size());
    }
    
    public int getFreeTab(){
        if (items.size() == TAB_COUNT) {
            return -1;
        } else {
            return items.size();
        }
    }
    
    public boolean swapItems(int tab, int one, int two){
        return false;
    }
    
    public boolean swapItems(int tab, Item one, Item two){
        return false;
    }
    
    private LinkedList<Item> verifyTab(int tab) {
        if (tab < 0 || tab > items.size()) {
            throw new IndexOutOfBoundsException("Tab index out of bounds");
        } else {
            return items.get(tab);
        }
    }
    
    private LinkedList<Item> verifyTab(Slot slot) {
        if (slot == null) {
            throw new IllegalArgumentException("Slot == null");
        } else {
            return verifyTab(slot.getTab());
        }
    }
    
    private Item verifyItem(Slot slot) {
        return verifyTab(slot).get(slot.getIndex());
    }
    
    @Override
    public Item remove(int index){
        return remove(getSlot(index));
    }
    
    public Item remove(Slot i) {
        return null;
    }
    
    public Item remove(ItemMatcher matcher) {
        return null;
    }
    
    @Override
    public Item get(int index) {
        return get(getSlot(index));
    }
    
    public Item get(Slot slot) {
        return verifyItem(slot);
    }
    
    public int getIndex(ItemMatcher matcher) {
        return -1;
    }
    
    public List<Item> getAllItems(){
        ArrayList<Item> allItems = new ArrayList<>(size());
        for (LinkedList<Item> tab : items) {
            for (Item i : tab) {
                allItems.add(i);
            }
        }
        return allItems;
    }
    
    public List<Item> getAllMatchingItems(ItemMatcher matcher) {
        return null;
    }
    
    public List<Slot> getAllMatchingSlots(ItemMatcher matcher) {
        return null;
    }
    
    /**
     * Returns the first Item in the tab.
     * The first Item in the tab acts as the tab's representative and it's icon
     * is used to represent the tab.
     * @param tab the tab
     * @return the representative Item for the tab
     */
    public Item getTabRepresentative(int tab) {
        return verifyTab(tab).getFirst();
    }
    
    public Item locateItem(ItemMatcher matcher){
        return null;
    }
    
    public int findTab(ItemMatcher matcher) {
        return -1;
    }
    
    public Slot findSlot(ItemMatcher matcher) {
        return null;
    }
    
    public int tabCount(){
        return items.size();
    }

    @Override
    public int size() {
        return size;
    }
    
    @Override 
    public Item set(int index, Item element){
         if (index >= 0 && index < items.size()) {
             //TODO implement set functionality
        }
        throw new IndexOutOfBoundsException();
    }
    
    public static class Slot {
        
        private int tab;
        private int index;
        
        public Slot(int tab, int index){
            assert tab >= 0 && index >= 0 && tab < TAB_COUNT;
            this.tab = tab;
            this.index = index;
        }

        public int getTab() {
            return tab;
        }

        public int getIndex() {
            return index;
        }

        @Override
        public int hashCode() {
            int hash = 3;
            hash = 29 * hash + this.tab;
            hash = 29 * hash + this.index;
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
            final Slot other = (Slot) obj;
            if (this.tab != other.getTab()) {
                return false;
            }
            if (this.index != other.getIndex()) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            return "Slot(" + tab + ", " + index + ")";
        }    
    }
}
