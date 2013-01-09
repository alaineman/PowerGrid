package org.powerbot.game.api.util.internal;

import java.util.Map;

/**
 * Represents constants of states or possibilities.
 *
 * @author Timer
 */
public class Constants {
	public final int
			MINIMAP_SETTINGS_ON,
			CLIENTSTATE_3, CLIENTSTATE_7,
			CLIENTSTATE_9, CLIENTSTATE_11,
			CLIENTSTATE_12,
			VIEWPORT_XOFF, VIEWPORT_XX, VIEWPORT_XY, VIEWPORT_XZ,
			VIEWPORT_YOFF, VIEWPORT_YX, VIEWPORT_YY, VIEWPORT_YZ,
			VIEWPORT_ZOFF, VIEWPORT_ZX, VIEWPORT_ZY, VIEWPORT_ZZ;

	public Constants(final Map<Integer, Integer> constants) {
		MINIMAP_SETTINGS_ON = constants.get(0);
		CLIENTSTATE_3 = constants.get(1);
		CLIENTSTATE_7 = constants.get(2);
		CLIENTSTATE_9 = constants.get(3);
		CLIENTSTATE_11 = constants.get(4);
		CLIENTSTATE_12 = constants.get(5);

		VIEWPORT_XOFF = constants.get(6);
		VIEWPORT_XX = constants.get(7);
		VIEWPORT_XY = constants.get(8);
		VIEWPORT_XZ = constants.get(9);
		VIEWPORT_YOFF = constants.get(10);
		VIEWPORT_YX = constants.get(11);
		VIEWPORT_YY = constants.get(12);
		VIEWPORT_YZ = constants.get(13);
		VIEWPORT_ZOFF = constants.get(14);
		VIEWPORT_ZX = constants.get(15);
		VIEWPORT_ZY = constants.get(16);
		VIEWPORT_ZZ = constants.get(17);
	}
}
