package powergrid.model.network;

import java.util.Objects;

/**
 * 
 * @param <T> the element type of this Edge.
 * @author Chronio
 */
public class Edge<T> {
    
    private T to;
    private int weight;
    
    public Edge(T to, int weight) {
        assert to != null && weight >= 0;
        this.to = to;
        this.weight = weight;
    }

    public T getTo() {
        return to;
    }

    public int getWeight() {
        return weight;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Edge) {
            Edge that = (Edge) obj;
            return this.getWeight() == that.getWeight()
                    && Objects.equals(this.getTo(), that.getTo());
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + Objects.hashCode(this.to);
        hash = 31 * hash + this.weight;
        return hash;
    }
    
}
