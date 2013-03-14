package test.model;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import powergrid.model.GameObject;
import powergrid.model.Point;
import powergrid.model.WorldMap;

public class WorldMapTest {
    
    public WorldMap map;
    
    @Before public void setup() {
        map = new WorldMap(6);
    }
    
    @Test public void testGetEmpty() {
        assertNull(map.get(new Point(3,4)));
    }
    
    @Test public void testGetNotEmpty() {
        GameObject go = new GameObject(new Point(3,4),null,3);
        map.put(go);
        assertEquals(go,map.get(new Point(3,4)));
    }
    
    @Test public void testSize() {
        map.put(new GameObject(new Point(5,6),null,3));
        assertEquals(1,map.size());
    }
    
    @Test public void testPutMask() {
        Point p = new Point(5,6);
        map.put(new GameObject(p,null,3));
        map.putMask(p, 4);
        assertEquals(4,map.get(p).getCollisionFlag());
    }
    
    @Test public void testIsBoundaryTrue() {
        Point p = new Point(4,3);
        map.put(new GameObject(p,null,3));
        assertTrue(map.isBoundary(p, 2));
    }
    
    @Test public void testIsBoundaryFalse() {
        Point p = new Point(4,3);
        map.put(new GameObject(p,null,5));
        assertFalse(map.isBoundary(p, 2));
    }
    
    @Test public void testEqualsSame() {
        map.put(new GameObject(new Point(4,6),null,28));
        assertEquals(map,map);
    }
    
    @Test public void testEqualsOther() {
        map.put(new GameObject(new Point(4,6),null,28));
        WorldMap other = new WorldMap(3);
        other.put(new GameObject(new Point(4,6),null,14));
        assertFalse(map.equals(other));
    }
}
