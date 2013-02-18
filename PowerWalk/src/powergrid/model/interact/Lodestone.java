package powergrid.model.interact;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Objects;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.PowerGrid;
import powergrid.control.Mapper;
import powergrid.control.XMLToolBox;
import powergrid.control.uicontrols.WidgetManager;
import powergrid.model.GameObject;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.XMLNode;

/**
 * Represents a Lodestone in the RSBot environment.
 *
 * @author Alaineman
 * @author Chronio
 */
public class Lodestone extends Teleportable {

    private int widgetNumber = -1;
    private String name = "";
    
    //<editor-fold defaultstate="collapsed" desc="static part">
    private static HashSet<Lodestone> lodestones = new HashSet<>(WidgetManager.lodestoneValues.length);
    private static XMLNode lodestoneTree = null;
    
    /**
     * Adds a Lodestone to the list of available Lodestones,
     * using its widget id on the Lodestone map.
     * <p/>
     * When the Lodestone was already added, this method does nothing.
     * @param dest the widget id of the Lodestone to be added.
     * @throws IllegalArgumentException when the given widget id does not resemble a Lodestone widget
     */
    public static void addLodestone(int dest) {
        
        if (lodestoneTree == null) {
            InputStream in = ClassLoader.getSystemResourceAsStream("powerwalk/data/lodestones.xml");
            lodestoneTree = XMLToolBox.getXMLTree(in);
        }
        XMLNode[] matches = XMLToolBox.filterNodes(lodestoneTree, "widget", String.valueOf(dest));
        if (matches.length > 0) {
            Point p = Point.fromString(matches[0].get("pos"));
            GameObject go = Mapper.getWorldMap().get(p);
            lodestones.add(new Lodestone(p.x,p.y,p.z,(go == null ? 0 : go.getRawNumber()),dest,matches[0].get("name")));
        }
    }
    
    /**
     * returns the Lodestone with the given destination, or null if there is no
     * such available Lodestone
     * @param name the destination name of the Lodestone
     * @return the Lodestone corresponding to the given destination.
     */
    public static Lodestone getLodestone(String name) {
        for(Lodestone lode : lodestones){
            if(lode.getName().equalsIgnoreCase(name)) {
                return lode;
            }
        }
        return null;
    }
    
    public static Lodestone getLodestone(Point p) {
        for (Lodestone l : lodestones) {
            if (l.getPosition().equals(p))
                return l;
        }
        return null;
    }
    
    /**
     * returns a List containing all available Lodestones.
     * @return a List containing all available Lodestones.
     */
    public static ArrayList<Lodestone> getAvailableLodestones() {
        return new ArrayList<>(lodestones);
    }
    //</editor-fold>
    
    private Lodestone(int x, int y, int z, int rawNumber, int number, String name) {
        super(x, y, z, rawNumber);
        widgetNumber = number;
        this.name = name;
    }

    /**
     * returns the number of the Widget corresponding to this Lodestone
     * @return the number of the Widget corresponding to this Lodestone
     */
    @Override public int getWidgetNumber() {
        return widgetNumber;
    } 

    /**
     * Returns a String representation of the destination of this Lodestone.
     * @return a String representation of the destination of this Lodestone
     */
    public String getName() {
        return name;
    }
    
    /**
     * Teleports to this Lodestone
     * @throws OutOfReachException 
     */
    @Override public void follow() throws OutOfReachException {
        // we locate the correct widgetChild in the lodestone widget
        WidgetManager.openLodestoneWidget();
        WidgetChild w = Widgets.get(1092,widgetNumber);
        if (w == null) throw new OutOfReachException("The required widget was not found");
        
        Mouse.click(w.getCentralPoint(),true);
        if (!Mouse.click(w.getCentralPoint(),true)) {
            // we failed, but let's try again
            Task.sleep(134,257);
            if (!Mouse.click(w.getCentralPoint(),true)) {
                // we still failed. Now, something must be wrong. Report and cancel the follow() operation
                PowerGrid.logMessage("Teleport to " + name + " failed: cannot click widget");
                throw new OutOfReachException(getPosition(),"Failed to click widget");
            }
        }
        Task.sleep(2000,4000);
        // appeareantly, we succeeded in clicking the widget, now we wait for the animations.
        Player local = Players.getLocal();
        while (local.getAnimation() == 16385 || local.getAnimation() == 16393) {
            Task.sleep(128,217);
        }
        // Now we arrived, assert that the player is idle before returning
        while (local.getAnimation() != -1) {
            Task.sleep(135,385);
        }
    }

    /**
     * Returns whether this Lodestone can be traveled to.
     * <p>A Lodestone can be traveled to when it has been added to the Lodestone list using <code>Lodestone.addLodestone(id)</code></p>
     * @param method the method of interaction. Since a Lodestone only has one method, this is ignored for Lodestones.
     * @return true if and only if the Lodestone can be traveled to, false otherwise
     */
    @Override public boolean isAllowed(String method) {
        return lodestones.contains(this);
    }
    
    @Override public int hashCode() {
        return 7 + 3* widgetNumber + 5*Objects.hashCode(name) + 2*super.hashCode();
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof Lodestone) {
            Lodestone that = (Lodestone)other;
            return this.getWidgetNumber() == that.getWidgetNumber() && this.getName().equals(that.getName());
        }
        return false;
    }
}
