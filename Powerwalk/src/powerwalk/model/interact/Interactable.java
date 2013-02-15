package powerwalk.model.interact;

import powerwalk.model.OutOfReachException;

/**
 * Interface specifying Objects in the RSBot environment that can be interacted with.
 * @author Chronio
 */
public interface Interactable {
    /**
     * Interacts with the object using the default action.
     * 
     * @throws OutOfReachException when the Interactable could not be reached
     */
    public void interact() throws OutOfReachException;
    /**
     * Interacts with the object using the action denoted by the given String.
     * This method may throw an UnsupportedOperationException when the given 
     * String does not resemble a valid action
     * @param method the method of interaction
     * 
     * @throws UnsupportedOperationException when the given method is not supported by this object
     * @throws OutOfReachException when the Interactable could not be reached
     */
    public void interact(String method) throws OutOfReachException;
}
