#ifndef JNIMETHOD_H
#define JNIMETHOD_H

#include "stdafx.h"
#include "jni.h"
#include "jnielement.h"

namespace jni {
  using namespace std;

  // The JNIMethod class represents a method in the Java Environment.
  // It contains information to help identifying the method,
  // since this is extremely hard with only the jmethodID reference.
  class JNIMethod : JNIElement {
    private:
      jclass cls;
      string signature;
      jmethodID method;
      jboolean isStatic;
    public:
      // Single constructor defining all fields.
      JNIMethod(string nm, jclass c, string sig, jboolean stat, jmethodID meth);

      // Getters for the fields.
      jclass GetClass();
      string GetSignature();
      jboolean IsStatic();
      jmethodID GetMethodID();
  };
}
#endif // JNIMETHOD_H
