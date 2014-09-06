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

#include "file.h"
#include "java/lang/string.h"
using jace::JNIException;

namespace java {
namespace io {

/*!
 * \class java::io::File
 * \brief Proxy class for \c java.io.File
 *
 * This class provides access to java File objects, and provides
 * additional operation to convert java File objects to QFile objects.
 */

File::File() : Object() {
}
File::File(const File &obj) :
    JObject(NoOp()), Object(obj) {
}

const jace::JClass* File::staticGetJavaJniClass() throw (JNIException) {
    static jace::JClassImpl cls ("java.io.File");
    return &cls;
}

const jace::JClass* File::getJavaJniClass() const throw (JNIException) {
    return File::staticGetJavaJniClass();
}

File::File(jobject object) :
    Object(object) {}
File::File(jvalue value) :
    Object(value) {}

File& File::operator =(const File &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

QFile *File::toQFile() const throw(JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass fileClass = File::staticGetJavaJniClass()->getClass();
    if (!fileClass) throw JNIException("Cannot find java.io.File class");
    jmethodID getAbsolutePath = env->GetMethodID(fileClass, "getAbsolutePath", "()Ljava/lang/String;");
    if (!getAbsolutePath) throw JNIException("Cannot find method \"getAbsolutePath()\" in java.io.File");
    String pathJString (env->CallObjectMethod(getJavaJniObject(), getAbsolutePath));
    QString path = pathJString.toQString();
    return new QFile(path);
}

} // namespace io
} // namespace java
