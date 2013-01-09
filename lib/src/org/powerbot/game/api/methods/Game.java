package org.powerbot.game.api.methods;

import java.awt.Canvas;
import java.awt.Dimension;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.util.internal.Constants;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.BaseInfo;
import org.powerbot.game.client.Client;

/**
 * A utility for the manipulation of the game.
 *
 * @author Timer
 */
public class Game {
	public static final int INDEX_LOGIN_SCREEN = 3;
	public static final int INDEX_LOBBY_SCREEN = 7;
	public static final int INDEX_LOGGING_IN = 9;
	public static final int INDEX_MAP_LOADED = 11;
	public static final int INDEX_MAP_LOADING = 12;
	public static final int[] INDEX_LOGGED_IN = {INDEX_MAP_LOADED, INDEX_MAP_LOADING};

	/**
	 * @return The current state of the game client.
	 */
	public static int getClientState() {
		final Client client = Context.client();
		final Constants constants = Context.constants();
		final int clientState = client.getLoginIndex();
		if (clientState == constants.CLIENTSTATE_3) {
			return 3;
		} else if (clientState == constants.CLIENTSTATE_7) {
			return 7;
		} else if (clientState == constants.CLIENTSTATE_9) {
			return 9;
		} else if (clientState == constants.CLIENTSTATE_11) {
			return 11;
		} else if (clientState == constants.CLIENTSTATE_12) {
			return 12;
		}
		return -1;
	}

	/**
	 * @return <tt>true</tt> if this client instance is logged in; otherwise <tt>false</tt>.
	 */
	public static boolean isLoggedIn() {
		final int state = getClientState();
		for (final int p_state : INDEX_LOGGED_IN) {
			if (state == p_state) {
				return true;
			}
		}
		return false;
	}

	/**
	 * @return The floor level, or plane, you are currently located on.
	 */
	public static int getPlane() {
		final Client client = Context.client();
		return client.getPlane();
	}

	/**
	 * @return The x location of the currently loaded map base.
	 */
	public static int getBaseX() {
		final Client client = Context.client();
		return client.getRSGroundInfo().getBaseInfo().getX();
	}

	/**
	 * @return The y location of the currently loaded map base.
	 */
	public static int getBaseY() {
		final Client client = Context.client();
		return client.getRSGroundInfo().getBaseInfo().getY();
	}

	public static Tile getMapBase() {
		final Client client = Context.client();
		final BaseInfo infoInts = client.getRSGroundInfo().getBaseInfo();
		return new Tile(
				infoInts.getX(),
				infoInts.getY(),
				Game.getPlane()
		);
	}

	public static int getLoopCycle() {
		final Client client = Context.client();
		return client.getLoopCycle();
	}

	public static Dimension getDimensions() {
		final Canvas canvas = Context.client().getCanvas();
		return new Dimension(canvas.getWidth(), canvas.getHeight());
	}

	/**
	 * @param lobby <tt>true</tt> if the method should log out to the lobby, <tt>false</tt> if the method should fully log out.
	 * @return <tt>true</tt> if and only if the client's state equals the state you want it to be in.
	 */
	public static boolean logout(final boolean lobby) {
		if (Game.getClientState() == Game.INDEX_LOBBY_SCREEN && lobby || Game.getClientState() == Game.INDEX_LOGIN_SCREEN && !lobby) {
			return true;
		}
		if (Tabs.LOGOUT.open()) {
			final WidgetChild w = Widgets.get(182, lobby ? 6 : 13);
			if (w != null && w.validate() && w.interact("Exit to " + (lobby ? "Lobby" : "Login"))) {
				for (int i = 0; i < 10; i++, Task.sleep(100, 200)) {
					if (Game.getClientState() == Game.INDEX_LOBBY_SCREEN && lobby || Game.getClientState() == Game.INDEX_LOGIN_SCREEN && !lobby) {
						return true;
					}
				}
			}
		}
		return false;
	}
}