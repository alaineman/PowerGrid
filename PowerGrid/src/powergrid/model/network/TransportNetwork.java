package powergrid.model.network;

import java.util.List;
import java.util.Set;
import powergrid.model.OutOfReachException;

/**
 * This interface represents a network of Transport Tiles. 
 * <p/>
 * It offers methods to add or remove elements, a check for presence of a certain element, and a size method.
 * It also provides a method that finds a path between two elements in the network.
 * <p/>
 * @author Chronio
 */
public interface TransportNetwork {
    /**
     * returns true if and only if the specified element is contained in this network, returns false otherwise.
     * @param element the element to check
     * @return whether this network contains the given element
     */
    public boolean contains(NetworkElement element);
    /**
     * Adds the given element to this network.
     * @param element the element to add.
     * @return true if the element was successfully added, false otherwise
     */
    public boolean add(NetworkElement element);
    /**
     * removes the given element from this network.
     * @param element the element to remove.
     * @return true if this network contained the element and it was successfully removed, false otherwise
     */
    public boolean remove(NetworkElement element);
    /**
     * returns the amount of elements in this network
     * @return the amount of elements in this network
     */
    public int size();
    
    /**
     * returns a list denoting the path trough the network to the given destination.
     * @param source the starting point
     * @param destination the endpoint
     * @return a shortest path to the destination.
     * @throws OutOfReachException when there is no path between source and destination.
     */
    public List<NetworkElement> findPath(NetworkElement source, 
            NetworkElement destination) throws OutOfReachException;
    
    /**
     * Returns a Set containing the elements in this network.
     * @return a Set containing the elements in this network
     */
    public Set<NetworkElement> getElements();
    
}
