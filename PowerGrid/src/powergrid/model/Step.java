package powergrid.model;

import java.util.Objects;

/**
 * This class represents a single Step for the Player that contains the data 
 * required to follow a series of steps to a final destination.
 * @author Chronio
 */
public class Step {
    
    private Point position;
    private Object option;
    private boolean isInteraction;
    
    /**
     * Creates a new Step at the given position.
     * @param p the position of this Step
     */
    public Step(Point p) {
        assert p != null;
        position = p;
        isInteraction = false;
        option = null;
    }
    
    /**
     * Creates a new Step at the specified position that specifies an 
     * interaction with the specified option.
     * @param p the position of this Step
     * @param option the interaction option, which may be null
     */
    public Step(Point p, Object option) {
        assert p != null;
        position = p;
        isInteraction = true;
        this.option = option;
    }
    
    /**
     * @return the interaction option for this Step
     */
    public Object getOption() {
        return option;
    }
    
    /**
     * @return the position of this Step
     */
    public Point getPosition() {
        return position;
    }
    
    /**
     * @return whether this Step specifies an interaction
     */
    public boolean isInteraction() {
        return isInteraction;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 17 * hash + Objects.hashCode(this.position);
        hash = 17 * hash + Objects.hashCode(this.option);
        hash = 17 * hash + (this.isInteraction ? 1 : 0);
        return hash;
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof Step) {
            Step that = (Step) other;
            return getPosition().equals(that.getPosition())
                    && isInteraction() == that.isInteraction()
                    && Objects.equals(getOption(), that.getOption());
                    
        }
        return false;
    }
    
    @Override public String toString() {
        StringBuilder sb = new StringBuilder("Step: ");
        sb.append(getPosition());
        if (isInteraction()) {
            sb.append(", interaction ");
            Object o = getOption();
            if (o == null) {
                sb.append("with no option");
            } else {
                sb.append("with option: ").append(o);
            }
        }
        return sb.toString();
    }
}
