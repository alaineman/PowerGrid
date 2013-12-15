#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>

namespace plugins {

  class Task : public QObject {
      Q_OBJECT

      QString nm;
      QString desc;
    public:
      Task(QString name, QString description);

      QString name() const { return nm; }
      QString description() const { return desc; }
  };
}

#endif // TASK_H
