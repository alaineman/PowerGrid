package powergrid.control.interaction;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.ViewportEntity;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;

/**
 * Default Interactor that simply clicks the provided Object when the 
 * environment allows it to be clicked.
 * <p/>
 * @author Chronio
 */
public class DefaultInteractor extends Interactor {

    public DefaultInteractor(WorldMap map, RSInteractor i) {
        super(map, i);
    }
    
    @Override
    public Set<String> getOptions(Object elem) {
        return Collections.singleton("");
    }

    @Override
    public boolean interact(Object elem, Object option) 
            throws OutOfReachException {
        if (elem instanceof Locatable) {
            return getInteractor().click((Locatable) elem);
        }
        if (elem instanceof ViewportEntity) {
            return getInteractor().click((ViewportEntity) elem);
        }
        return false;
    }

    @Override
    public Set<Class<?>> getTypes() {
        HashSet<Class<?>> res = new HashSet<>(4);
        res.add(Locatable.class);
        res.add(ViewportEntity.class);
        return res;
    }

    @Override
    public boolean isMoreFavorableThan(Interactor i,
            Class<?> c) {
        return false;
    }
    
}
