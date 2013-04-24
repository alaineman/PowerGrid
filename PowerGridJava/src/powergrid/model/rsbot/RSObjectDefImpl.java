package powergrid.model.rsbot;

import java.util.Arrays;
import org.powerbot.game.client.RSObjectDef;
import org.powerbot.game.client.RSObjectDefLoader;

/**
 * Minimal implementation class for RSObjectDef interface.
 * @author Chronio
 */
public class RSObjectDefImpl implements RSObjectDef {

    private String name;
    private String[] actions;
    private RSObjectDefLoader loader;
    private int id;

    /**
     * Creates a new RSObjectDefImpl object with the given data.
     * @param name the name of the object
     * @param actions the actions that can be performed on the object
     * @param loader the definition loader of this definition
     * @param id the id of the object
     */
    public RSObjectDefImpl(String name, String[] actions, RSObjectDefLoader loader, int id) {
        this.name = name;
        this.actions = Arrays.copyOf(actions, actions.length);
        this.loader = loader;
        this.id = id;
    }
    
    @Override
    public String getName() {
        return name;
    }

    @Override
    public String[] getActions() {
        return Arrays.copyOf(actions, actions.length);
    }

    @Override
    public RSObjectDefLoader getLoader() {
        return loader;
    }

    @Override
    public int getID() {
        return id;
    }
    
}
