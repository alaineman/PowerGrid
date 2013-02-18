package powergrid.model;

/**
 * An Exception that is thrown when an action involves 
 * moving towards an unreachable or non-existing destination.
 * @author Chronio
 */
public class OutOfReachException extends Exception {
    
    private Point outofreach = null;
    
    /**
     * Create a new OutOfReachException with the indicated message and destination.
     * The given destination is the destination that could not be reached.
     * @param destination the destination that was out of reach
     * @param message a message indicating the problem
     */
    public OutOfReachException(Point destination, String message) {
        super(message);
        outofreach = destination;
    }
    /**
     * Create a new OutOfReachException with the indicated destination.
     * The given destination is the destination that could not be reached.
     * @param destination the destination that was out of reach
     */
    public OutOfReachException(Point destination) {
        super();
        outofreach = destination;
    }
    /**
     * Create a new OutOfReachException with the indicated message.
     * @param message a message indicating the problem
     */
    public OutOfReachException(String message) {
        super(message);
    }
    /**
     * Creates a new generic OutOfReachException
     */
    public OutOfReachException() {
        super();
    }
    
    /**
     * returns the destination that was out of reach.
     * If no destination was set, this method returns null
     * @return the destination that was out of reach
     */
    public Point getDestination() {
        if (outofreach==null) return null;
        else return new Point(outofreach);
    }

    /**
     * Returns the message passed along with this OutOfReachException, if it was set, followed 
     * by the destination that could not be reached, if it was set.
     * @return the message describing the cause of the OutOfReachException
     */
    @Override public String getMessage() {
        String msg = super.getMessage();
        if (msg == null || msg.isEmpty()) 
            msg = "Could not travel to Point: " + outofreach;
        else if (outofreach != null)
            msg += " (original destination: " + outofreach + ")";
        return msg;
    }
}
