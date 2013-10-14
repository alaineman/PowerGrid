#ifndef POWERGRIDPLUGIN_H
#define POWERGRIDPLUGIN_H

#include "plugininterfaces.h"

#include <QList>

namespace plugins {
  namespace standard {

    class DummyTask : public QObject, public Task, public TaskDescriptor {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "net.pgrid.plugins.default.DummyTask")
        Q_INTERFACES(Task TaskDescriptor)

      public:
        explicit DummyTask(QObject* parent = NULL) : QObject(parent) {}
        ~DummyTask();

        void run();

        TaskDescriptor* descriptor() { return this; }

        QString name() const Q_DECL_NOTHROW {
          return QStringLiteral("DummyTask");
        }
        QString description() const Q_DECL_NOTHROW {
          return QStringLiteral(
                "A Dummy Task illustrating the PowerGrid plugin framework.");
        }
    };

    class PowerGridPlugin : public QObject, public Plugin {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "net.pgrid.plugins.default.PowerGridPlugin")
        Q_INTERFACES(Plugin)

      public:
        explicit PowerGridPlugin(QObject* parent = NULL) : QObject(parent) {}
        ~PowerGridPlugin();

        QString pluginName() const Q_DECL_NOTHROW {
          return QStringLiteral("default PowerGrid Plugin");
        }

        QList<TaskDescriptor> availableTasks() { return QListSingleton(DummyTask()); }

        // The dummy task is its own descriptor and thread-safe. As such, we can simply
        // (and safely) cast the input parameter using qobject_cast.
        Task& create(const TaskDescriptor& desc) { return qobject_cast<Task>(desc); }
    };

  }
}

#endif // POWERGRIDPLUGIN_H
