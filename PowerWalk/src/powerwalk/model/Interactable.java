package powerwalk.model;

/**
 * Interface specifying Objects in the RSBot environment that can be interacted with.
 * @author P.Kramer
 */
public interface Interactable {
    /**
     * Interacts with the object using the default action.
     */
    public void interact();
    /**
     * Interacts with the object using the action denoted by the given String.
     * This method may throw an UnsupportedOperationException when the given 
     * String does not resemble a valid action
     * @param method the method of interaction
     * 
     * @throws UnsupportedOperationException when the given method is not supported by this object
     */
    public void interact(String method);
}
