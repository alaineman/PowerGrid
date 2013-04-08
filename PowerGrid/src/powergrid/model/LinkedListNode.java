/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model;

import java.util.Objects;

/**
 *
 * @author Vincent W
 */
public class LinkedListNode<T> {
    
    private T element;
    private LinkedListNode<T> next;
    
    public LinkedListNode(T element, LinkedListNode<T> next){
        this.element = element;
        this.next = next;
    }

    public T getElement() {
        return element;
    }

    public LinkedListNode<T> getNext() {
        return next;
    }
    
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
