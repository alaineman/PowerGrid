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
#ifndef JNISTRING_H
#define JNISTRING_H

#include "jniobject.h"

namespace jni {

  /**
   * Representation of a String object in the java environment.
   *
   * This representation class does not provide any of the methods available to Java Strings.
   * This is, because it is usually faster to extract the QString, then perform the modifications on it,
   * and then create a new JNIString with the changed string.
   *
   * This class is able to convert between jstring references and QStrings.
   */
  class JNIString : public JNIObject {
    private:
      Q_DISABLE_COPY(JNIString)

      jstring string_ref;
      QString string_val;

      QString toQString(); /// Explicit conversion to QString
      jstring toJString(); /// Explicit conversion to jstring
    public:
      JNIString(jobject obj);
      JNIString(jstring str) : JNIObject(str) { string_ref = str; }
      JNIString(const char* str) { string_val = str; }
      JNIString(QString qstr) { string_val = qstr; }

      virtual jstring GetJNIObject() { return GetStringRef(); }

      jstring GetStringRef() { return string_ref == NULL ? toJString() : string_ref; }
      QString GetStringValue() { return string_val == NULL ? toQString() : string_val; }
      const char* GetData() { return qPrintable(GetStringValue()); }
  };

}

#endif // JNISTRING_H
