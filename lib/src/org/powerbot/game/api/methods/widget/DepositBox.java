package org.powerbot.game.api.methods.widget;

import java.util.ArrayList;
import java.util.Arrays;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Calculations;
import org.powerbot.game.api.methods.Walking;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.methods.input.Keyboard;
import org.powerbot.game.api.methods.interactive.Players;
import org.powerbot.game.api.methods.node.SceneEntities;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.node.Item;
import org.powerbot.game.api.wrappers.node.SceneObject;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

/**
 * Deposit box related methods.
 *
 * @author HelBorn
 */
public class DepositBox {
	public static final int[] DEPOSIT_BOX_IDS = new int[]{
			2045, 2133, 6396, 6402, 6404, 6417, 6418, 6453, 6457, 6478, 6836, 9398, 15985, 20228, 24995, 25937, 26969,
			32924, 32930, 32931, 34755, 36788, 39830, 45079, 66668, 70512, 73268
	};

	public static final int WIDGET_DEPOSIT_BOX = 11;
	public static final int WIDGET_SLOTS_CONTAINER = 17;
	public static final int WIDGET_BUTTON_CLOSE_DEPOSIT_BOX = 15;
	public static final int WIDGET_BUTTON_DEPOSIT_INVENTORY = 19;
	public static final int WIDGET_BUTTON_DEPOSIT_EQUIPMENT = 23;
	public static final int WIDGET_BUTTON_DEPOSIT_FAMILIAR = 25;
	public static final int WIDGET_BUTTON_DEPOSIT_POUCH = 21;

	public static boolean isOpen() {
		final Widget depositBox = Widgets.get(WIDGET_DEPOSIT_BOX);
		return depositBox != null && depositBox.validate();
	}

	/**
	 * Navigates to and opens the nearest deposit box.
	 *
	 * @return <tt>true</tt> if the deposit box was opened; otherwise <tt>false</tt>.
	 */
	public static boolean open() {
		final SceneObject depositBox = getNearest();
		if (depositBox == null) {
			return false;
		}
		if (!depositBox.isOnScreen() && (!Players.getLocal().isMoving()
				|| Calculations.distance(Walking.getDestination(), depositBox.getLocation()) > 4)) {
			Walking.walk(depositBox);
			Task.sleep(200, 400);
		}
		if (depositBox.isOnScreen() && depositBox.interact("Deposit")) {
			final Timer t = new Timer(4000);
			while (t.isRunning() && !isOpen()) {
				Task.sleep(10);
			}
		}
		return isOpen();
	}

