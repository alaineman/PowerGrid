package powerwalk.control;

import java.util.*;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.model.Collision;
import powerwalk.model.GameObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 * This Utility class deals with finding a path between two Points in the RSBot environment.
 *
 * @author Alaineman
 * @author Chronio
 */
public abstract class PathFinder {
    
    private static HashMap<Point,Point> previous = null;
    
    /** The maximum distance between two Points in the result Path. */
    public static final int maxDist = 15;
    
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
        //HashMap<Point,Double> f_score = new HashMap<>();
        PriorityQueue<Point> pending = new PriorityQueue<> ();/*(10,
            new Comparator<Point> () {
                @Override public int compare(Point o1, Point o2) {
                    return 0;
                }
            }
            );*/
        HashMap<Point, Double> pathCost = new HashMap<>();
        HashMap<Point,Point> came_from = new HashMap<>();
        
        //previous = new HashMap<>();
        
        pathCost.put(start,1.0);
        
        start.f_score = Math.sqrt( Math.pow(start.x-goal.x,2) + Math.pow(start.y-goal.y,2) );
        //f_score.put(start, Math.sqrt( Math.pow(start.x-goal.x,2) + Math.pow(start.y-goal.y,2) ));
        
        pending.offer(start);
        while (!pending.isEmpty()) {
            Point current = pending.poll();
            if (current.equals(goal)) {
                ArrayList<Point> fullPath = reconstruct(came_from,goal);
                return reducePoints(fullPath,maxDist);
            }
            closedSet.add(current);
            Point[] adjacents = current.getAdjacentPoints();
            for (int i=0;i<adjacents.length;i++) {
                
                Point p = adjacents[i];
                GameObject go = Bot.getBot().getWorldMap().get(p);
                if (!closedSet.contains(p)) { 
                    if (Bot.getBot().getWorldMap().get(p) instanceof Collision) {
                        closedSet.add(p);
                    } else {
                        double tempPathCost = pathCost.get(current) + 1;

                        boolean isPending = pending.contains(p);
                        if (!isPending || tempPathCost <= pathCost.get(p) || pathCost.get(p) == 0) {
                            came_from.put(p, current);
                            pathCost.put(p, tempPathCost);
                            p.f_score = tempPathCost + Math.sqrt( Math.pow(start.x-goal.x,2) + Math.pow(start.y-goal.y,2) );
                            if (!isPending) {
                                pending.offer(p);
                            }
                        }
                    }
                }
            }
        }
        throw new OutOfReachException(goal,"Destination could not be reached, is the area explored?");
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
        ArrayList<Point> selected = new ArrayList<>(path.size() / (maxDistance-3));
        int distSinceLastSelected = 0;
        int targetDistance = maxDistance - (int)(3 + 5 * Math.random());
        for (Point p : path) {
            if (distSinceLastSelected < targetDistance /* && instanceAt(p) != interactable */) {
                distSinceLastSelected++;
            } else {
                // set a new targetDistance
                targetDistance = maxDistance - (int)(2 + 5 * Math.random()); 
                selected.add(p);
                distSinceLastSelected = 0;
            }
        }
        Point lastPoint = path.get(path.size()-1);
        if (selected.isEmpty() || !selected.get(selected.size()-1).equals(lastPoint)) {
            // if the final Point is not there, add it to the selected Points
            selected.add(lastPoint);
        }
        selected.trimToSize();
        return selected;
    }
}
