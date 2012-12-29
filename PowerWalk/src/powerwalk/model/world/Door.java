package powerwalk.model.world;

import java.util.Arrays;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.wrappers.node.SceneObject;
import powerwalk.control.ToolBox;
import powerwalk.model.GameObject;
import powerwalk.model.OutOfReachException;
import powerwalk.model.interact.Interactable;

/**
 * Class representing a Door in the RSBot environment. 
 * <p>Doors are different from gates in that they usually cover only one tile, 
 * and they have different states (open and close). Gates only have one state, 
 * and always require an interact() command to pass through.</p>
 * @author Chronio
 */
public class Door extends GameObject implements Interactable {
    /** Raw values that represent doors in the RSBot environment */
    public static final int[] values = {
        /* Appears to be:
         *   First column: open.
         *   Second column: closed.
         *   Each row forms a pair (same door, different states).
         *   Pairs that behave different are marked with [X]
         */
        15535,15536, // Varrock "private" buildings, normal homes and such. Also: Cooks' guild
        24375,24376, // Varrock public buildings (stores and other places of interest)
        24377,24378, 
        24379,24381, // Varrock inner doors
        24383,24384, // Varrock back streets
        24387,24388, 
        /*?*/ 24536, // Varrock museum chain (this can only be opened by members, hence missing open value)
        /*?*/ 24565, // Varrock Museum back door (cannot be opened, I guess)
        /*?*/ 24567, // Varrock Museum back door (cannot be opened, I guess)
    };
    /** Raw values that represent open doors in the RSBot environment */
    public static final int[] openDoors = {15535,24375,24377,24379,24383,24387};
    
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
     * Performs the default interaction on the door.
     * <p>Use the open() and close() methods to ensure a specific door state</p>
     * @throws OutOfReachException when the door could not be interacted with
     */
    @Override public void interact() throws OutOfReachException {
        SceneObject d = SceneEntities.getAt(getPosition().toTile());
        if (d == null) throw new OutOfReachException("The door is not loaded");
        d.click(true);
    }
    
    /**
     * Tries to open the door.
     * @throws OutOfReachException when the door could not be opened
     */
    public void open() throws OutOfReachException {
        if (!isOpen()) {
            SceneObject d = SceneEntities.getAt(getPosition().toTile());
            if (d == null) throw new OutOfReachException(getPosition(),"Door not loaded");
            d.click(true);
        }
    }
    
    /**
     * Tries to close the door.
     * @throws OutOfReachException when the door could not be closed
     */
    public void close() throws OutOfReachException {
        if (isOpen()) {
            SceneObject d = SceneEntities.getAt(getPosition().toTile());
            if (d == null) throw new OutOfReachException(getPosition(),"Door not loaded");
            d.click(true);
        }
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
     * @throws OutOfReachException when the door could not be reached
     */
    @Override public void interact(String method) throws OutOfReachException {
        SceneObject d = SceneEntities.getAt(getPosition().toTile());
        if (d == null) throw new OutOfReachException(getPosition(),"Door not loaded");
        if (!d.interact(method))
            throw new UnsupportedOperationException("Operation not supported for this Door");
    }
    
    /**
     * returns whether this door is opened.
     * @return true if this door is opened, false if it is not.
     */
    public boolean isOpen() {
        return (-1 != Arrays.binarySearch(openDoors, getRawNumber()));
    }
}
