package org.powerbot.game.api.methods;

import java.awt.Canvas;
import java.awt.Point;

import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.widget.WidgetCache;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.interactive.Player;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.TileData;

/**
 * A utility for the manipulation of different calculations for the game.
 *
 * @author Timer
 */
public class Calculations {
	/**
	 * A representation of the game's (Java) Toolkit.
	 *
	 * @author Timer
	 */
	public static class Toolkit {
		public float absoluteX, absoluteY;
		public float xMultiplier, yMultiplier;
	}

	/**
	 * A representation of the game's Viewport, or Matrix.
	 *
	 * @author Timer
	 */
	public static class Viewport {
		public float xOff, xX, xY, xZ;
		public float yOff, yX, yY, yZ;
		public float zOff, zX, zY, zZ;
	}

	public static final int[] SIN_TABLE = new int[0x4000];
	public static final int[] COS_TABLE = new int[0x4000];

	static {
		final double d = 0.00038349519697141029D;
		for (int i = 0; i < 0x4000; i++) {
			Calculations.SIN_TABLE[i] = (int) (32768D * Math.sin(i * d));
			Calculations.COS_TABLE[i] = (int) (32768D * Math.cos(i * d));
		}
	}

	/**
	 * @param x     The local x position of the tile of which you desire to get the height for.
	 * @param y     The local y position of the tile of which you desire to get the height for.
	 * @param plane The plane to access this tile's information on.
	 * @return The height of the given tile on the provided plane.
	 */
	public static int calculateTileHeight(final int x, final int y, int plane) {
		final Client client = Context.client();
		final int x1 = x >> 9;
		final int y1 = y >> 9;
		try {
			final byte[][][] settings = client.getRSGroundInfo().getGroundBytes().getBytes();
			if (settings != null && x1 >= 0 && x1 < 104 && y1 >= 0 && y1 < 104) {
				if (plane <= 3 && (settings[1][x1][y1] & 2) != 0) {
					++plane;
				}
				final TileData[] planes = client.getRSGroundInfo().getRSGroundInfo().getTileData();
				if (planes != null && plane < planes.length && planes[plane] != null) {
					final int[][] heights = planes[plane].getHeights();
					if (heights != null) {
						final int x2 = x & 0x200 - 1;
						final int y2 = y & 0x200 - 1;
						final int start_h = heights[x1][y1] * (0x200 - x2) + heights[x1 + 1][y1] * x2 >> 9;
						final int end_h = heights[x1][1 + y1] * (0x200 - x2) + heights[x1 + 1][y1 + 1] * x2 >> 9;
						return start_h * (512 - y2) + end_h * y2 >> 9;
					}
				}
			}
		} catch (final NullPointerException ignored) {
		}
		return 0;
	}

	/**
	 * @param x      The absolute x ground position.
	 * @param y      The absolute x ground position.
	 * @param plane  The plane to calculation this tile's position on.
	 * @param height The height offset.
	 * @return The <code>Point</code> of the given tile on the screen.
	 */
	public static Point groundToScreen(final int x, final int y, final int plane, final int height) {
		if (x < 512 || y < 512 || x > 52224 || y > 52224) {
			return new Point(-1, -1);
		}
		final int z = calculateTileHeight(x, y, plane) - height;
		return worldToScreen(x, z, y);
	}

	/**
	 * @param x Absolute x position of the calculation.
	 * @param y Depth of the requested calculation.
	 * @param z Absolute y position of the calculation.
	 * @return The <code>Point</code> of the given coordinates on screen.
	 */
	public static Point worldToScreen(final int x, final int y, final int z) {
		final Context bot = Context.get();
		final Toolkit toolkit = bot.getToolkit();
		final Viewport viewport = bot.getViewport();
		final float _z = (viewport.zOff + (viewport.zX * x + viewport.zY * y + viewport.zZ * z));
		final float _x = (viewport.xOff + (viewport.xX * x + viewport.xY * y + viewport.xZ * z));
		final float _y = (viewport.yOff + (viewport.yX * x + viewport.yY * y + viewport.yZ * z));
		if (_x >= -_z && _x <= _z && _y >= -_z && _y <= _z) {
			return new Point(
					Math.round(toolkit.absoluteX + (toolkit.xMultiplier * _x) / _z),
					Math.round(toolkit.absoluteY + (toolkit.yMultiplier * _y) / _z)
			);
		}
		return new Point(-1, -1);
	}

