package powergrid.model.world.transportation;

import org.powerbot.game.client.RSGround;
import powergrid.model.Point;
import powergrid.model.TransportTile;
import powergrid.model.network.GraphNetwork;
import powergrid.model.network.TransportNetwork;

/**
 * This class represents NPC's that provide access to Magic carpets as a 
 * Transportation system.
 * <p/>
 * 
 * @author Alaineman
 * @author Chronio
 */
public class CarpetMerchant extends TransportTile {
    
    private String name;
    
    public CarpetMerchant(Point pos, RSGround ground, int colFlag) {
        super(pos, ground, colFlag);
    }
    
    @Override 
    public GraphNetwork getNetwork(){
        return (GraphNetwork) super.getNetwork();
    }
    
    @Override
    public CarpetMerchant withNetwork(TransportNetwork nw) {
        if(nw instanceof GraphNetwork){
        super.withNetwork(nw);
        return this;
        } else { 
            return null;
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    
}
