#ifndef JNISTRING_H
#define JNISTRING_H

#include "jniobject.h"

namespace jni {

  class JNIString : public JNIObject {
    private:
      jstring string_ref;
      QString string_val;

      QString toQString();
      jstring toJString();
    public:
      JNIString(jobject obj);
      JNIString(jstring str);
      JNIString(const char* str);

      jstring GetStringRef() { return string_ref == NULL ? toJString() : string_ref; }
      QString GetStringValue() { return string_val == NULL ? toQString() : string_val; }
  };

}

#endif // JNISTRING_H
