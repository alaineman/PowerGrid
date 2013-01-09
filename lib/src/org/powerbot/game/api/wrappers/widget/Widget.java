package org.powerbot.game.api.wrappers.widget;

import java.awt.Point;
import java.awt.Rectangle;
import java.util.Arrays;

import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSInterface;
import org.powerbot.game.client.RSInterfaceBase;

/**
 * @author Timer
 */
public class Widget implements Identifiable {
	private WidgetChild[] childCache = new WidgetChild[0];
	private final Object CACHE_LOCK = new Object();

	private final int index;

	public Widget(final int index) {
		this.index = index;
	}


	public boolean validate() {
		if (getChildrenInternal() == null) {
			return false;
		}
		final int idx = getIndex();
		final Client client = Context.client();
		final RSInterfaceBase[] inters = client.getRSInterfaceCache();
		if (idx < inters.length && inters[idx] != null) {
			final WidgetChild[] children = getChildren();
			int count = 0;
			for (final WidgetChild child : children) {
				if (child.getBoundsArrayIndex() == -1) {
					++count;
				}
			}
			return count != children.length;
		}
		return false;
	}

	public int getChildrenCount() {
		final Object[] children = getChildrenInternal();
		if (children != null) {
			return children.length;
		}
		return 0;
	}

	public String getText() {
		final StringBuilder sb = new StringBuilder();
		final Object[] children = getChildrenInternal();
		if (children != null) {
			for (final Object child : children) {
				String string;
				if (child != null && (string = ((RSInterface) child).getText()) != null) {
					sb.append(string);
					sb.append("\n");
				}
			}
		}
		if (sb.length() > 1) {
			sb.setLength(sb.length() - 1);
		}
		return sb.toString();
	}

	public int getIndex() {
		return index;
	}

	public int getId() {
		return index;
	}

	public Point getLocation() {
		final Client client = Context.client();
		final Object[] children = getChildrenInternal();
		if (children != null) {
			for (final Object child : children) {
				if (child != null) {
					final int index = ((RSInterface) child).getBoundsArrayIndex();
					final Rectangle[] boundsArray = client.getRSInterfaceBoundsArray();
					if (index > 0 && index < boundsArray.length) {
						return boundsArray[index].getLocation();
					}
				}
			}
		}
		return new Point(-1, -1);
	}

	public WidgetChild[] getChildren() {
		synchronized (CACHE_LOCK) {
			final Object[] children = getChildrenInternal();
			if (children == null) {
				return childCache.clone();
			} else {
				if (childCache.length < children.length) {
					final int prevLen = childCache.length;
					childCache = Arrays.copyOf(childCache, children.length);
					for (int i = prevLen; i < childCache.length; i++) {
						childCache[i] = new WidgetChild(this, i);
					}
				}
				return childCache.clone();
			}
		}
	}

	public WidgetChild getChild(final int index) {
		synchronized (CACHE_LOCK) {
			final RSInterface[] children = getChildrenInternal();
			final int ensureLen = Math.max(children != null ? children.length : 0, index + 1);
			if (childCache.length < ensureLen) {
				final int prevLen = childCache.length;
				childCache = Arrays.copyOf(childCache, ensureLen);
				for (int i = prevLen; i < ensureLen; i++) {
					childCache[i] = new WidgetChild(this, i);
				}
			}
			return childCache[index];
		}
	}

	@Override
	public boolean equals(final Object obj) {
		if (obj == this) {
			return true;
		}
		if (obj instanceof Widget) {
			final Widget inter = (Widget) obj;
			return inter.index == index;
		}
		return false;
	}

	@Override
	public int hashCode() {
		return getIndex();
	}

	RSInterface[] getChildrenInternal() {
		final Client client = Context.client();
		if (client == null) {
			return null;
		}
		final Object[] inters = client.getRSInterfaceCache();
		if (inters != null && index < inters.length && inters[index] != null) {
			final RSInterfaceBase base = (RSInterfaceBase) inters[index];
			return base.getComponents();
		}
		return null;
	}
}
