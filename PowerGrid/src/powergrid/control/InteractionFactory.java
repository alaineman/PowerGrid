package powergrid.control;

import java.io.InputStream;
import java.util.ArrayList;
import powergrid.PowerGrid;
import powergrid.model.GameObject;
import powergrid.model.XMLNode;

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
        Class<? extends GameObject> clazz = getClass(type);
        if (clazz == null) return;
        XMLNode server = null;
        ArrayList<XMLNode> clients = new ArrayList<>(type.children().size());
        for (XMLNode n : type) {
            if (n.getTag().equals("server")) {
                if (server == null) {
                    server = n;
                } else {
                    PowerGrid.logMessage("Critical error for type " + type.get("type") + ", there are multiple servers defined.");
                    return;
                }
            } else {
                clients.add(n);
            }
        }
        
        //TODO instantiate and connect the interactables.
    }
    
    private Class<? extends GameObject> getClass(XMLNode type) {
        String packageName = "powergrid.model.interact";
        if (type.get("manifold") != null)
            packageName += ".manifold";
        String className = type.get("type");
        if (type != null) {
            String name = packageName + "." + className;
            try {
                Class<?> clazz = Class.forName(name);
                if (GameObject.class.isAssignableFrom(clazz)) {
                    return clazz.asSubclass(GameObject.class);
                }
            } catch (ClassNotFoundException e) {
                PowerGrid.logMessage("The specified interaction type is not recognized: \"" + name + "\"", e);
            }
        }
        return null;
    }
    
    private void setUpPeers(XMLNode type) {
        Class<? extends GameObject> clazz = getClass(type);
        if (clazz == null) return;
        //TODO instantiate and connect the interactables.
    }
}
