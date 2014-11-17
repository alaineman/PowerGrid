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

String::String(const String &obj) :
    JObject(NoOp()), Object(obj),
     localString(obj.localString) {
}

const jace::JClass* String::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java/lang/String");
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
        } else {
            throw jace::JNIException("String::toQString() - String is null");
        }
    }
    return localString;
}

String String::fromQString(QString string) throw(jace::JNIException) {
    QByteArray data = string.toLocal8Bit();
    JNIEnv* env = jace::helper::attach();
    const char* chars = data.constData();
    if (chars == NULL) throw jace::JNIException("String::fromQString() - NULL String passed into fromQString()");
    jstring jstr = env->NewStringUTF(chars);
    if (jstr == NULL) throw jace::JNIException("String::fromQString() - Could not allocate String");
    jace::helper::catchAndThrow();
    return String(jstr);
}

String String::valueOf(JObject value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(Ljava/lang/Object;)Ljava/lang/String;");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getJavaJniObject());
    return String(result);
}

String String::valueOf(JByte value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(B)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getByte());
    return String(result);
}

String String::valueOf(JBoolean value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(Z)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getBoolean());
    return String(result);
}

String String::valueOf(JShort value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(S)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getShort());
    return String(result);
}

String String::valueOf(JChar value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(C)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getChar());
    return String(result);
}

String String::valueOf(JInt value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(I)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getInt());
    return String(result);
}

String String::valueOf(JLong value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(J)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getLong());
    return String(result);
}

String String::valueOf(JDouble value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(D)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getDouble());
    return String(result);
}

String String::valueOf(JFloat value) throw(jace::JNIException) {
    JNIEnv* env = jace::helper::attach();
    jclass stringClass = staticGetJavaJniClass()->getClass();
    jmethodID valueOf = env->GetStaticMethodID(stringClass, "valueOf", "(F)Ljava/lang/String;");
    if (!valueOf) throw jace::JNIException("Cannot find String.valueOf method");
    jobject result = env->CallStaticObjectMethod(stringClass, valueOf, value.getFloat());
    return String(result);
}

}
}
