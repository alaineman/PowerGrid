package powergrid.model.item;

import java.util.AbstractList;
import java.util.ArrayList;
import java.util.List;
import powergrid.model.LinkedList;

/**
 * This class represents the Runescape local player Bank
 * <p>
 * The bank is represented as a list of tabs containing a LinkedList of items.
 * @author Vincent W
 */
public class Bank extends AbstractList<Item> {

    /**
     * The maximum amount of tabs
     */
    public static final int TAB_COUNT = 9;
    
    private ArrayList<LinkedList<Item>> items;

    /**
     * Creates a new Bank object
     */
    public Bank() {
        items = new ArrayList<>(TAB_COUNT);
    }

    /**
     * Creates a new Bank object with the specified data
     * @param items the items in the Bank
     */
    public Bank(List<LinkedList<Item>> items) {
        this.items = new ArrayList<>(items);
    }

    /**
     * Adds a specified item to the default tab
     * @param item the specified item
     * @return true
     */
    @Override
    public boolean add(Item item) {
        return add(item, 0);
    }

    /**
     * Retrieves the Slot corresponding to the specified index
     * <p> 
     * Note: if the index is not valid 
     * a IndexOutOfBoundsException will be thrown
     * @throws IndexOutOfBoundsException
     * @param index the specified index
     * @return the Slot corresponding to the specified index
     */
    public Slot getSlot(int index) {
        if(index < size()){
            throw new IndexOutOfBoundsException();
        }
        for (int i = 0; i < items.size(); i++) {
            if (index > items.get(i).size()) {
                index = -items.get(i).size();
            } else {
                return new Slot(i, index);
            }
        }
        return null;
    }

    /**
     * Adds a specified item to a specified tab
     * @param item the specified item
     * @param tab the specified tab
     * @throws IndexOutOfBoundsException
     * @return true
     */
    public boolean add(Item item, int tab) {
        if (tab >= TAB_COUNT || tab < 0) {
            throw new IndexOutOfBoundsException("Invalid tab index");
        }
        while (items.size() - 1 < tab) {
            addTab();
        }
        LinkedList<Item> tabContents = items.get(tab);
        return tabContents.addLast(item);
    }

    /**
     * Adds a new tab to the Bank
     * @return the tab number (also the new tab size)
     */
    public int addTab() {
        items.add(new LinkedList<Item>());
        return items.size();
    }

    /**
     * Removes a tab from the Bank
     * @param tab the tab to be removed
     * @return true
     */
    public boolean removeTab(int tab) {
        verifyTab(tab);
        return items.get(0).concat(items.remove(tab));
    }

    /**
     * Checks whether or not a Slot contains an Item
     * @param slot the specified slot
     * @return true if it contains an Item, false otherwise
     */
    public boolean isOccupied(Slot slot) {
        return verifyTab(slot).size() > slot.getIndex();
    }

    /**
     * Finds and retrieves the first free Slot
     * @param tab the specified tab to search in
     * @return the first free Slot
     */
    public Slot getFreeSlot(int tab) {
        return new Slot(tab, verifyTab(tab).size());
    }

    /**
     * Finds and retrieves the first free tab
     * @return the tab number of the first free tab,
     * -1 if the bank has no more free tab left
     */
    public int getFreeTab() {
        if (items.size() == TAB_COUNT) {
            return -1;
        } else {
            return items.size();
        }
    }

    /**
     * Swaps two Item objects by their indices for the specified tab
     * @param tab the specified tab
     * @param index1 the first index
     * @param index2 the second index
     * @return true if both indices contain items and are not the same
     */
    public boolean swapItems(int tab, int index1, int index2) {        
        return verifyTab(tab).swap(index1, index2);                
    }
    
    /**
     * Swaps two Item objects for the specified tab
     * @param tab the specified tab
     * @param one the first Item
     * @param two the second Item
     * @return true if both items do exist in the specified tab 
     * and are not the same item
     */
    public boolean swapItems(int tab, Item one, Item two) {
        return verifyTab(tab).swap(one, two);
    }

    /**
     * Checks whether or not the given tab exists.
     * @param tab the specified tab
     * @return the tab itself
     */
    private LinkedList<Item> verifyTab(int tab) {
        if (tab < 0 || tab > items.size()) {
            throw new IndexOutOfBoundsException("Tab index out of bounds");
        } else {
            return items.get(tab);
        }
    }

    /**
     * Checks whether or not the given tab exists
     * @param slot the specified slot
     * @return the tab itself
     */
    private LinkedList<Item> verifyTab(Slot slot) {
        if (slot == null) {
            throw new IllegalArgumentException("Slot == null");
        } else {
            return verifyTab(slot.getTab());
        }
    }

    /**
     * Checks whether or not the given Item exists
     * @param slot the specified slot to the Item
     * @return the Item itself
     */
    private Item verifyItem(Slot slot) {
        return verifyTab(slot).get(slot.getIndex());
    }

