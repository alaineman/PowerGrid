package powerwalk.model.interact;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.control.WidgetManager;
import powerwalk.control.XMLToolBox;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

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
    private static ArrayList<Lodestone> lodestones = new ArrayList<>(WidgetManager.lodestoneValues.length);
    
    /**
     * Adds a Lodestone to the list of available Lodestones,
     * using its widget id on the Lodestone map.
     * @param dest the widget id of the Lodestone to be added.
     */
    public static void addLodestone(int dest) {
        for(Lodestone lode : lodestones){
            if(lode.getWidgetNumber() == dest){
                return;
            }
        }
        InputStream in = ClassLoader.getSystemResourceAsStream("powerwalk/data/lodestones.xml");
        try (BufferedReader myReader = new BufferedReader(new InputStreamReader(in))) {
            String current = myReader.readLine();
            while (!current.contains("<lodestone ")) {
                current = myReader.readLine();
            }
            while (!current.contains("widget=\"" + dest + "\"")) {
                current = myReader.readLine();
            }
            HashMap<String, String> tags = XMLToolBox.getAttributes(current);
            Point p = Point.fromString(tags.get("pos"));
            Lodestone l = new Lodestone(p.x, p.y, p.z, -1, dest, tags.get("name"));
            lodestones.add(l);
            Bot.getBot().getWorldMap().set(p, l);
        } catch (IOException ex) {}
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
        WidgetChild w = Widgets.getChild(widgetNumber);
        if (w == null) throw new OutOfReachException("The required widget was not found");
        if (!w.click(true)) {
            // we failed, but let's try again
            Task.sleep(134,257);
            if (!w.click(true)) {
                // we still failed. Now, something must be wrong. Report and cancel the follow() operation
                Starter.logMessage("Teleport to " + name + " failed: cannot click widget","Interact");
                throw new OutOfReachException(getPosition(),"Failed to click widget");
            }
        }
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
}
