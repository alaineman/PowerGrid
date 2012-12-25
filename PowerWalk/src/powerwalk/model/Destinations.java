package powerwalk.model;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.powerbot.game.api.wrappers.Tile;
import powerwalk.control.ToolBox;

/**
 * Utility class that maps destination Strings to their respective Tiles in the World.
 * @author P.Kramer
 */
public class Destinations {
    
    /**
     * (re)collects the destination information and stores it for lookup.
     * There is no need to call this method before looking up destinations, the getDestination() method automatically loads the destinationList when it hasn't been loaded yet.
     */
    public synchronized static void setupDestinationList() {
        destinations.clear();
        InputStream in = ClassLoader.getSystemResourceAsStream("powerwalk/data/destinations.xml");
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(in))) {
            String current = reader.readLine();
            
            while (reader.ready()) {
                if (ToolBox.getTagFromXML(current).equals("dest")) {
                    HashMap<String,String> data = ToolBox.getAttributes(current);
                    String key = data.get("name");
                    String pos = data.get("pos");
                    try {
                        pos = pos.substring(pos.indexOf("(")+1,pos.lastIndexOf(")"));
                        String[] coords = pos.split(",");
                        int x=0,y=0,z=0;
                        if (coords.length > 0) x = Integer.parseInt(coords[0]);
                        if (coords.length > 1) y = Integer.parseInt(coords[1]);
                        if (coords.length > 2) z = Integer.parseInt(coords[2]);

                        destinations.put(key,new Tile(x,y,z));

                    } catch (StringIndexOutOfBoundsException | NumberFormatException e) {
                        Logger.getLogger("Destinations").log(Level.FINE,"Destination " + current + " could not be read",e);
                    }
                }
                current = reader.readLine();
            }
        } catch (IOException iox) {
            Logger.getLogger("Destinations").log(Level.WARNING,"I/O Error while reading destinations",iox);
        }
    }
    
    /**
     * Purges the destinationList, freeing the memory used. Please be aware that 
     * the next call to getDestination will rebuild the destination List.
     * 
     * <p>Note that purging the destinationList will erase any custom destinations 
     * set with the <code>setCustomDestination(name,destination)</code> method.</p>
     */
    public static void purge() {
        destinations = new HashMap<>();
    }
    
    /**
     * get the Tile corresponding to a location.
     * @param dest the destination to look up.
     * @return the Tile corresponding to the String, or null if no match was found
     */
    public synchronized static Tile getDestination(String dest) {
        if (destinations.isEmpty()) {
            setupDestinationList();
        }
        return destinations.get(dest);
    }
    
    /**
     * Returns a Set containing the available destinations 
     * @return a Set containing the available destinations.
     */
    public static Set<String> getAvailableDestinations() {
        if (destinations.isEmpty()) setupDestinationList();
        return destinations.keySet();
    }
    
    public static Set<Entry<String,Tile>> getEntries() {
        if (destinations.isEmpty()) {
            setupDestinationList();
        }
        return destinations.entrySet();
    }
    
    /**
     * Assigns a custom binding for a specified String.
     * <p>consecutive calls to <code>getDestination(name)</code> will return the 
     * position specified by <code>Destination</code>.</p>
     * @param name the name of the Destination
     * @param destination the location of the Destination
     */
    public static void setCustomDestination(String name,Point destination) {
        destinations.put(name,destination.toTile());
    }
    
    private static HashMap<String,Tile> destinations = new HashMap<>();
}
