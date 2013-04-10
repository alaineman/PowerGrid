package test.control;

import java.util.Arrays;
import java.util.List;
import static org.junit.Assert.*;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import powergrid.control.PathFinder;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.structure.WorldMap;
import static powergrid.model.world.Wall.*;

@RunWith(Parameterized.class)
public class PathFinderTest {
    
    public static WorldMap theMap;
    
    @BeforeClass public static void setup() {
        theMap = new WorldMap(10);
        theMap.putMask(new Point(0,1),BLOCK);
        theMap.putMask(new Point(1,1),BLOCK);
        theMap.putMask(new Point(2,0),BLOCK);
        theMap.putMask(new Point(2,2),BLOCK);
        theMap.putMask(new Point(3,1),BLOCK);
    }
    
    /**
     * Convenience method for creating points used in the parameters for
     * fluency and readablitily.
     * @param x the Point's x coordinate
     * @param y the Point's y coordinate
     * @return a Point instance representing the position identified by (x,y)
     */
    public static Point p(int x, int y) {
        return new Point(x,y);
    }
    
    /**
     * Convenience method for creating a list of Points, providing better 
     * readability in this test class' Parameters method.
     * @param ps the array of Points to be used as path
     * @return a List representation of the specified Points.
     */
    public static List<Point> path(Point... ps) {
        return Arrays.asList(ps);
    }
    
    @Parameterized.Parameters
    public static List<Object[]> data() {
        return Arrays.asList(new Object[][] {
            /* { start,goal, expected path }*/
            { p(0,0),p(1,0), path(p(1,0)) },
            { p(3,2),p(3,0), path(p(4,2), p(4,1), p(4,0), p(3,0)) },
            { p(2,1),p(1,2), null},
            { p(2,1),p(2,1), path() }
        });
    }
    
    private List<Point> path;
    private PathFinder pathfinder;
    
    public PathFinderTest(Point start, Point goal, List<Point> path) {
        this.path = path;
        pathfinder = new PathFinder(start, goal).withMap(theMap);
    }
    
    @Test public void testPath() {
        try {
            List<Point> ps = pathfinder.calculatePrecise();
            assertArrayEquals(path.toArray(), ps.toArray());
        } catch (OutOfReachException e) {
            assertNull(path);
        }
    }
}
