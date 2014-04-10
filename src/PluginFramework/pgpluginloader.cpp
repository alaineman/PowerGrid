#include "pgpluginloader.h"
#include <stdexcept>
#include <QDir>
#include <QDirIterator>

using namespace std;

namespace plugins {

PGPluginLoader::PGPluginLoader(QString dir)
    : directoryName(dir), loaded(false) {
}

PGPluginLoader::~PGPluginLoader() throw() {
    // Delete all QPluginLoader instances.
    unloadPlugins();
}

QString PGPluginLoader::directory() const {
    return directoryName;
}

void PGPluginLoader::setDirectory(QString dir) {
    directoryName = dir;
}

void PGPluginLoader::loadPlugins() {
    if (loaded) {
        unloadPlugins();
    }
    QDir dir (directoryName);
    if (dir.exists()) {
        QDirIterator it (dir);
        while (it.hasNext()) {
            QString file = it.next();
            QPluginLoader* loader = new QPluginLoader(file);
            pluginList.append(loader);
        }
    }
}

void PGPluginLoader::unloadPlugins() {
    if (loaded) {
        QList<QPluginLoader*>::Iterator it = pluginList.begin();
        for (;it != pluginList.end(); it++) {
            if (*it) {
                (*it)->unload();
                delete (*it);
            }
        }
        pluginList.clear();
    }
}

QList<PGPlugin*> PGPluginLoader::plugins() const {
    QList<PGPlugin*> ps;
    for (int i=0;i<pluginList.size();i++) {
        QPluginLoader* loader = pluginList.at(i);
        if (loader) {
            PGPlugin* pgplugin = qobject_cast<PGPlugin*>(loader->instance());
            if (pgplugin) {
                ps.append(pgplugin);
            }
        }
    }
    return ps;
}

}
