#include "jniclass.h"
#include "javaenv.h"
#include "jniexception.h"

namespace jni {
  QString JNIClass::GetSigName() {
    if (name.isEmpty()) {
      JavaEnv* env = JavaEnv::instance();
      JNIClass* cls = GetClass();
      jclass c = (jclass) cls->GetJNIObject();
      JNIEnv* e = env->GetEnv();
      jmethodID getName = e->GetMethodID(c, "getName", "()Ljava/lang/String;");
      jstring n = (jstring) e->CallObjectMethod(c, getName);
      name = e->GetStringUTFChars(n, NULL);
    }
    return name;
  }

  QString JNIClass::GetSimpleName() {
    QString signame = GetSigName();
    int first = signame.lastIndexOf("/") + 1;
    return signame.right(signame.length() - first);
  }

  jboolean JNIClass::IsInstance(JNIObject o) {
    return IsInstance(o.GetJNIObject());
  }

  jboolean JNIClass::IsInstance(jobject o) {
    return JavaEnv::instance()->GetEnv()->IsInstanceOf(o, clazz);
  }

  JNIMethod* JNIClass::GetMethod(const char* name, const char* signature) {
    return JavaEnv::instance()->GetMethod(clazz, name, signature);
  }

  JNIValue JNIClass::InvokeStaticMethod(JNIMethod *method, ...) {
    if (method == NULL) {
      throw jni_error("Method is NULL");
    }
    jvalue_type type = method->GetReturnType();
    va_list args;
    int count = static_cast<int>(method->GetArgumentCount());
    va_start(args, count);
    JNIValue result = JavaEnv::instance()->CallStatic(type, clazz, method->GetMethodID(), args);
    va_end(args);
    return result;
  }
}
