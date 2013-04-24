package powergrid.model;

import java.util.Objects;

/**
 * This class represents a single Step for the Player that contains the data 
 * required to follow a series of steps to a final destination.
 * @author Chronio
 */
public class Step {
    
    private Point position;
    private Object interaction;
    private Object option;
    
    /**
     * Creates a new Step at the given position.
     * @param p the position of this Step
     */
    public Step(Point p) {
        assert p != null;
        position = p;
        interaction = null;
        option = null;
    }
    
    /**
     * Creates a new Step at the specified position that specifies an 
     * interaction with the specified option.
     * <p/>
     * <code>object</code> may be null, but only if <code>option</code> is 
     * also null.
     * @param p the position of this Step
     * @param object the object to interact with.
     * @param option the interaction option, which may be null
     */
    public Step(Point p, Object object, Object option) {
        assert p != null && (object != null || option == null);
        position = p;
        interaction = object;
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
    public Object getInteraction() {
        return interaction;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 17 * hash + Objects.hashCode(this.position);
        hash = 17 * hash + Objects.hashCode(this.option);
        hash = 17 * hash + Objects.hashCode(this.interaction);
        return hash;
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof Step) {
            Step that = (Step) other;
            return getPosition().equals(that.getPosition())
                    && Objects.equals(getInteraction(), that.getInteraction())
                    && Objects.equals(getOption(), that.getOption());
                    
        }
        return false;
    }
    
    @Override public String toString() {
        StringBuilder sb = new StringBuilder("Step: ");
        sb.append(getPosition());
        Object i = getInteraction();
        if (i != null) {
            sb.append(", interaction with <").append(i);
            Object o = getOption();
            if (o == null) {
                sb.append("> with no option");
            } else {
                sb.append("> with option: <").append(o).append(">");
            }
        }
        return sb.toString();
    }
}
