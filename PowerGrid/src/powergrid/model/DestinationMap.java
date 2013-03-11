package powergrid.model;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.Set;

/**
 * Maps Strings (names) to Points and places in the Runescape world.
 * <p/>
 * This gives a more semantic representation of the various locations in the world.
 * It also allows for a more natural representation of places to end users.
 * <p/>
 * @author Chronio
 */
public class DestinationMap implements Copyable<DestinationMap> {
    
    private HashMap<String,Point> destinations = new HashMap<>();
    
    /**
     * Parses the XML data in the given XML node and adds the Destination data in it.
     * <p/>
     * The data is expexted to be of the form
     * <pre>
     * &lt;destinations&gt;
     *   &lt;dest name="someName" pos="(x,y,z)" /&gt;
     *   &lt;dest name="someOtherName" pos="(x,y,z)" /&gt;
     *   ...
     * &lt;/destinations&gt;
     * </pre>
     * <p/>
     * @param data the XML-data representing the destinations
     * @return itself for fluency
     */
    public DestinationMap withData(XMLElement data) {
        assert data != null;
        if (data.getTag().equals("destinations")) {
            for (XMLElement dest : data) {
                String name = dest.get("name");
                Point pos = Point.fromString(dest.get("pos"));
                if (name != null && !name.isEmpty() && pos != null) {
                    destinations.put(name.toLowerCase(), pos);
                }
            }
        }
        return this;
    }
    
    /**
     * Adds the destination in the given Map from destination name to Point
     * @param data the Map containing the data
     * @return itself for fluency
     */
    public DestinationMap withData(Map<String,Point> data) {
        assert data != null;
        for (Entry<String,Point> e : data.entrySet()) {
            if (e.getKey() != null && e.getValue() != null) {
                destinations.put(e.getKey().toLowerCase(), e.getValue());
            }
        }
        return this;
    }
    
    /**
     * Adds the destinations from another DestinationMap to this DestinationMap
     * @param data the DestinationMap containing the data
     * @return itself for fluency
     */
    public DestinationMap withData(DestinationMap data) {
        assert data != null;
        Set<String> keys = data.destinationNames();
        for (String name : keys) {
            destinations.put(name.toLowerCase(), data.getPoint(name));
        }
        return this;
    }
    
    /**
     * Returns the name for the given Point.
     * <p/>
     * If the Point has no matching name, the String "Point(x,y,z)" is returned,
     * where x, y, and z are replaced with the coordinates of the Point parameter.
     * @param pos the Point to look up the name for
     * @return the matching destination's name for the given Point, or a 
     *         String-representation when no name exists.
     */
    public String getName(Point pos) {
        assert pos != null;
        for (Entry<String,Point> e : destinations.entrySet()) {
            if (pos.equals(e.getValue()))
                return e.getKey();
        }
        return "Point" + pos.toString();
    }
    
    /**
     * Returns the position for the given String, or null if no such Point exists.
     * @param name the name to look up
     * @return the Point associated with the given name, or null if the name is not in this DestinationMap
     */
    public Point getPoint(String name) {
        return destinations.get(name.toLowerCase());
    }
    
    /**
     * Returns whether this DestinationMap contains the given name.
     * @param name the name to check
     * @return true if this DestinationMap contains the given name, or false otherwise
     */
    public boolean containsName(String name) {
        return destinations.containsKey(name.toLowerCase());
    }
    
    /**
     * Registers a new destination name, or overwrites an existing one.
     * <p/>
     * @param name the name for the destination. It should not be empty
     * @param point the Point the name links to.
     * @return the Point previously referenced by the given name, or null if the name
     *         was not in this DestinationMap
     */
    public Point register(String name, Point point) {
        assert name != null && !name.isEmpty() && point != null;
        return destinations.put(name.toLowerCase(), point);
    }
    
    /**
     * Returns a Set of the registered names in this DestinationMap.
     * @return a Set of the registered names in this DestinationMap
     */
    public Set<String> destinationNames() {
        return destinations.keySet();
    }
    
    /**
     * Removes the registered name from the DestinationMap.
     * @param name the name of the entry to remove
     * @return the Point previously registered under this name, or null if no 
     *         entry was removed.
     */
    public Point remove(String name) {
        return destinations.remove(name.toLowerCase());
    }
    
    /**
     * Returns the amount of registered Destinations
     * @return the amount of registered Destinations
     */
    public int size() {
        return destinations.size();
    }
    
    /**
     * Returns a copy of the DestinationMap.
     * @return a copy of the DestinationMap
     */
    @Override public DestinationMap copy() {
        return new DestinationMap().withData(this);
    }

    @Override public int hashCode() {
        int hash = 7;
        hash = 53 * hash + Objects.hashCode(this.destinations);
        return hash;
    }

    @Override public boolean equals(Object o) {
        if (o instanceof DestinationMap) {
            DestinationMap d = (DestinationMap)o;
            if (size() != d.size()) return false;
            for (String name : destinationNames()) {
                if (!getPoint(name).equals(d.getPoint(name)))
                    return false;
            }
            return true;
        }
        return false;
    }
    
    public static class Destination {
        private String name;
        private Point pos;
        public Destination(String name, Point pos) {
            this.name = name.toLowerCase();
            this.pos = pos;
        }
        public String getName() {
            return name;
        }
        public Point getPos() {
            return pos;
        }
        @Override
        public int hashCode() {
            int hash = 7;
            hash = 89 * hash + Objects.hashCode(this.name);
            hash = 89 * hash + Objects.hashCode(this.pos);
            return hash;
        }
        @Override public boolean equals(Object o) {
            if (o instanceof Destination) {
                Destination d = (Destination)o;
                return d.name.equals(name) && d.pos.equals(pos);
            }
            return false;
        }
        @Override public String toString() {
            return "Destination(\"" + name + "\" => " + pos + ")";
        }
    }
}
