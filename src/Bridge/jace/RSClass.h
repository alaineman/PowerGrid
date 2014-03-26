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
    QMap<QString, jlong> modifierMap;
  public:
    /**
     * @brief Creates a new RSClass with the given name and type name.
     *
     * @param name - The name of this class, suitable for use in
     *               a call to JNIEnv::FindClass.
     * @param simpleName - the simple (semantic) name of the RSClass
     * @param fMap - a Map with field mappings for the class.
     * @param mMap - a Map with multiplier mappings for the class
     * @param cls [optional] the jclass reference to be used with the JNI
     *          Actually, in case of the Runescape client, this is required
     *          because JNI cannot properly resolve RS client class names due to
     *          the way they are loaded (through a custom ClassLoader).
     */
    JACE_API RSClass(const string name, const QString simpleName, QMap<QString, QString> fMap, QMap<QString, jlong> mMap, jclass cls = NULL);
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
    JACE_API jlong getFieldModifier(QString simpleName) const;
};

}
#endif // JACE_RSCLASS_H
