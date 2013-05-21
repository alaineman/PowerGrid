#include "javaenv.h"
#include <stdexcept>
#include <QDir>


namespace jni {
  using namespace std;

  JavaEnv::JavaEnv() {
    env = NULL;
    running = JNI_FALSE;
  }


  // Intialize and set up the environment

  void JavaEnv::Start() {
    if (running) {
      throw runtime_error("JVM already running.");
    }

    QString classpath("-Djava.class.path=");
    QChar sep = QDir::separator();
    QString home = QDir::homePath().replace("/", sep);
    classpath.append(home).append(sep).append("jagexcache").append(sep)
             .append("jagexlauncher").append(sep).append("bin").append(sep)
             .append("jagexappletviewer.jar");

    std::string printpath = classpath.toStdString();
    //qDebug() << qPrintable(classpath);

    JavaVMInitArgs vmargs;
    vmargs.version            = JNI_VERSION_1_6;
    vmargs.ignoreUnrecognized = JNI_FALSE;

    // the JVM options themselves. They are all used because these are the same
    // that the official Runescape loader uses. We also use them since we're trying
    // to mimic the Runescape loader as accurately as possible.
    JavaVMOption options[9];    
    options[0].optionString  = const_cast<char*>(printpath.c_str());
    options[1].optionString  = const_cast<char*>("-Dsun.java2d.noddraw=true");
    // The entire configuration for loading Runescape itself is stored on this link.
    // The appletloader parses it by itself, so loading the client can be done completely native.
    options[2].optionString  = const_cast<char*>("-Dcom.jagex.config=http://www.runescape.com/k=3/l=$(language:0)/jav_config.ws");
    options[3].optionString  = const_cast<char*>("-Xmx256m");
    options[4].optionString  = const_cast<char*>("-Xss2m");
    options[5].optionString  = const_cast<char*>("-XX:CompileThreshold=1500");
    options[6].optionString  = const_cast<char*>("-Xincgc");
    options[7].optionString  = const_cast<char*>("-XX:+UseConcMarkSweepGC");
    options[8].optionString  = const_cast<char*>("-XX:+UseParNewGC");

    vmargs.options = options;
    vmargs.nOptions = 9;

    JavaVM* jvm = NULL;

    qDebug() << "Creating Java Virtual Machine";
    JNI_CreateJavaVM(&jvm, (void**)&env, &vmargs);
    VERIFY_NON_NULL(jvm);
    VERIFY_NON_NULL(env);
    qDebug() << "Environment created";

    jclass c = GetClass("jagexappletviewer");
    jmethodID mainMethod = env->GetStaticMethodID(c, "main", "([Ljava/lang/String;)V");
    jobjectArray args = env->NewObjectArray(1, env->FindClass("java/lang/String"),
                                    env->NewStringUTF("runescape"));

    env->CallStaticVoidMethod(c, mainMethod, args);
    qDebug() << "Runescape started and running";

    running = JNI_TRUE;
  }


  // Get basic JNI element types

  jclass JavaEnv::GetClass(cstring name) {
    VALID_JAVA_ID_CHARS(name);
    jclass cls = env->FindClass(name);
    // TODO: implement a caching system to speed up consecutive calls.
    return cls;
  }

  jmethodID JavaEnv::GetMethodID(jclass c, cstring name, cstring signature) {
    VERIFY_NON_NULL(c);
    VALID_JAVA_ID_CHARS(name);
    VERIFY_THAT(strlen(signature) != 0);
    jmethodID meth = env->GetMethodID(c, name, signature);

    return meth;
  }

  jmethodID JavaEnv::GetStaticMethodID(jclass c, cstring name, cstring signature) {
    VERIFY_NON_NULL(c);
    VALID_JAVA_ID_CHARS(name);
    VERIFY_THAT(strlen(signature) != 0);
    jmethodID meth = env->GetStaticMethodID(c, name, signature);

    return meth;
  }


  // Get state and environment information

  JNIEnv* JavaEnv::GetEnv() {
    return env;
  }

  jboolean JavaEnv::IsRunning() {
    return running;
  }

  QString JavaEnv::GetEnvironmentVersion() {
    if (running) {
//      jclass system = GetClass("java/lang/System");
//      jmethodID getProperty = GetStaticMethodID(system, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");
//      jstring infoStr = (jstring) CallStaticObjectMethod(system, getProperty, 1, env->NewStringUTF("java.version"));
//      cstring info = env->GetStringUTFChars(infoStr, NULL);
      jclass system = GetClass("java/lang/System");
      JNIMethod* getProperty = GetMethod(system, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");
      jstring property = CreateString("java.version");
      JNIValue prop;
      try {
        prop = CallStatic(getProperty) << property << Invoke();
      } catch (runtime_error e) {
        qDebug() << e.what();
        return QString("<failed to fetch info>");
      }
      cstring info = GetString(prop);
      return QString(info);
    } else {
      return QString("<not running>");
    }
  }

  // Non-static Method Invocations

  jobject JavaEnv::CallObjectMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(method);
    VERIFY_NON_NULL(obj);
    jobject result = env->CallObjectMethodV(obj, method, args);
    va_end(args);

    return result;
  }

