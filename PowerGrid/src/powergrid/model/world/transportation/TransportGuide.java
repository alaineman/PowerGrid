package powergrid.model.world.transportation;

import org.powerbot.game.client.RSNPC;
import powergrid.model.network.NetworkElement;
import powergrid.model.network.TransportNetwork;
import powergrid.model.world.Mobile;

/**
 * This class represents any Mobile that can be interacted with in order to use
 * a certain transportation network.
 * <p/>
 * @author Chronio
 */
public class TransportGuide extends Mobile implements NetworkElement {

    private TransportNetwork network;
    
    /**
     * Creates a new TransportGuide with the specified RSNPC object
     * @param rsnpc the RSNPC object
     */
    public TransportGuide(RSNPC rsnpc) {
        super(rsnpc);
    }
    
    @Override
    public TransportGuide withNetwork(TransportNetwork network) {
        assert network != null;
        this.network = network;
        return this;
    }
    
    @Override
    public TransportNetwork getNetwork() {
        return network;
    }
}
