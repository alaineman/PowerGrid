#ifndef JNISTRING_H
#define JNISTRING_H

#include "jniobject.h"

namespace jni {

  class JNIString : public JNIObject {
    private:
      jstring string_ref;
      QString string_val;

      QString toQString(); /// Explicit conversion to QString
      jstring toJString(); /// Explicit conversion to jstring
    public:
      JNIString(jobject obj);
      JNIString(jstring str) : JNIObject(str) { string_ref = str; }
      JNIString(const char* str) { string_val = str; }
      JNIString(QString qstr) { string_val = qstr; }

      jstring GetStringRef() { return string_ref == NULL ? toJString() : string_ref; }
      QString GetStringValue() { return string_val == NULL ? toQString() : string_val; }
      const char* GetData() { return qPrintable(GetStringValue()); }
  };

}

#endif // JNISTRING_H
