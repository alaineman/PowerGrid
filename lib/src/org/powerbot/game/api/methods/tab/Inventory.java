package org.powerbot.game.api.methods.tab;

import java.awt.Rectangle;
import java.util.LinkedList;
import java.util.List;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Tabs;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.input.Mouse;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.wrappers.node.Item;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

public class Inventory {

	public static final int WIDGET = 679;
	public static final int WIDGET_BANK = 763;
	public static final int WIDGET_PRICE_CHECK = 204;
	public static final int WIDGET_EQUIPMENT_BONUSES = 670;
	public static final int WIDGET_EXCHANGE = 644;
	public static final int WIDGET_SHOP = 621;
	public static final int WIDGET_DUNGEONEERING_SHOP = 957;
	public static final int WIDGET_BEAST_OF_BURDEN_STORAGE = 665;
	public static final int WIDGET_STORE = 1266;
	public static final int WIDGET_SAWMILL_CART = 771;

	public static final int[] ALT_WIDGETS = {
			WIDGET_BANK,
			WIDGET_PRICE_CHECK, WIDGET_EQUIPMENT_BONUSES,
			WIDGET_EXCHANGE, WIDGET_SHOP, WIDGET_DUNGEONEERING_SHOP,
			WIDGET_BEAST_OF_BURDEN_STORAGE, WIDGET_STORE, WIDGET_SAWMILL_CART
	};

	/**
	 * Default filter. It accepts all items.
	 */
	public static final Filter<Item> ALL_FILTER = new Filter<Item>() {
		public boolean accept(final Item item) {
			return true;
		}
	};

	/**
	 * Checks whether the inventory contains an item whose id matches with any of the provided ids.
	 *
	 * @param ids the ids to look for
	 * @return <tt>true</tt> if the inventory contains an item whose id matches with any of the provided ids; otherwise <tt>false</tt>
	 */
	public static boolean contains(final int... ids) {
		return getCount(false, ids) > 0;
	}

	/**
	 * @deprecated use {@link #contains(int...)}
	 */
	public static boolean contains(final int id) {
		return contains(new int[]{id});
	}

	/**
	 * Checks whether the inventory contains all of the provided item ids.
	 *
	 * @param ids the ids to look for
	 * @return <tt>true</tt> if the inventory contains all of the provided item ids; otherwise <tt>false</tt>
	 */
	public static boolean containsAll(final int... ids) {
		for (final int id : ids) {
			if (getItem(id) == null) {
				return false;
			}
		}
		return true;
	}

	/**
	 * @deprecated use {@link #contains(int...)}
	 */
	public static boolean containsOneOf(final int... ids) {
		return contains(ids);
	}

	/**
	 * Drags the inventory item whose id matches with the provided id to the specified inventory slot.
	 *
	 * @param itemId the id of the item to drag
	 * @param slot   the inventory slot
	 */
	public static void dragItem(final int itemId, final int slot) {
		dragItem(getItem(itemId), slot);
	}

	/**
	 * Drags the provided inventory item to the specified inventory slot.
	 *
	 * @param item the inventory item to drag
	 * @param slot the inventory slot
	 */
	public static void dragItem(final Item item, final int slot) {
		if (item != null) {
			if (slot >= 0 && slot <= 27) {
				if (isItemSelected()) {
					if (!selectItem(null)) {
						return;
					}
				}
				WidgetChild componentSlot = getWidget(false).getChild(slot);
				if (componentSlot == null) {
					return;
				}
				Rectangle componentRectangle = componentSlot.getBoundingRectangle();
				Rectangle itemRectangle = item.getWidgetChild().getBoundingRectangle();
				if (componentRectangle.contains(itemRectangle)) {
					return;
				}
				Mouse.move(item.getWidgetChild().getNextViewportPoint());
				Mouse.drag(componentSlot.getNextViewportPoint());
			}
		}
	}

