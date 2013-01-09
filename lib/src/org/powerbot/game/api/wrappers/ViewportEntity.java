package org.powerbot.game.api.wrappers;

import java.awt.Point;

public interface ViewportEntity extends Verifiable {
	/**
	 * Determines the central point of the entity.
	 *
	 * @return The <code>Point</code> of the center of the entity.
	 */
	public Point getCentralPoint();

	/**
	 * Determines the next viewport point of the entity.
	 *
	 * @return The <code>Point</code> of the next viewport point of the entity.
	 */
	public Point getNextViewportPoint();

	/**
	 * Checks if the entity contains the provided point.
	 *
	 * @param point The <code>Point</code> you wish to check.
	 * @return <tt>true</tt> if the entity contains it; otherwise <tt>false</tt>.
	 */
	public boolean contains(final Point point);
}
