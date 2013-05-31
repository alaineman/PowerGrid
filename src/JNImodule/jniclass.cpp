#include "jniclass.h"
#include "javaenv.h"

namespace jni {
  JNIMethod* JNIClass::GetMethod(QString name, QString signature) {
    return NULL;
  }

  JNIValue JNIClass::InvokeStaticMethod(JNIMethod *method, ...) {
    va_list args;
    jvalue_type type = method->GetReturnType();
    int count = static_cast<int>(method->GetArgumentCount());
    va_start(args, count);
    JNIValue result = env->CallStatic(type, clazz, method->GetMethodID(), args);
    va_end(args);
    return result;
  }
}
