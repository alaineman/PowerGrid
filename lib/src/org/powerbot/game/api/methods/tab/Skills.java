package org.powerbot.game.api.methods.tab;

import org.powerbot.game.api.methods.Widgets;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import org.powerbot.game.bot.Context;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.Skill;

/**
 * @author Timer
 */
public class Skills {
	public static final int[] XP_TABLE = {0, 0, 83, 174, 276, 388, 512, 650, 801, 969, 1154, 1358, 1584, 1833, 2107,
			2411, 2746, 3115, 3523, 3973, 4470, 5018, 5624, 6291, 7028, 7842, 8740, 9730, 10824, 12031, 13363, 14833,
			16456, 18247, 20224, 22406, 24815, 27473, 30408, 33648, 37224, 41171, 45529, 50339, 55649, 61512, 67983,
			75127, 83014, 91721, 101333, 111945, 123660, 136594, 150872, 166636, 184040, 203254, 224466, 247886, 273742,
			302288, 333804, 368599, 407015, 449428, 496254, 547953, 605032, 668051, 737627, 814445, 899257, 992895,
			1096278, 1210421, 1336443, 1475581, 1629200, 1798808, 1986068, 2192818, 2421087, 2673114, 2951373, 3258594,
			3597792, 3972294, 4385776, 4842295, 5346332, 5902831, 6517253, 7195629, 7944614, 8771558, 9684577, 10692629,
			11805606, 13034431, 14391160, 15889109, 17542976, 19368992, 21385073, 23611006, 26068632, 28782069,
			31777943, 35085654, 38737661, 42769801, 47221641, 52136869, 57563718, 63555443, 70170840, 77474828,
			85539082, 94442737, 104273167};

	public static final int ATTACK = 0;
	public static final int DEFENSE = 1;
	public static final int STRENGTH = 2;
	public static final int CONSTITUTION = 3;
	public static final int RANGE = 4;
	public static final int PRAYER = 5;
	public static final int MAGIC = 6;
	public static final int COOKING = 7;
	public static final int WOODCUTTING = 8;
	public static final int FLETCHING = 9;
	public static final int FISHING = 10;
	public static final int FIREMAKING = 11;
	public static final int CRAFTING = 12;
	public static final int SMITHING = 13;
	public static final int MINING = 14;
	public static final int HERBLORE = 15;
	public static final int AGILITY = 16;
	public static final int THIEVING = 17;
	public static final int SLAYER = 18;
	public static final int FARMING = 19;
	public static final int RUNECRAFTING = 20;
	public static final int HUNTER = 21;
	public static final int CONSTRUCTION = 22;
	public static final int SUMMONING = 23;
	public static final int DUNGEONEERING = 24;

	public static final int WIDGET = 320;
	public static final int WIDGET_ATTACK = 1;
	public static final int WIDGET_DEFENSE = 18;
	public static final int WIDGET_STRENGTH = 4;
	public static final int WIDGET_CONSTITUTION = 2;
	public static final int WIDGET_RANGE = 35;
	public static final int WIDGET_PRAYER = 53;
	public static final int WIDGET_MAGIC = 66;
	public static final int WIDGET_COOKING = 47;
	public static final int WIDGET_WOODCUTTING = 78;
	public static final int WIDGET_FLETCHING = 72;
	public static final int WIDGET_FISHING = 29;
	public static final int WIDGET_FIREMAKING = 65;
	public static final int WIDGET_CRAFTING = 59;
	public static final int WIDGET_SMITHING = 16;
	public static final int WIDGET_MINING = 3;
	public static final int WIDGET_HERBLORE = 23;
	public static final int WIDGET_AGILITY = 10;
	public static final int WIDGET_THIEVING = 41;
	public static final int WIDGET_SLAYER = 85;
	public static final int WIDGET_FARMING = 91;
	public static final int WIDGET_RUNECRAFTING = 79;
	public static final int WIDGET_HUNTER = 103;
	public static final int WIDGET_CONSTRUCTION = 97;
	public static final int WIDGET_SUMMONING = 109;
	public static final int WIDGET_DUNGEONEERING = 115;

	@Deprecated
	/**
	 * @see #getTopLevels()
	 */
	public static int[] getLevels() {
		return getTopLevels();
	}

	public static int[] getTopLevels() {
		final Client client = Context.client();
		final Skill[] skills = client.getPlayerMetaInfo().getSkills();
		final int[] levels = new int[skills.length];
		for (int i = 0; i < skills.length; i++) {
			if (skills[i] != null) {
				levels[i] = skills[i].getLevel();
			} else {
				levels[i] = -1;
			}
		}
		return levels;
	}

	public static int[] getBottomLevels() {
		final Client client = Context.client();
		final Skill[] skills = client.getPlayerMetaInfo().getSkills();
		final int[] levels = new int[skills.length];
		for (int i = 0; i < skills.length; i++) {
			if (skills[i] != null) {
				levels[i] = skills[i].getRealLevel();
			} else {
				levels[i] = -1;
			}
		}
		return levels;
	}

	public static int[] getExperiences() {
		final Client client = Context.client();
		final Skill[] skills = client.getPlayerMetaInfo().getSkills();
		final int[] exparr = new int[skills.length];
		for (int i = 0; i < skills.length; i++) {
			if (skills[i] != null) {
				exparr[i] = skills[i].getExperience();
			} else {
				exparr[i] = -1;
			}
		}
		return exparr;
	}

	public static int getLevelAt(final int exp) {
		for (int i = Skills.XP_TABLE.length - 1; i > 0; i--) {
			if (exp > Skills.XP_TABLE[i]) {
				return i;
			}
		}
		return 1;
	}

	public static int getLevel(final int index) {
		return getTopLevels()[index];
	}

	public static int getRealLevel(final int index) {
		final int level = Skills.getLevelAt(getExperience(index));
		if (index != DUNGEONEERING && level > 99) {
			return 99;
		}
		return level;
	}

	public static int getExperience(final int index) {
		return getExperiences()[index];
	}

	public static int getExperienceRequired(final int lvl) {
		if (lvl > 120) {
			return -1;
		}
		return Skills.XP_TABLE[lvl];
	}

	public static int getExperienceToLevel(final int index, final int endLvl) {
		if (endLvl >= Skills.XP_TABLE.length) {
			return -1;
		}
		return getExperienceRequired(endLvl) - getExperience(index);
	}

	/**
	 * The Widget of the Skills tab.
	 */
	public static Widget getWidget() {
		return Widgets.get(WIDGET);
	}

	/**
	 * Gets the skill widget child at given index.
	 *
	 * @param widgetIndex The index of the widget child.
	 * @return the WidgetChild of the skill at the given index.
	 */
	public static WidgetChild getWidgetChild(final int widgetIndex) {
		return Widgets.get(WIDGET, widgetIndex);
	}
}
