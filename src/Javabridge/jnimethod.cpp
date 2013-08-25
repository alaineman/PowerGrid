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
#include "jnimethod.h"
#include "jniexception.h"

namespace jni {
  jmethodID JNIMethod::GetMethodID() {
    if (method == NULL && canExist) {
      method = JAVAENV->GetMethodID(cls, name, signature);
      if (method == NULL) canExist = false;
    }
    return method;
  }

  QString JNIMethod::GetReturnType() {
    return signature.right(signature.length() - signature.lastIndexOf(")") + 1);
  }

  QList<QString> JNIMethod::GetArgumentTypes() {
    QList<QString> args;
    int end = signature.lastIndexOf(")");
    for (int i = 1; i < end; ++i) {
      QChar c = signature.at(i);
      if (c == 'L') {
        int j = signature.indexOf(";", i);
        args.append(signature.mid(i, j-i));
        i = j;
      } else {
        args.append(c);
      }
    }
    return args;
  }

  // --- JNIObjectMethod --------------------------------------

  JNIClass* JNIObjectMethod::GetReturnTypeClass() {
    int begin = signature.lastIndexOf(")L") + 1;
    int end = signature.lastIndexOf(";") - 1;
    return JAVAENV->GetClass(signature.mid(begin, end - begin));
  }

  jobject JNIObjectMethod::Invoke(jobject obj, ...) {
    va_list args;
    jmethodID m = GetMethodID();
    if (m == NULL) {
      throw jni_error("non-existing method");
    }
    va_start(args, m);
    jobject result = JNIENV->CallObjectMethodV(obj, m, args);
    va_end(args);
    return result;
  }

  jobject JNIObjectMethod::InvokeV(jobject obj, va_list args) {
    jmethodID m = GetMethodID();
    if (m == NULL) {
      throw jni_error("non-existing method");
    }
    return JNIENV->CallObjectMethodV(obj, m, args);
  }
}
