#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>

namespace plugins {

  class TaskDescriptor;

  /**
   * @brief Defines a Task
   * A Task is an object that performs a certain job.
   * Tasks are the smallest units of work in a PowerGrid
   * Plugin, and as such one Plugin can have many Tasks.
   */
  class Task : public QObject {
      Q_OBJECT

      QString nm;
      QString desc;
      TaskDescriptor* descriptor;
    public:
      /**
       * @brief Creates a Task
       * @param name the name of the Task
       * @param description the description of the Task
       */
      Task(QString name, QString description, TaskDescriptor* desc = 0);

      /**
       * @brief Returns the name of this Task
       * @return the name of this Task
       */
      QString name() const { return nm; }
      /**
       * @brief Returns the description of this Task
       * @return the description of this Task
       */
      QString description() const { return desc; }

      /**
       * \brief Returns a cost estimate (in ms) this Task will take to execute.
       * \return the estimated cost of the Task in milliseconds.
       */
      virtual quint64 cost() const throw();

      /**
       * @brief Executes the Task
       *
       * The default implementation calls @c execute() on the
       * TaskDescriptor provided when this Task was created.
       *
       * When no TaskDescriptor was provided, this implementation
       * throws an std::logic_error.
       */
      virtual void execute();
  };
}

#endif // TASK_H
