/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.item;

import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Objects;

/**
 *
 * @author Vincent W
 */
public class FixedItemList extends AbstractList<Item> {
    
    private Item[] items;
    private int size;
    
    /**
     * Creates a new FixedItemList
     * @param capacity the capacity of the FixedItemList
     */
    public FixedItemList(int capacity){
        size = 0;
        items = new Item[capacity];   
    }

    /**
     * Creates a new FixedItemList with specified items
     * @param capacity  the capacity of the FixedItemList
     * @param items the Items
     */
    public FixedItemList(int capacity, Item[] items){
        size = 0;
        this.items = Arrays.copyOf(items, capacity);
        for(Item i : this.items) {
            if(i != null){
                size++;
            }
        }
    }
    
     /**
     * Sets a new Item to the specified index.
     *
     * @throws IndexOutOfBoundsException when index &lt; 0 or index &gt;
     * capacity()
     * @param index the index
     * @param element the new Item
     * @return the previous Item
     */
    @Override
    public Item set(int index, Item element) {
        if (index >= 0 && index < items.length) {
            Item original = items[index];
            items[index] = element;
            if (original != null && element == null) {
                size--;
            } else if (original == null && element != null) {
                size++;
            }
            return original;
        }
        throw new IndexOutOfBoundsException();
    }
    
    /**
     * 
     * @return the amount of Item slots.
     */
    public int capacity(){
        return items.length;
    }
    
     /**
     * Removes the item at the specified index
     *
     * @param index the index
     * @return the previous Item
     */
    @Override
    public Item remove(int index) {
        return set(index, null);
    }

    /**
     *
     * @return All the items from the Inventory
     */
    public Item[] getAllItems() {
        Item[] clone = Arrays.copyOf(items, items.length);
        return clone;
    }

    /**
     * Returns the Item that occupies the specified index.
     *
     * @param index the index
     * @return the item at the specified index or null if no such item exists
     */
    @Override
    public Item get(int index) {
        if (index >= 0 && index < items.length) {
            return items[index];
        }
        return null;
    }

    /**
     * Checks whether or not the specified index contains an Item.
     *
     * @param index the index
     * @return true if it is occupied, false otherwise.
     */
    public boolean isOccupied(int index) {
        return get(index) != null;
    }

    /**
     * Checks if the Inventory contains the specified Item.
     *
     * @param it the Item
     * @return true if it contains the item, false otherwise.
     */
    public boolean contains(Item it) {
        return indexOf(it) < 0;
    }

    /**
     * Returns the first occurrence of the specified Item.
     *
     * @param it the Item
     * @return the index of the first match
     */
    public int indexOf(Item it) {
        for (int i = 0; i < items.length; i++) {
            if (Objects.equals(it, items[i])) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Returns all indices of the specified Item
     *
     * @param it the Item
     * @return a collection of indices
     */
    public Collection<Integer> allIndexOf(Item it) {
        ArrayList<Integer> indices = new ArrayList<>(items.length);
        for (int i = 0; i < items.length; i++) {
            if (Objects.equals(it, items[i])) {
                indices.add(i);
            }
        }
        return indices;
    }

    /**
     * Returns the amount of the specified items your Inventory contains.
     *
     * @param it the Item
     * @return the amount of the Item
     */
    public int count(Item it) {
        return allIndexOf(it).size();
    }
    
     /**
     * @return the amount of items in your inventory
     */
    @Override
    public int size() {
        return size;
    }
    
     /**
     * Checks if your Inventory is full
     * @return true if all slots are occupied, false otherwise.
     */
    public boolean isFull() {
        return size() == capacity();
    }
}
