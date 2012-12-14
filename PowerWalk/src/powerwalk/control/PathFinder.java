package powerwalk.control;

import java.util.ArrayList;
import powerwalk.Bot;
import powerwalk.model.Collision;
import powerwalk.model.Point;

/**
 * This class finds a defined path between 2 points.
 *
 * @author Vincent W
 */
public class PathFinder {

    public ArrayList<Point> calculatePath(Point start, Point goal) {
        
        //Initialize the A* algorith.
        ArrayList<Point> closedSet = new ArrayList<Point>();
        ArrayList<Point> openSet = new ArrayList<Point>(); 
        openSet.add(start);
        
        
        
        
        
        
        return null;
    }

    /**
     * Calculates the cost between 2 points using the Euclidean distance.
     * @param start the base Point to calculate from
     * @param goal the end Point of the calculation.
     * @return returns the cost as a Double
     */
    public double heuristicCost(Point start, Point goal) {
        int dx = start.x - goal.x;
        int dy = start.y - goal.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
    
    /**
     * Check whether a Point it's GameObject is a Collision or not.
     * @param target the given Point to check.
     * @return see description.
     */
    public boolean isCollision(Point target){
        return (Bot.getBot().getWorldMap().get(target) instanceof Collision);
    }
}
