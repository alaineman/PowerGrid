#ifndef JNIVALUE_H
#define JNIVALUE_H

#include "jni.h"
#include <cstdlib>
#include <QtCore>

namespace jni {

  /**
   * @brief enum indicating a value type in the Java environment
   */
  enum jvalue_type {
    JVOID,JBOOLEAN,JBYTE,JCHAR,JSHORT,JINT,JLONG,JFLOAT,JDOUBLE,JOBJECT
  };

  /**
   * @brief Returns the name of the given @c jvalue_type as a QString
   */
  QString GetJValueTypeName(jvalue_type type);

  /**
   * @brief Wrapper class around jvalue
   * This class also contains its own type and allows for access of
   * the value itself through the GetValue() function
   */
  class JNIValue : public QObject {
    protected:
      jvalue value;
      jvalue_type type;
    public:
      /**
       * @brief Constructs a generic JNIValue
       * The type will be set to JVOID, and as such has no defined value
       */
      JNIValue() { type = JVOID; setObjectName("null");}

      /**
       * @brief copy constructor for JNIValue
       * @param v the JNIValue to copy from.
       */
      JNIValue(const JNIValue& v) : QObject() {
        type = v.type;
        value = v.value;
        setObjectName(GetJValueTypeName(type));
      }

      /**
       * @brief Creates a JNIValue based on the given jvalue and jvalue_type.
       * @param t the type of the jvalue
       * @param val the jvalue union containing the value
       */
      JNIValue(jvalue_type t, jvalue val) {
        type = t;
        value = val;
        setObjectName(GetJValueTypeName(type));
      }

      /**
       * Creates a JNIValue based on the given jobject
       * @param o the object this JNIValue represents
       */
      JNIValue(jobject o) {
        if (o == NULL) {
          type = JVOID;
        } else {
          type = JOBJECT;
          value.l = o;
        }
      }

      /**
       * @brief Returns whether this JNIValue represents the NULL value
       * @return true if and only if this JNIValue is equivalent to null in the Java Environment
       */
      jboolean IsNull() const { return type == JVOID; }

      /**
       * @brief Returns the type of this JNIValue
       * @return the type of this JNIValue
       */
      jvalue_type GetType() const { return type; }

      jvalue GetValue() const { return value; }
  };
}

#endif // JNIVALUE_H
