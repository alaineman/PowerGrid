#ifndef PLUGININTERFACES_H
#define PLUGININTERFACES_H

#include <QtPlugin>

#include <stdexcept>

class QList;

namespace plugins {

#define TaskDescriptor_iid "net.pgrid.plugins.TaskDescriptor"
  /// Descriptor for a Task implementation
  class TaskDescriptor {
    public:
      virtual ~TaskDescriptor() {}

      /// ID for this Task
      virtual int taskID() const Q_DECL_NOTHROW = 0;
      /// name for this Task
      virtual QString name() const Q_DECL_NOTHROW = 0;
      /// description for this Task
      virtual QString description() const Q_DECL_NOTHROW = 0;
  };

#define Task_iid "net.pgrid.plugins.Task"
  /// Task interface describing a single operation
  class Task {
    public:
      virtual ~Task() {}

      /// Runs the Task
      virtual void run() = 0;

      /// Returns this Task's TaskDescriptor
      virtual TaskDescriptor descriptor() const Q_DECL_NOTHROW = 0;
  };

#define Plugin_iid "net.pgrid.plugins.Plugin"
  /// Plugin interface identifying the Tasks in the Plugin
  class Plugin {
    public:
      virtual ~Plugin() {}

      /// Lists the Descriptors of the available Tasks in this Plugin
      virtual QList<TaskDescriptor> availableTasks() const Q_DECL_NOTHROW = 0;
      /** Creates and returns a Task based on the given TaskDescriptor
       *  @return the Task, or null if creating the Task failed.
       *  @throws std::runtime_error when creating a Task failed.
       */
      virtual Task create(TaskDescriptor) throw(std::runtime_error) = 0;
  };

}

Q_DECLARE_INTERFACE(plugins::TaskDescriptor, TaskDescriptor_iid)
Q_DECLARE_INTERFACE(plugins::Task,           Task_iid)
Q_DECLARE_INTERFACE(plugins::Plugin,         Plugin_iid)

#endif // PLUGININTERFACES_H
