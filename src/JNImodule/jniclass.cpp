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

  JNIClass* JNIClass::GetSuperClass() {
    jclass c = JNIENV->GetSuperclass(clazz);
    return JAVAENV->GetClass(c);
  }

  JNIMethod* JNIClass::GetMethod(QString name, QString signature) {
    return JAVAENV->GetMethod(this, name, signature);
  }

  JNIMethod* JNIClass::GetConstructor(QString signature) {
    return GetMethod("<init>", signature);
  }

  void JNIClass::emptyCache() {
    methods.clear();
    fields.clear();
    modifiers = 0;
  }
}
