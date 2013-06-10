#ifndef JNIOBJECT_H
#define JNIOBJECT_H

#include "jnivalue.h"
#include "jnimethod.h"

using namespace std;

namespace jni {

  class JavaEnv;
  class JNIClass;

  /**
   * @brief Representation of an object from the Java environment
   */
  class JNIObject : private JNIValue {
    protected:
      JavaEnv* env;                     /// The Java environment this object comes from
      jobject object;                   /// The jobject reference from the Java Environment
      JNIClass* type;                   /// The JNIClass object representing the type of this object

    public:
      JNIObject() : JNIValue() { type = NULL; }
      JNIObject(JavaEnv* e, jobject o);

      /**
       * @brief Returns the JavaEnv object this object comes from
       * @return the JavaEnv object this object comes from
       */
      JavaEnv* GetJavaEnv() { return env; }
      /**
       * @brief Returns the JNI jobject reference this object holds
       * @return the JNI jobject reference this object holds
       */
      virtual jobject GetJObject() { return object; }

      /**
       * @brief Returns the class of this object
       * @return the class of this object
       */
      JNIClass* GetClass();

      /**
       * @brief Returns the contents of the field with the provided name.
       * @param field the name of the field to look up
       *
       * Throws a jni_error if the field does not exist.
       * @return the value of the field.
       */
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
