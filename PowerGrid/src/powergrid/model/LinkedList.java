package powergrid.model;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;

/**
 * This class represents a LinkedList structure.
 * @param <T> the type of elements stored in this LinkedList
 * @author Alaineman
 */
public class LinkedList<T> implements Iterable<T>, Copyable {

    private LinkedListNode<T> end;
    private int size;

    /**
     * Creates a new empty LinkedList.
     */
    public LinkedList() {
        end = null;
        size = 0;
    }

    /**
     * Checks if the LinkedList is empty.
     * @return true when empty, false otherwise
     */
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * Retrieves the element of the first node of the LinkedList.
     * @return the element of the first node
     */
    public T getFirst() {
        if (isEmpty()) {
            return null;
        }
        return end.getNext().getElement();
    }

    /**
     * Retrieves the element of the last node of the LinkedList.
     * @return the element of the last node
     */
    public T getLast() {
        if (isEmpty()) {
            return null;
        }
        return end.getElement();
    }

    /**
     * Adds a new node to the list as the primary node. 
     * <p>
     * Note: In the case the LinkedList is empty the result of adding by using
     * addFirst() and addLast() is the same.
     * <p>
     * Note: Even null objects can be stored in a LinkedList therefore 
     * this method will return true for any element. 
     * @param element the specified object the node refers to.
     * @return true;
     */
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

    /**
     * Concatenates the specified LinkedList to the original LinkedList.
     * <p>
     * Note: A copy will be used of the given LinkedList.
     * <P>
     * Note: The parameter list and the original list have to be of the same 
     * object type T.
     * @param list the specified LinkedList of type T
     * @return true if the list is not null, otherwise false.
     */
    public boolean concat(LinkedList<T> list) {
        if (list == null) {
            return false;
        }
        list = list.copy();
        LinkedListNode<T> first = end.getNext();
        end.setNext(list.end.getNext());
        list.end.setNext(first);
        return true;
    }

     /**
     * Adds a new node to the list as the end node. 
     * <p>
     * Note: In the case the LinkedList is empty the result of adding by using
     * addFirst() and addLast() is the same.
     * <p>
     * Note: Even null objects can be stored in a LinkedList therefore 
     * this method will return true for any element. 
     * @param element the specified object the node refers to.
     * @return true;
     */
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

    /**
     * Removes the first node in the LinkedList
     * <p>
     * Note: the last node will now link to the new first node, 
     * the original second node, if such node exists.
     * @return the removed element of the first node when the LinkedList 
     * is not empty, null otherwise
     */
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

    /**
     * Removes the last node in the LinkedList
     * <p>
     * Note: the second to last node will now be the last node 
     * and link to the first node, if both these nodes exists.
     * @return the removed element of the last node when the LinkedList 
     * is not empty, null otherwise
     */
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

    /**
     * Removes the node containing the specified element from the LinkedList
     * <p>
     * The previous and the next node, if they both exist, will now be linked 
     * to one another
     * @param element the specified element
     * @return the element if it exists in the LinkedList, null otherwise
     */
    public T remove(T element) {
        if (size == 0) {
            return null;
        }
        if (size == 1) {
            if (Objects.equals(end.getElement(), element)) {
                end = null;
                size = 0;
                return element;
            }
            return null;
        }
        LinkedListNode<T> previous = getPrevious(element);
        if (previous == null) {
            return null;
        }
        T result = previous.getNext().getElement();
        previous.setNext(previous.getNext().getNext());
        size--;
        return result;
    }

    /**
     * Removes the node at the specified index
     * @param index the specified index
     * @return the element from the node at the specified index if the index 
     * is within the LinkedList, null otherwise
     */
    public T remove(int index) {
        assert index < size();
        if (size == 0) {
            return null;
        }
        if (size == 1) {
            if (index == 0) {
                T element = end.getElement();
                end = null;
                size = 0;
                return element;
            }
            return null;
        }
        LinkedListNode<T> current = end;
        for (int i = 0; i < index; i++) {
            current = current.getNext();
        }
        T result = current.getNext().getElement();
        current.setNext(current.getNext().getNext());
        return result;
    }

    /**
     * Removes the node to which element the matcher matches the object T
     * @param matcher the specified matcher
     * @return the element of the removed node if the matcher found a match,
     * null otherwise
     */
    public T remove(Matcher<T> matcher) {
        if (size == 0) {
            return null;
        }
        if (size == 1) {
            T element = end.getElement();
            if (matcher.matches(element)) {
                end = null;
                size = 0;
                return element;
            }
            return null;
        }
        LinkedListNode<T> current = end;
        do {
            T element = current.getNext().getElement();
            if (matcher.matches(element)) {
                current.setNext(current.getNext().getNext());
                return element;
            } else {
                current = current.getNext();
            }
        } while (current != end);
        return null;
    }

    /**
     * Checks whether or not the specified element of type T belongs 
     * to any node within the LinkedList
     * @param element the specified element
     * @return true if one of the nodes contain element, false otherwise
     */
    public boolean contains(T element) {
        return getPrevious(element) != null;
    }

    /**
     * Inserts a new LinkedListNode with the specified element after 
     * the specified node named 'after'
     * @param after the element you want to insert something after
     * @param element the specified element to be inserted
     * @return true if after is found, false otherwise
     */
    public boolean insertAfter(T after, T element) {
        LinkedListNode<T> previous = getPrevious(after);
        if (previous != null) {
            LinkedListNode<T> original = previous.getNext();
            original.setNext(new LinkedListNode<>(element, original.getNext()));
            size++;
            return true;
        } else {
            return false;
        }
    }

