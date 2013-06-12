#include "jniclass.h"
#include "javaenv.h"
#include "jniexception.h"
#include "jnistring.h"

namespace jni {
  QString JNIClass::J_GetName() {
    if (name.isEmpty()) {
      JavaEnv* env = JavaEnv::instance();
      JNIClass* cls = GetClass();
      jclass c = (jclass) cls->GetJNIObject();
      JNIEnv* e = env->GetEnv();
      jmethodID getName = e->GetMethodID(c, "getName", "()Ljava/lang/String;");
      jstring n = (jstring) e->CallObjectMethod(c, getName);
      QString result = JNIString(n).GetStringValue();
      name = result.replace(".", "/");
      name = e->GetStringUTFChars(n, NULL);
    }
    return name;
  }

  QString JNIClass::GetSimpleName() {
    QString signame = J_GetName();
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
    return JavaEnv::instance()->GetMethod(this, name, signature);
  }

  JNIValue JNIClass::InvokeStaticMethod(JNIMethod *method, ...) {
    if (method == NULL || !method->Exists()) {
      throw jni_error("Method is NULL");
    }
    jmethodID m_id = method->GetMethodID();
    va_list args;
    va_start(args, m_id);
    JNIValue result = JavaEnv::instance()->CallStatic(type, clazz, method->GetMethodID(), args);
    va_end(args);
    return result;
  }
}
