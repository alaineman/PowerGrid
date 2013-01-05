package powerwalk.control;

import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

/**
 * This class handles interaction with the Noticeboard, such as opening and 
 * closing the Noticeboard and opening a specific Tab.
 * <p/>
 * @author Alaineman
 */
public abstract class Noticeboard {

    /** Tab object that represents the "Featured" Tab on the Noticeboard */
    public static final Tab FEATURED = new Tab(1345, "Featured");
    /** Tab object that represents the "Challenges" Tab on the Noticeboard */
    public static final Tab CHALLENGES = new Tab(1343, "Challenges");
    /** Tab object that represents the "Quests" Tab on the Noticeboard */
    public static final Tab QUESTS = new Tab(190, "Quests");
    /** Tab object that represents the "Achievements" Tab on the Noticeboard */
    public static final Tab ACHIEVEMENTS = new Tab(917, "Achievements");
    /** Tab object that represents the "Minigames" Tab on the Noticeboard */
    public static final Tab MINIGAMES = new Tab(1344, "Minigames");
    
    /**
     * Contains all values of the five tabpanels from the Noticeboard. Each of
     * the values is described below;
     * <p/>
     * <ul> 
     * <li> Index 0, Value 190, Description: Quest tab. </li> 
     * <li> Index 1, Value 917, Description: Achievements tab. </li> 
     * <li> Index 2, Value 1343, Description: Challenges tab. </li> 
     * <li> Index 3, Value 1344, Description: Minigames tab. </li> 
     * <li> Index 4, Value 1345, Description: Featured tab. </li> 
     * </ul>
     */
    public static final Tab[] noticeboardTabs = {FEATURED, CHALLENGES, QUESTS, ACHIEVEMENTS, MINIGAMES};

    /**
     * Opens the given Tab of the Noticeboard. 
     * <p/>
     * This method may require somewhere between 2 and 5 seconds to complete.
     * If the required Tab was not opened during this time, this method returns false.
     * <p/>
     * @param tab the Tab to open
     * @return true if the Tab was opened, false otherwise
     */
    public static boolean openTab(Tab tab) {
        if (tab == null) {
            return false;
        }
        Tab current = getCurrentTab();
        WidgetChild[] search = Widgets.get(current.widgetNum).getChildren();
        for (WidgetChild child : search) {
            if (child.getText() != null && child.getText().equals(tab.name)) {
                child.click(true);
                return true;
            }
        }
        return false;
    }

    /**
     * returns the currently opened Tab. This Tab can be compared using the following pattern:
     * <p/>
     * <code><pre>
     *     if (Noticeboard.getCurrentTab() != Noticeboard.QUESTS) {
     *         Noticeboard.openTab(Noticeboard.QUESTS);
     *     }
     *     // do something on the Quests Tab
     * </pre></code>
     * <p/>
     * @return the currently opened Tab
     */
    public static Tab getCurrentTab() {
        for (Tab i : noticeboardTabs) {
            if (Widgets.get(i.widgetNum).validate()) {
                return i;
            }
        }
        return null;
    }

    /**
     * Ensures that the Noticeboard is visible.
     * <p/>
     * This is a convenience method for WigetManager.openNoticeboard().
     */
    public static void open() {
        WidgetManager.openNoticeBoard();
    }
    
    /**
     * This class represents a Tab of the Noticeboard.
     */
    public static class Tab {

        private int widgetNum;
        private String name;

        private Tab(int num, String name) {
            widgetNum = num;
            this.name = name;
        }
    }
}