    /**
     * Swaps two nodes by their respective elements of type T
     * @param elem1 the first element
     * @param elem2 the second element
     * @return true if: 
     * <ul> 
     * <li>both do not belong to the same node</li>
     * <li>the list is not empty</li>
     * <li>both elements belong to a node in the list</li>
     * </ul>
     * false if the conditions above are not met
     */
    public boolean swap(T elem1, T elem2) {
        if(size()< 2) return false;
        LinkedListNode<T> one = getPrevious(elem1);
        LinkedListNode<T> two = getPrevious(elem2);
        if (one != null || two != null) {
            LinkedListNode<T> nodeOne = one.getNext();
            LinkedListNode<T> nextOne = nodeOne.getNext();

            LinkedListNode<T> nodeTwo = two.getNext();
            LinkedListNode<T> nextTwo = nodeTwo.getNext();

            one.setNext(nodeTwo);
            nodeTwo.setNext(nextOne);
            two.setNext(nodeOne);
            nodeOne.setNext(nextTwo);
            return true;
        }
        return false;
    }

    /**
     * Swaps two nodes by their respective indices
     * @param index1 the first index
     * @param index2 the second index
     * @return true if: 
     * <ul> 
     * <li>both do not belong to the same node</li>
     * <li>the list is not empty</li>
     * <li>both elements belong to a node in the list</li>
     * </ul>
     * false if the conditions above are not met
     */
    public boolean swap(int index1, int index2) {
        if (index1 < 0 || index1 > size() || index2 < 0 || index2 > size() || index1 != index2) {
            return false;
        }
        LinkedListNode<T> node1 = null;
        LinkedListNode<T> node2 = null;
        LinkedListNode<T> current = end;
        for (int i = 0; i < Math.max(index1, index2); i++) {
            if (i + 1 == index1) {
                node1 = current;
            }
            if (i + 1 == index2) {
                node2 = current;
            }
            current = current.getNext();
        }
        if (node1 != null || node2 != null) {
            LinkedListNode<T> nodeOne = node1.getNext();
            LinkedListNode<T> nextOne = nodeOne.getNext();

            LinkedListNode<T> nodeTwo = node2.getNext();
            LinkedListNode<T> nextTwo = nodeTwo.getNext();

            node1.setNext(nodeTwo);
            nodeTwo.setNext(nextOne);
            node2.setNext(nodeOne);
            nodeOne.setNext(nextTwo);
            return true;
        }
        return false;
    }

     /**
     * Inserts a new LinkedListNode with the specified element before 
     * the specified node named 'before'
     * @param before the element you want to insert something before
     * @param element the specified element to be inserted
     * @return true if 'before' is found, false otherwise
     */
    public boolean insertBefore(T before, T element) {
        LinkedListNode<T> previous = getPrevious(before);
        if (previous != null) {
            previous.setNext(new LinkedListNode<>(element, previous.getNext()));
            size++;
            return true;
        } else {
            return false;
        }
    }

    /**
     * Finds the item which matches the specified matcher
     * <p> 
     * Note: this method has no use on a empty LinkedList
     * Just saying...
     * @param matcher the specified matcher
     * @return the object of type T if the matching object is found, 
     * null otherwise
     */
    public T find(Matcher<T> matcher) {
        if (size == 0) {
            return null;
        }
        if (size == 1) {
            T element = end.getElement();
            if (matcher.matches(element)) {
                return element;
            }
            return null;
        }
        LinkedListNode<T> current = end;
        do {
            if (matcher.matches(current.getNext().getElement())) {
                return current.getElement();
            } else {
                current = current.getNext();
            }
        } while (current != end);
        return null;
    }

    /**
     * Finds the index of the node to which the specified matcher 
     * matches the element of
     * @param matcher the specified matcher
     * @return the found index if such index exists, -1 otherwise
     */
    public int findIndex(Matcher<T> matcher) {
        if (size == 0) {
            return -1;
        }
        if (size == 1) {
            T element = end.getElement();
            if (matcher.matches(element)) {
                return 0;
            }
            return -1;
        }
        LinkedListNode<T> current = end;
        int i = 0;
        do {
             if (matcher.matches(current.getNext().getElement())) {
                return i;
            } else {
                current = current.getNext();
                i++;
            }
        } while (current != end);
        return -1;
    }

    /**
     * Retrieves the previous LinkedListNode to the node corresponding 
     * with element T
     * @param element the specified element of the node previous is linked to
     * @return the node previous to the node with the specified element 
     * if such node exist, null otherwise
     */
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

    /**
     * Retrieves the element of the node at the specified index
     * @param index the specified index
     * @return the element of the node, null if the index is invalid
     */
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

    /**
     * 
     * @return the amount of nodes within the LinkedList
     */
    public int size() {
        return size;
    }

    @Override
    public Iterator<T> iterator() {
        return null;
    }

    @Override
    public LinkedList<T> copy() {
        LinkedList<T> copy = new LinkedList<>();
        copy(copy, end.getNext());
        return copy;
    }
   
    private void copy(LinkedList<T> list, LinkedListNode<T> node) {
        if (node == end) {
            list.addFirst(end.getElement());
        } else {
            copy(list, node.getNext());
            list.addFirst(node.getElement());
        }
    }
    
    /**
     * The LinkedListIterator class
     * Enables iteration to the LinkedList
     */
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
