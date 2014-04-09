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

#include "object.h"
#include "java/lang/string.h"

namespace java {
namespace lang {

Object::Object() :
    JObject() {}

Object::Object(const NoOp &noop) :
    JObject(noop) {}

Object::Object(const Object &obj) :
    JObject(obj.getJavaJniValue()) {}

Object::Object(jobject obj) :
    JObject(obj) {}

Object::Object(jvalue val) :
    JObject(val) {}

const jace::JClass* Object::staticGetJavaJniClass() throw (jace::JNIException) {
    static jace::JClassImpl cls ("java.lang.Object");
    return &cls;
}

const jace::JClass* Object::getJavaJniClass() const throw(jace::JNIException) {
    return Object::staticGetJavaJniClass();
}

Object& Object::operator =(const Object& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

bool Object::operator ==(const Object& obj) {
    return getJavaJniObject() == obj.getJavaJniObject() || (!isNull() && equals(obj));
}

bool Object::operator !=(const Object& obj) {
    return !(*this == obj);
}

bool Object::equals(const Object &other) const {
    JNIEnv* env = jace::helper::attach();
    jmethodID equals_id = env->GetMethodID(
                Object::staticGetJavaJniClass()->getClass(), "equals", "(Ljava/lang/Object;)Z");
    return env->CallBooleanMethod(getJavaJniObject(), equals_id, other.getJavaJniObject()) == JNI_TRUE;
}

jstring Object::toString() const {
    JNIEnv* env = jace::helper::attach();
    jmethodID toString_id = env->GetMethodID(
                Object::staticGetJavaJniClass()->getClass(), "toString", "()Ljava/lang/String;");
    jstring result = static_cast<jstring>(env->CallObjectMethod(getJavaJniObject(), toString_id));
    return result;
}

} // end namespace lang
} // end namespace java

std::ostream& operator<<(std::ostream& out, java::lang::Object& object) {
    return out << jace::helper::toString(object.getJavaJniObject());
}

