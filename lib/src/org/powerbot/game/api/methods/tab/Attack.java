package org.powerbot.game.api.methods.tab;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Settings;
import org.powerbot.game.api.methods.Tabs;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

public class Attack {
	public static final int WIDGET = 884;
	public static final int WIDGET_BUTTON_AUTO_RETALIATE = 12;
	public static final int WIDGET_BUTTON_SPECIAL_ATTACK = 36;

	/**
	 * Gets the current fighting mode.
	 *
	 * @return the current fighting mode
	 */
	public static int getFightMode() {
		return Settings.get(Settings.SETTING_COMBAT_STYLE);
	}

	/**
	 * Gets the current special energy percent.
	 *
	 * @return the current special energy percent
	 */
	public static int getSpecialEnergy() {
		return Settings.get(Settings.SETTING_SPECIAL_ENERGY) / 10;
	}

	/**
	 * Gets the name of the equipped weapon.
	 *
	 * @return the name of the equipped weapon or an empty <code>String</code>
	 */
	public static String getWeaponName() {
		final WidgetChild c = Widgets.get(WIDGET, 0);
		return c != null ? c.getText() : "";
	}

	/**
	 * Checks whether auto-retaliate option is enabled.
	 *
	 * @return <tt>true</tt> if auto-retaliate option is enabled; otherwise <tt>false</tt>
	 */
	public static boolean isAutoRetaliateEnabled() {
		return Settings.get(Settings.SETTING_AUTO_RETALIATE) == 0;
	}

	/**
	 * Checks whether the special-attack is option is enabled.
	 *
	 * @return <tt>true</tt> if special-attack option is enabled; otherwise <tt>false</tt>
	 */
	public static boolean isSpecialEnabled() {
		return Settings.get(Settings.SETTING_SPECIAL_ATTACK) == 1;
	}

	/**
	 * Turns auto-retaliate on or off in the combat tab.
	 *
	 * @param enable <tt>true</tt> to enable; otherwise <tt>false</tt>
	 */
	public static void setAutoRetaliate(final boolean enable) {
		if (isAutoRetaliateEnabled() != enable) {
			Tabs.ATTACK.open();
			final WidgetChild c = Widgets.get(WIDGET, WIDGET_BUTTON_AUTO_RETALIATE);
			if (c != null) {
				c.click(true);
			}
		}
	}

	/**
	 * Sets the attack mode. The corresponding 4 attacking modes are in the range of 0 and 3.
	 *
	 * @param fightMode the fight mode to set it to
	 */
	public static boolean setFightMode(final int fightMode) {
		if (Tabs.ATTACK.isOpen() || Tabs.ATTACK.open(true)) {
			final WidgetChild styleButton = Widgets.get(WIDGET, fightMode + 7);
			if (styleButton.validate() && styleButton.click(true)) {
				for (byte b = 0; b < 20 && getFightMode() != fightMode; b++, Task.sleep(100)) {
				}
			}
		}
		return getFightMode() == fightMode;
	}

	/**
	 * Turns special attack on or off in the combat tab.
	 *
	 * @param enable <tt>true</tt> to enable; <tt>false</tt> to disable
	 */
	public static boolean setSpecial(final boolean enable) {
		if (isSpecialEnabled() != enable && (Tabs.ATTACK.isOpen() || Tabs.ATTACK.open())) {
			final WidgetChild w = Widgets.get(WIDGET, WIDGET_BUTTON_SPECIAL_ATTACK);
			if (w.isOnScreen() && w.interact("Toggle Special Attack")) {
				for (byte i = 0; i < 10 && isSpecialEnabled() != enable; i++, Task.sleep(100)) {
				}
			}
		}
		return isSpecialEnabled() == enable;
	}
}