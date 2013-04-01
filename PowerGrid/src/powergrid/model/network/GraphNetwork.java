/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.network;

import java.util.List;
import java.util.Set;
import powergrid.model.TransportTile;

/**
 *
 * @author Vincent W
 */
public class GraphNetwork implements TransportNetwork {

    @Override
    public boolean contains(TransportTile element) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean add(TransportTile element) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean remove(TransportTile element) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public int size() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public List<TransportTile> findPath(TransportTile source, TransportTile destination) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Set<TransportTile> getElements() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
    public Set<TransportTile> getAdjacentTiles(TransportTile tile) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
