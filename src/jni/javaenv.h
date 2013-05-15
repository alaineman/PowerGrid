#ifndef JAVAENV_H
#define JAVAENV_H

#include "stdafx.h"
#include <jni.h>


namespace jni {
  using namespace std;



  // The JavaEnv class is a C++ wrapper around the Java environment (JNIEnv struct).
  // The functions this class provides check for illegal arguments, like NULL values.
  // The original JNI does not do this, and as such errors could occur when providing the
  // JNI with such arguments.
  class JavaEnv {
  private:
    static JavaEnv* environment;
    // pointer to the JNIEnv object
    JNIEnv* env;
    // Flag indicating if the environment has started.
    jboolean running;

    void VerifyNonNull(void* pntr, const char* message = "NULL value not allowed");

  public:
    static JavaEnv* Instance();
    // Constructor and destructor don't really do anything useful.
    JavaEnv();
    ~JavaEnv();

    // Returns the environment. Calling this before calling Setup does not give a valid JNIEnv object
    JNIEnv* GetEnv();

    jboolean IsRunning();

    // Setup function for the JNI environment. throws runtime_error upon failure.
    void Setup();

    void Start();

    // Accessor functions for looking up classes and methods. They check for NULL values and such.
    jclass GetClass(const char* name);
    jmethodID GetMethodID(jclass c, const char* name, const char* signature);
    jmethodID GetStaticMethodID(jclass c, const char* name, const char* signature);

    // Version of the currently loaded environment as a QString
    QString GetEnvironmentVersion();

    // Safe versions of all (14) method invocation functions. They check NULL values and such.
    jobject  CallObjectMethod  (jobject obj, jmethodID method, int n_args, ...);
    jint     CallIntMethod     (jobject obj, jmethodID method, int n_args, ...);
    jdouble  CallDoubleMethod  (jobject obj, jmethodID method, int n_args, ...);
    //jboolean CallBooleanMethod (jobject obj, jmethodID method, int n_args, ...);
    //jfloat   CallFloatMethod   (jobject obj, jmethodID method, int n_args, ...);
    //jbyte    CallByteMethod    (jobject obj, jmethodID method, int n_args, ...);
    //jchar    CallCharMethod    (jobject obj, jmethodID method, int n_args, ...);

    //jobject  CallStaticObjectMethod  (jmethodID method, ...);
    //jint     CallStaticIntMethod     (jmethodID method, ...);
    //jdouble  CallStaticDoubleMethod  (jmethodID method, ...);
    //jboolean CallStaticBooleanMethod (jmethodID method, ...);
    //jfloat   CallStaticFloatMethod   (jmethodID method, ...);
    //jbyte    CallStaticByteMethod    (jmethodID method, ...);
    //jchar    CallStaticCharMethod    (jmethodID method, ...);

  };
}

#endif // JAVAENV_H
