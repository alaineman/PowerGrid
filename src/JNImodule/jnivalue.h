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
   * This class also contains its own type and allows for safe access of
   * values through the GetXXX member functions.
   */
  class JNIValue : public QObject {
    private:
      jvalue value;
      jvalue_type type;
    public:
      /**
       * @brief Constructs a generic JNIValue
       * The type will be set to JVOID, and as such has no defined value
       */
      JNIValue() { type = JVOID; setObjectName(QStringLiteral("null"));}

      JNIValue(const JNIValue& v) : QObject() {
        type = v.type;
        value = v.value;
      }

      /**
       * @brief Creates a JNIValue based on the given jvalue and jvalue_type.
       * @param t the type of the jvalue
       * @param val the jvalue union containing the value
       */
      JNIValue(jvalue_type t, jvalue val);

      /**
       * @brief Creates a JOBJECT-type JNIValue with the specified value
       * @param o the jobject with the value
       */
      JNIValue(jobject o);
      /**
       * @brief Creates a JBOOLEAN-type JNIValue with the specified value
       * @param z the jboolean with the value
       */
      JNIValue(jboolean z);
      /**
       * @brief Creates a JBYTE-type JNIValue with the specified value
       * @param b the jbyte with the value
       */
      JNIValue(jbyte b);
      /**
       * @brief Creates a JSHORT-type JNIValue with the specified value
       * @param s the jshort with the value
       */
      JNIValue(jshort s);
      /**
       * @brief Creates a JCHAR-type JNIValue with the specified value
       * @param c the jchar with the value
       */
      JNIValue(jchar c);
      /**
       * @brief Creates a JINT-type JNIValue with the specified value
       * @param i the jint with the value
       */
      JNIValue(jint i);
      /**
       * @brief Creates a JDOUBLE-type JNIValue with the specified value
       * @param d the jdouble with the value
       */
      JNIValue(jdouble d);
      /**
       * @brief Creates a JFLOAT-type JNIValue with the specified value
       * @param f the jfloat with the value
       */
      JNIValue(jfloat f);
      /**
       * @brief Creates a JLONG-type JNIValue with the specified value
       * @param l the jlong with the value
       */
      JNIValue(jlong l);

      /**
       * @brief Compares this JNIValue to another
       * @param v the value to compare with
       * @return true if this JNIValue is equal to the other value, false otherwise.
       */
      jboolean operator== (JNIValue v);

      /**
       * @brief Returns whether this JNIValue represents the NULL value
       * @return true if and only if this JNIValue is of the JOBJECT type and the
       *         value of this JNIValue is NULL, or when the type is JVOID. false otherwise.
       */
      jboolean IsNull() { return type == JVOID || (type == JOBJECT && value.l == NULL); }

      /**
       * @brief Returns the type of this JNIValue
       * @return the type of this JNIValue
       */
      jvalue_type GetType() { return type; }
      /**
       * @brief Returns the jvalue belonging to this JNIValue
       *
       * This throws an jni_error when this JNIValue's type is JVOID
       * @return the jvalue of this JNIValue
       */
      jvalue Get() { return value; }

      /**
       * @brief Returns the value of this JNIValue as a jboolean.
       * @throws runtime_error when the value does not have the required type
       * @return the jboolean value of this JNIValue
       */
      jboolean GetBoolean();
      /**
       * @brief Returns the value of this JNIValue as a jshort.
       * @throws runtime_error when the value does not have the required type
       * @return the jshort value of this JNIValue
       */
      jshort GetShort();
      /**
       * @brief Returns the value of this JNIValue as a jbyte.
       * @throws runtime_error when the value does not have the required type
       * @return the jbyte value of this JNIValue
       */
      jbyte GetByte();
      /**
       * @brief Returns the value of this JNIValue as a jchar.
       * @throws runtime_error when the value does not have the required type
       * @return the jchar value of this JNIValue
       */
      jchar GetChar();
      /**
       * @brief Returns the value of this JNIValue as a jint.
       * @throws runtime_error when the value does not have the required type
       * @return the jint value of this JNIValue
       */
      jint GetInt();
      /**
       * @brief Returns the value of this JNIValue as a jobject.
       * @throws runtime_error when the value does not have the required type
       * @return the jobject value of this JNIValue
       */
      virtual jobject GetJObject();
      /**
       * @brief Returns the value of this JNIValue as a jlong.
       * @throws runtime_error when the value does not have the required type
       * @return the jlong value of this JNIValue
       */
      jlong GetLong();
      /**
       * @brief Returns the value of this JNIValue as a jdouble.
       * @throws runtime_error when the value does not have the required type
       * @return the jdouble value of this JNIValue
       */
      jdouble GetDouble();
      /**
       * @brief Returns the value of this JNIValue as a jfloat.
       * @throws runtime_error when the value does not have the required type
       * @return the jfloat value of this JNIValue
       */
      jfloat GetFloat();
  };
}

#endif // JNIVALUE_H
