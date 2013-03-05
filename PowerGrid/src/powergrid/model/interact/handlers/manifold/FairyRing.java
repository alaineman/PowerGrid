package powergrid.model.interact.handlers.manifold;

import java.util.ArrayList;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.node.SceneObject;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.model.OutOfReachException;
import powergrid.model.interact.Transportable;

/**
 *
 * @author Alaineman
 */
public class FairyRing extends Transportable {

    /**
     * These are the Transportable GameObject Id's.
     *
     * @see Transportable
     */
    public final static int[] values = {61345};
    
    WidgetChild scrollBar = Widgets.get(735, 80);
    WidgetChild travelWidget = null;
    boolean travelLog = false;
    static String ringCode = null;

    public enum RING_CODES {

        A(23, 0), B(24, 1), C(24, 2), D(23, 1),
        I(25, 0), J(26, 1), K(26, 2), L(25, 1),
        P(27, 0), Q(28, 1), R(28, 2), S(27, 1),;
        private final int direction;
        private final int clicks;

        /**
         *
         * @param direction Which widget child should be clicked.
         * @param clicks The amount of clicks on the specified widget.
         */
        RING_CODES(int direction, int clicks) {
            this.direction = direction;
            this.clicks = clicks;
        }
    }

    public FairyRing(int x,int y,int z,int rawNumber) {
        super(x, y, z, rawNumber, new ArrayList<FairyRing>(70));
    }

    @Override
    protected void handle(Transportable dest) throws OutOfReachException {
        SceneObject ring = SceneEntities.getNearest(values);
        if (ring == null || !ring.isOnScreen()) {
            throw new OutOfReachException(dest.getPosition(), "No cart nearby.");
        }
        ring.click(true);
        if (dest.getDestinations().length > 1) {
            ringCode = converToRingCode(dest.getWidgetNumber());
            Timer wait = new Timer(5000);
            while (wait.isRunning() && !Widgets.get(735).validate()) {
                Task.sleep(50, 100);
            }
            for (int i = 0; i < Widgets.get(735, 13).getChildren().length; i++) {
                if (Widgets.get(735, 13).getChild(i).getText()
                        .replaceAll(" ", "").equals(ringCode)) {
                    travelWidget = Widgets.get(735, 13).getChild(i);
                    travelLog = true;
                }
            }
            if (travelLog) {
                travelWidget.click(true);
                Task.sleep(2000, 3000);
            } else {
                selectRing(ringCode);
                Task.sleep(1000, 1500);
            }

            Widgets.get(734, 21).interact("Teleport");
        }
    }

    @Override
    protected void waitForCompletion(Transportable dest) {
        Timer anim = new Timer(8000);
        while (anim.isRunning() && Players.getLocal().getAnimation() != 3254) {
            Task.sleep(50, 100);
        }
        while (anim.isRunning() && Players.getLocal().getAnimation() == 3254) {
            Task.sleep(50, 100);
        }
        anim.reset();
        while (anim.isRunning() && Players.getLocal().getAnimation() == 3255) {
            Task.sleep(50, 100);
        }
    }

    @Override
    public boolean isAllowed(String method) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    private void selectRing(String ringCode) {
        for (int i = 0; i < RING_CODES.values().length; i++) {
            RING_CODES current = RING_CODES.values()[i];
            if (ringCode.contains(current.name())) {
                for (int q = 0; q < current.clicks; q++) {
                    Widgets.get(734, current.direction)
                            .click(true);
                    Task.sleep(500, 800);
                }
            }
        }
    }

public String converToRingCode(int widgetNumber) {
        char[] letters = new char[3];
        letters[2] = (char) (widgetNumber % 256);
        widgetNumber = (widgetNumber - letters[2]) / 256;
        letters[1] = (char) (widgetNumber % 256);
        widgetNumber = (widgetNumber - letters[1]) / 256;
        letters[0] = (char) (widgetNumber % 256);
        return String.valueOf(letters);
    }

    public int convertFromRingCode(String ringCode) {
        if (ringCode.length() != 3) {
            throw new IllegalArgumentException();
        }
        return ringCode.charAt(0) * 256 ^ 2 + ringCode.charAt(1) * 256 + ringCode.charAt(2);
    }
}
