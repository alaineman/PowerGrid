package org.powerbot.game.api.wrappers.interactive;

import java.lang.ref.SoftReference;

import org.powerbot.game.client.RSPlayer;
import org.powerbot.game.client.RSPlayerComposite;

/**
 * @author Timer
 */
public class Player extends Character {
	private final SoftReference<RSPlayer> p;

	public Player(final RSPlayer p) {
		this.p = new SoftReference<RSPlayer>(p);
	}

	public int getLevel() {
		return get().getLevel();
	}

	public String getName() {
		return get().getName();
	}

	public int getTeam() {
		return get().getTeam();
	}

	public int getPrayerIcon() {
		return get().getPrayerIcon();
	}

	public int getSkullIcon() {
		return get().getSkullIcon();
	}

	public int getNpcId() {
		final RSPlayerComposite composite = get().getComposite();
		return composite == null ? -1 : composite.getNPCID();
	}

	public int getId() {
		return getName().hashCode();
	}

	public int[] getAppearance() {
		final RSPlayerComposite composite = get().getComposite();
		if (composite != null) {
			final int[] appearance = composite.getEquipment().clone();
			for (int i = 0; i < appearance.length; i++) {
				if ((appearance[i] & 0x40000000) > 0) {
					appearance[i] &= 0x3fffffff;
				} else {
					appearance[i] = -1;
				}
			}
			return appearance;
		}
		return null;
	}

	public RSPlayer get() {
		return p.get();
	}
}
