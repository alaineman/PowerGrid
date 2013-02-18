package powergrid.model.interact;

/**
 * ComplexInteractable is an extension on Interactable for all more extensive interactions.
 * Interface representing complex interactions. Checks must be made to ensure the interaction is allowed.
 * @author Alaineman
 */
public interface ComplexInteractable extends Interactable {
    
    /**
     * This method checks if all requirements for this Complex Interaction are met.
     * <p>If this method returns true, it cannot be guaranteed that the interact 
     * method will successfully execute the interaction. It merely means all 
     * requirements for the interaction are met (as far as PowerWalk can observe).</p>
     * @param method the method of interaction.
     * @return whether the interaction is allowed.
     */
    public boolean isAllowed(String method);
}