/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.control.interaction.interactor;

import java.util.Collections;
import java.util.Set;
import powergrid.control.interaction.Interactor;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;
import powergrid.model.network.GraphNetwork;
import powergrid.model.world.transportation.CarpetMerchant;

/**
 *
 * @author Vincent W
 */
public class MagiccarpetInteractor extends Interactor {
    
    public MagiccarpetInteractor(WorldMap map, RSInteractor interactor) {
        super(map,interactor);
    }   

    @Override
    public Set<?> getOptions(Object elem) {
        if(elem instanceof CarpetMerchant){
            CarpetMerchant mc = (CarpetMerchant) elem;
            GraphNetwork tn = mc.getNetwork();
            return tn.getAdjacentTiles(mc);
        } else {
            return Collections.emptySet();
        }
    }

    @Override
    public boolean interact(Object elem, Object option) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Set<Class<?>> getTypes() {
        return (Set<Class<?>>) Collections.singleton((Class<?>) CarpetMerchant.class); 
    }
    
}
