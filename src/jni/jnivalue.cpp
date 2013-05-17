#include "jnivalue.h"

namespace jni {
  using namespace std;
  JNIValue::JNIValue() {
    value.i = 0;
    type    = JINT;
  }

  JNIValue::JNIValue(const JNIValue& val) {
    value = val.value;
    type  = val.type;
  }

  JNIValue::JNIValue(jvalue_type t, jvalue val) {
    value = val;
    type  = t;
  }

  JNIValue::JNIValue(jobject o) {
    value.l = o;
    type = JOBJECT;
  }

  jvalue JNIValue::Get() {
    return value;
  }

  jvalue_type JNIValue::GetType() {
    return type;
  }

  jboolean JNIValue::operator ==(JNIValue other) {
    if (GetType() != other.GetType()) {
      return JNI_FALSE;
    } else {
      jvalue val2 = other.Get();
      switch(type) {
        case JBOOLEAN: return value.z == val2.z;
        case JSHORT:   return value.s == val2.s;
        case JBYTE:    return value.b == val2.b;
        case JCHAR:    return value.c == val2.c;
        case JINT:     return value.i == val2.i;
        case JOBJECT:  return value.l == val2.l; // naive == instead of equals for performance reasons
        case JLONG:    return value.j == val2.j;
        case JDOUBLE:  return value.d == val2.d;
        case JFLOAT:   return value.f == val2.f;
        default:       return JNI_FALSE; // should not happen
      }
    }
  }

  jboolean JNIValue::GetBoolean() {
    VERIFY_THAT(type == JBOOLEAN);
    return value.z;
  }

  jshort JNIValue::GetShort() {
    VERIFY_THAT(type == JSHORT);
    return value.s;
  }

  jbyte JNIValue::GetByte() {
    VERIFY_THAT(type == JBYTE);
    return value.b;
  }

  jchar JNIValue::GetChar() {
    VERIFY_THAT(type == JCHAR);
    return value.c;
  }

  jint JNIValue::GetInt() {
    VERIFY_THAT(type == JINT);
    return value.i;
  }

  jobject JNIValue::GetObject() {
    VERIFY_THAT(type == JOBJECT);
    return value.l;
  }

  jlong JNIValue::GetLong() {
    VERIFY_THAT(type == JLONG);
    return value.j;
  }

  jdouble JNIValue::GetDouble() {
    VERIFY_THAT(type == JDOUBLE);
    return value.d;
  }

  jfloat JNIValue::GetFloat() {
    VERIFY_THAT(type == JFLOAT);
    return value.f;
  }

}
