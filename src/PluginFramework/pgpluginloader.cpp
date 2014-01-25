#include "pgpluginloader.h"
#include <stdexcept>
#include <QDir>

using namespace std;

namespace plugins {

PGPluginLoader::PGPluginLoader(QString dir)
    : directoryName(dir), loaded(false) {
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
            QPluginLoader loader (file);
            pluginList.append(loader);
        }
    }
}

void PGPluginLoader::unloadPlugins() {
    if (loaded) {
        QList<QPluginLoader>::Iterator it = pluginList.begin();
        for (;it != pluginList.end(); it++) {
            (*it).unload();
        }
        pluginList.clear();
    }
}

QList<PGPlugin*> PGPluginLoader::plugins() {
    if (!loaded) {
        loadPlugins();
    }
    QList<PGPlugin*> ps;
    for (int i=0;i<pluginList.size();i++) {
        QPluginLoader loader = pluginList[i];
        QObject* obj = loader.instance();
        if (obj) {
            PGPlugin* pgplugin = qobject_cast<PGPlugin*>(obj);
            if (pgplugin) {
                ps.append(pgplugin);
            }
        }
    }
    return ps;
}
}
