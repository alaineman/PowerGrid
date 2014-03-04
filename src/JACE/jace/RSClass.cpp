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

#include "RSClass.h"
#include "MappingUnavailableException.h"
using std::string;

namespace jace {
/**
 * Creates a new RSClass with the given name and type name.
 *
 * @param name - The name of this class, suitable for use in
 *               a call to JNIEnv::FindClass.
 * @param simpleName the simple (semantic) name of the RSClass
 */
RSClass::RSClass(const string name, const QString simpleName, QMap<QString, QString> fMap, QMap<QString, int> mMap) :
  JClassImpl(name),
  simpleName (simpleName),
  fieldMap (fMap),
  modifierMap (mMap ) {
}

const QString &RSClass::getSimpleName() const {
  return simpleName;
}

string RSClass::getFieldName(QString name) const {
    QMap<QString, QString>::const_iterator it = fieldMap.find(name);
    if (it == fieldMap.cend()) {
        throw MappingUnavailableException(simpleName + name);
    }
    return it.value().toStdString();
}

int RSClass::getFieldModifier(QString simpleName) const {
    QMap<QString, int>::const_iterator it = modifierMap.find(simpleName);
    if (it == modifierMap.cend()) {
        return 1; // equivalent to no modifier ( f*1 == f )
    } else {
        return it.value();
    }
}

}
