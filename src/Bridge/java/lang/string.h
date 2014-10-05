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
#ifndef JAVA_LANG_STRING_H
#define JAVA_LANG_STRING_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"

namespace java {
namespace lang {

/*!
 * \brief Proxy class for \c java.lang.String
 *
 * This class provides access to java String objects, and provides
 * additional operations to convert java Strings to \c std::string and
 * \c QString objects.
 */
class String : public Object {
private:
    mutable QString localString; ///< QString used for caching the String locally
public:
    /**
     * @brief Creates a new String that points to NULL
     */
    String();
    /**
     * @brief Creates a new String that points to the same Java String as @c obj
     * @param obj - the other String
     */
    String(const String& obj);

    /**
     * @brief Returns the JClass representative of this object
     */
    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    /**
     * @brief Returns the JClass representative for the String class.
     */
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    /**
     * @brief Creates a new String object from the provided jvalue
     * @param value - the jvalue to create a String from
     */
    explicit String(jvalue value);
    /**
     * @brief Creates a new String object from the provided jobject
     * @param object - the jobject to create a String from
     */
    explicit String(jobject object);
    /**
     * @brief Creates a new String object from the provided jstring
     * @param string - the jstring to create a String from
     */
    String(jstring string);
    /**
     * @brief copy-assigns the other String's reference to this String
     * @param obj - the other String object
     * @return this String object
     */
    String& operator = (const String& obj);

    /**
     * @brief Returns the length of the string
     *
     * If this String reference is NULL, this function returns -1.
     * Else, this function returns the length of the string. This way,
     * it is possible to distinct between NULL strings and empty strings.
     *
     * @return the length of the string.
     */
    int length() const;

    /**
     * @brief Copies the contents of this Java String to an std::wstring.
     *
     * This function is generally faster than @c toQString(), and provides
     * the string in a wider character range than the @c toStdString() function.
     * However, for comparison with standard strings, it is generally a better
     * choice to use toStdString() instead.
     *
     * @return an std::wstring with the same contents as this Java String.
     */
    std::wstring toStdWString() const throw(jace::JNIException);

    /**
     * @brief Copies the contents of this Java String to an std::string
     *
     * Caution: Due to Java Strings being encoded differently from
     * std::strings, some characters may not be represented correctly.
     * Even so, this function is preferred over @c toQString() if
     * performance is important (see toQString() documentation).
     *
     * @return an std::string with the same contents as this Java String.
     */
    std::string toStdString() const throw(jace::JNIException);

    /**
     * @brief Copies the contents of this Java String to a QString.
     *
     * The Java String is first copied to native memory in UTF-16 encoding,
     * and then converted to a QString. As such, all characters that can be
     * represented in UTF-16 should convert properly (as opposed to the
     * @c toStdString() member function).
     *
     * The first invocation will copy the string to a QString, which takes
     * linear time. Subsequent invocations will return the same QString,
     * taking constant time.
     *
     * @return a QString with the same contents as this Java String.
     */
    QString toQString() const throw(jace::JNIException);

    /**
     * @brief Creates a Java String from the provided QString.
     * @param string - the QString to convert
     * @return a Java String with the same contents as the QString.
     */
    static String fromQString(QString string) throw(jace::JNIException);

    // Each of these functions converts its parameter to a String representation.
    // This is done through the JVM, by calling the appropriate String.valueOf(...)
    // method and returning a String object with the result.
    static String valueOf(JObject  value) throw(jace::JNIException);
    static String valueOf(JByte    value) throw(jace::JNIException);
    static String valueOf(JBoolean value) throw(jace::JNIException);
    static String valueOf(JShort   value) throw(jace::JNIException);
    static String valueOf(JChar    value) throw(jace::JNIException);
    static String valueOf(JInt     value) throw(jace::JNIException);
    static String valueOf(JLong    value) throw(jace::JNIException);
    static String valueOf(JDouble  value) throw(jace::JNIException);
    static String valueOf(JFloat   value) throw(jace::JNIException);

private:
    template <typename T>
    friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // end namespace lang
} // end namespace java

#endif // JAVA_LANG_STRING_H
