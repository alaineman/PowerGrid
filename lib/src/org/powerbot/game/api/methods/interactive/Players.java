package org.powerbot.game.api.methods.interactive;

import java.util.HashSet;
import java.util.Set;

import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSPlayer;

/**
 * A utility for the access of Players.
 *
 * @author Timer
 */
public class Players {
	public static final Filter<Player> ALL_FILTER = new Filter<Player>() {
		public boolean accept(final Player player) {
			return true;
		}
	};

	/**
	 * @return An array of the currently loaded Players in the game.
	 */
	public static Player[] getLoaded() {
		return getLoaded(ALL_FILTER);
	}

	/**
	 * @param filter The filtering <code>Filter</code> to accept all the Players through.
	 * @return An array of the currently loaded Players in the game that are accepted by the provided filter.
	 */
	public static Player[] getLoaded(final Filter<Player> filter) {
		final Client client = Context.client();
		final int[] indices = client.getRSPlayerIndexArray();
		final Object[] playerArray = client.getRSPlayerArray();
		final Set<Player> players = new HashSet<Player>();
		for (final int index : indices) {
			if (index != 0 && playerArray[index] != null) {
				final Player player = new Player((RSPlayer) playerArray[index]);
				if (filter.accept(player)) {
					players.add(player);
				}
			}
		}
		return players.toArray(new Player[players.size()]);
	}

	public static Player getNearest(final Filter<Player> filter) {
		final Client client = Context.client();
		final int[] indices = client.getRSPlayerIndexArray();
		final RSPlayer[] playerArray = client.getRSPlayerArray();
		Player player = null;
		double distance = Double.MAX_VALUE;
		final RegionOffset position = Players.getLocal().getRegionOffset();
		for (final int index : indices) {
			if (index != 0 && playerArray[index] != null) {
				final Player t_player = new Player(playerArray[index]);
				if (filter.accept(t_player)) {
					final double dist = Calculations.distance(position, t_player.getRegionOffset());
					if (dist < distance) {
						distance = dist;
						player = t_player;
					}
				}
			}
		}
		return player;
	}

	/**
	 * @return The client's local <code>Player</code>.
	 */
	public static Player getLocal() {
		return new Player(Context.client().getMyRSPlayer());
	}
}
