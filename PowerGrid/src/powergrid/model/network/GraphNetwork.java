/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.network;

import java.util.HashMap;
import java.util.List;
import java.util.Set;
import powergrid.model.OutOfReachException;

/**
 *
 * @author Vincent W
 */
public class GraphNetwork implements TransportNetwork {

    private HashMap<NetworkElement, Set<Edge>> nodes;
    
    public Set<? extends NetworkElement> getAdjacentTiles(NetworkElement tile) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean contains(NetworkElement element) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public boolean add(NetworkElement element) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public boolean remove(NetworkElement element) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public int size() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public List<NetworkElement> findPath(NetworkElement source,
            NetworkElement destination) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Set<NetworkElement> getElements() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
