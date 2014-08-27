/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
