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

#ifndef JACE_RSCLASSMAPPER_H
#define JACE_RSCLASSMAPPER_H
#include "jace/os_dep.h"
#include "jni.h"
#include "RSClass.h"

#include <QObject>
#include <QMap>
#include <QFile>

Q_DECLARE_LOGGING_CATEGORY(logMapper)

namespace jace {
/**
 * @brief Maps proxy classes to their Java equivalents
 *
 * This class contains all data required for successfully mapping C++ class
 * names to their obfuscated names. This class is called by each of the RS
 * proxies to get the mapping data for each class.
 */
class RSClassMapper : public QObject {
    Q_OBJECT
private:
    static RSClassMapper* classmapper;

    QMap<QString, QString> classMap;                // semanticClassName => realClassName
    QMap<QString, QMap<QString, QString>> fieldMap; // semanticClassName => ( semanticFieldName => realFieldName )
    QMap<QString, QMap<QString, jlong>> modifiers;  // semanticClassName => ( semanticFieldName => modifier value )

    QMap<QString, RSClass*> classes;                // semanticClassname => RSClass representative

    // static fields may be stored in different classes between distributions,
    // so we need to remember in which classes the static references are.
    // For this purpose, we assume static field names are unique, and
    // map both the actual field name, as well as the class in which the
    // field is stored.
    QMap<QString, QString> staticClassMap;          // [static] semanticFieldName => realClassName
    QMap<QString, QString> staticFieldMap;          // [static] semanticFieldName => realFieldName
    QMap<QString, jlong> staticModifierMap;         // [static] semanticFieldName => modifier value
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
     * If no binding for the given name exists, a MappingUnavailableException
     * is thrown with the requested class name as message. This means that in
     * places where this is (either directly or indirectly) used, exceptions
     * of this type should be caught and handled appropriately.
     *
     * @return a pointer to the \c RSClass.
     * @throws MappingUnavailableException when the name cannot be mapped
     */
    JACE_API RSClass* getRSClass(QString name);

    JACE_API QString getStaticFieldClass(QString fieldName) const;
    JACE_API QString getStaticFieldName(QString fieldName) const;
    JACE_API jlong getStaticFieldModifier(QString fieldName) const;

    JACE_API jclass getClass(QString name);
    JACE_API QString getRealName(QString semanticName) const;

    /**
     * \brief Checks and returns if a binding exists for the indicated field.
     *
     * If the binding does not exist, this function returns false. Otherwise
     * (if the binding does exist), this function returns true.
     *
     * \return true if the binding exists, false otherwise
     */
    JACE_API bool isAvailable(QString className, QString fieldName) const;

    /**
     * \brief Checks and asserts that a binding exists for the indicated field.
     *
     * If the binding does not exist, a \c JNIException will be thrown indicating
     * the missing binding. Otherwise (if the binding does exist), this function
     * does nothing.
     */
    JACE_API void assertAvailable(QString className, QString fieldName) const
            throw(JNIException);

    /**
     * @brief Returns the type of the field with the given name.
     *
     * @param className the name of the class.
     * @param fieldName the name of the field.
     * @return the name of the field type.
     * @throws JNIException if the type cannot be deduced, or if an error
     *         occurred in the JVM.
     */
    JACE_API QString getType(QString className, QString fieldName) const;

    /**
     * @brief Parses the provided data
     *
     * The provided @c jbytearray is parsed as XML to
     * read the mapping data. The parsed data is stored in this
     * RSClassMapper for later retrieval using @c getRSClass(QString name).
     * @param data the java byte array containing the data
     */
    JACE_API void parseData(jbyteArray data) throw(JNIException);
private:
    QMap<QString, QString> getFieldMap(QString className) const;
    QMap<QString, jlong> getModifierMap(QString className) const;


    // Helper functions for the parser
    int parseClass(QXmlStreamReader *reader) throw(JNIException);
    void parseField(QXmlStreamReader *reader, QString className, bool isStatic) throw(JNIException);
    void parseModifier(QXmlStreamReader *reader, QString className, QString fieldName, bool isStatic) throw(JNIException);
};

}
#endif // JACE_RSCLASSMAPPER_H
