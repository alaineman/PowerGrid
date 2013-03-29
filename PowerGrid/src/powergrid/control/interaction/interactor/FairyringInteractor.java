package powergrid.control.interaction.interactor;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import powergrid.control.interaction.Interactor;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.TransportTile;
import powergrid.model.WorldMap;
import powergrid.model.world.transportation.FairyRing;

/**
 * Interacts with Fairy Rings. 
 * @author Vincent W
 */
public class FairyringInteractor extends Interactor {
    
    /**
     * Creates a new FairyringInteractor that will use the specified map and 
     * interactor for interactions.
     * @param map the WorldMap instance to use
     * @param interactor the RSInteractor to use
     */
    public FairyringInteractor(WorldMap map, RSInteractor interactor) {
        super(map,interactor);
    }

    /**
     * Returns a list of all ringcodes that can be travelled to from the given 
     * Object.
     * <p/>
     * @param elem the FairyRing to check
     * @return a Set containing the codes of the FairyRings that can be reached
     *         from the given FairyRing, or the empty set if the provided 
     *         Object is not a FairyRing instance.
     */
    @Override
    public Set<String> getOptions(Object elem) {
        if (elem instanceof FairyRing) {
            FairyRing ring = (FairyRing) elem;
            String startCode = ring.getCode();
            HashSet<String> res = new HashSet<>();
            for (TransportTile tt: ring.getNetwork().getElements()) {
                if (tt instanceof FairyRing) {
                    String destCode = ((FairyRing) tt).getCode();
                    if (!destCode.equals(startCode)) {
                        res.add(destCode);
                    }
                }
            }
            return res;
        } else {
            return Collections.emptySet();
        }
    }

    /**
     * Interacts with the specified FairyRing to teleport to the specified 
     * destination.
     * <p/>
     * @param elem the FairyRing to interact with
     * @param option the FairyRing to teleport to
     * @return true if the interaction succeeded, false otherwise
     * @throws OutOfReachException when the FairyRing could not be reached
     */
    @Override
    public boolean interact(Object elem, Object option) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Set<Class<?>> getTypes() {
        HashSet<Class<?>> set = new HashSet<>(2);
        set.add(FairyRing.class);
        return set;
    }
    
}
