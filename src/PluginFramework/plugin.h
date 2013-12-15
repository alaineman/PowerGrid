#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QString>
#include <QList>
#include "taskdescriptor.h"

namespace plugins {
  class PGPlugin {
    public:
      virtual QList<TaskDescriptor> tasks() const = 0;
      virtual QString name() const = 0;
  };
}

#define PGPlugin_iid "net.pgrid.plugins.PGPlugin"
Q_DECLARE_INTERFACE(plugins::PGPlugin, PGPlugin_iid)

#endif // PLUGIN_H
