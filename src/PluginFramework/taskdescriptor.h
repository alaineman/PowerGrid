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
#ifndef TASKDESCRIPTOR_H
#define TASKDESCRIPTOR_H

#include <QObject>
#include <QString>

namespace plugins {

  class Task;

  /**
   * @brief Describes a Task type
   * TaskDescriptors serve to describe task types.
   * They have a name and description to identify
   * the Task they represent. They are also
   * responsible for instantiating the Tasks they
   * represent.
   */
  class TaskDescriptor : public QObject {
      Q_OBJECT

      QString nm;
      QString desc;
    public:
      /**
       * @brief Creates a new TaskDescriptor
       * @param name        the name of the Task type
       * @param description the description of the Task
       */
      TaskDescriptor(QString name, QString description);

      /**
       * \brief Executes the Task of this TaskDescriptor.
       *
       * Note for Plugin developers: It is possible either
       * implement this function for a Task, or subclass
       * Task itself and override @c execute there. Either way will
       * work. Note that if you subclass Task, you will have to
       * override this TaskDescriptor's @c createTask() function
       * to return an instance of your subclass.
       *
       * Subclassing Task gives the advantage of having a separate object
       * for each time the Task is executed. This allows Tasks of the
       * same type to be configured differently. When implementing the
       * @c execute() here, this is not possible.
       *
       * Also note that if the Task's execute() and this function are both
       * overridden (and createTask is overridden as required), then the
       * Task's execute will always be invoked.
       */
      virtual void execute() {}

      /**
       * \brief Returns a cost estimate for this TaskDescriptor in milliseconds.
       *
       * Similar to execute() this function can be overridden in both TaskDescriptor
       * and Task, and the implementation of Task takes precedence over this one.
       *
       * The default return value is the maximum value of the quint64 data type.
       * \return the expected duration of the TaskDescriptor's execute().
       */
      virtual quint64 cost() const throw();

      /**
       * @brief The name of the Task type
       * @return the name of the Task type
       */
      QString name() const { return nm; }
      /**
       * @brief The description of the Task type
       * @return the description of the Task type
       */
      QString description() const { return desc; }

      /**
       * @brief Creates a new Task instance.
       *
       * The caller is responsible for proper
       * deletion of the returned Task*.
       *
       * @return a pointer to a Task instance
       */
      virtual Task* createTask();
  };
}
#endif // TASKDESCRIPTOR_H
