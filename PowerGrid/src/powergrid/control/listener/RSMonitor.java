
package powergrid.control.listener;

import java.util.HashSet;
import java.util.Set;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.world.Player;

/**
 *
 * @author Chronio
 */
public class RSMonitor implements Runnable {

    private RSInteractor interactor;
    
    private Set<HealthListener> healthListeners = new HashSet<>(6);
    
    private double health = 1;
    private Player localPlayer;
    
    public RSMonitor(RSInteractor client) {
        assert client != null;
        this.interactor = client;
    }

    public RSInteractor getInteractor() {
        return interactor;
    }
    
    public Player getLocalPlayer() {
        return localPlayer;
    }
    
    @Override
    public void run() {
        localPlayer = getInteractor().getLocalPlayer();
        checkHealth();
    }
    
    public void checkHealth() {
        double newHealth = getLocalPlayer().getHealth();
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
    }
    
    
}
