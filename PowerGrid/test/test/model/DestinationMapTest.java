package test.model;

import java.util.HashMap;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import powergrid.model.DestinationMap;
import powergrid.model.Point;

public class DestinationMapTest {
    
    public DestinationMap dests;
    
    @Before public void setup() {
        dests = new DestinationMap();
    }
    
    @Test public void testGetPut() {
        dests.register("Name", new Point(2,5));
        assertEquals(new Point(2,5),dests.getPoint("Name"));
    }
    
    @Test public void testOverwriteKey() {
        dests.register("name", new Point(2,4));
        dests.register("name", new Point(5,9));
        assertEquals(new Point(5,9), dests.getPoint("name"));
    }
    
    @Test public void testEquals() {
        dests.register("name", new Point(4,8));
        assertEquals(dests,dests);
        assertFalse(dests.equals(new DestinationMap()));
        DestinationMap other = new DestinationMap();
        other.register("name", new Point(4,8));
        assertEquals(other,dests);
    }
    
    @Test public void testWithDataHashMap() {
        HashMap<String,Point> vals = new HashMap<>(4);
        vals.put("name", new Point(4,6));
        vals.put("name2", new Point(5,7));
        DestinationMap other = new DestinationMap();
        other.register("name", new Point(4,6));
        other.register("name2", new Point(5,7));
        
        dests.withData(vals);
        assertEquals(other, dests);
    }
    
    @Test public void testCopy() {
        assertEquals(dests, dests.copy());
        dests.register("name", new Point(4,12));
        DestinationMap cp = dests.copy();
        assertEquals(dests, cp);
        dests.register("name", new Point(12,4));
        assertFalse(dests.equals(cp));
        assertEquals(dests,dests.copy());
    }
}
