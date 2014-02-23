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

/*!
   \class java::lang::Object
   \brief Proxy for \c{java.lang.Object}

   This class is the base class of all java classes, and as such also
   the base class of all proxy classes.
 */

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

Object& Object::operator =(Object& obj) {
    setJavaJniObject(obj.getJavaJniObject());
    return *this;
}

/*!
 * \brief Calls this Java Object's \c equals method.
 * This invokes the equals method on the two java objects in the Java VM.
 *
 * \param other the object to call equals with
 * \return true if the two objects are equal according to this
 *         object's equals method, false otherwise
 */
bool Object::equals(const Object &other) {
    JNIEnv* env = jace::helper::attach();
    jmethodID equals_id = env->GetMethodID(
                Object::staticGetJavaJniClass()->getClass(), "equals", "(Ljava/lang/Object;)Z");
    return env->CallBooleanMethod(getJavaJniObject(), equals_id, other.getJavaJniObject()) == JNI_TRUE;
}

/*!
 * \brief Calls this Java Object's \c toString method.
 * This invokes the \c toString method on the java object in the Java VM.
 * \return the String value of the java Object, as a java String.
 */
String& Object::toString() {
    JNIEnv* env = jace::helper::attach();
    jmethodID toString_id = env->GetMethodID(
                Object::staticGetJavaJniClass()->getClass(), "toString", "()Ljava/lang/String;");
    return String(env->CallObjectMethod(getJavaJniObject(), toString_id));
}

} // end namespace lang
} // end namespace java

std::ostream& operator<<(std::ostream& out, java::lang::Object& object) {
    return out << jace::helper::toString(object.getJavaJniObject());
}

