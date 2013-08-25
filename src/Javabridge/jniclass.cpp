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
#include "jniclass.h"
#include "javaenv.h"
#include "jniexception.h"
#include "jnistring.h"

namespace jni {
  QString JNIClass::J_GetName() {
    if (name.isEmpty()) {
      JavaEnv* env = JavaEnv::instance();
      JNIClass* cls = GetClass();
      jclass c = (jclass) cls->GetJNIObject();
      JNIEnv* e = env->GetEnv();
      jmethodID getName = e->GetMethodID(c, "getName", "()Ljava/lang/String;");
      jstring n = (jstring) e->CallObjectMethod(c, getName);
      QString result = JNIString(n).GetStringValue();
      name = result.replace(".", "/");
      name = e->GetStringUTFChars(n, NULL);
    }
    return name;
  }

  QString JNIClass::GetSimpleName() {
    QString signame = J_GetName();
    int first = signame.lastIndexOf("/") + 1;
    return signame.right(signame.length() - first);
  }

  jboolean JNIClass::IsInstance(JNIObject o) {
    return IsInstance(o.GetJNIObject());
  }

  jboolean JNIClass::IsInstance(jobject o) {
    return JavaEnv::instance()->GetEnv()->IsInstanceOf(o, clazz);
  }

  JNIClass* JNIClass::GetSuperClass() {
    jclass c = JNIENV->GetSuperclass(clazz);
    return JAVAENV->GetClass(c);
  }

  JNIMethod* JNIClass::GetMethod(QString name, QString signature) {
    return JAVAENV->GetMethod(this, name, signature);
  }

  JNIMethod* JNIClass::GetConstructor(QString signature) {
    return GetMethod("<init>", signature);
  }

  void JNIClass::emptyCache() {
    methods.clear();
    fields.clear();
    modifiers = 0;
  }
}
