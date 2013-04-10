package powergrid.model.world.player;

/**
 * Represents a Skill in Runescape
 * @author Alaineman
 */
public class Skill {
    
    private String name;
    private double experience;
    
    /**
     * Creates a new Skill by the specified name
     * <p>
     * Note: name is required and must have at least one character
     * @param name the specified name
     */
    public Skill(String name){
        assert name != null && !name.isEmpty();
        this.name = name;
        this.experience = 0;
    }
    
    /**
     * @return the current level of this skill
     */
    public int getLevel() {
        return getLevelForExp(experience);
    }
    
    /**
     * Adds the experience to the skill and checks if you leveled
     * <p>
     * Note: the amount of experience must be positive
     * @param exp the experience added
     * @return true if you leveled, false otherwise
     */
    public boolean gain(double exp){
        assert exp > 0;
        int l = getLevel();
        experience += exp;
        return getLevel() != l;
    }
    
    /**
     * @return the next level to this Skill
     */
    public int getNextLevel(){
        return getLevel()+1;
    }
    
    /**
     * @return the experience gained in this Skill
     */
    public double getExperience(){
        return experience;
    }
    
    /**
     * @return the amount of experience to the next level
     */
    public double getExpToNextLevel() {
        return getExpForLevel(getLevelForExp(getExperience())+1) - getExperience();
    }
    
    /**
     * Calculates the level you would be on with 
     * the specified amount of experience
     * @param exp the specified amount of experience
     * @return the Skill level
     */
    public static int getLevelForExp(double exp){
        return (int)(7d * Math.log((Math.pow(2, 1/7d) -1)/75 * exp + 1)/Math.log(2));
    }
    
    /**
     * Calculates the amount of experience needed for the specified level
     * <p>
     * Note: the Skill level should be level one or higher
     * @param level the specified level
     * @return the amount of experience needed
     */
    public static int getExpForLevel(int level){
        assert level > 0;
        int result = 0;
        for(int i = 1; i < level; i++){
            result += (int) (i + 300 * Math.pow(2, i/7d));
        }
        return result;
    }
}
