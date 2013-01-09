package org.powerbot.game.api.wrappers.widget;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.input.Keyboard;

/**
 * @author Stephan J. Bijzitter (Salvation)
 * @since 26-04-2012
 */
public class ChatOption {
	private int number;
	private WidgetChild child;

	/**
	 * Constructs a new ChatOption.
	 *
	 * @param number The number this option is bound to.
	 * @param child  An instance of the WidgetChild this option is bound to.
	 */
	public ChatOption(final int number, final WidgetChild child) {
		this.number = number;
		this.child = child;
	}

	/**
	 * @return The number this option is bound to.
	 */
	public int getOptionNumber() {
		return number;
	}

	/**
	 * @return An instance of the WidgetChild this option is bound to.
	 */
	public WidgetChild getWidgetChild() {
		return child;
	}

	/**
	 * @param isValid   <tt>true</tt> if the result must valid.
	 * @param isVisible <tt>true</tt> if the result must be visible.
	 * @return <tt>true</tt> if and only if the Widget including all its children match the criteria, otherwise <tt>false</tt>.
	 */
	public boolean revalidate(final boolean isValid, final boolean isVisible) {
		WidgetChild w = this.child.getParent();
		if (w != null) {
			w = Widgets.get(w.getIndex(), this.child.getIndex());
		}
		return !(w == null || (isValid && !w.validate()) || (isVisible && !w.visible()));
	}

	/**
	 * Interacts with this option, using either the mouse or the keyboard.
	 *
	 * @param key <tt>true</tt> if and only if the keyboard should be used, <tt>false</tt> otherwise.
	 * @return -1 if the mouse failed to interact, 0 is the keyboard was used (regardless of success!) or +1 if the mouse successfully interacted.
	 */
	public int select(final boolean key) {
		if (key) {
			Keyboard.sendText(number == -1 ? " " : Integer.toString(number), false);
			return 0;
		} else {
			return child.click(true) ? 1 : -1;
		}
	}

	/**
	 * Interacts with this option, using either the mouse or the keyboard.
	 *
	 * @param key      <tt>true</tt> if and only if the keyboard should be used, <tt>false</tt> otherwise.
	 * @param maxSleep The amount of milliseconds the method may wait for the game to respond.
	 * @return <tt>true</tt> if and only if the option was selected successfully
	 */
	public boolean select(final boolean key, final int maxSleep) {
		if (select(key) > -1) {
			final long timeout = System.currentTimeMillis() + maxSleep;
			while (System.currentTimeMillis() < timeout) {
				if (!revalidate(child.validate(), child.visible())) {
					return true;
				}
				Task.sleep(50, 100);
			}
		}
		return false;
	}

	@Override
	public String toString() {
		return getClass().getName() + "(" + number + ", " + child.getText() + ")";
	}
}