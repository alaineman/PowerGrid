package powerwalk.model.world;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.control.ToolBox;
import powerwalk.model.GameObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.interact.Interactable;

/**
 * Class representing a Door in the RSBot environment
 * @author Chronio
 */
public class Door extends GameObject implements Interactable {
    /** Raw values that represent doors in the RSBot environment */
    public static final int[] values = {15536,24387,24388};
    
    /**
     * Creates a new Door at the given position. the <code>rawNumber</code> 
     * indicates the type of object as provided by the RSBot environment.
     * @param x the x-coordinate of this object
     * @param y the y-coordinate of this object
     * @param z the z-coordinate of this object
     * @param rawNumber the raw value from the environment specifying the type
     */
    public Door(int x,int y,int z,int rawValue) {
        super(x,y,z,rawValue);
        if (ToolBox.arrayIndexOf(rawValue, values) == -1)
            throw new IllegalArgumentException("value " + rawValue + " does not represent a Door");
    }
    
    /**
     * Tries to open / close the door.
     * @throws OutOfReachException when the door could not be interacted with
     */
    @Override public void interact() throws OutOfReachException {
        try { interact("open"); } 
        catch (UnsupportedOperationException e) {
            try { interact("close"); }
            catch (UnsupportedOperationException ex) {
                Logger.getLogger("Door").log(Level.WARNING,"The door could not be interacted with",ex);
            }
        }
    }
    
    /**
     * Tries to open the door.
     * @throws OutOfReachException when the door could not be opened
     */
    public void open() throws OutOfReachException {
        interact("open");
    }
    
    /**
     * Tries to close the door.
     * @throws OutOfReachException when the door could not be closed
     */
    public void close() throws OutOfReachException {
        interact("close");
    }
    
    /**
     * Interacts with this door.
     * <p> The following actions are supported: </p>
     * <ul>
     *  <li>open</li>
     *  <li>close</li>
     *  <li>examine</li>
     * </ul>
     * 
     * @param method the method of interaction with this door
     * @throws UnsupportedOperationException when the given method is not supported
     * @throws IllegalStateException when open is called when the door is open, 
     *                               or close is called when the door is closed.
     * @throws OutOfReachException when the door could not be reached
     */
    @Override public void interact(String method) throws OutOfReachException {
        Tile t = getPosition().toTile();
        SceneObject[] ss = SceneEntities.getLoaded(t);
        for (SceneObject s : ss) {
            if (s.getType() == getRawNumber()) {
                if (!s.interact(method)) {
                    throw new UnsupportedOperationException("This interaction is not supported");
                }
                break;
            }
        }
        throw new OutOfReachException(getPosition(),"This Door could not be found at the given position");
    }
    
}
