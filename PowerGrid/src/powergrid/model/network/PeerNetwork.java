package powergrid.model.network;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * This TransportNetwork represents a network in which all elements are interconnected.
 * <p/>
 * It uses a HashSet to store the elements for fast access, meaning that the 
 * contains, add and remove methods run in O(1).
 * <p/>
 * Since all nodes in the network are interconnected, the findPath method always 
 * returns a List containing only the destination as long as both the source and 
 * destination are contained in this network. Because of this, the findPath method 
 * also runs in O(1).
 * <p/>
 * @author Chronio
 */
public class PeerNetwork implements TransportNetwork {

    private HashSet<NetworkElement> elements;
    
    /**
     * Creates a new PeerNetwork with a initial capacity of 16.
     */
    public PeerNetwork() {
        elements = new HashSet<>();
    }
    /**
     * Creates a new PeerNetwork with a custom initial capacity.
     * @param size the initial capacity.
     */
    public PeerNetwork(int size) {
        elements = new HashSet<>(size);
    }
    
    /**
     * Returns true if the element is contained in this PeerNetwork
     * @param element the element to look up
     * @return true if this PeerNetwork contains the given element, false otherwise.
     */
    @Override public boolean contains(NetworkElement element) {
        return elements.contains(element);
    }

    /**
     * Adds the given element to this PeerNetwork
     * @param element the element to add
     * @return true if the PeerNetwork did not yet contain this element and has now been added.
     */
    @Override public boolean add(NetworkElement element) {
        if (elements.contains(element))
            return false;
        return elements.add(element);
    }

    /**
     * Removes the given element from this PeerNetwork
     * @param element the element to remove
     * @return true if the PeerNetwork contained the element and it has now been removed, false otherwise
     */
    @Override public boolean remove(NetworkElement element) {
        return elements.remove(element);
    }

    /**
     * Returns the amount of Peers in this PeerNetwork
     * @return the amount of peers in this PeerNetwork
     */
    @Override public int size() {
        return elements.size();
    }

    /**
     * Returns a List containing the destination Transportable if both the 
     * source and destination are peers in this network. Returns null otherwise.
     * @param source the source Transportable
     * @param destination the destination Transportable
     * @return the path from source to destination, or null if no path exists.
     */
    @Override public List<NetworkElement> findPath(NetworkElement source, NetworkElement destination) {
        if (elements.contains(source) && elements.contains(destination)) {
            List<NetworkElement> list = new ArrayList<>(1);
            list.add(destination);
            return list;
        } else 
            return null;
    }
    
    @Override public Set<NetworkElement> getElements() {
        return new HashSet<>(elements);
    }
}
