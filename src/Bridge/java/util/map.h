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
#ifndef JAVA_UTIL_MAP_H
#define JAVA_UTIL_MAP_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
using namespace java::lang;
using jace::JNIException;

namespace java {
namespace util {

class Map : public Object {
public:
    Map();
    Map(const Map&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (JNIException);

    explicit Map(jvalue value);
    explicit Map(jobject object);
    Map& operator = (const Map& obj);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);

};

} // namespace util
} // namespace java

#endif // JAVA_UTIL_MAP_H
