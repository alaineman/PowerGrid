#include "jniobject.h"

namespace jni {
  JNIObject::JNIObject(JavaEnv *e, jobject o) {
    env = e;
    object = o;
    setObjectName(QStringLiteral("JNIObject"));
  }

  jobject JNIObject::GetJObject() {
    return object;
  }
}
