package org.powerbot.game.api.methods.tab;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Tabs;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.widget.Bank;
import org.powerbot.game.api.wrappers.node.Item;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

public class Equipment {
	public static final int WIDGET = 387;
	public static final int WIDGET_BANK = 667;
	public static final int COMPONENT_EQUIP_INVENTORY = 9;

	public static final int NUM_APPEARANCE_SLOTS = 9;
	public static final int NUM_SLOTS = 13;

	public static enum Slot {
		HELMET(7, 0, 0, -1),
		CAPE(10, 1, 1, -1),
		NECK(13, 2, 2, -1),
		WEAPON(16, 3, 3, 15),
		BODY(19, 4, 4, -1),
		SHIELD(22, 5, 5, 16),
		LEGS(25, 7, 7, -1),
		HANDS(28, 9, 9, -1),
		FEET(31, 10, 10, -1),
		RING(34, 12, -1, -1),
		AMMO(39, 13, -1, -1),
		AURA(48, 14, 14, -1),
		POCKET(70, 15, -1, -1);

		private final int componentIndex;
		private final int bankComponentIndex;
		private final int appearanceIndex;
		private final int sheathedAppearanceIndex;

		Slot(final int componentIndex, final int bankComponentIndex, final int appearanceIndex, final int sheathedAppearanceIndex) {
			this.componentIndex = componentIndex;
			this.bankComponentIndex = bankComponentIndex;
			this.appearanceIndex = appearanceIndex;
			this.sheathedAppearanceIndex = sheathedAppearanceIndex;
		}

		/**
		 * Gets the component index of the slot
		 *
		 * @return the index of the slot for either the bank or the regular Equipment tab
		 */
		public int getIndex() {
			return getIndex(Bank.isOpen());
		}

		/**
		 * Gets the component index of the slot
		 *
		 * @param bank <tt>true</tt> to get component index of bank equipment component otherwise <tt>false</tt> for regular index
		 * @return the index of the slot based on the bank parameter
		 */
		public int getIndex(final boolean bank) {
			return bank ? getBankComponentIndex() : getComponentIndex();
		}

		/**
		 * Gets the regular component index of the slot
		 *
		 * @return the regular component index
		 */
		public int getComponentIndex() {
			return componentIndex;
		}

		/**
		 * Gets the bank component index of the slot
		 *
		 * @return the bank component index
		 */
		public int getBankComponentIndex() {
			return bankComponentIndex;
		}

		/**
		 * Gets the visible equipment index of the slot
		 *
		 * @return the visible equipment index
		 */
		public int getAppearanceIndex() {
			return appearanceIndex;
		}

		/**
		 * Gets the sheathed visible equipment index of the slot
		 *
		 * @return the sheathed visible equipment index
		 */
		public int getSheathedAppearanceIndex() {
			return sheathedAppearanceIndex;
		}
	}

	/**
	 * Checks whether all of the provided item ids are visibly equipped items.
	 *
	 * @param itemIds the item ids to look for
	 * @return <tt>true</tt> if all of the provided item ids are visible items; otherwise <tt>false</tt>
	 * @see #appearanceContainsOneOf(int...)
	 */
	public static boolean appearanceContainsAll(final int... itemIds) {
		final int[] visibleEquipment = getAppearanceIds();
		for (final int id : itemIds) {
			boolean hasItem = false;
			for (final int i : visibleEquipment) {
				if (i == id) {
					hasItem = true;
					break;
				}
			}
			if (!hasItem) {
				return false;
			}
		}
		return true;
	}

