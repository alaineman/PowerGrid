/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powergrid.control.interaction.interactor;

import java.util.Collections;
import java.util.List;
import java.util.Set;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.control.interaction.Interactor;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.OutOfReachException;
import powergrid.model.WorldMap;
import powergrid.model.network.GraphNetwork;
import powergrid.model.network.NetworkElement;
import powergrid.model.world.transportation.CarpetMerchant;

/**
 *
 * @author Vincent W
 */
public class MagiccarpetInteractor extends Interactor {
    
    public static final int ANIMATION = 330;
    
    public MagiccarpetInteractor(WorldMap map, RSInteractor interactor) {
        super(map,interactor);
    }   

    @Override
    public Set<?> getOptions(Object elem) {
        if(elem instanceof CarpetMerchant){
            CarpetMerchant mc = (CarpetMerchant) elem;
            GraphNetwork tn = mc.getNetwork();
            return tn.getAdjacentElements(mc);
        } else {
            return Collections.emptySet();
        }
    }

    @Override
    public boolean interact(Object elem, Object option) 
            throws OutOfReachException {
        if (elem == null || option == null) {
            return false;
        } 
        CarpetMerchant start = (CarpetMerchant) elem;
        CarpetMerchant dest = (CarpetMerchant) option;
        GraphNetwork network = start.getNetwork();
        List<NetworkElement> path = network.findPath(start, dest);
        CarpetMerchant current = start;
        for (NetworkElement n : path) {
            if (!current.equals(n) &&
                    !travel(current, (CarpetMerchant) n)) {
                return false;
            }
        }
        return true;
    }
    
    public boolean travel(CarpetMerchant from, CarpetMerchant node) {
        RSInteractor in = getInteractor();
        in.click(from, "Travel");
        Widget optionWidget = in.getWidget(RSInteractor.MAGICCARPET_PANEL);
        in.waitForVisible(optionWidget, 5000);
        for (WidgetChild wc : optionWidget.getChildren()) {
            if (wc.getText().contains(node.getPositionName())) {
                if (in.click(wc)) {
                    in.clickContinue();
                    in.waitForAnimations(120000, ANIMATION);
                    return true;
                }
            }
        }
        return false;
    }

    @Override
    @SuppressWarnings("unchecked") // The cast is allowed
    public Set<Class<?>> getTypes() {
        return (Set<Class<?>>) Collections.singleton(
                (Class<?>) CarpetMerchant.class); 
    }
    
}
