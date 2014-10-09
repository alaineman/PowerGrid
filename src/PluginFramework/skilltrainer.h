/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
     *     template<> virtual uint getXP<Mining>() { return 20; }
     *
     * @param s the Skill for which to get the amount of experience.
     * @return The amount of experience
     *
     */
    template <Skill s>
    virtual uint getXP() const { return 0; }
};

#endif // SKILLTRAINER_H
