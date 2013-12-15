#ifndef TASKDESCRIPTOR_H
#define TASKDESCRIPTOR_H

#include <QObject>
#include <QString>

#include "task.h"

namespace plugins {
  class TaskDescriptor : public QObject {
      Q_OBJECT

      QString nm;
      QString desc;
    public:
      TaskDescriptor(QString, QString);
      virtual ~TaskDescriptor() {}

      QString name() const { return nm; }
      QString description() const { return desc; }

      virtual Task create();
  };
}
#endif // TASKDESCRIPTOR_H
