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
#ifndef ENTITY_TASKFACTORY_H
#define ENTITY_TASKFACTORY_H

#include <QString>
#include <QObject>
#include <QHash>

namespace entity {

class Task;

/**
 * @brief Factory class for Tasks
 *
 * This class acts as a superclass for Factory classes that create Tasks.
 *
 * Each TaskFactory represents a single Task type that can be instantiated.
 * TaskFactories operate asynchronously, and can make use of UIs to allow
 * users to configure the Task beforehand.
 *
 */
class TaskFactory : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Creates a new TaskFactory instance
     * @param parent - the parent of this TaskFactory
     */
    TaskFactory(QObject* parent = NULL);

    /**
     * @brief Returns the name of Tasks created by this TaskFactory.
     * @return a string with the name
     */
    virtual QString     taskName()        const = 0;
    /**
     * @brief Returns a description of Tasks created by this TaskFactory.
     * @return a string with the description
     */
    virtual QString     taskDescription() const = 0;
    /**
     * @brief Returns the author(s) of this Task.
     * @return a list of author names
     */
    virtual QStringList taskAuthors()     const = 0;

signals:
    /**
     * @brief Signal emitted when the Task is successfully instantiated
     * @param task - The created Task
     */
    void preparationDone(Task* task);
    /**
     * @brief Signal emitted when the Task was canceled by the user
     *
     * This signal indicates (for example) that the user pressed the
     * 'cancel' button on the configuration GUI of this TaskFactory
     */
    void preparationCanceled();
    /**
     * @brief Signal emitted to indicate that an error occurred.
     * @param description - a description of the error, suitable for end-users.
     */
    void preparationError(QString description);
public slots:
    /**
     * @brief Configures this Task and instantiates it.
     *
     * This member function can set up a UI, but should return
     * as soon as possible.
     *
     * The result is communicated asynchronously using signals/slots.
     * See the documentation for the signals of this class for
     * possible results.
     */
    virtual void prepareTask() = 0;
};

} // namespace entity

/**
 * @brief Hashing function for TaskFactory instances
 *
 * This allows TaskFactory pointers to be saved in a hashed
 * data structure (such as QHash or QSet).
 *
 * @param factory - the TaskFactory to compute a hash for
 * @param seed    - a seed for the hashing algorithm
 * @return the computed hash
 */
uint qHash(entity::TaskFactory* factory, uint seed = 0) {
    return factory ? qHash(factory->taskName(), seed) : 0;
}

#endif // ENTITY_TASKFACTORY_H
