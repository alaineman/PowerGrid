#include "javaenv.h"
#include <stdexcept>
#include "jniexception.h"
#include <QDir>

namespace jni {
  using namespace std;

  class JNIMethod;

  JavaEnv::JavaEnv() : QObject() {
    env = NULL;
    running = JNI_FALSE;
    setObjectName("JavaEnvironment");
  }

  // Intialize and set up the environment
  void JavaEnv::Start() {
    if (running) {
      throw logic_error("JVM already running.");
    }

    QString classpath("-Djava.class.path=");
 #ifndef Q_OS_DARWIN
    // In the case of Mac OS, the jagexappletviewer jar file is not accessible through the
    // native Runescape loader and must be packaged along with the application.
    QChar sep = QDir::separator();
    QString home = QDir::homePath().replace("/", sep);
    classpath.append(home).append(sep).append("jagexcache").append(sep)
             .append("jagexlauncher").append(sep).append("bin").append(sep);
#endif
    classpath.append("jagexappletviewer.jar");

    // We need to store the intermediate QByteArray, since the char* is not copied and as such
    // the pointer becomes invalid after the data() function returns.
    QByteArray cpArray = classpath.toUtf8();

    JavaVMInitArgs vmargs;
    vmargs.version            = JNI_VERSION_1_6;
    vmargs.ignoreUnrecognized = JNI_FALSE;

    // the JVM options themselves. They are all used because these are the same
    // that the official Runescape loader uses. We also use them since we're trying
    // to mimic the Runescape loader as accurately as possible.
    JavaVMOption options[9];    
    options[0].optionString  = const_cast<char*>(cpArray.data());
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
    qDebug() << "Environment created";

    JNIClass* c = GetClass("jagexappletviewer");
    if (c == NULL) qFatal("jagexappletviewer class not found");
    JNIMethod* m = c->GetMethod("main", "([Ljava/lang/String;)V");
    if (c == NULL) qFatal("main method not found");

    jobjectArray args = env->NewObjectArray(1, env->FindClass("java/lang/String"), env->NewStringUTF("runescape"));
    if (args == NULL) qFatal("Failed to create argument array");

    try {
      c->InvokeStaticMethod(m, args);
      qDebug() << "Runescape started and running";
    } catch (jni_error e) {
      qFatal(e.what());
    }

    if (jvm->DetachCurrentThread() < 0) {
        qWarning() << "Could not detach startup thread from the Java VM";
    }

    running = JNI_TRUE;
  }

  // Get basic JNI element types
  JNIClass* JavaEnv::GetClass(const char* name) {
    jclass cls = env->FindClass(name);
    JNIClass* jnic = new JNIClass(cls, this);
    // TODO: implement a caching system to speed up consecutive calls.
    return jnic;
  }

  jmethodID JavaEnv::GetMethodID(JNIClass* c, const char* name, const char* signature) {
    jmethodID meth = env->GetMethodID(static_cast<jclass>(c->GetJObject()), name, signature);
    return meth;
  }

  jmethodID JavaEnv::GetStaticMethodID(JNIClass* c, const char* name, const char* signature) {
    jmethodID meth = env->GetStaticMethodID(static_cast<jclass>(c->GetJObject()), name, signature);
    return meth;
  }

  QString JavaEnv::GetEnvironmentVersion() {
    if (running) {
      JNIClass* system = GetClass("java/lang/System");
      if (system == NULL) {
        throw jni_error("java.lang.System class not found");
      }
      JNIMethod* getProperty = system->GetMethod("getProperty", "(Ljava/lang/String;)Ljava/lang/String;");
      if (getProperty == NULL) {
        throw jni_error("java.lang.System.getProperty method not found");
      }
      JNIValue infoStr = system->InvokeStaticMethod(getProperty, env->NewStringUTF("java.version"));
      QString info (env->GetStringUTFChars(static_cast<jstring>(infoStr.GetJObject()), NULL));
      return info;
    } else {
      return QString();
    }
  }

  // Non-static Method Invocations

  jobject JavaEnv::CallObjectMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jobject result = env->CallObjectMethodV(obj, method, args);
    va_end(args);

