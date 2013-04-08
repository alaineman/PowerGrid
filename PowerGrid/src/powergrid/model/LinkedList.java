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
public class LinkedList<T> {

    private LinkedListNode<T> end;
    private int size;

    public LinkedList() {
        end = null;
        size = 0;
    }

    public boolean addFirst(T element) {
        if (end == null) {
            end = new LinkedListNode<>(element, null);
            end.setNext(end);
        } else {
            LinkedListNode<T> first = new LinkedListNode<>(element, end.getNext());
            end.setNext(first);
        }
        size++;
        return true;
    }

    public boolean addLast(T element) {
        if (end == null) {
            end = new LinkedListNode<>(element, null);
            end.setNext(end);
        } else {
            LinkedListNode<T> last = new LinkedListNode<>(element, end.getNext());
            end.setNext(last);
            end = last;
        }
        size++;
        return true;
    }

    public T removeFirst() {
        if (end == null) {
            return null;
        } else {
            LinkedListNode<T> temp = end.getNext();
            if (temp.equals(end)) {
                end = null;
                size = 0;
                return temp.getElement();
            }
            end.setNext(temp.getNext());
            size--;
            return temp.getElement();
        }
    }

    public T removeLast() {
        if (end == null) {
            return null;
        } else {
            LinkedListNode<T> temp = end.getNext();
            if (temp.equals(end)) {
                end = null;
                size = 0;
                return temp.getElement();
            }
            while (temp.getNext().getNext() != end) {
                temp = temp.getNext();
            }
            temp.setNext(end.getNext());
            T res = end.getElement();
            end = temp;
            size--;
            return res;
        }
    }

    public boolean remove(T element) {
        if (size == 0) {
            return false;
        }
        if (size == 1) {
            if (Objects.equals(end.getElement(), element)) {
                end = null;
                size = 0;
                return true;
            }
            return false;
        }
        LinkedListNode<T> previous = getPrevious(element);
        if (previous == null) {
            return false;
        }
        previous.setNext(previous.getNext().getNext());
        size--;
        return true;

    }

    public boolean contains(T element) {
        return true;
    }

    public boolean insertAfter(T after, T element) {
        return true;
    }

    public boolean insertBefore(T before, T element) {
        return true;
    }

    private LinkedListNode<T> getPrevious(T element) {
        LinkedListNode<T> current = end;
        while (!Objects.equals(current.getNext().getElement(), element) && current.getNext() != end) {
            current = current.getNext();
        }
        if (current.getNext() == end && !Objects.equals(current.getNext().getElement(), element)) {
            return null;
        } else {
            return current;
        }
    }
}
