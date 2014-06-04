#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QString>
#include <QList>

using namespace std;

namespace entity {
 class Classifier;
}

using entity::Classifier;

namespace plugins {

  class TaskDescriptor;

  /**
   * @brief Interface defining a PowerGrid plugin
   */
  class PGPlugin {
    public:
      virtual ~PGPlugin() {}

      /**
       * @brief Returns a list of TaskDescriptors
       * The TaskDescriptors returned can be used
       * to create and run Tasks
       * @return a list of TaskDescriptors
       */
      virtual QList<TaskDescriptor*> tasks() const = 0;

      /**
       * @brief Returns a list of Classifiers this Plugin provides.
       *
       * The returned Classifiers can be used to detect Entities and
       * assign Components to them.
       * @return a list of Classifiers.
       */
      virtual QList<Classifier*> classifiers() const = 0;

      /**
       * @brief Returns the name of this plugin
       * @return the name of this plugin
       */
      virtual QString name() const = 0;

      /**
       * @brief Returns the author(s) of the plugin
       * @return a QList with the names of the authors
       *         of this PGPlugin
       */
      virtual QList<QString> authors() const = 0;

      /**
       * @brief Returns the description for this PGPlugin
       * @return the description for this Plugin
       */
      virtual QString description() const = 0;
  };
}

#define PGPlugin_iid "net.pgrid.plugins.PGPlugin"
Q_DECLARE_INTERFACE(plugins::PGPlugin, PGPlugin_iid)

#endif // PLUGIN_H
