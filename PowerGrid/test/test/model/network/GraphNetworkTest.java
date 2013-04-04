package test.model.network;

import java.util.Collections;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.TransportTile;
import powergrid.model.network.GraphNetwork;
import powergrid.model.network.NetworkElement;

/**
 * Test class that tests functionality of the GraphNetwork class.
 * @author Alaineman
 * @author Chronio
 */
public class GraphNetworkTest {
    
    private GraphNetwork graph;
    private NetworkElement elem, other;
    
    /**
     * Creates the GraphNetwork instance and two NetworkElements.
     */
    @Before public void setup() {
        graph = new GraphNetwork();
        elem = new TransportTile(new Point(), null, 0);
        other = new TransportTile(new Point(), null, 1);
    }
    
    /**
     * Tests add method for a single element.
     */
    @Test public void testAddSingleElement(){
        assertTrue(graph.add(elem));
    }
    
    /**
     * Tests whether the add sets the element's network correctly.
     */
    @Test public void testAddSetsElementsNetwork() {
        graph.add(elem);
        assertEquals(graph, elem.getNetwork());
    }
    
    /**
     * Tests whether contains returns true for a previously added element.
     */
    @Test public void testContainsSingleElement() {
        graph.add(elem);
        assertTrue(graph.contains(elem));
    }
    
    /**
     * Verifies that the size returns the correct value.
     */
    @Test public void testSizeNonEmptyGraph(){
        graph.add(elem);
        assertEquals(1, graph.size());
    }
    
    /**
     * Tests that the remove method returns true when removing a previously 
     * added element.
     */
    @Test public void testRemoveSingleExistingElement(){
        graph.add(elem);
        assertTrue(graph.remove(elem));
    }
    
    /**
     * Verifies that removing an element also sets the element's network 
     * to null.
     */
    @Test public void testRemoveSetsNetworkToNull() {
        graph.add(elem);
        graph.remove(elem);
        assertNull(elem.getNetwork());
    }
    
    /**
     * Tests that the size is 0 for an empty graph.
     */
    @Test public void testSizeEmptyGraph(){
        assertEquals(0, graph.size());
    }
    
    /**
     * Tests that remove returns false when removing an element that was not 
     * added to the graph.
     */
    @Test public void testRemoveSingleNonExistingElement(){
        graph.add(elem);
        assertFalse(graph.remove(other));
    }
    
    /**
     * Tests that the findPath method throws an OutOfReachException when the
     * start and end nodes are not connected.
     * @throws OutOfReachException as expected
     */
    @Test (expected = OutOfReachException.class) 
    public void testFindPathNonConnectedNonEmptyGraph() 
            throws OutOfReachException {
        graph.add(elem);
        graph.add(other);
        graph.findPath(elem, other);
    }
    
    /**
     * Tests that the makeConnection method returns the right value.
     */
    @Test public void testMakeDirectedConnectionForAddedElements() {
        graph.add(elem);
        graph.add(other);
        assertTrue(graph.makeDirectedConnection(elem, other, 1));
    }
    
    /**
     * Verifies that making a connection with the same object is not allowed.
     */
    @Test public void testMakeDirectedConnectionWithSameObject() {
        graph.add(elem);
        graph.add(other);
        assertFalse(graph.makeDirectedConnection(elem, elem, 1));
    }
    
    /**
     * Verifies that making an undirected connection returns true.
     */
    @Test public void testMakeUndirectedConnectionForAddedElements() {
        graph.add(elem);
        graph.add(other);
        assertTrue(graph.makeUndirectedConnection(elem, other, 1));
    }
    
    /**
     * Verifies that making a connection that already exists returns false.
     */
    @Test public void testMakeConnectionThatAlreadyExists() {
        graph.add(elem);
        graph.add(other);
        graph.makeDirectedConnection(elem, other, 1);
        assertFalse(graph.makeDirectedConnection(elem, other, 1));
    }
    
    /**
     * Verifies that a connection exists when added using 
     * makeDirectedConnection.
     */
    @Test public void testConnectionExistsForExistingConnection() {
        graph.add(elem);
        graph.add(other);
        graph.makeDirectedConnection(elem, other, 1);
        assertTrue(graph.connectionExists(elem, other));
    }
    
    /**
     * Verifies that a connection does not exist when such a connection has not
     * been made.
     */
    @Test public void testConnectionExistsForNonExistingConnection() {
        graph.add(elem);
        graph.add(other);
        graph.makeDirectedConnection(other, elem, 1);
        assertFalse(graph.connectionExists(elem, other));
    }
    
    /**
     * Verifies that connectionExists returns false when the end node is not in
     * the graph.
     */
    @Test public void testConnectionExistsForNonExistingEndNode() {
        graph.add(elem);
        assertFalse(graph.connectionExists(elem, other));
    }
    
    /**
     * Verifies that connectionExists returns false when the start node is not
     * in the graph.
     */
    @Test public void testConnectionExistsForNonExistingStartNode() {
        graph.add(elem);
        assertFalse(graph.connectionExists(other, elem));
    }
    
    /**
     * Tests that the getElements method contains the right values for a 
     * non-empty graph.
     */
    @Test public void testGetElementsNonEmptyGraph(){
        graph.add(elem);
        assertEquals(Collections.singleton(elem), graph.getElements());
    }
    
    /**
     * Tests that the getElements method returns the empty set for an empty 
     * graph.
     */
    @Test public void testGetElementsEmptyGraph(){
        assertEquals(Collections.emptySet(), graph.getElements());
    }
}
