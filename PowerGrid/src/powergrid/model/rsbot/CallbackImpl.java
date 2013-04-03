package powergrid.model.rsbot;

import org.powerbot.game.client.Callback;
import org.powerbot.game.client.Render;

/**
 * Minimal implementation class for the Callback interface.
 * <p/>
 * The methods in this class do nothing, and can be overridden by subclasses 
 * when required.
 * @author Patrick Kramer
 */
public class CallbackImpl implements Callback {

    @Override
    public void updateRenderInfo(Render render) {}

    @Override
    public void notifyMessage(int i, String string, String string1) {}
    
}
