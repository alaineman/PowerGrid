#include "jniclass.h"
#include "javaenv.h"
#include "jniexception.h"

namespace jni {
  JNIMethod* JNIClass::GetMethod(const char* name, const char* signature) {
    return NULL;
  }

  JNIValue JNIClass::InvokeStaticMethod(JNIMethod *method, ...) {
    if (method == NULL) {
      throw jni_error("Method is NULL");
    }
    jvalue_type type = method->GetReturnType();
    va_list args;
    int count = static_cast<int>(method->GetArgumentCount());
    va_start(args, count);
    JNIValue result = env->CallStatic(type, clazz, method->GetMethodID(), args);
    va_end(args);
    return result;
  }
}
