/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import powerwalk.Bot;
import powerwalk.control.ToolBox;
import powerwalk.control.WidgetManager;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;

/**
 * Represents a Lodestone in the RSBot environment.
 *
 * @author Alaineman
 * @author P.Kramer
 */
public class Lodestone extends Teleportable {

    /**
     *
     */
    private int widgetNumber = -1;
    
    private String name = "";
    private static ArrayList<Lodestone> lodestones = new ArrayList<>(WidgetManager.lodestoneValues.length);

    /**
     *
     * @param x
     * @param y
     * @param z
     * @param rawNumber
     * @param loc
     */
    private Lodestone(int x, int y, int z, int rawNumber, int number, String name) {
        super(x, y, z, rawNumber);
        widgetNumber = number;
        this.name = name;
    }

    /**
     *
     * @param dest
     * @return
     */
    public static Lodestone getLodestone(String name) {
        for(Lodestone lode : lodestones){
            if(lode.getName().equalsIgnoreCase(name)) {
                return lode;
            }
        }
        return null;
    }

    public int getWidgetNumber() {
        return widgetNumber;
    } 

    public String getName() {
        return name;
    }    

    /**
     * 
     * @param dest
     * @return
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
            HashMap<String, String> tags = ToolBox.getAttributes(current);
            Point p = Point.fromString(tags.get("pos")); 
            Lodestone l = new Lodestone(p.x, p.y, p.z, -1, dest, tags.get("name"));
            lodestones.add(l);
            Bot.getBot().getWorldMap().set(p, l);
            
        } catch (IOException ex) {
        }       
    }

    @Override
    public void follow() throws OutOfReachException {
        WidgetManager.openLodestoneWidget();

    }

    @Override
    public boolean isAllowed(String method) {
        return lodestones.contains(this);
    }
}
