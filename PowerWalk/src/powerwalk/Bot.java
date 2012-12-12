package powerwalk;

import powerwalk.model.Grid;

/**
 * Bot-class representing the Player. 
 * The Bot can execute high-level tasks such as "travel to [destination]", 
 * "go to nearest [place of interest]", and others.
 * @author Vincent W, P.Kramer
 */
public class Bot {
    private static Bot theBot = new Bot();
    
    public static Bot getBot() {
        return theBot;
    }
    
    private Grid theWorldMap = new Grid();
    
    private Bot() {}
    
    public Grid getWorldMap() {
        return theWorldMap;
    }
    
    public void travelTo(String dest) {} //TODO (--) implement travelTo stub method
    
    public void gotoNearest(String dest) {} //TODO (--) implement gotoNearest stub method
}
