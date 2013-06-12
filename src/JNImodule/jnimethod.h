#ifndef JNIMETHOD_H
#define JNIMETHOD_H

#include "jni.h"
#include "jnivalue.h"
#include <QtCore>
#include "javaenv.h"
#include "stdarg.h"

namespace jni {
  using namespace std;

  class JNIClass;

  // These #defines allow for more compact code in parameter lists.
  // JNIP is especially for pointer types and JNI for non-pointer types.
#define JNI(obj) obj.GetJNIObject()
#define JNIP(obj) obj->GetJNIObject()

  /// The JNIMethod class represents a method in the Java Environment.
  class JNIMethod {
    protected:
      QString name;
      JNIClass* cls;
      QString signature;
      jmethodID method;
      bool isStatic;
      bool canExist;
    public:
      JNIMethod(JNIClass* c, QString nm, QString sig, bool stat = false) {
        cls = c; name = nm; signature = sig; isStatic = stat; canExist = true;
      }

      QString GetName() { return name; }
      JNIClass* GetClass() { return cls; }
      bool IsStatic() { return isStatic; }
      jmethodID GetMethodID();

      QString GetReturnType();
      QList<QString> GetArgumentTypes();

      bool Exists() { return (canExist ? GetMethodID() != NULL : false); }
      virtual bool isValid() { return Exists(); }
  };

  class JNIObjectMethod : public JNIMethod {
    public:
      JNIObjectMethod(JNIClass* c, const char *nm, const char* sig, bool stat)
        : JNIMethod(c,nm,sig,stat) {}

      JNIClass* GetReturnTypeClass();

      virtual jobject Invoke(jobject obj, ...);
      virtual jobject InvokeV(jobject obj, va_list args);
  };
}
#endif // JNIMETHOD_H
