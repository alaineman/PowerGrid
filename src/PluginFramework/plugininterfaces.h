#ifndef PLUGININTERFACES_H
#define PLUGININTERFACES_H

#include <QtPlugin>

#include <stdexcept>

#include <QList>

// Convenience function for creating singleton QLists

template <typename T> QList<T> CreateQListSingleton(T elem) {
  QList<T> ql ();
  ql.append(elem);
  return ql;
}

// Convenience macro using initializer lists, or the above defined 
// function depending on the compiler
#ifdef Q_COMPILER_INITIALIZER_LISTS
  // The compiler supports initializer lists, so use that QList constructor
  #define QListSingleton(e) QList({e})
#else
  // fall back on the CreateQListSingleton function
  #define QListSingleton(e) CreateQListSingleton(e)
#endif

namespace plugins {

#define TaskDescriptor_iid "net.pgrid.plugins.TaskDescriptor"
  /// Descriptor for a Task implementation
  class TaskDescriptor {
    public:
      virtual ~TaskDescriptor();

      /// name for this Task
      virtual QString name() const Q_DECL_NOTHROW = 0;
      /// description for this Task
      virtual QString description() const Q_DECL_NOTHROW = 0;
  };

#define Task_iid "net.pgrid.plugins.Task"
  /// Task interface describing a single operation
  class Task {
    public:
      virtual ~Task();

      /// Runs the Task
      virtual void run() = 0;

      /// Returns this Task's TaskDescriptor
      virtual TaskDescriptor* descriptor() const Q_DECL_NOTHROW = 0;
  };

#define Plugin_iid "net.pgrid.plugins.Plugin"
  /// Plugin interface identifying the Tasks in the Plugin
  class Plugin {
    public:
      virtual ~Plugin();

      /// The name of the Plugin
      virtual QString pluginName() const Q_DECL_NOTHROW = 0;

      /// Lists the Descriptors of the available Tasks in this Plugin
      virtual QList<TaskDescriptor> availableTasks() const Q_DECL_NOTHROW = 0;
      /** Creates and returns a Task based on the given TaskDescriptor
       *  @return the Task, or null if creating the Task failed.
       *  @throws std::runtime_error when creating a Task failed.
       */
      virtual Task& create(const TaskDescriptor&) throw(std::runtime_error) = 0;
  };

}

Q_DECLARE_INTERFACE(plugins::TaskDescriptor, TaskDescriptor_iid)
Q_DECLARE_INTERFACE(plugins::Task,           Task_iid)
Q_DECLARE_INTERFACE(plugins::Plugin,         Plugin_iid)

#endif // PLUGININTERFACES_H
