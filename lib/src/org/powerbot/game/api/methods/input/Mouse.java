package org.powerbot.game.api.methods.input;

import java.awt.Canvas;
import java.awt.Component;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.util.HashMap;
import java.util.Map;

import org.powerbot.core.bot.Bot;
import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.wrappers.ViewportEntity;
import org.powerbot.game.bot.Context;
import org.powerbot.game.bot.handler.input.MouseExecutor;
import org.powerbot.game.bot.handler.input.util.MouseNode;
import org.powerbot.game.client.Client;

/**
 * A utility for the manipulation of the game's mouse.
 *
 * @author Timer
 */
public class Mouse {
	private static final Map<ThreadGroup, Integer> dragLengths = new HashMap<ThreadGroup, Integer>();
	private static final Map<ThreadGroup, Integer> sides = new HashMap<ThreadGroup, Integer>();

	public enum Speed {
		VERY_SLOW, SLOW, NORMAL, FAST, VERY_FAST
	}

	public static void setSpeed(final Speed speed) {
		Bot.setSpeed(speed);
	}

	/**
	 * @return The local x position of the mouse.
	 */
	public static int getX() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse == null ? -1 : mouse.getX();
	}

	/**
	 * @return The local y position of the mouse.
	 */
	public static int getY() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse == null ? -1 : mouse.getY();
	}

	/**
	 * @return The local (<code>Point</code>) position of the mouse.
	 */
	public static Point getLocation() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse == null ? new Point(-1, -1) : new Point(mouse.getX(), mouse.getY());
	}

	/**
	 * @return The local x location at which the bot's mouse was last clicked.
	 */
	public static int getPressX() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse == null ? -1 : mouse.getPressX();
	}

	/**
	 * @return The local y location at which the bot's mouse was last clicked.
	 */
	public static int getPressY() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse == null ? -1 : mouse.getPressY();
	}

	/**
	 * @return The System time of the last recorded mouse click.
	 */
	public static long getPressTime() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse == null ? -1L : mouse.getPressTime();
	}


	/**
	 * @return <tt>true</tt> if the mouse is present; otherwise <tt>false</tt>.
	 */
	public static boolean isPresent() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse != null && mouse.isPresent();
	}

	/**
	 * @return <tt>true</tt> if the mouse is pressed; otherwise <tt>false</tt>.
	 */
	public static boolean isPressed() {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		return mouse != null && mouse.isPressed();
	}

	/**
	 * Scrolls the mouse up or down by 1 unit.
	 *
	 * @param down <tt>true</tt> to scroll down, <tt>false</tt> to scroll up.
	 */
	public static void scroll(final boolean down) {
		scroll(down, 0);
	}

	/**
	 * Scrolls the mouse up or down with delay.
	 *
	 * @param down  <tt>true</tt> to scroll down, <tt>false</tt> to scroll up.
	 * @param delay Amount of milliseconds to wait with scrolling
	 */
	public static void scroll(final boolean down, final int delay) {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		final Component target = getTarget();
		if (mouse == null || target == null) {
			return;
		}

		mouse.sendEvent(
				new MouseWheelEvent(target, MouseWheelEvent.MOUSE_WHEEL, System.currentTimeMillis() + delay, 0, getX(), getY(), 0, false, MouseWheelEvent.WHEEL_UNIT_SCROLL, 3, down ? 3 : -3)
		);
	}

	/**
	 * Clicks the mouse at it's current position.
	 *
	 * @param left <tt>true</tt> to click left; otherwise <tt>false</tt> to click right.
	 */
	public static boolean click(final boolean left) {
		if (!isPresent()) {
			return false;
		}
		final int x = getX(), y = getY();
		pressMouse(x, y, left);
		Task.sleep(Random.nextInt(50, 150));
		releaseMouse(x, y, left);
		Task.sleep(Random.nextInt(50, 80));
		return true;
	}

	public static boolean click(final Point p, final boolean left) {
		return click(p.x, p.y, left);
	}

	public static boolean click(final int x, final int y, final boolean left) {
		if (move(x, y)) {
			click(left);
			return true;
		}
		return false;
	}

	/**
	 * Holds the mouse at it's current position.
	 *
	 * @param time The amount of milliseconds to hold the mouse down for.
	 * @param left <tt>true</tt> to click left; otherwise <tt>false</tt> to click right.
	 */
	public static void hold(final int time, final boolean left) {
		if (!isPresent()) {
			return;
		}
		final int x = getX(), y = getY();
		pressMouse(x, y, left);
		Task.sleep(time);
		releaseMouse(x, y, left);
		Task.sleep(Random.nextInt(50, 80));
	}

	/**
	 * Hops the mouse to the desired destination.
	 *
	 * @param x The x location to hop to.
	 * @param y The y location to hop to.
	 */
	public static void hop(final int x, final int y) {
		hop(x, y, 0, 0);
	}

	/**
	 * Hops the mouse to the desired destination.
	 *
	 * @param x       The x location to hop to.
	 * @param y       The y location to hop to.
	 * @param randomX The random x gaussian distribution.
	 * @param randomY The random y gaussian distribution.
	 */
	public static void hop(int x, int y, final int randomX, final int randomY) {
		moveMouse(x + Random.nextGaussian(-randomX, randomX, randomX), y + Random.nextGaussian(-randomY, randomY, randomY));
	}

	/**
	 * Moves the mouse to the desired destination.
	 *
	 * @param x THe desired x location.
	 * @param y The desired y location.
	 * @return <tt>true</tt> if we reached this position; otherwise <tt>false</tt>.
	 */
	public static boolean move(final int x, final int y) {
		return move(x, y, 1, 1);
	}

	public static boolean move(final Point p) {
		return move(p.x, p.y, 1, 1);
	}

	public static void drag(final Point p) {
		drag(p.x, p.y);
	}

	public static void drag(final int dx, final int dy) {
		drag(dx, dy, 1, 1);
	}

	public static void drag(final Point p, final int rx, final int ry) {
		drag(p.x, p.y, rx, ry);
	}

	public static void drag(final int dx, final int dy, final int rx, final int ry) {
		if (!isPresent()) {
			return;
		}
		pressMouse(getX(), getY(), true);
		Task.sleep(Random.nextInt(10, 400));
		move(dx, dy, rx, ry);
		Task.sleep(Random.nextInt(10, 400));
		releaseMouse(getX(), getY(), true);
	}

	/**
	 * Moves the mouse to the desired destination.
	 *
	 * @param x       The desired x location.
	 * @param y       The desired y location.
	 * @param randomX The random x gaussian distribution.
	 * @param randomY The random y gaussian distribution.
	 * @return <tt>true</tt> if we reached this position; otherwise <tt>false</tt>.
	 */
	public static boolean move(int x, int y, final int randomX, final int randomY) {
		final MouseExecutor executor = Context.get().getExecutor();
		final MouseNode node = create(x, y, randomX, randomY, false, false);
		while (node.getTimer().isRunning() && node.processable()) {
			executor.step(node);
		}
		return node.isCompleted();
	}

	public static boolean move(final Point p, final int randomX, final int randomY) {
		return move(p.x, p.y, randomX, randomY);
	}

	public static boolean apply(final ViewportEntity viewportEntity, final Filter<Point> filter) {
		final MouseExecutor executor = Context.get().getExecutor();
		final MouseNode node = new MouseNode(viewportEntity, filter);
		while (node.getTimer().isRunning() && node.processable()) {
			executor.step(node);
		}
		return node.isCompleted();
	}

	private static void pressMouse(final int x, final int y, final boolean left) {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		final Component target = getTarget();
		if (mouse == null || target == null ||
				mouse.isPressed() || !mouse.isPresent()) {
			return;
		}
		mouse.sendEvent(
				new MouseEvent(target, MouseEvent.MOUSE_PRESSED, System.currentTimeMillis(), 0, x, y, 1, false, left ? MouseEvent.BUTTON1 : MouseEvent.BUTTON3)
		);
	}

	private static void moveMouse(final int x, final int y) {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		final Component target = getTarget();
		if (mouse == null || target == null) {
			return;
		}
		if (mouse.isPressed()) {
			mouse.sendEvent(
					new MouseEvent(target, MouseEvent.MOUSE_DRAGGED, System.currentTimeMillis(), 0, x, y, 0, false)
			);
			if ((getDragLength() & 0xFF) != 0xFF) {
				putDragLength(getDragLength() + 1);
			}
		}

		if (!mouse.isPresent()) {
			if (Calculations.isOnScreen(x, y)) {
				mouse.sendEvent(
						new MouseEvent(target, MouseEvent.MOUSE_ENTERED, System.currentTimeMillis(), 0, x, y, 0, false)
				);
			} else {
				mouse.update(x, y);
			}
		} else if (!Calculations.isOnScreen(x, y)) {
			mouse.sendEvent(
					new MouseEvent(target, MouseEvent.MOUSE_EXITED, System.currentTimeMillis(), 0, x, y, 0, false)
			);
			final Client client = Context.client();
			final Canvas canvas;
			if (client != null && (canvas = client.getCanvas()) != null) {
				final int w = canvas.getWidth(), h = canvas.getHeight();
				if (x <= 0) {
					Mouse.putSide(1);
				} else if (x >= w) {
					Mouse.putSide(3);
				} else if (y <= 0) {
					Mouse.putSide(4);
				} else if (y >= h) {
					Mouse.putSide(2);
				} else {
					Mouse.putSide(Random.nextInt(0, 5));
				}
			}
		} else if (!mouse.isPressed()) {
			mouse.sendEvent(
					new MouseEvent(target, MouseEvent.MOUSE_MOVED, System.currentTimeMillis(), 0, x, y, 0, false)
			);
		}
	}

	private static void releaseMouse(final int x, final int y, final boolean left) {
		final org.powerbot.game.client.input.Mouse mouse = getMouse();
		final Component target = getTarget();
		if (mouse == null || target == null ||
				!mouse.isPressed()) {
			return;
		}
		mouse.sendEvent(
				new MouseEvent(target, MouseEvent.MOUSE_RELEASED, System.currentTimeMillis(), 0, x, y, 1, false, left ? MouseEvent.BUTTON1 : MouseEvent.BUTTON3)
		);
		if ((getDragLength() & 0xFF) <= 3) {
			mouse.sendEvent(
					new MouseEvent(target, MouseEvent.MOUSE_CLICKED, System.currentTimeMillis(), 0, x, y, 1, false, left ? MouseEvent.BUTTON1 : MouseEvent.BUTTON3)
			);
		}
		putDragLength(0);
	}

	/**
	 * Returns the mouse associated with this thread-group to relay events to.
	 *
	 * @return The <code>org.powerbot.game.client.input.Mouse</code> to relay events to.
	 */
	private static org.powerbot.game.client.input.Mouse getMouse() {
		final Client client = Context.client();
		return client == null ? null : client.getMouse();
	}

	public static boolean isReady() {
		return getMouse() != null;
	}

	/**
	 * The component associated with this thread-group to dispatch events onto.
	 *
	 * @return The <code>Component</code> to dispatch events to.
	 */
	private static Component getTarget() {
		final Context context = Context.get();
		if (context.getApplet() == null || context.getApplet().getComponentCount() == 0) {
			return null;
		}
		return context.getApplet().getComponent(0);
	}

	private static int getDragLength() {
		Integer integer = dragLengths.get(Thread.currentThread().getThreadGroup());
		if (integer == null) {
			integer = 0;
			dragLengths.put(Thread.currentThread().getThreadGroup(), integer);
		}
		return integer;
	}

	private static void putDragLength(final int length) {
		dragLengths.put(Thread.currentThread().getThreadGroup(), length);
	}

	public static int getSide() {
		Integer integer = sides.get(Thread.currentThread().getThreadGroup());
		if (integer == null) {
			integer = 0;
			sides.put(Thread.currentThread().getThreadGroup(), integer);
		}
		return integer;
	}

	public static void putSide(final int side) {
		sides.put(Thread.currentThread().getThreadGroup(), side);
	}

	private static MouseNode create(final int x, final int y, final int randomX, final int randomY, final boolean click, final boolean left) {
		return new MouseNode(
				new ViewportEntity() {
					private final Rectangle area = new Rectangle(x - randomX, y - randomY, randomX * 2, randomY * 2);

					public Point getCentralPoint() {
						return new Point(x, y);
					}

					public Point getNextViewportPoint() {
						return new Point(x + Random.nextGaussian(-randomX, randomX, randomX), y + Random.nextGaussian(-randomY, randomY, randomY));
					}

					public boolean contains(final Point point) {
						return area.contains(point);
					}

					public boolean validate() {
						return Calculations.isOnScreen(x, y);
					}
				},
				new Filter<Point>() {
					public boolean accept(final Point point) {
						if (click) {
							Mouse.click(left);
						}
						return true;
					}
				}
		);
	}
}
