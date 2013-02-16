package powerwalk.tasks;

import java.util.Arrays;
import java.util.List;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.control.PathFinder;
import powerwalk.control.XMLToolBox;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.XMLNode;

/**
 * Calculates a path to the nearest position matching certain criteria and walks it.
 * <p/>
 * 
 * @author Chronio
 */
public class TravelNearestTask extends TravelTask {
    
    private String type = "";
    private String target = "";
    private String traits = "";
    
    public TravelNearestTask(String type, String target, String traits) {
        if (type != null)
            this.type = type;
        if (target != null)
            this.target = target;
        if (traits != null)
            this.traits = traits;
    }
    public TravelNearestTask(String type, String target) {
        this(type,target,"");
    }
    public TravelNearestTask(String type) {
        this(type,"","");
    }
    
    public String getType() {
        return type;
    }
    public String getTarget() {
        return target;
    }
    public String getTraits() {
        return traits;
    }
    public Iterable<XMLNode> getMatching() {
        XMLNode root = XMLToolBox.getXMLTree(ClassLoader.getSystemResourceAsStream("powerwalk/data/specialLocations.xml"));
        // look for the correct type, they are sorted on "name", so binSearch:
        XMLNode typeNode = null;// = XMLToolBox.binarySearch(root.children(), "name", type);
        for (XMLNode child : root) {
            if (child.get("name").equals(type)) {
                typeNode = child;
                break;
            }
        }
        if (typeNode == null) {
            cancel();
            return null;
        }
        // we now have the correct type, now match target
        Iterable<XMLNode> matches;
        if (target == null || target.isEmpty()) {
            matches = typeNode;
        } else {
            matches = Arrays.asList(XMLToolBox.filterNodes(typeNode, "target", target));
        }
        
        if (traits != null && !traits.isEmpty()) {
            matches = Arrays.asList(XMLToolBox.filterNodes(matches, "traits", traits));
        }
        return matches;
    }
    
    @Override public synchronized void start() {
        Iterable<XMLNode> matches = getMatching();
        path = calculateNearest(Bot.getBot().getPosition(),matches);
    }
    
    public static List<Point> calculateNearest(Point from, Iterable<XMLNode> nodes) {
        if(nodes == null) throw new IllegalArgumentException("Invalid Iterable of nodes: null");
        if (from == null) throw new IllegalArgumentException("Invalid supplied origin: null");
        List<Point> shortest = null;
        int length = Integer.MAX_VALUE;
        for (XMLNode n : nodes) {
            try {
                List<Point> path = new PathFinder(from,Point.fromString(n.getOrElse("pos", "(0,0)"))).calculatePath();
                if (path.size() < length) {
                    shortest = path;
                    length = path.size();
                }
            } catch (OutOfReachException e) {
                Starter.logMessage("Found possible location " + e.getDestination() + ", but it could not be reached","TravelToNearest",e);
            }
        }
        return shortest;
    }
    
}
