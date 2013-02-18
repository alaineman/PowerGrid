package powerwalk.model;

import java.io.InputStream;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.Set;
import powerwalk.PowerGrid;
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
    
    /**
     * Creates a new destination with the given name at the given position
     * @param p the position this Destination points to
     * @param name the name given to this Destination
     * @throws IllegalArgumentException when the provided Point is null
     */
    public Destination(Point p, String name) {
        if (p == null) 
            throw new IllegalArgumentException("Point cannot be null");
        this.dest = new Point(p);
        if (name != null && !name.isEmpty())
            this.name = name;
    }
    /**
     * Returns the name assigned to this Destination.
     * @return the name assigned to this Destination.
     */
    public String getName() {
        return name;
    }
    /**
     * Returns the Point that this Destination points to.
     * @return the Point that this Destination points to.
     */
    public Point getPosition() {
        return new Point(dest);
    }
    /**
     * Returns the hashCode for this Destination
     * @return the hashCode for this Destination
     */
    @Override public int hashCode() {
        return 7 * Objects.hashCode(name) + 11 * Objects.hashCode(dest);
    }
    /**
     * Returns whether this Destination is equal to another Object.
     * <p/>
     * This method returns true if the other Object is a Destination, the name 
     * given to that Destination is the same as the name given to this Destination, 
     * and the two Destination point to the same position.
     * @param other the Object to compare with
     * @return whether this Destination is equal to another Object
     */
    @Override public boolean equals(Object other) {
        if (other instanceof Destination) {
            Destination that = (Destination)other;
            return this.getName().equals(that.getName()) && this.getPosition().equals(that.getPosition());
        }
        return false;
    }
    /**
     * Returns a String-representation of this Destination.
     * @return a String-representation of this Destination.
     */
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
        for (XMLNode n : tree) {
            if (n.getTag().equals("dest")) {
                try { 
                    destinations.put(n.get("name"),Point.fromString(n.get("pos")));
                } catch (NumberFormatException e) {
                    PowerGrid.logMessage("A Destination could not be read");
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
