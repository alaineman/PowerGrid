package org.powerbot.game.api.methods.widget;

import java.awt.Dimension;
import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.Arrays;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Settings;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.input.Keyboard;
import org.powerbot.game.api.methods.interactive.NPCs;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.node.Menu;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.methods.tab.Inventory;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.Entity;
import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.interactive.NPC;
import org.powerbot.game.api.wrappers.node.Item;
import org.powerbot.game.api.wrappers.node.SceneObject;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

/**
 * Bank related methods.
 *
 * @author HelBorn
 */
public class Bank {
	public static final int[] BANK_NPC_IDS = new int[]{
			44, 45, 166, 494, 495, 496, 497, 498, 499, 553, 909, 953, 958, 1036, 1360, 1702, 2163, 2164, 2354, 2355,
			2568, 2569, 2570, 2617, 2618, 2619, 2718, 2759, 3046, 3198, 3199, 3293, 3416, 3418, 3824, 4456, 4457,
			4458, 4459, 4519, 4907, 5257, 5258, 5259, 5260, 5488, 5776, 5777, 5901, 6200, 6362, 7049, 7050, 7605,
			8948, 9710, 13932, 14707, 14923, 14924, 14925, 15194
	};
	public static final int[] BANK_BOOTH_IDS = new int[]{
			782, 2213, 3045, 5276, 6084, 10517, 11338, 11758, 12759, 12798, 12799, 12800, 12801, 14369, 14370,
			16700, 19230, 20325, 20326, 20327, 20328, 22819, 24914, 25808, 26972, 29085, 34752, 35647,
			36262, 36786, 37474, 49018, 49019, 52397, 52589
	};
	public static final int[] BANK_COUNTER_IDS = new int[]{
			42217, 42377, 42378
	};
	public static final int[] BANK_CHEST_IDS = new int[]{
			2693, 4483, 8981, 12308, 14382, 20607, 21301, 27663, 42192, 57437, 62691
	};
    	public static final int[] UNDEPOSITABLE_ITEM_IDS = new int[]{2528, 6796, 14664, 23713, 23714, 23715, 23716, 23717,
         	   	23718, 23719, 23720, 23721, 23722, 23723, 23724, 23725, 23726, 23727, 23728, 23729, 23730, 23731, 23732,
         	   	23733, 23734, 23735, 23736, 23737, 23738, 23739, 23740, 23741, 23742, 23743, 23744, 23745, 23746, 23747,
         	   	23748, 23749, 23750, 23751, 23752, 23753, 23754, 23755, 23756, 23757, 23758, 23759, 23760, 23761, 23762,
        	   	23763, 23764, 23765, 23766, 23767, 23768, 23769, 23770, 23771, 23773, 23774, 23775, 23776, 23777, 23778,
          	   	23779, 23780, 23781, 23782, 23783, 23784, 23785, 23786, 23787, 23788, 23789, 23790, 23791, 23792, 23793,
         	   	23794, 23795, 23796, 23797, 23798, 23799, 23800, 23801, 23802, 23803, 23804, 23805, 23806, 23807, 23808,
          	   	23809, 23810, 23811, 23812, 23813, 23814, 23815, 23816, 23817, 24154, 24155
   	};
	public static final Tile[] UNREACHABLE_BANK_TILES = new Tile[]{
			new Tile(3191, 3445, 0), new Tile(3180, 3433, 0)
	};

	public static final int WIDGET_BANK = 762;
	public static final int WIDGET_SLOTS_CONTAINER = 95;
	public static final int WIDGET_SCROLLBAR = 116;
	public static final int WIDGET_BUTTON_CLOSE_BANK = 45;
	public static final int WIDGET_BUTTON_DEPOSIT_INVENTORY = 34;
	public static final int WIDGET_BUTTON_DEPOSIT_EQUIPMENT = 38;
	public static final int WIDGET_BUTTON_DEPOSIT_FAMILIAR = 40;
	public static final int WIDGET_BUTTON_DEPOSIT_POUCH = 36;
	public static final int WIDGET_BUTTON_SEARCH = 18;
	public static final int WIDGET_BUTTON_WITHDRAW_NOTED = 20;

	public static final int WIDGET_BANKPIN = 13;

	public static final int SETTING_WITHDRAWAL_MODE = 160;
	public static final int SETTING_BANK_TAB = 110;

