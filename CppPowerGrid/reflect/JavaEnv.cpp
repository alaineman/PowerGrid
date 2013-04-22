#include "jni.h"
#include "JavaEnv.h"

namespace powergrid {
namespace reflect {
    JavaEnv::~JavaEnv() {
        Terminate();
    }
    
    JNIEnv* JavaEnv::Env() {
        return env;
    }
    
    JavaVM* JavaEnv::JVM() {
        return jvm;
    }
    
    int JavaEnv::Setup(const char* classpath, const char* mainClass) {
        JavaVMInitArgs args;
        args.version = JNI_VERSION_1_6;
        args.nOptions = 1;
        args.options = new JavaVMOption;
        
        args.options[0] = "-Djava.class.path=" + classpath;
        JNI_CreateJavaVM(jvm, reinterpret_cast<void**>(env), args);
    }
    
    jclass JavaEnv::FindClass(const char* name) {
        return env->FindClass(name);
    }
    
    jclass JavaEnv::FindClass(jclass annotation) {
        //TODO implement FindClass(jclass)
    }
    
    jmethodID JavaEnv::FindMethod(jclass c, const char* name, const char* sig) {
        return env->GetMethodID(c, name, sig);
    }
}
}
