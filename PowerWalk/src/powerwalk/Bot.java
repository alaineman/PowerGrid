package powerwalk;

import powerwalk.model.Grid;

/**
 * 
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
}
