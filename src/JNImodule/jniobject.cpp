#include "jniobject.h"
#include "javaenv.h"
#include "jnistring.h"

namespace jni {

  JNIObject::~JNIObject() {
    if (object != NULL) {

    }
  }

  JNIClass* JNIObject::GetClass() {
    if (clazz == NULL) {
      nullCheck();
      JavaEnv* env = JavaEnv::instance();
      clazz = env->GetClassForObject(object);
    }
    return clazz;
  }

  JNIString* JNIObject::J_toString() {
    nullCheck();
    JNIMethod* m = GetMethod("toString", "()Ljava/lang/String;");
    jstring str = (jstring) JAVAENV->CallObjectMethod(object, m->GetMethodID(), 0);
    JNIString* result = new JNIString(str);
    setObjectName(result->GetStringValue());
    return result;
  }

  bool JNIObject::J_equals(JNIObject* other) {
    nullCheck();
    jobject that = other->GetJNIObject();
    JNIMethod* m = GetMethod("equals", "(Ljava/lang/Object;)Z");
    jboolean b = JAVAENV->CallBooleanMethod(object, m->GetMethodID(), 1, that);
    return b == JNI_TRUE;
  }

  int JNIObject::J_hashCode() {
    nullCheck();
    JNIMethod* m = GetMethod("hashCode", "()I");
    return JAVAENV->CallIntMethod(object, m->GetMethodID(), 0);
  }

  JNIMethod* JNIObject::GetMethod(QString methodName, QString signature) {
    return JAVAENV->GetMethod(GetClass(), methodName, signature);
  }

}