	/**
	 * Checks whether one of the provided item ids is a visibly equipped item.
	 *
	 * @param itemIds the item ids to check for
	 * @return <tt>true</tt> if one of the provided items is visibly equipped; otherwise <tt>false</tt>
	 * @see #appearanceContainsAll(int...)
	 */
	public static boolean appearanceContainsOneOf(final int... itemIds) {
		for (final int id : getAppearanceIds()) {
			for (final int i : itemIds) {
				if (i == id) {
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * Checks whether all of the provided item ids are equipped items.
	 *
	 * @param itemIds the item ids to look for
	 * @return <tt>true</tt> if all of the provided item ids are equipped items; otherwise <tt>false</tt>
	 * @see #containsOneOf(int...)
	 */
	public static boolean containsAll(final int... itemIds) {
		final Item[] items = getItems();
		for (final Item item : items) {
			if (item == null) {
				continue;
			}
			boolean hasItem = false;
			final int itemId = item.getId();
			for (final int id : itemIds) {
				if (itemId == id) {
					hasItem = true;
					break;
				}
			}
			if (!hasItem) {
				return false;
			}
		}
		return true;
	}

	/**
	 * Checks whether one of the provided item ids is an equipped item.
	 *
	 * @param itemIds the item ids to check for
	 * @return <tt>true</tt> if one of the provided items is an equipped item; otherwise <tt>false</tt>
	 * @see #containsAll(int...)
	 */
	public static boolean containsOneOf(final int... itemIds) {
		for (final Item item : getItems()) {
			final int itemId = item.getId();
			for (final int id : itemIds) {
				if (itemId == id) {
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * Gets the visibly equipped item id at the given slot.
	 *
	 * @param slot the <code>Slot</code> of the item
	 * @return the item id at the specified <code>Slot</code>; otherwise <code>-1</code> if not visible
	 */
	public static int getAppearanceId(final Slot slot) {
		if (slot.getAppearanceIndex() == -1) {
			return -1;
		}
		final int[] visibleEquipment = Players.getLocal().getAppearance();
		int slotId = visibleEquipment[slot.getAppearanceIndex()];
		if (slotId <= 0 && slot.getSheathedAppearanceIndex() != -1) {
			slotId = visibleEquipment[slot.getSheathedAppearanceIndex()];
		}
		return slotId > 0 ? slotId : -1;
	}

	/**
	 * Gets all the visibly equipped items.
	 *
	 * @return an array instance of integers representing the local player's visible equipment.
	 */
	public static int[] getAppearanceIds() {
		final int[] equipmentIds = new int[NUM_APPEARANCE_SLOTS];
		final int[] visibleEquipment = Players.getLocal().getAppearance();
		final Slot[] slots = Slot.values();
		for (int i = 0; i < equipmentIds.length; i++) {
			final int index = visibleEquipment[slots[i].getAppearanceIndex()] > 0 ? slots[i].getAppearanceIndex() : slots[i].getSheathedAppearanceIndex();
			if (index != -1) {
				final int id = visibleEquipment[index];
				equipmentIds[i] = id > 0 ? id : -1;
			}
		}
		return equipmentIds;
	}

	/**
	 * Gets all the equipped items. If the tab is not currently open, it will not open it
	 * and will return the last known array of items.
	 *
	 * @return an array instance of <code>Item</code>
	 */
	public static Item[] getCachedItems() {
		final Widget widget = Widgets.get(WIDGET);
		if (widget != null) {
			final WidgetChild[] components = widget.getChildren();
			if (components.length > 0) {
				final Item[] items = new Item[NUM_SLOTS];
				final Slot[] slots = Slot.values();
				for (int i = 0; i < NUM_SLOTS; i++) {
					items[i] = new Item(components[slots[i].getComponentIndex()]);
				}
				return items;
			}
		}
		return new Item[0];
	}

	/**
	 * Gets the count of equipped items ignoring stack sizes.
	 *
	 * @return the count of equipped items
	 */
	public static int getCount() {
		return NUM_SLOTS - getCount(-1);
	}

	/**
	 * Gets the count of all equipped items matching with any of the provided ids ignoring stack sizes.
	 *
	 * @param itemIds the item ids to look for
	 * @return the count
	 */
	public static int getCount(final int... itemIds) {
		int count = 0;
		for (final Item item : getItems()) {
			if (item == null) {
				continue;
			}
			final int itemId = item.getId();
			for (final int id : itemIds) {
				if (itemId == id) {
					count++;
					break;
				}
			}
		}
		return count;
	}

	/**
	 * Gets the equipped item at the given index.
	 *
	 * @param slot the <code>Slot</code> of the item
	 * @return an <code>Item</code>; otherwise <code>null</code> if invalid
	 */
	public static Item getItem(final Slot slot) {
		final Widget widget = getWidget();
		if (widget != null && widget.validate()) {
			try {
				final WidgetChild itemComp = (widget.getIndex() == WIDGET_BANK) ?
						widget.getChild(COMPONENT_EQUIP_INVENTORY).getChild(slot.getBankComponentIndex()) : widget.getChild(slot.getComponentIndex());
				if (itemComp != null) {
					return new Item(itemComp);
				}
			} catch (IndexOutOfBoundsException ignored) {
			}
		}
		return null;
	}

	/**
	 * Gets the first item in the inventory with an id matching the argument(s)
	 *
	 * @param itemIds the id(s) to search for
	 * @return an <code>Item</code> with an id matching the argument(s)
	 */
	public static Item getItem(final int... itemIds) {
		for (final Item item : getItems()) {
			if (item == null) {
				continue;
			}
			for (final int itemId : itemIds) {
				if (itemId == item.getId()) {
					return item;
				}
			}
		}
		return null;
	}

	/**
	 * Gets the first item in the inventory with an id matching the argument(s) from the last known array of items
	 *
	 * @param itemIds the id(s) to search for
	 * @return an <code>Item</code> with an id matching the argument(s)
	 */
	public static Item getCachedItem(final int... itemIds) {
		for (final Item item : getCachedItems()) {
			if (item == null) {
				continue;
			}
			for (final int itemId : itemIds) {
				if (itemId == item.getId()) {
					return item;
				}
			}
		}
		return null;
	}

	/**
	 * Gets the equipped item at the given index from the last known array of items.
	 *
	 * @param slot the <code>Slot</code> of the item
	 * @return an <code>Item</code>; otherwise <code>null</code> if invalid
	 */
	public static Item getCachedItem(final Slot slot) {
		final Widget cache = Widgets.get(WIDGET);
		if (cache != null && cache.validate()) {
			try {
				return new Item(cache.getChild(slot.getComponentIndex()));
			} catch (ArrayIndexOutOfBoundsException ignored) {
			}
		}
		return null;
	}

	/**
	 * Gets all the equipped items.
	 *
	 * @return an array instance of <code>Item</code>
	 */
	public static Item[] getItems() {
		final Widget widget = getWidget();
		if (widget != null) {
			final boolean isBank = widget.getIndex() != WIDGET;
			final WidgetChild[] equip = (isBank) ? widget.getChild(COMPONENT_EQUIP_INVENTORY).getChildren() : widget.getChildren();
			if (equip.length > 0) {
				if (!isBank) {
					final Item[] items = new Item[NUM_SLOTS];
					final Slot[] slots = Slot.values();
					for (int i = 0; i < NUM_SLOTS; i++) {
						items[i] = new Item(equip[slots[i].getComponentIndex()]);
					}
					return items;
				} else {
					final Item[] items = new Item[equip.length];
					for (int i = 0; i < items.length; i++) {
						items[i] = new Item(equip[i]);
					}
					return items;
				}
			}
		}
		return new Item[0];
	}

	/**
	 * Gets the equipment widget.
	 *
	 * @return the equipment <code>Widget</code>
	 */
	public static Widget getWidget() {
		if (!Bank.isOpen()) {
			Tabs.EQUIPMENT.open();
			return Widgets.get(WIDGET);
		}
		return Widgets.get(WIDGET_BANK);
	}

	/**
	 * Equips an item if it is in the inventory
	 *
	 * @param itemIds the ids of the item(s) that need(s) to be equipped
	 * @return <tt>true</tt> if an item was successfully equipped otherwise <tt>false</tt>
	 */
	public static boolean equip(final int... itemIds) {
		final Item item = Inventory.getItem(itemIds);
		if (item != null) {
			int index = -1;
			for (final int itemId : itemIds) {
				if ((index = Inventory.indexOf(itemId)) != -1) {
					break;
				}
			}
			final WidgetChild item_child = item.getWidgetChild();
			for (String action : item_child.getActions()) {
				if (action == null) {
					continue;
				}
				if (action.contains("Equip") || action.contains("Wear") || action.contains("Wield")) {
					item_child.interact(action);
				}
			}
			for (int i = 0; i < 100; i++) {
				if (!item.equals(Inventory.getItemAt(index))) {
					return true;
				}
				Task.sleep(10);
			}
		}
		return false;
	}

	/**
	 * Unequips an item if it is present in the current equipment
	 *
	 * @param itemIds the ids of the item(s) that need(s) to be unequipped
	 * @return <tt>true</tt> if an item was successfully unequipped otherwise <tt>false</tt>
	 */
	public static boolean unequip(final int... itemIds) {
		final int count = getCount(itemIds);
		final Item item = getItem(itemIds);
		if (item != null) {
			if (item.getWidgetChild().interact("Remove")) {
				Task.sleep(250, 500);
				return getCount(itemIds) < count;
			}
		}
		return false;
	}

}
