
package powergrid.control.listener;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.Point;

/**
 * Class that monitors various parameters and settings in Runescape. 
 * <p/>
 * It works by continuously polling information from the Runescape environment.
 * It then calls the appropriate methods of the Listeners registered in the 
 * Monitor.
 * <p/>
 * @author Chronio
 */
public class RSMonitor implements Runnable {

    private RSInteractor interactor;
    
    private Set<HealthListener> healthListeners = new HashSet<>(6);
    private Map<AreaListener, Boolean> areaListeners = new HashMap<>(6);
    
    private double health = 1;
    
    /**
     * Creates a new RSMonitor.
     * @param interactor the RSInteractor this Monitor should use
     */
    public RSMonitor(RSInteractor interactor) {
        assert interactor != null;
        this.interactor = interactor;
    }

    /**
     * @return the RSInteractor instance this RSMonitor uses.
     */
    public RSInteractor getInteractor() {
        return interactor;
    }
    
    /**
     * Checks all values once and calls the appropriate listeners.
     */
    @Override
    public synchronized void run() {
        if (!healthListeners.isEmpty()) {
            checkHealth();
        }
        if (!areaListeners.isEmpty()) {
            
        }
    }
    
    /**
     * Checks the player's health and calls the appropriate listeners when 
     * required.
     */
    public synchronized void checkHealth() {
        double newHealth = getInteractor().getLocalPlayer().getHealth();
        if (newHealth > health) {
            for (HealthListener l : healthListeners) {
                l.healthAdded(newHealth, newHealth - health);
            }
        } else if (newHealth < health) {
            for (HealthListener l : healthListeners) {
                l.healthRemoved(newHealth, health - newHealth);
            }
            if (newHealth == 0) {
                for (HealthListener l : healthListeners) {
                    l.died();
                }
            }
        }
        health = newHealth;
    }
    
    public synchronized void checkArea() {
        Point pos = getInteractor().getLocalPlayer().getPosition();
        for (Entry<AreaListener, Boolean> e : areaListeners.entrySet()) {
            AreaListener a = e.getKey();
            if (e.getValue()) {
                if (pos.distance(a.centerPoint()) > a.radius()) {
                    a.areaLeft(getInteractor());
                }
            } else {
                if (pos.distance(a.centerPoint()) <= a.radius()) {
                    a.areaLeft(getInteractor());
                }
            }
        }
    }
}
