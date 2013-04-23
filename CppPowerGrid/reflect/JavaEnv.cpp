#include "jni.h"
#include "JavaEnv.h"
#include <iostream>

using namespace std;

namespace powergrid {
namespace reflect {
    JavaEnv::~JavaEnv() {
        // Make sure the JVM is no longer running when this object is removed.
        Terminate();
    }
    
    JNIEnv* JavaEnv::Env() {
        return env;
    }
    
    JavaVM* JavaEnv::JVM() {
        return jvm;
    }
    
    void JavaEnv::Setup(const char* classpath, const char* mainClass) {
        //TODO move this to separate Thread.
        JavaVMInitArgs args;
        args.version = JNI_VERSION_1_6;
        args.nOptions = 1;
        args.options = new JavaVMOption;
        args.options[0].optionString = strcat(C_TEXT("-Djava.class.path="), classpath);
        JNI_CreateJavaVM(&jvm, (void**)(&env), &args);
        jclass c = env->FindClass(mainClass);
        if (c == NULL) {
            cout << "Main Class not on provided classpath" << endl;
            throw JAVAENV_MISSING_CLASS;
        }
        jmethodID main = env->GetStaticMethodID(c, "main", "([Ljava.lang.String;)V");
        if (main == NULL) {
            cout << "Provided class does not contain main method" << endl;
            throw JAVAENV_MISSING_METHOD;
        }
        jobjectArray mainArgs = env->NewObjectArray(0, env->FindClass("java.lang.String"), NULL);
        
        env->CallStaticVoidMethod(c, main, mainArgs);
        
    }
    
    jclass JavaEnv::FindClass(const char* name) {
        return env->FindClass(name);
    }
    
    jmethodID JavaEnv::FindMethod(jclass c, const char* name, const char* sig) {
        return env->GetMethodID(c, name, sig);
    }
    
    int JavaEnv::FindSubclasses(jclass* children, jclass parent) {
        return 0;
    }
    
    int JavaEnv::Terminate() {
        jvm->DestroyJavaVM();
        delete env;
        delete jvm;
        return 0;
    }
}
}
