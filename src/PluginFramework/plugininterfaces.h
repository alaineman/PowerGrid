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

// Convenience macro defining an inequality check for classes that define operator==
#define INSERT_NOT_EQUALS(Type) \
bool operator !=(Type other) { \
  return !this->operator ==(other); \
}

namespace plugins {

#define TaskDescriptor_iid "net.pgrid.plugins.TaskDescriptor"
  /// Descriptor for a Task implementation
  class TaskDescriptor : public QObject {
      Q_OBJECT
      Q_DISABLE_COPY(TaskDescriptor)
    private:
      QString nm;
      QString desc;
    public:
      TaskDescriptor(QString taskName, QString taskDescription) : QObject(),
         nm(taskName), desc(taskDescription) {}

      virtual ~TaskDescriptor();

      /// name for this Task
      virtual QString name() const Q_DECL_NOTHROW { return nm; }
      /// description for this Task
      virtual QString description() const Q_DECL_NOTHROW { return desc; }

      /// operator overload checking equality
      bool operator ==(TaskDescriptor other) const Q_DECL_NOTHROW {
        return nm == other.name() && desc == other.description();
      }

      INSERT_NOT_EQUALS(TaskDescriptor)
  };

#define Task_iid "net.pgrid.plugins.Task"
  /// Task interface describing a single operation
  class Task : public QObject {
      Q_OBJECT
    public:
      virtual ~Task();

      /// Runs the Task
      virtual void run() = 0;

      /// Returns this Task's TaskDescriptor
      virtual const TaskDescriptor* descriptor() const Q_DECL_NOTHROW = 0;

      bool operator ==(Task& other) const Q_DECL_NOTHROW {
        return descriptor() == other.descriptor();
      }

      INSERT_NOT_EQUALS(Task&)
  };

#define Plugin_iid "net.pgrid.plugins.Plugin"
  /// Plugin interface identifying the Tasks in the Plugin
  class Plugin : public QObject {
      Q_OBJECT
    private:
      QString name;
    public:
      /// Creates a new Plugin with the given name
      Plugin(QString pluginName) : name(pluginName) {}

      virtual ~Plugin();

      /// The name of the Plugin
      QString pluginName() const Q_DECL_NOTHROW { return name; }

      /// Lists the Descriptors of the available Tasks in this Plugin
      virtual QList<TaskDescriptor*> availableTasks() const Q_DECL_NOTHROW = 0;

      /** Creates and returns a Task based on the given TaskDescriptor
       *  @return the Task, or null if creating the Task failed.
       *  @throws std::runtime_error when creating a Task failed.
       */
      virtual Task* create(const TaskDescriptor*) = 0;
  };

}

Q_DECLARE_INTERFACE(plugins::TaskDescriptor, TaskDescriptor_iid)
Q_DECLARE_INTERFACE(plugins::Task,           Task_iid)
Q_DECLARE_INTERFACE(plugins::Plugin,         Plugin_iid)

#endif // PLUGININTERFACES_H
