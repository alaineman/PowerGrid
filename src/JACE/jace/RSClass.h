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

#ifndef JACE_RSCLASS_H
#define JACE_RSCLASS_H

#include "jace/os_dep.h"
#include "jace/JClassImpl.h"
#include "jace/JNIException.h"

#include <string>
using std::string;

#include <QMap>
#include <QString>

namespace jace {
/**
 * @brief JClass representative for RS classes
 *
 * This class represents a Runescape class.
 * It contains lookup tables to match the simple names used in the C++ client
 * with the real, obfuscated names as they exist in the Runescape client.
 *
 * @author Patrick Kramer
 */
class RSClass : public jace::JClassImpl {
  private:
    QString simpleName;
    QMap<QString, QString> fieldMap;
    QMap<QString, int> modifierMap;
  public:
    /**
     * @brief Creates a new RSClass instance from the provided data
     * @param name the real (obfuscated) name of the class
     * @param simpleName the simple name of the class
     * @param fMap the map with field names
     * @param mMap the map with modifer values
     */
    JACE_API RSClass(const string name, const QString simpleName, QMap<QString, QString> fMap, QMap<QString, int> mMap);
    JACE_API virtual ~RSClass() throw() {}

    /**
     * @brief Returns the simple name for this RSClass
     * @return the simple name for this RSClass
     */
    JACE_API virtual const QString &getSimpleName() const;
    /**
     * @brief Returns the real name for the given field.
     *
     * If the field cannot be mapped, a Mapping UnavailableException is thrown
     * that contains the failed binding as message. This means that at some point
     * in code, this type of exception must be handled.
     *
     * @param name the simple field name
     * @return the real (obfuscated) name of the field
     * @throws MappingUnavailableException when the field is not mapped
     */
    JACE_API string getFieldName(QString name) const;
    /**
     * @brief Returns the modifier for the give field
     *
     * If the modifier is not mapped, this method returns \c 1,
     * in order to allow primitive fields that have no modifier
     * to be accessed in the same way as fields with a modifier.
     *
     * Note that this means that, in cases where the field is mapped,
     * but the corresponding modifier is not, this will not throw,
     * and instead the resulting field value may be invalid. However,
     * since we assume that the modifier is mapped when the field name
     * is mapped, such cases should not occur in practice.
     *
     * @param simpleName the simple field name
     * @return the modifier value for the field
     */
    JACE_API int getFieldModifier(QString simpleName) const;
};

}
#endif // JACE_RSCLASS_H
