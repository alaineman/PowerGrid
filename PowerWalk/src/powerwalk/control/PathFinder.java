package powerwalk.control;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;
import powerwalk.Bot;
import powerwalk.model.Collision;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 * This Utility class deals with finding a path between two Points in the RSBot environment.
 *
 * @author Vincent W, P.Kramer
 */
public abstract class PathFinder {
    
    /** The maximum distance between two Points in the result Path. */
    public static final int maxDist = 20; //TODO (0) check the display range of the minimap to set maxDist
    
    /**
     * Calculates a path between start and goal using the A* algorithm.
     * @param start The start Point
     * @param goal The goal Point
     * @return A Path from start to goal
     * @throws OutOfReachException When no path between start and goal exists
     */
    public static ArrayList<Point> calculatePath(Point start, Point goal) throws OutOfReachException {

        //Initialize the A* algorith.
        HashSet<Point> closedSet = new HashSet<>();
        PriorityQueue<Point> pending = new PriorityQueue<>();
        HashMap<Point, Double> pathCost = new HashMap<>();
        HashMap<Point,Point> came_from = new HashMap<>();
        
        pathCost.put(start, 1d);
        
        start.f_score = heuristicCost(start, goal);
        
        pending.offer(start);

        //Start the spread
        while (!pending.isEmpty()) {
            Point current = pending.poll();
            if (current.equals(goal)) {
                ArrayList<Point> fullPath = reconstruct(came_from,goal);
                return fullPath;//reducePoints(fullPath,maxDist);
            }
            closedSet.add(current);
            Point[] adjacents = current.getAdjacentPoints();
            for (int i=0;i<adjacents.length;i++) {
                Point p = adjacents[i];
                if (closedSet.contains(p) || isCollision(p)) {
                    continue;
                }
                double tempPathCost = pathCost.get(current) + 1;
                
                boolean isPending = pending.contains(p);
                if (!isPending || tempPathCost <= pathCost.get(p) || pathCost.get(p) == 0) {
                    came_from.put(p, current);
                    pathCost.put(p, tempPathCost);
                    p.f_score = tempPathCost + heuristicCost(p,goal);
                    if (!isPending) {
                        pending.offer(p);
                    }
                }
                
                p.f_score = pathCost.get(current) + 1;
                pending.offer(p);
            }
        }
        throw new OutOfReachException(goal,"Destination could not be reached");
    }
    
    private static double heuristicCost(Point start, Point goal) {
        // calculates the length between start and goal
        int dx = start.x - goal.x;
        int dy = start.y - goal.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
    
    private static boolean isCollision(Point target) {
        // checks whether target contains a Collision-object
        return (Bot.getBot().getWorldMap().get(target) instanceof Collision);
    }
    
    private static ArrayList<Point> reconstruct(HashMap<Point,Point> came_from, Point current) {
        // reconstruct the path from the came_from HashMap
        Point previous = came_from.get(current);
        if (previous == null) {
            ArrayList<Point> thePath = new ArrayList<>();
            thePath.add(current);
            return thePath;
        } else {
            ArrayList<Point> thePath = reconstruct(came_from,  came_from.get(current));
            thePath.add(current);
            return thePath;
        }
    }
    
    private static ArrayList<Point> reducePoints(ArrayList<Point> path, int maxDistance) {
        // The Greedy algorithm reducing the points the Bot will click
        ArrayList<Point> selected = new ArrayList<>();
        int distSinceLastSelected = 0;
        int targetDistance = maxDistance - (int)(5 + 5 * Math.random());
        for (Point p : path) {
            if (distSinceLastSelected < targetDistance) {
                distSinceLastSelected++;
            } else {
                // set a new targetDistance
                targetDistance = maxDistance - (int)(5 + 5 * Math.random()); 
                selected.add(p);
                distSinceLastSelected = 0;
            }
        }
        return selected;
    }
}
