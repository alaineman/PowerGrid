package powerwalk.control.noticeboard;

import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.Set;
import javax.net.ssl.SSLContext;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.tab.Quest;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powerwalk.Starter;
import powerwalk.control.WidgetManager;

/**
 * This class deals with checking the status of Quests and as such can be used 
 * to check requirements for various tasks.
 * <p />
 * Quest names are case-insensitive, and can be given with either underscores 
 * or spaces. Any special characters like apostrophes and such cannot be omitted
 * <p />
 * 
 * @author Alaineman
 * @author Chronio
 */
public abstract class Quests {
    public static final int UNAVAILABLE = 3;
    
    /** Status for a Quest that indicates that the Player has not yet started 
     *  the Quest. 
     */
    public static final int NOT_STARTED = 0;
    /** Status for a Quest that indicates that the Player has started, but not yet
     *  yet completed the Quest.
     */
    public static final int STARTED     = 1;
    /** Status for a Quest that indicates that the Player has completed the Quest. 
     */
    public static final int COMPLETED   = 2;
    
    /**
     * contains the String values for the statuses. The String-value of a status 
     * is equal to <code>status[status]</code>. For example, status[COMPLETED] 
     * contains the String "Completed".
     */
    public static final String[] status = new String[] {
        "Not Started", "Started", "Completed", "Unavailable"
    };
    
    private static HashMap<String,Integer> questStats = new HashMap<>();
    
    /**
     * Returns the Status of the Quest with the given name.
     * <p/>
     * This method returns either Quests.NOT_STARTED, Quests.STARTED, or
     * Quests.COMPLETED, depending on the status of the Quest.
     * <p/>
     * When no Quest with the given name is found, this method throws a
     * NoSuchElementException.
     * <p/>
     * @param quest the name of the quest
     * @return the status of the quest
     * @throws NoSuchElementException when no such quest is found
     */
    public static int getStatus(String quest) {
        quest = formatString(quest);
        if (questStats.containsKey(quest)) {
            return questStats.get(quest);
        } else {
            
            throw new NoSuchElementException("This Quest is not registered");
        }
    }
    
    /**
     * Returns true if the player has completed the given Quest.
     * <p/>
     * When no Quest with the given name is found, this method throws a
     * NoSuchElementException.
     * <p/>
     * @param quest the name of the quest
     * @return true if the player has completed the given quest, false otherwise.
     * @throws NoSuchElementException when no such quest is found
     */
    public static boolean isCompleted(String quest) {
        return getStatus(quest) == COMPLETED;
    }
    
    /**
     * Returns true if the player has started, but no completed the given Quest.
     * <p/>
     * When no Quest with the given name is found, this method throws a
     * NoSuchElementException.
     * <p/>
     * @param quest the name of the quest
     * @return true if the player has started the given quest but has yet to 
     *         complete it, false otherwise.
     * @throws NoSuchElementException when no such quest is found
     */
    public static boolean isStarted(String quest) {
        return getStatus(quest) == STARTED;
    }
    
    /**
     * Returns true if the player has not yet started the given Quest.
     * <p/>
     * When no Quest with the given name is found, this method throws a
     * NoSuchElementException.
     * <p/>
     * @param quest the name of the quest
     * @return true if the player has not yet started the given quest, false otherwise.
     * @throws NoSuchElementException when no such quest is found
     */
    public static boolean isUnstarted(String quest) {
        return getStatus(quest) == NOT_STARTED;
    }
    
    /**
     * Reloads the Quest information from the environment. When the PowerWalk 
     * plug-in is loaded, the Quest data was loaded when PowerWalk started. 
     * Otherwise, this method needs to be called before any information on Quests 
     * can be collected.
     * <p />
     * This method must be manually called to reflect changes to the status of 
     * Quests after PowerWalk is loaded. A feasible way to do this is to assign 
     * a Task to the Bot class with the lowest priority. The Bot will then update 
     * the caches automatically when there is nothing else to do.
     * <p />
     * Note that this method involves opening and closing the Noticeboard, and 
     * may therefore take around 3-4 seconds to complete.
     * <p />
     */
    public static void updateQuestData() {
        // Open the Quests tab
        WidgetManager.openQuestTab();
        // check all Quest entries for their color.
        WidgetChild[] children = Widgets.get(190,40).getChildren();
        for (WidgetChild child : children) {
            String text = child.getText();
            if (child.visible() && text != null && !text.isEmpty()) {
                if (text.equals("Free") || text.equals("Members") || text.equals("Seasonal quest"))
                    continue;
                int s = NOT_STARTED;
                int color = child.getTextColor(); // decide whether a Quest is done by looking at color in noticeboard
                if (color == 65280) {
                    s = COMPLETED;
                    Starter.logMessage("Completed Quest: " + text,"Quests");
                } // color = green, completed
                if (color == 65535) {
                    s = STARTED;
                    Starter.logMessage("Started Quest:   " + text,"Quests");
                }   // color = blue,  started
                questStats.put(formatString(text), s);
            }
        }
        // close the noticeboard
        WidgetManager.clearScreen();
        
        Starter.logMessage("The Quest information has been updated","Quests");
    }
    
    /**
     * Formats the input String, so that it closely matches the required format.
     * <p/>
     * @param s the input String
     * @return the formatted String
     */
    private static String formatString(String s) {
        return s.replace(' ', '_').replace('\'', '_').toUpperCase();
    }
    
    /**
     * returns a Set containing all loaded names for Quests.
     * @return a Set containing all Quest names.
     */
    public static Set<String> getAllQuests() {
        return questStats.keySet();
    }
}
