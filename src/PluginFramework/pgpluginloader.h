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
    /**
     * @brief Creates a new PluginLoader that loads all plugins in the specified directory.
     *
     * Passing an empty string causes this PluginLoader to load from the default directory.
     * @param dir the directory to load from
     */
    PGPluginLoader(QString dir = "");

    /**
     * @brief Returns the directory this PGPluginLoader loads from
     */
    QString directory() const;
    /**
     * @brief Sets the directory to load from
     * @param dir the new directory to load from
     */
    void setDirectory(QString dir);

    /**
     * @brief Returns whether the plugins are loaded
     */
    bool isLoaded() const { return loaded; }

    /**
     * @brief Loads all plugins in directory().
     */
    void loadPlugins();
    /**
     * @brief Unloads all Plugins in this PluginLoader.
     */
    void unloadPlugins();

    /**
     * @brief Returns a list of all loaded Plugin instances.
     */
    QList<PGPlugin*> plugins();
};

}
#endif // PGPLUGINLOADER_H
