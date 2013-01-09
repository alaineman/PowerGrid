package org.powerbot.game.api.wrappers.interactive;

import java.lang.ref.SoftReference;

import org.powerbot.game.client.RSNPC;
import org.powerbot.game.client.RSNPCDef;

/**
 * @author Timer
 */
public class NPC extends Character {
	private final SoftReference<RSNPC> n;

	public NPC(final RSNPC n) {
		this.n = new SoftReference<RSNPC>(n);
	}

	public int getLevel() {
		return get().getRSNPCDef().getLevel();
	}

	public String getName() {
		return get().getRSNPCDef().getName();
	}

	public int getId() {
		return get().getRSNPCDef().getID();
	}

	public String[] getActions() {
		return get().getRSNPCDef().getActions();
	}

	public RSNPC get() {
		return n.get();
	}
}
