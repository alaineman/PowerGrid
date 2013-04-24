package powergrid.model.world.transportation;

import org.powerbot.game.client.RSNPC;
import powergrid.model.network.TransportNetwork;
import powergrid.model.network.TreeNetwork;

/**
 * This class represents NPC's that provide access to Gnome Gliders as a 
 * Transportation system.
 * <p/>
 * 
 * @author Alaineman
 * @author Chronio
 */
public class GnomePilot extends TransportGuide {
    
    private String positionName;

    public GnomePilot(RSNPC rsnpc) {
        super(rsnpc);
    }
    
    @Override 
    public TreeNetwork getNetwork(){
        return (TreeNetwork) super.getNetwork();
    }
    
    @Override
    public GnomePilot withNetwork(TransportNetwork nw) {
        if(nw instanceof TreeNetwork){
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