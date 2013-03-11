package powergrid.model.interaction;

import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import powergrid.PowerGrid;
import powergrid.control.XMLParser;
import powergrid.model.Point;
import powergrid.model.XMLElement;
import powergrid.model.interact.Transportable;

/**
 * This class deals with setting up the interaction handlers and teleport 
 * connections.
 * <p/>
 * @author Chronio
 */
public class InteractionFactory {
    
    private HashMap<String,TransportNetwork> networks = new HashMap<>();
    
    public void loadConnections(InputStream source) {
        assert source != null;
        XMLElement data = XMLParser.getXMLTree(source);
        networks.clear();
        for (XMLElement type : data.childElements()) {
            switch (type.getTag()) {
                case "serverset":
                    setUpServerClient(type);
                case "peerset":
                    setUpPeers(type);
                default:
                    PowerGrid.logMessage("The interaction type \"" + type.getTag() + "\" is not recognized.");
            }
        }
    }
    
    public TransportNetwork getInteractions(String type) {
        TransportNetwork nw = networks.get(type);
        if (nw != null) return nw;
        else throw new IllegalArgumentException("Unknown transport type: " + type);
    }
    
    public Collection<TransportNetwork> getLoadedNetworks() {
        return networks.values();
    }
    
    private TreeNetwork setUpServerClient(XMLElement type) {
        Class<? extends Transportable> clazz = getClass(type);
        if (clazz == null) return null;
        XMLElement serverNode = null;
        ArrayList<XMLElement> clients = new ArrayList<>(type.childElements().size());
        for (XMLElement n : type.childElements()) {
            if (n.getTag().equals("server")) {
                if (serverNode == null) {
                    serverNode = n;
                } else {
                    PowerGrid.logMessage("Critical error for type " + type.get("type") + ", there are multiple servers defined.");
                    return null;
                }
            } else {
                clients.add(n);
            }
        }
        Transportable server;
        try {
            Point p = new Point(serverNode.getOrElse("pos", "(0,0)"));
            server = clazz.getConstructor(int.class,int.class,int.class,int.class).newInstance(p.x,p.y,p.z,-1);
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            return null;
        }
        
        TreeNetwork network = new TreeNetwork(server);
        
        for (XMLElement n : clients) {
            Point p = new Point(n.getOrElse("pos", "(0,0)"));
            try {
                Transportable t = clazz.getConstructor(int.class,int.class,int.class,int.class).newInstance(p.x,p.y,p.z,-1);
                network.add(t);
            } catch (InstantiationException | IllegalAccessException | InvocationTargetException | NoSuchMethodException e) {
                PowerGrid.logMessage("Could not instantiate transportable at " + p,e);
            }
        }
        networks.put(type.get("type"), network);
        return network;
    }
    
    private Class<? extends Transportable> getClass(XMLElement type) {
        assert type != null;
        String packageName = "powergrid.model.interact";
        if (type.get("manifold") != null)
            packageName += ".manifold";
        String className = type.get("type");
        String name = packageName + "." + className;
        try {
            Class<?> clazz = Class.forName(name);
            if (Transportable.class.isAssignableFrom(clazz)) {
                return clazz.asSubclass(Transportable.class);
            }
        } catch (ClassNotFoundException e) {
            PowerGrid.logMessage("The specified interaction type is not recognized: \"" + name + "\"", e);

        }
        return null;
    }
    
    private PeerNetwork setUpPeers(XMLElement type) {
        Class<? extends Transportable> clazz = getClass(type);
        if (clazz == null) return null;
        PeerNetwork network = new PeerNetwork();
        for (XMLElement node : type.childElements()) {
            Point p = new Point(node.getOrElse("pos", "(0,0)"));
            try {
                Transportable t = clazz.getConstructor(int.class,int.class,int.class,int.class).newInstance(p.x,p.y,p.z,-1);
                network.add(t);
            } catch (InvocationTargetException | InstantiationException | 
                    IllegalAccessException | NoSuchMethodException e) {
                PowerGrid.logMessage("Could not instantiate transportable at " + p,e);
            }
        }
        networks.put(type.get("type"), network);
        return network;
    }
}
