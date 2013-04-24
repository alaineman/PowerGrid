package powergrid.model.world.transportation;

import org.powerbot.game.client.RSNPC;
import powergrid.model.network.PeerNetwork;
import powergrid.model.network.TransportNetwork;

/**
 * This class represents NPC's that provide access to Charter Ships as a 
 * Transportation system.
 * <p/>
 * 
 * @author Alaineman
 * @author Chronio
 */
public class CharterCrew extends TransportGuide {
    
    private String positionName;

    public CharterCrew(RSNPC rsnpc) {
        super(rsnpc);
    }
    
    @Override 
    public PeerNetwork getNetwork(){
        return (PeerNetwork) super.getNetwork();
    }
    
    @Override
    public CharterCrew withNetwork(TransportNetwork nw) {
        if(nw instanceof PeerNetwork){
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