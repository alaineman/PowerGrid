/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.item;

import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author Vincent W
 */
public class Bank extends AbstractList<Item> {
    
    public static final int TAB_SIZE = 9;
    
    private ArrayList<Item>[] items;
    private int size;
    private int tab_count;
    
    public Bank() {        
        size = 0;
        items = new ArrayList[TAB_SIZE];
    }
    
    public Bank(ArrayList<Item>[] items){
        size = 0;
        this.items = Arrays.copyOf(items, TAB_SIZE);
    }
    
    @Override
    public boolean add(Item item){
        return add(item, 0);
    }
    
    public boolean add(Item item, int tab) {
        if(tab >= TAB_SIZE || tab < 0) throw new IndexOutOfBoundsException();
        while(tab_count<tab){
            addTab();
        }
        ArrayList<Item> tabItems = items[tab];        
        size++;
        return tabItems.add(item);
    }
    
    public int addTab(){
        items[tab_count] = new ArrayList<>(5);
        return tab_count++;
    }
    
    public boolean isOccupied(int index){
        return false;
    }
    
    public boolean isOccupied(int tab, int slot){
        return false;
    }
    
    public int[] indexToTabSlot(int index){
        return new int[4];
    }
    
    public int tabSlotToIndex(int tab, int slot){
        return -1;
    }  
    
    public int getFreeSlot(int tab){
        return -1;
    }
    
    public int getFreeTab(){
        return -1;
    }
    
    public ArrayList<Item> swapItems(int one, int two){
        return new ArrayList();
    }
    
    public boolean swapItems(Item one, Item two){
        return true;
    }    
    
    @Override
    public Item remove(int id){
        return null;
    }   
    
    @Override
    public Item get(int index) {
        return null;
    }
    
    public int getIndex(Item item){
        return -1;
    }
    
    public int getIndex(int itemId){
        return -1;
    }
    
    public int getIndex(String itemName){
        return -1;
    }
    
    public List<Item> getAllItems(){
        return null;
    }
    
    public Item get(int tab, int slot){
        return null;
    }
    
    public Item getItem(int itemId){
        return null;
    }
    
    public ArrayList<Item> getItems(int[] itemIds) {
        return new ArrayList();
    }
    
    public int findTab(int itemId){
        return -1;
    }
    
    public int findTab(Item item){
        return -1;
    }
    
    public int findTab(String itemName){
        return -1;
    }
    
    public int findSlot(int itemId){
        return -1;
    }
    
    public int findSlot(Item item){
        return -1;
    }
    
    public int findSlot(String itemName){
        return -1;
    }
    
    public int tabCount(){
        return -1;
    }

    @Override
    public int size() {
        return size;
    }
    
    @Override 
    public Item set(int index, Item element){
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
    
    public static class Slot {
        
        private int tab;
        private int index;
        
        public Slot(int tab, int index){
            assert tab >= 0 && index >= 0 && tab < TAB_SIZE;
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
            if (this.tab != other.tab) {
                return false;
            }
            if (this.index != other.index) {
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
