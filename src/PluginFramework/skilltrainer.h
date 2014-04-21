#ifndef SKILLTRAINER_H
#define SKILLTRAINER_H

#include <QtGlobal>

/**
 * @brief enum representation of all Runescape Skills.
 *
 * Represents all 26 Skills currently available to train in Runescape.
 */
enum Skill {
    Attack = 0,
    Strength,
    Defence,
    Ranged,
    Prayer,
    Magic,
    Constitution,
    Summoning,
    Mining,
    Fishing,
    Woodcutting,
    Farming,
    Hunter,
    Divination,
    Herblore,
    Crafting,
    Fletching,
    Smithing,
    Cooking,
    Firemaking,
    Runecrafting,
    Construction,
    Agility,
    Thieving,
    Slayer,
    Dungeoneering
};

/**
 * @brief the SkillTrainer class
 *
 * Instances of this class can be used to train skills.
 * The single member function of this class can be overridden to provide the correct amount of experience rewarded.
 */
class SkillTrainer {
public:
    /**
     * @brief The amount of experience this SkillTrainer yields when executed.
     *
     * The default implementation returns 0 for all skills. This should be overridden for
     * relevant Skills to return the correct amount of experience for a task. For example,
     * to indicate the SkillTrainer provides 20 Mining experience, override this member
     * function using template specialization as follows:
     *
     *     template<> uint getXP<Mining>() { return 20; }
     *
     * @param S the Skill for which to get the amount of experience.
     * @return The amount of experience
     *
     */
    template <Skill s> uint getXP() const { return 0; }
};

#endif // SKILLTRAINER_H
