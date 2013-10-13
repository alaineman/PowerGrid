#ifndef POWERGRIDPLUGIN_H
#define POWERGRIDPLUGIN_H

#include "plugininterfaces.h"

#include <QList>

namespace plugins {

  class DummyTask : Task, TaskDescriptor {
      Q_OBJECT
      Q_PLUGIN_METADATA(IID "net.pgrid.plugins.default.DummyTask")
      Q_INTERFACES(Task TaskDescriptor)

    public:
      DummyTask();
      ~DummyTask();

      void run();

      TaskDescriptor descriptor() { return *this; }

      int taskID() const Q_DECL_NOTHROW { return 0; }
      QString name() const Q_DECL_NOTHROW {
        return QStringLiteral("DummyTask");
      }
      QString description() const Q_DECL_NOTHROW {
        return QStringLiteral(
              "A Dummy Task illustrating the PowerGrid plugin framework.");
      }
  };

  class PowerGridPlugin : Plugin {
      Q_OBJECT
      Q_PLUGIN_METADATA(IID "net.pgrid.plugins.default.PowerGridPlugin")
      Q_INTERFACES(Plugin)

    public:
      PowerGridPlugin();
      ~PowerGridPlugin();

      QList<TaskDescriptor> availableTasks();
      // The dummy task is its own descriptor and thread-safe. As such, we can simply
      // (and safely) cast the input parameter using qobject_cast.
      virtual Task create(TaskDescriptor desc) { return qobject_cast<Task>(desc); }
  };

}

#endif // POWERGRIDPLUGIN_H