  jint JavaEnv::CallIntMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(method);
    VERIFY_NON_NULL(obj);
    jint result = env->CallIntMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jdouble JavaEnv::CallDoubleMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(method);
    VERIFY_NON_NULL(obj);
    jdouble result = env->CallDoubleMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jboolean JavaEnv::CallBooleanMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(method);
    VERIFY_NON_NULL(obj);
    jboolean result = env->CallBooleanMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jfloat JavaEnv::CallFloatMethod(jobject obj, jmethodID method, uint n_args, ...) {
    VERIFY_NON_NULL(obj);
    VERIFY_NON_NULL(method);
    va_list args;
    va_start(args, n_args);
    jfloat result = env->CallFloatMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jbyte JavaEnv::CallByteMethod(jobject obj, jmethodID method, uint n_args, ...) {
    VERIFY_NON_NULL(obj);
    VERIFY_NON_NULL(method);
    va_list args;
    va_start(args, n_args);
    jbyte result = env->CallByteMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jchar JavaEnv::CallCharMethod(jobject obj, jmethodID method, uint n_args, ...) {
    VERIFY_NON_NULL(obj);
    VERIFY_NON_NULL(method);
    va_list args;
    va_start(args, n_args);
    jchar result = env->CallCharMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jlong JavaEnv::CallLongMethod(jobject obj, jmethodID method, uint n_args, ...) {
    VERIFY_NON_NULL(obj);
    VERIFY_NON_NULL(method);
    va_list args;
    va_start(args, n_args);
    jlong result = env->CallLongMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jshort JavaEnv::CallShortMethod(jobject obj, jmethodID method, uint n_args, ...) {
    VERIFY_NON_NULL(obj);
    VERIFY_NON_NULL(method);
    va_list args;
    va_start(args, n_args);
    jshort result = env->CallShortMethodV(obj, method, args);
    va_end(args);
    return result;
  }


  // Static Method Invocations

  jobject JavaEnv::CallStaticObjectMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jobject result = env->CallStaticObjectMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jint JavaEnv::CallStaticIntMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jint result = env->CallStaticIntMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jdouble JavaEnv::CallStaticDoubleMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jdouble result = env->CallStaticDoubleMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jboolean JavaEnv::CallStaticBooleanMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jboolean result = env->CallStaticBooleanMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jfloat JavaEnv::CallStaticFloatMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jfloat result = env->CallStaticFloatMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jbyte JavaEnv::CallStaticByteMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jbyte result = env->CallStaticByteMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jchar JavaEnv::CallStaticCharMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jchar result = env->CallStaticCharMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jlong JavaEnv::CallStaticLongMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jlong result = env->CallStaticLongMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jshort JavaEnv::CallStaticShortMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VERIFY_NON_NULL(c);
    VERIFY_NON_NULL(method);
    jshort result = env->CallStaticShortMethodV(c, method, args);
    va_end(args);

    return result;
  }


  JNIMethod* JavaEnv::GetMethod(jclass c, cstring name, cstring signature) {
    // TODO: Look up from internal cache
    jboolean st = JNI_FALSE;
    jmethodID methodID = GetMethodID(c, name, signature);
    if (methodID == NULL) {
      methodID = GetStaticMethodID(c, name, signature);
      if (methodID == NULL) {
        return NULL;
      }
      st = JNI_TRUE;
    }
    jvalue_type retType = ParseReturnValueFromSignature(signature);
    // TODO: Store in internal cache
    return new JNIMethod(name, c, retType, vector<jvalue_type>(), st, methodID); // << warning: potential memory leak here, which will be fixed when cache is implemented, though.
  }

  OngoingInvocation JavaEnv::Call(JNIValue object, JNIMethod *method) {
    if (object.GetType() != JOBJECT) {
      throw runtime_error("Invalid value for Call: expected JOBJECT type");
    }
    return OngoingInvocation(this, object.GetObject(), method);
  }

  OngoingInvocation JavaEnv::CallStatic(JNIMethod *method) {
    return OngoingInvocation(this, NULL, method);
  }

  jstring JavaEnv::CreateString(cstring str) {
    return env->NewStringUTF(str);
  }

  cstring JavaEnv::GetString(JNIValue str) {
    VERIFY_THAT(str.GetType() == JOBJECT);
    jstring param = (jstring) str.GetObject();
    return env->GetStringUTFChars(param, NULL);
  }

  cstring JavaEnv::GetString(jstring str) {
    VERIFY_NON_NULL(str);
    return env->GetStringUTFChars(str, NULL);
  }

  jvalue_type JavaEnv::ParseReturnValueFromSignature(cstring signature) {
    VERIFY_NON_NULL(signature);
    std::string sig (signature);
    uint index = sig.find(')') + 1;
    if (index < sig.length()) {
      char c = sig.at(index);
      switch (c) {
        case 'Z': return JBOOLEAN;
        case 'S': return JSHORT;
        case 'C': return JCHAR;
        case 'V': return JVOID;
        case 'B': return JBYTE;
        case 'L': return JOBJECT;
        case 'I': return JINT;
        case 'J': return JLONG;
        case 'D': return JDOUBLE;
        case 'F': return JFLOAT;
      }
    }
    throw runtime_error("Invalid signature");
  }
}
