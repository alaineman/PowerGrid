/* 
 * File:   JavaEnv.h
 * Author: Chronio
 * 
 * Defines a Java Environment object that acts as a wrapper around JNI.
 * The object can perform calls to the running Java environment in a fashion 
 * similar to the Java Reflection library. 
 *
 * Created on April 22, 2013, 9:45 AM
 */
#include "jni.h"
#include <windows.h>
#include <cstdlib>
#include <stdexcept>

#ifndef JAVAENV_H
#define	JAVAENV_H

/* Error codes for the JavaEnv */
/* Java Home directory not found */
#define JAVAENV_NO_JAVAHOME 1
/* Could not create Java process */
#define JAVAENV_FAILED_PROCESS 2
/* Main class not found */
#define JAVAENV_MISSING_CLASS 3
/* Main method not found */
#define JAVAENV_MISSING_METHOD 4

/* Macro that converts a string literal to a char* type. */
#define C_TEXT( text ) ((char*)std::string( text ).c_str())

namespace powergrid {
namespace reflect {
    
	/* This class represents an exception thrown by a JavaEnv object upon failure.
	 */
	class JavaEnvException : public std::runtime_error {
	public:
		JavaEnvException(const char* message) : runtime_error(message) {};
	};

    /* This class provides an easy-to-use wrapper around a running Java 
     * environment.
     */
    class JavaEnv {
	private:
		typedef jint (JNICALL *CreateJavaVM)(JavaVM **pvm, void **penv, void *args);

        /* The Java virtual machine. */
        JavaVM* jvm;
        /* The JNI environment. */
        JNIEnv* env;

		/* The Windows handle object. */
		HINSTANCE hInstance;
		/* The Java Virtual Machine DLL handle. */
		HINSTANCE jvmDll;
    public:
		/* Creates a new JavaEnv object using the provided HINSTANCE object
		 */
		JavaEnv(HINSTANCE);
        /* Destructs the JavaEnv object, terminating the JavaVM
         */
        ~JavaEnv();
        
        /* Returns the JNIEnv object referenced in this JavaEnv. */
        JNIEnv* Env();
        /* Returns the JavaVM object referenced in this JavaEnv. */
        JavaVM* JVM();
        
        /* Sets up and starts the Java VM, using the given classpath and main
           Class.
         */
        virtual void Setup(const char* classpath, const char* mainClass);
        /* Finds and returns the class with the given fully qualified name. 
           When no class with that name is found, this function returns NULL.
         */
        virtual jclass FindClass(const char* name);
        /* Finds all subclasses of the given parent class and places them in 
           the given jclass array. This method returns the amount of classes 
           found. Note that this is an expensive operation.
         */
        virtual int FindSubclasses(jclass* children, jclass parent);
        /* Gracefully terminates this Java environment. 
         */
        virtual int Terminate();
        /* Finds the method with the specified name and parameters in the 
           provided jclass.
         */
        virtual jmethodID FindMethod(jclass c, const char* name, const char* sig);
		/* Invokes the method with the specified name, signature and parameters 
		   on the object. The return value of the method should be jint.
		 */
		virtual jclass GetClass(jobject o);
		/* Returns the string value for the given object, using that object's 
		   toString() method. If the given jobject is a jstring, it is converted
		   to a std::string.
		 */
		virtual std::string AsString(jobject o);
    };
    
} /* namespace reflect */
} /* namespace powergrid */

#endif	/* JAVAENV_H */

