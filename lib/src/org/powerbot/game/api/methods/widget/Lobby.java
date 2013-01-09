package org.powerbot.game.api.methods.widget;

import java.awt.Dimension;
import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.Game;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.util.Filter;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

/**
 * @author HelBorn
 */
public class Lobby {
	public static final int STATE_LOBBY_IDLE = 7;
	public static final int STATE_LOGGING_IN = 9;
	public static final int LOGIN_DEFAULT_TIMEOUT = 30000;

	public static final int WIDGET_MAIN_LOBBY = 906;
	public static final int WIDGET_BUTTON_PLAY_GAME = 197;
	public static final int WIDGET_BUTTON_LOGOUT = 221;
	public static final int WIDGET_LABEL_CURRENT_WORLD = 11;
	public static final int WIDGET_WORLDS_TABLE = 62;
	public static final int WIDGET_WORLDS_TABLE_SCROLLBAR = 86;
	public static final int WIDGET_WORLDS_ROWS = 77;
	public static final int WIDGET_WORLDS_COLUMN_FAVOURITE = 68;
	public static final int WIDGET_WORLDS_COLUMN_WORLD_NUMBER = 69;
	public static final int WIDGET_WORLDS_COLUMN_MEMBERS = 70;
	public static final int WIDGET_WORLDS_COLUMN_PLAYERS = 71;
	public static final int WIDGET_WORLDS_COLUMN_ACTIVITY = 72;
	public static final int WIDGET_WORLDS_COLUMN_LOOT_SHARE = 75;
	public static final int WIDGET_WORLDS_COLUMN_PING = 76;

	/**
	 * Representation of the lobby tabs.
	 */
	public static enum Tab {
		PLAYER_INFO(230, 907), WORLD_SELECT(28, 910), FRIENDS(27, 909),
		FRIENDS_CHAT(280, 589), CLAN_CHAT(26, 912), OPTIONS(25, 911);

		private final int widgetTabIndex;
		private final int widgetPanelIndex;

		private Tab(final int widgetTabIndex, final int widgetPanelIndex) {
			this.widgetTabIndex = widgetTabIndex;
			this.widgetPanelIndex = widgetPanelIndex;
		}

		/**
		 * Gets the widget of the clickable tab.
		 *
		 * @return The widget of the tab.
		 */
		public WidgetChild getWidget() {
			if (!Lobby.isOpen()) {
				return null;
			}
			return Widgets.get(WIDGET_MAIN_LOBBY, widgetTabIndex);
		}

		/**
		 * Gets the tab's panel widget.
		 *
		 * @return The tab's panel widget.
		 */
		public Widget getPanelWidget() {
			if (!Lobby.isOpen()) {
				return null;
			}
			return Widgets.get(widgetPanelIndex);
		}

		public boolean isOpen() {
			final WidgetChild child = getWidget();
			return child != null && child.validate() && child.getTextureId() == 4671;
		}

		public boolean open() {
			final WidgetChild child = getWidget();
			if (isOpen()) {
				return true;
			}
			if (child != null && child.validate() && child.click(true)) {
				Task.sleep(Random.nextInt(1200, 2000));
				return true;
			}
			return false;
		}
	}

	/**
	 * Representation of the lobby dialogs.
	 */
	public static enum Dialog {
		TRANSFER_COUNTDOWN(255, -1, 252, "^You have only just left another world."),
		ACCOUNT_IN_USE(260, -1, 252, "^Your account has not logged out from its last session."),
		LOGIN_LIMIT_EXCEEDED(260, -1, 252, "^Login limit exceeded: too many connections from your address."),
		MEMBERS_ONLY_WORLD(260, -1, 252, "^You need a member's account to log in to this world."),
		INSUFFICIENT_SKILL_TOTAL(260, -1, 252, "^You must have a total skill level of"),
		//ACCOUNT_BANNED(-1, -1, -1, null), //TODO
		WILDERNESS_WARNING(118, 120, 113, "^Warning: This is a High-risk Wilderness world."),
		VALIDATE_EMAIL(379, 379, 352, "^Validate your email now for increased account security");

		private final int backButtonIndex;
		private final int continueButtonIndex;
		private final int textIndex;
		private final Pattern textPattern;

		private Dialog(final int backButtonIndex, final int continueButtonIndex, final int textIndex, final String textPattern) {
			this.backButtonIndex = backButtonIndex;
			this.continueButtonIndex = continueButtonIndex;
			this.textIndex = textIndex;
			this.textPattern = Pattern.compile(textPattern);
		}

		public boolean isOpen() {
			final WidgetChild child = Widgets.get(WIDGET_MAIN_LOBBY, textIndex);
			if (child != null && child.isOnScreen()) {
				final String text = child.getText();
				return text != null && textPattern.matcher(text).find();
			}
			return false;
		}

		public boolean hasContinue() {
			return continueButtonIndex != -1;
		}

