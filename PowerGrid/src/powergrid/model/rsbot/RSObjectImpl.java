package powergrid.model.rsbot;

import org.powerbot.game.client.Model;
import org.powerbot.game.client.RSObject;

/**
 * Minimal implementation class for RSObject.
 * @author Chronio
 */
public class RSObjectImpl implements RSObject {

    private int id;
    private Model model;
    
    public RSObjectImpl(int id, Model model) {
        this.id = id;
        this.model = model;
    }
    
    @Override
    public int getId() {
        return id;
    }

    @Override
    public Model getModel() {
        return model;
    }
    
}