	/**
	 * Returns the <code>Point</code> of given x and y values in the game's 2D plane.
	 *
	 * @param x x value based on the game plane.
	 * @param y y value based on the game plane.
	 * @return <code>Point</code> within map; otherwise <tt>new Point(-1, -1)</tt>.
	 */
	public static Point worldToMap(double x, double y) {
		final Client client = Context.client();
		final Player local = Players.getLocal();
		x -= Game.getBaseX();
		y -= Game.getBaseY();

		final RegionOffset localTile = local.getRegionOffset();
		final int calculatedX = (int) (x * 4 + 2) - (localTile.getX() << 9) / 0x80;
		final int calculatedY = (int) (y * 4 + 2) - (localTile.getY() << 9) / 0x80;

		final WidgetChild mm2 = WidgetCache.getMap();
		if (mm2 == null) {
			return new Point(-1, -1);
		}
		final int actDistSq = calculatedX * calculatedX + calculatedY * calculatedY;
		final int mmDist = Math.max(mm2.getWidth() / 2, mm2.getHeight() / 2) - 8;

		if (mmDist * mmDist >= actDistSq) {
			int angle = 0x3fff & (int) client.getMinimapAngle();
			final boolean setting4 = client.getMinimapSettings() == Context.constants().MINIMAP_SETTINGS_ON;

			if (!setting4) {
				angle = 0x3fff & client.getMinimapOffset() + (int) client.getMinimapAngle();
			}

			int cs = Calculations.SIN_TABLE[angle];
			int cc = Calculations.COS_TABLE[angle];

			if (!setting4) {
				final int fact = 0x100 + client.getMinimapScale();
				cs = 0x100 * cs / fact;
				cc = 0x100 * cc / fact;
			}

			final int calcCenterX = cc * calculatedX + cs * calculatedY >> 0xf;
			final int calcCenterY = cc * calculatedY - cs * calculatedX >> 0xf;
			final int screen_x = calcCenterX + mm2.getAbsoluteX() + mm2.getWidth() / 2;
			final int screen_y = -calcCenterY + mm2.getAbsoluteY() + mm2.getHeight() / 2;
			return new Point(screen_x, screen_y);
		}

		return new Point(-1, -1);
	}

	/**
	 * @param point The <code>Point</code> to determine if it's on screen or not.
	 * @return <tt>true</tt> if the point is on the screen; otherwise <tt>false</tt>.
	 */
	public static boolean isOnScreen(final Point point) {
		return isOnScreen(point.x, point.y);
	}

	/**
	 * @param x The x pixel relative to the game.
	 * @param y The y pixel relative to the game.
	 * @return <tt>true</tt> if the point is on the screen; otherwise <tt>false</tt>.
	 */
	public static boolean isOnScreen(final int x, final int y) {
		final Canvas canvas = Context.client().getCanvas();
		return x >= 0 && y >= 0 && x < canvas.getWidth() && y < canvas.getHeight();
	}

	public static double distance(final Locatable locatable1, final Locatable locatable2) {
		final Tile tile1 = locatable1.getLocation(), tile2 = locatable2.getLocation();
		return Math.sqrt(Math.pow(tile1.getX() - tile2.getX(), 2) + Math.pow(tile1.getY() - tile2.getY(), 2));
	}

	public static double distance(final RegionOffset tile1, final RegionOffset tile2) {
		return Math.sqrt(Math.pow(tile1.getX() - tile2.getX(), 2) + Math.pow(tile1.getY() - tile2.getY(), 2));
	}

	public static double distance(final int x1, final int y1, final int x2, final int y2) {
		return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
	}

	public static double distanceTo(final Locatable locatable) {
		return distance(locatable, Players.getLocal());
	}

	public static double distanceTo(final RegionOffset offset) {
		return distance(offset, Players.getLocal().getRegionOffset());
	}

	public static double distanceTo(final int x, final int y) {
		final Tile pos = Players.getLocal().getLocation();
		return distance(x, y, pos.getX(), pos.getY());
	}
}
