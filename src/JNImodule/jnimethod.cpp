#include "jnimethod.h"
#include "jniexception.h"

namespace jni {
  jmethodID JNIMethod::GetMethodID() {
    if (method == NULL && canExist) {
      method = JAVAENV->GetMethodID(cls, name, signature);
      if (method == NULL) canExist = false;
    }
    return method;
  }

  QString JNIMethod::GetReturnType() {
    return signature.right(signature.length() - signature.lastIndexOf(")") + 1);
  }

  QList<QString> JNIMethod::GetArgumentTypes() {
    QList<QString> args;
    int end = signature.lastIndexOf(")");
    for (int i = 1; i < end; ++i) {
      QChar c = signature.at(i);
      if (c == 'L') {
        int j = signature.indexOf(";", i);
        args.append(signature.mid(i, j-i));
        i = j;
      } else {
        args.append(c);
      }
    }
    return args;
  }

  // --- JNIObjectMethod --------------------------------------

  JNIClass* JNIObjectMethod::GetReturnTypeClass() {
    int begin = signature.lastIndexOf(")L") + 1;
    int end = signature.lastIndexOf(";") - 1;
    return JAVAENV->GetClass(signature.mid(begin, end - begin));
  }

  jobject JNIObjectMethod::Invoke(jobject obj, ...) {
    va_list args;
    jmethodID m = GetMethodID();
    if (m == NULL) {
      throw jni_error("non-existing method");
    }
    va_start(args, m);
    jobject result = JNIENV->CallObjectMethodV(obj, m, args);
    va_end(args);
    return result;
  }

  jobject JNIObjectMethod::InvokeV(jobject obj, va_list args) {
    jmethodID m = GetMethodID();
    if (m == NULL) {
      throw jni_error("non-existing method");
    }
    return JNIENV->CallObjectMethodV(obj, m, args);
  }
}
