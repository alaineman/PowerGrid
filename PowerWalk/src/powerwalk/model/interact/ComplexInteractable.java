/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact;

/**
 * ComplexInteractable is an extension on Interactable for all more extensive interactions.
 * Interface representing complex interactions. Checks must be made to ensure the interaction is allowed.
 * @author vync job
 */
public interface ComplexInteractable extends Interactable {
    
    /**
     * This method check is the Complex Interaction is available for this character.
     * @param method the method of interaction.
     * @return whether the interaction is allowed.
     */
    public boolean isAllowed(String method);
}