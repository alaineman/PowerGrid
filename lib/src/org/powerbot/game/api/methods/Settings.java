package org.powerbot.game.api.methods;

import org.powerbot.game.bot.Context;

/**
 * A utility for the manipulation of game settings.
 *
 * @author Timer
 */
public class Settings {
	public static final int SETTING_COMBAT_STYLE = 43;
	public static final int SETTING_AUTO_RETALIATE = 172;
	public static final int SETTING_RUN_ENABLED = 463;
	public static final int SETTING_SPECIAL_ENERGY = 300;
	public static final int SETTING_SPECIAL_ATTACK = 301;
	public static final int SETTING_RANDOMEVENT_DRILLDEMON_MAT = 531;

	/**
	 * @return The <code>int[]</code> of all the game's settings in their respective positioning.
	 */
	public static int[] get() {
		return Context.client().getPlayerMetaInfo().getSettings().getData().clone();
	}

	/**
	 * @param index The position of this setting in the game's database.
	 * @return The setting value of the desired index.
	 */
	public static int get(final int index) {
		final int[] settings = get();
		if (index < settings.length) {
			return settings[index];
		}
		return -1;
	}

	/**
	 * Gets the value at a given index and applies a given mask to the value
	 *
	 * @param index the index in the settings array
	 * @param mask  the bitmask
	 * @return the masked value
	 */
	public static int get(final int index, final int mask) {
		return get(index, 0, mask);
	}

	/**
	 * Gets the value at a given index, bit shifts it right by a given number of bits and applies a mask
	 *
	 * @param index the index in the settings array
	 * @param shift the number of bits to right shift
	 * @param mask  the bitmask
	 * @return the masked value
	 */
	public static int get(final int index, final int shift, final int mask) {
		return (get(index) >>> shift) & mask;
	}
}
