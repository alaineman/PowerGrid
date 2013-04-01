package powergrid.model.world.transportation;

import org.powerbot.game.client.RSNPC;
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
public class CarpetMerchant extends TransportGuide {
    
    private String positionName;

    public CarpetMerchant(RSNPC rsnpc) {
        super(rsnpc);
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

    public String getPositionName() {
        return positionName;
    }

    public void setPositionName(String name) {
        this.positionName = name;
    }
}
