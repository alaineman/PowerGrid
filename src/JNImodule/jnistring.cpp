#include "jnistring.h"
#include "jniclass.h"

namespace jni {

  JNIString::JNIString(jobject obj) : JNIObject(obj) {
    JNIClass* stringClass = GetClass();
    if (!stringClass->IsInstance(obj)) {
      throw jni_error("Illegal conversion to JNIString");
    }
    string_ref = (jstring) obj;
  }

  jstring JNIString::toJString() {
    QByteArray arr = string_val.toLocal8Bit();
    char* data = arr.data();
    type = JOBJECT; // we set this JNIValue as non-null
    return static_cast<jstring>(object = string_ref = JNIENV->NewStringUTF(data));
  }

  QString JNIString::toQString() {
    const char* data = JNIENV->GetStringUTFChars(string_ref, NULL);
    return string_val = data;
  }
}
