/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.world.resources;

import powerwalk.model.Item;

/**
 *
 * @author Vincent W
 */
public class Fishspot extends AbstractResource {
    
    public Fishspot(int x, int y, int rawValue, Item... it) {
        super(x, y, rawValue, it);
    }

    @Override
    public void gather() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean isAvailable() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public boolean meetsRequirements() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
