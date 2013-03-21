package test.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import static org.hamcrest.CoreMatchers.*;
import org.hamcrest.Matcher;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;
import powergrid.model.Point;
import powergrid.model.XMLNode;
import powergrid.task.TravelNearestTask;

public class TravelNearestTaskTest {
    
    private static TravelNearestTask t;
    
    @Before public void setUp() {
        t = new TravelNearestTask("WaterSource");
    }
    
    @Test public void testGetters() {
        assertEquals("Test getType()","WaterSource", t.getType());
        assertEquals("Test getTarget()","", t.getTarget());
        assertEquals("Test getTraits()","", t.getTraits());
    }
    
    @Test public void testMatchingOnMismatch() {
        List<XMLNode> matches = t.getMatching();
        ArrayList<Matcher<? extends String>> allowedValues = new ArrayList<>();
        allowedValues.add(is("Fountain"));
        allowedValues.add(is("Sink"));
        for (XMLNode match : matches) {
            assertThat(match.get("target"),anyOf(allowedValues));
        }
    }
    
    @Test public void testMatchingOnMismatchWithTargetFilter() {
        TravelNearestTask t2 = new TravelNearestTask("WaterSource", "Fountain");
        List<XMLNode> matches = t2.getMatching();
        for (XMLNode match : matches)
            assertEquals("Fountain", match.get("target"));
        assertEquals(5, matches.size());
    }
    
    @Test public void testMatchingOnCompleteness() {
        List<XMLNode> matches = t.getMatching();
        assertEquals(7, matches.size());
    }
    
    @Test public void testGetMatchingEmptyType() {
        TravelNearestTask t2 = new TravelNearestTask("Watermill");
        List<XMLNode> matching = t2.getMatching();
        // Watermill has no contents, empty Iterable is expected
        assertNotNull(matching);
        assertEquals(0, matching.size());
    }
    
    @Test public void testGetMatchingNonExistingType() {
        TravelNearestTask t2 = new TravelNearestTask("NonExistingType");
        List<XMLNode> matches = t2.getMatching();
        // NonExistingType does not exists, null is expected
        assertNull(matches);
    }
    
    @Ignore("Not working due to work on Mapper and WorldMap")
    @Test public void testCalculateNearest() {
        List<XMLNode> matches = t.getMatching();
        List<Point> path = TravelNearestTask.calculateNearest(new Point(3100,3463), matches);
        
        assertEquals(new Point(3191,3469), path.get(path.size()-1));
    }
    
    @Test public void testGetMatchingTraits() {
        TravelNearestTask t2 = new TravelNearestTask("MagicCarpet",null,"Shantay Pass");
        List<XMLNode> matches = t2.getMatching();
        assertEquals(1, matches.size());
        XMLNode res = matches.get(0);
        assertEquals("(3309,3109)", res.get("pos"));
    }
    
    @Test public void testCalculateNearestNoMatches() {
        List<XMLNode> matches = new ArrayList<>();
        List<Point> path = TravelNearestTask.calculateNearest(new Point(), matches);
        assertNull(path);
    }
    
    @Ignore // note: this test takes ~12 seconds to complete (it tests if the timeout works)
    @Test public void testCalculateNearestTimeOut() {
        XMLNode[] nodes = new XMLNode[60];
        HashMap<String,String> atts = new HashMap<>();
        atts.put("pos", new Point().toString());
        atts.put("target", "Fountain");
        XMLNode data = new XMLNode("location",atts);
        for (int i=0;i<nodes.length;i++) {
            nodes[i] = data;
        }
        List<Point> path = TravelNearestTask.calculateNearest(new Point(200,200), Arrays.asList(nodes));
        assertEquals(new Point(), path.get(path.size()-1));
    }
}
