#ifndef JNIOBJECT_H
#define JNIOBJECT_H

#include "jnivalue.h"
#include "jnimethod.h"
#include "jniexception.h"
#include "javaenv.h"

using namespace std;

namespace jni {

  class JNIClass;
  class JNIString;

  /**
   * @brief Representation of an object from the Java environment
   *
   * The member functions starting with "J_" make a call to the java function with the same name (minus the "J_").
   * For example, J_toString() returns the result of the toString method when invoked on the object.
   */
  class JNIObject : public JNIValue {
    private:
      static JNIObject sharedNull;
    protected:
      JNIObject() : JNIValue() { clazz = NULL; }

      jobject object;                   /// The jobject reference from the Java Environment
      JNIClass* clazz;                   /// The JNIClass object representing the type of this object

      /// Verifies that this object is not null (and throws a jni_error when it is)
      void nullCheck() { if (IsNull()) throw jni_error("dereferencing null"); }
    public:
      /// Returns the shared value for Null
      static JNIObject Null() { return sharedNull; }

      virtual ~JNIObject();

      /**
       * @brief Creates an JNIObject representing the specified jobject
       * @param o the object reference from the JNI environment
       */
      JNIObject(jobject o) : JNIValue(o) { if (o == NULL) throw jni_error("creating null object"); object = o; }

      /**
       * @brief Returns the JNI jobject reference this object holds
       * @return the JNI jobject reference this object holds
       */
      jobject GetJNIObject() { return object; }

      /**
       * @brief Returns the class of this object
       * @return the class of this object
       */
      JNIClass* GetClass();

      /**
       * returns a String representation of this object
       * Calling this function automatically sets the object's name to the result of the method call.
       * @return the result of this.toString() in the Java environment as a QString
       */
      JNIString* J_toString();

      /**
       * returns whether this object is equal to another object according to the object's equals method
       * @param other the object to compare with
       * @return the result of this.equals(other) in the Java environment
       */
      bool J_equals(JNIObject* other);

      /**
       * returns the hashCode for this object
       * @return the result of this.hashCode() in the Java environment
       */
      int J_hashCode();

      jfieldID GetFieldID(QString fieldName, QString type);

      JNIMethod* GetMethod(QString methodName, QString signature);
  };

}

#endif // JNIOBJECT_H
