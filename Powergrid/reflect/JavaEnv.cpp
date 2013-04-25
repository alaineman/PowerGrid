#include "jni.h"
#include "JavaEnv.h"
#include <iostream>
#include <stdarg.h>
#include "../wintools/Registry.h"

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
    
    void JavaEnv::Setup(LPCSTR classpath, LPCSTR mainClass) {

		// Collect the Registry key value for the Java Runtime library.
		HKEY hKey;
		if (ERROR_SUCCESS != GetHKEYForRead(&hKey, HKEY_LOCAL_MACHINE, L"SOFTWARE\\JavaSoft\\Java Runtime Environment\\1.7")) {
			throw JavaEnvException("Java directory not found. Verify that Java is installed.");
		}
		std::wstring java_dll;
		if (ERROR_SUCCESS != GetStringRegKey(hKey, L"RuntimeLib", java_dll, L"bad")) {
			throw JavaEnvException("Failed to read from registry, java directory not found.");
		}
		std::wstring defaultCP;
		if (ERROR_SUCCESS != GetStringRegKey(hKey, L"JavaHome", defaultCP, L"bad")) {
			throw JavaEnvException("Failed to read from registry, Java Home not found.");
		}
		defaultCP += L"\\lib\\rt.jar";
		// try loading jvm dll
		HMODULE jvmDll = LoadLibraryW(java_dll.c_str());
		if(jvmDll == NULL) { 
			throw JavaEnvException("jvm.dll not found");
		}

		// Get the "JNI_CreateJavaVM" procedure from the loaded DLL
		CreateJavaVM createJVM = (CreateJavaVM)GetProcAddress(jvmDll, "JNI_CreateJavaVM");
		if (createJVM == NULL)  {
			throw JavaEnvException("JNI_CreateJavaVM procedure not found");
		}
		
		JavaVMInitArgs vm_args;
		vm_args.version            = JNI_VERSION_1_6;
		
		vm_args.ignoreUnrecognized = JNI_TRUE;

		// Get the class path.
		string cpArg = "-Djava.class.path=";
		if (classpath != NULL) {
			cpArg += classpath;
			cpArg += ";";
		}
		string str (defaultCP.begin(), defaultCP.end());
		cpArg += str;

		JavaVMOption options[2];
		options[0].optionString  = const_cast<char*>(cpArg.c_str());
		options[1].optionString  = "-verbose:jni";
		vm_args.options          = options;
		vm_args.nOptions         = 2;
 
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
			jvm->DestroyJavaVM();
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

	void JavaEnv::ThrowException(LPCSTR file, INT line, LPCSTR info) {
		LPSTR errorMessage = "";

		if (file != NULL && line != 0 && info != NULL) {
			sprintf(errorMessage, "JNIException at %s:%d (%s)", file, line, info);
		}

		jclass eClass = NULL;

		eClass = env->FindClass("java.lang.Exception");
		env->ThrowNew(eClass, errorMessage);
		env->DeleteLocalRef(eClass);
	}
}
}
