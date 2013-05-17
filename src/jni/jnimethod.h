#ifndef JNIMETHOD_H
#define JNIMETHOD_H

#include "stdafx.h"
#include "jni.h"
#include "jnielement.h"
#include "jnivalue.h"

namespace jni {
  using namespace std;

  // The JNIMethod class represents a method in the Java Environment.
  // It contains information to help identifying the method,
  // since this is extremely hard with only the jmethodID reference.
  class JNIMethod : JNIElement {
    private:
      jclass cls;
      jvalue_type return_type;
      vector<jvalue_type> argument_types;
      jmethodID method;
      jboolean isStatic;
    public:
      // Single constructor defining all fields.
      JNIMethod(string nm, jclass c, jvalue_type ret, const vector<jvalue_type> args,
                jboolean stat, jmethodID meth);

      // Getters for the fields.
      jclass GetClass();
      jvalue_type GetReturnType();
      jvalue_type GetArgumentType(uint n);
      jboolean IsStatic();
      jmethodID GetMethodID();
      uint GetArgumentCount();

      // Validates the given vector as input for the method.
      jboolean ValidateInput(vector<JNIValue> arguments);
  };
}
#endif // JNIMETHOD_H
