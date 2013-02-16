package test.tasks;

import java.util.ArrayList;
import java.util.List;
import static org.hamcrest.CoreMatchers.*;
import org.hamcrest.Matcher;
import static org.junit.Assert.*;
import org.junit.BeforeClass;
import org.junit.Test;
import powerwalk.model.Point;
import powerwalk.model.XMLNode;
import powerwalk.tasks.TravelNearestTask;

public class TravelNearestTest {
    
    private static TravelNearestTask t;
    
    public TravelNearestTest() {}
    
    @BeforeClass public static void setUp() {
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
    
    @Test public void testCalculateNearest() {
        List<XMLNode> matches = t.getMatching();
        List<Point> path = TravelNearestTask.calculateNearest(new Point(3100,3463), matches);
        
        assertEquals(new Point(3191,3469), path.get(path.size()-1));
    }
}
