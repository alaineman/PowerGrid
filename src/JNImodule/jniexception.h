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
#ifndef JNI_EXCEPTION_H
#define JNI_EXCEPTION_H

#include "stdexcept"
#include "jni.h"

using namespace std;

namespace jni {

  class JNIValue;

  /// Describes an error in the JNI
  class jni_error : public runtime_error {
    public:
      /// Creates a new jni_error with the specified message
      jni_error(const string& msg) : runtime_error(msg) {}
  };

  /// Describes an exception in the java environment
  class java_exception : public jni_error {
    private:
      jthrowable except;
    public:
      /// Creates a new java_exception with the specified jthrowable and optional description
      java_exception(jthrowable ex, const string& desc = "Java Exception occurred")
          : jni_error(desc) { except = ex; }

      /// returns the java exception object that caused this java_exception
      jthrowable GetExceptionObject() { return except; }
  };
}

#endif // JNI_EXCEPTION_H
