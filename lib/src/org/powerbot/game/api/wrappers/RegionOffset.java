package org.powerbot.game.api.wrappers;

public class RegionOffset {
	protected final int x, y, plane;

	public RegionOffset(final int x, final int y, final int plane) {
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
}
