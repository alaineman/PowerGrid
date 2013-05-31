#include "jnivalue.h"
#include "jniexception.h"

using namespace std;

namespace jni {

  JNIValue::JNIValue(jvalue_type t, jvalue val) {
    if (t != JVOID) {
      // If the type is JVOID we don't save the jvalue, since we don't retrieve it anyway.
      value = val;
    }
    type  = t;
  }

  JNIValue::JNIValue(jobject o) {
    value.l = o;
    type = JOBJECT;
  }

  JNIValue::JNIValue(jboolean z) {
    value.z = z;
    type = JBOOLEAN;
  }

  JNIValue::JNIValue(jbyte b) {
    value.b = b;
    type = JBYTE;
  }

  JNIValue::JNIValue(jchar c) {
    value.c = c;
    type = JCHAR;
  }

  JNIValue::JNIValue(jdouble d) {
    value.d = d;
    type = JDOUBLE;
  }

  JNIValue::JNIValue(jfloat f) {
    value.f = f;
    type = JFLOAT;
  }

  JNIValue::JNIValue(jint i) {
    value.i = i;
    type = JINT;
  }

  JNIValue::JNIValue(jlong l) {
    value.j = l;
    type = JLONG;
  }

  JNIValue::JNIValue(jshort s) {
    value.s = s;
    type = JSHORT;
  }

  jboolean JNIValue::operator ==(JNIValue other) {
    if (type != other.GetType()) {
      return JNI_FALSE;
    } else {
      jvalue val2 = other.Get();
      switch(type) {
        case JVOID:    return JNI_TRUE; // void type == void type regardless of actual content.
        case JBOOLEAN: return value.z == val2.z;
        case JSHORT:   return value.s == val2.s;
        case JBYTE:    return value.b == val2.b;
        case JCHAR:    return value.c == val2.c;
        case JINT:     return value.i == val2.i;
        case JOBJECT:  return value.l == val2.l;
        case JLONG:    return value.j == val2.j;
        case JDOUBLE:  return value.d == val2.d;
        case JFLOAT:   return value.f == val2.f;
        default:       throw logic_error("Invalid or unknown JNIValue"); // should not happen
      }
    }
  }


  jboolean JNIValue::GetBoolean() {
    if (type != JBOOLEAN) {
        throw logic_error("Invalid Get request");
    }
    return value.z;
  }

  jshort JNIValue::GetShort() {
    if (type != JSHORT) {
        throw logic_error("Invalid Get request");
    }
    return value.s;
  }

  jbyte JNIValue::GetByte() {
    if (type != JBYTE) {
        throw logic_error("Invalid Get request");
    }
    return value.b;
  }

  jchar JNIValue::GetChar() {
    if (type != JCHAR) {
        throw logic_error("Invalid Get request");
    }
    return value.c;
  }

  jint JNIValue::GetInt() {
    if (type != JINT) {
        throw logic_error("Invalid Get request");
    }
    return value.i;
  }

  jobject JNIValue::GetJObject() {
    if (type != JOBJECT) {
        throw logic_error("Invalid Get request");
    }
    return value.l;
  }

  jlong JNIValue::GetLong() {
    if (type != JLONG) {
        throw logic_error("Invalid Get request");
    }
    return value.j;
  }

  jdouble JNIValue::GetDouble() {
    if (type != JDOUBLE) {
        throw logic_error("Invalid Get request");
    }
    return value.d;
  }

  jfloat JNIValue::GetFloat() {
    if (type != JFLOAT) {
        throw logic_error("Invalid Get request");
    }
    return value.f;
  }

}
