package org.powerbot.game.api.wrappers.map;

import java.util.Arrays;
import java.util.EnumSet;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.wrappers.Tile;

public class TilePath extends Path {
	protected Tile[] tiles;
	protected Tile[] orig;

	private boolean end;

	public TilePath(final Tile[] tiles) {
		orig = tiles;
		this.tiles = Arrays.copyOf(tiles, tiles.length);
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean traverse(final EnumSet<TraversalOption> options) {
		final Tile next = getNext();
		if (next == null) {
			return false;
		}
		if (next.equals(getEnd())) {
			if (Calculations.distanceTo(next) <= 1 || end && (!Players.getLocal().isMoving() || Calculations.distanceTo(next) < 3)) {
				return false;
			}
			end = true;
		} else {
			end = false;
		}
		if (options != null && options.contains(TraversalOption.HANDLE_RUN) && !Walking.isRunEnabled() && Walking.getEnergy() > 50) {
			Walking.setRun(true);
			Task.sleep(300);
		}
		if (options != null && options.contains(TraversalOption.SPACE_ACTIONS)) {
			final Tile dest = Walking.getDestination();
			if (dest.getX() != -1 && Players.getLocal().isMoving() && Calculations.distanceTo(dest) > 5 && Calculations.distance(next, dest) < 7) {
				return true;
			}
		}
		return Walking.walk(next);
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean validate() {
		return tiles.length > 0 && getNext() != null && Calculations.distanceTo(getEnd()) > Math.sqrt(2);
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public Tile getNext() {
		final Tile dest = Walking.getDestination();
		for (int i = tiles.length - 1; i >= 0; --i) {
			if (tiles[i].isOnMap() && (tiles[i].canReach() || (i != 0 && (dest.getX() != -1 ? Calculations.distance(dest, tiles[i - 1]) < 3 : Calculations.distanceTo(tiles[i - 1]) < 7)))) {
				return tiles[i];
			}
		}
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public Tile getStart() {
		return tiles[0];
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public Tile getEnd() {
		return tiles[tiles.length - 1];
	}

	public TilePath randomize(final int maxX, final int maxY) {
		for (int i = 0; i < tiles.length; ++i) {
			tiles[i] = orig[i].derive(Random.nextInt(-maxX, maxX + 1), Random.nextInt(-maxY, maxY + 1));
		}
		return this;
	}

	public TilePath reverse() {
		Tile[] reversed = new Tile[tiles.length];
		for (int i = 0; i < orig.length; ++i) {
			reversed[i] = orig[tiles.length - 1 - i];
		}
		orig = reversed;
		reversed = new Tile[tiles.length];
		for (int i = 0; i < tiles.length; ++i) {
			reversed[i] = tiles[tiles.length - 1 - i];
		}
		tiles = reversed;
		return this;
	}

	public Tile[] toArray() {
		final Tile[] a = new Tile[tiles.length];
		System.arraycopy(tiles, 0, a, 0, tiles.length);
		return a;
	}
}