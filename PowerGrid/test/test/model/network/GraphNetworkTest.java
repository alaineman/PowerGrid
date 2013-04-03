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
    
    
    @Before public void setup() {
        graph = new GraphNetwork();
    }
    
    @Ignore
    @Test public void testGetAdjacentElements(){
        
    }
    
    //Test fails
    @Test public void testAddSingleElement(){
        NetworkElement e1 = new TransportTile(new Point(), null, 2);
        graph.add(e1);
        assertTrue(graph.contains(e1));
    }
    
    @Test public void testSizeNonEmptyGraph(){
        NetworkElement e1 = new TransportTile(new Point(), null, 2);
        graph.add(e1);
        assertEquals(1, graph.size());
    }
    
    //Test fails
    @Test public void testRemoveSingleExistingElement(){
        NetworkElement e1 = new TransportTile(new Point(), null, 2);
        graph.add(e1);
        assertTrue(graph.remove(e1));
    }
    
    @Test public void testSizeEmptyGraph(){
        assertEquals(0, graph.size());
    }
    
    @Test public void testRemoveSingleNonExistingElement(){
        NetworkElement e1 = new TransportTile(new Point(), null, 2);
        graph.add(e1);
        NetworkElement e2 = new TransportTile(new Point(1,4), null, 3);
        assertFalse(graph.remove(e2));
    }
    
    @Test (expected = OutOfReachException.class) 
    public void testFindPathNonConnectedNonEmptyGraph() throws OutOfReachException {
        NetworkElement e1 = new TransportTile(new Point(), null, 2);
        NetworkElement e2 = new TransportTile(new Point(3,3), null, 1);
        graph.add(e1);
        graph.add(e2);
        graph.findPath(e1, e2);
    }
    
    //TODO: test findPath() for a connected non empty graph   
    
    @Test public void testGetElementsNonEmptyGraph(){
        NetworkElement e1 = new TransportTile(new Point(), null, 2);
        graph.add(e1);      
        assertEquals(Collections.singleton(e1), graph.getElements());
    }
    
    @Test public void testGetElementsEmptyGraph(){
        assertEquals(Collections.emptySet(), graph.getElements());
    }
}
