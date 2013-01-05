package powerwalk.tasks;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Walking;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.control.PathFinder;
import powerwalk.model.Destinations;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 * This Task travels to the given destination using all available methods.
 * @author Chronio
 */
public class TravelTask extends StepTask {

    private Point destination = null;
    
    private ArrayList<Point> path = null;
    private int target = 0;
    
    /**
     * Creates a new TravelTask set to travel to the specified Point
     * @param destination the point this TravelTask travels to
     * @param priority the priority of this Task
     */
    public TravelTask(Point destination, int priority) {
        super(priority);
        this.destination = destination;
        
        String name = Destinations.findNameForDestination(destination);
        if (name == null) name = destination.toString();
        setName("Travel to " + name);
    }
    
    /**
     * Creates a new TravelTask set to travel to the specified Point.
     * <p />
     * The Task will be made with priority 0.
     * @param destination the point this TravelTask travels to
     */
    public TravelTask(Point destination) {
        this(destination,0);
    }
    
    /**
     * Calculates a path and checks preconditions for this TravelTask.
     * The Task is immediately canceled when <code>getDestination() == null</code>, 
     * or when the PathFinder class has found no path to the given destination.
     */
    @Override public void start() {
        if (destination == null)
            cancel();
        else {
            try {
                path = PathFinder.calculatePath(Bot.getBot().getPosition(), destination);
                if (path.size() > 0) {
                    Point t = path.get(target);
                    Starter.logMessage("travel to " + path.get(path.size() - 1) + " has started, there are " + path.size() + " points on this path.", "Task");
                    Walking.walk(t.toTile());
                }
            } catch (OutOfReachException e) {
                path = new ArrayList<>(1);
                path.add(Bot.getBot().getPosition());
                Starter.logMessage("No path found to " + destination + ", task was canceled","TravelTask");
                cancel();
            }
        }
    }
    
    /**
     * Attempts to move to the next Point in the path, or waits if no action is 
     * required.
     * <p />
     * When the Player has more then 20 stamina left, but the Player's run mode 
     * is set to false, Run mode is automatically enabled.
     */
    @Override public void step() {
        setStepsLeft(path.size() - target);
        Point playerPos = Bot.getBot().getPosition();
        // check the distance to our next point.
        double distToTarget = Math.sqrt(
            Math.pow(playerPos.x - path.get(target).x, 2)
            + Math.pow(playerPos.y - path.get(target).y, 2));

        // check if we are running. If not, enable when we have some stamina left
        if (!Walking.isRunEnabled() && Walking.getEnergy() >= 20) {
            Walking.setRun(true);
        }

        // Are we are close enough?
        if (distToTarget < (3 + 3 * Math.random())) {
            // Are there more points?
            if (target + 1 < path.size()) {
                ++target;
                // Then we walk to the next tile.
                Point t = path.get(target);
                Walking.walk(t.toTile());
            } else {
                // There are no more points, so we are done.
                cancel();
            }
        }

        // wait a while before checking again
        Task.sleep(130, 210);
    }
    
    /**
     * Reports to the console that the destination has been reached.
     */
    @Override public void finish() {
        Starter.logMessage("Destination " + path.get(path.size() - 1) + " reached", "Task");
    }
    
    /**
     * Resets the path counter so that the Task can be run again.
     * <p />
     * Re-running a TravelTask calculates a path from the current location to 
     * the destination, regardless of the previous path. After this method is 
     * called, the start() method must be called first to recalculate the path.
     * Note that the PowerWalk Task Manager does this automatically, so when 
     * re-assigning this Task to the TaskQueue using the assignTask method from 
     * the PowerWalk Bot class or assigning it to a TaskRunner, manually calling 
     * the start() method is not required.
     */
    @Override public void reset() {
        target = 0;
    }
    
    /**
     * returns the destination that this TravelTask is set to travel to.
     * @return the destination of this TravelTask
     */
    public Point getDestination() {
        return new Point(destination);
    }
}
