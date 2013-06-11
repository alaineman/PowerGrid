#include "jniobject.h"
#include "javaenv.h"

namespace jni {

  JNIClass* JNIObject::GetClass() {
    if (type == NULL) {
      nullCheck();
      JavaEnv* env = JavaEnv::instance();
    }
    return type;
  }
}
