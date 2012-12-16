package powerwalk.control;

import org.powerbot.game.api.methods.Widgets;
import powerwalk.model.interact.Lodestone;

/**
 * Manages opening of Widgets in order to access the various possibilities that 
 * the RSBot environment provides.
 * @author Alaineman
 * @author P.Kramer
 */
public abstract class WidgetManager {
    
    /** Contains all values of widgets that represent lodestone locations */
    public final static int[] lodestoneValues = {7, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};

    /**
     * Ensures that the Spellbook panel is visible
     */
    public static void openSpellBook() {
        if (!Widgets.get(275, 18).visible()) {
            Widgets.get(548, 123).click(true);
        }
    }

    /**
     * Ensures that the Magic Abilities panel is visible
     */
    public static void openMagicAbilities() {
        openSpellBook();
        try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
        }
        if (!Widgets.get(275, 38).visible()) {
            Widgets.get(275, 41).click(true);
        }
    }

    /**
     * Ensures that the Teleport Spells panel is visible
     */
    public static void openTeleportSpells() {
        openMagicAbilities();
        try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
        }
        if (!Widgets.get(275, 18).getChild(155).visible()) {
            Widgets.get(275, 38).click(true);
        }
    }

    /**
     * Ensures that the Lodestone panel is visible
     */
    public static void openLodestoneWidget() {
        openTeleportSpells();
        try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
        }
        if (!Widgets.get(1092).validate()) {
            Widgets.get(275, 18).getChild(155).click(true);
        }
        try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
        }
        updateLodestones();
    }    
    
    private static void updateLodestones() {
        for(int i : lodestoneValues){
             if (Widgets.get(1092, i).getTextureId() < 10117) {
                 Lodestone.addLodestone(i);
             }
        }        
    }
}
