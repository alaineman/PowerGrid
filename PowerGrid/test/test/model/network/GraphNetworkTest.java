/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.model.network;

import java.util.Collections;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.TransportTile;
import powergrid.model.network.GraphNetwork;
import powergrid.model.network.NetworkElement;

/**
 *
 * @author Vincent W
 */
public class GraphNetworkTest {
    
    public GraphNetwork graph;
    public NetworkElement elem;
    
    @Before public void setup() {
        graph = new GraphNetwork();
        elem = new TransportTile(new Point(), null, 2);
    }
    
    @Test public void testAddSingleElement(){
        assertTrue(graph.add(elem));
    }
    
    @Test public void testContainsSingleElement() {
        graph.add(elem);
        assertTrue(graph.contains(elem));
    }
    
    @Test public void testSizeNonEmptyGraph(){
        graph.add(elem);
        assertEquals(1, graph.size());
    }
    
    //Test fails
    @Test public void testRemoveSingleExistingElement(){
        graph.add(elem);
        assertTrue(graph.remove(elem));
    }
    
    @Test public void testSizeEmptyGraph(){
        assertEquals(0, graph.size());
    }
    
    @Test public void testRemoveSingleNonExistingElement(){
        graph.add(elem);
        NetworkElement other = new TransportTile(new Point(1,4), null, 3);
        assertFalse(graph.remove(other));
    }
    
    @Test (expected = OutOfReachException.class) 
    public void testFindPathNonConnectedNonEmptyGraph() throws OutOfReachException {
        NetworkElement other = new TransportTile(new Point(3,3), null, 1);
        graph.add(elem);
        graph.add(other);
        graph.findPath(elem, other);
    }
    
    //TODO: test findPath() for a connected non empty graph   
    
    @Test public void testGetElementsNonEmptyGraph(){
        graph.add(elem);      
        assertEquals(Collections.singleton(elem), graph.getElements());
    }
    
    @Test public void testGetElementsEmptyGraph(){
        assertEquals(Collections.emptySet(), graph.getElements());
    }
}
