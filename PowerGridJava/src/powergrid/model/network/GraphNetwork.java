package powergrid.model.network;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Set;
import powergrid.model.OutOfReachException;

/**
 * TransportNetwork that is organized as a Graph.
 * @author Alaineman
 * @author Chronio
 */
public class GraphNetwork implements TransportNetwork {

    private HashMap<NetworkElement, Set<Edge>> nodes;
    
    public GraphNetwork() {
        nodes = new HashMap<>();
    }
    
    public boolean makeDirectedConnection(NetworkElement from, 
            NetworkElement to, int weight) {
        if (from != null && to != null && !Objects.equals(from, to)) {
            boolean elemAdded = false;
            if (!nodes.containsKey(from)) {
                add(from);
                elemAdded = true;
            }
            if (!nodes.containsKey(to)) {
                add(to);
                elemAdded = true;
            }
            if (elemAdded || !connectionExists(from, to)) {
                Set<Edge> edges = nodes.get(from);
                edges.add(new Edge(to,weight));
                return true;
            }
        }
        return false;
    }
    
    public boolean makeUndirectedConnection(NetworkElement e1, 
            NetworkElement e2, int weight) {
        return makeDirectedConnection(e1, e2, weight)
                && makeDirectedConnection(e2, e1, weight);
    }
    
    public boolean connectionExists(NetworkElement from, NetworkElement to) {
        if (nodes.containsKey(from) && nodes.containsKey(to)) {
            for (Edge e : nodes.get(from)) {
                if (e.getTo().equals(to)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    public Set<? extends NetworkElement> getAdjacentElements(NetworkElement tile) {
        Set<Edge> elems = nodes.get(tile);
        HashSet<NetworkElement> res = new HashSet<>(elems.size() * 8/7, 7/8f);
        for (Edge<NetworkElement> edge : elems) {
            res.add(edge.getTo());
        }
        return res;
    }

    @Override
    public boolean contains(NetworkElement element) {
        boolean result = nodes.containsKey(element);
        return result;
    }

    @Override
    public boolean add(NetworkElement element) {
        if (contains(element)) {
            return false;
        } else {
            nodes.put(element, new HashSet<Edge>(4));
            element.withNetwork(this);
            return true;
        }
    }

    @Override
    public boolean remove(NetworkElement element) {
        if (nodes.remove(element) != null) {
            element.withNetwork(null);
            return true;
        }
        return false;
    }

    @Override
    public int size() {
        return nodes.size();
    }

    @Override
    public List<NetworkElement> findPath(NetworkElement source,
            NetworkElement destination) throws OutOfReachException {
        if (!nodes.containsKey(source) || !nodes.containsKey(destination)) {
            throw new OutOfReachException("Not in this network");
        }
        final HashMap<NetworkElement, Integer> dist = 
                new HashMap(nodes.size()* 4/3);
        HashMap<NetworkElement, NetworkElement> prev = 
                new HashMap(nodes.size() * 4/3);
        PriorityQueue<NetworkElement> elems = new PriorityQueue<>(nodes.size(),
                new Comparator<NetworkElement>() {
                    @Override
                    public int compare(NetworkElement ne1, NetworkElement ne2) {
                        return dist.get(ne2).compareTo(dist.get(ne1));
                    }
                });
        
        for (NetworkElement e : nodes.keySet()) {
            dist.put(e, Integer.MAX_VALUE);
            prev.put(e, null);
        }
        dist.put(source, 0);
        
        while (!elems.isEmpty()) {
            NetworkElement u = elems.poll();
            if (u.equals(destination)) {
                return reconstruct(prev, u);
            }
            if (dist.get(u) == Integer.MAX_VALUE) {
                break;
            }
            
            for (Edge<NetworkElement> e : nodes.get(u)) {
                int old = dist.get(u);
                int alt = old + e.getWeight();
                NetworkElement ne = e.getTo();
                if (alt < dist.get(ne)) {
                    dist.put(ne, alt);
                    prev.put(ne, u);
                    if (!elems.contains(ne)) {
                        elems.offer(ne);
                    }
                }
            }
            
        }
        throw new OutOfReachException("No path found");
    }
    
    private List<NetworkElement> reconstruct(
            Map<NetworkElement, NetworkElement> prev, NetworkElement last) {
        ArrayList<NetworkElement> path = new ArrayList<>(nodes.size());
        NetworkElement u = last;
        while (prev.containsKey(u)) {
            path.add(u);
            u = prev.get(u);
        }
        Collections.reverse(path);
        return path;
    }

    @Override
    public Set<NetworkElement> getElements() {
        return nodes.keySet();
    }
    
}
