package org.powerbot.game.api.methods.widget;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import org.powerbot.game.api.methods.Tabs;
import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;

/**
 * @author Timer
 */
public class WidgetCache {
	private static final Map<ThreadGroup, Record> cache = Collections.synchronizedMap(new HashMap<ThreadGroup, Record>());

	public static void purge() {
		cache.clear();
	}

	public static WidgetChild getCompass() {
		final Record record = get();
		update(record);
		if (record.index_widget == -1) {
			return null;
		}
		final Widget widget = Widgets.get(record.index_widget);
		if (widget != null) {
			if (record.index_compass == -1) {
				for (final WidgetChild widgetChild : widget.getChildren()) {
					final String[] actions = widgetChild.getActions();
					if (actions != null && actions.length == 1 && actions[0].equalsIgnoreCase("Face North")) {
						record.index_compass = widgetChild.getIndex();
						break;
					}
				}
			}
			if (record.index_compass != -1) {
				return Widgets.get(record.index_widget, record.index_compass);
			}
		}
		return null;
	}

	public static WidgetChild getMap() {
		final Record record = get();
		update(record);
		if (record.index_widget == -1) {
			return null;
		}
		final Widget widget = Widgets.get(record.index_widget);
		if (widget != null) {
			if (record.index_map == -1) {
				for (final WidgetChild widgetChild : widget.getChildren()) {
					if (widgetChild.getSpecialType() == 1338) {
						record.index_map = widgetChild.getIndex();
						break;
					}
				}
			}
			if (record.index_map != -1) {
				return Widgets.get(record.index_widget, record.index_map);
			}
		}
		return null;
	}

	public static WidgetChild getTab(final Tabs tab) {
		final Record record = get();
		update(record);
		if (record.index_widget == -1) {
			return null;
		}
		final Widget widget = Widgets.get(record.index_widget);
		if (widget != null) {
			final int index = tab.getIndex();
			if (index < 0 || index > 16) {
				return null;
			}
			if (record.indices_tabs[index] == -1) {
				for (final WidgetChild widgetChild : widget.getChildren()) {
					final String[] actions = widgetChild.getActions();
					if (actions != null && actions.length > 0 && actions[0].equalsIgnoreCase(tab.getDescription())) {
						record.indices_tabs[index] = widgetChild.getIndex();
						break;
					}
				}
			}
			if (record.indices_tabs[index] != -1) {
				return Widgets.get(record.index_widget, record.indices_tabs[index]);
			}
		}
		return null;
	}

	private synchronized static void update(final Record record) {
		final int master_index = record.client.getGUIRSInterfaceIndex();
		if (master_index != record.index_widget) {
			record.index_map = -1;
			record.index_compass = -1;
			for (int i = 0; i < 17; i++) {
				record.indices_tabs[i] = -1;
			}
			record.index_widget = master_index;
		}
	}

	private synchronized static Record get() {
		final ThreadGroup threadGroup = Thread.currentThread().getThreadGroup();
		Record record = cache.get(threadGroup);
		if (record == null) {
			record = new Record();
			cache.put(threadGroup, record);
		}
		return record;
	}

	private static final class Record {
		private int index_widget, index_map, index_compass;
		private final int[] indices_tabs = new int[17];
		private final Client client;

		private Record() {
			client = Context.client();
			index_widget = -1;
			index_map = -1;
			index_compass = -1;
			for (int i = 0; i < 17; i++) {
				indices_tabs[i] = -1;
			}
		}
	}
}
