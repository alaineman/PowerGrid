package powergrid.control.listener;

/**
 *
 * @author Alaineman
 */
public interface SkillListener {
    
    public void levelUp(String skillName, int newLevel);
    
    public void experienceGained(String skillName, double exp);
        
}
