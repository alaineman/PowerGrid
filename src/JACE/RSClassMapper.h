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

#ifndef RSCLASSMAPPER_H
#define RSCLASSMAPPER_H
#include "jace/os_dep.h"
#include "jni.h"
#include "RSClass.h"

#include <QObject>
#include <QMap>
#include <QFile>

/**
 * @brief Maps proxy classes to their Java equivalents
 *
 * This class contains all data required for successfully mapping C++ class
 * names to their obfuscated names. This class is called by each of the RS
 * proxies to get the mapping data for each class.
 *
 * Warning: Do not call @c getRSClass(QString name) from here! Use
 * @c name::staticGetJavaJniClass() instead.
 */
class RSClassMapper : public QObject {
    Q_OBJECT
private:
    static RSClassMapper* classmapper;

    QMap<QString, QString> classMap;                // semanticClassName => realClassName
    QMap<QString, QMap<QString, QString>> fieldMap; // semanticClassName => ( semanticFieldName => realFieldName )
    QMap<QString, QMap<QString, int>> modifiers;    // semanticClassName => ( semanticFieldName => modifier value )

    QMap<QString, RSClass*> classes;                // semanticClassname => RSClass representative
public:
    /**
     * @brief Returns the global RSClassMapper instance.
     * @return a pointer to the singleton RSClassMapper.
     */
    JACE_API static RSClassMapper* DefaultInstance();

    /**
     * @brief Creates a new RSClassMapper
     */
    JACE_API explicit RSClassMapper();

    JACE_API virtual ~RSClassMapper();

    /**
     * @brief Returns the RSClass belonging to the given name.
     *
     * Warning: Calling this manually may prevent the actual proxy
     * from collecting the RSClass*! Therefore, please call
     * @c name::staticGetJavaJniClass() instead.
     */
    JACE_API RSClass* getRSClass(QString name);

    /**
     * @brief Parses the provided data
     *
     * The provided @c jbytearray is parsed as XML to
     * read the mapping data. The parsed data is stored in this
     * RSClassMapper for later retrieval using @c getRSClass(QString name)
     * @param data the java byte array containing the data
     */
    JACE_API void parseData(jbyteArray data);
private:
    JACE_API QMap<QString, QString> getFieldMap(QString className) const;
    JACE_API QMap<QString, int> getModifierMap(QString className) const;
    JACE_API QString getRealName(QString semanticName) const;
};

#endif // RSCLASSMAPPER_H
