package powerwalk.control;

import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

/**
 *
 * @author Alaineman
 */
public abstract class Noticeboard {

    public static final Tab FEATURED = new Tab(1345, "Featured");
    public static final Tab CHALLANGES = new Tab(1343, "Challanges");
    public static final Tab QUESTS = new Tab(190, "Quests");
    public static final Tab ACHIEVEMENTS = new Tab(917, "Achievements");
    public static final Tab MINIGAMES = new Tab(1344, "Minigames");
    /**
     * Contains all values of the five tabpanels from the Noticeboard. Each of
     * the values is described below;
     *
     * <ul> <li> Index 0, Value 190, Description: Quest tab. </li> <li> Index 1,
     * Value 917, Description: Achievements tab. </li> <li> Index 2, Value 1343,
     * Description: Challanges tab. </li> <li> Index 3, Value 1344, Description:
     * Minigames tab. </li> <li> Index 4, Value 1345, Description: Featured tab.
     * </li> </ul>
     */
    public static final Tab[] noticeboardTabs = {FEATURED, CHALLANGES, QUESTS, ACHIEVEMENTS, MINIGAMES};

    /**
     *
     * @param tab
     * @return
     */
    public static boolean openTab(Tab tab) {
        if (tab == null) {
            return false;
        }
        Tab current = getCurrentTab();
        int tries = 5;
        while(current == null && tries > 0) {
            open();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
            }
            current = getCurrentTab();
            tries--;
        }
        WidgetChild[] search = Widgets.get(current.widgetNum).getChildren();
        for (WidgetChild child : search) {
            if (child.getText() != null && child.getText().contains(tab.name)) {
                child.click(true);
                return true;
            }
        }
        return false;
    }

    /**
     *
     * @return
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
     */
    public static void open() {
        WidgetManager.openNoticeboardTab();
        try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
        }
        for (Tab i : Noticeboard.noticeboardTabs) {
            if (Widgets.get(i.widgetNum).validate()) {
                return;
            }
        }
        Widgets.get(1056, 60).click(true);
    }

    public static class Tab {

        private int widgetNum;
        private String name;

        private Tab(int num, String name) {
            widgetNum = num;
            this.name = name;
        }
    }
}