    return result;
  }

  jint JavaEnv::CallIntMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jint result = env->CallIntMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jdouble JavaEnv::CallDoubleMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jdouble result = env->CallDoubleMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jboolean JavaEnv::CallBooleanMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jboolean result = env->CallBooleanMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jfloat JavaEnv::CallFloatMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jfloat result = env->CallFloatMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jbyte JavaEnv::CallByteMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jbyte result = env->CallByteMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jchar JavaEnv::CallCharMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jchar result = env->CallCharMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jlong JavaEnv::CallLongMethod(jobject obj, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jlong result = env->CallLongMethodV(obj, method, args);
    va_end(args);
    return result;
  }

  jshort JavaEnv::CallShortMethod(jobject obj, jmethodID method, uint n_args, ...) {
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
    jobject result = env->CallStaticObjectMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jint JavaEnv::CallStaticIntMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jint result = env->CallStaticIntMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jdouble JavaEnv::CallStaticDoubleMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jdouble result = env->CallStaticDoubleMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jboolean JavaEnv::CallStaticBooleanMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jboolean result = env->CallStaticBooleanMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jfloat JavaEnv::CallStaticFloatMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jfloat result = env->CallStaticFloatMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jbyte JavaEnv::CallStaticByteMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jbyte result = env->CallStaticByteMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jchar JavaEnv::CallStaticCharMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jchar result = env->CallStaticCharMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jlong JavaEnv::CallStaticLongMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jlong result = env->CallStaticLongMethodV(c, method, args);
    va_end(args);

    return result;
  }

  jshort JavaEnv::CallStaticShortMethod(jclass c, jmethodID method, uint n_args, ...) {
    va_list args;
    va_start(args, n_args);
    jshort result = env->CallStaticShortMethodV(c, method, args);
    va_end(args);

    return result;
  }

  JNIValue JavaEnv::CallStatic(jvalue_type ret_type, jclass c, jmethodID method, va_list args) {
    return JNIValue();
  }


  JNIMethod* JavaEnv::GetMethod(jclass c, const char* name, const char* signature) {
    // TODO: Look up from internal cache
    jboolean st = JNI_FALSE;
    jmethodID methodID = env->GetMethodID(c, name, signature);
    if (methodID == NULL) {
      methodID = env->GetStaticMethodID(c, name, signature);
      if (methodID == NULL) {
        return NULL;
      }
      st = JNI_TRUE;
    }
    jvalue_type retType = ParseReturnValueFromSignature(signature);
    // TODO: Store in internal cache
    return new JNIMethod(name, c, retType, vector<jvalue_type>(), st, methodID); // << warning: potential memory leak here, which will be fixed when cache is implemented, though.
  }

  jstring JavaEnv::CreateString(const char* str) {
    return env->NewStringUTF(str);
  }

  QString JavaEnv::GetString(JNIValue str) {
    jstring param = static_cast<jstring>(str.GetJObject());
    return QString(env->GetStringUTFChars(param, NULL));
  }

  QString JavaEnv::GetString(jstring str) {
    return QString(env->GetStringUTFChars(str, NULL));
  }

  jvalue_type JavaEnv::ParseReturnValueFromSignature(const char* signature) {
    std::string sig (signature);
    uint index = sig.find_last_of(')') + 1;
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

  vector<jvalue_type> JavaEnv::ParseArgumentTypesFromSignature(const char* signature) {
    std::string sig (signature);
    vector<jvalue_type> arguments;
    uint index = 0;
    uint end = sig.find_last_of(')');
    if (end >= sig.length()) {
        throw runtime_error("Invalid signature");
    }
    while (index < end) {
        char c = sig.at(index++);
        switch(c) {
        case 'Z': arguments.push_back(JBOOLEAN); break;
        case 'S': arguments.push_back(JSHORT);   break;
        case 'C': arguments.push_back(JCHAR);   break;
        case 'B': arguments.push_back(JBYTE);   break;
        case 'I': arguments.push_back(JINT); break;
        case 'J': arguments.push_back(JLONG); break;
        case 'D': arguments.push_back(JDOUBLE); break;
        case 'F': arguments.push_back(JFLOAT); break;
        case 'L':
            arguments.push_back(JOBJECT);
            // For object types, the substring denoting the class should be skipped before continuing.
            index = sig.find_first_of(';', index)+1;
            break;       
        default:
            qWarning() << "unrecognized type: " << c;
        }
    }
    return arguments;
  }
}
