package org.powerbot.game.api.wrappers.node;

import org.powerbot.game.api.wrappers.Identifiable;
import org.powerbot.game.client.RSObjectDef;

/**
 * @author Timer
 */
public class SceneObjectDefinition implements Identifiable {
	private final RSObjectDef def;

	public SceneObjectDefinition(final RSObjectDef def) {
		this.def = def;
	}

	public String getName() {
		return def.getName();
	}

	public String[] getActions() {
		return def.getActions();
	}

	public int getId() {
		return def.getID();
	}
}