	private static final Filter<Identifiable> ALL_FILTER = new Filter<Identifiable>() {
		@Override
		public boolean accept(final Identifiable bank) {
			if ((!isBanker(bank) && !isBankBooth(bank) && !isBankChest(bank) && !isBankCounter(bank))) {
				return false;
			}
			for (final Tile badTile : UNREACHABLE_BANK_TILES) {
				if (((Locatable) bank).getLocation().equals(badTile)) {
					return false;
				}
			}
			return true;
		}
	};

	public static enum Amount {
		ONE(1), FIVE(5), TEN(10), ALL_BUT_ONE(-1), ALL(0);

		private final int value;

		private Amount(final int value) {
			this.value = value;
		}

		public int getValue() {
			return value;
		}
	}

	public static enum Tab {
		NONE(-1), SEARCH(0), ALL(1), SECOND(2), THIRD(3), FOURTH(4),
		FIFTH(5), SIXTH(6), SEVENTH(7), EIGHTH(8), NINTH(9);

		private final int index;

		private Tab(final int index) {
			this.index = index;
		}

		public WidgetChild getWidgetChild() {
			if (this != NONE && this != SEARCH && Bank.isOpen()) {
				return Widgets.get(WIDGET_BANK, 67 - (index * 2));
			}
			return null;
		}

		public boolean open() {
			final WidgetChild tabWidget = getWidgetChild();
			return tabWidget != null && tabWidget.click(true);
		}

		/**
		 * Gets the item that is shown on the tab, which will be the first item ordered in that tab. Note that the
		 * main tab doesn't display a symbol item, so this will return <tt>null</tt> if attempted.
		 *
		 * @return The item visually shown on the bank tab, or <tt>null</tt> if none found.
		 */
		public Item getSymbolItem() {
			final WidgetChild tabWidget = getWidgetChild();
			if (tabWidget != null && tabWidget.getChildId() != -1) {
				return new Item(tabWidget);
			}
			return null;
		}

		public static Tab getTab(final int index) {
			for (final Tab tab : Tab.values()) {
				if (tab.index == index) {
					return tab;
				}
			}
			return NONE;
		}
	}

	public static Widget getWidget() {
		return Widgets.get(WIDGET_BANK);
	}

	public static boolean isOpen() {
		final Widget bank = getWidget();
		return bank != null && bank.validate();
	}

	/**
	 * Navigates to and opens the nearest bank.
	 *
	 * @return <tt>true</tt> if the bank was opened; otherwise <tt>false</tt>.
	 */
	public static boolean open() {
		if (isOpen()) {
			return true;
		}
		final Entity bank = getNearest();
		if (bank == null) {
			return false;
		}
		if (!bank.isOnScreen() && (!Players.getLocal().isMoving()
				|| Calculations.distance(Walking.getDestination(), ((Locatable) bank).getLocation()) > 4)) {
			Walking.walk((Locatable) bank);
			Task.sleep(200, 400);
		}
		if (bank.isOnScreen()) {
			boolean interacted = false;
			if (isBanker((Identifiable) bank)) {
				interacted = bank.interact("Bank");
			} else if (isBankBooth((Identifiable) bank)) {
				interacted = bank.interact("Bank", "Bank booth");
			} else if (isBankChest((Identifiable) bank)) {
				bank.hover();
				interacted = Menu.contains("Open") ? bank.interact("Open") : bank.interact("Use");
			} else if (isBankCounter((Identifiable) bank)) {
				interacted = bank.interact("Bank", "Counter");
			}
			final Widget bankpin = Widgets.get(WIDGET_BANKPIN);
			final Timer t = new Timer(4000);
			while (t.isRunning() && interacted && !isOpen() && (bankpin == null || !bankpin.validate())) {
				Task.sleep(10);
			}
		}
		return isOpen();
	}

