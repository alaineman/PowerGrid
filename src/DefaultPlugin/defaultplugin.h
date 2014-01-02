#ifndef DEFAULTPLUGIN_H
#define DEFAULTPLUGIN_H

#include "defaultplugin_global.h"
#include <QObject>
#include <plugin.h>

namespace plugins {

  namespace powergrid {
    class DEFAULTPLUGIN_EXPORT DefaultPlugin : public QObject, PGPlugin {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "net.pgrid.plugins.powergrid.DefaultPlugin")
        Q_INTERFACES(plugins::PGPlugin)
      public:
        virtual QList<TaskDescriptor*> tasks() const;
        virtual QString name() const { return "Default Plugin"; }
    };
  }
}

#endif // DEFAULTPLUGIN_H
