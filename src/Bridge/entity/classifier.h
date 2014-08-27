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
#ifndef PLUGINS_CLASSIFIER_H
#define PLUGINS_CLASSIFIER_H

#include <QObject>

namespace entity {

class Entity;
/**
 * @brief Interface for classifying Entity types.
 *
 * Classifiers recognize and assign Components to Entities
 * to allow other classes to process these Entities
 * according to their properties.
 *
 * Entities originating from the Runescape overworld can be assumed to
 * have Position and ID Components already assigned. Other Components
 * may or may not already be assigned depending on the order in which
 * the various Classifiers are invoked.
 */
class Classifier : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Classifier)
public:
    Classifier() {}
public slots:
    /**
     * \brief Processes the provided Entity.
     *
     * This assigns Components to this Entity based on
     * the Entity's already existing properties.
     *
     * \param e the Entity to process
     */
    virtual void process(entity::Entity* e) = 0;
};

} // namespace plugins

#endif // PLUGINS_CLASSIFIER_H
