#ifndef PLUGININTERFACES_H
#define PLUGININTERFACES_H

#include <QtPlugin>

#include <stdexcept>

class QList;

namespace plugins {

#define TaskDescriptor_iid "net.pgrid.plugins.TaskDescriptor"
  class TaskDescriptor {
    public:
      virtual ~TaskDescriptor() {}

      virtual int taskID() const Q_DECL_NOTHROW = 0;

      virtual QString name() const Q_DECL_NOTHROW = 0;
      virtual QString description() const Q_DECL_NOTHROW = 0;
  };

#define Task_iid "net.pgrid.plugins.Task"
  class Task {
    public:
      virtual ~Task() {}

      virtual void run() = 0;

      virtual TaskDescriptor descriptor() const Q_DECL_NOTHROW = 0;
  };

#define Plugin_iid "net.pgrid.plugins.Plugin"
  class Plugin {
    public:
      virtual ~Plugin() {}

      virtual QList<TaskDescriptor> availableTasks() const Q_DECL_NOTHROW = 0;

      virtual Task create(TaskDescriptor) throw(std::runtime_error) = 0;
  };

}

Q_DECLARE_INTERFACE(plugins::TaskDescriptor, TaskDescriptor_iid)
Q_DECLARE_INTERFACE(plugins::Task,           Task_iid)
Q_DECLARE_INTERFACE(plugins::Plugin,         Plugin_iid)

#endif // PLUGININTERFACES_H
