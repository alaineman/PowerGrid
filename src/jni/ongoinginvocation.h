#ifndef ONGOINGINVOCATION_H
#define ONGOINGINVOCATION_H

#include "stdafx.h"
#include "jnimethod.h"

namespace jni {
  class JavaEnv;
  class Invoke {};

class OngoingInvocation {
  private:
    jvalue* CreateArgumentArray();

    JavaEnv* env;
    jobject object;
    JNIMethod* method;
    vector<JNIValue> arguments;
  public:
    OngoingInvocation(const OngoingInvocation& orig);
    OngoingInvocation(JavaEnv* e, jobject o, JNIMethod* m);

    vector<JNIValue> GetArguments();
    JNIMethod* GetMethod();
    jobject GetObject();

    jvalue_type GetNextArgumentType();
    jvalue_type GetReturnType();

    jboolean isValid();

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
    JNIValue          operator << (Invoke);

    void ClearArguments();

    JNIValue Execute();
};

}

#endif // ONGOINGINVOCATION_H
