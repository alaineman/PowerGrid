/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model;

import java.util.Objects;

/**
 * This class represents a node object to a LinkedList.
 * <p> 
 * A node consists of an element and is linked to a next node. This generic 
 * structure is suitable for every object T.
 * 
 * @param <T> the type of object the node contains as element.
 * @author Alaineman
 */
public class LinkedListNode<T> {
    
    private T element;
    private LinkedListNode<T> next;
    
    /**
     * Creates a new LinkedListNode.
     * @param element the specified element this node refers to.
     * @param next the specified node this node refers to.
     */
    public LinkedListNode(T element, LinkedListNode<T> next){
        this.element = element;
        this.next = next;
    }

    /**
     * 
     * @return the element the node refers to.
     */
    public T getElement() {
        return element;
    }

    /**
     * 
     * @return the next node in the LinkedList.
     * @see LinkedList
     */
    public LinkedListNode<T> getNext() {
        return next;
    }
    
    /**
     * Links to a new node and returns the old node.
     * @param nextNode the new node link this node to.
     * @return the old node this node was linking to.
     */
    public LinkedListNode<T> setNext(LinkedListNode<T> nextNode) {
        LinkedListNode<T> temp = next;
        next = nextNode;
        return temp;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 71 * hash + Objects.hashCode(this.element);
        hash = 71 * hash + Objects.hashCode(this.next);
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
        final LinkedListNode<T> other = (LinkedListNode<T>) obj;
        if (!Objects.equals(this.element, other.element)) {
            return false;
        }       
        return true;
    }
    
    
}
