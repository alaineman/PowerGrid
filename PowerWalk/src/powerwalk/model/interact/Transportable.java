package powerwalk.model.interact;

import java.util.ArrayList;
import java.util.Collection;
import powerwalk.model.OutOfReachException;

/**
 * Represents a GameObject that allows a transport to another Transportable.
 * @author Alaineman
 * @author P.Kramer
 */
public abstract class Transportable extends Teleportable {
    
    private ArrayList<Transportable> destinations;
    
    /**
     * Creates a new <code>Transportable</code> at the specified position and with the specified raw value.
     * <p> the destinations for this Transportable are defined in dests</p>
     * @param x the x-coordinate of the <code>Teleportable</code>
     * @param y the y-coordinate of the <code>Teleportable</code>
     * @param z the z-coordinate of the <code>Teleportable</code>
     * @param rawNumber the raw value for this object from the RSBot environment
     */
    public Transportable(int x,int y,int z,int rawNumber, Collection<Transportable> dests) {
        super(x, y, z, rawNumber);
        destinations = new ArrayList<>(dests);
    }    
    
    /**
     * Teleports you to the designated Point.
     * @throws OutOfReachException when the requirements are not met or this 
     *         Transportable cannot be used to travel to Transportable dest.
     * @param dest the Point of destination.
     */
    public abstract void follow(Transportable dest) throws OutOfReachException;
    
    /**
     * Teleports you to the first destination Point.
     * @throws OutOfReachException when the requirements are not met.
     */
    @Override public void follow() throws OutOfReachException {
        if(!destinations.isEmpty()){
            follow(destinations.get(0));
        }
    }
    
    /**
     * Returns available destinations for this Transportable.
     * @return available destinations.
     */
    public Transportable[] getDestinations() {
        return destinations.toArray(new Transportable[0]);
    };
            
}
