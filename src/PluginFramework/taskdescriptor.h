#ifndef TASKDESCRIPTOR_H
#define TASKDESCRIPTOR_H

#include <QObject>
#include <QString>

#include "mappingunavailableexception.h"

#include "task.h"

namespace plugins {
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
       * @brief Creates an instance of a Task
       * @return a Task instance
       */
      virtual Task createTask();
  };
}
#endif // TASKDESCRIPTOR_H
