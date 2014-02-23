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
#ifndef JAVA_IO_FILE_H
#define JAVA_IO_FILE_H

#include "jace/os_dep.h"
#include "jace/javacast.h"

#include "jace/proxy/JObject.h"
#include "jace/JArray.h"
#include "jace/JMethod.h"
#include "jace/JField.h"
#include "jace/JClass.h"

#include "java/lang/object.h"
#include <QFile>
using namespace java::lang;

namespace java {
namespace io {

class File : public Object {
public:
    File();
    File(const File&obj);

    virtual const jace::JClass* getJavaJniClass() const throw (jace::JNIException);
    static const jace::JClass* staticGetJavaJniClass() throw (jace::JNIException);

    explicit File(jvalue value);
    explicit File(jobject object);
    File& operator = (const File& obj);

    QFile toQFile() const throw(jace::JNIException);
private:
    template <typename T> friend T (jace::java_cast)(const jace::proxy::JObject&);
};

} // namespace io
} // namespace java

#endif // JAVA_IO_FILE_H
