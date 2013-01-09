package org.powerbot.game.api.wrappers;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Polygon;

import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.methods.node.Menu;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Random;

/**
 * @author Timer
 */
public class Tile implements Entity, Locatable, Identifiable {
	protected final int x, y, plane;

	public static interface Flag {
		static final int WALL_NORTHWEST = 0x1;
		static final int WALL_NORTH = 0x2;
		static final int WALL_NORTHEAST = 0x4;
		static final int WALL_EAST = 0x8;
		static final int WALL_SOUTHEAST = 0x10;
		static final int WALL_SOUTH = 0x20;
		static final int WALL_SOUTHWEST = 0x40;
		static final int WALL_WEST = 0x80;

		static final int OBJECT_TILE = 0x100;

		static final int WALL_BLOCK_NORTHWEST = 0x200;
		static final int WALL_BLOCK_NORTH = 0x400;
		static final int WALL_BLOCK_NORTHEAST = 0x800;
		static final int WALL_BLOCK_EAST = 0x1000;
		static final int WALL_BLOCK_SOUTHEAST = 0x2000;
		static final int WALL_BLOCK_SOUTH = 0x4000;
		static final int WALL_BLOCK_SOUTHWEST = 0x8000;
		static final int WALL_BLOCK_WEST = 0x10000;

		static final int OBJECT_BLOCK = 0x20000;
		static final int DECORATION_BLOCK = 0x40000;

		static final int WALL_ALLOW_RANGE_NORTHWEST = 0x400000;
		static final int WALL_ALLOW_RANGE_NORTH = 0x800000;
		static final int WALL_ALLOW_RANGE_NORTHEAST = 0x1000000;
		static final int WALL_ALLOW_RANGE_EAST = 0x2000000;
		static final int WALL_ALLOW_RANGE_SOUTHEAST = 0x4000000;
		static final int WALL_ALLOW_RANGE_SOUTH = 0x8000000;
		static final int WALL_ALLOW_RANGE_SOUTHWEST = 0x10000000;
		static final int WALL_ALLOW_RANGE_WEST = 0x20000000;

		static final int OBJECT_ALLOW_RANGE = 0x40000000;

		static final int BLOCKED = 0x1280100;
	}

	public Tile(final int x, final int y, final int plane) {
		this.x = x;
		this.y = y;
		this.plane = plane;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public int getPlane() {
		return plane;
	}

	public Tile randomize(final int left, final int right, final int down, final int up) {
		return derive(Random.nextInt(left, right + 1), Random.nextInt(down, up + 1));
	}

	public Tile randomize(final int x, final int y) {
		return randomize(-x, x, -y, y);
	}

	public Tile derive(final int x, final int y) {
		return new Tile(this.x + x, this.y + y, this.plane);
	}

	public boolean validate() {
		final int x = this.x - Game.getBaseX();
		final int y = this.y - Game.getBaseY();
		return x >= 0 && x < 104 && y >= 0 && y < 104;
	}

	public Point getMapPoint() {
		return Calculations.worldToMap(x, y);
	}

	public boolean isOnMap() {
		final Point p = getMapPoint();
		return p.x != -1 && p.y != -1;
	}

	public Point getCentralPoint() {
		return getPoint(0.5d, 0.5d, 0);
	}

	public Point getNextViewportPoint() {
		return getPoint(Random.nextDouble(), Random.nextDouble(), 0);
	}

	public boolean contains(final Point point) {
		final Polygon[] polygons = getBounds();
		return polygons.length == 1 && polygons[0].contains(point);
	}

	public boolean isOnScreen() {
		return getBounds().length == 1;
	}

	public Polygon[] getBounds() {
		final Point localPoint1 = getPoint(0.0D, 0.0D, 0);
		final Point localPoint2 = getPoint(1.0D, 0.0D, 0);
		final Point localPoint3 = getPoint(0.0D, 1.0D, 0);
		final Point localPoint4 = getPoint(1.0D, 1.0D, 0);
		if (Calculations.isOnScreen(localPoint1) && Calculations.isOnScreen(localPoint2) &&
				Calculations.isOnScreen(localPoint3) && Calculations.isOnScreen(localPoint4)) {
			final Polygon localPolygon = new Polygon();
			localPolygon.addPoint(localPoint1.x, localPoint1.y);
			localPolygon.addPoint(localPoint2.x, localPoint2.y);
			localPolygon.addPoint(localPoint4.x, localPoint4.y);
			localPolygon.addPoint(localPoint3.x, localPoint3.y);
			return new Polygon[]{localPolygon};
		}
		return new Polygon[0];
	}

	public boolean hover() {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return true;
			}
		});
	}

	public boolean click(final boolean left) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				Mouse.click(left);
				return true;
			}
		});
	}

	public boolean clickOnMap() {
		return Walking.walk(this);
	}

	public boolean interact(final String action) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return Menu.select(action);
			}
		});
	}

	public boolean interact(final String action, final String option) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return Menu.select(action, option);
			}
		});
	}

	public boolean canReach() {
		return Walking.findPath(this).init();
	}

	public double distanceTo() {
		return Calculations.distanceTo(this);
	}

	public double distance(final Locatable locatable) {
		return Calculations.distance(this, locatable);
	}

	public Point getPoint(final double xOff, final double yOff, final int height) {
		return Calculations.groundToScreen((int) ((x - Game.getBaseX() + xOff) * 0x200), (int) ((y - Game.getBaseY() + yOff) * 0x200), plane, -height);
	}

	public void draw(final Graphics render) {
		final Polygon[] polygons = getBounds();
		if (polygons.length == 1) {
			render.drawPolygon(polygons[0]);
		}
	}

	public Tile getLocation() {
		return this;
	}

	public RegionOffset getRegionOffset() {
		return new RegionOffset(x - Game.getBaseX(), y - Game.getBaseY(), plane);
	}

	public int getId() {
		return x * 31 + y;
	}

	@Override
	public int hashCode() {
		return getId();
	}

	@Override
	public String toString() {
		return "(" + x + ", " + y + ", " + plane + ')';
	}

	@Override
	public boolean equals(final Object o) {
		if (o != null && o instanceof Tile) {
			final Tile tile = (Tile) o;
			return x == tile.x && y == tile.y && plane == tile.plane;
		}
		return false;
	}
}
