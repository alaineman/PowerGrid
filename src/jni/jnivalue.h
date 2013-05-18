#include "stdafx.h"
#include "jni.h"

#ifndef JNIVALUE_H
#define JNIVALUE_H

namespace jni {

class JNIValue {
  private:
    jvalue value;
    jvalue_type type;
  public:
    JNIValue();
    JNIValue(jvalue_type t, jvalue val);
    JNIValue(jobject o);
    JNIValue(const JNIValue& val);
    //JNIValue operator = (OngoingInvocation oi);

    jboolean operator== (JNIValue v);
    //bool operator== (OngoingInvocation oi);

    jvalue_type GetType();
    jvalue Get();

    jboolean GetBoolean();
    jshort GetShort();
    jbyte GetByte();
    jchar GetChar();
    jint GetInt();
    jobject GetObject();
    jlong GetLong();
    jdouble GetDouble();
    jfloat GetFloat();
};

}

#endif // JNIVALUE_H