	/**
	 * Gets all the inventory items.
	 * This includes null items (empty inventory slot) and, thus, the array returned by this method will always have a size of 28.
	 *
	 * @param useCache <tt>true</tt> to get a cached version of the inventory items; otherwise <tt>false</tt>
	 * @return an array of <code>Item</code>
	 */
	public static Item[] getAllItems(final boolean useCache) {
		final Item[] items = new Item[28];
		final WidgetChild widget = getWidget(useCache);
		if (widget != null) {
			final WidgetChild[] children = widget.getChildren();
			if (children.length >= items.length) {
				for (int i = 0; i < items.length; i++) {
					final WidgetChild child = children[i];
					items[i] = child == null || child.getChildId() == -1 ? null : new Item(child);
				}
			}
		}
		return items;
	}

	/**
	 * Gets the count of all inventory items ignoring stack sizes.
	 *
	 * @return the count of all inventory items ignoring stack sizes
	 * @see #getCount(boolean)
	 * @see #getCount(boolean, org.powerbot.game.api.util.Filter)
	 */
	public static int getCount() {
		return getItems().length;
	}

	/**
	 * Gets the count of all inventory items.
	 *
	 * @param includeStacks <tt>true</tt> to include stack sizes; otherwise <tt>false</tt>
	 * @return the count of all inventory items
	 * @see #getCount(boolean, org.powerbot.game.api.util.Filter)
	 */
	public static int getCount(final boolean includeStacks) {
		return getCount(includeStacks, ALL_FILTER);
	}

	/**
	 * Gets the count of all inventory items that are accepted by the provided filter. Stack sizes are ignored.
	 *
	 * @param filter the filter to use
	 * @return the count of inventory items accepted by the filter
	 * @see #getCount(boolean, org.powerbot.game.api.util.Filter)
	 */
	public static int getCount(final Filter<Item> filter) {
		return getCount(false, filter);
	}

	/**
	 * Gets the count of inventory items whose id matches with any of the provided ids. This ignores stack sizes.
	 *
	 * @param ids the ids to look for
	 * @return the count of inventory items whose id matches with any of the provided ids ignoring stack sizes
	 * @see #getCount(boolean, int...)
	 */
	public static int getCount(final int... ids) {
		return getCount(false, ids);
	}

	/**
	 * Gets the count of inventory items whose id matches with any of the provided ids.
	 *
	 * @param includeStacks <tt>true</tt> to include stack sizes; otherwise <tt>false</tt>
	 * @param ids           the ids to look for
	 * @return the count of inventory items whose id matches with any of the provided ids
	 */
	public static int getCount(final boolean includeStacks, final int... ids) {
		return getCount(includeStacks, new Filter<Item>() {
			public boolean accept(final Item item) {
				for (final int id : ids) {
					if (item.getId() == id) {
						return true;
					}
				}
				return false;
			}
		});
	}

	/**
	 * Gets the count of all inventory items accepted by the provided filter.
	 *
	 * @param includeStacks <tt>true</tt> to include stack sizes; otherwise <tt>false</tt>
	 * @param filter        the filter to use
	 * @return the count of inventory items accepted by the filter
	 */
	public static int getCount(final boolean includeStacks, final Filter<Item> filter) {
		int count = 0;
		for (Item item : getItems(filter)) {
			count += includeStacks ? item.getStackSize() : 1;
		}
		return count;
	}

	/**
	 * Gets the first inventory item whose id matches with any of the provided ids.
	 *
	 * @param ids the item ids to look for
	 * @return an <code>Item</code> or <code>null</code>
	 * @see #getItem(org.powerbot.game.api.util.Filter)
	 */
	public static Item getItem(final int... ids) {
		final Item[] items = getItems(false);
		for (final Item item : items) {
			final int itemId = item.getId();
			for (final int id : ids) {
				if (itemId == id) {
					return item;
				}
			}
		}
		return null;
	}

