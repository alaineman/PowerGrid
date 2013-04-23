#include "jni.h"
#include "JavaEnv.h"
#include <iostream>
#include <stdarg.h>

using namespace std;

namespace powergrid {
namespace reflect {
	JavaEnv::JavaEnv(HINSTANCE h) {
		hInstance = h;
	}

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

		LPTSTR java_home;
		LPTSTR buf = (LPTSTR) malloc(1024 * sizeof(TCHAR));

		// find the JAVA_HOME directory
		GetEnvironmentVariable(TEXT("JAVA_HOME"), buf, 1024);
		if (!buf) {
			throw JavaEnvException("NULL value for JAVA_HOME");
		}
		java_home = buf;
		LPTSTR java_dll = java_home;
		java_dll = strcat(java_dll, TEXT("\\bin\\server\\jvm.dll"));
		
		// try loading jvm dll
		jvmDll = LoadLibraryA(java_home);
		if(!jvmDll) { 
			throw JavaEnvException("jvm.dll not found");
		}

		// Get the class path.
		string cp = "-Djava.class.path=";
		cp += classpath; 
 
		// Construct the java.library.path
		string lp = "-Djava.library.path=";
		lp += java_home;
		lp += "\\lib,";
		lp += java_home;
		lp += "\\jre\\lib";
     
		// Get the "JNI_CreateJavaVM" procedure from the loaded DLL
		CreateJavaVM createJVM = (CreateJavaVM)GetProcAddress(jvmDll, "JNI_CreateJavaVM");
		if (!createJVM)  {
			throw JavaEnvException("JNI_CreateJavaVM procedure not found");
		}
 
		JavaVMOption options[3];
		options[0].optionString  = const_cast<char*>(cp.c_str());
		options[1].optionString  = const_cast<char*>(lp.c_str());
		options[2].optionString  = "-verbose:jni";
 
		JavaVMInitArgs vm_args;
		vm_args.version            = JNI_VERSION_1_6;
		vm_args.options            = options;   
		vm_args.nOptions           = 3;      
		vm_args.ignoreUnrecognized = JNI_TRUE;
 
		//Create the JVM
		jint res = createJVM(&jvm, (void**)&env, &vm_args);
		if (res < 0) {
			throw JavaEnvException("Error Creating JVM, result code: " + res);
		}
		if (mainClass != NULL) {
			jclass c = env->FindClass(mainClass);
			if (c == NULL) {
				throw JavaEnvException("Main Class not on provided classpath");
			}
			jmethodID main = env->GetStaticMethodID(c, "main", "([Ljava.lang.String;)V");
			if (main == NULL) {
				throw JavaEnvException("Provided class does not contain main method");
			}
			jobjectArray mainArgs = env->NewObjectArray(0, 
				env->FindClass("java.lang.String"), NULL);
        
			env->CallStaticVoidMethod(c, main, mainArgs);
		}
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
		if (jvm) {
			jvm->DestroyJavaVM();
			delete jvm;
		}
		if (env) {
			delete env;
		}
        return 0;
    }

	jclass JavaEnv::GetClass(jobject o) {
		return env->GetObjectClass(o);
	}

	string JavaEnv::AsString(jobject object) {
		jmethodID getClassMethod = FindMethod(FindClass("java.lang.Object"), 
			"toString", "()Ljava.lang.String;");
		jstring res = (jstring)env->CallObjectMethod(object, getClassMethod);
		return string(env->GetStringUTFChars(res, NULL));
	}
}
}
