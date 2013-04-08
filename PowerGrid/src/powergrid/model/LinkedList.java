package powergrid.model;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;

/**
 *
 * @param <T> the type of elements stored in this LinkedList
 * @author Alaineman
 */
public class LinkedList<T> implements Iterable<T> {

    private LinkedListNode<T> end;
    private int size;

    public LinkedList() {
        end = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public T getFirst() {
        if (isEmpty()) {
            return null;
        }
        return end.getNext().getElement();
    }

    public T getLast() {
        if (isEmpty()) {
            return null;
        }
        return end.getElement();
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
        return getPrevious(element) != null;
    }

    public boolean insertAfter(T after, T element) {
        LinkedListNode<T> previous = getPrevious(after);
        if(previous != null){
            LinkedListNode<T> original = previous.getNext();
            original.setNext(new LinkedListNode<>(element, original.getNext()));
            size++;
            return true;
        } else {
            return false;
        }
    }

    public boolean swap(T elem1, T elem2) {
        return false;
    }

    public boolean insertBefore(T before, T element) {
        LinkedListNode<T> previous = getPrevious(before);
        if(previous != null){
            previous.setNext(new LinkedListNode<>(element, previous.getNext()));            
            size++;
            return true;
        } else {
            return false;
        }    
    }

    public T find(Matcher<T> matcher) {
        return getPrevious(Item).getNext().getElement();
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

    public T get(int index) {
        if (index < 0 || index >= size()) {
            return null;
        }
        LinkedListNode<T> node = end.getNext();
        for (int i = 0; i < index; i++) {
            node = node.getNext();
        }
        return node.getElement();
    }

    public int size() {
        return size;
    }

    @Override
    public Iterator<T> iterator() {
        return null;
    }

    public class LinkedListIterator implements Iterator<T> {

        // the node containing the node before the last returned element
        private LinkedListNode<T> previous = null;

        @Override
        public boolean hasNext() {
            if (size == 0) {
                return false;
            }
            if (size == 1) {
                return previous == null;
            }
            return previous.getNext() != end;
        }

        @Override
        public T next() {
            if (hasNext()) {
                if (previous == null) {
                    previous = end;
                }
                previous = previous.getNext();
                return previous.getNext().getElement();
            }
            throw new NoSuchElementException();
        }

        @Override
        public void remove() {
            previous.setNext(previous.getNext().getNext());
        }
    }
}
