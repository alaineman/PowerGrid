package powergrid.task;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import powergrid.PowerGrid;
import powergrid.control.PathFinder;
import powergrid.control.XMLToolBox;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;
import powergrid.model.XMLNode;

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
    public List<XMLNode> getMatching() {
        XMLNode root = XMLToolBox.getXMLTree(ClassLoader.getSystemResourceAsStream("powergrid/data/specialLocations.xml"));
        // look for the correct type
        XMLNode typeNode = null;
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
        List<XMLNode> matches;
        if (target == null || target.isEmpty()) {
            matches = typeNode.children();
        } else {
            matches = Arrays.asList(XMLToolBox.filterNodes(typeNode, "target", target));
        }
        
        if (traits != null && !traits.isEmpty()) {
            matches = Arrays.asList(XMLToolBox.filterNodes(new XMLNode("",null,matches), "traits", traits));
        }
        return matches;
    }
    
    @Override public synchronized void start() {
        List<XMLNode> matches = getMatching();
        path = calculateNearest(PowerGrid.BOT.getPosition(),matches);
    }
    
    public static List<Point> calculateNearest(final Point from, List<XMLNode> options) {
        if(options == null) throw new IllegalArgumentException("Invalid Iterable of nodes: null");
        if (from == null) throw new IllegalArgumentException("Invalid supplied origin: null");
        
        Collections.sort(options, new PointComparator(from));
        
        List<Point> shortest = null;
        // ensure that 3 <= retries <= 7, but retries < options.size()
        int retries = Math.min(Math.max(3, Math.min(7, options.size()/6)), options.size());
        long startTime = System.currentTimeMillis();
        Iterator<XMLNode> it = options.iterator();
        while (it.hasNext() && retries > 0) {
            XMLNode n = it.next();
            Point dest = new Point(n.get("pos"));
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
    
    private static class PointComparator implements Comparator<XMLNode> {
        private Point from;
        public PointComparator(Point from) {
            this.from = from;
        }
        
        @Override public int compare(XMLNode one, XMLNode two) {
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