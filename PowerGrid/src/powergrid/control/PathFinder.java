package powergrid.control;

import java.util.*;
import powergrid.PowerGrid;
import powergrid.model.Copyable;
import powergrid.model.GameTile;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.WorldMap;
import powergrid.model.interact.Lodestone;
import powergrid.model.world.Wall;

/**
 * This class deals with finding a path between two Points in the RSBot
 * environment.
 * <p/>
 * It uses the A* algorithm on the map data collected by the mapper. Therefore,
 * in order for the PathFinder to return the shortest known path, PowerGrid must
 * be running and the environment surrounding the start and endpoints must be
 * mapped.
 * <p/>
 * When calculating the path, various teleports and shortcuts are also used
 * during calculation. The only teleports and shortcuts that are used are the
 * ones the player has access to.
 * <p/>
 * @author Alaineman
 * @author Chronio
 */
public class PathFinder implements Copyable<PathFinder> {

    /**
     * Finds a path between the given start and end using the A* algorithm.
     * <p/>
     * An ArrayList of the Points is returned that indicates a shortest path
     * between the start and endpoint.
     * <p/>
     * The returned List is immutable.
     * <p/>
     * @param start the startPoint
     * @param end the endPoint
     * @return a shortest path between the given start and endpoints.
     * @throws OutOfReachException when no path exists between start and end
     * @throws IllegalArgumentException when the given start or endpoint is null
     */
    public static List<Point> findPath(Point start, Point end) throws OutOfReachException {
        return new PathFinder(start, end).calculatePath();
    }

    /**
     * Calculates and returns a shortest path from the player's current position
     * to the given endpoint.
     * <p/>
     * This method is effectively the same as calling
     * <code>PathFinder.findPath(Bot.getBot().getPosition(),end)</code>.
     * <p/>
     * The returned List is immutable.
     * <p/>
     * @param end the Point to travel to
     * @return a shortest path between the player's current position and the
     * given endpoint.
     * @throws OutOfReachException when no path exists between the player's
     * current position and the given endpoint.
     * @throws IllegalArgumentException when the given endpoint is null.
     */
    public static List<Point> findPath(Point end) throws OutOfReachException {
        return new PathFinder(PowerGrid.BOT.getPosition(), end).calculatePath();
    }
    /**
     * The maximum distance between two Points in the result Path.
     */
    private WorldMap theMap = null;
    
    public static final int maxDist = 14;
    private Point start, goal;
    private HashMap<Point, Point> cameFrom;
    private HashMap<Point, Double> pathCost;
    private HashMap<Point, Double> fScore;
    private HashSet<Point> closedSet;
    private PriorityQueue<Point> pending;
    private ArrayList<Point> path = null;

