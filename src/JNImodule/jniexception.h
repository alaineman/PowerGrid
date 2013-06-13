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
