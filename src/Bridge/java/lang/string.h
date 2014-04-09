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
 * additional operation to convert java Strings to \c std::string and
 * \c QString objects.
 */
class String : public Object {
public:
    String();
    String(const String&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit String(jvalue value);
    explicit String(jobject object);
    String(jstring string);
    String& operator = (const String& obj);

    std::string toStdString() const throw(jace::JNIException);
    QString toQString() const throw(jace::JNIException);

private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // end namespace lang
} // end namespace java

#endif // JAVA_LANG_STRING_H
