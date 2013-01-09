package org.powerbot.game.api.wrappers.widget;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Polygon;
import java.awt.Rectangle;

import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.methods.node.Menu;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.util.node.HashTable;
import org.powerbot.game.api.wrappers.Entity;
import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSInterface;
import org.powerbot.game.client.RSInterfaceNode;

/**
 * @author Timer
 */
public class WidgetChild implements Entity, Identifiable {
	/**
	 * The index of this interface in the parent. If this
	 * component does not have a parent component, this
	 * represents the index in the parent interface;
	 * otherwise this represents the component index in
	 * the parent component.
	 */
	private final int index;

	/**
	 * The parent interface containing this component.
	 */
	private final Widget parentWidget;

	/**
	 * The parent component
	 */
	private final WidgetChild parent;

	/**
	 * Initializes the component.
	 *
	 * @param parent The parent interface.
	 * @param index  The child index of this child.
	 */
	public WidgetChild(final Widget parent, final int index) {
		parentWidget = parent;
		this.index = index;
		this.parent = null;
	}

	/**
	 * Initializes the component.
	 *
	 * @param parentWidget    The parent interface.
	 * @param parentComponent The parent component.
	 * @param index           The child index of this child.
	 */
	public WidgetChild(final Widget parentWidget, final WidgetChild parentComponent, final int index) {
		this.parentWidget = parentWidget;
		this.parent = parentComponent;
		this.index = index;
	}

	/**
	 * Gets the parent widget of this component.  This component may be nested from its parent widget in parent components.
	 *
	 * @return The parent widget.
	 */
	public Widget getWidget() {
		return parentWidget;
	}

	/**
	 * Gets the parent component of this component, or null if this is a top-level component.
	 *
	 * @return The parent component, or null.
	 */
	public WidgetChild getParent() {
		return parent;
	}

	public int getIndex() {
		return index;
	}

	public int getAbsoluteX() {
		return getAbsoluteLocation().x;
	}

	public int getAbsoluteY() {
		return getAbsoluteLocation().y;
	}

	public Point getAbsoluteLocation() {
		if (getInternal() == null) {
			return new Point(-1, -1);
		}
		final Client client = Context.client();
		final int parentId = getParentId();
		int x = 0, y = 0;
		if (parentId != -1) {
			final Point point = Widgets.get(parentId >> 0x10, parentId & 0xffff).getAbsoluteLocation();
			x = point.x;
			y = point.y;
		} else {
			final Rectangle[] bounds = client.getRSInterfaceBoundsArray();
			final int index = getBoundsArrayIndex();
			if (bounds != null && index > 0 && index < bounds.length && bounds[index] != null) {
				return new Point(bounds[index].x, bounds[index].y);
			}
			//x = getMasterX();
			//y = getMasterY();
		}
		if (parentId != -1) {
			final WidgetChild child = Widgets.getChild(parentId);
			final int horizontalScrollSize = child.getScrollableContentWidth(), verticalScrollSize = child.getScrollableContentHeight();
			if (horizontalScrollSize > 0 || verticalScrollSize > 0) {
				x -= child.getHorizontalScrollPosition();
				y -= child.getVerticalScrollPosition();
			}
		}
		x += getRelativeX();
		y += getRelativeY();
		return new Point(x, y);
	}

