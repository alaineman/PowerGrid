package powerwalk.control.uicontrols;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Tabs;
import org.powerbot.game.api.methods.Widgets;
import powerwalk.PowerGrid;
import powerwalk.model.interact.Lodestone;

/**
 * Manages opening of Widgets in order to access the various possibilities that
 * the RSBot environment provides.
 *
 * @author Alaineman
 * @author Chronio
 */
public class WidgetManager {

    private WidgetManager() {}
    
    /**
     * Contains all values of widgets that represent lodestone locations, sorted ascending.
     */
    public final static int[] lodestoneValues = {7, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
    
    /**
     * Ensures that the SpellBook panel is visible.
     */
    public static void openSpellBook() {
        if (!Tabs.ABILITY_BOOK.isOpen()){
            Tabs.ABILITY_BOOK.open();
            Task.sleep(400,600);
        }        
    }

    /**
     * Ensures the Noticeboard Tab is visible.
     */
    public static void openNoticeboardTab() {
        if (!Tabs.NOTICEBOARD.isOpen()){
            Tabs.NOTICEBOARD.open(); 
            Task.sleep(200,300);
        }      
    }
    
    /**
     * Ensures the NoticeBoard panel is opened.
     */
    public static void openNoticeBoard() {
        openNoticeboardTab();
        if (!Widgets.get(1345,192).visible()) {
            Widgets.get(1056, 9).click(true);
            Task.sleep(1200,1400);
        }
    }

    /**
     * Ensures the Quest tab is visible.
     */
    public static void openQuestTab() {
        openNoticeBoard();
        if (!Widgets.get(190, 40).visible()) {
            Widgets.get(1345, 192).click(true);
            Task.sleep(1200,1400);
        }
    }

    /**
     * Ensures that the Magic Abilities panel is visible.
     */
    public static void openMagicAbilities() {
        openSpellBook();
        if (!Widgets.get(275, 38).visible()) {
            Widgets.get(275, 41).click(true);
            Task.sleep(400,700);
        }
    }

    /**
     * Ensures that the Teleport Spells panel is visible.
     */
    public static void openTeleportSpells() {
        openMagicAbilities();
        if (!Widgets.get(275, 18).getChild(155).visible()) {
            Widgets.get(275, 38).click(true);
        }
        Task.sleep(300,500);
    }

    /**
     * Ensures that the Lodestone panel is visible.
     */
    public static void openLodestoneWidget() {
        openTeleportSpells();
        if (!Widgets.get(1092).validate()) {
            if (!Widgets.get(275, 18).getChild(155).click(true))
                PowerGrid.logMessage("Opening Lodestone Widget failed");
        }
        Task.sleep(1100,1200);
        if (!Widgets.get(1092).validate()) {
            Task.sleep(1200);
        }
        updateLodestones();
    }

    // helper method that automatically updates the available Lodestones when the
    // Lodestone widget is opened
    private static void updateLodestones() {
        for (int i : lodestoneValues) {
            if (Widgets.get(1092, i).getTextureId() < 10117) {
                Lodestone.addLodestone(i);
            }
        }
    }
    
}
