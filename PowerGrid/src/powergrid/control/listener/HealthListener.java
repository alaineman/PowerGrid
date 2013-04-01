package powergrid.control.listener;

/**
 *
 * @author Chronio
 */
public interface HealthListener {
    
    public void healthAdded(double newHealth, double amount);
    
    public void healthRemoved(double newHealth, double amount);
    
    public void died();
}
