#include "task.h"
#include "taskdescriptor.h"

#include <stdexcept>
#include <limits>

namespace plugins {
  Task::Task(QString name, QString description, TaskDescriptor *desc) :
    nm(name), desc(description), descriptor(desc) {}

  quint64 Task::cost() const throw() {
      if (descriptor) {
          return 0;
      } else {
          return std::numeric_limits<quint64>::max();
      }
  }

  void Task::execute() {
      if (descriptor) {
          descriptor->execute();
      } else {
          throw std::logic_error("Task::execute not overridden and no TaskDescriptor provided");
      }
  }
}
