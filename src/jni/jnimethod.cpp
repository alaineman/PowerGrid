#include "jnimethod.h"

namespace jni {
  JNIMethod::JNIMethod(string nm, jclass c, jvalue_type ret, const vector<jvalue_type> args,
                       jboolean stat, jmethodID meth) {
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(meth);
    VERIFY_THAT(nm.length() != 0)
#ifdef PG_STRING_CHECK
    char first = nm.at(0);
    VERIFY_THAT((first >= 'A' && first <= 'Z') || (first >= 'a' && first <= 'z') || first == '$' || first == '_');
#endif
    name = nm;
    cls = c;
    return_type = ret;
    argument_types = vector<jvalue_type>(args);
    isStatic = stat;
    method = meth;
  }

  string JNIMethod::GetName() {
    return name;
  }

  jclass JNIMethod::GetClass() {
    return cls;
  }

  jmethodID JNIMethod::GetMethodID() {
    return method;
  }

  jvalue_type JNIMethod::GetReturnType() {
    return return_type;
  }

  jvalue_type JNIMethod::GetArgumentType(uint n) {
    if (n >= argument_types.size()) {
      return JVOID;
    } else {
      return argument_types.at(n);
    }
  }

  uint JNIMethod::GetArgumentCount() {
    return argument_types.size();
  }

  jboolean JNIMethod::IsStatic() {
    return isStatic;
  }

  jboolean JNIMethod::ValidateInput(vector<JNIValue> arguments) {
    if (argument_types.size() != arguments.size()) {
      return JNI_FALSE;
    } else {\
      uint len = arguments.size();
      for (uint i = 0; i < len; i++) {
        JNIValue val = arguments.at(i);
        if (val.GetType() != argument_types.at(i)) {
          return JNI_FALSE;
        }
      }
      return JNI_TRUE;
    }
  }
}