    /**
     * Creates new PathFinder instance that creates a path from start to goal.
     *
     * @param start the startpoint of this path
     * @param goal the endpoint of this path
     */
    public PathFinder(Point start, Point goal) {
        assert start != null && goal != null;
        
        theMap = PowerGrid.MAPPER.getWorldMap();
        this.start = start;
        this.goal = goal;

        Point delta = start.subtract(goal);
        int dist = Math.abs(delta.x) + Math.abs(delta.y) + Math.abs(delta.z);
        int tiles = Math.abs(delta.x * delta.y);
        cameFrom = new HashMap<>(tiles);
        pathCost = new HashMap<>(tiles);
        fScore = new HashMap<>(tiles);
        closedSet = new HashSet<>(tiles);
        pending = new PriorityQueue<>(Math.abs(dist) + 1, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                return (int) (fScore.get(p1) - fScore.get(p2));
            }
        });

        pathCost.put(start, 1d);
        fScore.put(start, start.distance(goal));
        pending.offer(start);
    }
    
    /**
     * Specifies the WorldMap that is used for the pathfinding.
     * @param map the WorldMap to use
     * @return itself for fluency
     */
    public PathFinder withMap(WorldMap map) {
        assert map != null;
        theMap = map;
        return this;
    }
    
    /**
     * Calculates a precise path between start and goal using the A* algorithm.
     * <p/>
     * When this method has been called once, any consecutive calls to this
     * method will return the same path.
     * <p/>
     * @return An unmodifyable List describing a shortest path from start to goal
     * @throws OutOfReachException When no path between start and goal exists
     */
    public List<Point> calculatePrecise() throws OutOfReachException {
        
        if (path != null) { 
            /* if a path already exists, return that path, since we assume that
             * the environment is static. */
            return path;
        }
        if (start.equals(goal)) {
            /* Return an empty List when we are already at the specified destination,
             * because no action needs to be taken to reach the destination. */
            return new ArrayList<>(1);
        }
        for (Lodestone l : Lodestone.getAvailableLodestones()) {
            /* Check for available Lodestones at the beginning, and add them to 
             * the PriorityQueue. If a Lodestone teleport is feasible, it will
             * be the most appropriate at the start. */
            Point p = l.getPosition();
            if (p.distance(start) > maxDist) {
                pathCost.put(p, 1d * maxDist);
                fScore.put(p, 2d * maxDist);
                pending.add(p);
            }
        }

        while (!pending.isEmpty()) {
            Point current = pending.poll();
            if (current.equals(goal)) {
                /* We save this path in the pathfinder for fast retrieval later.*/
                path = reconstruct(goal);
                /* We also release all references to data structures, since we 
                 * won't need them anymore. */
                cameFrom = null;
                pathCost = null;
                fScore = null;
                closedSet = null;
                pending = null;
                return Collections.unmodifiableList(path);
            }
            closedSet.add(current);
            Set<Point> adjacents = availableEdges(current);
            for (Point p : adjacents) {
                if (!closedSet.contains(p)) {
                    double tempPathCost = pathCost.get(current) + 1;
                    boolean isPending = pending.contains(p);
                    if (!isPending || tempPathCost <= pathCost.get(p) || pathCost.get(p) == 0) {
                        cameFrom.put(p, current);
                        pathCost.put(p, tempPathCost);
                        fScore.put(p, tempPathCost + start.distance(goal));
                        if (!isPending) {
                            pending.offer(p);
                        }
                    }
                }
            }
        }
        throw new OutOfReachException(goal, "Destination could not be reached, is the area explored?");
    }
    
    /**
     * Calculates a path between start and goal using the A* algorithm.
     * <p/>
     * The returned List will contain Points placed at most <code>maxDist</code>
     * from one another, allowing the path to be executed in the RSBot environment
     * Point by Point.
     * <p/>
     * When this method has been called once, any consecutive calls to this
     * method will return the same path.
     * <p/>
     * @return A Path from start to goal with gaps between the Points
     * @throws OutOfReachException When no path between start and goal exists
     */
    public List<Point> calculatePath() throws OutOfReachException {
        return Collections.unmodifiableList(reducePoints(calculatePrecise()));
    }
    
    /**
     * Returns the direction of the Point adj as seen from base.
     * @param base the Point from which to look
     * @param adj the adjacent Point.
     * @return the mask that specifies the Wall side that would block going from base to adj.
     */
    public static int getDirection(Point base, Point adj) {
        double theta = adj.subtract(base).theta(); // the angle from base to adj
        if (Math.abs(theta) <= Math.PI / 4) {
            return Wall.EAST;
        }
        if (Math.abs(theta) >= 3 * Math.PI / 4) {
            return Wall.WEST;
        }
        if (theta > 0) {
            return Wall.NORTH;
        }
        return Wall.SOUTH;
    }

    /**
     * Helper method that returns all available edges going from base.
     * @param base the Point to check from
     * @return a Set of Points that contains the available edges.
     */
    public Set<Point> availableEdges(Point base) {
        HashSet<Point> points = new HashSet<>(6);
        Point[] edges = { // the possible adjacent edges
            new Point(base.x, base.y - 1, base.z),
            new Point(base.x + 1, base.y, base.z),
            new Point(base.x, base.y + 1, base.z),
            new Point(base.x - 1, base.y, base.z)
        };
        for (Point p : edges) {
            GameTile go = theMap.get(p);
            if (go == null || go.getCollisionFlag() == 0) {
                points.add(p);
            } else if (!theMap.isBoundary(p,getDirection(p, base))) {
                points.add(p);
            }
        }
        return points;
    }

    /**
     * Helper method that reconstructs the Path recursively using the cameFrom HashMap
     * @param current the node to look up
     * @return the path leading to <code>current</code>
     */
    private ArrayList<Point> reconstruct(Point current) {
        // reconstruct the path from the cameFrom HashMap
        Point prev = cameFrom.get(current);
        if (prev == null) {
            // we reached the start of the path
            return new ArrayList<>();
        } else {
            ArrayList<Point> thePath = reconstruct(cameFrom.get(current));
            thePath.add(current);
            return thePath;
        }
    }

    /**
     * Reduces points in a path to contain only points that are approximately 
     * <code>maxDist</code> tiles apart.
     * <p/>
     * For this, a pseudo-optimal Greedy algorithm is used that picks Points
     * <code>maxDist - (2 + 4 * Math.random())</code> apart, where this value 
     * is recomputed for each Point in the resulting path, leading to variations 
     * in distance between the path's points.
     * <p/>
     * @param path the original path with all points.
     * @return the resulting path with obsolete Points removed
     */
    public static ArrayList<Point> reducePoints(List<Point> path) {
        // Greedy (pseudo-optimal) algorithm reducing the points the Bot will click
        ArrayList<Point> selected = new ArrayList<>((int) Math.ceil(path.size() / (maxDist - 3)));
        int distSinceLastSelected = 0;
        int targetDistance = maxDist - (int) (2 + 4 * Math.random());
        for (Point p : path) {
            Lodestone l = Lodestone.getLodestone(p);
            if (l != null && (selected.isEmpty() || selected.get(selected.size() - 1).distance(p) >= maxDist)) {
                selected.add(p);
            } else {
                if (distSinceLastSelected < targetDistance) {
                    distSinceLastSelected++;
                } else {
                    // set a new targetDistance
                    targetDistance = maxDist - (int) (2 + 4 * Math.random());
                    selected.add(p);
                    distSinceLastSelected = 0;
                }
            }
        }
        Point lastPoint = path.get(path.size() - 1);
        if (selected.isEmpty() || !selected.get(selected.size() - 1).equals(lastPoint)) {
            // if the final Point is not there, add it to the selected Points
            selected.add(lastPoint);
        }
        return selected;
    }

    @Override public PathFinder copy() {
        return new PathFinder(start, goal).withMap(theMap);
    }
}