    /**
     * Removes the Item at the specified index
     * @param index the specified index
     * @return the Item, null if the index was not occupied
     * {@link #isOccupied(Slot) isOccupied}
     */
    @Override
    public Item remove(int index) {
        return remove(getSlot(index));
    }

    /**
     * Removes the Item from the specified Slot
     * @param i the specified Slot
     * @return the removed item, null if the slot was not occupied
     * {@link #isOccupied(Slot) isOccupied}
     */
    public Item remove(Slot i) {
        return verifyTab(i).remove(i.getIndex());
    }

    /**
     * Removes the Item from the specified tab that matches the matcher
     * @param tab the specified tab
     * @param matcher the matcher
     * @return the removed Item, null if no matches occurred
     */
    public Item remove(int tab, ItemMatcher matcher) {
        return verifyTab(tab).remove(matcher);
    }

    /**
     * Finds and retrieves the Item on the given index
     * @param index the specified index
     * @return the Item, null if the index was not occupied
     * {@link #isOccupied(Slot) isOccupied}
     */
    @Override
    public Item get(int index) {
        return get(getSlot(index));
    }

    /**
     * Finds and retrieves the Item on the given Slot
     * @param slot the specified Slot
     * @return the Item, null if the slot is not occupied
     * {@link #isOccupied(Slot) isOccupied}
     */
    public Item get(Slot slot) {
        return verifyItem(slot);
    }
    
    /**
     * Gets the slot corresponding to the matcher
     * @param matcher the specified matcher
     * @return the Slot found by the matcher, null if no such Slot is found
     */
    public Slot getSlot(ItemMatcher matcher) {
        for(int i = 0; i < items.size(); i++){
            int index = items.get(i).findIndex(matcher);
            if(index != -1){
                return new Slot(i, index);
            }
        }        
        return null;
    }

    /**
     * Retrieves all Items from the Bank object in a List
     * @return a list of the items
     */
    public List<Item> getAllItems() {
        ArrayList<Item> allItems = new ArrayList<>(size());
        for (LinkedList<Item> tab : items) {
            for (Item i : tab) {
                allItems.add(i);
            }
        }
        return allItems;
    }

    /**
     * Lists all the found Items who match the matcher.
     * @param matcher the matcher
     * @return the list of items
     */
    public List<Item> getAllMatchingItems(ItemMatcher matcher) {
        List<Item> result = new ArrayList<>(8);
        for(int i = 0; i < items.size(); i++){
            Item item = items.get(i).find(matcher);
            if(item != null){
                result.add(item);
            }
        }        
        return result;
    }

    /**
     * Lists all the Slots of the found items who match the matcher
     * @param matcher the matcher
     * @return the list of Slots
     */
    public List<Slot> getAllMatchingSlots(ItemMatcher matcher) {
        List<Slot> result = new ArrayList<>(8);
        for(int i = 0; i < items.size(); i++){
            int index = items.get(i).findIndex(matcher);
            if(index != -1){
                result.add(getSlot(index));
            }
        }        
        return result;
    }

    /**
     * Returns the first Item in the tab. The first Item in the tab acts as the
     * tab's representative and it's icon is used to represent the tab.
     *
     * @param tab the tab
     * @return the representative Item for the tab
     */
    public Item getTabRepresentative(int tab) {
        return verifyTab(tab).getFirst();
    }

    /**
     * Search and retrieves the Item when matches
     * @param matcher the matcher
     * @return the Item found, null if no such Item could be found
     */
    public Item locateItem(ItemMatcher matcher) {
        for(int i = 0; i < items.size(); i++){            
            Item item = items.get(i).find(matcher);
            if(item != null){
                return item;
            }
        }        
        return null;
    }

    /**
     * Gets the tab in which the matched Item if stored
     * @param matcher the matcher
     * @return the tab number, -1 if no matches have been found
     */
    public int getTab(ItemMatcher matcher) {
        Slot slot = getSlot(matcher);
        return slot == null ? -1 : slot.getTab();
    }
    
    /**
     * Retrieves the amount of bank tabs you currently have
     * @return the amount of bank tabs
     */
    public int tabCount() {
        return items.size();
    }

    /**
     * @return the total amount of occupied Slots in your bank
     */
    @Override
    public int size() {
        int size = 0;
        for(LinkedList<Item> l : items){
            size += l.size();            
        }
        return size;
    }

    @Override
    public Item set(int index, Item element) {
        if (index >= 0 && index < items.size()) {
            //TODO implement set functionality
        }
        throw new IndexOutOfBoundsException();
    }

    /**
     * Represents a Slot in the Bank
     */
    public static class Slot {

        private int tab;
        private int index;

        /**
         * Creates a new Slot with the specified tab with the specified index
         * @param tab the specified tab
         * @param index the specified index
         */
        public Slot(int tab, int index) {
            assert tab >= 0 && index >= 0 && tab < TAB_COUNT;
            this.tab = tab;
            this.index = index;
        }

        /** 
         * @return the tab number of this Slot
         */
        public int getTab() {
            return tab;
        }

        /**
         * @return The index of this Slot
         */
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
