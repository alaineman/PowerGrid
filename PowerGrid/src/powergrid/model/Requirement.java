package powergrid.model;

/**
 * Represents a requirement for an element, network or a similar object that 
 * requires one or more conditions to be met in order to be used.
 * <p/>
 * It can be used to indicate that certain operations are or are not allowed.
 * The exact meaning of implementing this method differs greatly between types.
 * 
 * @param <T> the type of object that has the requirement
 * @author Vincent W
 */
public interface Requirement<T> {
    
    /**
     * Checks if the Requirement is met for the specified object.
     * <p/>
     * A requirement must be true before the object can be used.
     * <p/>
     * The option can be used to provide additional details that help to verify
     * the condition. The way this is used can be found in the classes that 
     * check for the requirements. The documentation for those methods or 
     * classes should contain a description about how the option is utilized.
     * <p/>
     * @param object the object to check the requirement for
     * @param option an optional parameter to indicate additional information.
     * @return true if the condition holds, false if it does not.
     */
    public boolean requirementMet(T object, Object option);
}
