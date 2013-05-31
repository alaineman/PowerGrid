#ifndef JNISTRING_H
#define JNISTRING_H

#include "jniobject.h"

namespace jni {

  class JNIString : JNIObject {
    private:
      jstring string_ref;
      QString string_val;
    public:
      JNIString();
      JNIString(jstring str);
      JNIString(const char* str);

      ~JNIString();

      jstring GetStringRef();
      QString GetStringValue();
  };

}

#endif // JNISTRING_H
