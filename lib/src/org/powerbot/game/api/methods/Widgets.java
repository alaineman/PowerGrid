package org.powerbot.game.api.methods;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;

/**
 * A utility for the manipulation of widgets.
 *
 * @author Timer
 */
public class Widgets {
	private static final Map<Client, Widget[]> caches = new HashMap<Client, Widget[]>();

	/**
	 * @return An <code>Widget[]</code> of the latest cached widgets.
	 */
	public static Widget[] getLoaded() {
		final Client client = Context.client();
		if (client == null) {
			return new Widget[0];
		}
		ensureCapacity(client);
		final Object[] clientInterfaceCache = client.getRSInterfaceCache();
		if (clientInterfaceCache == null) {
			return new Widget[0];
		}
		final ArrayList<Widget> validInterfaces = new ArrayList<Widget>();
		for (int index = 0; index < clientInterfaceCache.length; index++) {
			if (clientInterfaceCache[index] != null) {
				final Widget widget = get(index);
				if (widget.validate()) {
					validInterfaces.add(widget);
				}
			}
		}
		return validInterfaces.toArray(new Widget[validInterfaces.size()]);
	}

	/**
	 * @param index The position in the widget cache.
	 * @return The <code>Widget</code> retrieved from the cache.
	 */
	public static Widget get(final int index) {
		if (index < 0) {
			throw new RuntimeException("index < 0 (" + index + ")");
		}

		final Client client = Context.client();
		Widget[] cachedInterfaces = caches.get(client);
		if (cachedInterfaces == null) {
			cachedInterfaces = new Widget[100];
			caches.put(client, cachedInterfaces);
		}
		Widget widget;
		if (index < cachedInterfaces.length) {
			widget = cachedInterfaces[index];
			if (widget == null) {
				widget = new Widget(index);
				cachedInterfaces[index] = widget;
			}
		} else {
			widget = new Widget(index);
			ensureCapacity(client);
			cachedInterfaces = caches.get(client);
			if (index < cachedInterfaces.length) {
				cachedInterfaces[index] = widget;
			}
		}
		return widget;
	}

	/**
	 * @param index      The position in the widget cache.
	 * @param childIndex The position of the widget child in the children array of the cached widget.
	 * @return The <code>WidgetChild</code> retrieved from the children of the cached widget.
	 */
	public static WidgetChild get(final int index, final int childIndex) {
		return get(index).getChild(childIndex);
	}

	public static WidgetChild getChild(final int id) {
		final int x = id >> 0x10;
		final int y = id & 0xffff;
		return get(x).getChild(y);
	}

	public static WidgetChild getContinue() {
		WidgetChild button = get(752, 5);
		if (button != null && button.validate() && button.getTextColor() == 128 && button.getRelativeX() == 0) {
			return button;
		}
		button = get(1184, 18);
		if (button != null && button.validate()) {
			return button;
		}
		button = get(1186, 8);
		if (button != null && button.validate()) {
			return button;
		}
		button = get(1191, 18);
		if (button != null && button.validate()) {
			return button;
		}
		return null;
	}

	public static boolean canContinue() {
		return getContinue() != null;
	}

	public static boolean clickContinue() {
		final WidgetChild widgetChild = getContinue();
		return widgetChild != null && widgetChild.click(true);
	}

	public static boolean scroll(final WidgetChild component, final WidgetChild scrollBar) {
		if (component == null || scrollBar == null || !component.validate() || scrollBar.getChildren().length != 6) {
			return true;
		}

		WidgetChild scrollableArea = component;
		while (scrollableArea.getScrollableContentHeight() == 0 && scrollableArea.getParentId() != -1) {
			scrollableArea = getChild(scrollableArea.getParentId());
		}

		if (scrollableArea.getScrollableContentHeight() == 0) {
			return false;
		}

		final int areaY = scrollableArea.getAbsoluteY();
		final int areaHeight = scrollableArea.getHeight();

		if (component.getAbsoluteY() >= areaY && component.getAbsoluteY() <= areaY + areaHeight - component.getHeight()) {
			return true;
		}

		final WidgetChild scrollBarArea = scrollBar.getChildren()[0];
		final int contentHeight = scrollableArea.getScrollableContentHeight();

		int pos = (int) ((float) scrollBarArea.getHeight() / contentHeight * (component.getRelativeY() + Random.nextInt(-areaHeight / 2, areaHeight / 2 - component.getHeight())));
		if (pos < 0) {
			pos = 0;
		} else if (pos >= scrollBarArea.getHeight()) {
			pos = scrollBarArea.getHeight() - 1;
		}

		Mouse.click(scrollBarArea.getAbsoluteX() + Random.nextInt(0, scrollBarArea.getWidth()), scrollBarArea.getAbsoluteY() + pos, true);

		Task.sleep(Random.nextInt(200, 400));

		while (component.getAbsoluteY() < areaY || component.getAbsoluteY() > areaY + areaHeight - component.getHeight()) {
			final boolean scrollUp = component.getAbsoluteY() < areaY;
			scrollBar.getChildren()[scrollUp ? 4 : 5].click(true);

			Task.sleep(Random.nextInt(100, 200));
		}

		return component.getAbsoluteY() >= areaY && component.getAbsoluteY() <= areaY + areaHeight - component.getHeight();
	}

	/**
	 * @param client The <code>Client</code> to ensure caching capacity of.
	 */
	private static void ensureCapacity(final Client client) {
		if (client == null) {
			return;
		}
		final Object[] clientInterfaceCache = client.getRSInterfaceCache();
		Widget[] cachedInterfaces = caches.get(client);
		if (cachedInterfaces == null) {
			cachedInterfaces = new Widget[100];
			caches.put(client, cachedInterfaces);
		}
		if ((clientInterfaceCache != null) && (cachedInterfaces.length < clientInterfaceCache.length)) {
			caches.put(client, Arrays.copyOf(cachedInterfaces, clientInterfaceCache.length));
		}
	}
}
