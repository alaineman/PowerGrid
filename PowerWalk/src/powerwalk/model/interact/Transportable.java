package powerwalk.model.interact;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.NoSuchElementException;
import powerwalk.control.XMLToolBox;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.XMLNode;

/**
 * Represents a GameObject that allows a transport to another Transportable.
 *
 * @author Alaineman
 * @author P.Kramer
 */
public abstract class Transportable extends Teleportable {

    private ArrayList<Transportable> destinations;

    /**
     * Creates a new
     * <code>Transportable</code> at the specified position and with the
     * specified raw value. <p> the destinations for this Transportable are
     * defined in dests</p>
     *
     * @param x the x-coordinate of the <code>Teleportable</code>
     * @param y the y-coordinate of the <code>Teleportable</code>
     * @param z the z-coordinate of the <code>Teleportable</code>
     * @param rawNumber the raw value for this object from the RSBot environment
     */
    public Transportable(int x, int y, int z, int rawNumber, Collection<? extends Transportable> dests) {
        super(x, y, z, rawNumber);
        destinations = new ArrayList<>(dests);
    }

    /**
     * Teleports you to the designated Point.
     *
     * @throws OutOfReachException when the requirements are not met or this
     * Transportable cannot be used to travel to Transportable dest.
     * @param dest the Point of destination.
     */
    public void follow(Transportable dest) throws OutOfReachException {
        handle(dest);
        waitForCompletion(dest);
    }

    protected abstract void handle(Transportable dest) throws OutOfReachException;

    protected void waitForCompletion(Transportable dest) {
    }

    public boolean addDestination(Transportable dest) {
        if (dest == null || destinations.contains(dest)) {
            return false;
        }
        return destinations.add(dest);
    }

    /**
     * Teleports you to the first destination Point. <p>When there are no
     * destinations for this Transportable, this method does nothing.
     *
     * @throws OutOfReachException when the requirements are not met.
     */
    @Override
    public void follow() throws OutOfReachException {
        if (!destinations.isEmpty()) {
            follow(destinations.get(0));
        }
    }

    /**
     * Returns available destinations for this Transportable.
     *
     * @return the available destinations.
     */
    public Transportable[] getDestinations() {
        return destinations.toArray(new Transportable[0]);
    }

    public String getTraits() {
        try {
            XMLNode file = XMLToolBox.getXMLTree(ClassLoader.getSystemResource("powerwalk/data/specialLocations.xml").openStream());
            XMLNode[] node = XMLToolBox.filterNodes(file, "name", getClass().getSimpleName()); // of andere naam
            if (node.length > 0) {
                XMLNode transportType = node[0];
                for (XMLNode vertex : transportType) {
                    if (Point.fromString(vertex.get("pos")).equals(getPosition())) {
                       return vertex.get("traits");
                    }
                }
                return null;
            } else {
                throw new NoSuchElementException("No such Transporttype found");
            }
        } catch (IOException ex) {
            return null;
        }
    }

    public int[] getNPCIDs() {
        try {
            XMLNode file = XMLToolBox.getXMLTree(ClassLoader.getSystemResource("powerwalk/data/specialLocations.xml").openStream());
            XMLNode[] node = XMLToolBox.filterNodes(file, "name", getClass().getSimpleName()); // of andere naam
            if (node.length > 0) {
                XMLNode transportType = node[0];
                for (XMLNode vertex : transportType) {
                    if (Point.fromString(vertex.get("pos")).equals(getPosition())) {
                        if (vertex.get("target") != null) {
                            String[] npcidString = vertex.get("target").split("|");
                            int[] npcIds = new int[npcidString.length];
                            for (int i = 0; i < npcidString.length; i++) {
                                npcIds[i] = Integer.parseInt(npcidString[i].substring(1));
                            }
                            return npcIds;
                        }
                    }
                }
                return null;
            } else {
                throw new NoSuchElementException("No such Transporttype found");
            }
        } catch (IOException ex) {
            return null;
        }
    }
}

