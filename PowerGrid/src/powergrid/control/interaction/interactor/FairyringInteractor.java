package powergrid.control.interaction.interactor;

import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.control.interaction.Interactor;
import powergrid.control.uicontrols.RSInteractor;
import static powergrid.control.uicontrols.RSInteractor.FAIRYRING_PANEL;
import powergrid.model.OutOfReachException;
import powergrid.model.TransportTile;
import powergrid.model.WorldMap;
import powergrid.model.world.transportation.FairyRing;

/**
 * Interacts with Fairy Rings.
 * @author Vincent W
 * @author Chronio
 */
public class FairyringInteractor extends Interactor {
    
    /** The sequence of animations to wait for after the interaction. */
    public static final int[] ANIMATION_SEQUENCE = new int[] {3254, 3255};
    
    /**
     * Defines the way to interact with the destination chooser for FairyRings 
     * by listing the required widget and the required number of clicks.
     */
    public enum CODECHAR {
        A(23, 0), B(24, 1), C(24, 2), D(23, 1),
        I(25, 0), J(26, 1), K(26, 2), L(25, 1),
        P(27, 0), Q(28, 1), R(28, 2), S(27, 1);
        
        private int widget;
        private int clicks;

        private CODECHAR(int widget, int clicks) {
            assert widget > 0 && clicks >= 0;
            this.widget = widget;
            this.clicks = clicks;
        }

        /**
         * Returns this CODECHAR's number of clicks
         * @return this CODECHAR's number of clicks
         */
        public int getClicks() {
            return clicks;
        }

        /**
         * Returns this CODECHAR's linked widget number
         * @return this CODECHAR's linked widget number
         */
        public int getWidget() {
            return widget;
        }
    }
    
    
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
    public boolean interact(Object elem, Object option) 
            throws OutOfReachException {
        FairyRing start = null;
        FairyRing dest = null;
        String code = null;
        
        if (elem instanceof FairyRing) {
            start = (FairyRing) elem;
            if (option instanceof String) {
                code = (String) option;
                dest = lookupDestination(code, start);
            } else if (option instanceof FairyRing) {
                dest = (FairyRing) option;
                code = dest.getCode();
            }
        }
        if (start == null || code == null || dest == null) {
            return false;
        }
        RSInteractor in = getInteractor();
        Widget ringPanel = in.getWidget(FAIRYRING_PANEL);
        in.click(start);
        in.waitForVisible(ringPanel, 5000);
        WidgetChild logEntry = findTravelLogEntry(code);
        if (logEntry == null) {
            selectCode(dest.getCode());
        } else {
            in.click(logEntry);
        }
        WidgetChild confirm = ringPanel.getChild(21);
        in.waitForVisible(confirm, 2000);
        in.click(confirm);
        in.waitForAnimations(16000, ANIMATION_SEQUENCE);
        return true;
    }
    
    /**
     * Finds the FairyRing instance that matches the given code.
     * <p/>
     * @param code the code to look for
     * @param start the start FairyRing
     * @return the FairyRing instance with the provided code
     * @throws OutOfReachException when no such FairyRing exists
     * @throws IllegalArgumentException when the provided code is not valid
     */
    private FairyRing lookupDestination(String code, FairyRing start) 
            throws OutOfReachException {
        code = code.toUpperCase();
        if (code.length() != FairyRing.CODE_LENGTH) {
            throw new IllegalArgumentException("Invalid code length");
        }
        FairyRing destination = null;
        for (TransportTile tile : start.getNetwork().getElements()) {
            if (tile instanceof FairyRing) {
                FairyRing ring = (FairyRing) tile;
                if (ring.getCode().equals(code)) {
                    destination = ring;
                    break;
                }
            }
        }
        if (destination == null) {
            throw new OutOfReachException(
                    "No FairyRing with the designated code found");
        }
        return destination;
    }

    /**
     * Clicks the WidgetChildren on the FAIRYRING_PANEL widget to match the 
     * given code.
     * @param code the code to match
     */
    private void selectCode(String code) {
        Widget w = getInteractor().getWidget(FAIRYRING_PANEL);
        for (CODECHAR cc : CODECHAR.values()) {
            if (code.contains(cc.name())) {
                WidgetChild wc = w.getChild(cc.getWidget());
                int clicks = cc.getClicks();
                while (clicks > 0) {
                    getInteractor().click(wc);
                    Task.sleep(500, 800);
                    clicks--;
                }
            }
        }
    }
    
    private WidgetChild findTravelLogEntry(String code) {
        WidgetChild[] entries = getInteractor()
                .getWidgetChild(FAIRYRING_PANEL, 13).getChildren();
        for(WidgetChild child : entries) {
            String entryCode = child.getText().replace(" ", "");
            if (entryCode.equalsIgnoreCase(code)) {
                return child;
            }
        }
        return null;
    }
    /**
     * Returns the set of types supported by this Interactor.
     * @return a set containing only the FairyRing.class object.
     */
    @Override
    public Set<Class<?>> getTypes() {
        HashSet<Class<?>> set = new HashSet<>(2);
        set.add(FairyRing.class);
        return set;
    }
    
}
