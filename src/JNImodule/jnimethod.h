#ifndef JNIMETHOD_H
#define JNIMETHOD_H

#include "jni.h"
#include "jnivalue.h"
#include <QtCore>

namespace jni {
  using namespace std;

  // The JNIMethod class represents a method in the Java Environment.
  // It contains information to help identifying the method,
  // since this is extremely hard with only the jmethodID reference.
  class JNIMethod {
    private:
      QString name;
      jclass cls;
      jvalue_type return_type;
      vector<jvalue_type> argument_types;
      jmethodID method;
      jboolean isStatic;
    public:
      // Single constructor defining all fields.
      JNIMethod(const char *nm, jclass c, jvalue_type ret, const vector<jvalue_type> args,
                jboolean stat, jmethodID meth);

      // Getters for the fields.
      QString GetName() { return name; }
      jclass GetClass() { return cls; }
      jvalue_type GetReturnType() { return return_type; }
      jvalue_type GetArgumentType(uint n);
      jboolean IsStatic() { return isStatic; }
      jmethodID GetMethodID() { return method; }
      uint GetArgumentCount() { return argument_types.size(); }


      // Validates the given vector as input for the method.
      jboolean ValidateInput(vector<JNIValue> arguments);
  };
}
#endif // JNIMETHOD_H
