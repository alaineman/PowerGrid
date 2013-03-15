/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.model.interaction;

/**
 * Interface that defines methods for a class that can interact with a certain
 * kind of object.
 * <p/>
 * The 
 * @param T The type of object the Interactor handles
 * @author Chronio
 */
public interface Interactor<T> {
    /**
     * Returns an array containing the actions this Interactor can perform on
     * the given object.
     * <p/>
     * This does not have to be equal to the possible actions in the Runescape
     * environment, it simply means this Interactor can handle the operation.
     * <p/>
     * @param elem the element to check the actions for
     * @return an array containing the 
     */
    public String[] getActions(T elem);
    
    /**
     * Interacts with the element using the default action.
     * <p/>
     * The Interactor is free to decide what the default action is, but it 
     * should generally be the default action in the Runescape environment to
     * avoid confusion.
     * <p/>
     * @param elem the element to interact with
     * @return whether the interaction was successful
     */
    public boolean interact(T elem);
    
    /**
     * Interacts with the element using the given action.
     * @param elem the element to interact with
     * @param method the method of interaction
     * @return whether the interaction was successful
     */
    public boolean interact(T elem, String method);
    
    /**
     * Returns an array of all classes this Interactor can handle.
     * <p/>
     * When including a class in this method's result array, the Interactor 
     * must make sure that it accepts at least one interaction method for that 
     * type.
     * @return 
     */
    public Class<?>[] getTypes();
    
    /**
     * Returns whether this Interactor should be preferred over another.
     * <p/>
     * The InteractionManager will take the result call of this method into 
     * account when selecting the most appropriate Interactor for a certain 
     * object.
     * <p/>
     * This method should check compatibility carefully, and not simply return 
     * true.
     * <p/>
     * The InteractionManager wil consider this Interactor to be more suited to
     * handling the interaction when this method returns true, and the other 
     * interactor's <code>isMoreFavorableThan</code> method returns false.
     * When both interactors give the same answer, they will be considered 
     * equal and the one chosen to perform the interaction is undefined.
     * <p/>
     * @param i the other Interactor
     * @param elem the object for which 
     * @return whether this Interactor is more suited to handling the given 
     *         object's interactions.
     */
    public boolean isMoreFavorableThan(Interactor i, T elem);
}
