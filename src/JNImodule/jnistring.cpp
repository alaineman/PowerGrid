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
#include "jnistring.h"
#include "jniclass.h"

namespace jni {

  JNIString::JNIString(jobject obj) : JNIObject(obj) {
    JNIClass* stringClass = GetClass();
    if (!stringClass->IsInstance(obj)) {
      throw jni_error("Illegal conversion to JNIString");
    }
    string_ref = (jstring) obj;
  }

  jstring JNIString::toJString() {
    QByteArray arr = string_val.toLocal8Bit();
    char* data = arr.data();
    type = JOBJECT; // we set this JNIValue as non-null
    return static_cast<jstring>(object = string_ref = JNIENV->NewStringUTF(data));
  }

  QString JNIString::toQString() {
    const char* data = JNIENV->GetStringUTFChars(string_ref, NULL);
    return string_val = data;
  }
}
