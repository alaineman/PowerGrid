#ifndef SKILLTRAINER_H
#define SKILLTRAINER_H

#include <QtGlobal>
/**
 * @brief Skill Enum
 *
 * Represents all current 26 Skills availabe to train in Runescape.
 */
enum Skill {
    Attack,
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
 * @brief The SkillTrainer class
 *
 */
class SkillTrainer {

public:
    /**
     * @brief Creates a new SkillTrainer object
     *
     */
    SkillTrainer();

    /**
     * @brief The xp goal corresponding to this SkillTrainer
     *
     * @return The amount of experience
     *
     */
    template <Skill S> uint getXP() const { return 0; }

};

#endif // SKILLTRAINER_H
