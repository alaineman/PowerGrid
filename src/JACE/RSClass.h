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

#ifndef RSCLASS_H
#define RSCLASS_H

#include "jace/os_dep.h"
#include "jace/JClassImpl.h"
#include "jace/JNIException.h"

#include <string>
using std::string;

#include <QMap>
#include <QString>

class RSClass : public jace::JClassImpl {
  private:
    QString simpleName;
    QMap<QString, QString> fieldMap;
    QMap<QString, int> modifierMap;
  public:
    JACE_API RSClass(const string name, const QString simpleName, QMap<QString, QString> fMap, QMap<QString, int> mMap);
    JACE_API virtual ~RSClass() throw() {}

    JACE_API virtual const QString &getSimpleName() const;
    JACE_API string getFieldName(QString name) const;
    JACE_API int getFieldModifier(QString simpleName) const;
};

#endif // RSCLASS_H