	/**
	 * Gets the first inventory item that is accepted by the provided filter.
	 *
	 * @param filter the filter to use
	 * @return an <code>Item</code> or <code>null</code>
	 */
	public static Item getItem(final Filter<Item> filter) {
		final Item[] items = getItems(false);
		for (final Item item : items) {
			if (filter.accept(item)) {
				return item;
			}
		}
		return null;
	}

	/**
	 * Gets the item at the specified index.
	 *
	 * @param index the index
	 * @return the <code>Item</code> at the specified index; otherwise <code>null</code>
	 * @throws IndexOutOfBoundsException if index is too big
	 */
	public static Item getItemAt(final int index) {
		return getAllItems(false)[index];
	}

	/**
	 * Gets all inventory items.
	 *
	 * @return an array of <code>Item</code>
	 * @see #getItems(boolean)
	 * @see #getItems(org.powerbot.game.api.util.Filter)
	 * @see #getItems(boolean, org.powerbot.game.api.util.Filter)
	 */
	public static Item[] getItems() {
		return getItems(false);
	}

	/**
	 * Gets all inventory items.
	 *
	 * @param useCache <tt>true</tt> to get a cached version of the inventory items; otherwise <tt>false</tt>
	 * @return an array of <code>Item</code>
	 * @see #getItems(boolean, org.powerbot.game.api.util.Filter)
	 */
	public static Item[] getItems(final boolean useCache) {
		return getItems(useCache, ALL_FILTER);
	}

	/**
	 * Gets all inventory items that are accepted by the provided filter.
	 *
	 * @param filter the filter to use
	 * @return an array of <code>Item</code>
	 * @see #getItems(boolean, org.powerbot.game.api.util.Filter)
	 */
	public static Item[] getItems(final Filter<Item> filter) {
		return getItems(false, filter);
	}

	/**
	 * Gets all inventory items that are accepted by the provided filter.
	 *
	 * @param useCache <tt>true</tt> to get a cached version of the inventory items; otherwise <tt>false</tt>
	 * @param filter   the filter to use
	 * @return an array of <code>Item</code>
	 */
	public static Item[] getItems(final boolean useCache, final Filter<Item> filter) {
		final WidgetChild widget = getWidget(useCache);
		if (widget != null) {
			final WidgetChild[] children = widget.getChildren();
			if (children.length > 27) {
				final List<Item> items = new LinkedList<>();
				for (int i = 0; i < 28; ++i) {
					WidgetChild child = children[i];
					if (child.getChildId() != -1) {
						final Item item = new Item(child);
						if (filter.accept(item)) {
							items.add(item);
						}
					}
				}
				return items.toArray(new Item[items.size()]);
			}
		}
		return new Item[0];
	}

	/**
	 * Gets the inventory item that is currently selected.
	 *
	 * @return the <code>Item</code> currently selected; otherwise <tt>false</tt>
	 */
	public static Item getSelectedItem() {
		final int index = getSelectedItemIndex();
		return index == -1 ? null : getItemAt(index);
	}

	/**
	 * Gets the index of the inventory item currently selected.
	 *
	 * @return the index of the inventory item currently selected or -1
	 */
	public static int getSelectedItemIndex() {
		final Item[] items = getAllItems(false);
		for (int i = 0; i < items.length; i++) {
			Item item = items[i];
			if (item == null) {
				continue;
			} else if (item.getWidgetChild().getBorderThickness() == 2) {
				return i;
			}
		}
		return -1;
	}

	/**
	 * Gets the respective widget representing the inventory.
	 *
	 * @param useCache <tt>true</tt> to get cached version of the widget; otherwise <tt>false</tt>
	 * @return a <code>WidgetChild</code>
	 */
	public static WidgetChild getWidget(final boolean useCache) {
		for (final int widget : ALT_WIDGETS) {
			WidgetChild inventory = Widgets.get(widget, 0);
			if (inventory != null && inventory.getAbsoluteX() > 50) {
				return inventory;
			}
		}
		if (!useCache) {
			Tabs.INVENTORY.open(false);
		}
		return Widgets.get(WIDGET, 0);
	}

