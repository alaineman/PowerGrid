package powerwalk.model;

import java.io.InputStream;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.Set;
import powerwalk.Starter;
import powerwalk.control.XMLToolBox;

/**
 * Defines a destination by linking a location in the world to a name. 
 * This improves the readability and ease of access for end-users.
 * @author Chronio
 */
public class Destination {
    
    private static HashMap<String,Point> destinations = new HashMap<>();
    
    private Point dest;
    private String name = "undefined";
    
    public Destination(Point p, String name) {
        this.dest = new Point(p);
        if (name != null && !name.isEmpty())
            this.name = name;
    }
    
    public String getName() {
        return name;
    }
    
    public Point getPosition() {
        return new Point(dest);
    }
    
    @Override public int hashCode() {
        return 7 * Objects.hashCode(name) + 11 * Objects.hashCode(dest);
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof Destination) {
            Destination that = (Destination)other;
            return this.getName().equals(that.getName()) && this.getPosition().equals(that.getPosition());
        }
        return false;
    }
    
    @Override public String toString() {
        return "Destination(\"" + name + "\" at " + dest + ")";
    }
    
    /**
     * (re)collects the destination information and stores it for lookup.
     * <p/>
     * There is no need to call this method before looking up destinations, the 
     * getDestination() method automatically loads the destinationList when it 
     * hasn't been loaded yet.
     * <p/>
     * Calling this method will erase any custom destinations currently registered.
     */
    public synchronized static void setupDestinationList() {
        destinations.clear();
        InputStream in = ClassLoader.getSystemResourceAsStream("powerwalk/data/destinations.xml");
        XMLNode tree = XMLToolBox.getXMLTree(in);
        for (XMLNode n : tree.children()) {
            if (n.getTag().equals("dest")) {
                try { 
                    destinations.put(n.get("name"),Point.fromString(n.get("pos")));
                } catch (NumberFormatException e) {
                    Starter.logMessage("A Destination could not be read","Destinations",e);
                }
            }
        }
    }
    
    /**
     * Get the Destination corresponding to a given name.
     * @param dest the destination name to look up.
     * @return the Destination corresponding to the String, or null if no match was found
     */
    public synchronized static Destination getDestination(String dest) {
        if (destinations.isEmpty())
            setupDestinationList();
        Point p = destinations.get(dest);
        if (p == null) return null;
        return new Destination(p,dest);
    }
    
    public synchronized static Destination[] getDestinations() {
        if (destinations.isEmpty())
            setupDestinationList();
        Destination[] dests = new Destination[destinations.size()];
        int index = 0;
        for (Entry<String,Point> e : destinations.entrySet())
            dests[index++] = new Destination(e.getValue(),e.getKey());
        return dests;
    }
    
    /**
     * checks if a destination is set for the given point.
     * @param p the Point to look up
     * @return the destination that maps to the given Point, or null if none exists
     */
    public synchronized static Destination getDestination(Point p) {
        if (p == null) return null;
        Set<Entry<String,Point>> entries = destinations.entrySet();
        for (Entry<String,Point> e : entries) {
            if (p.equals(e.getValue())) {
                return new Destination(p,e.getKey());
            }
        }
        return null;
    }
    
    /**
     * Assigns a custom binding for a specified String.
     * <p>after this method returns, calls to <code>getDestination(name)</code> will return the 
     * position specified by <code>destination</code>.</p>
     * @param name the name of the Destination
     * @param destination the location of the Destination
     */
    public synchronized static void setCustomDestination(String name,Point destination) {
        destinations.put(name,destination);
    }
    
    public synchronized static void setCustomDestination(Destination dest) {
        setCustomDestination(dest.getName(), dest.getPosition());
    }
}