		public boolean clickContinue() {
			if (!hasContinue()) {
				return false;
			}
			final WidgetChild child = Widgets.get(WIDGET_MAIN_LOBBY, continueButtonIndex);
			return child != null && child.isOnScreen() && child.click(true);
		}

		public boolean hasBack() {
			return backButtonIndex != -1;
		}

		public boolean clickBack() {
			if (!hasBack()) {
				return false;
			}
			final WidgetChild child = Widgets.get(WIDGET_MAIN_LOBBY, backButtonIndex);
			return child != null && child.isOnScreen() && child.click(true);
		}
	}

	public static class World {
		private final int number;
		private final boolean members;
		private final String activity;
		private final boolean lootShare;
		private int players;
		private int ping;
		private boolean favorite;

		private World(final int widgetIndex) {
			final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
			this.number = Integer.parseInt(panel.getChild(WIDGET_WORLDS_COLUMN_WORLD_NUMBER).getChild(widgetIndex).getText());
			this.members = panel.getChild(WIDGET_WORLDS_COLUMN_MEMBERS).getChild(widgetIndex).getTextureId() == 1531;
			this.activity = panel.getChild(WIDGET_WORLDS_COLUMN_ACTIVITY).getChild(widgetIndex).getText();
			this.lootShare = panel.getChild(WIDGET_WORLDS_COLUMN_LOOT_SHARE).getChild(widgetIndex).getTextureId() == 699;
			this.players = getPlayers();
			this.ping = getPing();
			this.favorite = isFavorite();
		}

		private static int getWidgetIndex(final int worldNumber) {
			final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
			if (panel == null || !panel.validate()) {
				return -1;
			}
			for (final WidgetChild child : panel.getChild(WIDGET_WORLDS_COLUMN_WORLD_NUMBER).getChildren()) {
				if (child.getText().equals(String.valueOf(worldNumber))) {
					return child.getIndex();
				}
			}
			return -1;
		}

		public int getNumber() {
			return number;
		}

		public boolean isMembers() {
			return members;
		}

		public String getActivity() {
			return activity;
		}

		public boolean isLootShare() {
			return lootShare;
		}

		/**
		 * Gets the current number of players.
		 *
		 * @return the number of players, or -1 if the world is offline or full.
		 */
		public int getPlayers() {
			final int index = getWidgetIndex(number);
			if (index != -1) {
				final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
				try {
					players = Integer.parseInt(panel.getChild(WIDGET_WORLDS_COLUMN_PLAYERS).getChild(index).getText());
				} catch (final NumberFormatException ex) {
					players = -1;
				}
			}
			return players;
		}

		public int getPing() {
			final int index = getWidgetIndex(number);
			if (index != -1) {
				final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
				try {
					ping = Integer.parseInt(panel.getChild(WIDGET_WORLDS_COLUMN_PING).getChild(index).getText());
				} catch (final NumberFormatException ex) {
					ping = 999;
				}
			}
			return ping;
		}

		public boolean isFavorite() {
			final int index = getWidgetIndex(number);
			if (index != -1) {
				final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
				favorite = panel.getChild(WIDGET_WORLDS_COLUMN_FAVOURITE).getChild(index).getTextureId() == 1541;
			}
			return favorite;
		}

		/**
		 * Opens the World Select tab and clicks on the correct world.
		 *
		 * @return <tt>true</tt> if the world is selected; otherwise <tt>false</tt>.
		 */
		public boolean click() {
			if (!Lobby.isOpen() || (!Tab.WORLD_SELECT.isOpen() && !Tab.WORLD_SELECT.open())) {
				return false;
			}
			final World selected = Lobby.getSelectedWorld();
			if (selected != null && selected.equals(this)) {
				return true;
			}
			final int index = getWidgetIndex(number);
			if (index == -1) {
				return false;
			}
			final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
			final WidgetChild table = panel.getChild(WIDGET_WORLDS_TABLE);
			final WidgetChild row = panel.getChild(WIDGET_WORLDS_ROWS).getChild(index);
			if (table != null && table.validate() && row != null && row.validate()) {
				final Rectangle visibleBounds = new Rectangle(
						table.getAbsoluteLocation(),
						new Dimension(table.getWidth(), table.getHeight() - row.getHeight())
				);
				if (!visibleBounds.contains(row.getAbsoluteLocation())) {
					final WidgetChild scrollBar = panel.getChild(WIDGET_WORLDS_TABLE_SCROLLBAR);
					if (scrollBar == null || !Widgets.scroll(row, scrollBar)) {
						return false;
					}
				}
				return row.click(true);
			}
			return false;
		}

		@Override
		public boolean equals(final Object o) {
			return o instanceof World && ((World) o).number == this.number;
		}
	}

	public static boolean isOpen() {
		return Game.getClientState() == STATE_LOBBY_IDLE;
	}

