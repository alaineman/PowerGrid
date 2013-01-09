package org.powerbot.game.api.methods.node;

import java.util.ArrayList;
import java.util.List;

import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.node.Deque;
import org.powerbot.game.api.util.node.Nodes;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.node.GroundItem;
import org.powerbot.game.api.wrappers.node.Item;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.HashTable;
import org.powerbot.game.client.NodeDeque;
import org.powerbot.game.client.NodeListCache;
import org.powerbot.game.client.RSItem;

public class GroundItems {
	public static final Filter<GroundItem> ALL_FILTER = new Filter<GroundItem>() {
		public boolean accept(final GroundItem item) {
			return true;
		}
	};

	/**
	 * Returns all ground items in the loaded area.
	 *
	 * @return All ground items in the loaded area.
	 */
	public static GroundItem[] getLoaded() {
		return getLoaded(104, ALL_FILTER);
	}


	public static GroundItem[] getLoaded(final int id) {
		return getLoaded(new Filter<GroundItem>() {
			public boolean accept(final GroundItem groundItem) {
				return groundItem.getGroundItem().getId() == id;
			}
		});
	}

	public static GroundItem[] getLoaded(final Filter<GroundItem> filter) {
		return getLoaded(104, filter);
	}

	public static GroundItem[] getLoaded(final int range, final int id) {
		return getLoaded(range, new Filter<GroundItem>() {
			public boolean accept(final GroundItem groundItem) {
				return groundItem.getGroundItem().getId() == id;
			}
		});
	}

	/**
	 * Returns all matching ground items within the provided range.
	 *
	 * @param range  The range (max distance in all directions) in which to check items for.
	 * @param filter Filters out unwanted matches.
	 * @return <tt>GroundItem</tt> array containing all of the items in range.
	 */
	public static GroundItem[] getLoaded(final int range, final Filter<GroundItem> filter) {
		final ArrayList<GroundItem> temp = new ArrayList<GroundItem>();
		final Tile tile = Players.getLocal().getLocation();
		final int pX = tile.getX();
		final int pY = tile.getY();
		final int baseX = Game.getBaseX();
		final int baseY = Game.getBaseY();
		final int minX = Math.max(baseX, pX - range), minY = Math.max(baseY, pY - range);
		final int maxX = Math.min(baseX + 104, pX + range), maxY = Math.min(baseY + 104, pY + range);
		for (int x = minX; x < maxX; x++) {
			for (int y = minY; y < maxY; y++) {
				final GroundItem[] items = getLoadedAt(x, y);
				for (final GroundItem item : items) {
					if (item != null && filter.accept(item)) {
						temp.add(item);
					}
				}
			}
		}
		return temp.toArray(new GroundItem[temp.size()]);
	}

	public static GroundItem getNearest(final int... ids) {
		return getNearest(new Filter<GroundItem>() {
			public boolean accept(final GroundItem groundItem) {
				final int itemID = groundItem.getId();
				for (final int id : ids) {
					if (itemID == id) {
						return true;
					}
				}
				return false;
			}
		});
	}

	public static GroundItem getNearest(final Filter<GroundItem> filter) {
		return getNearest(104, filter);
	}

	public static GroundItem getNearest(final int range, final int id) {
		return getNearest(range, new Filter<GroundItem>() {
			public boolean accept(final GroundItem groundItem) {
				return groundItem.getGroundItem().getId() == id;
			}
		});
	}

	public static GroundItem getNearest(final int range, final Filter<GroundItem> filter) {
		GroundItem groundItem = null;
		double distance = Double.MAX_VALUE;
		final RegionOffset position = Players.getLocal().getRegionOffset();
		final Tile tile = Players.getLocal().getLocation();
		final int pX = tile.getX();
		final int pY = tile.getY();
		final int baseX = Game.getBaseX();
		final int baseY = Game.getBaseY();
		final int minX = Math.max(baseX, pX - range), minY = Math.max(baseY, pY - range);
		final int maxX = Math.min(baseX + 104, pX + range), maxY = Math.min(baseY + 104, pY + range);
		for (int x = minX; x < maxX; x++) {
			for (int y = minY; y < maxY; y++) {
				final GroundItem[] items = getLoadedAt(x, y);
				for (final GroundItem item : items) {
					if (item != null && filter.accept(item)) {
						final double dist = Calculations.distance(position, item.getRegionOffset());
						if (dist < distance) {
							distance = dist;
							groundItem = item;
						}
					}
				}
			}
		}
		return groundItem;
	}

	/**
	 * Returns all the ground items at a tile on the current plane.
	 *
	 * @param x The x position of the tile in the world.
	 * @param y The y position of the tile in the world.
	 * @return An array of the ground items on the specified tile.
	 */
	public static GroundItem[] getLoadedAt(final int x, final int y) {
		if (!Game.isLoggedIn()) {
			return new GroundItem[0];
		}
		final List<GroundItem> groundItems = new ArrayList<GroundItem>();
		final Client client = Context.client();
		final HashTable itemHashTable = client.getRSItemHashTable();
		final int floor = Game.getPlane();
		final int index = x | y << 14 | floor << 28;

		final NodeListCache itemNodeListCache = (NodeListCache) Nodes.lookup(itemHashTable, index);

		if (itemNodeListCache == null || itemNodeListCache.getNodeList() == null) {
			return new GroundItem[0];
		}

		final Deque<RSItem> itemDeque = new Deque<RSItem>(itemNodeListCache.getNodeList());
		for (RSItem item = itemDeque.getHead(); item != null; item = itemDeque.getNext()) {
			groundItems.add(new GroundItem(new Tile(x, y, floor), new Item(item)));
		}
		return groundItems.toArray(new GroundItem[groundItems.size()]);
	}
}
