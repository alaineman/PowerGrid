package org.powerbot.game.api.wrappers;

import java.awt.Graphics;
import java.awt.Polygon;

/**
 * Represents an interactive entity in RuneScape.
 *
 * @author Timer
 */
public interface Entity extends ViewportEntity {
	/**
	 * Determines if this entity is on screen.
	 *
	 * @return <tt>true</tt> if this entity is on screen; otherwise <tt>false</tt>.
	 */
	public boolean isOnScreen();

	/**
	 * Returns the boundaries of the entity.
	 *
	 * @return The <code>Polygon[]</code> of the bounds.
	 */
	public Polygon[] getBounds();

	/**
	 * Hovers this entity.
	 *
	 * @return <tt>true</tt> if hovered; otherwise <tt>false</tt>.
	 */
	public boolean hover();

	/**
	 * Clicks this entity.
	 *
	 * @param left Left click or right click.
	 * @return <tt>true</tt> if clicked; otherwise <tt>false</tt>.
	 */
	public boolean click(final boolean left);

	/**
	 * Interacts with this entity.
	 *
	 * @param action The action to perform.
	 * @return <tt>true</tt> if interacted; otherwise <tt>false</tt>.
	 */
	public boolean interact(final String action);

	/**
	 * Interacts with this entity.
	 *
	 * @param action The action to perform.
	 * @param option The option to perform.
	 * @return <tt>true</tt> if interacted; otherwise <tt>false</tt>.
	 */
	public boolean interact(final String action, final String option);

	/**
	 * Draws the entity in detail.
	 *
	 * @param render The render to paint onto.
	 */
	public void draw(final Graphics render);
}