	public static boolean close() {
		if (!isOpen()) {
			return true;
		}
		final WidgetChild closeButton = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_CLOSE_BANK);
		return closeButton != null && closeButton.interact("Close");
	}

	/**
	 * Finds the nearest interactive entity that allows a player to open their bank. The returned entity may be
	 * explicitly cast to a <tt>Locatable</tt> or <tt>Identifiable</tt> if required.
	 *
	 * @return The nearest bank entity, or <tt>null</tt> if none found.
	 * @see Locatable
	 * @see Identifiable
	 */
	public static Entity getNearest() {
		final Locatable[] banks = getLoadedBanks();
		Locatable nearest = null;
		for (final Locatable bank : banks) {
			if (ALL_FILTER.accept((Identifiable) bank) && ((Entity) bank).validate()) {
				if ((nearest == null || Calculations.distanceTo(bank) < Calculations.distanceTo(nearest))) {
					nearest = bank;
				}
			}
		}
		return (Entity) nearest;
	}

	public static boolean withdraw(final int id, final Amount amount) {
		return withdraw(id, amount.getValue());
	}

	public static boolean withdraw(final int id, final int amount) {
		final Item item = getItem(id);
		if (!isOpen() || item == null) {
			return false;
		}
		final Timer t = new Timer(500);
		while (t.isRunning() && item.getWidgetChild().getRelativeY() == 0 && getCurrentTab() != Tab.ALL) {
			setCurrentTab(Tab.ALL);
			Task.sleep(50, 70);
		}
		if (!isSlotVisible(item.getWidgetChild())) {
			final WidgetChild scrollBar = Widgets.get(WIDGET_BANK, WIDGET_SCROLLBAR);
			if (scrollBar == null || !Widgets.scroll(item.getWidgetChild(), scrollBar)) {
				return false;
			}
		}
		String action = "Withdraw-" + amount;
		if ((amount >= item.getStackSize() && amount != 1 && amount != 5 && amount != 10) || amount == 0) {
			action = "Withdraw-All";
		} else if (amount == (item.getStackSize() - 1) || amount == -1) {
			action = "Withdraw-All but one";
		}
		final int invCount = Inventory.getCount(true);
		if (slotContainsAction(item.getWidgetChild(), action)) {
			if (!item.getWidgetChild().interact(action)) {
				return false;
			}
		} else if (item.getWidgetChild().interact("Withdraw-X") && waitForInputWidget(true)) {
			Task.sleep(200, 800);
			Keyboard.sendText(String.valueOf(amount), true);
		}
		t.setEndIn(2000);
		while (t.isRunning() && Inventory.getCount(true) == invCount) {
			Task.sleep(5);
		}
		return Inventory.getCount(true) != invCount;
	}

	public static boolean deposit(final int id, final Amount amount) {
		return deposit(id, amount.getValue());
	}

	public static boolean deposit(final int id, final int amount) {
		final Item item = Inventory.getItem(id);
		if (!isOpen() || item == null || amount < 0) {
			return false;
		}
		String action = "Deposit-" + amount;
		if (Inventory.getCount(true, id) <= amount || amount == 0) {
			action = "Deposit-All";
		}
		if (Inventory.getCount(true, item.getId()) == 1) {
			action = "Deposit";
		}
		final int invCount = Inventory.getCount(true);
		if (slotContainsAction(item.getWidgetChild(), action)) {
			if (!item.getWidgetChild().interact(action)) {
				return false;
			}
		} else if (item.getWidgetChild().interact("Deposit-X") && waitForInputWidget(true)) {
			Task.sleep(200, 800);
			Keyboard.sendText(String.valueOf(amount), true);
		}
		final Timer t = new Timer(2000);
		while (t.isRunning() && Inventory.getCount(true) == invCount) {
			Task.sleep(5);
		}
		return Inventory.getCount(true) != invCount;
	}

	/**
	 * Deposits the players inventory using the provided "deposit items" button. For efficiency, this method will
	 * automatically return <tt>true</tt> without clicking the button if the players inventory is already empty.
	 *
	 * @return <tt>true</tt> if inventory becomes empty; otherwise <tt>false</tt>.
	 */
	public static boolean depositInventory() {
		if (!isOpen()) {
			return false;
		}
		if (Inventory.getCount() == 0) {
			return true;
		}
		final WidgetChild child = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_DEPOSIT_INVENTORY);
		final int invCount = Inventory.getCount();
		if (child != null && child.click(true)) {
			final Timer t = new Timer(2000);
			while (t.isRunning() && Inventory.getCount() == invCount) {
				Task.sleep(5);
			}
		}
		return invCount != Inventory.getCount();
	}

	public static boolean depositEquipment() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_DEPOSIT_EQUIPMENT);
		return child != null && child.click(true);
	}

	public static boolean depositFamiliarInventory() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_DEPOSIT_FAMILIAR);
		return child != null && child.click(true);
	}

	public static boolean depositMoneyPouch() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_DEPOSIT_POUCH);
		return child != null && child.click(true);
	}

	public static Item[] getItems() {
		return getItems(false);
	}

	public static Item[] getItems(final boolean currentTabOnly) {
		return getItems(currentTabOnly, Inventory.ALL_FILTER);
	}

	public static Item[] getItems(final Filter<Item> itemFilter) {
		return getItems(false, itemFilter);
	}

	public static Item[] getItems(final boolean currentTabOnly, final Filter<Item> itemFilter) {
		if (!isOpen()) {
			return new Item[0];
		}
		final WidgetChild[] slots = Widgets.get(WIDGET_BANK, WIDGET_SLOTS_CONTAINER).getChildren();
		final ArrayList<Item> items = new ArrayList<Item>(slots.length);
		for (final WidgetChild slot : slots) {
			if (slot != null && slot.getChildId() != -1 && (!currentTabOnly || slot.getRelativeY() != 0)) {
				final Item item = new Item(slot);
				if (itemFilter.accept(item)) {
					items.add(item);
				}
			}
		}
		return items.toArray(new Item[items.size()]);
	}

	public static Item getItem(final int... ids) {
		return getItem(new Filter<Item>() {
			public boolean accept(final Item item) {
				for (final int id : ids) {
					if (id == item.getId()) {
						return true;
					}
				}
				return false;
			}
		});
	}

	public static Item getItem(final Filter<Item> itemFilter) {
		for (final Item item : getItems()) {
			if (item != null && itemFilter.accept(item)) {
				return item;
			}
		}
		return null;
	}

	public static int getItemCount(final int... ids) {
		return getItemCount(false, ids);
	}

	public static int getItemCount(final boolean countStack, final int... ids) {
		return getItemCount(countStack, new Filter<Item>() {
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

	public static int getItemCount(final boolean countStack) {
		return getItemCount(countStack, Inventory.ALL_FILTER);
	}

	public static int getItemCount(final boolean countStack, final Filter<Item> itemFilter) {
		int count = 0;
		for (final Item item : getItems()) {
			if (item != null && itemFilter.accept(item)) {
				count += countStack ? item.getStackSize() : 1;
			}
		}
		return count;
	}

	public static boolean isWithdrawNotedEnabled() {
		return Settings.get(SETTING_WITHDRAWAL_MODE) == 1;
	}

	public static boolean setWithdrawNoted(final boolean noted) {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_WITHDRAW_NOTED);
		if (isWithdrawNotedEnabled() != noted && child != null && child.click(true)) {
			final Timer t = new Timer(500);
			while (t.isRunning() && isWithdrawNotedEnabled() != noted) {
				Task.sleep(5);
			}
		}
		return isWithdrawNotedEnabled() == noted;
	}

	public static boolean isSearchEnabled() {
		return getCurrentTab() == Tab.SEARCH;
	}

	public static boolean setSearchMode(final boolean enable) {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_BANK, WIDGET_BUTTON_SEARCH);
		if (isSearchEnabled() != enable && child != null && child.click(true)) {
			final Timer t = new Timer(500);
			while (t.isRunning() && isSearchEnabled() != enable) {
				Task.sleep(5);
			}
		}
		return isSearchEnabled() == enable;
	}

	/**
	 * Uses the bank's search utility. Note that search mode will still be enabled after this method exits.
	 * In order to go back to the last viewed tab before the search, search mode must be turned off.
	 *
	 * @param itemName The (partial) name of the item to search for in the bank.
	 * @return An array of the resulting items displayed in the bank from the search, or <tt>null</tt> if unable
	 *         to perform the search.
	 * @see Bank#setSearchMode(boolean)
	 */
	public static Item[] search(final String itemName) {
		if (!isOpen()) {
			return null;
		}
		if (isSearchEnabled() && !isInputWidgetOpen()) {
			setSearchMode(false);
			Task.sleep(1000, 2000);
			setSearchMode(true);
		}
		if ((isSearchEnabled() || setSearchMode(true)) && waitForInputWidget(true)) {
			Task.sleep(200, 400);
			Keyboard.sendText(itemName, true);
			if (waitForInputWidget(false)) {
				return getItems(true);
			}
		}
		return null;
	}

	public static Tab getCurrentTab() {
		if (!isOpen()) {
			return Tab.NONE;
		}
		return Tab.getTab((Settings.get(SETTING_BANK_TAB) >>> 0x1B) ^ 0x10);
	}

	/**
	 * Sets the current bank tab. The enumerations <tt>Tab.NONE</tt> and <tt>Tab.SEARCH</tt> cannot be applied here,
	 * as they are not true tabs and therefore unclickable.
	 *
	 * @param tab The tab to open.
	 * @return <tt>true</tt> if opening the tab was successful; otherwise <tt>false</tt>.
	 */
	public static boolean setCurrentTab(final Tab tab) {
		return !(!isOpen() || tab == Tab.NONE || tab == Tab.SEARCH || tab.index > getTabCount()) && (getCurrentTab() == tab || tab.open());
	}

	public static int getTabCount() {
		if (!isOpen()) {
			return -1;
		}
		int count = 1;
		for (final Tab tab : Tab.values()) {
			final WidgetChild child = tab.getWidgetChild();
			if (child != null && child.getChildId() != -1 && tab != Tab.SEARCH) {
				count++;
			}
		}
		return count;
	}

	protected static boolean slotContainsAction(final WidgetChild slot, final String action) {
		final String[] actions = slot.getActions();
		if (actions != null) {
			for (final String a : actions) {
				if (a != null && a.matches("^" + action + "(<.*>)?$")) {
					return true;
				}
			}
		}
		return false;
	}

	private static boolean isSlotVisible(final WidgetChild slot) {
		final WidgetChild slots = Widgets.get(WIDGET_BANK, WIDGET_SLOTS_CONTAINER);
		final Rectangle visibleBounds = new Rectangle(
				slots.getAbsoluteLocation(),
				new Dimension(
						slots.getWidth() - slot.getWidth(), slots.getHeight() - slot.getHeight()
				)
		);
		return visibleBounds.contains(slot.getAbsoluteLocation());
	}

	protected static boolean waitForInputWidget(final boolean open) {
		final Timer t = new Timer(3000);
		while (t.isRunning() && isInputWidgetOpen() != open) {
			Task.sleep(5);
		}
		return isInputWidgetOpen() == open;
	}

	private static boolean isInputWidgetOpen() {
		final WidgetChild child = Widgets.get(752, 3);
		return child != null && child.isOnScreen();
	}

	private static Locatable[] getLoadedBanks() {
		final ArrayList<Locatable> banks = new ArrayList<Locatable>();
		final NPC[] loadedNPCs = NPCs.getLoaded(BANK_NPC_IDS);
		for (final NPC npc : loadedNPCs) {
			if (npc.validate() && ALL_FILTER.accept(npc)) {
				banks.add(npc);
			}
		}
		final SceneObject[] loadedObjects = SceneEntities.getLoaded();
		for (final SceneObject object : loadedObjects) {
			if (object.validate() && ALL_FILTER.accept(object)) {
				banks.add(object);
			}
		}
		return banks.toArray(new Locatable[banks.size()]);
	}

	private static boolean isBanker(final Identifiable identifiable) {
		Arrays.sort(BANK_NPC_IDS);
		return identifiable instanceof NPC && Arrays.binarySearch(BANK_NPC_IDS, identifiable.getId()) >= 0;
	}

	private static boolean isBankBooth(final Identifiable identifiable) {
		Arrays.sort(BANK_BOOTH_IDS);
		return identifiable instanceof SceneObject && Arrays.binarySearch(BANK_BOOTH_IDS, identifiable.getId()) >= 0;
	}

	private static boolean isBankCounter(final Identifiable identifiable) {
		Arrays.sort(BANK_COUNTER_IDS);
		return identifiable instanceof SceneObject && Arrays.binarySearch(BANK_COUNTER_IDS, identifiable.getId()) >= 0;
	}

	private static boolean isBankChest(final Identifiable identifiable) {
		Arrays.sort(BANK_CHEST_IDS);
		return identifiable instanceof SceneObject && Arrays.binarySearch(BANK_CHEST_IDS, identifiable.getId()) >= 0;
	}
}