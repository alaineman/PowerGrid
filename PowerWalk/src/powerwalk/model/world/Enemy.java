package powerwalk.model.world;

import powerwalk.model.OutOfReachException;

/**
 * This class represents aggressive or otherwise non-friendly Entities, whose main 
 * purpose is to be defeated
 * @author Chronio
 */
public class Enemy extends Entity {

    public static final int[] values = new int[] {};
    
    public Enemy(int x,int y,int z,int rawValue) {
        super(x,y,z,rawValue);
    }
    
    /**
     * Executes the default interact method on this Enemy.
     * <p>For most Enemies, interaction with an enemy of lower level this means attack the Enemy,
     * while for stronger Enemies, this may not be true.</p>
     * <p>When trying to specifically attack the Enemy, use the attack() method.</p>
     * @throws OutOfReachException when the target is not nearby
     */
    @Override public void interact() throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void attack() {
        
    }
    
    @Override public void interact(String method) throws OutOfReachException {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
