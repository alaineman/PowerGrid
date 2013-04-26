#include "jni.h"
#include "JavaEnv.h"
#include <iostream>
#include <stdarg.h>

using namespace std;

namespace powergrid {
namespace reflect {
	JavaEnv::JavaEnv(HINSTANCE h) {
		hInstance = h;
		jvm = NULL;
		env = NULL;
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
    
    void JavaEnv::Setup() {

		// Find the Jagex launcher's bin folder
		char jagexfolder[512];
		ExpandEnvironmentStrings("%USERPROFILE%\\jagexcache\\jagexlauncher\\bin", jagexfolder, 512);

		// try loading jvm dll
		string java_dll (jagexfolder);
		java_dll += "\\jvm.dll";
		HMODULE jvmDll = LoadLibrary(java_dll.c_str());
		if(jvmDll == NULL) { 
			throw JavaEnvException("jvm.dll not found");
		}

		// Get the "JNI_CreateJavaVM" procedure from the loaded DLL
		CreateJavaVM createJVM = (CreateJavaVM)GetProcAddress(jvmDll, "JNI_CreateJavaVM");
		if (createJVM == NULL)  {
			throw JavaEnvException("JNI_CreateJavaVM procedure not found");
		}

		// Get the Jagex cache location (the appletviewer must be in the correct directory).
		string cp(jagexfolder);
		cp += "\\jagexappletviewer.jar";
		string classpath = string("-Djava.class.path=").append(cp);

		JavaVMInitArgs vm_args;
		vm_args.version            = JNI_VERSION_1_6;
		vm_args.ignoreUnrecognized = JNI_FALSE;

		JavaVMOption options[10];
		options[0].optionString  = const_cast<char*>(classpath.c_str());
		options[1].optionString  = "-verbose:jni";
		options[2].optionString  = "-Dsun.java2d.noddraw=true";
		options[3].optionString  = "-Dcom.jagex.config=http://www.runescape.com/k=3/l=$(language:0)/jav_config.ws";
		options[4].optionString  = "-Xmx256m";
		options[5].optionString  = "-Xss2m";
		options[6].optionString  = "-XX:CompileThreshold=1500";
		options[7].optionString  = "-Xincgc";
		options[8].optionString  = "-XX:+UseConcMarkSweepGC";
		options[9].optionString  = "-XX:+UseParNewGC";

		vm_args.options          = options;
		vm_args.nOptions         = 10;
 
		//Create the JVM
		jint res = createJVM(&jvm, (void**)&env, &vm_args);

		jvm->AttachCurrentThread((void**)&env, NULL);

		if (res < 0) {
			throw JavaEnvException("Error Creating JVM, result code: " + res);
		}
		jclass c = env->FindClass("jagexappletviewer");
		if (c == NULL) {
			throw JavaEnvException("Main Class not on classpath");
		}
		jmethodID main = env->GetStaticMethodID(c, "main", "([Ljava/lang/String;)V");
		if (main == NULL) {
			throw JavaEnvException("Provided class does not contain main method");
		}
		jobjectArray mainArgs = env->NewObjectArray(1, env->FindClass("java/lang/String"), NULL);
		env->SetObjectArrayElement(mainArgs, 0, env->NewStringUTF("runescape"));
        env->CallStaticVoidMethod(c, main, mainArgs);
    }
    
    jclass JavaEnv::FindClass(LPSTR name) {
        return env->FindClass(name);
    }
    
    jmethodID JavaEnv::FindMethod(jclass c, LPSTR name, LPSTR sig) {
        return env->GetMethodID(c, name, sig);
    }

	jmethodID JavaEnv::FindConstructor(jclass c, LPSTR sig) {
		return FindMethod(c, "<init>", sig);
	}
    
    int JavaEnv::FindSubclasses(jclass* children, jclass parent) {
        return 0;
    }
    
    int JavaEnv::Terminate() {
		if (jvm != NULL) {
			jvm->DetachCurrentThread();
			jvm->DestroyJavaVM();
		}
        return 0;
    }

	jclass JavaEnv::GetClass(jobject o) {
		return env->GetObjectClass(o);
	}

	string JavaEnv::AsString(jobject object) {
		jmethodID getClassMethod = FindMethod(FindClass("java/lang/Object"), 
			"toString", "()Ljava/lang/String;");
		jstring res = (jstring)env->CallObjectMethod(object, getClassMethod);
		return string(env->GetStringUTFChars(res, NULL));
	}

	void JavaEnv::ThrowException(LPCSTR file, INT line, LPCSTR info) {
		LPSTR errorMessage = "";

		if (file != NULL && line != 0 && info != NULL) {
			sprintf(errorMessage, "JNIException at %s:%d (%s)", file, line, info);
		}

		jclass eClass = NULL;

		eClass = env->FindClass("java/lang/Exception");
		env->ThrowNew(eClass, errorMessage);
		env->DeleteLocalRef(eClass);
	}
}
}
