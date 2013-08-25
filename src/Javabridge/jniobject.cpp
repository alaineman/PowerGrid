/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
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
#include "jniobject.h"
#include "javaenv.h"
#include "jnistring.h"

namespace jni {

  void JNIObject::nullCheck() {
 // if (JNI safety check is enabled) {
      if (IsNull()) {
        throw jni_error("dereferencing null");
      }
 // }
  }

  JNIObject::~JNIObject() {
    if (object != NULL) {
      JNIENV->DeleteLocalRef(object);
    }
  }

  JNIClass* JNIObject::GetClass() {
    if (clazz == NULL) {
      nullCheck();
      clazz = JAVAENV->GetClassForObject(object);
    }
    return clazz;
  }

  JNIString* JNIObject::J_toString() {
    nullCheck();
    S_JAVAENV(env);
    JNIMethod* m = env->GetMethod("java/lang/Object", "toString", "()Ljava/lang/String;");
    jstring str = (jstring) env->CallObjectMethod(object, m->GetMethodID(), 0);
    JNIString* result = new JNIString(str);
    setObjectName(result->GetStringValue());
    return result;
  }

  bool JNIObject::J_equals(JNIObject* other) {
    nullCheck();
    S_JAVAENV(env);
    if (other == NULL || other->IsNull()) {
      // if other is null, the equals method will surely return false
      return false;
    }
    jobject that = other->GetJNIObject();
    JNIMethod* m = env->GetMethod("java/lang/Object", "equals", "(Ljava/lang/Object;)Z");
    jboolean b = env->CallBooleanMethod(object, m->GetMethodID(), 1, that);
    return b == JNI_TRUE;
  }

  int JNIObject::J_hashCode() {
    nullCheck();
    S_JAVAENV(env);
    JNIMethod* m = env->GetMethod("java/lang/Object", "hashCode", "()I");
    return env->CallIntMethod(object, m->GetMethodID(), 0);
  }

  JNIMethod* JNIObject::GetMethod(QString methodName, QString signature) {
    nullCheck();
    JNIMethod* m = JAVAENV->GetMethod(GetClass(), methodName, signature);
    if (m == NULL) {
      throw jni_error("No such method");
    }
    return m;
  }

}
