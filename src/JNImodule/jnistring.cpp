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

  JNIString::JNIString(jstring str) : JNIObject(str) {
    string_ref = str;
  }
  JNIString::JNIString(const char *str) {
    string_val = str;
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
