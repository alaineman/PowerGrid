package powerwalk.control;

import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powerwalk.Starter;
import powerwalk.model.interact.Lodestone;

/**
 * Manages opening of Widgets in order to access the various possibilities that
 * the RSBot environment provides.
 *
 * @author Alaineman
 * @author Chronio
 */
public abstract class WidgetManager {

    /**
     * Contains all values of widgets that represent lodestone locations.
     */
    public final static int[] lodestoneValues = {7, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
    
    /**
     * Ensures that the SpellBook panel is visible
     */
    public static void openSpellBook() {
        if (!Widgets.get(275, 18).visible()) {
            Widgets.get(548, 123).click(true);
            try { Thread.sleep(500); } catch (Exception e) {}
        }
    }

    /**
     * Ensures the Noticeboard Tab is visible.
     */
    public static void openNoticeboardTab() {
        if (Widgets.get(548, 136).getTextureId() != 1840) { // texture of selected box
            Widgets.get(548, 108).click(true);
            try { Thread.sleep(150); } catch (Exception e) {}
        }
    }
    
    /**
     * Ensures the NoticeBoard panel is opened.
     */
    public static void openNoticeBoard() {
        openNoticeboardTab();
        if (!Widgets.get(1345,192).visible()) {
            Widgets.get(1056, 9).click(true);
            try { Thread.sleep(1200); } catch (Exception e) {}
        }
    }

    /**
     * Ensures the Quest tab is visible.
     */
    public static void openQuestTab() {
        openNoticeBoard();
        if (!Widgets.get(190, 40).visible()) {
            Widgets.get(1345, 192).click(true);
            try { Thread.sleep(1200); } catch (Exception e) {}
        }
    }

    /**
     * Ensures that the Magic Abilities panel is visible.
     */
    public static void openMagicAbilities() {
        openSpellBook();
        if (!Widgets.get(275, 38).visible()) {
            Widgets.get(275, 41).click(true);
            try { Thread.sleep(500); } catch (Exception e) {}
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
    }

    /**
     * Ensures that the Lodestone panel is visible.
     */
    public static void openLodestoneWidget() {
        openTeleportSpells();
        if (!Widgets.get(1092).validate()) {
            Widgets.get(275, 18).getChild(155).click(true);
        }
        try { Thread.sleep(500); } catch (Exception e) {}
        updateLodestones();
    }

    private static void updateLodestones() {
        for (int i : lodestoneValues) {
            if (Widgets.get(1092, i).getTextureId() < 10117) {
                Lodestone.addLodestone(i);
            }
        }
    }
    
    /**
     * Closes any open widgets that were opened by the WidgetManager.
     */
    public static void clearScreen() {
        // NoticeBoard
        WidgetChild closeBtn = Widgets.get(1345, 33);
        closeBtn.click(true);
        try { Thread.sleep(1200); } catch(Exception e) {}
    }
}
