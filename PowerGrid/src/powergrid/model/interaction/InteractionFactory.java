package powergrid.model.interaction;

import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import powergrid.PowerGrid;
import powergrid.control.XMLToolBox;
import powergrid.model.GameObject;
import powergrid.model.Point;
import powergrid.model.XMLNode;
import powergrid.model.interact.Transportable;

/**
 * This class deals with setting up the interaction handlers and teleport 
 * connections.
 * <p/>
 * @author Chronio
 */
public class InteractionFactory {
    
    private XMLNode data;
    
    public InteractionFactory(InputStream source) {
        data = XMLToolBox.getXMLTree(source);
    }
    
    public void setUpInteractions() {
        for (XMLNode type : data) {
            switch (type.getTag()) {
                case "serverset":
                    setUpServerClient(type);
                    break;
                case "peerset":
                    setUpPeers(type);
                    break;
                default:
                    PowerGrid.logMessage("The interaction type \"" + type.getTag() + "\" is not recognized.");
            }
        }
    }
    
    private void setUpServerClient(XMLNode type) {
        Class<? extends Transportable> clazz = getClass(type);
        if (clazz == null) return;
        XMLNode serverNode = null;
        ArrayList<XMLNode> clients = new ArrayList<>(type.children().size());
        for (XMLNode n : type) {
            if (n.getTag().equals("server")) {
                if (serverNode == null) {
                    serverNode = n;
                } else {
                    PowerGrid.logMessage("Critical error for type " + type.get("type") + ", there are multiple servers defined.");
                    return;
                }
            } else {
                clients.add(n);
            }
        }
        Transportable server;
        try {
            Point p = Point.fromString(serverNode.getOrElse("pos", "(0,0)"));
            server = clazz.getConstructor(int.class,int.class,int.class,int.class).newInstance(p.x,p.y,p.z,-1);
        } catch (NoSuchMethodException | InstantiationException | IllegalAccessException | InvocationTargetException e) {
            return;
        }
        
        TreeNetwork network = new TreeNetwork(server);
        
        for (XMLNode n : clients) {
            Point p = Point.fromString(n.getOrElse("pos", "(0,0)"));
            try {
                Transportable t = clazz.getConstructor(int.class,int.class,int.class,int.class).newInstance(p.x,p.y,p.z,-1);
                network.add(t);
            } catch (InstantiationException | IllegalAccessException | InvocationTargetException | NoSuchMethodException e) {
                PowerGrid.logMessage("Could not instantiate transportable at " + p,e);
            }
        }
        //TODO instantiate and connect the interactables.
    }
    
    private Class<? extends Transportable> getClass(XMLNode type) {
        String packageName = "powergrid.model.interact";
        if (type.get("manifold") != null)
            packageName += ".manifold";
        String className = type.get("type");
        if (type != null) {
            String name = packageName + "." + className;
            try {
                Class<?> clazz = Class.forName(name);
                if (Transportable.class.isAssignableFrom(clazz)) {
                    return clazz.asSubclass(Transportable.class);
                }
            } catch (ClassNotFoundException e) {
                PowerGrid.logMessage("The specified interaction type is not recognized: \"" + name + "\"", e);
            }
        }
        return null;
    }
    
    private void setUpPeers(XMLNode type) {
        Class<? extends Transportable> clazz = getClass(type);
        if (clazz == null) return;
        PeerNetwork network = new PeerNetwork();
        for (XMLNode node : type) {
            Point p = Point.fromString(node.getOrElse("pos", "(0,0)"));
            try {
                Transportable t = clazz.getConstructor(int.class,int.class,int.class,int.class).newInstance(p.x,p.y,p.z,-1);
                network.add(t);
            } catch (InvocationTargetException | InstantiationException | 
                    IllegalAccessException | NoSuchMethodException e) {
                PowerGrid.logMessage("Could not instantiate transportable at " + p,e);
            }
        }
    }
}
