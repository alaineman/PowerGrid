#include "taskdescriptor.h"
#include "task.h"

#include <limits>

namespace plugins {
  TaskDescriptor::TaskDescriptor(QString name, QString description) :
    nm(name), desc(description) {}

  quint64 TaskDescriptor::cost() const throw() {
      return std::numeric_limits<quint64>::max();
  }

  Task* TaskDescriptor::createTask() {
    return new Task(nm, desc, this);
  }
}
