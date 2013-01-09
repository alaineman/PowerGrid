package org.powerbot.game.api.wrappers.node;

import org.powerbot.game.api.util.node.Nodes;
import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.HardReference;
import org.powerbot.game.client.Node;
import org.powerbot.game.client.RSItem;
import org.powerbot.game.client.SoftReference;

/**
 * Represents an item (with an id and stack size).
 * May or may not wrap a component.
 *
 * @author Timer
 */
public class Item implements Identifiable {
	private final int id;
	private final int stack;
	private WidgetChild widgetChild;

	public Item(final int id, final int stack) {
		this.id = id;
		this.stack = stack;
	}

	public Item(final RSItem item) {
		id = item.getId();
		stack = item.getStackSize();
	}

	public Item(final WidgetChild widgetChild) {
		id = widgetChild.getChildId();
		stack = widgetChild.getChildStackSize();
		this.widgetChild = new WidgetChild_Item(widgetChild);
	}

	public int getId() {
		return id;
	}

	public int getStackSize() {
		return stack;
	}

	public String getName() {
		if (widgetChild != null) {
			return widgetChild.getChildName().replaceAll("\\<.*?>", "");
		} else {
			final ItemDefinition definition = getDefinition();
			if (definition != null) {
				return definition.getName().replaceAll("\\<.*?>", "");
			}
		}
		return null;
	}

	public ItemDefinition getDefinition() {
		try {
			final Node ref = Nodes.lookup(Context.client().getRSItemDefLoader().getCache().getTable(), id);
			if (ref != null) {
				if (ref instanceof HardReference) {
					return new ItemDefinition((org.powerbot.game.client.RSItemDef) ((HardReference) ref).get());
				} else if (ref instanceof SoftReference) {
					final Object def = ((java.lang.ref.SoftReference<?>) ((SoftReference) ref).get()).get();

					if (def != null) {
						return new ItemDefinition((org.powerbot.game.client.RSItemDef) def);
					}
				}
			}
			return null;
		} catch (final ClassCastException | AbstractMethodError e) {
			return null;
		}
	}

	public WidgetChild getWidgetChild() {
		return widgetChild;
	}

	@Override
	public boolean equals(final Object o) {
		if (o instanceof Item) {
			final Item item = (Item) o;
			if (item.getId() == id && item.getStackSize() == stack) {
				return !(widgetChild != null && item.getWidgetChild() != null) || widgetChild.equals(item.getWidgetChild());
			}
		}
		return false;
	}

	private final class WidgetChild_Item extends WidgetChild {
		public WidgetChild_Item(final WidgetChild original) {
			super(original.getWidget(), original.getParent(), original.getIndex());
		}

		@Override
		public boolean validate() {
			return super.validate() && widgetChild.getChildId() != -1;
		}
	}
}
