#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QString>
#include <QList>
#include "taskdescriptor.h"

namespace plugins {
  /**
   * @brief Interface defining a PowerGrid plugin
   */
  class PGPlugin {
    public:
      /**
       * @brief Returns a list of TaskDescriptors
       * The TaskDescriptors returned can be used
       * to create and run Task
       * @return a list of TaskDescriptors
       */
      virtual QList<TaskDescriptor> tasks() const = 0;

      /**
       * @brief Returns the name of this plugin
       * @return the name of this plugin
       */
      virtual QString name() const = 0;
  };
}

#define PGPlugin_iid "net.pgrid.plugins.PGPlugin"
Q_DECLARE_INTERFACE(plugins::PGPlugin, PGPlugin_iid)

#endif // PLUGIN_H
