package powergrid.model;

/**
 * Interface for objects that match other objects for certain criteria.
 * <p/>
 * The Matcher is taken to accept an object when the matches method with that
 * object as parameter returns true.
 * @param <T> the type of object the Matcher matches
 * @author Chronio
 */
public interface Matcher<T> {
    
    /**
     * Matches the provided object against this Matcher's criteria.
     * @param object the object to check
     * @return true if this Matcher accepts the provided object, 
     *         false otherwise
     */
    public boolean matches(T object);
}
