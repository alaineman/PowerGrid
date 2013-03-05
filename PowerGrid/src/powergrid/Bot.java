package powergrid;

import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.wrappers.interactive.Player;
import powergrid.control.TaskManager;
import powergrid.model.Destination;
import powergrid.model.Point;
import powergrid.tasks.RestTask;
import powergrid.tasks.TravelNearestTask;
import powergrid.tasks.TravelTask;

/**
 * Bot-class representing the Player.
 * The Bot can execute high-level tasks such as "travel to [destination]",
 * "go to nearest [place of interest]", and others. It makes use of the Task 
 * subclasses in the <code>powerwalk.tasks</code> package to achieve these tasks.
 * <p />
 * The Bot also provides top-level access to PowerWalk's functionality, and can 
 * be used either issue commands, or retrieve information about the Player's 
 * current state.
 * <p />
 * @author Alaineman
 * @author Chronio
 */
public class Bot {
    
    // The Bot's States
    /** This State represents any state that is not recognized by PowerWalk. */
    public static final int STATE_UNKNOWN = 0;
    /** This State represents the state of the Bot when there are no Tasks. */
    public static final int STATE_IDLE = 1;
    /** This State represents the state of the Bot while resting. */
    public static final int STATE_RESTING = 2;
    /** This State represents the state of the Bot while walking or running. */
    public static final int STATE_WALKING = 3;
    
    private TaskManager theTM = null;
    private Player rsPlayer = Players.getLocal();
    
    /**
     * Creates a new Bot that connects to the specified TaskManager.
     * @param tm the TaskManager for this Bot.
     */
    public Bot(Player thePlayer, TaskManager tm) {
        assert tm != null : "Invalid TaskManager in Bot constructor";
        theTM = tm;
        if (thePlayer != null)
            rsPlayer = thePlayer;
    }
    
    public void reloadLocalPlayer() {
        Player rsLocal = Players.getLocal();
        if (rsLocal != null) {
            rsPlayer = rsLocal;
        }
    }
    
    /**
     * Registers a Task that moves to the destination specified in name.
     * <p/>
     * @param name The target destination (providing correct casing is faster, but not required)
     * @param priority The priority of this Task
     * @throws IllegalArgumentException when no Destination exists with that name
     */
    public void travelTo(String name,int priority) {
        // Look up the given Destination for the provided name
        Destination dest = Destination.getDestination(name);
        if (dest == null) 
            throw new IllegalArgumentException("Undefined Destination: " + name);
        // travel to the matched destination
        theTM.assignTask(new TravelTask(dest,priority));
    }
    
    /**
     * Registers a Task that moves to the specified Point in the World
     * <p/>
     * @param p        The Point to move to
     * @param priority The priority of this Task
     */
    public void travelTo(Point p, int priority) {
        theTM.assignTask(new TravelTask(p,priority));
    }
    
    /**
     * Registers a RestTask instance that rests until the player's energy is at 
     * 100% again.
     * @param priority the priority of this Task
     * @param abortOnTask whether this Task should be aborted when other Tasks are present.
     */
    public void rest(int priority, boolean abortOnTask) {
        theTM.assignTask(new RestTask(priority,abortOnTask));
    }
    
    /**
     * Returns an integer specifying the current state of the Bot.
     * <p />
     * This integer represents one of the following states:
     * <ul>
     *   <li>Idle (represented by <code>Bot.STATE_IDLE</code></li>
     *   <li>Walking (represented by <code>Bot.STATE_WALKING</code></li>
     *   <li>Resting (represented by <code>Bot.STATE_RESTING</code></li>
     *   <li>Unknown (represented by <code>Bot.STATE_UNKNOWN</code></li>
     * </ul>
     * More states might be added in future releases.
     * @return an integer specifying the current state of the Bot.
     */
    public int getState() {
        
        if (rsPlayer == null)
            return STATE_UNKNOWN;
        
        if (rsPlayer.isMoving()) return STATE_WALKING;
        int anim = rsPlayer.getAnimation();
        if (anim == 12108 || anim == 2033 || anim == 2716 || anim == 11786 || anim == 5713) return STATE_RESTING;
        if (theTM.tasksPending() == 0) return STATE_IDLE;
        return STATE_UNKNOWN;
    }
    
    /**
     * returns the Player's current Position
     * @return the Player's current Position
     */
    public Point getPosition() {
        if (rsPlayer == null)
            return new Point();
        else
            return Point.fromTile(rsPlayer.getLocation());
    }
    
    /**
     * registers a Task that moves to the nearest destination that matches the description in dest.
     * <p/>
     * @param dest     The target destination
     * @param priority the priority of this Task
     * @throws NoSuchElementException   when no destinations for this destination type are registered
     * @throws IllegalArgumentException when the provided destination type is invalid
     */
    public void gotoNearest(String dest, int priority) {
        theTM.assignTask(new TravelNearestTask(dest),priority);
    }
    
    /**
     * Returns the associated TaskManager of this Bot-object.
     * @return the associated TaskManager of this Bot-object
     */
    public TaskManager getTM() {
        return theTM;
    }
}
