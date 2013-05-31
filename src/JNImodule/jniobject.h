#ifndef JNIOBJECT_H
#define JNIOBJECT_H

#include "jnivalue.h"
#include "jnimethod.h"

using namespace std;

namespace jni {

  class JavaEnv;
  class JNIClass;

  class JNIObject : public JNIValue {
    protected:
      JavaEnv* env;                     // The Java environment this object comes from
      jobject object;                   // The jobject reference from the Java Environment
      JNIClass* type;                   // The JNIClass object representing the type of this object

    public:
      JNIObject() : JNIValue() {}
      JNIObject(JavaEnv* e, jobject o);

      JavaEnv* GetJavaEnv() { return env; }
      jobject GetJavaObject() { return object; }

      JNIClass* GetClass();

      JNIValue GetField(QString field);
      /**
       * @brief Invokes a method in the Java environment on this object
       * @param method the name of the method to invoke
       * @param signature the signature of the method to invoke
       *
       * If the method does not exist for this object, a jni_error is thrown.
       * If the method throws an exception, a java_exception is thrown.
       *
       * @return The result of the method call, or a JNIValue for NULL when the method's return type is void.
       */
      JNIValue Invoke(QString method, QString signature, ...);
      /**
       * @brief Invokes a method in the Java environment on this object
       * @param method the method to invoke
       *
       * If method is NULL or the method cannot be invoked on this object, a jni_error is thrown.
       * If the method throws an exception, a java_exception is thrown.
       *
       * @return the result of the method call, or a JNIValue for NULL when the method's return type is void.
       */
      JNIValue Invoke(JNIMethod* method, ...);
  };

}

#endif // JNIOBJECT_H
