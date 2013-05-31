#include "jnimethod.h"

namespace jni {
  JNIMethod::JNIMethod(const char* nm, jclass c, jvalue_type ret, const vector<jvalue_type> args,
                       jboolean stat, jmethodID meth) {
    name = nm;
    cls = c;
    return_type = ret;
    argument_types = vector<jvalue_type>(args);
    isStatic = stat;
    method = meth;
  }

  jvalue_type JNIMethod::GetArgumentType(uint n) {
    if (n >= argument_types.size()) {
      return JVOID;
    } else {
      return argument_types.at(n);
    }
  }

  jboolean JNIMethod::ValidateInput(vector<JNIValue> arguments) {
    if (argument_types.size() != arguments.size()) {
      return JNI_FALSE;
    } else {\
      uint len = arguments.size();
      for (uint i = 0; i < len; i++) {
        if (arguments.at(i).GetType() != argument_types.at(i)) {
          return JNI_FALSE;
        }
      }
      return JNI_TRUE;
    }
  }
}
