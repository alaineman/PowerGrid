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

#include "string.h"

namespace java {
namespace lang {

String::String() : Object() {
}

String::String(const String &obj) : Object(obj),
    localString(obj.localString) {
}

const jace::JClass* String::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java.lang.String");
    return &cls;
}

const jace::JClass* String::getJavaJniClass() const throw (jace::JNIException) {
    return String::staticGetJavaJniClass();
}

String::String(jobject object) : Object(object) {}

String::String(jvalue value)   : Object(value) {}

String::String(jstring string) : Object(string) {}

String& String::operator =(const String &obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

int String::length() const {
    if (isNull()) {
        return -1;
    }
    if (localString.isNull()) {
        return jace::helper::attach()->GetStringLength(
                    static_cast<jstring>(getJavaJniObject()));
    } else {
        return localString.length();
    }
}

std::string String::toStdString() const throw (jace::JNIException){
    JNIEnv* env = jace::helper::attach();
    jstring string = static_cast<jstring>(getJavaJniObject());
    const char* chars = env->GetStringUTFChars(string, NULL);
    return chars;
}

QString String::toQString() const throw (jace::JNIException) {
    if (localString.isNull()) {
        jstring string = static_cast<jstring>(getJavaJniObject());
        if (string != NULL) {
            JNIEnv* env = jace::helper::attach();
            const jchar* chars = env->GetStringChars(string, NULL);
            localString.setUtf16(chars, env->GetStringLength(string));
        }
    }
    return localString;
}

}
}
