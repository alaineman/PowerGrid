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
#ifndef JNIMETHOD_H
#define JNIMETHOD_H

#include "jni.h"
#include "jnivalue.h"
#include <QtCore>
#include "javaenv.h"
#include "stdarg.h"

namespace jni {
  using namespace std;

  class JNIClass;

  // These #defines allow for more compact code in parameter lists.
  // JNIP is especially for pointer types and JNI for non-pointer types.
  // They bascially "unwrap" a JNIObject and leave the jobject reference, or
  // NULL if the object is NULL.
  // TO can be used for explicit casting of types when required
#define JNI(obj) (obj.IsNull() ? NULL : obj.GetJNIObject())
#define JNIP(obj) (obj == NULL || obj->IsNull() ? NULL : obj->GetJNIObject())
#define TO(value, type) static_cast<type>(value)

  /// The JNIMethod class represents a method in the Java Environment.
  class JNIMethod {
    protected:
      QString name;
      JNIClass* cls;
      QString signature;
      jmethodID method;
      bool isStatic;
      bool canExist;
    public:
      JNIMethod(JNIClass* c, QString nm, QString sig, bool stat = false) {
        cls = c; name = nm; signature = sig; isStatic = stat; canExist = true;
      }

      QString GetName() { return name; }
      JNIClass* GetClass() { return cls; }
      bool IsStatic() { return isStatic; }
      jmethodID GetMethodID();

      QString GetReturnType();
      QList<QString> GetArgumentTypes();

      bool Exists() { return (canExist ? GetMethodID() != NULL : false); }
      virtual bool isValid() { return Exists(); }
  };

  class JNIObjectMethod : public JNIMethod {
    public:
      JNIObjectMethod(JNIClass* c, const char *nm, const char* sig, bool stat)
        : JNIMethod(c,nm,sig,stat) {}

      JNIClass* GetReturnTypeClass();

      virtual jobject Invoke(jobject obj, ...);
      virtual jobject InvokeV(jobject obj, va_list args);
  };
}
#endif // JNIMETHOD_H
