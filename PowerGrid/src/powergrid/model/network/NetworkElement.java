package powergrid.model.network;

/**
 * Interface for classes that are elements of a TransportNetwork.
 * @author Chronio
 */
public interface NetworkElement {
    
    /**
     * Links the specified TransportNetwork to this NetworkElement.
     * <p/>
     * Note that this alone does not add the NetworkElement to the provided 
     * network.
     * @param network the network this NetworkElement belongs to.
     * @return itself for fluency 
     */
    public NetworkElement withNetwork(TransportNetwork network);
    
    /**
     * @return the TransportNetwork this NetworkElement belongs to.
     */
    public TransportNetwork getNetwork();
}
