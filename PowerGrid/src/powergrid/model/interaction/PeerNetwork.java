package powergrid.model.interaction;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import powergrid.model.interact.Transportable;

/**
 * This TransportNetwork represents a network in which all elements are interconnected.
 * <p/>
 * It uses a HashSet to store the elements for fast access, meaning that the 
 * contains, add and remove methods run in O(1).
 * <p/>
 * Since all nodes in the network are interconnected, the findPath method always 
 * returns a List containing only the destination as long as both the source and 
 * destination are contained in this network.
 * <p/>
 * @author Chronio
 */
public class PeerNetwork implements TransportNetwork<Transportable> {

    private HashSet<Transportable> elements;
    
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
    
    @Override public boolean contains(Transportable element) {
        return elements.contains(element);
    }

    @Override public boolean add(Transportable element) {
        if (elements.contains(element))
            return false;
        return elements.add(element);
    }

    @Override public boolean remove(Transportable element) {
        return elements.remove(element);
    }

    @Override public int size() {
        return elements.size();
    }

    @Override public List<Transportable> findPath(Transportable source, Transportable destination) {
        if (elements.contains(source) && elements.contains(destination)) {
            List<Transportable> list = new ArrayList<>(1);
            list.add(destination);
            return list;
        } else 
            return null;
    }
}
