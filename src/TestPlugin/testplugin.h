#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include "testplugin_global.h"
#include <QObject>
#include "pgplugin.h"
#include "entity/classifier.h"

namespace plugins {
namespace examples {

using entity::Classifier;

class TESTPLUGINSHARED_EXPORT TestPlugin : public QObject, public PGPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PGPlugin_iid FILE "testplugin.json")
    Q_INTERFACES(plugins::PGPlugin)
public:
    TestPlugin();
    ~TestPlugin();

    QList<TaskDescriptor*> tasks() const;
    QList<Classifier*> classifiers() const;

    QString name() const { return QStringLiteral("Test Plugin"); }
    QList<QString> authors() const {
        return QList<QString>({"Alaineman", "Chronio"});
    }

    QString description() const {
        return QStringLiteral(
                    "This Plugin contains some dummy tasks to illustrate the "
                    "different features of the Plugin Framework. It is mainly "
                    "designed for the purpose of UI-related testing, and features "
                    "little to none practically useful tasks."
               );
    }
};

}
}

#endif // TESTPLUGIN_H
