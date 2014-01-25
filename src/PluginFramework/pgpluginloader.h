#ifndef PGPLUGINLOADER_H
#define PGPLUGINLOADER_H

#include <QString>
#include <QPluginLoader>
#include "plugin.h"


namespace plugins {

/**
 * @brief The PGPluginLoader class
 * This class tries to load the PGPlugins it finds in the
 * "plugins" directory
 */
class PGPluginLoader {
private:
    QString directoryName;
    QList<QPluginLoader*> pluginList;
    bool loaded;
public:
    PGPluginLoader(QString dir = "");

    QString directory() const;
    void setDirectory(QString dir);

    bool isLoaded() const { return loaded; }
    void loadPlugins();
    void unloadPlugins();

    QList<PGPlugin*> plugins();
};

}
#endif // PGPLUGINLOADER_H
