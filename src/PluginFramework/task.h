#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>

namespace plugins {
  /**
   * @brief Defines a Task
   * A Task is an object that performs a certain job.
   * Tasks are the smallest units of work in a PowerGrid
   * Plugin, and as such one Plugin can have many Tasks.
   *
   * Custom Tasks can be defined by overriding the run
   * member function. The default Task implementation
   * does nothing.
   */
  class Task : public QObject {
      Q_OBJECT

      QString nm;
      QString desc;
    public:
      /**
       * @brief Creates a Task
       * @param name the name of the Task
       * @param description the description of the Task
       */
      Task(QString name, QString description);

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
       * @brief Executes the Task
       * The default implementation does nothing.
       */
      virtual void run() {}
  };
}

#endif // TASK_H
