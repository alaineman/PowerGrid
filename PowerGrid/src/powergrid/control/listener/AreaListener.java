package powergrid.control.listener;

import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.Point;

/**
 * Listener for entering or leaving a certain area
 * @author Chronio
 */
public interface AreaListener {
    
    /**
     * @return the radius in which the player must be before the events are 
     *         triggered.
     */
    public double radius();
    
    /**
     * @return the center Point of the area.
     */
    public Point centerPoint();
    
    /**
     * Called when the area defined by radius() and centerPoint() is entered.
     * @param rsi the RSInteractor providing the data
     */
    public void areaEntered(RSInteractor rsi);
    
    /**
     * Called when the area defined by radius() and centerPoint() is left.
     * @param rsi the RSInteractor providing the data
     */
    public void areaLeft(RSInteractor rsi);
}