	/**
	 * Returns the index of the first occurrence of an inventory item whose id matches with any of the provided ids.
	 *
	 * @param ids the ids to look for
	 * @return the index of the first occurrence of an inventory item whose id matches with any of the provided ids or -1
	 * @see #indexOf(boolean, int...)
	 */
	public static int indexOf(final int... ids) {
		return indexOf(false, ids);
	}

	/**
	 * Returns the index of the first occurrence of an inventory item whose id matches with any of the provided ids.
	 *
	 * @param useCache <tt>true</tt> to get a cached version of the inventory items; otherwise <tt>false</tt>
	 * @param ids      the ids to look for
	 * @return the index of the first occurrence of an inventory item whose id matches with any of the provided ids or -1
	 */
	public static int indexOf(final boolean useCache, final int... ids) {
		final Item[] items = getAllItems(useCache);
		for (int i = 0; i < items.length; i++) {
			final Item item = items[i];
			if (item == null) {
				continue;
			}
			int itemId = item.getId();
			for (int id : ids) {
				if (itemId == id) {
					return i;
				}
			}
		}
		return -1;
	}

	/**
	 * Returns the index of the first occurrence of an inventory item whose name matches with the provided item name.
	 *
	 * @param name the item name
	 * @return the index of the first occurrence of an inventory item whose name matches with the provided item name or -1
	 */
	public static int indexOf(final String name) {
		return indexOf(false, name);
	}

	/**
	 * Returns the index of the first occurrence of an inventory item whose name matches with the provided item name.
	 *
	 * @param useCache <tt>true</tt> to get a cached version of inventory items; otherwise <tt>false</tt>
	 * @param name     the item name
	 * @return the index of the first occurrence of an inventory item whose name matches with the provided item name or -1
	 */
	public static int indexOf(final boolean useCache, final String name) {
		if (name != null && !name.isEmpty()) {
			final Item[] items = getAllItems(useCache);
			for (int i = 0; i < items.length; i++) {
				final Item item = items[i];
				if (item == null) {
					continue;
				} else if (name.equalsIgnoreCase(item.getName())) {
					return i;
				}
			}
		}
		return -1;
	}

	/**
	 * Checks whether the inventory is full. This means that each inventory slot must contain an item.
	 *
	 * @return <tt>true</tt> if the inventory is full; otherwise <tt>false</tt>
	 */
	public static boolean isFull() {
		return getCount() == 28;
	}

	/**
	 * Checks whether there is an inventory item currently selected.
	 *
	 * @return <tt>true</tt> if there is an inventory item currently selected; otherwise <tt>false</tt>
	 */
	public static boolean isItemSelected() {
		return getSelectedItemIndex() != -1;
	}

	/**
	 * Selects the inventory item whose id matches with the provided id.
	 * If there is no inventory item with an id of <code>itemId</code>,
	 * then this method will only deselect the item that is currently selected.
	 *
	 * @param itemId the item id to look for
	 * @return <tt>true</tt> if selected; otherwise <tt>false</tt>
	 * @see #selectItem(org.powerbot.game.api.wrappers.node.Item)
	 */
	public static boolean selectItem(final int itemId) {
		return selectItem(getItem(itemId));
	}

	/**
	 * Selects the specified inventory item.
	 * If <code>item</code> is null, then this method will only deselect the item that is currently selected.
	 *
	 * @param item the inventory item to select
	 * @return <tt>true</tt> if selected; otherwise <tt>false</tt>
	 */
	public static boolean selectItem(final Item item) {
		final Item selectedItem = getSelectedItem();
		if (selectedItem != null) {
			if (selectedItem.equals(item)) {
				return true;
			}
			selectedItem.getWidgetChild().interact("Use");
			Task.sleep(500, 700);
			if (getSelectedItem() != null) {
				// Somehow, we couldn't deselect the item.
				return false;
			}
		}
		if (item == null) {
			return true;
		}
		item.getWidgetChild().interact("Use");
		Task.sleep(500, 700);
		return item.equals(getSelectedItem());
	}

}
