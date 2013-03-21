package powergrid.control.interaction.interactor;

import java.util.Set;
import powergrid.control.interaction.Interactor;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;

/**
 *
 * @author Vincent W
 */
public class FairyringInteractor extends Interactor {
    
    public FairyringInteractor(WorldMap map, RSInteractor interactor) {
        super(map,interactor);
    }

    @Override
    public Set<?> getOptions(Object elem) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean interact(Object elem, Object option) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public Set<Class<?>> getTypes() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
