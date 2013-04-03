package powergrid.model.world;

import powergrid.model.OutOfReachException;

/**
 * This class represents aggressive or otherwise non-friendly Entities, whose main 
 * purpose is to attack or be attacked.
 * @author Chronio
 */
@Deprecated
public class Enemy extends Entity {

    public static final int[] values = new int[] {};
    
    public Enemy(int x,int y,int z,int rawValue) {
        super(x,y,z,rawValue);
    }
    

    /**
     * tries to attack the Enemy by using the interaction method labeled "attack".
     * @throws UnsupportedOperationException when the action failed, or when no attack method was found
     * @throws OutOfReachException when the target is not nearby
     */
    public void attack() throws OutOfReachException {
        throw new UnsupportedOperationException();
    }
}
