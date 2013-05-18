#ifndef ONGOINGINVOCATION_H
#define ONGOINGINVOCATION_H

#include "stdafx.h"
#include "jnimethod.h"

namespace jni {

class OngoingInvocation {
  private:
    jobject object;
    JNIMethod* method;
    vector<JNIValue> arguments;
  public:
    OngoingInvocation(jobject o, JNIMethod* m);

    vector<JNIValue> GetArguments();

    OngoingInvocation operator << (jobject);
    //OngoingInvocation operator << (jboolean);
    //OngoingInvocation operator << (jbyte);
    //OngoingInvocation operator << (jchar);
    //OngoingInvocation operator << (jshort);
    //OngoingInvocation operator << (jint);
    //OngoingInvocation operator << (jlong);
    //OngoingInvocation operator << (jfloat);
    //OngoingInvocation operator << (jdouble);
    OngoingInvocation operator << (JNIValue);

    jboolean isValid();

    jvalue_type GetNextArgumentType();
};

}

#endif // ONGOINGINVOCATION_H
