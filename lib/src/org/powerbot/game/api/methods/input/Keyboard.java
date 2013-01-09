package org.powerbot.game.api.methods.input;

import java.awt.Component;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;

/**
 * A utility that handles the dispatching of fake key events.
 *
 * @author Timer
 */
public class Keyboard {
	/**
	 * 'Presses' the given char for the given delay and with the given mask.
	 *
	 * @param ch    The char to press.
	 * @param delay The time until the key is held down.
	 * @param mask  The mask to press this key with.
	 */
	public static void pressKey(final char ch, final int delay, final int mask) {
		pressKey(ch, ch, delay, mask);
	}

	/**
	 * 'Presses' the given char for the given delay and with the given mask.
	 *
	 * @param ch    The char to press.
	 * @param code  The code of the char to press.
	 * @param delay The time until the key is held down.
	 * @param mask  The mask to press this key with.
	 */
	public static void pressKey(final char ch, final int code, final int delay, final int mask) {
		getKeyboard().keyPressed(
				new KeyEvent(getTarget(), KeyEvent.KEY_PRESSED, System.currentTimeMillis() + delay, mask, code, getKeyChar(ch), getLocation(ch))
		);
		if ((ch < KeyEvent.VK_LEFT || ch > KeyEvent.VK_DOWN) && (ch < KeyEvent.VK_SHIFT || ch > KeyEvent.VK_CAPS_LOCK) && (ch != KeyEvent.CHAR_UNDEFINED)) {
			getKeyboard().keyTyped(
					new KeyEvent(getTarget(), KeyEvent.KEY_TYPED, System.currentTimeMillis() + delay, mask, KeyEvent.VK_UNDEFINED, getKeyChar(ch), 0)
			);
		}
	}

	/**
	 * Releases a key after the given delay and with the given mask.
	 *
	 * @param ch    The char to release.
	 * @param delay The time to wait until this key is released.
	 * @param mask  The mask to release the given char with.
	 */
	public static void releaseKey(final char ch, final int delay, final int mask) {
		releaseKey(ch, ch, delay, mask);
	}

	/**
	 * Releases a key after the given delay and with the given mask.
	 *
	 * @param ch    The char to release.
	 * @param code  The code of the char to release.
	 * @param delay The time to wait until this key is released.
	 * @param mask  The mask to release the given char with.
	 */
	public static void releaseKey(final char ch, final int code, final int delay, final int mask) {
		getKeyboard().keyReleased(
				new KeyEvent(getTarget(), KeyEvent.KEY_RELEASED, System.currentTimeMillis() + delay, mask, code, getKeyChar(ch), getLocation(ch))
		);
	}

	/**
	 * Returns the standard location of the character on the keyboard for masks.
	 *
	 * @param ch The character to determine the position of.
	 * @return The key location value.
	 */
	private static int getLocation(final char ch) {
		if (ch >= KeyEvent.VK_SHIFT && ch <= KeyEvent.VK_ALT) {
			return Random.nextInt(KeyEvent.KEY_LOCATION_LEFT, KeyEvent.KEY_LOCATION_RIGHT + 1);
		}
		return KeyEvent.KEY_LOCATION_STANDARD;
	}

	/**
	 * Types a single character.
	 *
	 * @param ch The key to type.
	 */
	public static void sendKey(final char ch) {
		sendKey(ch, 0);
	}

	/**
	 * Presses and holds the given character for the delay, then releases.
	 *
	 * @param ch    The character to type.
	 * @param delay The time to hold the key for.
	 */
	public static void sendKey(char ch, final int delay) {
		int code = ch;
		if (ch >= 'a' && ch <= 'z') {
			code -= 32;
		}

		sendKey(ch, code, delay);
	}

