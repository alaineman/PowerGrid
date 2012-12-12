package powerwalk.model.world;

import java.util.logging.Level;
import java.util.logging.Logger;
import powerwalk.control.ToolBox;
import powerwalk.model.GameObject;
import powerwalk.model.Interactable;

/**
 * Class representing a Door in the RSBot environment
 * @author P.Kramer
 */
public class Door extends GameObject implements Interactable {
    /** Raw values that represent doors in the RSBot environment */
    public static final int[] values = {};
    
    public Door(int x,int y,int z,int rawValue) {
        super(x,y,z,rawValue);
        if (ToolBox.arrayIndexOf(rawValue, values) == -1)
            throw new IllegalArgumentException("value " + rawValue + " does not represent a Door");
    }
    
    /**
     * Tries to open / close the door
     */
    @Override public void interact() {
        try { interact("open"); } 
        catch (UnsupportedOperationException e) {
            try { interact("close"); }
            catch (UnsupportedOperationException ex) {
                Logger.getLogger("Door").log(Level.WARNING,"The door could not be interacted with",ex);
            }
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
     */
    @Override public void interact(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