	public static boolean close() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild closeButton = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_BUTTON_CLOSE_DEPOSIT_BOX);
		return closeButton != null && closeButton.interact("Close");
	}

	public static SceneObject getNearest() {
		Arrays.sort(DEPOSIT_BOX_IDS);
		return SceneEntities.getNearest(new Filter<SceneObject>() {
			@Override
			public boolean accept(final SceneObject sceneObject) {
				return sceneObject != null && Arrays.binarySearch(DEPOSIT_BOX_IDS, sceneObject.getId()) >= 0;
			}
		});
	}

	public static boolean deposit(final int id, final Bank.Amount amount) {
		return deposit(id, amount.getValue());
	}

	public static boolean deposit(final int id, final int amount) {
		final Item item = getItem(id);
		if (!isOpen() || item == null || amount < 0) {
			return false;
		}
		String action = "Deposit-" + amount;
		if (getItemCount(true, id) <= amount || amount == 0) {
			action = "Deposit-All";
		}
		final int invCount = getItemCount(true);
		if (Bank.slotContainsAction(item.getWidgetChild(), action)) {
			if (!item.getWidgetChild().interact(action)) {
				return false;
			}
		} else if (item.getWidgetChild().interact("Deposit-X") && Bank.waitForInputWidget(true)) {
			Task.sleep(200, 800);
			Keyboard.sendText(String.valueOf(amount), true);
		}
		final Timer t = new Timer(2000);
		while (t.isRunning() && getItemCount(true) == invCount) {
			Task.sleep(5);
		}
		return getItemCount(true) != invCount;
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
		if (getItems().length == 0) {
			return true;
		}
		final WidgetChild child = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_BUTTON_DEPOSIT_INVENTORY);
		final int invCount = getItems().length;
		if (child != null && child.click(true)) {
			final Timer t = new Timer(2000);
			while (t.isRunning() && getItems().length == invCount) {
				Task.sleep(5);
			}
		}
		return invCount != getItems().length;
	}

	public static boolean depositEquipment() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_BUTTON_DEPOSIT_EQUIPMENT);
		return child != null && child.click(true);
	}

	public static boolean depositFamiliarInventory() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_BUTTON_DEPOSIT_FAMILIAR);
		return child != null && child.click(true);
	}

	public static boolean depositMoneyPouch() {
		if (!isOpen()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_BUTTON_DEPOSIT_POUCH);
		return child != null && child.click(true);
	}

	/**
	 * Finds an item in the deposit box viewport. Note that the deposit box viewport displays items from the players
	 * inventory, not items from the players bank. The inventory tab will be unavailable while the deposit box is open.
	 *
	 * @param filter The filter to look for the item.
	 * @return The found item, or <tt>null</tt> if not found.
	 */
	public static Item getItem(final Filter<Item> filter) {
		for (final Item item : getItems()) {
			if (filter.accept(item)) {
				return item;
			}
		}
		return null;
	}

	public static Item getItem(final int id) {
		return getItem(new Filter<Item>() {
			public boolean accept(final Item item) {
				return item.getId() == id;
			}
		});
	}

	/**
	 * Gets the items displayed in the deposit box viewport. Note that the deposit box viewport displays items from
	 * the players inventory, not items from the players bank. The inventory tab will be unavailable while the
	 * deposit box is open.
	 *
	 * @return An array of items in the deposit box view. The array will be empty if deposit box is not open.
	 */
	public static Item[] getItems() {
		if (!isOpen()) {
			return new Item[0];
		}
		final WidgetChild[] slots = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_SLOTS_CONTAINER).getChildren();
		final ArrayList<Item> items = new ArrayList<Item>();
		for (final WidgetChild slot : slots) {
			if (slot.getChildId() != -1) {
				items.add(new Item(slot));
			}
		}
		return items.toArray(new Item[items.size()]);
	}

	public static Item[] getItems(final Filter<Item> filter) {
		if (!isOpen()) {
			return new Item[0];
		}
		final WidgetChild[] slots = Widgets.get(WIDGET_DEPOSIT_BOX, WIDGET_SLOTS_CONTAINER).getChildren();
		final ArrayList<Item> items = new ArrayList<Item>();
		for (final WidgetChild slot : slots) {
			final Item item;
			if (slot.getChildId() != -1 && filter.accept(item = new Item(slot))) {
				items.add(item);
			}
		}
		return items.toArray(new Item[items.size()]);
	}

	public static int getItemCount(final int... ids) {
		return getItemCount(false, new Filter<Item>() {
			public boolean accept(final Item item) {
				final int id = item.getId();
				for (final int i : ids) {
					if (i == id) {
						return true;
					}
				}
				return false;
			}
		});
	}

	public static int getItemCount(final boolean countStack, final int... ids) {
		return getItemCount(countStack, new Filter<Item>() {
			public boolean accept(final Item item) {
				final int id = item.getId();
				for (final int i : ids) {
					if (i == id) {
						return true;
					}
				}
				return false;
			}
		});
	}

	public static int getItemCount(final boolean countStack, final Filter<Item> filter) {
		int count = 0;
		for (final Item item : getItems()) {
			if (filter.accept(item)) {
				count += countStack ? item.getStackSize() : 1;
			}
		}
		return count;
	}

	public static int getItemCount(final boolean countStack) {
		int count = 0;
		for (final Item item : getItems()) {
			count += countStack ? item.getStackSize() : 1;
		}
		return count;
	}
}
