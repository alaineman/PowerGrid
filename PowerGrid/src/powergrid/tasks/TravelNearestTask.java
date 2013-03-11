package powergrid.tasks;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import powergrid.PowerGrid;
import powergrid.control.PathFinder;
import powergrid.control.XMLParser;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.XMLElement;

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
    public List<XMLElement> getMatching() {
        XMLElement root = XMLParser.getXMLTree(ClassLoader.getSystemResourceAsStream("powergrid/data/specialLocations.xml"));
        // look for the correct type
        XMLElement typeNode = null;
        for (XMLElement child : root.childElements()) {
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
        List<XMLElement> matches;
        if (target == null || target.isEmpty()) {
            matches = typeNode.childElements();
        } else {
            matches = Arrays.asList(XMLParser.filterNodes(typeNode, "target", target));
        }
        
        if (traits != null && !traits.isEmpty()) {
            matches = Arrays.asList(XMLParser.filterNodes(new XMLElement("",null,matches), "traits", traits));
        }
        return matches;
    }
    
    @Override public synchronized void start() {
        List<XMLElement> matches = getMatching();
        path = calculateNearest(PowerGrid.BOT.getPosition(),matches);
    }
    
    public static List<Point> calculateNearest(final Point from, List<XMLElement> options) {
        if(options == null) throw new IllegalArgumentException("Invalid Iterable of nodes: null");
        if (from == null) throw new IllegalArgumentException("Invalid supplied origin: null");
        
        Collections.sort(options, new PointComparator(from));
        
        List<Point> shortest = null;
        // ensure that 3 <= retries <= 7, but retries < options.size()
        int retries = Math.min(Math.max(3, Math.min(7, options.size()/6)), options.size());
        long startTime = System.currentTimeMillis();
        Iterator<XMLElement> it = options.iterator();
        while (it.hasNext() && retries > 0) {
            XMLElement n = it.next();
            Point dest = new Point(n.get("pos"));
            if (dest == null) continue;
            try {
                List<Point> trial = new PathFinder(from,dest).calculatePath();
                if (shortest == null || shortest.size() > trial.size()) {
                    shortest = trial;
                }
                long timePassed = System.currentTimeMillis() - startTime;
                if (timePassed > 10000 && shortest != null) {
                    // 10 second time-out
                    break;
                }
                retries--;
            } catch (OutOfReachException e) {
                PowerGrid.logMessage("Found point " + dest + ", but could not reach it");
            }
        }
        
        return shortest;
    }
    
    private static class PointComparator implements Comparator<XMLElement> {
        private Point from;
        public PointComparator(Point from) {
            this.from = from;
        }
        
        @Override public int compare(XMLElement one, XMLElement two) {
            Point pOne = new Point(one.getOrElse("pos", "(0,0)"));
            Point pTwo = new Point(two.getOrElse("pos", "(0,0)"));
            return (int)(pOne.distance(from) - pTwo.distance(from));
        }
        
    }

    @Override public boolean equals(Object other) {
        if (other instanceof TravelNearestTask) {
            TravelNearestTask that = (TravelNearestTask)other;
            if (!this.getTarget().equals(that.getTarget())) return false;
            if (!this.getTraits().equals(that.getTraits())) return false;
            if (!this.getType().equals(that.getType())) return false;
            
            return true;
        }
        
        return false;
    }
}
