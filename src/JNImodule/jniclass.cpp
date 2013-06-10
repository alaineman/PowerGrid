#include "jniclass.h"
#include "javaenv.h"
#include "jniexception.h"

namespace jni {
  QString JNIClass::GetSigName() {
    if (name == NULL) {
      JNIClass* cls = GetClass();
      jclass c = (jclass) cls->GetJavaObject();
      JNIEnv* e = env->GetEnv();
      jmethodID getName = e->GetMethodID(c, "getName", "()Ljava/lang/String;");
      jstring n = (jstring) e->CallObjectMethod(c, getName);
      name = new QString(env->GetString(n));
    }
    return *name;
  }

  QString JNIClass::GetSimpleName() {
    QString signame = GetSigName();
    int first = signame.lastIndexOf("/") + 1;
    return signame.right(signame.length() - first);
  }

  jboolean JNIClass::IsInstance(JNIObject o) {
    return IsInstance(o.GetJObject());
  }

  jboolean JNIClass::IsInstance(jobject o) {
    return env->GetEnv()->IsInstanceOf(o, clazz);
  }

  JNIMethod* JNIClass::GetMethod(const char* name, const char* signature) {
    return env->GetMethod(clazz, name, signature);
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
