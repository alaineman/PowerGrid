#include "jnimethod.h"

namespace jni {
  JNIMethod::JNIMethod(string nm, jclass c, string sig, jboolean stat, jmethodID meth)
      : JNIElement(nm) {
#ifdef PG_NULL_CHECK
    if (c == NULL || meth == NULL) {
      throw runtime_error("Null value in JNIMethod");
    }
#endif
#ifdef PG_STRING_CHECK
    if (sig.length() == 0) {
      throw runtime_error("Empty String");
    }
    if (sig.find_first_of("(") != 0 || sig.find_first_of(")") < 0) {
      throw runtime_error("Invalid signature");
    }
    if (sig.find_first_of(" ") >= 0) {
      throw runtime_error("Illegal character in signature");
    }
#endif
    cls = c;
    signature = sig;
    isStatic = stat;
    method = meth;
  }

  jclass JNIMethod::GetClass() {
    return cls;
  }

  jmethodID JNIMethod::GetMethodID() {
    return method;
  }

  string JNIMethod::GetSignature() {
    return signature;
  }

  jboolean JNIMethod::IsStatic() {
    return isStatic;
  }
}
