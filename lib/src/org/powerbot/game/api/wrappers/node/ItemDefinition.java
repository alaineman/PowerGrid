package org.powerbot.game.api.wrappers.node;

import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.RSItemDef;

/**
 * @author Timer
 */
public class ItemDefinition implements Identifiable {
	private final RSItemDef definition;

	public ItemDefinition(final RSItemDef definition) {
		this.definition = definition;
	}

	public String getName() {
		try {
			return definition.getName();
		} catch (final ClassCastException ignored) {
		}
		return null;
	}

	public int getId() {
		try {
			return definition.getID();
		} catch (final ClassCastException ignored) {
		}
		return -1;
	}

	public boolean isMembers() {
		try {
			return definition.isMembersObject();
		} catch (final ClassCastException ignored) {
		}
		return false;
	}

	public String[] getActions() {
		try {
			return definition.getActions();
		} catch (final ClassCastException ignored) {
		}
		return null;
	}

	public String[] getGroundActions() {
		try {
			return definition.getGroundActions();
		} catch (final ClassCastException ignored) {
		}
		return null;
	}
}
