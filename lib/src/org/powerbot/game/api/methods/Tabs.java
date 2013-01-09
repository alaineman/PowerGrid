package org.powerbot.game.api.methods;

import java.awt.event.KeyEvent;

import org.powerbot.core.script.job.Task;
import org.powerbot.game.api.methods.input.Keyboard;
import org.powerbot.game.api.methods.widget.WidgetCache;
import org.powerbot.game.api.util.Random;
import org.powerbot.game.api.util.Timer;
import org.powerbot.game.api.wrappers.widget.WidgetChild;

/**
 * @author Timer
 */
public enum Tabs {
	NONE(-1, null, -1),
	ATTACK(0, "Combat", KeyEvent.VK_F5),
	NOTICEBOARD(1, "Noticeboard", -1),
	STATS(2, "Stats", -1),
	COMBAT_ACADEMY(3, "Combat Academy", -1),
	INVENTORY(4, "Inventory", KeyEvent.VK_F1),
	EQUIPMENT(5, "Worn Equipment", KeyEvent.VK_F2),
	PRAYER(6, "Prayer List", KeyEvent.VK_F3),
	ABILITY_BOOK(7, "Ability Book", KeyEvent.VK_F4),
	EXTRAS(8, "Extras", -1),
	FRIENDS(9, "Friends List", -1),
	FRIENDS_CHAT(10, "Friends Chat", -1),
	CLAN_CHAT(11, "Clan Chat", -1),
	OPTIONS(12, "Options", -1),
	EMOTES(13, "Emotes", -1),
	MUSIC(14, "Music Player", -1),
	NOTES(15, "Notes", -1),
	LOGOUT(16, "Exit", -1);
	private static final int WIDGET_LOGOUT_X = 182;
	private final String description;
	private final int functionKey;
	private final int index;

	Tabs(final int index, final String description, final int functionKey) {
		this.description = description;
		this.functionKey = functionKey;
		this.index = index;
	}

	public String getDescription() {
		return description;
	}

	public int getFunctionKey() {
		return functionKey;
	}

	public boolean hasFunctionKey() {
		return functionKey != -1;
	}

	public int getIndex() {
		return index;
	}

	public boolean open() {
		return open(false);
	}

	public boolean open(final boolean fast) {
		if (this == Tabs.NONE) {
			return false;
		} else if (this == getCurrent()) {
			return true;
		}
		if (fast && hasFunctionKey()) {
			Keyboard.sendKey(KeyEvent.CHAR_UNDEFINED, getFunctionKey(), Random.nextInt(100, 300));
		} else {
			final WidgetChild widgetChild = WidgetCache.getTab(this);
			if (widgetChild != null && widgetChild.validate()) {
				if (widgetChild.click(true)) {
					final Timer timer = new Timer(800);
					while (timer.isRunning() && getCurrent() != this) {
						Task.sleep(15);
					}
				}
			}
		}
		return getCurrent() == this;
	}

	public boolean isOpen() {
		return getCurrent() == this;
	}

	public static Tabs getCurrent() {
		for (final Tabs t : Tabs.values()) {
			final WidgetChild tab = WidgetCache.getTab(t);
			if (tab != null && tab.getTextureId() != -1) {
				return t;
			}
		}
		final WidgetChild logout = Widgets.get(WIDGET_LOGOUT_X, 1);
		return logout != null && logout.validate() && logout.visible() ? Tabs.LOGOUT : Tabs.NONE;
	}
}