	/**
	 * Presses and holds the given character for the delay, then releases.
	 *
	 * @param ch    The character to type.
	 * @param code  Key code for special characters
	 * @param delay The time to hold the key for.
	 */
	public static void sendKey(char ch, int code, final int delay) {
		boolean shift = false;
		if (ch >= 'A' && ch <= 'Z') {
			shift = true;
		}
		int wait = 0;
		if (shift) {
			pressKey((char) KeyEvent.VK_SHIFT, 0, InputEvent.SHIFT_DOWN_MASK);
			wait = Random.nextInt(100, 200);
		}
		pressKey(ch, code, wait, shift ? InputEvent.SHIFT_DOWN_MASK : 0);
		if (delay > 500) {
			pressKey(ch, code, 500 + wait, shift ? InputEvent.SHIFT_DOWN_MASK : 0);
			final int iterationWait = delay - 500;
			for (int i = 37; i < iterationWait; i += Random.nextInt(20, 40)) {
				pressKey(ch, code, 500 + i + wait, shift ? InputEvent.SHIFT_DOWN_MASK : 0);
			}
		}
		final int releasedDelay = delay + Random.nextInt(-30, 30);
		releaseKey(ch, code, releasedDelay + wait, shift ? InputEvent.SHIFT_DOWN_MASK : 0);
		if (shift) {
			releaseKey((char) KeyEvent.VK_SHIFT, releasedDelay + wait + Random.nextInt(50, 120), InputEvent.SHIFT_DOWN_MASK);
		}
	}

	/**
	 * Types an array of characters.
	 *
	 * @param text       The text to send.
	 * @param pressEnter <tt>true</tt> to press enter; otherwise <tt>false</tt>.
	 */
	public static void sendText(final String text, final boolean pressEnter) {
		sendText(text, pressEnter, 100, 200);
	}

	/**
	 * Types an array of characters with the given delay between keys.
	 *
	 * @param text       The text to enter into the game.
	 * @param pressEnter <tt>true</tt> to press enter; otherwise <tt>false</tt>.
	 * @param minDelay   The lowest possible wait (inclusive).
	 * @param maxDelay   The largest possible wait (exclusive).
	 */
	public static void sendText(final String text, final boolean pressEnter, final int minDelay, final int maxDelay) {
		final char[] chars = text.toCharArray();
		for (final char element : chars) {
			final int wait = Random.nextInt(minDelay, maxDelay);
			sendKey(element, wait);
			if (wait > 0) {
				Task.sleep(wait);
			}
		}
		if (pressEnter) {
			sendKey((char) KeyEvent.VK_ENTER, Random.nextInt(minDelay, maxDelay));
		}
	}

	/**
	 * @return <tt>true</tt> if the keyboard is ready to accept events; otherwise <tt>false</tt>.
	 */
	public static boolean isReady() {
		try {
			return getKeyboard() != null;
		} catch (RuntimeException ignored) {
		}
		return false;
	}

	/**
	 * Returns the keyboard associated with this thread-group to relay events to.
	 *
	 * @return The <code>org.powerbot.game.client.input.Keyboard</code> to relay events to.
	 */
	private static org.powerbot.game.client.input.Keyboard getKeyboard() {
		final Client client = Context.client();
		if (client == null || client.getCanvas() == null) {
			throw new RuntimeException("client not ready for events");
		}
		final KeyListener[] listeners = client.getCanvas().getKeyListeners();
		if (listeners.length != 1) {
			throw new RuntimeException("listener mismatch");
		}
		return (org.powerbot.game.client.input.Keyboard) listeners[0];
	}

	/**
	 * The component associated with this thread-group to dispatch events onto.
	 *
	 * @return The <code>Component</code> to dispatch events to.
	 */
	private static Component getTarget() {
		final Context context = Context.get();
		if (context.getApplet() == null || context.getApplet().getComponentCount() == 0) {
			throw new RuntimeException("client not ready for events");
		}
		return context.getApplet().getComponent(0);
	}

	/**
	 * Returns the key char for this character, excluding non-letters.
	 *
	 * @param c The character to verify.
	 * @return The verified character.
	 */
	private static char getKeyChar(final char c) {
		if (c >= 36 && c <= 40) {
			return KeyEvent.VK_UNDEFINED;
		}
		return c;
	}
}
