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

#include <QMap>
#include "entity/task.h"

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
 * The protected @c setXPGain(Skill,uint) member function should be
 * called once in the constructor of any subclass, for each Skill
 * it trains.
 */
class SkillTrainer : public entity::Task {
    Q_OBJECT
private:
    QMap<Skill,uint> xpMap;
protected:
    /**
     * @brief Sets the amount of XP this Task yields for the specified Skill.
     *
     * @param s          - The Skill this Task trains
     * @param expectedXP - The amount of XP earned for the Skill.
     */
    void setXPGain(Skill s, uint expectedXP) { xpMap.insert(s, expectedXP); }
public:
    SkillTrainer(QString name, entity::Task *parent) : Task(name, parent) {}
    /**
     * @brief The amount of experience this SkillTrainer yields when executed.
     *
     * @param s the Skill for which to get the amount of experience.
     * @return The amount of experience
     */
    uint getXP(Skill s) const { return xpMap.value(s, 0); }
};

#endif // SKILLTRAINER_H
