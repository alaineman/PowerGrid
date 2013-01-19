package powerwalk.control;

import java.util.*;
import powerwalk.Bot;
import powerwalk.model.GameObject;
import powerwalk.model.Grid;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.world.Wall;

/**
 * This Utility class deals with finding a path between two Points in the RSBot
 * environment.
 *
 * @author Alaineman
 * @author Chronio
 */
public abstract class PathFinder {

    private static HashMap<Point, Point> previous = null;
    /**
     * The maximum distance between two Points in the result Path.
     */
    public static final int maxDist = 15;
    public static Grid map;

    /**
     * Calculates a path between start and goal using the A* algorithm.
     *
     * @param start The start Point
     * @param goal The goal Point
     * @return A Path from start to goal
     * @throws OutOfReachException When no path between start and goal exists
     */
    public static ArrayList<Point> calculatePath(Point start, Point goal) throws OutOfReachException {
        map = Bot.getBot().getWorldMap();
        //Initialize the A* algorith.
        HashSet<Point> closedSet = new HashSet<>();
        //HashMap<Point,Double> f_score = new HashMap<>();
        PriorityQueue<Point> pending = new PriorityQueue<>();/*(10,
         new Comparator<Point> () {
         @Override public int compare(Point o1, Point o2) {
         return 0;
         }
         }
         );*/
        HashMap<Point, Double> pathCost = new HashMap<>();
        HashMap<Point, Point> came_from = new HashMap<>();

        //previous = new HashMap<>();

        pathCost.put(start, 1.0);
        start.f_score = Math.sqrt(Math.pow(start.x - goal.x, 2) + Math.pow(start.y - goal.y, 2));
        //f_score.put(start, Math.sqrt( Math.pow(start.x-goal.x,2) + Math.pow(start.y-goal.y,2) ));

        pending.offer(start);
        while (!pending.isEmpty()) {
            Point current = pending.poll();
            if (current.equals(goal)) {
                ArrayList<Point> fullPath = reconstruct(came_from, goal);
                return reducePoints(fullPath, maxDist);
            }
            closedSet.add(current);
            ArrayList<Point> adjacents = availableEdges(current);
            for (Point p : adjacents) {
                GameObject go = Bot.getBot().getWorldMap().get(p);
                if (!closedSet.contains(p)) {                                           
                        double tempPathCost = pathCost.get(current) + 1;
                        boolean isPending = pending.contains(p);
                        if (!isPending || tempPathCost <= pathCost.get(p) || pathCost.get(p) == 0) {
                            came_from.put(p, current);
                            pathCost.put(p, tempPathCost);
                            p.f_score = tempPathCost + Math.sqrt(Math.pow(start.x - goal.x, 2) + Math.pow(start.y - goal.y, 2));
                            if (!isPending) {
                                pending.offer(p);
                            }
                        }
                    }
               }
        }
        throw new OutOfReachException(goal, "Destination could not be reached, is the area explored?");
    }

    private static int getDirection(Point base, Point adj) {
        if (base.distance(adj) == 1) {
            Point delta = adj.subtract(base);
            if (delta.x > 0) {
                return Wall.EAST;
            }
            if (delta.x < 0) {
                return Wall.WEST;
            }
            if (delta.y > 0) {
                return Wall.NORTH;
            }
            if (delta.y < 0) {
                return Wall.SOUTH;
            }
        }
        return 0;
    }

    private static ArrayList<Point> availableEdges(Point base) {
        ArrayList<Point> points = new ArrayList<>(4);
        Point[] edges = getAdjacentPoints(base);
        for(Point p : edges){
            GameObject go = Bot.getBot().getWorldMap().get(p);
            if(!(go instanceof Wall)) points.add(p);
            else if(!((Wall) go).containsType(getDirection(p, base))) points.add(p);
        }
        return points;
    }
    
    public static Point[] getAdjacentPoints(Point p){
        //Points are top, right, bottom, left        
        Point[] res = {new Point(p.x, p.y-1, p.z), new Point(p.x+1, p.y, p.z), new Point(p.x, p.y+1, p.z), new Point(p.x-1, p.y, p.z)};        
        return res;
    }

    private static ArrayList<Point> reconstruct(HashMap<Point, Point> came_from, Point current) {
        // reconstruct the path from the came_from HashMap
        Point prev = came_from.get(current);
        if (prev == null) {
            ArrayList<Point> thePath = new ArrayList<>();
            thePath.add(current);
            return thePath;
        } else {
            ArrayList<Point> thePath = reconstruct(came_from, came_from.get(current));
            thePath.add(current);
            return thePath;
        }
    }

    private static ArrayList<Point> reducePoints(ArrayList<Point> path, int maxDistance) {
        // The Greedy algorithm reducing the points the Bot will click
        ArrayList<Point> selected = new ArrayList<>(path.size() / (maxDistance - 3));
        int distSinceLastSelected = 0;
        int targetDistance = maxDistance - (int) (3 + 5 * Math.random());
        for (Point p : path) {
            if (distSinceLastSelected < targetDistance /* && instanceAt(p) != interactable */) {
                distSinceLastSelected++;
            } else {
                // set a new targetDistance
                targetDistance = maxDistance - (int) (2 + 5 * Math.random());
                selected.add(p);
                distSinceLastSelected = 0;
            }
        }
        Point lastPoint = path.get(path.size() - 1);
        if (selected.isEmpty() || !selected.get(selected.size() - 1).equals(lastPoint)) {
            // if the final Point is not there, add it to the selected Points
            selected.add(lastPoint);
        }
        selected.trimToSize();
        return selected;
    }
}