	/**
	 * Logs out of RuneScape by clicking the X button in the upper-right corner of the lobby widget.
	 *
	 * @return <tt>true</tt> if the logout button was clicked; otherwise <tt>false</tt>.
	 */
	public static boolean close() {
		if (!isOpen() || !closeDialog()) {
			return false;
		}
		final WidgetChild child = Widgets.get(WIDGET_MAIN_LOBBY, WIDGET_BUTTON_LOGOUT);
		return child != null && child.validate() && child.click(true);
	}

	public static boolean enterGame() {
		return enterGame(LOGIN_DEFAULT_TIMEOUT);
	}

	public static boolean enterGame(final int timeout) {
		return enterGame(null, timeout);
	}

	public static boolean enterGame(final World world) {
		return enterGame(world, LOGIN_DEFAULT_TIMEOUT);
	}

	/**
	 * Attempts to login to the game from the lobby. It will close any open dialogs prior to logging in. This is
	 * a blocking method; it will wait until the account is logged in, or the timeout is reached, before the
	 * method exits.
	 * <p/>
	 * If the login fails, the {@link Dialog} will still be open when the method finishes as it allows the
	 * developer to diagnose the reason for login failure.
	 *
	 * @param world   The world to select before logging in. Can be <tt>null</tt> if no world selection is wanted.
	 * @param timeout The amount of time (in milliseconds) to wait for the account to login. If the timeout is
	 *                reached, the method will exit regardless the the current login state.
	 * @return <tt>true</tt> if the account is logged in; otherwise <tt>false</tt>.
	 */
	public static boolean enterGame(final World world, final int timeout) {
		if (Game.getClientState() == STATE_LOBBY_IDLE) {
			if (!closeDialog() || (Tab.OPTIONS.isOpen() && !Tab.PLAYER_INFO.open())) {
				return false;
			}
			final World selected = (world != null) ? getSelectedWorld() : null;
			if (selected != null && !selected.equals(world) && !world.click()) {
				return false;
			}
			final WidgetChild child = Widgets.get(WIDGET_MAIN_LOBBY, WIDGET_BUTTON_PLAY_GAME);
			if (!(child != null && child.validate() && child.click(true))) {
				return false;
			}
		}
		final Timer t = new Timer(timeout);
		while (t.isRunning() && !Game.isLoggedIn()) {
			final Dialog dialog = getOpenDialog();
			if (dialog == Dialog.TRANSFER_COUNTDOWN || (dialog != null && dialog.clickContinue())) {
				t.reset();
			} else if (dialog != null) {
				Task.sleep(500, 1000);
				break;
			}
			Task.sleep(5);
		}
		return Game.isLoggedIn();
	}

	/**
	 * Gets the currently selected world on the World Select panel. If the panel cannot be validated, the method
	 * will open the World Select tab in order to validate it.
	 *
	 * @return The currently selected world, or <tt>null</tt> if unable to retrieve world.
	 */
	public static World getSelectedWorld() {
		if (!isOpen() || !closeDialog() || (!Tab.WORLD_SELECT.getPanelWidget().validate() && !Tab.WORLD_SELECT.open())) {
			return null;
		}
		final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
		final String text = panel.validate() ? panel.getChild(WIDGET_LABEL_CURRENT_WORLD).getText() : null;
		if (text != null) {
			final Matcher m = Pattern.compile("^World\\s(\\d*)$").matcher(text);
			if (m.find()) {
				return getWorld(Integer.parseInt(m.group(1)));
			}
		}
		return null;
	}

	public static World getWorld(final int worldNumber) {
		final World[] worlds = getWorlds(new Filter<World>() {
			@Override
			public boolean accept(final World world) {
				return world.getNumber() == worldNumber;
			}
		});
		return worlds.length == 1 ? worlds[0] : null;
	}

	public static World[] getWorlds() {
		return getWorlds(new Filter<World>() {
			@Override
			public boolean accept(final World world) {
				return true;
			}
		});
	}

	public static World[] getWorlds(final Filter<World> filter) {
		if (!isOpen() || !closeDialog()) {
			return new World[0];
		}
		final Widget panel = Tab.WORLD_SELECT.getPanelWidget();
		if (!panel.validate() && !Tab.WORLD_SELECT.open()) {
			return new World[0];
		}
		final ArrayList<World> worlds = new ArrayList<World>();
		final WidgetChild[] rows = panel.getChild(WIDGET_WORLDS_ROWS).getChildren();
		for (final WidgetChild row : rows) {
			final World world = new World(row.getIndex());
			if (filter.accept(world)) {
				worlds.add(world);
			}
		}
		return worlds.toArray(new World[worlds.size()]);
	}

	public static Dialog getOpenDialog() {
		for (final Dialog d : Dialog.values()) {
			if (d.isOpen()) {
				return d;
			}
		}
		return null;
	}

	private static boolean closeDialog() {
		final Dialog dialog = getOpenDialog();
		return dialog == null || (dialog.hasBack() && dialog.clickBack());
	}
}