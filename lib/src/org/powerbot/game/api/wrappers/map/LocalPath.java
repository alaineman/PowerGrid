package org.powerbot.game.api.wrappers.map;

import java.util.EnumSet;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.wrappers.Tile;

import static org.powerbot.game.api.wrappers.Tile.Flag.BLOCKED;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_EAST;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_NORTH;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_NORTHEAST;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_NORTHWEST;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_SOUTH;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_SOUTHEAST;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_SOUTHWEST;
import static org.powerbot.game.api.wrappers.Tile.Flag.WALL_WEST;

public class LocalPath extends Path {
	private final Tile end;
	private Tile base;
	private int[][] flags;
	private int offX, offY;

	private TilePath tilePath;

	public LocalPath(final Tile end) {
		this.end = end;
	}

	@Override
	public boolean traverse(final EnumSet<TraversalOption> options) {
		return getNext() != null && tilePath.traverse(options);
	}

	@Override
	public boolean validate() {
		return getNext() != null && Calculations.distanceTo(getEnd()) > Math.sqrt(2);
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean init() {
		if (!Game.getMapBase().equals(base)) {
			final int[][] flags = adjustCollisionFlags(Walking.getCollisionFlags(Game.getPlane()));
			if (flags != null) {
				base = Game.getMapBase();
				final Tile start = Players.getLocal().getLocation();
				final Tile[] tiles = findPath(start, end);
				if (tiles == null) {
					base = null;
					return false;
				}
				tilePath = new TilePath(tiles);
			}
		}
		return true;
	}

	@Override
	public Tile getNext() {
		if (!init()) {
			return null;
		}
		return tilePath.getNext();
	}

	@Override
	public Tile getStart() {
		return null;
	}

	@Override
	public Tile getEnd() {
		return end;
	}

	public TilePath getTilePath() {
		return tilePath;
	}

	private Tile[] findPath(final Tile start, final Tile end) {
		if (start.getPlane() != end.getPlane()) {
			return null;
		}
		final int curr_plane = start.getPlane();
		final int base_x = base.getX(), base_y = base.getY();
		final int curr_x = start.getX() - base_x, curr_y = start.getY() - base_y;
		int dest_x = end.getX() - base_x, dest_y = end.getY() - base_y;

		final int plane = Game.getPlane();
		if (curr_plane != plane) {
			return null;
		}
		flags = Walking.getCollisionFlags(plane);
		final Tile offset = Walking.getCollisionOffset(plane);
		offX = offset.getX();
		offY = offset.getY();

		if (flags == null || curr_x < 0 || curr_y < 0 || curr_x >= flags.length || curr_y >= flags.length) {
			return null;
		} else if (dest_x < 0 || dest_y < 0 || dest_x >= flags.length || dest_y >= flags.length) {
			if (dest_x < 0) {
				dest_x = 0;
			} else if (dest_x >= flags.length) {
				dest_x = flags.length - 1;
			}
			if (dest_y < 0) {
				dest_y = 0;
			} else if (dest_y >= flags.length) {
				dest_y = flags.length - 1;
			}
		}

		final HashSet<Vertex> open = new HashSet<Vertex>();
		final HashSet<Vertex> closed = new HashSet<Vertex>();
		Vertex curr = new Vertex(curr_x, curr_y, curr_plane);
		final Vertex dest = new Vertex(dest_x, dest_y, curr_plane);

		curr.f = heuristic(curr, dest);
		open.add(curr);

		while (!open.isEmpty()) {
			curr = lowest_f(open);
			if (curr.equals(dest)) {
				return path(curr, base_x, base_y);
			}
			open.remove(curr);
			closed.add(curr);
			for (final Vertex next : successors(curr)) {
				if (!closed.contains(next)) {
					final double t = curr.g + dist(curr, next);
					boolean use_t = false;
					if (!open.contains(next)) {
						open.add(next);
						use_t = true;
					} else if (t < next.g) {
						use_t = true;
					}
					if (use_t) {
						next.prev = curr;
						next.g = t;
						next.f = t + heuristic(next, dest);
					}
				}
			}
		}

		return null;
	}

	public static double heuristic(final Vertex start, final Vertex end) {
		final double dx = Math.abs(start.x - end.x);
		final double dy = Math.abs(start.y - end.y);
		final double diag = Math.min(dx, dy);
		final double straight = dx + dy;
		return Math.sqrt(2.0) * diag + straight - 2 * diag;
	}

	public static double dist(final Vertex start, final Vertex end) {
		if (start.x != end.x && start.y != end.y) {
			return 1.41421356;
		} else {
			return 1.0;
		}
	}

	public static Vertex lowest_f(final Set<Vertex> open) {
		Vertex best = null;
		for (final Vertex t : open) {
			if (best == null || t.f < best.f) {
				best = t;
			}
		}
		return best;
	}

	private List<Vertex> successors(final Vertex t) {
		final LinkedList<Vertex> tiles = new LinkedList<Vertex>();
		final int x = t.x, y = t.y, z = t.z;
		final int f_x = x - offX, f_y = y - offY;
		final int here = flags[f_x][f_y];
		final int upper = flags.length - 1;
		if (f_y > 0 && (here & WALL_SOUTH) == 0 && (flags[f_x][f_y - 1] & BLOCKED) == 0) {
			tiles.add(new Vertex(x, y - 1, z));
		}
		if (f_x > 0 && (here & WALL_WEST) == 0 && (flags[f_x - 1][f_y] & BLOCKED) == 0) {
			tiles.add(new Vertex(x - 1, y, z));
		}
		if (f_y < upper && (here & WALL_NORTH) == 0 && (flags[f_x][f_y + 1] & BLOCKED) == 0) {
			tiles.add(new Vertex(x, y + 1, z));
		}
		if (f_x < upper && (here & WALL_EAST) == 0 && (flags[f_x + 1][f_y] & BLOCKED) == 0) {
			tiles.add(new Vertex(x + 1, y, z));
		}
		if (f_x > 0 && f_y > 0 && (here & (WALL_SOUTHWEST | WALL_SOUTH | WALL_WEST)) == 0
				&& (flags[f_x - 1][f_y - 1] & BLOCKED) == 0
				&& (flags[f_x][f_y - 1] & (BLOCKED | WALL_WEST)) == 0
				&& (flags[f_x - 1][f_y] & (BLOCKED | WALL_SOUTH)) == 0) {
			tiles.add(new Vertex(x - 1, y - 1, z));
		}
		if (f_x > 0 && f_y < upper && (here & (WALL_NORTHWEST | WALL_NORTH | WALL_WEST)) == 0
				&& (flags[f_x - 1][f_y + 1] & BLOCKED) == 0
				&& (flags[f_x][f_y + 1] & (BLOCKED | WALL_WEST)) == 0
				&& (flags[f_x - 1][f_y] & (BLOCKED | WALL_NORTH)) == 0) {
			tiles.add(new Vertex(x - 1, y + 1, z));
		}
		if (f_x < upper && f_y > 0 && (here & (WALL_SOUTHEAST | WALL_SOUTH | WALL_EAST)) == 0
				&& (flags[f_x + 1][f_y - 1] & BLOCKED) == 0
				&& (flags[f_x][f_y - 1] & (BLOCKED | WALL_EAST)) == 0
				&& (flags[f_x + 1][f_y] & (BLOCKED | WALL_SOUTH)) == 0) {
			tiles.add(new Vertex(x + 1, y - 1, z));
		}
		if (f_x > 0 && f_y < upper && (here & (WALL_NORTHEAST | WALL_NORTH | WALL_EAST)) == 0
				&& (flags[f_x + 1][f_y + 1] & BLOCKED) == 0
				&& (flags[f_x][f_y + 1] & (BLOCKED | WALL_EAST)) == 0
				&& (flags[f_x + 1][f_y] & (BLOCKED | WALL_NORTH)) == 0) {
			tiles.add(new Vertex(x + 1, y + 1, z));
		}
		return tiles;
	}

	public static Tile[] path(final Vertex end, final int base_x, final int base_y) {
		final LinkedList<Tile> path = new LinkedList<Tile>();
		Vertex p = end;
		while (p != null) {
			path.addFirst(p.get(base_x, base_y));
			p = p.prev;
		}
		return path.toArray(new Tile[path.size()]);
	}

	public static final class Vertex {
		public final int x, y, z;
		public Vertex prev;
		public double g, f;
		public boolean special;

		public Vertex(final int x, final int y, final int z) {
			this(x, y, z, false);
		}

		public Vertex(final int x, final int y, final int z, final boolean special) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.special = special;
			g = f = 0;
		}

		@Override
		public int hashCode() {
			return x << 4 | y;
		}

		@Override
		public boolean equals(final Object o) {
			if (o instanceof Vertex) {
				final Vertex n = (Vertex) o;
				return x == n.x && y == n.y && z == n.z;
			}
			return false;
		}

		@Override
		public String toString() {
			return "(" + x + "," + y + ")";
		}

		public Tile get(final int baseX, final int baseY) {
			return new Tile(x + baseX, y + baseY, z);
		}
	}

	private int[][] adjustCollisionFlags(final int[][] flags) {
		final int lx = flags.length - 1;
		final int lx_m = lx - 5;
		for (int x = 0; x <= lx; x++) {
			final int ly = flags[x].length - 1;
			final int ly_m = ly - 5;
			for (int y = 0; y <= ly; y++) {
				if (x <= 5 || y <= 5 || x >= lx_m || y >= ly_m) {
					flags[x][y] = -1;
				}
			}
		}

		return flags;
	}
}