	public int getRelativeX() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getX() : -1;
	}

	public int getRelativeY() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getY() : -1;
	}

	public Point getRelativeLocation() {
		final RSInterface widget = getInternal();
		if (widget == null) {
			return new Point(-1, -1);
		}
		return new Point(widget.getX(), widget.getY());
	}

	public int getWidth() {
		if (!isInScrollableArea()) {
			return getHorizontalScrollThumbSize();
		}
		final RSInterface widget = getInternal();
		return widget != null ? widget.getWidth() : -1;
	}

	public int getHeight() {
		if (!isInScrollableArea()) {
			return getVerticalScrollThumbSize();
		}
		final RSInterface widget = getInternal();
		return widget != null ? widget.getHeight() : -1;
	}

	public int getId() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getID() : -1;
	}

	public int getType() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getType() : -1;
	}

	public int getSpecialType() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getSpecialType() : -1;
	}

	public int getChildId() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getComponentID() : -1;
	}

	public int getChildIndex() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getComponentIndex() : -1;
	}

	public String getChildName() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getComponentName() : null;
	}

	public int getTextureId() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getTextureID() : -1;
	}

	public String getText() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getText() : null;
	}

	public int getTextColor() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getTextColor() : -1;
	}

	public int getShadowColor() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getShadowColor() : -1;
	}

	public String getTooltip() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getTooltip() : null;
	}

	public int getBorderThickness() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getBorderThinkness() : -1;
	}

	public String getSelectedAction() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getSelectedActionName() : null;
	}

	public int getModelId() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getModelID() : -1;
	}

	public int getModelType() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getModelType() : -1;
	}

	public int getModelZoom() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getModelZoom() : -1;
	}

	public boolean isInventory() {
		final RSInterface widget = getInternal();
		return widget != null && widget.isInventoryInterface();
	}

	public int getChildStackSize() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getComponentStackSize() : -1;
	}

	public int getXRotation() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getXRotation() : -1;
	}

	public int getYRotation() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getYRotation() : -1;
	}

	public int getZRotation() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getZRotation() : -1;
	}

	public String[] getActions() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getActions() : null;
	}

	public boolean isHorizontallyFlipped() {
		final RSInterface widget = getInternal();
		return widget != null && widget.isHorizontallyFlipped();
	}

	public boolean isVerticallyFlipped() {
		final RSInterface widget = getInternal();
		return widget != null && widget.isVerticallyFlipped();
	}

	public int getHorizontalScrollPosition() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getHorizontalScrollbarPosition() : -1;
	}

	public int getScrollableContentWidth() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getHorizontalScrollbarSize() : -1;
	}

	public int getHorizontalScrollThumbSize() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getHorizontalScrollbarThumbSize() : -1;
	}

	public int getVerticalScrollPosition() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getVerticalScrollbarPosition() : -1;
	}

	public int getScrollableContentHeight() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getVerticalScrollbarSize() : -1;
	}

	public int getVerticalScrollThumbSize() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getVerticalScrollbarThumbSize() : -1;
	}

	public int getBoundsArrayIndex() {
		final RSInterface widget = getInternal();
		return widget != null ? widget.getBoundsArrayIndex() : -1;
	}

	public WidgetChild[] getChildren() {
		final RSInterface inter = getInternal();
		if (inter != null) {
			final RSInterface[] interfaceComponents = inter.getComponents();
			if (interfaceComponents != null) {
				final WidgetChild[] components = new WidgetChild[interfaceComponents.length];
				for (int i = 0; i < components.length; i++) {
					components[i] = new WidgetChild(parentWidget, this, i);
				}
				return components;
			}
		}
		return new WidgetChild[0];
	}

	public WidgetChild getChild(final int index) {
		final WidgetChild[] children = getChildren();
		if (index >= 0 && index < children.length) {
			return children[index];
		}
		return null;
	}

	public boolean visible() {
		final RSInterface inter = getInternal();
		if (inter == null || inter.isHidden()) {
			return false;
		}
		if (inter.isVisible()) {
			return true;
		}
		if (getParentId() != -1) {
			return Widgets.getChild(getParentId()).visible();
		}
		return validate();
	}

	@Override
	public int hashCode() {
		return parentWidget.getIndex() * 0x1f + index;
	}

	@Override
	public boolean equals(final Object obj) {
		if (obj == this) {
			return true;
		}
		if (obj instanceof WidgetChild) {
			final WidgetChild child = (WidgetChild) obj;
			return index == child.index && child.parentWidget.equals(parentWidget);
		}
		return false;
	}


	public int getParentId() {
		final RSInterface inter = getInternal();
		if (inter == null) {
			return -1;
		}
		final Client client = Context.client();

		final int parentId = inter.getParentID();

		if (parentId != -1) {
			return parentId;
		}

		final int mainID = getId() >>> 0x10;
		final HashTable ncI = new HashTable(client.getRSInterfaceNC());
		for (RSInterfaceNode node = (RSInterfaceNode) ncI.getFirst(); node != null; node = (RSInterfaceNode) ncI.getNext()) {
			if (mainID == node.getMainID()) {
				return (int) node.getId();
			}
		}

		return -1;
	}

	public boolean isInScrollableArea() {
		if (getParentId() == -1) {
			return false;
		}

		WidgetChild scrollableArea = Widgets.getChild(getParentId());
		while (scrollableArea.getScrollableContentHeight() == 0 && scrollableArea.getParentId() != -1) {
			scrollableArea = Widgets.getChild(scrollableArea.getParentId());
		}

		int scrollableContentHeight = scrollableArea.getScrollableContentHeight();
		return scrollableContentHeight != 0;
	}


	private RSInterface getInternal() {
		if (parent != null) {
			final RSInterface p = parent.getInternal();
			if (p != null) {
				final RSInterface[] components = p.getComponents();
				if (components != null && index >= 0 && index < components.length) {
					return components[index];
				}
			}
		} else {
			final RSInterface[] children = parentWidget.getChildrenInternal();
			if (children != null && index < children.length) {
				return children[index];
			}
		}
		return null;
	}

	public boolean isOnScreen() {
		return validate() && visible();
	}

	public Polygon[] getBounds() {
		if (validate()) {
			final Point p = getAbsoluteLocation();
			final int w = getWidth();
			final int h = getHeight();
			final Polygon poly = new Polygon();
			poly.addPoint(p.x, p.y);
			poly.addPoint(p.x + w, p.y);
			poly.addPoint(p.x + w, p.y + h);
			poly.addPoint(p.x, p.y + h);
			return new Polygon[]{poly};
		}
		return new Polygon[0];
	}

	public Rectangle getBoundingRectangle() {
		if (validate()) {
			final Point p = getAbsoluteLocation();
			final int w = getWidth();
			final int h = getHeight();
			return new Rectangle(p.x, p.y, w, h);
		}
		return new Rectangle(-1, -1);
	}

	public boolean hover() {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return true;
			}
		});
	}

	public boolean click(final boolean left) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				Mouse.click(left);
				return true;
			}
		});
	}

	public boolean interact(final String action) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return Menu.select(action);
			}
		});
	}

	public boolean interact(final String action, final String option) {
		return Mouse.apply(this, new Filter<Point>() {
			public boolean accept(final Point point) {
				return Menu.select(action, option);
			}
		});
	}

	public void draw(final Graphics render) {
		final Polygon[] p = getBounds();
		if (p.length == 1) {
			render.drawPolygon(p[0]);
		}
	}

	public Point getCentralPoint() {
		final Point p = getAbsoluteLocation();
		final int w = getWidth();
		final int h = getHeight();
		return validate() ? new Point((p.x * 2 + w) / 2, (p.y * 2 + h) / 2) : new Point(-1, -1);
	}

	public Point getNextViewportPoint() {
		final Rectangle rect = getBoundingRectangle();
		if (rect.x == -1 || rect.y == -1 || rect.width == -1 || rect.height == -1) {
			return new Point(-1, -1);
		}
		final int min_x = rect.x + 1, min_y = rect.y + 1;
		final int max_x = min_x + rect.width - 2, max_y = min_y + rect.height - 2;
		return new Point(Random.nextGaussian(min_x, max_x, rect.width / 3), Random.nextGaussian(min_y, max_y, rect.height / 3));
	}

	public boolean contains(final Point point) {
		final Rectangle rect = getBoundingRectangle();
		if (rect.x == -1 || rect.y == -1 || rect.width == -1 || rect.height == -1) {
			return false;
		}
		final int min_x = rect.x + 1, min_y = rect.y + 1;
		final int max_x = min_x + rect.width - 2, max_y = min_y + rect.height - 2;
		return (point.x >= min_x) && (point.x <= max_x) && (point.y >= min_y) && (point.y <= max_y);
	}

	public boolean validate() {
		return parentWidget.validate() && getBoundsArrayIndex() != -1;
	}
}
