package org.powerbot.game.api.methods.tab;

import org.powerbot.game.bot.Context;

/**
 * @author Timer
 */
public class Magic {
	public static boolean isSpellSelected() {
		return Context.client().isSpellSelected();
	}
}
