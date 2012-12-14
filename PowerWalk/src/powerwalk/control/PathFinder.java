package powerwalk.control;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
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
        HashMap<Point, Integer> pathCost = new HashMap<>();
        pathCost.put(start, 0);
        start.f_score = pathCost.get(start) + heuristicCost(start, goal);
        PriorityQueue<Point> pending = new PriorityQueue<>();
        pending.offer(start);
        double tempPathCost = 0;

        //Start the spread
        while (!pending.isEmpty()) {
            Point current = pending.poll();
            Point[] adjacents = current.getAdjacentPoints();
            closedSet.add(current);
            for (Point p : adjacents) {
                if (closedSet.contains(p) || isCollision(p)) {
                    continue;
                }
                p.previous = current; //wanneer moet dit?
                tempPathCost = pathCost.get(p) + 1;
                p.f_score = pathCost.get(current) + 1;
                pending.offer(p);
            }
        }


        return null;
    }

    /**
     * Calculates the cost between 2 points using the Euclidean distance.
     *
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
     *
     * @param target the given Point to check.
     * @return see description.
     */
    public boolean isCollision(Point target) {
        return (Bot.getBot().getWorldMap().get(target) instanceof Collision);
    }
}
