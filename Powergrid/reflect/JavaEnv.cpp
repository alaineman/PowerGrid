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
		//InitializeCriticalSection(&lock);
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
		//EnterCriticalSection(&lock);
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

		// Required classes / methods
		jclass window = FindClass("java/awt/Window");
		jclass frame = FindClass("java/awt/Frame");
		jclass jframe = FindClass("javax/swing/JFrame");

		jmethodID getWindows = env->GetStaticMethodID(window, "getWindows", "()[Ljava/awt/Window;");
		jmethodID getTitle = FindMethod(frame, "getTitle", "()Ljava/lang/String;");
		jmethodID setCloseOp = FindMethod(jframe, "setDefaultCloseOperation", "(I)V");

		jobject theWindow = NULL;

		bool windowCreated = false;
		do {
			jobjectArray windows = (jobjectArray)env->CallStaticObjectMethod(window, getWindows);
			if (env->GetArrayLength(windows) > 0) {
				theWindow = env->GetObjectArrayElement(windows, 0);
				jstring string = (jstring)env->CallObjectMethod(theWindow, getTitle);
				std::string title(env->GetStringUTFChars(string, NULL));
				windowCreated = !title.compare("RuneScape");
			}
		} while (!windowCreated);

		env->CallVoidMethod(theWindow, setCloseOp, 2); // WindowConstants.DISPOSE_ON_CLOSE

		//LeaveCriticalSection(&lock);
    }
    
    jclass JavaEnv::FindClass(LPSTR name) {
        return env->FindClass(name);
    }
    
    jmethodID JavaEnv::FindMethod(jclass c, LPSTR name, LPSTR sig) {
        return env->GetMethodID(c, name, sig);
    }

	jmethodID JavaEnv::FindConstructor(jclass c, LPSTR sig) {
		return env->GetMethodID(c, "<init>", sig);
	}
    
    int JavaEnv::FindSubclasses(jclass* children, jclass parent) {
        return 0;
    }
    
    int JavaEnv::Terminate() {
		if (jvm != NULL) {
			jvm->DestroyJavaVM();
		}
        return 0;
    }

	jclass JavaEnv::GetClass(jobject o) {
		return env->GetObjectClass(o);
	}

	string JavaEnv::AsString(jobject object) {
		if (object == NULL) {
			return "NULL";
		}
		jclass stringClass = FindClass("java/lang/Object");
		jmethodID toString = FindMethod(stringClass, "toString", "(Ljava/lang/Object;)Ljava/lang/String;");
		jstring res = (jstring)env->CallObjectMethod(object, toString);
		return string(env->GetStringUTFChars(res, NULL));
	}

	jboolean JavaEnv::equals(jobject o1, jobject o2) {
		if (o1 == NULL) {
			return o2 == NULL;
		} else if (o2 == NULL) {
			return false;
		} else {
			jmethodID equals = FindMethod(FindClass("java/lang/Object"), "equals", "(Ljava/lang/Object;)Z");
			return env->CallBooleanMethod(o1, equals, o2);
		}
	}
}
}
