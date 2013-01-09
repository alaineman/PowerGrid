package org.powerbot.game.api.methods.node;

import java.util.LinkedHashSet;
import java.util.Set;

import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.node.SceneObject;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSAnimableNode;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSGroundInfo;
import org.powerbot.game.client.RSInfo;
import org.powerbot.game.client.RSObject;

/**
 * A utility for the gathering of locations on the game plane's mesh.
 *
 * @author Timer
 */
public class SceneEntities {
	public static final int TYPE_INTERACTIVE = 0x1;
	public static final int TYPE_FLOOR_DECORATION = 0x2;
	public static final int TYPE_BOUNDARY = 0x4;
	public static final int TYPE_WALL_DECORATION = 0x8;
	public static final int TYPE_UNKNOWN = 0x10;

	public static final Filter<SceneObject> ALL_FILTER = new Filter<SceneObject>() {
		public boolean accept(final SceneObject obj) {
			return true;
		}
	};

	/**
	 * @return An array of all of the loaded Locations within the currently loaded region.
	 */
	public static SceneObject[] getLoaded() {
		return getLoaded(ALL_FILTER);
	}

	/**
	 * @param tile The <code>Tile</code> desired to have its Locations listed.
	 * @return An array of all of the loaded Locations positioned on the given tile.
	 */
	public static SceneObject[] getLoaded(final Tile tile) {
		if (tile.validate()) {
			final Set<SceneObject> locations = getLocalAt(tile.getX() - Game.getBaseX(), tile.getY() - Game.getBaseY(), -1);
			return locations.toArray(new SceneObject[locations.size()]);
		}
		return new SceneObject[0];
	}

	public static SceneObject[] getLoaded(final int... ids) {
		return getLoaded(new Filter<SceneObject>() {
			public boolean accept(final SceneObject location) {
				final int id = location.getId();
				for (final int i : ids) {
					if (id == i) {
						return true;
					}
				}
				return false;
			}
		});
	}

	/**
	 * @param filter The filtering <code>Filter</code> to accept all the Locations through.
	 * @return An array of all of the loaded Locations within the currently loaded region that are accepted by the provided filter.
	 */
	public static SceneObject[] getLoaded(final Filter<SceneObject> filter) {
		final Set<SceneObject> objects = new LinkedHashSet<SceneObject>();
		for (int x = 0; x < 104; x++) {
			for (int y = 0; y < 104; y++) {
				for (final SceneObject l : getLocalAt(x, y, -1)) {
					if (l != null && filter.accept(l)) {
						objects.add(l);
					}
				}
			}
		}
		return objects.toArray(new SceneObject[objects.size()]);
	}

	public static SceneObject getNearest(final int... ids) {
		return getNearest(new Filter<SceneObject>() {
			public boolean accept(final SceneObject location) {
				final int id = location.getId();
				for (final int i : ids) {
					if (id == i) {
						return true;
					}
				}
				return false;
			}
		});
	}

	public static SceneObject getNearest(final Filter<SceneObject> filter) {
		return getNearestTo(Players.getLocal(), filter);
	}

	public static SceneObject getNearestTo(final Locatable locatable, final Filter<SceneObject> filter) {
		SceneObject location = null;
		double distance = Double.MAX_VALUE;
		final RegionOffset position = locatable.getRegionOffset();
		for (int x = 0; x < 104; x++) {
			for (int y = 0; y < 104; y++) {
				for (final SceneObject l : getLocalAt(x, y, -1)) {
					if (l != null && filter.accept(l)) {
						final double dist = Calculations.distance(position.getX(), position.getY(), x, y);
						if (dist < distance) {
							distance = dist;
							location = l;
						}
					}
				}
			}
		}
		return location;
	}

	private static RSGround[][][] getRSGroundArray(final Client client) {
		Object obj;
		if ((obj = client.getRSGroundInfo()) == null) {
			return null;
		}
		if ((obj = ((RSInfo) obj).getRSGroundInfo()) == null) {
			return null;
		}
		if ((obj = ((RSGroundInfo) obj).getRSGroundArray()) == null) {
			return null;
		}
		return (RSGround[][][]) obj;
	}

	public static SceneObject getAt(int x, int y, final int mask) {
		if (x > 103 || y > 103) {
			x -= Game.getBaseX();
			y -= Game.getBaseY();
		}
		if (x >= 0 && y >= 0 && x < 104 && y < 104) {
			final Set<SceneObject> objects = getLocalAt(x, y, mask);
			if (objects.size() > 0) {
				return objects.toArray(new SceneObject[objects.size()])[0];
			}
		}
		return null;
	}

	public static SceneObject getAt(final int x, final int y) {
		return getAt(x, y, -1);
	}

	public static SceneObject getAt(final Locatable l, final int mask) {
		final Tile t = l.getLocation();
		return getAt(t.getX(), t.getY(), mask);
	}

	public static SceneObject getAt(final Locatable l) {
		return getAt(l, -1);
	}

	public static Set<SceneObject> getLocalAt(int x, int y, final int mask) {
		final Client client = Context.client();
		final Set<SceneObject> objects = new LinkedHashSet<SceneObject>();
		final RSGround[][][] groundArray = getRSGroundArray(client);
		if (groundArray == null) {
			return objects;
		}
		final int plane = client.getPlane();
		final RSGround rsGround = groundArray[plane][x][y];

		if (rsGround != null) {
			Object obj;

			if ((mask & TYPE_INTERACTIVE) != 0) {
				for (RSAnimableNode node = rsGround.getRSAnimableList(); node != null; node = node.getNext()) {
					obj = node.getRSAnimable();
					if (obj != null && obj instanceof RSObject) {
						objects.add(new SceneObject((RSObject) obj, TYPE_INTERACTIVE, plane));
					}
				}
			}

			if ((mask & TYPE_FLOOR_DECORATION) != 0) {
				obj = rsGround.getFloorDecoration();
				if (obj != null && obj instanceof RSObject) {
					objects.add(new SceneObject((RSObject) obj, TYPE_FLOOR_DECORATION, plane));
				}
			}

			if ((mask & TYPE_BOUNDARY) != 0) {
				obj = rsGround.getBoundary1();
				if (obj != null && obj instanceof RSObject) {
					objects.add(new SceneObject((RSObject) obj, TYPE_BOUNDARY, plane));
				}

				obj = rsGround.getBoundary2();
				if (obj != null && obj instanceof RSObject) {
					objects.add(new SceneObject((RSObject) obj, TYPE_BOUNDARY, plane));
				}
			}

			if ((mask & TYPE_WALL_DECORATION) != 0) {
				obj = rsGround.getWallDecoration1();
				if (obj != null && obj instanceof RSObject) {
					objects.add(new SceneObject((RSObject) obj, TYPE_WALL_DECORATION, plane));
				}

				obj = rsGround.getWallDecoration2();
				if (obj != null && obj instanceof RSObject) {
					objects.add(new SceneObject((RSObject) obj, TYPE_WALL_DECORATION, plane));
				}
			}
		}
		return objects;
	}
}
