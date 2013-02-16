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
        Iterable<XMLNode> matches = t.getMatching();
        ArrayList<Matcher<? extends String>> allowedValues = new ArrayList<>();
        allowedValues.add(is("Fountain"));
        allowedValues.add(is("Sink"));
        for (XMLNode match : matches) {
            assertThat(match.get("target"),anyOf(allowedValues));
        }
    }
    
    @Test public void testMatchingOnCompleteness() {
        Iterable<XMLNode> matches = t.getMatching();
        int length = 0;
        for (XMLNode match : matches) {
            if (match != null) 
                length++;
        }
        assertEquals(7, length);
    }
    
    @Test public void testGetMatchingEmptyType() {
        TravelNearestTask t2 = new TravelNearestTask("Watermill");
        Iterable<XMLNode> matching = t2.getMatching();
        // Watermill has no contents, empty Iterable is expected
        assertNotNull(matching);
        int length = 0;
        for (XMLNode n : matching) {
            if (n != null) 
                length++;
        }
        assertEquals(0, length);
    }
    
    @Test public void testGetMatchingNonExistingType() {
        TravelNearestTask t2 = new TravelNearestTask("NonExistingType");
        Iterable<XMLNode> matches = t2.getMatching();
        // NonExistingType does not exists, null is expected
        assertNull(matches);
    }
    
    @Test public void testCalculateNearest() {
        Iterable<XMLNode> matches = t.getMatching();
        List<Point> path = TravelNearestTask.calculateNearest(new Point(3100,3463), matches);
        
        assertEquals(new Point(3207,3463), path.get(path.size()-1));
    }
}
