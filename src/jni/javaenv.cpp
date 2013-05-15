#include "javaenv.h"
#include <stdexcept>
#include <QDir>

namespace jni {
  using namespace std;

  JavaEnv::JavaEnv() {
    env = NULL;
    running = JNI_FALSE;
  }

  JavaEnv::~JavaEnv() {}

  void JavaEnv::VerifyNonNull(void* pntr, const char* message) {
    if (pntr == NULL) {
        throw runtime_error(message);
    }
  }

  void JavaEnv::Setup() {
    if (running) {
      throw runtime_error("JVM already running.");
    }

    QString classpath("-Djava.class.path=");
    QChar sep = QDir::separator();
    QString home = QDir::homePath().replace("/", "\\");
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
    VerifyNonNull(jvm, "JVM == NULL");
    VerifyNonNull(env, "env == NULL");
    qDebug() << "Environment created";
    running = JNI_TRUE;
  }

  void JavaEnv::Start() {
    if (!running) {
      throw runtime_error("Environment must be running");
    }
    jclass c = GetClass("jagexappletviewer");
    jmethodID mainMethod = env->GetStaticMethodID(c, "main", "([Ljava/lang/String;)V");
    jobjectArray args = env->NewObjectArray(1, env->FindClass("java/lang/String"),
                                    env->NewStringUTF("runescape"));

    env->CallStaticVoidMethod(c, mainMethod, args);
  }

  QString JavaEnv::GetEnvironmentVersion() {
    jclass system = GetClass("java/lang/System");
    jmethodID getProperty = GetStaticMethodID(system, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring infoStr = (jstring) env->CallStaticObjectMethod(system, getProperty, env->NewStringUTF("java.version"));
    const char* info = env->GetStringUTFChars(infoStr, NULL);
    return QString(info);
  }

  jclass JavaEnv::GetClass(const char *name) {
    VerifyNonNull(const_cast<char*>(name), "Name cannot be NULL");
    jclass cls = env->FindClass(name);
    // TODO: implement a caching system to speed up consecutive calls.
    return cls;
  }

  jmethodID JavaEnv::GetMethodID(jclass c, const char *name, const char *signature) {
    VerifyNonNull(c);
    VerifyNonNull(const_cast<char*>(name));
    VerifyNonNull(const_cast<char*>(signature));
    jmethodID meth = env->GetMethodID(c, name, signature);

    return meth;
  }

  jmethodID JavaEnv::GetStaticMethodID(jclass c, const char *name, const char *signature) {
    VerifyNonNull(c);
    VerifyNonNull(const_cast<char*>(name));
    VerifyNonNull(const_cast<char*>(signature));
    jmethodID meth = env->GetStaticMethodID(c, name, signature);

    return meth;
  }

  JNIEnv* JavaEnv::GetEnv() {
    return env;
  }

  jboolean JavaEnv::IsRunning() {
    return running;
  }

  jobject JavaEnv::CallObjectMethod(jmethodID method, jobject obj, int n_args ...) {
    va_list args;
    va_start(args, n_args);
    VerifyNonNull(method);
    VerifyNonNull(obj);
    jobject result = env->CallObjectMethodV(obj, method, args);
    va_end(args);

    return result;
  }

  jint JavaEnv::CallIntMethod(jmethodID method, jobject obj, int n_args, ...) {
    va_list args;
    va_start(args, n_args);
    VerifyNonNull(method);
    VerifyNonNull(obj);
    jint result = env->CallIntMethodV(obj, method, args);
    va_end(args);
    return result;
  }
}
